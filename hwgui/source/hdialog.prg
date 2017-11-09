/*
* $Id: hdialog.prg,v 1.71 2008/10/10 20:59:49 mlacecilia Exp $
* HWGUI - Harbour Win32 GUI library source code:
* HDialog class
* Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"
#include "common.ch"

#define  WM_PSPNOTIFY         WM_USER+1010

STATIC aSheet := Nil
STATIC aMessModalDlg := { ;
   { WM_COMMAND, { | o, w, l | DlgCommand( o, w, l ) } },         ;
   { WM_SIZE,{|o,w,l|onSize(o,w,l)} },                ;
   { WM_INITDIALOG,{|o,w,l|InitModalDlg(o,w,l)} },    ;
   { WM_ERASEBKGND,{|o,w|onEraseBk(o,w)} },           ;
   { WM_DESTROY,{|o|onDestroy(o)} },                  ;
   { WM_ENTERIDLE,{|o,w,l|onEnterIdle(o,w,l)} },      ;
   { WM_ACTIVATE,{|o,w,l|onActivate(o,w,l)} },        ;
   { WM_PSPNOTIFY,{|o,w,l|onPspNotify(o,w,l)} },      ;
   { WM_HELP,{|o,w,l|onHelp(o,w,l)} }                 ;
   }

STATIC FUNCTION onDestroy( oDlg )

   IF oDlg:oEmbedded != Nil
      oDlg:oEmbedded:End()
   ENDIF

   oDlg:Super:onEvent( WM_DESTROY )
   oDlg:Del()

   RETURN 0

   // Class HDialog

CLASS HDialog INHERIT HCustomWindow

CLASS VAR aDialogs       SHARED INIT {}

CLASS VAR aModalDialogs  SHARED INIT {}

   DATA menu
   DATA oPopup                // Context menu for a dialog
   DATA lModal   INIT .T.
   DATA lResult  INIT .F.     // Becomes TRUE if the OK button is pressed
   DATA lUpdated INIT .F.     // TRUE, if any GET is changed
   DATA lClipper INIT .F.     // Set it to TRUE for moving between GETs with ENTER key
   DATA GetList  INIT {}      // The array of GET items in the dialog
   DATA KeyList  INIT {}      // The array of keys ( as Clipper's SET KEY )
   DATA lExitOnEnter INIT .T. // Set it to False, if dialog shouldn't be ended after pressing ENTER key,
   // Added by Sandro Freire
   DATA lExitOnEsc   INIT .T. // Set it to False, if dialog shouldn't be ended after pressing ENTER key,
   // Added by Sandro Freire
   DATA lRouteCommand  INIT .F.
   DATA nLastKey INIT 0
   DATA oIcon, oBmp
   DATA bActivate
   DATA lActivated INIT .F.
   DATA xResourceID
   DATA oEmbedded
   DATA bOnActivate

METHOD New( lType,nStyle,x,y,width,height,cTitle,oFont,bInit,bExit,bSize, ;
      bPaint,bGfocus,bLfocus,bOther,lClipper,oBmp,oIcon,lExitOnEnter,nHelpId,xResourceID, lExitOnEsc ,bcolor)

METHOD Activate( lNoModal,bOnActivate )

METHOD onEvent( msg, wParam, lParam )

METHOD Add()      INLINE Aadd( Iif( ::lModal,::aModalDialogs,::aDialogs ), Self )

METHOD Del()

METHOD FindDialog( hWnd )

METHOD GetActive()

METHOD Center()   INLINE Hwg_CenterWindow( ::handle )

METHOD Restore()  INLINE SendMessage(::handle,  WM_SYSCOMMAND, SC_RESTORE, 0)

METHOD Maximize() INLINE SendMessage(::handle,  WM_SYSCOMMAND, SC_MAXIMIZE, 0)

METHOD Minimize() INLINE SendMessage(::handle,  WM_SYSCOMMAND, SC_MINIMIZE, 0)

METHOD Close()    INLINE EndDialog( ::handle )

   //METHOD Release()  INLINE Iif( ::lModal, Hwg_EndDialog( ::handle ), DestroyWindow( ::handle ) )

ENDCLASS

METHOD NEW( lType,nStyle,x,y,width,height,cTitle,oFont,bInit,bExit,bSize, ;
      bPaint,bGfocus,bLfocus,bOther,lClipper,oBmp,oIcon,lExitOnEnter,nHelpId, xResourceID, lExitOnEsc ,bcolor) CLASS HDialog

   ::oDefaultParent := Self
   ::xResourceID := xResourceID
   ::type     := lType
   ::title    := cTitle
   ::style    := Iif( nStyle==Nil,DS_ABSALIGN+WS_POPUP+WS_VISIBLE+WS_CAPTION+WS_SYSMENU,nStyle )
   ::oBmp     := oBmp
   ::oIcon    := oIcon
   ::nTop     := Iif( y==Nil,0,y )
   ::nLeft    := Iif( x==Nil,0,x )
   ::nWidth   := Iif( width==Nil,0,width )
   ::nHeight  := Iif( height==Nil,0,height )
   ::oFont    := oFont
   ::bInit    := bInit
   ::bDestroy := bExit
   ::bSize    := bSize
   ::bPaint   := bPaint
   ::bGetFocus  := bGFocus
   ::bLostFocus := bLFocus
   ::bOther     := bOther
   ::lClipper   := Iif( lClipper==Nil,.F.,lClipper )
   ::lExitOnEnter:=Iif( lExitOnEnter==Nil,.T.,!lExitOnEnter )
   ::lExitOnEsc  :=Iif( lExitOnEsc==Nil,.T.,!lExitOnEsc )

   IF nHelpId != nil
      ::HelpId := nHelpId
   END
   IF bColor != NIL
      ::brush := HBrush():Add(bcolor)
      ::bColor := bcolor
   ENDIF

   RETURN Self

METHOD Activate( lNoModal, bOnActivate ) CLASS HDialog

   LOCAL oWnd, hParent

   ::bOnActivate := bOnActivate
   CreateGetList( Self )
   hParent := IIf( ::oParent != Nil .AND. ;
      __ObjHasMsg( ::oParent, "HANDLE" ) .AND. ::oParent:handle != Nil ;
      .AND. ! Empty( ::oParent:handle ) , ::oParent:handle, ;
      IIf( ( oWnd := HWindow():GetMain() ) != Nil,    ;
      oWnd:handle, GetActiveWindow() ) )

   IF ::Type == WND_DLG_RESOURCE
      IF lNoModal == Nil .OR. ! lNoModal
         ::lModal := .T.
         ::Add()
         // Hwg_DialogBox( HWindow():GetMain():handle,Self )
         Hwg_DialogBox( GetActiveWindow(), Self )
      ELSE
         ::lModal  := .F.
         ::handle  := 0
         ::lResult := .F.
         ::Add()
         Hwg_CreateDialog( hParent, Self )
         /*
         IF ::oIcon != Nil
         SendMessage( ::handle,WM_SETICON,1,::oIcon:handle )
         ENDIF
         */
      ENDIF
      /*
      IF ::title != NIL
      SetWindowText( ::handle, ::title )
      ENDIF
      */

   ELSEIF ::Type == WND_DLG_NORESOURCE
      IF lNoModal == Nil .OR. ! lNoModal
         ::lModal := .T.
         ::Add()
         // Hwg_DlgBoxIndirect( HWindow():GetMain():handle,Self,::nLeft,::nTop,::nWidth,::nHeight,::style )
         Hwg_DlgBoxIndirect( GetActiveWindow(), Self, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::style )
      ELSE
         ::lModal  := .F.
         ::handle  := 0
         ::lResult := .F.
         ::Add()
         Hwg_CreateDlgIndirect( hParent, Self, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::style )
         /*
         IF ::oIcon != Nil
         SendMessage( ::handle,WM_SETICON,1,::oIcon:handle )
         ENDIF
         */
      ENDIF
   ENDIF

   RETURN NIL

