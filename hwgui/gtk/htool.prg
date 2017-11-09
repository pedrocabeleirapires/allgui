/*
* $Id: htool.prg,v 1.1 2008/03/29 14:50:20 lculik Exp $
* HWGUI - Harbour Win32 GUI library source code:
* Copyright 2004 Luiz Rafael Culik Guimaraes <culikr@brtrubo.com>
* www - http://sites.uol.com.br/culikr/
*/

#include "windows.ch"
#include "inkey.ch"
#include "hbclass.ch"
#include "guilib.ch"
#include "common.ch"

#define TRANSPARENT 1

CLASS HToolBar INHERIT HControl

   DATA winclass INIT "ToolbarWindow32"
   DATA TEXT, id, nTop, nLeft, nwidth, nheight
CLASSDATA oSelected INIT Nil
   DATA State INIT 0
   DATA ExStyle
   DATA bClick, cTooltip

   DATA lPress INIT .F.
   DATA lFlat
   DATA nOrder
   DATA aItem init {}

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont,bInit, ;
      bSize,bPaint,ctooltip,tcolor,bcolor,lTransp ,aItem)

METHOD Activate()

METHOD INIT()

METHOD REFRESH()

METHOD AddButton(a,s,d,f,g,h)

METHOD onEvent( msg, wParam, lParam )

METHOD EnableAllButtons()

METHOD DisableAllButtons()

METHOD EnableButtons(n)

METHOD DisableButtons(n)

ENDCLASS

METHOD New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont,bInit, ;
      bSize,bPaint,ctooltip,tcolor,bcolor,lTransp ,aitem) CLASS hToolBar
   DEFAULT  aItem to {}
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
      bSize,bPaint,ctooltip,tcolor,bcolor )

   ::aitem := aItem

   ::Activate()

   RETURN Self

METHOD Activate CLASS hToolBar

   Tracelog(  ::oParent:handle  )
   IF !empty(::oParent:handle )

      ::handle := CREATETOOLBAR(::oParent:handle )
      SetWindowObject( ::handle,Self )
      ::Init()
   ENDIF

   RETURN NIL

