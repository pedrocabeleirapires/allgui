/*
 * $Id: richedit.c,v 1.26 2008/05/27 12:11:02 lculik Exp $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * C level richedit control functions
 *
 * Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
 * www - http://kresin.belgorod.su
*/

#define HB_OS_WIN_32_USED

#define _WIN32_WINNT 0x0400
#define _WIN32_IE    0x0400
//#define OEMRESOURCE
#include <windows.h>
#if defined(__MINGW32__) || defined(__WATCOMC__)
   #include <prsht.h>
#endif
#include <commctrl.h>
#define _RICHEDIT_VER	0x0200
#include <richedit.h>
#if defined(__DMC__)
#define GetWindowLongPtr GetWindowLong
#endif
#include "guilib.h"
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#include "hbdate.h"

extern PHB_DYNS pSym_onEvent;

LRESULT APIENTRY RichSubclassProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

static HINSTANCE hRichEd = 0;
static WNDPROC wpOrigRichProc;

HB_FUNC( HWG_INITRICHEDIT )
{
   if( !hRichEd )
      hRichEd = LoadLibrary( "riched20.dll" );
}

HB_FUNC( CREATERICHEDIT )
{
   HWND hCtrl;

   if( !hRichEd )
      hRichEd = LoadLibrary( "riched20.dll" );

   hCtrl = CreateWindowEx( 
                 0	,     /* extended style    */
                 "RichEdit20A",  /* predefined class  */
                 NULL,        /* title   */
                 WS_CHILD | WS_VISIBLE | hb_parnl(3), /* style  */
                 hb_parni(4), hb_parni(5),            /* x, y   */
                 hb_parni(6), hb_parni(7),      /* nWidth, nHeight */
                 (HWND) HB_PARHANDLE(1),           /* parent window    */ 
                 (HMENU) hb_parni(2),               /* control ID  */
                 GetModuleHandle( NULL ),
                 NULL);

   if( hb_pcount() > 7 )
      SendMessage( hCtrl, WM_SETTEXT, 0, (LPARAM) hb_parc(8) );  

   HB_RETHANDLE( hCtrl );

}

/*
 * re_SetCharFormat( hCtrl, n1, n2, nColor, cName, nHeight, lBold, lItalic, 
           lUnderline, nCharset, lSuperScript/lSubscript(.T./.F.), lProtected )
 */