METHOD onEvent( msg, wParam, lParam ) CLASS HDialog

   LOCAL i, oTab, nPos

   IF msg = WM_GETMINMAXINFO
      IF ::minWidth  > -1 .OR. ::maxWidth  > -1 .OR.;
            ::minHeight > -1 .OR. ::maxHeight > -1
         MINMAXWINDOW(::handle, lParam,;
            IIF(::minWidth  > -1,::minWidth,nil),;
            IIF(::minHeight > -1,::minHeight,nil),;
            IIF(::maxWidth  > -1,::maxWidth,nil),;
            IIF(::maxHeight > -1,::maxHeight,nil))

         RETURN 0
      ENDIF
   ENDIF

   IF ( i := Ascan( aMessModalDlg, {|a|a[1]==msg} ) ) != 0
      IF ::lRouteCommand .and. (msg ==WM_COMMAND .or. msg == WM_NOTIFY)
         nPos := ascan(::aControls,{|x| x:className() == "HTAB"})
         IF nPos > 0
            oTab := ::aControls[ nPos ]
            IF len(oTab:aPages) > 0
               eval( aMessModalDlg[i,2], oTab:aPages[oTab:GetActivePage(),1], wParam, lParam )
            ENDIF
         ENDIF
      ENDIF
      //AgE SOMENTE NO DIALOG
      IF !::lSuspendMsgsHandling .OR. msg = WM_ERASEBKGND .OR. msg = WM_SIZE
         //writelog( str(msg) + str(wParam) + str(lParam)+CHR(13) )

         RETURN Eval( aMessModalDlg[i,2], Self, wParam, lParam )
      ENDIF
   ELSE
      IF msg == WM_HSCROLL .OR. msg == WM_VSCROLL .or. msg == WM_MOUSEWHEEL
         onTrackScroll( Self,msg,wParam,lParam )
      ENDIF

      RETURN Super:onEvent( msg, wParam, lParam )
   ENDIF

   RETURN 0

