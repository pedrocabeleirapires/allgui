/*
* $Id: hcheck.prg,v 1.23 2008/09/01 19:00:18 mlacecilia Exp $
* HWGUI - Harbour Win32 GUI library source code:
* HCheckButton class
* Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

CLASS HCheckButton INHERIT HControl

CLASS VAR winclass   INIT "BUTTON"

   DATA bSetGet
   DATA value
   DATA lEnter
   DATA lnoValid    INIT .F.

METHOD New( oWndParent,nId,vari,bSetGet,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont, ;
      bInit,bSize,bPaint,bClick,ctooltip,tcolor,bcolor,bGFocus, lEnter )

METHOD Activate()

METHOD Redefine( oWnd,nId,vari,bSetGet,oFont,bInit,bSize,bPaint,bClick,ctooltip,tcolor,bcolor,bGFocus , lEnter )

METHOD Init()

METHOD Refresh()

METHOD Disable()

METHOD Enable()

METHOD SetValue( lValue )  INLINE SendMessage(::handle,BM_SETCHECK,Iif(lValue,1,0),0), ::value := lValue

METHOD GetValue()          INLINE ( SendMessage(::handle,BM_GETCHECK,0,0)==1 )

METHOD KillFocus()

ENDCLASS

METHOD New( oWndParent,nId,vari,bSetGet,nStyle,nLeft,nTop,nWidth,nHeight,cCaption,oFont, ;
      bInit,bSize,bPaint,bClick,ctooltip,tcolor,bcolor,bGFocus,lEnter  ) CLASS HCheckButton

   nStyle   := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), BS_NOTIFY+BS_PUSHBUTTON+BS_AUTOCHECKBOX+WS_TABSTOP )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
      bSize,bPaint,ctooltip,tcolor,bcolor )

   ::title   := cCaption
   ::value   := Iif( vari==Nil .OR. Valtype(vari)!="L",.F.,vari )
   ::bSetGet := bSetGet

   ::Activate()

   ::lEnter     := Iif( lEnter==Nil .OR. Valtype(lEnter)!="L",.F.,lEnter )
   ::bLostFocus := bClick
   ::bGetFocus  := bGFocus

   IF bGFocus != Nil
      ::oParent:AddEvent( BN_SETFOCUS,self,{|o,id|__When(o:FindControl(id))},,"onGotFocus" )
      ::lnoValid := .T.
   ENDIF

   ::oParent:AddEvent( BN_CLICKED,self,{|o,id|__Valid(o:FindControl(id),)},,"onClick" )
   ::oParent:AddEvent( BN_KILLFOCUS,self,{|| ::KILLFOCUS()})

   RETURN Self

METHOD Activate CLASS HCheckButton

   IF !empty( ::oParent:handle )
      ::handle := CreateButton( ::oParent:handle, ::id, ;
         ::style, ::nLeft, ::nTop, ::nWidth, ::nHeight, ::title )
      ::Init()
   ENDIF

   RETURN NIL

METHOD Redefine( oWndParent,nId,vari,bSetGet,oFont,bInit,bSize,bPaint,bClick,ctooltip,tcolor,bcolor,bGFocus, lEnter ) CLASS HCheckButton

   Super:New( oWndParent,nId,0,0,0,0,0,oFont,bInit, ;
      bSize,bPaint,ctooltip,tcolor,bcolor )

   ::value   := Iif( vari==Nil .OR. Valtype(vari)!="L",.F.,vari )
   ::bSetGet := bSetGet
   ::lEnter     := Iif( lEnter==Nil .OR. Valtype(vari)!="L",.F.,lEnter )
   ::bLostFocus := bClick
   ::bGetFocus  := bGFocus
   ::oParent:AddEvent( BN_CLICKED,self,{|o,id|__Valid(o:FindControl(id))},,"onClick" )
   IF bGFocus != Nil
      ::oParent:AddEvent( BN_SETFOCUS,self,{|o,id|__When(o:FindControl(id))},,"onGotFocus" )
   ENDIF

   RETURN Self

METHOD Init() CLASS HCheckButton

   IF !::lInit
      Super:Init()
      IF ::value
         SendMessage(::handle,BM_SETCHECK,1,0)
      ENDIF
   ENDIF

   RETURN NIL

METHOD Refresh() CLASS HCheckButton

   LOCAL var

   IF ::bSetGet != Nil
      VAR := Eval( ::bSetGet,,nil )
      ::value := Iif( var==Nil,.F.,var )
   ENDIF

   SendMessage(::handle,BM_SETCHECK,Iif(::value,1,0),0)

   RETURN NIL

METHOD Disable() CLASS HCheckButton

   Super:Disable()
   SendMessage( ::handle,BM_SETCHECK,BST_INDETERMINATE,0 )

   RETURN NIL

METHOD Enable() CLASS HCheckButton

   Super:Enable()
   SendMessage(::handle,BM_SETCHECK,Iif(::value,1,0),0)

   RETURN NIL

METHOD killFocus() CLASS HCheckButton

   LOCAL ndown := getkeystate(VK_RIGHT)+getkeystate(VK_DOWN) +GetKeyState( VK_TAB )
   LOCAL nSkip := 0

   IF ::oParent:classname = "HTAB" //.AND. !getkeystate(VK_RETURN) < 0
      ///oCtrl:oparent:HANDLE)
      IF getkeystate(VK_LEFT) + getkeystate(VK_UP) < 0 .OR. ;
            (GetKeyState( VK_TAB ) < 0 .and. GetKeyState(VK_SHIFT) < 0 )
         nSkip := -1
      ELSEIF nDown < 0
         nSkip := 1
      ENDIF
      IF nSkip != 0
         SETFOCUS(::oParent:handle)
         GetSkip( ::oparent, ::handle, , nSkip )
      ENDIF
   ENDIF
   IF getkeystate(VK_RETURN) < 0 .AND. ::lEnter
      ::SetValue( !::GetValue() )
      __VALID(self)
   ENDIF

   RETURN NIL

STATIC FUNCTION __When( oCtrl )

   LOCAL res := .t., oParent, nSkip := 1

   IF !CheckFocus(oCtrl, .f.)

      RETURN .t.
   ENDIF
   nSkip := iif( GetKeyState( VK_UP ) < 0 .or. (GetKeyState( VK_TAB ) < 0 .and. GetKeyState(VK_SHIFT) < 0 ), -1, 1 )
   IF oCtrl:bGetFocus != Nil
      octrl:lnoValid := .T.
      octrl:oparent:lSuspendMsgsHandling := .t.
      res := Eval( oCtrl:bGetFocus, Eval( oCtrl:bSetGet, , oCtrl ), oCtrl )
      octrl:oparent:lSuspendMsgsHandling := .f.
      octrl:lnoValid := ! res
      IF ! res
         oParent := ParentGetDialog(oCtrl)
         IF oCtrl == ATail(oParent:GetList)
            nSkip := -1
         ELSEIF oCtrl == oParent:getList[1]
            nSkip := 1
         ENDIF
         GetSkip( oCtrl:oParent, oCtrl:handle, , nSkip )
      ENDIF
   ENDIF

   RETURN res

STATIC FUNCTION __Valid( oCtrl )

   LOCAL l := SendMessage( oCtrl:handle,BM_GETCHECK,0,0 )

   IF !CheckFocus(oCtrl, .t.)  .OR. oCtrl:lnoValid

      RETURN .T.
   ENDIF
   IF l == BST_INDETERMINATE
      CheckDlgButton( oCtrl:oParent:handle, oCtrl:id, .F. )
      SendMessage( oCtrl:handle,BM_SETCHECK,0,0 )
      oCtrl:value := .F.
   ELSE
      oCtrl:value := ( l == 1 )
   ENDIF
   IF oCtrl:bSetGet != Nil
      Eval( oCtrl:bSetGet,oCtrl:value, oCtrl )
   ENDIF
   IF oCtrl:bLostFocus != Nil
      octrl:oparent:lSuspendMsgsHandling := .t.
      Eval( oCtrl:bLostFocus, oCtrl:value,  oCtrl )
      octrl:oparent:lSuspendMsgsHandling := .f.
   ENDIF

   RETURN .T.