HB_FUNC ( RE_SETCHARFORMAT )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   CHARRANGE chrOld, chrNew;
   CHARFORMAT2 cf;
   PHB_ITEM pArr;

   SendMessage( hCtrl, EM_EXGETSEL, 0, (LPARAM) &chrOld );
   SendMessage( hCtrl, EM_HIDESELECTION, 1, 0 );

   if( ISARRAY(2) )
   {
      ULONG ul, ulLen, ulLen1;
      PHB_ITEM pArr1;
      pArr = hb_param( 2, HB_IT_ARRAY );
      ulLen = hb_arrayLen( pArr );
      for( ul=1; ul<=ulLen; ul++ )
      {
         pArr1 = hb_arrayGetItemPtr( pArr,ul );
         ulLen1 = hb_arrayLen( pArr1 );
         chrNew.cpMin = hb_arrayGetNL( pArr1,1 )-1;
         chrNew.cpMax = hb_arrayGetNL( pArr1,2 )-1;
         SendMessage( hCtrl, EM_EXSETSEL, 0, (LPARAM) &chrNew );

         memset( &cf, 0, sizeof(CHARFORMAT2) );
         cf.cbSize = sizeof(CHARFORMAT2);
         if( hb_itemType( hb_arrayGetItemPtr( pArr1,3 ) ) != HB_IT_NIL )
         {
            cf.crTextColor = (COLORREF) hb_arrayGetNL( pArr1,3 );
            cf.dwMask |= CFM_COLOR;
         }
         if( ulLen1 > 3 && hb_itemType( hb_arrayGetItemPtr( pArr1,4 ) ) != HB_IT_NIL )
         {
            strcpy( cf.szFaceName, hb_arrayGetCPtr( pArr1,4 ) );
            cf.dwMask |= CFM_FACE;
         }
         if( ulLen1 > 4 && hb_itemType( hb_arrayGetItemPtr( pArr1,5 ) ) != HB_IT_NIL )
         {
            cf.yHeight = hb_arrayGetNL( pArr1,5 );
            cf.dwMask |= CFM_SIZE;
         }
         if( ulLen1 > 5 && hb_itemType( hb_arrayGetItemPtr( pArr1,6 ) ) != HB_IT_NIL && hb_arrayGetL( pArr1,6 ) )
         {
            cf.dwEffects |= CFE_BOLD;
         }
         if( ulLen1 > 6 && hb_itemType( hb_arrayGetItemPtr( pArr1,7 ) ) != HB_IT_NIL && hb_arrayGetL( pArr1,7 ) )
         {
            cf.dwEffects |= CFE_ITALIC;
         }
         if( ulLen1 > 7 && hb_itemType( hb_arrayGetItemPtr( pArr1,8 ) ) != HB_IT_NIL && hb_arrayGetL( pArr1,8 ) )
         {
            cf.dwEffects |= CFE_UNDERLINE;
         }
         if( ulLen1 > 8 && hb_itemType( hb_arrayGetItemPtr( pArr1,9 ) ) != HB_IT_NIL )
         {
            cf.bCharSet = (BYTE) hb_arrayGetNL( pArr1,9 );
            cf.dwMask |= CFM_CHARSET;
         }
         if( ulLen1 > 9 && hb_itemType( hb_arrayGetItemPtr( pArr1,10 ) ) != HB_IT_NIL )
         {
            if( hb_arrayGetL( pArr1,10 ) )
               cf.dwEffects |= CFE_SUPERSCRIPT;
            else
               cf.dwEffects |= CFE_SUBSCRIPT;
            cf.dwMask |= CFM_SUPERSCRIPT;
         }
         if( ulLen1 > 10 && hb_itemType( hb_arrayGetItemPtr( pArr1,11 ) ) != HB_IT_NIL && hb_arrayGetL( pArr1,11 ) )
         {
            cf.dwEffects |= CFE_PROTECTED;
         }
         cf.dwMask |= ( CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_PROTECTED );
         SendMessage( hCtrl, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM) &cf );
      }
   }
   else
   {
      /*   Set new selection   */
      chrNew.cpMin = hb_parnl(2)-1;
      chrNew.cpMax = hb_parnl(3)-1;
      SendMessage( hCtrl, EM_EXSETSEL, 0, (LPARAM) &chrNew );

      memset( &cf, 0, sizeof(CHARFORMAT2) );
      cf.cbSize = sizeof(CHARFORMAT2);

      if( !ISNIL(4) )
      {
         cf.crTextColor = (COLORREF) hb_parnl(4);
         cf.dwMask |= CFM_COLOR;
      }
      if( !ISNIL(5) )
      {
         strcpy( cf.szFaceName, hb_parc(5) );
         cf.dwMask |= CFM_FACE;
      }
      if( !ISNIL(6) )
      {
         cf.yHeight = hb_parnl(6);
         cf.dwMask |= CFM_SIZE;
      }
      if( !ISNIL(7) )
      {
         cf.dwEffects |= (hb_parl(7))? CFE_BOLD:0;
         cf.dwMask |= CFM_BOLD;
      }
      if( !ISNIL(8) )
      {
         cf.dwEffects |= (hb_parl(8))? CFE_ITALIC:0;
         cf.dwMask |= CFM_ITALIC;
      }
      if( !ISNIL(9) )
      {
         cf.dwEffects |= (hb_parl(9))? CFE_UNDERLINE:0;
         cf.dwMask |= CFM_UNDERLINE;
      }
      if( !ISNIL( 10 ) )
      {
         cf.bCharSet = (BYTE) hb_parnl( 10 );
         cf.dwMask |= CFM_CHARSET;
      }
      if( !ISNIL( 11 ) )
      {
         if( hb_parl( 9 ) )
            cf.dwEffects |= CFE_SUPERSCRIPT;
         else
            cf.dwEffects |= CFE_SUBSCRIPT;
         cf.dwMask |= CFM_SUPERSCRIPT;
      }
      if( !ISNIL( 12 ) )
      {
         cf.dwEffects |= CFE_PROTECTED;
         cf.dwMask |= CFM_PROTECTED;
      }

      SendMessage( hCtrl, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM) &cf );
   }

   /*   Restore selection   */
   SendMessage( hCtrl, EM_EXSETSEL, 0, (LPARAM) &chrOld );
   SendMessage( hCtrl, EM_HIDESELECTION, 0, 0 );

}

/*
 * re_SetDefault( hCtrl, nColor, cName, nHeight, lBold, lItalic, lUnderline, nCharset )
 */
HB_FUNC( RE_SETDEFAULT )
{
   HWND hCtrl = (HWND) HB_PARHANDLE( 1 );
   CHARFORMAT2 cf;

   memset( &cf, 0, sizeof(CHARFORMAT2) );
   cf.cbSize = sizeof( CHARFORMAT2 );

   if( ISNUM( 2 ) )
   {
      cf.crTextColor = (COLORREF) hb_parnl( 2 );
      cf.dwMask |= CFM_COLOR;
   }
   if( ISCHAR( 3 ) )
   {     
      strcpy( cf.szFaceName, hb_parc( 3 ));
      cf.dwMask |= CFM_FACE;
   }

   if( ISNUM( 4 ) )
   {
      cf.yHeight = hb_parnl( 4 );
      cf.dwMask |= CFM_SIZE;
   }

   if( !ISNIL(5) )
   {
      cf.dwEffects |= (hb_parl(5))? CFE_BOLD:0;
   }
   if( !ISNIL(6) )
   {
      cf.dwEffects |= (hb_parl(6))? CFE_ITALIC:0;
   }
   if( !ISNIL(7) )
   {
      cf.dwEffects |= (hb_parl(7))? CFE_UNDERLINE:0;
   }

   if( ISNUM( 8 ) )
   {
      cf.bCharSet = (BYTE) hb_parnl( 8 );
      cf.dwMask |= CFM_CHARSET;
   }

   cf.dwMask |= ( CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE );
   SendMessage( hCtrl, EM_SETCHARFORMAT, SCF_ALL, (LPARAM) &cf );


}