METHOD Del() CLASS HDialog

   LOCAL i

   IF ::lModal
      IF ( i := Ascan( ::aModalDialogs,{|o|o==Self} ) ) > 0
         Adel( ::aModalDialogs,i )
         Asize( ::aModalDialogs, Len(::aModalDialogs)-1 )
      ENDIF
   ELSE
      IF ( i := Ascan( ::aDialogs,{|o|o==Self} ) ) > 0
         Adel( ::aDialogs,i )
         Asize( ::aDialogs, Len(::aDialogs)-1 )
      ENDIF
   ENDIF

   RETURN NIL

METHOD FindDialog( hWnd ) CLASS HDialog

   LOCAL i := Ascan( ::aDialogs, {|o|o:handle==hWnd} )

   RETURN Iif( i == 0, Nil, ::aDialogs[i] )

METHOD GetActive() CLASS HDialog

   LOCAL handle := GetFocus()
   LOCAL i := Ascan( ::Getlist,{|o|o:handle==handle} )

   RETURN Iif( i == 0, Nil, ::Getlist[i] )

   // End of class
   // ------------------------------------

STATIC FUNCTION InitModalDlg( oDlg,wParam,lParam )

   LOCAL nReturn := 1

   HB_SYMBOL_UNUSED(wParam)
   HB_SYMBOL_UNUSED(lParam)

   // oDlg:handle := hDlg
   // writelog( str(oDlg:handle)+" "+oDlg:title )
   *  .if uMsg == WM_INITDIALOG
   *-EnableThemeDialogTexture(odlg:handle,6)  //,ETDT_ENABLETAB)

   IF Valtype( oDlg:menu ) == "A"
      hwg__SetMenu( oDlg:handle, oDlg:menu[5] )
   ENDIF

   InitControls( oDlg,.T. )

   IF oDlg:oIcon != Nil
      SendMessage( oDlg:handle,WM_SETICON,1,oDlg:oIcon:handle )
   ENDIF
   IF oDlg:Title != NIL
      SetWindowText(oDlg:Handle,oDlg:Title)
   ENDIF
   IF oDlg:oFont != Nil
      SendMessage( oDlg:handle, WM_SETFONT, oDlg:oFont:handle, 0 )
   ENDIF

   IF oDlg:bInit != Nil
      oDlg:lSuspendMsgsHandling := .t.
      IF Valtype(nReturn := Eval( oDlg:bInit, oDlg )) != "N"
         nReturn := 1
      ENDIF
      oDlg:lSuspendMsgsHandling := .F.
   ENDIF
   IF Valtype(oDlg:bOnActivate) == "B"
      eval(oDlg:bOnActivate)
   ENDIF

   IF oDlg:bGetFocus != Nil
      oDlg:lSuspendMsgsHandling := .t.
      Eval( oDlg:bGetFocus, oDlg )
      oDlg:lSuspendMsgsHandling := .f.
   ENDIF

   SetFocus(oDlg:handle)

   RETURN nReturn

