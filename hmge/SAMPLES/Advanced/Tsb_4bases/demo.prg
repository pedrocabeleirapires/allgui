/*
 * MINIGUI - Harbour Win32 GUI library Demo
 *
 * Copyright 2016 SergKis - http://clipper.borda.ru
 * Design and color were made by Verchenko Andrey <verchenkoag@gmail.com>
*/

#include "hmg.ch"
#include "tsbrowse.ch"

REQUEST DBFCDX

MEMVAR nY, nX, nW, nH, aPrivBColor, nPrivFsize

/////////////////////////////////////////////////////////////////////////////
SET PROCEDURE TO util.prg
/////////////////////////////////////////////////////////////////////////////

#define PROGRAM	  "TSBrowse: The discovery of different databases on a single form."
*---------------------------------------------------
PROCEDURE Main
*---------------------------------------------------
    LOCAL aBase, nFontSize, nMaxWidth, nMaxHeight

    PRIVATE nY, nX, nW, nH, nPrivFsize
    PRIVATE aPrivBColor := { {192,185,154} , {159,191,236} , {195,224,133}, {251,230,148} }
 
    SET EXACT    ON
    SET CENTURY  ON
    SET EPOCH    TO ( Year(Date()) - 50 )
    SET DATE     TO GERMAN
 
    RDDSETDEFAULT('DBFCDX')
 
    SET AUTOPEN   ON
    SET EXCLUSIVE ON
    SET SOFTSEEK  ON
    SET DELETED   ON
 
    SET TOOLTIP BALLOON ON

    // Create a database and return a list of databases
    aBase := MyCreateDbfCdx()  

    nFontSize  := 9
    nMaxWidth  := GetDesktopWidth() 
    nMaxHeight := ( GetDesktopHeight() - GetTaskBarHeight() ) 
    IF nMaxWidth > 1200
       nFontSize  := 12
       nMaxWidth  := 1200 
       nMaxHeight := 700 
    ENDIF
    nPrivFsize := nFontSize  // to declare the size of the background for the table 

    SET FONT TO "Arial" , nFontSize             // Default font

    DEFINE WINDOW      wMain	   ;   
           AT          0, 0        ;
           WIDTH       nMaxWidth   ;
           HEIGHT      nMaxHeight  ;
           TITLE       'DEMO Tsb4' ;
           ICON        '1MAIN_ICO' ;
           MAIN                    ; 
           ON INIT ( wStandardWnd(aBase, nMaxWidth, nMaxHeight), ;
                     wMain.Release() )

    END WINDOW

    CENTER    WINDOW wMain
    ACTIVATE  WINDOW wMain 

RETURN    

////////////////////////////////////////////////////////////
FUNCTION wStandardWnd( aBase, nMaxWidth, nMaxHeight )
   LOCAL cForm  := "Form_1"
   LOCAL oBrw, nHbar, nCliW
   LOCAL nRow := 10, nCol := 10

   If _IsWindowDefined(cForm)
      RETURN NIL
   EndIf

   DEFINE WINDOW &cForm AT 0, 0 WIDTH nMaxWidth HEIGHT nMaxHeight ;
      TITLE PROGRAM                 ;
      ICON "1MAIN_ICO"              ;
      WINDOWTYPE STANDARD TOPMOST   ;
      NOMAXIMIZE NOSIZE             ;
      BACKCOLOR { 93,114,148}       ;
      ON INIT   {|| wMain.Hide, DoMethod( cForm, "Restore" ), ;
                    SetProperty(cForm, "Topmost", .F.) }

      nCliW := This.ClientWidth

      DEFINE STATUSBAR BOLD  
          STATUSITEM ''                           // ������� ������ ���
          STATUSITEM MiniGuiVersion() WIDTH nCliW * 0.4 ICON '1MAIN_ICO'
          STATUSITEM ''               WIDTH nCliW * 0.1
          DATE                        WIDTH 100
          CLOCK                       WIDTH 100
      END STATUSBAR

      // ������� ���� ������ �������
      nHbar := MyToolBar(cForm, nRow, nCol, aBase )
      // ��������� ����������� �������
      nY := nHbar + 5
      nX := 2
      nW := -( nX * 2 )
      nH := -( GetWindowHeight(This.StatusBar.Handle) + 4 )
      
      oBrw := MyTsb(1,aBase)  // ������ ����� ���������� �������

      oBrw:SetFocus()

   END WINDOW

   CENTER   WINDOW &cForm
   ACTIVATE WINDOW &cForm

 RETURN NIL

