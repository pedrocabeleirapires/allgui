/*
* $Id: guimain.prg,v 1.27 2008/10/07 12:37:49 lculik Exp $
* HWGUI - Harbour Win32 GUI library source code:
* Main prg level functions
* Copyright 2001 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://kresin.belgorod.su
*/

#include "windows.ch"
#include "guilib.ch"
#include "common.ch"

FUNCTION InitControls( oWnd,lNoActivate )

   LOCAL i, pArray := oWnd:aControls, lInit

   lNoActivate := Iif( lNoActivate==Nil,.F.,lNoActivate )

   IF pArray != Nil
      FOR i := 1 TO Len( pArray )
         // writelog( "InitControl1"+str(pArray[i]:handle)+"/"+pArray[i]:classname+" "+str(pArray[i]:nWidth)+"/"+str(pArray[i]:nHeight) )
         IF empty(pArray[i]:handle)  .AND. !lNoActivate
            //         IF empty(pArray[i]:handle ) .AND. !lNoActivate
            lInit := pArray[i]:lInit
            pArray[i]:lInit := .T.
            pArray[i]:Activate()
            pArray[i]:lInit := lInit

         ENDIF
         //           IF empty(pArray[i]:handle)// <= 0
         IF if(valtype(pArray[i]:handle)=="P",ptrtoulong(pArray[i]:handle),pArray[i]:handle ) <= 0
            pArray[i]:handle := GetDlgItem( oWnd:handle, pArray[i]:id )

            // writelog( "InitControl2"+str(pArray[i]:handle)+"/"+pArray[i]:classname )
         ENDIF
         IF !Empty( pArray[i]:aControls )
            InitControls( pArray[i] )
         ENDIF
         pArray[i]:Init()
      NEXT
   ENDIF

   RETURN .T.

FUNCTION FindParent( hCtrl,nLevel )

   LOCAL i, oParent, hParent := GetParent( hCtrl )

   IF hParent > 0
      IF ( i := Ascan( HDialog():aModalDialogs,{|o|o:handle==hParent} ) ) != 0

         RETURN HDialog():aModalDialogs[i]
      ELSEIF ( oParent := HDialog():FindDialog(hParent) ) != Nil

         RETURN oParent
      ELSEIF ( oParent := HWindow():FindWindow(hParent) ) != Nil

         RETURN oParent
      ENDIF
   ENDIF
   IF nLevel == Nil; nLevel := 0; ENDIF
      IF nLevel < 2
         IF ( oParent := FindParent( hParent,nLevel+1 ) ) != Nil

            RETURN oParent:FindControl( ,hParent )
         ENDIF
      ENDIF

      RETURN NIL

FUNCTION FindSelf( hCtrl )

   LOCAL oParent

   oParent := FindParent( hCtrl )
   IF oParent == Nil
      oParent := GetAncestor(hCtrl, GA_PARENT)
   ENDIF
   IF oParent != Nil

      RETURN oParent:FindControl( ,hCtrl )
   ENDIF

   RETURN NIL

FUNCTION WriteStatus( oWnd, nPart, cText, lRedraw )

   LOCAL aControls, i

   aControls := oWnd:aControls
   IF ( i := Ascan( aControls, {|o|o:ClassName()=="HSTATUS"} ) ) > 0
      WriteStatusWindow( aControls[i]:handle,nPart-1,cText )
      IF lRedraw != Nil .AND. lRedraw
         RedrawWindow( aControls[i]:handle, RDW_ERASE + RDW_INVALIDATE )
      ENDIF
   ENDIF

   RETURN NIL

FUNCTION ReadStatus( oWnd, nPart)

   LOCAL aControls, i, ntxtLen, cText := ""

   aControls := oWnd:aControls
   IF ( i := Ascan( aControls, {|o|o:ClassName()=="HSTATUS"} ) ) > 0
      ntxtLen := SendMessage(aControls[i]:handle,SB_GETTEXTLENGTH, nPart-1, 0)
      cText := replicate(chr(0),ntxtLen)
      SendMessage( aControls[i]:handle, SB_GETTEXT, nPart-1, @cText )
   ENDIF

   RETURN cText