STATIC FUNCTION onEnterIdle( oDlg, wParam, lParam )

   LOCAL oItem

   HB_SYMBOL_UNUSED(oDlg)

   IF wParam == 0 .AND. ( oItem := Atail( HDialog():aModalDialogs ) ) != Nil ;
         .AND. oItem:handle == lParam .AND. !oItem:lActivated
      oItem:lActivated := .T.
      IF oItem:bActivate != Nil
         Eval( oItem:bActivate, oItem )
      ENDIF
   ENDIF

   RETURN 0

STATIC FUNCTION onEraseBk( oDlg,hDC )

   LOCAL aCoors

   IF __ObjHasMsg( oDlg,"OBMP")
      IF oDlg:oBmp != Nil
         SpreadBitmap( hDC, oDlg:handle, oDlg:oBmp:handle )

         RETURN 1
      ELSE
         aCoors := GetClientRect( oDlg:handle )
         IF oDlg:brush != Nil
            IF Valtype( oDlg:brush ) != "N"
               FillRect( hDC, aCoors[1],aCoors[2],aCoors[3]+1,aCoors[4]+1,oDlg:brush:handle )
            ENDIF
         ELSE
            FillRect( hDC, aCoors[1],aCoors[2],aCoors[3]+1,aCoors[4]+1,COLOR_3DFACE+1 )
         ENDIF

         RETURN 1
      ENDIF
   ENDIF

   RETURN 0

   #define  FLAG_CHECK      2

FUNCTION DlgCommand( oDlg,wParam,lParam )

   LOCAL iParHigh := HiWord( wParam ), iParLow := LoWord( wParam )
   LOCAL aMenu, i, hCtrl, oCtrl, nEsc := .F.

   HB_SYMBOL_UNUSED(lParam)

   IF iParHigh == 0
      IF iParLow == IDOK
         hCtrl := GetFocus()
         oCtrl := oDlg:FindControl(,hctrl)
         IF oCtrl == nil
            hCtrl := GetAncestor(hCtrl, GA_PARENT)
            IF ( oCtrl := oDlg:FindControl( , hCtrl ) ) != Nil
               GetSkip( oCtrl:oParent, hCtrl, , 1 )
            ENDIF
         ENDIF

         IF oCtrl != Nil .AND. octrl:classname = "HTAB"

            RETURN 1
         ENDIF
         IF oCtrl != Nil .AND. GetNextDlgTabItem( GetActiveWindow() , hctrl, 1) == hCtrl
            *IF __ObjHasMsg(oCtrl,"BVALID") .AND. oCtrl:bValid != NIl
            IF  __ObjHasMsg(oCtrl,"BLOSTFOCUS") .AND. oCtrl:blostfocus != NIl
               *oDlg:lSuspendMsgsHandling := .T.
               * EVAL(OCTRL:BLOSTFOCUS,OCTRL)
               *oDlg:lSuspendMsgsHandling := .F.
               oCtrl:setfocus()
               Eval( oCtrl:bValid, oCtrl )
            ENDIF
         ENDIF
         IF oCtrl != Nil .AND. oCtrl:id == IDOK //iParLow
            oDlg:lResult := .T.
         EndDialog( oDlg:handle )   // VER AQUI
      ENDIF
      /*
      IF !oDlg:lExitOnEnter .AND. lParam > 0 .AND. lParam != hCtrl
      IF oCtrl:oParent:oParent != Nil
      GetSkip( oCtrl:oParent, hCtrl, , 1)
      eNDIF

      RETURN 0
      ENDIF
      */
      IF oDlg:lClipper
         IF oCtrl != Nil .AND. !GetSkip( oCtrl:oParent, hCtrl, , 1)
            IF oDlg:lExitOnEnter
               oDlg:lResult := .T.
            EndDialog( oDlg:handle )
         ENDIF
      ENDIF
      //setfocus(odlg:handle)

      RETURN 1
   ENDIF
