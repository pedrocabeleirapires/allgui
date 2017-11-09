/*
* $Id: hdatepic.prg,v 1.18 2008/09/01 19:00:19 mlacecilia Exp $
* HWGUI - Harbour Win32 GUI library source code:
* HDatePicker class
* Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

#define DTN_DATETIMECHANGE    -759
#define DTN_CLOSEUP           -753
#define DTM_GETMONTHCAL       4104   // 0x1008
#define NM_KILLFOCUS          -8
#define NM_SETFOCUS           -7

CLASS HDatePicker INHERIT HControl

CLASS VAR winclass   INIT "SYSDATETIMEPICK32"

   DATA bSetGet
   DATA value
   DATA bChange
   DATA lnoValid       INIT .F.

METHOD New( oWndParent,nId,vari,bSetGet,nStyle,nLeft,nTop,nWidth,nHeight, ;
      oFont,bInit,bGfocus,bLfocus,bChange,ctooltip,tcolor,bcolor )

METHOD Activate()

METHOD Init()

METHOD Refresh()

METHOD Redefine( oWndParent,nId,vari,bSetGet,oFont,bInit, ;
      bGfocus,bLfocus,bChange,ctooltip,tcolor,bcolor)

ENDCLASS

METHOD New( oWndParent,nId,vari,bSetGet,nStyle,nLeft,nTop,nWidth,nHeight, ;
      oFont,bInit,bGfocus,bLfocus,bChange,ctooltip,tcolor,bcolor ) CLASS HDatePicker

   nStyle := Hwg_BitOr( Iif( nStyle==Nil,0,nStyle ), WS_TABSTOP )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
      ,,ctooltip,tcolor,bcolor )

   ::value   := Iif( vari==Nil .OR. Valtype(vari)!="D",CTOD(SPACE(8)),vari )
   ::bSetGet := bSetGet
   ::bChange := bChange

   HWG_InitCommonControlsEx()
   ::Activate()

   IF bSetGet != Nil
      ::bGetFocus := bGFocus
      ::bLostFocus := bLFocus
      ::oParent:AddEvent( NM_SETFOCUS,self,{|o,id|__When(o:FindControl(id))},.T.,"onGotFocus" )
      ::oParent:AddEvent( NM_KILLFOCUS,self,{|o,id|__Valid(o:FindControl(id))},.T.,"onLostFocus" )
   ELSE
      IF bGfocus != Nil
         ::lnoValid := .T.
         ::oParent:AddEvent( NM_SETFOCUS,self,bGfocus,.T.,"onGotFocus" )
      ENDIF
      IF bLfocus != Nil
         ::oParent:AddEvent( NM_KILLFOCUS,self,bLfocus,.T.,"onLostFocus" )
      ENDIF
   ENDIF
   ::oParent:AddEvent( DTN_DATETIMECHANGE,self,{|o,id|__Change(o:FindControl(id),DTN_DATETIMECHANGE)},.T.,"onChange" )
   ::oParent:AddEvent( DTN_CLOSEUP,self,{|o,id|__Change(o:FindControl(id),DTN_CLOSEUP)},.T.,"onClose" )

   RETURN Self

METHOD Activate CLASS HDatePicker

   IF !empty( ::oParent:handle )
      ::handle := CreateDatePicker( ::oParent:handle, ::id, ;
         ::nLeft, ::nTop, ::nWidth, ::nHeight, ::style )
      ::Init()
   ENDIF

   RETURN NIL

METHOD Init() CLASS HDatePicker

   IF !::lInit
      Super:Init()
      IF Empty( ::value )
         SetDatePickerNull( ::handle )
      ELSE
         SetDatePicker( ::handle,::value )
      ENDIF
   ENDIF

   RETURN NIL

METHOD Refresh() CLASS HDatePicker

   IF ::bSetGet != Nil
      ::value := Eval( ::bSetGet,,nil )
   ENDIF

   IF Empty(::value)
      SetDatePickerNull( ::handle )
   ELSE
      SetDatePicker( ::handle,::value )
   ENDIF

   RETURN NIL

METHOD Redefine( oWndParent,nId,vari,bSetGet,oFont,bSize,bInit, ;
      bGfocus,bLfocus,bChange,ctooltip,tcolor,bcolor) CLASS  HDatePicker
   Super:New( oWndParent,nId,0,0,0,0,0,oFont,bInit, ;
      bSize,,ctooltip,tcolor,bcolor )
   HWG_InitCommonControlsEx()
   ::value   := Iif( vari==Nil .OR. Valtype(vari)!="D",CTOD(SPACE(8)),vari )
   ::bSetGet := bSetGet
   ::bChange := bChange
   IF bGfocus != Nil
      ::oParent:AddEvent( NM_SETFOCUS,self,bGfocus,.T.,"onGotFocus" )
   ENDIF
   ::oParent:AddEvent( DTN_DATETIMECHANGE,self,{|o,id|__Change(o:FindControl(id),DTN_DATETIMECHANGE)},.T.,"onChange" )
   ::oParent:AddEvent( DTN_CLOSEUP,self,{|o,id|__Change(o:FindControl(id),DTN_CLOSEUP)},.T.,"onClose" )
   IF bSetGet != Nil
      ::bLostFocus := bLFocus
      ::oParent:AddEvent( NM_KILLFOCUS,self,{|o,id|__Valid(o:FindControl(id))},.T.,"onLostFocus" )
   ELSE
      IF bLfocus != Nil
         ::oParent:AddEvent( NM_KILLFOCUS,self,bLfocus,.T.,"onLostFocus" )
      ENDIF
   ENDIF

   RETURN self

STATIC FUNCTION __Change( oCtrl, nMess )

   IF ( nMess == DTN_DATETIMECHANGE .AND. ;
         SendMessage( oCtrl:handle,DTM_GETMONTHCAL,0,0 ) == 0 ) .OR. ;
         nMess == DTN_CLOSEUP
      oCtrl:value := GetDatePicker( oCtrl:handle )
      IF oCtrl:bSetGet != Nil
         Eval( oCtrl:bSetGet,oCtrl:value, oCtrl )
      ENDIF
      IF oCtrl:bChange != Nil
         octrl:oparent:lSuspendMsgsHandling := .T.
         Eval( oCtrl:bChange,oCtrl:value,oCtrl )
         octrl:oparent:lSuspendMsgsHandling := .F.
      ENDIF
   ENDIF

   RETURN .T.

STATIC FUNCTION __When( oCtrl )

   LOCAL res := .t., oParent, nSkip

   IF !CheckFocus(oCtrl, .f.)

      RETURN .t.
   ENDIF
   nSkip := iif( GetKeyState( VK_UP ) < 0 .or. (GetKeyState( VK_TAB ) < 0 .and. GetKeyState(VK_SHIFT) < 0 ), -1, 1 )
   IF oCtrl:bGetFocus != Nil
      octrl:oparent:lSuspendMsgsHandling := .T.
      octrl:lnoValid := .T.
      res :=  Eval( oCtrl:bGetFocus, oCtrl:value, oCtrl )
      octrl:oparent:lSuspendMsgsHandling := .F.
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

   LOCAL  res := .t.

   IF !CheckFocus(oCtrl, .t.)  .OR. oCtrl:lnoValid

      RETURN .T.
   ENDIF
   oCtrl:value := GetDatePicker( oCtrl:handle )
   IF oCtrl:bSetGet != Nil
      Eval( oCtrl:bSetGet,oCtrl:value, oCtrl )
   ENDIF
   IF oCtrl:bLostFocus != Nil
      octrl:oparent:lSuspendMsgsHandling := .T.
      res := Eval( oCtrl:bLostFocus, oCtrl:value,  oCtrl )
      octrl:oparent:lSuspendMsgsHandling := .F.
      IF ! res
         SetFocus( oCtrl:handle )
      ENDIF
   ENDIF

   RETURN res