////////////////////////////////////////////////////////////
FUNCTION MyTsb( nBrw, aBase )
   LOCAL cForm  := ThisWindow.Name
   LOCAL cBrw   := "BrwLog"
   LOCAL cAlias
   LOCAL oBrw, lCell := .T., cFile
   LOCAL aFont, cFont, nFont
   LOCAL aBackcolor, aMarker[2], aCursorBC, aBackColor2

   aFont  := { "Tahoma", "Times New Roman", "Comic Sans MS", 'Arial' }
   cFile  := aBase[ nBrw, 1 ]     // File dbf
   cAlias := aBase[ nBrw, 2 ]     // Alias dbf
   cFont  := aFont[ nBrw ]
   nFont  := nPrivFsize               // Private variable
   aBackcolor := aPrivBColor[ nBrw ]  // Private variable
   This.BaseName.Value := "Alias: " + cAlias
  
   // ��������� ���� � ������� ������ ������� ��� ������� ������ �������� ���� !
   // Close the database and delete the table object by clicking the top menu button!
   If _IsControlDefined(cBrw, cForm)
      If Select(cAlias) > 0
         ( cAlias )->( dbClosearea() )
      EndIf
      DoMethod(cForm, cBrw, 'Release')
   EndIf
   
   Use &cFile Via "DBFCDX" Alias &cAlias Shared New
  
   If OrdCount() > 0
      OrdSetFocus(1)
   EndIf

   // DEFINE TBROWSE ...
   oBrw := TBrw_Create(cBrw, cForm, nY, nX, nW, nH, cAlias, lCell, cFont, nFont, aBackcolor)  

   WITH OBJECT oBrw   // oBrw ������ ����������\���������������

      :LoadFields(.F.) 
   
      :lNoChangeOrd := .T.               // ������ ���������� �� ����
      :lNoGrayBar   := .T.               // ���������� ������
      :nColOrder    := 0                 // ������ ������ ���������� �� ����
      :lNoHScroll   := .T.               // ����� ��������������� ���������
      :nHeightCell  += 5
      :nHeightHead  := :nHeightCell
      :nHeightFoot  := :nHeightHead      // ������ ������ �������
      :lFooting     := .T.               // ������������ ������
      :lDrawFooters := .T.               // ��������  �������
  
      aEval(:aColumns, {|oCol,nCol| oCol:cFooting := hb_ntos(nCol) }) // ����� � ������� �������
      aEval(:aColumns, {|oCol     | oCol:nFAlign  := DT_CENTER     }) // ��������� ������� �������
      aEval(:aColumns, {|oCol     | oCol:lFixLite := .T.           }) // Fixed cursor , ����.������

      // -------------- �������� ����� ������� � ���� ������.������� ������� ---------
      //   AEval(oBrw:aColumns, {|oCol,nCol| _LogFile(.T.,nCol, oCol:cName) })
  
      aMarker[ 1 ] := Rgb( 255, 255, 255 )   // �����
      aMarker[ 2 ] := Rgb( 127, 127, 127 )   // ����� 25%          

      // ������������ ����: ������ �������/������� ������ ������ ����
      aCursorBC := { 4915199,255}
      :SetColor( { 6}, { { |a,b,c,d| a:=d, IF( c:nCell == b, aCursorBC ,;  
                                { aMarker[1], aMarker[2] })  }  } )            

      // -------------------- ���������� ����� � ������� ------------------------------
      :SetColor( { 1}, { { || CLR_BLACK                         } } ) // ������ � ������� �������
      :SetColor( { 3}, { { || CLR_YELLOW                        } } ) // ������ ����� �������                                  
      :SetColor( { 4}, { { || { RGB(43,149,168), RGB(0,54,94) } } } ) // ���� ����� �������
      :SetColor( { 9}, { { ||   CLR_YELLOW                      } } ) // ������ ������� �������                                
      :SetColor( {10}, { { || { RGB(43,149,168), RGB(0,54,94) } } } ) // ���� ������� �������                                  

      :nClrLine := RGB(43,149,168) // ���� ����� ����� �������� ������� 
  
      aBackColor2 := { 215, 215, 215 }   // �����, ��������� 15%
      If nBrw < 4
         // ������� �������� ���� ������ �� ������ ������ ������\��������
         :SetColor( { 2}, { { |a,b,o| a:=b, iif( o:nAt % 2 == 0, MyRGB(aBackColor2 ), ;
                                                        MyRGB(aBackcolor) ) } } )
         If nBrw == 1 
            // --- ������ ����� ������ � ������� ������� --( oCol:nClrFore = oBrw:SetColor({1}...)---
            AEval(:aColumns, {|oCol| oCol:nClrFore := { |a,b,o| a:=b, MyTsbColorText( (o:cAlias)->ERR_1 ) } } )
         ElseIf nBrw == 2 
            // --- ������ ����� ������ � ������� ������� --( oCol:nClrFore = oBrw:SetColor({1}...)---
            AEval(:aColumns, {|oCol| oCol:nClrFore := { |a,b,o| a:=b, MyTsbColorText( (o:cAlias)->ERR_2 ) } } )
         EndIf
      Else
         // ����� ��� 4-� �������
         // ������� �������� ���� ������ �� ���� ���� FIELD->DATE_4
         :SetColor( { 2}, { { |a,b,o| a:=b, iif( Year( (o:cAlias)->DATE_4 ) % 2 == 0, ;
                                   MyRGB( aBackColor2 ), MyRGB( aBackcolor ) ) } } )

         // --- ������ ����� ������ � ������� ������� --( oCol:nClrFore = oBrw:SetColor({1}...)---
         AEval(:aColumns, {|oCol| oCol:nClrFore := { |a,b,o| a:=b, MyTsbColorText( (o:cAlias)->ERR_4 ) } } )
      Endif

      If nBrw == 3  // ����� ��� 3-� �������
         // ---- ������ �� ���� �������� ----( oCol:nClrBack = oBrw:SetColor( {2} ...) ----
         AEval(:aColumns, {|oCol| oCol:nClrBack := { |a,b,o| a:=b, ;
            iif( 'hmg' $ LOWER( (o:cAlias)->NAME_3 ) .OR. ;
                 'box' $ LOWER( (o:cAlias)->NAME_3 ), MyRGB({235,117,123}), ;
            iif( o:nAt % 2 == 0, MyRGB(aBackcolor), MyRGB(aBackColor2) ) ) } })
         // --- ������ ����� ������ � ������� ������� --( oCol:nClrFore = oBrw:SetColor({1}...)---
         AEval(:aColumns, {|oCol| oCol:nClrFore := { |a,b,o| a:=b, MyTsbColorText( (o:cAlias)->ERR_3 ) } } )
      Endif

      :ResetVScroll()  // ����� ������������� ����������

      // ------------ ����� � ������� ����� �� �������� -----------------------
      :aColumns[1]:cFooting := { || '[' + HB_NtoS( oBrw:nLen ) + ']' }
      :aColumns[5]:cFooting := { || '[' + HB_NtoS( MyGetCountField("SIZE_",nBrw) ) + ' Mb]' }
  
   END WITH         // oBrw ������ ����
  
   // END TBROWSE
   TBrw_Show(oBrw)           
   
   oBrw:Refresh(.T.)  // ���������� �������
   
   oBrw:nCell := 2    // ����������� ������ 

   RETURN oBrw