FUNCTION VColor( cColor )

   LOCAL i,res := 0, n := 1, iValue

   cColor := Trim(cColor)
   FOR i := 1 to Len( cColor )
      iValue := Asc( Substr( cColor,Len(cColor)-i+1,1 ) )
      IF iValue < 58 .and. iValue > 47
         iValue -= 48
      ELSEIF iValue >= 65 .and. iValue <= 70
         iValue -= 55
      ELSEIF iValue >= 97 .and. iValue <= 102
         iValue -= 87
      ELSE

         RETURN 0
      ENDIF
      res += iValue * n
      n *= 16
   NEXT

   RETURN res

FUNCTION MsgGet( cTitle, cText, nStyle, x, y, nDlgStyle, cResIni )

   LOCAL oModDlg, oFont := HFont():Add( "MS Sans Serif",0,-13 )
   LOCAL cRes := IIF(cResIni != Nil, Trim(cResIni), "")

   IF !Empty(cRes)
      Keyb_Event(VK_END)
   ENDIF
   nStyle := Iif( nStyle == Nil, 0, nStyle )
   x := Iif( x == Nil, 210, x )
   y := Iif( y == Nil, 10, y )
   nDlgStyle := Iif( nDlgStyle == Nil, 0, nDlgStyle )

   INIT DIALOG oModDlg TITLE cTitle AT x,y SIZE 300,140 ;
      FONT oFont CLIPPER STYLE WS_POPUP+WS_VISIBLE+WS_CAPTION+WS_SYSMENU+WS_SIZEBOX+nDlgStyle

   @ 20,10 SAY cText SIZE 260,22
   @ 20,35 GET cres  SIZE 260,26 STYLE WS_TABSTOP + nStyle

   @ 20,95 BUTTON "Ok" ID IDOK SIZE 100,32
   @ 180,95 BUTTON "Cancel" ID IDCANCEL SIZE 100,32

   ACTIVATE DIALOG oModDlg

   oFont:Release()
   IF oModDlg:lResult

      RETURN Trim( cRes )
   ELSE
      cRes := ""
   ENDIF

   RETURN cRes