ELSEIF iParLow == IDCANCEL
   nEsc := ( getkeystate( VK_ESCAPE ) < 0 )
   oDlg:nLastKey := 27
ENDIF

ENDIF

IF (VALTYPE(oDlg:nInitFocus) = "O" .OR. oDlg:nInitFocus > 0) .AND.!isWindowVisible(oDlg:handle)
   oDlg:nInitFocus := IIF(VALTYPE(oDlg:nInitFocus) = "O", oDlg:nInitFocus:Handle,oDlg:nInitFocus)
   //SETFOCUS(oDlg:nInitFocus)
   PostMessage( GetActiveWindow(), WM_NEXTDLGCTL, oDlg:nInitFocus , 1 )

   RETURN 1
ENDIF

IF oDlg:aEvents != Nil .AND. ! oDlg:lSuspendMsgsHandling .AND. oDlg:nInitFocus == 0 .AND. ;
      ( i := Ascan( oDlg:aEvents, {|a|a[1]==iParHigh.and.a[2]==iParLow} ) ) > 0
   Eval( oDlg:aEvents[ i,3 ],oDlg,iParLow )

ELSEIF iParHigh == 0 .AND. !oDlg:lSuspendMsgsHandling .AND. ( ;
      ( iParLow == IDOK .AND. oDlg:FindControl(IDOK) != nil ) .OR. ;
      iParLow == IDCANCEL )
   IF iParLow == IDOK
      oDlg:lResult := .T.
   ENDIF
   //Replaced by Sandro
   IF oDlg:lExitOnEsc .OR. !nEsc
   EndDialog( oDlg:handle )
ENDIF
ELSEIF __ObjHasMsg(oDlg,"MENU") .AND. Valtype( oDlg:menu ) == "A" .AND. ;
   ( aMenu := Hwg_FindMenuItem( oDlg:menu,iParLow,@i ) ) != Nil
IF Hwg_BitAnd( aMenu[ 1,i,4 ],FLAG_CHECK ) > 0
   CheckMenuItem( ,aMenu[1,i,3], !IsCheckedMenuItem( ,aMenu[1,i,3] ) )
ENDIF
IF aMenu[ 1,i,1 ] != Nil
   Eval( aMenu[ 1,i,1 ] )
ENDIF
ELSEIF __ObjHasMsg(oDlg,"OPOPUP") .AND. oDlg:oPopup != Nil .AND. ;
   ( aMenu := Hwg_FindMenuItem( oDlg:oPopup:aMenu,wParam,@i ) ) != Nil ;
   .AND. aMenu[ 1,i,1 ] != Nil
Eval( aMenu[ 1,i,1 ] )
ENDIF

IF  __ObjHasMsg(oDlg,"NINITFOCUS") .AND. oDlg:nInitFocus > 0
   oDlg:nInitFocus := 0
ENDIF

RETURN 1

FUNCTION DlgMouseMove()

   LOCAL oBtn := SetNiceBtnSelected()

   IF oBtn != Nil .AND. !oBtn:lPress
      oBtn:state := OBTN_NORMAL
      InvalidateRect( oBtn:handle, 0 )
      * PostMessage( oBtn:handle, WM_PAINT, 0, 0 )
      SetNiceBtnSelected( Nil )
   ENDIF

   RETURN 0