////////////////////////////////////////////////////////////
STATIC FUNCTION MyTsbColorText(nVal)
   LOCAL nColor

   IF nVal == -1 
     nColor := CLR_HRED
   ELSEIF nVal == 1 
     nColor := CLR_HBLUE
   ELSE
     nColor := CLR_BLACK
   ENDIF

   RETURN nColor

///////////////////////////////////////////////////////////////////////////////////////////
// ������� �������� ����� ���� �� �������
FUNCTION MyGetCountField(cField,nBrw) 
   LOCAL cAlias, nLen, nRec

   nLen := 0
   cAlias := ALIAS()
   nRec := ( cAlias )->( RecNo() )
   cField := cField + HB_NtoS(nBrw)

   ( cAlias )->( DbEval( { || nLen += &(cField) } ) )

   ( cAlias )->( DbGoTo( nRec ) )

   nLen := nLen  / 1024 / 1024

   RETURN nLen

////////////////////////////////////////////////////////////
FUNCTION MyToolBar( cForm, nRow, nCol, aBase )
   LOCAL nY,nX,nW,nH,cB,cC,cT
   LOCAL nMaxWidth := This.ClientWidth     
       //-------------------Define user toolbar buttons------------------------------//
         nY := nRow
         nX := nCol
         nW := 48
         nH := 48
         
         cB := "Butt_1"; cC := "Dbf-1";  cT := "Open Base_1.dbf"
       @ nY, nX  BUTTONEX &cB  CAPTION cC  TOOLTIP cT ;
                 BACKCOLOR aPrivBColor[1] BOLD ;
                 ACTION {|oBrw| oBrw := MyTsb(1,aBase), oBrw:SetFocus() } ;
                 WIDTH  nW HEIGHT nH NOXPSTYLE HANDCURSOR NOTABSTOP
         nX += GetWindowWidth(GetControlHandle(cB, cForm))

         cB := "Butt_2"; cC := "Dbf-2";  cT := "Open Base_2.dbf"
       @ nY, nX  BUTTONEX &cB  CAPTION cC TOOLTIP cT  ;
                 BACKCOLOR aPrivBColor[2] BOLD ;
                 ACTION {|oBrw| oBrw := MyTsb(2,aBase), oBrw:SetFocus() } ;
                 WIDTH  nW HEIGHT nH NOXPSTYLE HANDCURSOR NOTABSTOP
         nX += GetWindowWidth(GetControlHandle(cB, cForm))

         cB := "Butt_3"; cC := "Dbf-3";  cT := "Open Base_3.dbf"
       @ nY, nX  BUTTONEX &cB  CAPTION cC  TOOLTIP cT  ;
                 BACKCOLOR aPrivBColor[3] BOLD ;
                 ACTION {|oBrw| oBrw := MyTsb(3,aBase), oBrw:SetFocus() } ;
                 WIDTH  nW HEIGHT nH NOXPSTYLE HANDCURSOR NOTABSTOP
         nX += GetWindowWidth(GetControlHandle(cB, cForm))

         cB := "Butt_4"; cC := "Dbf-4";  cT := "Open Base_4.dbf"
       @ nY, nX  BUTTONEX &cB  CAPTION cC  TOOLTIP cT  ;
                 BACKCOLOR aPrivBColor[4] BOLD ;
                 ACTION {|oBrw| oBrw := MyTsb(4,aBase), oBrw:SetFocus() } ;
                 WIDTH  nW HEIGHT nH NOXPSTYLE HANDCURSOR NOTABSTOP
         nX += GetWindowWidth(GetControlHandle(cB, cForm))

         cB := "Butt_5"; cC := "Exit";   cT := "Exit from programm"
       @ nY, nX  BUTTONEX &cB  CAPTION cC  TOOLTIP cT  ;
                 FONTCOLOR WHITE BACKCOLOR MAROON BOLD     ;
                 ACTION ThisWindow.Release                 ;
                 WIDTH  nW HEIGHT nH NOXPSTYLE HANDCURSOR NOTABSTOP
         nX += GetWindowWidth(GetControlHandle(cB, cForm)) + nW
         
       @ nY, nX LABEL BaseName  VALUE '' WIDTH nMaxWidth-nX HEIGHT nH SIZE 20 ;
         FONTCOLOR WHITE TRANSPARENT VCENTERALIGN

         nY += GetWindowHeight(GetControlHandle(cB, cForm))  