METHOD INIT CLASS hToolBar

   LOCAL n,n1
   LOCAL aTemp
   LOCAL hIm
   LOCAL aButton :={}
   LOCAL aBmpSize
   LOCAL oImage
   LOCAL nPos
   LOCAL aItem

   IF !::lInit
      Super:Init()
      FOR n := 1 TO len( ::aItem )

         //         IF Valtype( ::aItem[ n, 7 ] ) == "B"
         //            ::oParent:AddEvent( BN_CLICKED, ::aItem[ n, 2 ], ::aItem[ n ,7 ] )
         //         ENDIF

         //         IF Valtype( ::aItem[ n, 9 ] ) == "A"
         //            ::aItem[ n, 10 ] := hwg__CreatePopupMenu()
         //            aTemp := ::aItem[ n, 9 ]
         //            FOR n1 :=1 to Len( aTemp )
         //               hwg__AddMenuItem( ::aItem[ n, 10 ], aTemp[ n1, 1 ], -1, .F., aTemp[ n1, 2 ], , .F. )
         //               ::oParent:AddEvent( BN_CLICKED, aTemp[ n1, 2 ], aTemp[ n1,3 ] )
         //            NEXT
         //         ENDIF
         IF valtype( ::aItem[ n, 1 ] ) == "N"
            IF !empty( ::aItem[ n, 1 ] )
               AAdd( aButton, ::aItem[ n , 1 ])
            ENDIF
         ELSEIF  valtype( ::aItem[ n, 1 ] ) == "C"
            Tracelog(::aItem[ n, 1 ] )
            IF ".ico" in lower(::aItem[ n, 1 ])
               oImage:=hIcon():AddFile( ::aItem[ n, 1 ] )
            ELSE
               oImage:=hBitmap():AddFile( ::aItem[ n, 1 ] )
            ENDIF
            tracelog(valtoprg(oimage))
            IF valtype(oImage) =="O"
               aadd(aButton,Oimage:handle)
               ::aItem[ n, 1 ] := Oimage:handle
            ENDIF

         ENDIF

      NEXT

      /*      IF Len(aButton ) >0

      aBmpSize := GetBitmapSize( aButton[1] )

      IF aBmpSize[ 3 ] == 4
      hIm := CreateImageList( {} ,aBmpSize[ 1 ], aBmpSize[ 2 ], 1, ILC_COLOR4 + ILC_MASK )
      ELSEIF aBmpSize[ 3 ] == 8
      hIm := CreateImageList( {} ,aBmpSize[ 1 ], aBmpSize[ 2 ], 1, ILC_COLOR8 + ILC_MASK )
      ELSEIF aBmpSize[ 3 ] == 24
      hIm := CreateImageList( {} ,aBmpSize[ 1 ], aBmpSize[ 2 ], 1, ILC_COLORDDB + ILC_MASK )
      ENDIF

      FOR nPos :=1 to len(aButton)

      aBmpSize := GetBitmapSize( aButton[nPos] )

      IF aBmpSize[3] == 24
      //             Imagelist_AddMasked( hIm,aButton[nPos],RGB(236,223,216) )
      Imagelist_Add( hIm, aButton[ nPos ] )
      ELSE
      Imagelist_Add( hIm, aButton[ nPos ] )
      ENDIF

      NEXT

      SendMessage( ::Handle, TB_SETIMAGELIST, 0, hIm )

      ENDIF
      */
      IF len( ::aItem ) >0
         FOR EACH aItem in ::aItem

            IF aItem[4] == TBSTYLE_BUTTON

               aItem[11] := CreateToolBarButton(::handle,aItem[1],aItem[6],.f.)
               aItem[2] := hb_enumindex()
               //               hwg_SetSignal( aItem[11],"clicked",WM_LBUTTONUP,aItem[2],0 )
               TOOLBAR_SETACTION(aItem[11],aItem[7])
               IF !empty(aItem[8])
                  AddtoolTip(::handle, aItem[11],aItem[8])
               ENDIF
            ELSEIF aitem[4] == TBSTYLE_SEP
               aItem[11] := CreateToolBarButton(::handle,,,.t.)
               aItem[2] := hb_enumindex()
            ENDIF
         NEXT
      ENDIF

   ENDIF
   Tracelog(valtoprg(::aItem))

   RETURN NIL
   /*

   METHOD Notify( lParam ) CLASS hToolBar

   Local nCode :=  GetNotifyCode( lParam )
   Local nId

   Local nButton
   Local nPos

   IF nCode == TTN_GETDISPINFO

   nButton :=TOOLBAR_GETDISPINFOID( lParam )
   nPos := AScan( ::aItem,  { | x | x[ 2 ] == nButton })
   TOOLBAR_SETDISPINFO( lParam, ::aItem[ nPos, 8 ] )

   ELSEIF nCode == TBN_GETINFOTIP

   nId := TOOLBAR_GETINFOTIPID(lParam)
   nPos := AScan( ::aItem,  { | x | x[ 2 ] == nId })
   TOOLBAR_GETINFOTIP( lParam, ::aItem[ nPos, 8 ] )

   ELSEIF nCode == TBN_DROPDOWN
   if valtype(::aItem[1,9]) ="A"
   nid := TOOLBAR_SUBMENUEXGETID( lParam )
   nPos := AScan( ::aItem,  { | x | x[ 2 ] == nId })
   TOOLBAR_SUBMENUEx( lParam, ::aItem[ nPos, 10 ], ::oParent:handle )
   else
   TOOLBAR_SUBMENU(lParam,1,::oParent:handle)
   endif
   ENDIF

   Return 0
   */

METHOD AddButton(nBitIp,nId,bState,bStyle,cText,bClick,c,aMenu) CLASS hToolBar

   LOCAL hMenu := Nil

   DEFAULT nBitIp to -1
   DEFAULT bstate to TBSTATE_ENABLED
   DEFAULT bstyle to 0x0000
   DEFAULT c to ""
   DEFAULT ctext to ""
   AAdd( ::aItem ,{ nBitIp, nId, bState, bStyle, 0, cText, bClick, c, aMenu, hMenu ,0} )
   tracelog(valtoprg(::aItem ))

   RETURN Self

METHOD onEvent( msg, wParam, lParam )  CLASS HToolbar

   LOCAL nPos

   Tracelog(  msg, wParam, lParam  )
   IF msg == WM_LBUTTONUP
      nPos := ascan(::aItem,{|x| x[2] == wParam})
      IF nPos>0
         IF ::aItem[nPos,7] != Nil
            Eval( ::aItem[nPos,7] ,Self )
         ENDIF
      ENDIF
   ENDIF

   RETURN  NIL

METHOD REFRESH() class htoolbar

   IF ::lInit
      ::lInit := .f.
   ENDIF
   ::init()

   RETURN NIL

METHOD EnableAllButtons() class htoolbar

   LOCAL xItem

   FOR EACH xItem in ::aItem
      EnableWindow( xItem[ 11 ], .T. )
   NEXT

   RETURN Self

METHOD DisableAllButtons() class htoolbar

   LOCAL xItem

   FOR EACH xItem in ::aItem
      EnableWindow( xItem[ 11 ], .F. )
   NEXT

   RETURN Self

METHOD EnableButtons(n) class htoolbar

   EnableWindow( ::aItem[n, 11 ], .T. )

   RETURN Self

METHOD DisableButtons(n) class htoolbar

   EnableWindow( ::aItem[n, 11 ], .T. )

   RETURN Self