STATIC FUNCTION onSize( oDlg,wParam,lParam )

   LOCAL aControls, iCont , nW1, nH1
   LOCAL nW := LoWord( lParam ), nH := HiWord( lParam )

   HB_SYMBOL_UNUSED(wParam)

   IF oDlg:oEmbedded != Nil
      oDlg:oEmbedded:Resize( LoWord( lParam ), HiWord( lParam ) )
   ENDIF
   // VERIFY MIN SIZES AND MAX SIZES
   IF (oDlg:nHeight = oDlg:minHeight .AND. nH < oDlg:minHeight).OR.;
         (oDlg:nHeight = oDlg:maxHeight .AND. nH > oDlg:maxHeight) .OR.;
         (oDlg:nWidth = oDlg:minWidth .AND. nW < oDlg:minWidth) .OR.;
         (oDlg:nWidth = oDlg:maxWidth .AND. nW > oDlg:maxWidth)

      RETURN 0
   ENDIF
   nw1 := oDlg:nWidth
   nh1 := oDlg:nHeight
   *aControls := GetWindowRect( oDlg:handle )
   oDlg:nWidth := LoWord( lParam )  //aControls[3]-aControls[1]
   oDlg:nHeight := HiWord( lParam ) //aControls[4]-aControls[2]
   IF oDlg:bSize != Nil .AND. ;
         ( oDlg:oParent == Nil .OR. !__ObjHasMsg( oDlg:oParent,"ACONTROLS" ) )
      Eval( oDlg:bSize, oDlg, LoWord( lParam ), HiWord( lParam ) )
   ENDIF
   aControls := oDlg:aControls
   IF aControls != Nil
      oDlg:Anchor(odlg,nw1,nh1, oDlg:nWidth, oDlg:nHeight )
      FOR iCont := 1 TO Len( aControls )
         IF aControls[iCont]:bSize != Nil
            Eval( aControls[iCont]:bSize, ;
               aControls[iCont], LoWord( lParam ), HiWord( lParam ), nw1, nh1 )
         ENDIF
      NEXT
   ENDIF

   RETURN 0

STATIC FUNCTION onActivate( oDlg,wParam,lParam )

   LOCAL iParLow := LoWord( wParam )

   HB_SYMBOL_UNUSED(lParam)

   IF iParLow > 0 .AND. oDlg:bGetFocus != Nil .AND. IsWindowVisible(odlg:handle)
      oDlg:lSuspendMsgsHandling := .t.
      Eval( oDlg:bGetFocus, oDlg )
      oDlg:lSuspendMsgsHandling := .f.
   ELSEIF iParLow == 0 .AND. oDlg:bLostFocus != Nil
      oDlg:lSuspendMsgsHandling := .t.
      Eval( oDlg:bLostFocus, oDlg )
      oDlg:lSuspendMsgsHandling := .f.
   ENDIF

   RETURN 0

STATIC FUNCTION onHelp( oDlg,wParam,lParam )

   LOCAL oCtrl, nHelpId, oParent

   HB_SYMBOL_UNUSED(wParam)

   IF ! Empty(SetHelpFileName())
      oCtrl := oDlg:FindControl( nil, GetHelpData( lParam ) )
      IF oCtrl != nil
         nHelpId := oCtrl:HelpId
         IF Empty( nHelpId )
            oParent := oCtrl:oParent
            nHelpId := oParent:HelpId
         ENDIF

         WinHelp( oDlg:handle, SetHelpFileName(), iif( Empty(nHelpId), 3, 1), nHelpId)

      ENDIF
   ENDIF

   RETURN 0

STATIC FUNCTION onPspNotify( oDlg,wParam,lParam )

   LOCAL nCode := GetNotifyCode( lParam ), res := .T.

   HB_SYMBOL_UNUSED(wParam)

   IF nCode == PSN_SETACTIVE //.AND. !oDlg:aEvdisable
      IF oDlg:bGetFocus != Nil
         oDlg:lSuspendMsgsHandling := .T.
         res := Eval( oDlg:bGetFocus, oDlg )
         oDlg:lSuspendMsgsHandling := .F.
      ENDIF
      // 'res' should be 0(Ok) or -1

      Hwg_SetDlgResult( oDlg:handle,Iif(res,0,-1) )

      RETURN 1
   ELSEIF nCode == PSN_KILLACTIVE //.AND. !oDlg:aEvdisable
      IF oDlg:bLostFocus != Nil
         oDlg:lSuspendMsgsHandling := .T.
         res := Eval( oDlg:bLostFocus, oDlg )
         oDlg:lSuspendMsgsHandling := .F.
      ENDIF
      // 'res' should be 0(Ok) or 1
      Hwg_SetDlgResult( oDlg:handle,Iif(res,0,1) )

      RETURN 1
   ELSEIF nCode == PSN_RESET
   ELSEIF nCode == PSN_APPLY
      IF oDlg:bDestroy != Nil
         res := Eval( oDlg:bDestroy, oDlg )
      ENDIF
      // 'res' should be 0(Ok) or 2
      Hwg_SetDlgResult( oDlg:handle,Iif(res,0,2) )
      IF res
         oDlg:lResult := .T.
      ENDIF

      RETURN 1
   ELSE
      IF oDlg:bOther != Nil
         res := Eval( oDlg:bOther, oDlg, WM_NOTIFY, 0, lParam )
         Hwg_SetDlgResult( oDlg:handle,Iif(res,0,1) )

         RETURN 1
      ENDIF
   ENDIF

   RETURN 0