RETURN nY

///////////////////////////////////////////////////////////////////////////
FUNCTION MyCreateDbfCdx()
   LOCAL aBase, aDbf, aStr, a2Str, cPath := GetStartUpFolder()+"\" 
   LOCAL aFindPath, aFiles, cFileMask, aResult := NIL, cFld, cStr, nErr
   LOCAL nL, nI, nJ, cAlias, cFile, cFileIndx, cI, aField /*[9]*/
   LOCAL cPathBCC, cPathGUI, cPathSmpl, cPathIncl, lHmg
 
   aDbf := {'zBASE_1.DBF','zBASE_2.DBF','zBASE_3.DBF','zBASE_4.DBF'}
   aStr := {} 
   AAdd( aStr, { 'NN'  , 'N',  6, 0 } )
   AAdd( aStr, { 'TBL' , 'C', 15, 0 } )
   AAdd( aStr, { 'PATH', 'C', 35, 0 } )
   AAdd( aStr, { 'NAME', 'C', 30, 0 } )
   AAdd( aStr, { 'SIZE', 'N', 12, 0 } )
   AAdd( aStr, { 'DATE', 'D',  8, 0 } )
   AAdd( aStr, { 'TIME', 'C', 10, 0 } )
   AAdd( aStr, { 'DIR' , 'L',  1, 0 } )
   AAdd( aStr, { 'ERR' , 'N',  2, 0 } )

   aBase := {} 
   // �������� �� ������� ������ � �������� �� �� ����� �������
   If !file(cPath + aDbf[1]) .OR. !file(cPath + aDbf[2])  .OR. ;
      !file(cPath + aDbf[3]) .OR. !file(cPath + aDbf[4])

      cPathBCC  := GetEnv( 'MG_BCC'  )
      cPathGUI  := GetEnv( 'MG_ROOT' )
      lHmg := IIF( cPathGUI == "", .F., .T. )
      cPathBCC  := IIF( cPathBCC == "", GetEnv( 'windir' ), cPathBCC )
      cPathGUI  := IIF( lHmg, cPathGUI, GetEnv( 'windir' )                              )
      cPathIncl := IIF( lHmg, cPathGUI+"\Include" , GetEnv( 'windir' )+"\Help"          )
      cPathSmpl := IIF( lHmg, cPathGUI+"\SAMPLES" , GetEnv( 'windir' )+"\Microsoft.NET" )
      aFindPath := { cPathBCC, cPathGUI, cPathIncl, cPathSmpl }

      SET WINDOW MAIN OFF
      WaitWindow( "Processing...", .T. )
      For nI := 1 TO 4
         a2Str := {}
         For nJ := 1 TO LEN(aStr)
             cFld := aStr[nJ,1]+"_"+hb_ntos(nI)
             AADD( a2Str, { cFld,aStr[nJ,2],aStr[nJ,3],aStr[nJ,4] } )
         Next
         cFile := cPath + aDbf[nI]
         DbCreate( cFile, a2Str )
         Use (cFile) Via "DBFCDX" Alias BASE Exclusive New

         cFileMask := IIF( nI == 4 .AND. lHmg, "*.prg", "*.*" )
         aFiles := DirectoryRecurse( aFindPath[nI], cFileMask, aResult )
         Select BASE
         cI := "_"+hb_ntos(nI)
         aField := { 'NN'+cI, 'TBL'+cI, 'PATH'+cI, 'NAME'+cI, 'SIZE'+cI,'DATE'+cI, 'TIME'+cI, 'DIR'+cI, 'ERR'+cI }
         For nJ := 1 TO LEN(aFiles)
             APPEND BLANK
             BASE->&(aField[1]) := nJ
             BASE->&(aField[2]) := "Table ( " + HB_NtoS(nI) + " )" 
             If nI == 4
                nL := LEN(cPathSmpl)
                cStr := cFilePath( aFiles[nJ,1] ) + "\"
                cStr := "..." + SUBSTR( cStr, nL+1 )
                BASE->&(aField[3]) := cStr
             Else
                BASE->&(aField[3]) := cFilePath( aFiles[nJ,1] ) + "\"
             Endif
             BASE->&(aField[4]) := cFileNoPath( aFiles[nJ,1] )
             BASE->&(aField[5]) := aFiles[nJ,2] 
             BASE->&(aField[6]) := aFiles[nJ,3]
             BASE->&(aField[7]) := aFiles[nJ,4]
             BASE->&(aField[8]) := IIF( aFiles[nJ,5] == "D", .F. , .T. )
             nErr := IIF( nJ % 11 == 0, -1, IIF( nJ % 7 == 0, 1, 0 ) )
             BASE->&(aField[9]) := nErr
         Next
         cFileIndx := ChangeFileExt( cFile, ".cdx" )
         If ! File(cFileIndx)
            cFld := "Upper(FIELD->PATH_"+hb_ntos(nI)+")"
            If nI == 1 
               INDEX ON &cFld TAG Name
            ElseIf nI == 2
               INDEX ON &cFld TAG Name
            ElseIf nI == 3   
               INDEX ON &cFld TAG Name
            Else
               INDEX ON DTOS(FIELD->DATE_4) TAG Name
            Endif
         Endif
         Close BASE
         cAlias := 'BASE_' + HB_NtoS(nI)
         AADD( aBase, { cFile, cAlias } )
      Next
      WaitWindow()
      SET WINDOW MAIN ON
   Else
      For nI := 1 TO 4
         cFile := cPath + aDbf[nI]
         cAlias := 'BASE_' + HB_NtoS(nI)
         AADD( aBase, { cFile, cAlias } )
      NEXT
   Endif

   RETURN aBase

///////////////////////////////////////////////////////////////////////////
Static Function DirectoryRecurse( cPath, cFileMask, aResult )
   local n, aFiles := Directory( cPath + "\*.*", "D" )
   local aFindMask := Directory( cPath + "\" + cFileMask )

   if ProcName( 5 ) == "DIRECTORYRECURSE"
      return {}
   endif

   if aResult == NIL
      aResult := {}
   endif

   if Len( aFindMask ) > 0

      Aeval( aFindMask, { |e| if( "TMP" $ e[ 1 ] .or. !"." $ e[ 1 ], , Aadd( aResult, {cPath + "\" + e[ 1 ], e[ 2 ], e[ 3 ], e[ 4 ], e[ 5 ]} ) ) } )

   endif

   for n := 1 to Len( aFiles )

      if "D" $ aFiles[ n ][ 5 ] .and. ! ( aFiles[ n ][ 1 ] $ ".." )

         DirectoryRecurse( cPath + "\" + aFiles[ n ][ 1 ], cFileMask, aResult )

      endif

   next

   Return aResult

////////////////////////////////////////////////////////////////////
STATIC FUNCTION MyRGB( aDim )
   RETURN RGB( aDim[1], aDim[2], aDim[3] )