FUNCTION WChoice( arr, cTitle, nLeft, nTop, oFont, clrT, clrB, clrTSel, clrBSel, cOk, cCancel )

   LOCAL oDlg, oBrw, nChoice := 0, lArray := .T., nField, lNewFont := .F.
   LOCAL i, aLen, nLen := 0, addX := 20, addY := 20, minWidth := 0, x1
   LOCAL hDC, aMetr, width, height, aArea, aRect
   LOCAL nStyle := WS_POPUP+WS_VISIBLE+WS_CAPTION+WS_SYSMENU+WS_SIZEBOX

   IF cTitle == Nil; cTitle := ""; ENDIF
      IF nLeft == Nil .AND. nTop == Nil; nStyle += DS_CENTER; ENDIF
         IF nLeft == Nil; nLeft := 0; ENDIF
            IF nTop == Nil; nTop := 0; ENDIF
               IF oFont == Nil
                  oFont := HFont():Add( "MS Sans Serif",0,-13 )
                  lNewFont := .T.
               ENDIF
               IF cOk != Nil
                  minWidth += 120
                  IF cCancel != Nil
                     minWidth += 100
                  ENDIF
                  addY += 30
               ENDIF

               IF Valtype( arr ) == "C"
                  lArray := .F.
                  aLen := RecCount()
                  IF ( nField := FieldPos( arr ) ) == 0

                     RETURN 0
                  ENDIF
                  nLen := dbFieldInfo( 3,nField )
               ELSE
                  aLen := Len( arr )
                  IF Valtype( arr[1] ) == "A"
                     FOR i := 1 TO aLen
                        nLen := Max( nLen,Len(arr[i,1]) )
                     NEXT
                  ELSE
                     FOR i := 1 TO aLen
                        nLen := Max( nLen,Len(arr[i]) )
                     NEXT
                  ENDIF
               ENDIF

               hDC := GetDC( GetActiveWindow() )
               SelectObject( hDC, ofont:handle )
               aMetr := GetTextMetric( hDC )
               aArea := GetDeviceArea( hDC )
               aRect := GetWindowRect( GetActiveWindow() )
               ReleaseDC( GetActiveWindow(),hDC )
               height := (aMetr[1]+1)*aLen+4+addY+8
               IF height > aArea[2]-aRect[2]-nTop-60
                  height := aArea[2]-aRect[2]-nTop-60
               ENDIF
               width := Max( aMetr[2] * 2 * nLen + addX, minWidth )

               INIT DIALOG oDlg TITLE cTitle ;
                  AT nLeft,nTop           ;
                  SIZE width,height       ;
                  STYLE nStyle            ;
                  FONT oFont              ;
                  ON INIT {|o|ResetWindowPos(o:handle),oBrw:setfocus()}

               IF lArray
                  @ 0,0 BROWSE oBrw ARRAY
                  oBrw:aArray := arr
                  IF Valtype( arr[1] ) == "A"
                     oBrw:AddColumn( HColumn():New( ,{|value,o|HB_SYMBOL_UNUSED(value),o:aArray[o:nCurrent,1]},"C",nLen ) )
                  ELSE
                     oBrw:AddColumn( HColumn():New( ,{|value,o|HB_SYMBOL_UNUSED(value),o:aArray[o:nCurrent]},"C",nLen ) )
                  ENDIF
               ELSE
                  @ 0,0 BROWSE oBrw DATABASE
                  oBrw:AddColumn( HColumn():New( ,{|value,o|HB_SYMBOL_UNUSED(value),(o:alias)->(FieldGet(nField))},"C",nLen ) )
               ENDIF

               oBrw:oFont  := oFont
               oBrw:bSize  := {|o,x,y|MoveWindow(o:handle,addX/2,10,x-addX,y-addY)}
               oBrw:bEnter := {|o|nChoice:=o:nCurrent,EndDialog(o:oParent:handle)}

               oBrw:lDispHead := .F.
               IF clrT != Nil
                  oBrw:tcolor := clrT
               ENDIF
               IF clrB != Nil
                  oBrw:bcolor := clrB
               ENDIF
               IF clrTSel != Nil
                  oBrw:tcolorSel := clrTSel
               ENDIF
               IF clrBSel != Nil
                  oBrw:bcolorSel := clrBSel
               ENDIF

               IF cOk != Nil
                  x1 := Int(width/2) - Iif( cCancel != Nil, 90, 40 )
                  @ x1,height-36 BUTTON cOk SIZE 80,30 ON CLICK {||nChoice:=oBrw:nCurrent,EndDialog(oDlg:handle)}
                  IF cCancel != Nil
                     @ x1+100,height-36 BUTTON cCancel SIZE 80,30 ON CLICK {||nChoice:=0,EndDialog(oDlg:handle)}
                  ENDIF
               ENDIF

               oDlg:Activate()
               IF lNewFont
                  oFont:Release()
               ENDIF

               RETURN nChoice

FUNCTION ShowProgress( nStep,maxPos,nRange,cTitle,oWnd,x1,y1,width,height )

   LOCAL nStyle := WS_POPUP+WS_VISIBLE+WS_CAPTION+WS_SYSMENU+WS_SIZEBOX

   STATIC oDlg, hPBar, iCou, nLimit

   IF nStep == 0
      nLimit := Iif( nRange != Nil,Int( nRange/maxPos ),1 )
      iCou := 0
      x1 := Iif( x1==Nil,0,x1 )
      y1 := Iif( x1==Nil,0,y1 )
      width := Iif( width==Nil,220,width )
      height := Iif( height==Nil,55,height )
      IF x1 == 0
         nStyle += DS_CENTER
      ENDIF
      IF oWnd != Nil
         oDlg := Nil
         hPBar := CreateProgressBar( oWnd:handle, maxPos,20,25,width-40,20 )
      ELSE
         INIT DIALOG oDlg TITLE cTitle   ;
            AT x1,y1 SIZE width,height ;
            STYLE nStyle               ;
            ON INIT {|o|hPBar:=CreateProgressBar(o:handle, maxPos,20,25,width-40,20)}
         ACTIVATE DIALOG oDlg NOMODAL
      ENDIF
   ELSEIF nStep == 1
      iCou ++
      IF iCou == nLimit
         iCou := 0
         UpdateProgressBar( hPBar )
      ENDIF
   ELSEIF nStep == 2
      UpdateProgressBar( hPBar )
   ELSEIF nStep == 3
      SetWindowText( oDlg:handle,cTitle )
      IF maxPos != Nil
         SetProgressBar( hPBar,maxPos )
      ENDIF
   ELSE
      DestroyWindow( hPBar )
      IF oDlg != Nil
      EndDialog( oDlg:handle )
   ENDIF