FUNCTION PropertySheet( hParentWindow, aPages, cTitle, x1, y1, width, height, ;
      lModeless, lNoApply, lWizard )
   LOCAL hSheet, i, aHandles := Array( Len( aPages ) ), aTemplates := Array( Len( aPages ) )

   aSheet := Array( Len( aPages ) )
   FOR i := 1 TO Len( aPages )
      IF aPages[i]:type == WND_DLG_RESOURCE
         aHandles[i] := _CreatePropertySheetPage( aPages[i] )
      ELSE
         aTemplates[i] := CreateDlgTemplate( aPages[i],x1,y1,width,height,WS_CHILD+WS_VISIBLE+WS_BORDER )
         aHandles[i] := _CreatePropertySheetPage( aPages[i],aTemplates[i] )
      ENDIF
      aSheet[i] := { aHandles[i], aPages[i] }
      // Writelog( "h: "+str(aHandles[i]) )
   NEXT
   hSheet := _PropertySheet( hParentWindow, aHandles, Len( aHandles ), cTitle, ;
      lModeless, lNoApply, lWizard )
   FOR i := 1 TO Len( aPages )
      IF aPages[i]:type != WND_DLG_RESOURCE
         ReleaseDlgTemplate( aTemplates[i] )
      ENDIF
   NEXT

   RETURN hSheet

FUNCTION GetModalDlg

   LOCAL i := Len( HDialog():aModalDialogs )

   RETURN Iif( i>0, HDialog():aModalDialogs[i], 0 )

FUNCTION GetModalHandle

   LOCAL i := Len( HDialog():aModalDialogs )

   RETURN Iif( i>0, HDialog():aModalDialogs[i]:handle, 0 )

FUNCTION EndDialog( handle )

   LOCAL oDlg
   LOCAL res

   IF handle == Nil
      IF ( oDlg := Atail( HDialog():aModalDialogs ) ) == Nil

         RETURN NIL
      ENDIF
   ELSE
      IF ( ( oDlg := Atail( HDialog():aModalDialogs ) ) == Nil .OR. ;
            oDlg:handle != handle ) .AND. ;
            ( oDlg := HDialog():FindDialog(handle) ) == Nil

         RETURN NIL
      ENDIF
   ENDIF
   IF oDlg:bDestroy != Nil
      oDlg:lSuspendMsgsHandling := .T.
      res := Eval( oDlg:bDestroy, oDlg )
      oDlg:lSuspendMsgsHandling := .F.
      IF !res
         oDlg:nLastKey := 0

         RETURN NIL
      ENDIF
   ENDIF

   RETURN  Iif( oDlg:lModal, Hwg_EndDialog( oDlg:handle ), DestroyWindow( oDlg:handle ) )

FUNCTION SetDlgKey( oDlg, nctrl, nkey, block )

   LOCAL i, aKeys, bOldSet

   IF oDlg == Nil ; oDlg := HCustomWindow():oDefaultParent ; ENDIF
      IF nctrl == Nil ; nctrl := 0 ; ENDIF

         IF !__ObjHasMsg( oDlg,"KEYLIST" )

            RETURN NIL
         ENDIF
         aKeys := oDlg:KeyList
         IF (i := Ascan( aKeys,{|a|a[1]==nctrl.AND.a[2]==nkey} )) > 0
            bOldSet := aKeys[i,3]
         ENDIF
         IF block == Nil
            IF i > 0
               Adel( oDlg:KeyList, i )
               Asize( oDlg:KeyList, Len(oDlg:KeyList)-1 )
            ENDIF
         ELSE
            IF i == 0
               Aadd( aKeys, { nctrl,nkey,block } )
            ELSE
               aKeys[i,3] := block
            ENDIF
         ENDIF

         RETURN bOldSet

         EXIT PROCEDURE Hwg_ExitProcedure
         Hwg_ExitProc()

         RETURN

