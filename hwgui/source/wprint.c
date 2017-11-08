/*
 * $Id: wprint.c,v 1.17 2008/05/27 12:11:04 lculik Exp $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * C level print functions
 *
 * Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#define HB_OS_WIN_32_USED

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


HB_FUNC( HWG_OPENPRINTER )
{
   HB_RETHANDLE( CreateDC( NULL, hb_parc(1), NULL, NULL ) );
}

HB_FUNC( HWG_OPENDEFAULTPRINTER )
{
   DWORD            dwNeeded, dwReturned ;
   HDC              hDC;
   PRINTER_INFO_4 * pinfo4;
   PRINTER_INFO_5 * pinfo5;

   if( GetVersion() & 0x80000000 )         // Windows 98
   {
      EnumPrinters( PRINTER_ENUM_DEFAULT, NULL, 5, NULL,
            0, &dwNeeded, &dwReturned );

      pinfo5 = (PRINTER_INFO_5*)malloc( dwNeeded );

      EnumPrinters( PRINTER_ENUM_DEFAULT, NULL, 5, (PBYTE) pinfo5,
            dwNeeded, &dwNeeded, &dwReturned );

      hDC = CreateDC( NULL, pinfo5->pPrinterName, NULL, NULL );
      if( hb_pcount() > 0 )
         hb_storc( pinfo5->pPrinterName,1 );

      free (pinfo5) ;
   }
   else                                    // Windows NT
   {
      EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, NULL,
            0, &dwNeeded, &dwReturned );

      pinfo4 = (PRINTER_INFO_4*)malloc( dwNeeded );

      EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, (PBYTE) pinfo4,
            dwNeeded, &dwNeeded, &dwReturned );
      hDC = CreateDC( NULL, pinfo4->pPrinterName, NULL, NULL );
      if( hb_pcount() > 0 )
         hb_storc( pinfo4->pPrinterName,1 );

      free( pinfo4 );
   }
   HB_RETHANDLE( hDC );
}


HB_FUNC( HWG_GETDEFAULTPRINTER )
{
   DWORD            dwNeeded, dwReturned ;
   PRINTER_INFO_4 * pinfo4;
   PRINTER_INFO_5 * pinfo5;
   char PrinterDefault [128];
   DWORD BuffSize = 256;
   OSVERSIONINFO osvi;
   BOOL bIsWindowsXPorLater;

   ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

   GetVersionEx(&osvi);

   if(osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )         // Windows 98
   {
      EnumPrinters( PRINTER_ENUM_DEFAULT, NULL, 5, NULL,
            0, &dwNeeded, &dwReturned );

      pinfo5 = (PRINTER_INFO_5*)malloc( dwNeeded );
      EnumPrinters( PRINTER_ENUM_DEFAULT, NULL, 5, (LPBYTE) pinfo5,
            dwNeeded, &dwNeeded, &dwReturned );
      strcpy(PrinterDefault,pinfo5->pPrinterName);

      free (pinfo5) ;
   }
   else if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
   {
      if (osvi.dwMajorVersion >= 5) /* Windows 2000 or later */
      {
        GetDefaultPrinter(PrinterDefault,&BuffSize);
      }
      else                                   // Windows NT
      {
         EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, NULL,
               0, &dwNeeded, &dwReturned );

         pinfo4 = (PRINTER_INFO_4*)malloc( dwNeeded );

         EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, (PBYTE) pinfo4,
              dwNeeded, &dwNeeded, &dwReturned );

         hb_retc( (char *) pinfo4->pPrinterName);
         strcpy(PrinterDefault,pinfo4->pPrinterName);

         free( pinfo4 );
       }
   }

   hb_retc(PrinterDefault);
   return ;
}

HB_FUNC( HWG_GETPRINTERS )
{
   DWORD            dwNeeded, dwReturned ;
   PBYTE            pBuffer = NULL;
   PRINTER_INFO_4 * pinfo4 = NULL;
   PRINTER_INFO_5 * pinfo5 = NULL;

   PHB_ITEM aMetr, temp;


   if (GetVersion () & 0x80000000)         // Windows 98
   {
      EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 5, NULL,
            0, &dwNeeded, &dwReturned );
      if( dwNeeded )
      {
         pBuffer = (PBYTE) malloc( dwNeeded );
         pinfo5  = (PRINTER_INFO_5*) pBuffer;
         EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 5, pBuffer,
             dwNeeded, &dwNeeded, &dwReturned );
      }
   }
   else                                    // Windows NT
   {
      EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, NULL,
            0, &dwNeeded, &dwReturned );
      if( dwNeeded )
      {
         pBuffer = (PBYTE) malloc( dwNeeded );
         pinfo4  = (PRINTER_INFO_4*) pBuffer;
         EnumPrinters( PRINTER_ENUM_LOCAL, NULL, 4, pBuffer,
             dwNeeded, &dwNeeded, &dwReturned );
      }
   }
   if( dwReturned )
   {
      int i;

      aMetr = hb_itemArrayNew( dwReturned );

      for( i=0; i<(int)dwReturned; i++ )
      {
         if( pinfo4 )
         {
            temp = hb_itemPutC( NULL, pinfo4->pPrinterName );
            pinfo4++;
         }
         else
         {
            temp = hb_itemPutC( NULL, pinfo5->pPrinterName );
            pinfo5++;
         }
         hb_itemArrayPut( aMetr, i+1, temp );
         hb_itemRelease( temp );
      }
      hb_itemReturn( aMetr );
      hb_itemRelease( aMetr );
   }
   else
      hb_ret();

   if( pBuffer )
      free( pBuffer );

}