ENDIF

RETURN NIL

FUNCTION EndWindow()

   IF HWindow():GetMain() != Nil
      SendMessage( HWindow():aWindows[1]:handle, WM_SYSCOMMAND, SC_CLOSE, 0 )
   ENDIF

   RETURN NIL

FUNCTION HdSerial( cDrive )

   LOCAL n       :=  HDGETSERIAL( cDrive )
   LOCAL cHex    :=  NUMTOHEX(n)
   LOCAL cResult := ""

   cResult := Substr( cHex,1, 4 ) + '-' + Substr( cHex,5, 4 )

   RETURN cResult

FUNCTION Hwg_GetIni( cSection, cEntry, cDefault, cFile )

   RETURN GetPrivateProfileString(cSection, cEntry, cDefault, cFile )

FUNCTION Hwg_WriteIni( cSection, cEntry, cValue, cFile )

   RETURN( WritePrivateProfileString( cSection, cEntry, cValue, cFile ) )

FUNCTION SetHelpFileName ( cNewName )

   STATIC cName := ""
   LOCAL cOldName := cName

   IF cNewName <> Nil
      cName := cNewName
   ENDIF

   RETURN cOldName

FUNCTION RefreshAllGets( oDlg )

   AEval( oDlg:GetList, {|o|o:Refresh()} )

   RETURN NIL

   /*

   cTitle:   Window Title
   cDescr:  'Data Bases','*.dbf'
   cTip  :   *.dbf
   cInitDir: Initial directory

   */

FUNCTION SelectMultipleFiles(cDescr, cTip, cIniDir, cTitle )

   LOCAL aFiles, cRet, cFile, x, cFilter := "", cItem, nAt, cChar,i
   LOCAL hWnd := 0
   LOCAL nFlags:=""
   LOCAL cPath := ""
   LOCAL nIndex:=1

   cFilter += cDescr + Chr(0) + cTip + Chr(0)

   cFile := Space( 32000 )

   cRet := _GetOpenFileName( hWnd, @cFile, cTitle, cFilter, nFlags, cIniDir, Nil, @nIndex )

   nAt := At( Chr(0) + Chr(0), cFile )

   cFile := Left( cFile, nAt )

   aFiles := {}

   IF nAt == 0 // no double chr(0) user must have pressed cancel

      RETURN( aFiles )
   ENDIF

   x := At( Chr(0), cFile ) // fist null
   cPath := Left( cFile, x )

   cFile := StrTran( cFile, cPath, "" )

   IF ! Empty(cFile) // user selected more than 1 file
      cItem := ""

      FOR i:=1 to Len(cFile) //EACH cChar IN cFile
         cChar:=cFile[i]
         IF cChar == 0
            aAdd( aFiles, StrTran( cPath, Chr(0), "" ) + '\' + cItem )
            cItem := ""
            LOOP
         ENDIF
         cItem += cChar
      NEXT
   ELSE
      aFiles := { StrTran( cPath, CHR(0), "" ) }
   ENDIF

   RETURN( aFiles )

FUNCTION HWG_Version(oTip)

   LOCAL oVersion

   IF oTip==1
      oVersion:="HwGUI "+HWG_VERSION+" "+Version()
   ELSE
      oVersion:="HwGUI "+HWG_VERSION
   ENDIF

   RETURN oVersion

FUNCTION TxtRect( cTxt, oWin )

   LOCAL hDC
   LOCAL ASize
   LOCAL hFont
   LOCAL oFont := oWin:oFont

   hDC       := GetDC( oWin:handle )
   IF oFont == Nil
      oFont := oWin:oParent:oFont
   ENDIF
   IF oFont != Nil
      hFont := SelectObject( hDC, oFont:handle )
   ENDIF
   ASize     := GetTextSize( hDC, cTxt )
   IF oFont != Nil
      SelectObject( hDC, hFont )
   ENDIF
   ReleaseDC( oWin:handle, hDC )

   RETURN ASize