/*
 * re_CharFromPos( hEdit, xPos, yPos ) --> nPos
 */
HB_FUNC( RE_CHARFROMPOS )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   int x = hb_parni( 2 );
   int y = hb_parni( 3 );
   ULONG ul;
   POINTL pp;

   pp.x = x;
   pp.y = y;
   ul = SendMessage( hCtrl, EM_CHARFROMPOS, 0, (LPARAM)&pp );
   hb_retnl( ul );
}

/*
 * re_GetTextRange( hEdit, n1, n2 )
 */
HB_FUNC( RE_GETTEXTRANGE )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   TEXTRANGE tr;
   ULONG ul;

   tr.chrg.cpMin = hb_parnl(2)-1;
   tr.chrg.cpMax = hb_parnl(3)-1;

   tr.lpstrText = (LPSTR) hb_xgrab( tr.chrg.cpMax-tr.chrg.cpMin+2 );
   ul = SendMessage( hCtrl, EM_GETTEXTRANGE, 0, (LPARAM)&tr );
   hb_retclen( tr.lpstrText, ul );
   hb_xfree( tr.lpstrText );

}

/*
 * re_GetLine( hEdit, nLine )
 */
HB_FUNC( RE_GETLINE )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   int nLine = hb_parni(2);
   ULONG uLineIndex = SendMessage( hCtrl, EM_LINEINDEX, (WPARAM)nLine, 0 );
   ULONG ul = SendMessage( hCtrl, EM_LINELENGTH, (WPARAM)uLineIndex, 0 );
   char * cBuf = (char*) hb_xgrab( ul+4 );

   *((ULONG*)cBuf) = ul;

   ul = SendMessage( hCtrl, EM_GETLINE, nLine, (LPARAM)cBuf );
   hb_retclen( cBuf, ul );
   hb_xfree( cBuf );

}

HB_FUNC( RE_INSERTTEXT )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   char * ptr = hb_parc(2);

   SendMessage( hCtrl, EM_REPLACESEL, 0, (LPARAM)ptr );
}

/*
 * re_FindText( hEdit, cFind, nStart, bCase, bWholeWord, bSearchUp )
 */
HB_FUNC( RE_FINDTEXT )
{
   HWND hCtrl = (HWND) HB_PARHANDLE(1);
   FINDTEXTEX ft;
   LONG lPos;
   LONG lFlag = ( ( ISNIL(4) || !hb_parl(4) )? 0 : FR_MATCHCASE ) |
                ( ( ISNIL(5) || !hb_parl(5) )? 0 : FR_WHOLEWORD ) |
                ( ( ISNIL(6) || !hb_parl(6) )? FR_DOWN : 0 );

   ft.chrg.cpMin = ( ISNIL(3) )? 0 : hb_parnl(3);
   ft.chrg.cpMax = -1;
   ft.lpstrText = hb_parc(2);

   lPos = (LONG) SendMessage( hCtrl, EM_FINDTEXTEX, (WPARAM)lFlag, (LPARAM)&ft );
   hb_retnl( lPos );
}

HB_FUNC( HWG_INITRICHPROC )
{
   wpOrigRichProc = (WNDPROC) SetWindowLong( (HWND) HB_PARHANDLE(1),
                                 GWL_WNDPROC, (LONG) RichSubclassProc );
}

LRESULT APIENTRY RichSubclassProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
   long int res;
   PHB_ITEM pObject = ( PHB_ITEM ) GetWindowLongPtr( hWnd, GWL_USERDATA );

   if( !pSym_onEvent )
      pSym_onEvent = hb_dynsymFindName( "ONEVENT" );

   if( pSym_onEvent && pObject )
   {
      hb_vmPushSymbol( hb_dynsymSymbol( pSym_onEvent ) );
      hb_vmPush( pObject );
      hb_vmPushLong( (LONG ) message );
      hb_vmPushLong( (LONG ) wParam );
      hb_vmPushLong( (LONG ) lParam );
      hb_vmSend( 3 );
      res = hb_parnl( -1 );
      if( res == -1 )
         return( CallWindowProc( wpOrigRichProc, hWnd, message, wParam, lParam ) );
      else
         return res;
   }
   else
      return( CallWindowProc( wpOrigRichProc, hWnd, message, wParam, lParam ) );
}