HB_FUNC( SETPRINTERMODE )
{
   LPTSTR pPrinterName = (LPTSTR) hb_parc(1);
   HANDLE hPrinter = (ISNIL(2))? (HANDLE)NULL : (HANDLE)HB_PARHANDLE(2);
   long int nSize;
   PDEVMODE pdm;

   if( !hPrinter )
      if( !OpenPrinter( pPrinterName, &hPrinter, NULL ) )
      {
         return;
      }

   /* Determine the size of DEVMODE structure */
   nSize = DocumentProperties( NULL, hPrinter, pPrinterName, NULL, NULL, 0 );
   pdm = (PDEVMODE)GlobalAlloc( GPTR, nSize );

   /* Get the printer mode */
   DocumentProperties( NULL, hPrinter, pPrinterName, pdm, NULL, DM_OUT_BUFFER );

   /* Changing of values */
   if( !ISNIL(3) )
   {
      pdm->dmOrientation = hb_parni(3);
      pdm->dmFields = pdm->dmFields | DM_ORIENTATION;
   }

   // Call DocumentProperties() to change the values
   DocumentProperties( NULL, hPrinter, pPrinterName,
                      pdm, pdm, DM_OUT_BUFFER | DM_IN_BUFFER );

   // ᮧ����� ���⥪�� ���ன�⢠ �ਭ��
   HB_RETHANDLE(  CreateDC( NULL, pPrinterName, NULL, pdm ) );
   HB_STOREHANDLE( hPrinter,2 );
   GlobalFree( pdm );
}

HB_FUNC( CLOSEPRINTER )
{
   HANDLE hPrinter = (HANDLE)HB_PARHANDLE(1);
   ClosePrinter( hPrinter );
}

HB_FUNC( HWG_STARTDOC )
{
   DOCINFO di;
   di.cbSize = sizeof(DOCINFO);
   di.lpszDocName = hb_parc( 2 );
   di.lpszOutput = (LPTSTR) NULL;
   di.lpszDatatype = (LPTSTR) NULL;
   di.fwType = 0;

   hb_retnl( (LONG) StartDoc( (HDC) HB_PARHANDLE( 1 ), &di ) );
}

HB_FUNC( HWG_ENDDOC )
{
   EndDoc( (HDC) HB_PARHANDLE( 1 ) );
}

HB_FUNC( HWG_STARTPAGE )
{
   hb_retnl( (LONG) StartPage( (HDC) HB_PARHANDLE( 1 ) ) );
}

HB_FUNC( HWG_ENDPAGE )
{
   hb_retnl( (LONG) EndPage( (HDC) HB_PARHANDLE( 1 ) ) );
}

/*
 * HORZRES	Width, in pixels, of the screen.
 * VERTRES	Height, in raster lines, of the screen.
 * HORZSIZE	Width, in millimeters, of the physical screen.
 * VERTSIZE	Height, in millimeters, of the physical screen.
 * LOGPIXELSX	Number of pixels per logical inch along the screen width.
 * LOGPIXELSY	Number of pixels per logical inch along the screen height.
 *
 */
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

