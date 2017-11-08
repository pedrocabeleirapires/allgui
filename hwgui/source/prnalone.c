/*
 *
 * C level print functions
 *
 * Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://www.geocities.com/alkresin/
*/

#define _WIN32_WINNT 0x0400
#define OEMRESOURCE
#include <windows.h>
#include <commctrl.h>

#include "guilib.h"
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"

#ifdef __XHARBOUR__
#include "hbfast.h"
#endif

HB_FUNC( PRINTSETUP )
{
   PRINTDLG pd;

   memset( (void*) &pd, 0, sizeof( PRINTDLG ) );

   pd.lStructSize = sizeof(PRINTDLG); 
   pd.Flags = PD_RETURNDC; 
   pd.hwndOwner = GetActiveWindow();
   pd.nFromPage = 1; 
   pd.nToPage = 1; 
   pd.nCopies = 1; 
    
   if( PrintDlg(&pd) )
      HB_RETHANDLE( (LONG) pd.hDC );
   else
      HB_RETHANDLE( 0 );  
}

HB_FUNC( OPENPRINTER )
{
   HB_RETHANDLE(  CreateDC( NULL, hb_parc(1), NULL, NULL ) );
}

HB_FUNC( OPENDEFAULTPRINTER )
{
  DWORD            dwNeeded, dwReturned ;
  HDC              hDC;
  PRINTER_INFO_4 * pinfo4;
  PRINTER_INFO_5 * pinfo5;

  if (GetVersion () & 0x80000000)         // Windows 98
  {
     EnumPrinters (PRINTER_ENUM_DEFAULT, NULL, 5, NULL,
           0, &dwNeeded, &dwReturned) ;

     pinfo5 = malloc (dwNeeded) ;

     EnumPrinters (PRINTER_ENUM_DEFAULT, NULL, 5, (PBYTE) pinfo5,
           dwNeeded, &dwNeeded, &dwReturned) ;
     hDC = CreateDC (NULL, pinfo5->pPrinterName, NULL, NULL) ;

     free (pinfo5) ;
  }
  else                                    // Windows NT
  {
     EnumPrinters (PRINTER_ENUM_LOCAL, NULL, 4, NULL,
           0, &dwNeeded, &dwReturned) ;

     pinfo4 = malloc (dwNeeded) ;

     EnumPrinters (PRINTER_ENUM_LOCAL, NULL, 4, (PBYTE) pinfo4,
           dwNeeded, &dwNeeded, &dwReturned) ;
     hDC = CreateDC (NULL, pinfo4->pPrinterName, NULL, NULL) ;

     free (pinfo4) ;
  }
  HB_RETHANDLE( hDC );   
}

HB_FUNC( STARTDOC )
{
   DOCINFO di;
   di.cbSize = sizeof(DOCINFO); 
   di.lpszDocName = hb_parc( 2 );
   di.lpszOutput = (LPTSTR) NULL; 
   di.lpszDatatype = (LPTSTR) NULL; 
   di.fwType = 0; 

   hb_retnl( (LONG) StartDoc( (HDC) HB_PARHANDLE( 1 ), &di ) );
}

HB_FUNC( ENDDOC )
{
   EndDoc( (HDC) HB_PARHANDLE( 1 ) );
}

HB_FUNC( STARTPAGE )
{
   hb_retnl( (LONG) StartPage( (HDC) HB_PARHANDLE( 1 ) ) );
}

HB_FUNC( ENDPAGE )
{
   hb_retnl( (LONG) EndPage( (HDC) HB_PARHANDLE( 1 ) ) );
}

HB_FUNC( DELETEDC )
{
   DeleteDC( (HDC) HB_PARHANDLE( 1 ) );
}

HB_FUNC( GETDEVICEAREA )
{
   HDC hDC = (HDC) HB_PARHANDLE( 1 );
   PHB_ITEM temp;
   PHB_ITEM aMetr = hb_itemArrayNew( 9 );
   
   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,HORZRES ) );
   hb_itemArrayPut( aMetr, 1, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,VERTRES ) );
   hb_itemArrayPut( aMetr, 2, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,HORZSIZE ) );
   hb_itemArrayPut( aMetr, 3, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,VERTSIZE ) );
   hb_itemArrayPut( aMetr, 4, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,LOGPIXELSX ) );
   hb_itemArrayPut( aMetr, 5, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,LOGPIXELSY ) );
   hb_itemArrayPut( aMetr, 6, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,RASTERCAPS ) );
   hb_itemArrayPut( aMetr, 7, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,PHYSICALWIDTH ) );
   hb_itemArrayPut( aMetr, 8, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, GetDeviceCaps( hDC,PHYSICALHEIGHT ) );
   hb_itemArrayPut( aMetr, 9, temp );
   hb_itemRelease( temp );

   hb_itemReturn( aMetr );
   hb_itemRelease( aMetr );
}

HB_FUNC( DRAWTEXT )
{
   char *cText = hb_parc( 2 );
   RECT rc;

   rc.left = hb_parni( 3 );
   rc.top = hb_parni( 4 );
   rc.right = hb_parni( 5 );
   rc.bottom = hb_parni( 6 );

   DrawText(
     (HDC) HB_PARHANDLE( 1 ),       // handle of device context 
     (LPCTSTR) cText,	        // address of string 
     strlen( cText ), 	        // number of characters in string 
     &rc,
     hb_parni( 7 )
   );
}