HB_FUNC( CREATEENHMETAFILE )
{
   HWND hWnd = (HWND) HB_PARHANDLE( 1 );
   HDC hDCref = GetDC( hWnd ), hDCmeta;
   LPCTSTR lpFilename = (hb_pcount()>1)? hb_parc(2):NULL;
   int iWidthMM, iHeightMM, iWidthPels, iHeightPels;
   RECT rc;
   // char cres[80];

   /* Determine the picture frame dimensions. 
    * iWidthMM is the display width in millimeters. 
    * iHeightMM is the display height in millimeters. 
    * iWidthPels is the display width in pixels. 
    * iHeightPels is the display height in pixels 
    */ 
    
   iWidthMM = GetDeviceCaps(hDCref, HORZSIZE); 
   iHeightMM = GetDeviceCaps(hDCref, VERTSIZE); 
   iWidthPels = GetDeviceCaps(hDCref, HORZRES); 
   iHeightPels = GetDeviceCaps(hDCref, VERTRES); 

    
   /* 
    * Retrieve the coordinates of the client 
    * rectangle, in pixels. 
    */ 
    
   GetClientRect( hWnd, &rc );
   // sprintf( cres,"%d %d %d %d %d %d %d %d",iWidthMM, iHeightMM, iWidthPels, iHeightPels,rc.left,rc.top,rc.right,rc.bottom );
   // MessageBox( GetActiveWindow(), cres, "", MB_OK | MB_ICONINFORMATION );
    
   /* 
    * Convert client coordinates to .01-mm units. 
    * Use iWidthMM, iWidthPels, iHeightMM, and 
    * iHeightPels to determine the number of 
    * .01-millimeter units per pixel in the x- 
    *  and y-directions. 
    */ 
    
   rc.left   = (rc.left * iWidthMM * 100)/iWidthPels; 
   rc.top    = (rc.top * iHeightMM * 100)/iHeightPels; 
   rc.right  = (rc.right * iWidthMM * 100)/iWidthPels; 
   rc.bottom = (rc.bottom * iHeightMM * 100)/iHeightPels; 

   hDCmeta = CreateEnhMetaFile( hDCref, lpFilename, &rc, NULL );
   ReleaseDC( hWnd, hDCref );
   HB_RETHANDLE( hDCmeta );

}

HB_FUNC( CREATEMETAFILE )
{
   HDC hDCref = (HDC) HB_PARHANDLE( 1 ), hDCmeta;
   LPCTSTR lpFilename = (hb_pcount()>1 && !ISNIL(2))? hb_parc(2):NULL;
   int iWidthMM, iHeightMM;
   RECT rc;

   /* Determine the picture frame dimensions. 
    * iWidthMM is the display width in millimeters. 
    * iHeightMM is the display height in millimeters. 
    * iWidthPels is the display width in pixels. 
    * iHeightPels is the display height in pixels 
    */ 
    
   iWidthMM = GetDeviceCaps(hDCref, HORZSIZE); 
   iHeightMM = GetDeviceCaps(hDCref, VERTSIZE); 

   /* 
    * Convert client coordinates to .01-mm units. 
    * Use iWidthMM, iWidthPels, iHeightMM, and 
    * iHeightPels to determine the number of 
    * .01-millimeter units per pixel in the x- 
    *  and y-directions. 
    */ 
    
   rc.left   = 0;
   rc.top    = 0;
   rc.right  = iWidthMM * 100;
   rc.bottom = iHeightMM * 100;

   hDCmeta = CreateEnhMetaFile( hDCref, lpFilename, &rc, NULL );
   HB_RETHANDLE(  hDCmeta );

}

HB_FUNC( CLOSEENHMETAFILE )
{
   HB_RETHANDLE(  CloseEnhMetaFile( (HDC) HB_PARHANDLE(1) ) );
}

HB_FUNC( DELETEENHMETAFILE )
{
   HB_RETHANDLE( (LONG) DeleteEnhMetaFile( (HENHMETAFILE) HB_PARHANDLE(1) ) );
}

HB_FUNC( PLAYENHMETAFILE )
{
   HDC hDC = (HDC) HB_PARHANDLE(1);
   RECT rc;

   if( hb_pcount() > 2 )
   {
      rc.left   = hb_parni(3);
      rc.top    = hb_parni(4);
      rc.right  = hb_parni(5);
      rc.bottom = hb_parni(6);
   }
   else
      GetClientRect( WindowFromDC( hDC ), &rc );
   hb_retnl( (LONG) PlayEnhMetaFile( hDC, (HENHMETAFILE)  HB_PARHANDLE(2), &rc ) );
}

HB_FUNC( PRINTENHMETAFILE )
{
   HDC hDC = (HDC) HB_PARHANDLE(1);
   // DOCINFO di;
   RECT rc;

   /*
   di.cbSize = sizeof(DOCINFO); 
   di.lpszDocName = hb_parc( 3 );
   di.lpszOutput = (LPTSTR) NULL; 
   di.lpszDatatype = (LPTSTR) NULL; 
   di.fwType = 0; 
   */

   SetRect( &rc, 0, 0, GetDeviceCaps( hDC, HORZRES ), GetDeviceCaps( hDC, VERTRES ) );

   // StartDoc( hDC, &di );
   StartPage( hDC );
   hb_retnl( (LONG) PlayEnhMetaFile( hDC, (HENHMETAFILE)  HB_PARHANDLE(2), &rc ) );
   EndPage( hDC );
   // EndDoc( hDC );
}
