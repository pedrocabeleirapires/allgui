/*
* HMG - Harbour Win32 GUI library Demo
* Copyright 2002 Roberto Lopez <mail.box.hmg@gmail.com>
* http://www.hmgforum.com//
*/

#include "hmg.ch"
#include "common.ch"

#define CRLF HB_OsNewLine()
#define PROGRAM 'Notes'
#define COPYRIGHT ' by Grigory Filatov, 2002'

#define MAXSHEETS 100
#define NTRIM( n ) LTrim( Str( n ) )

STATIC nWindows := 0, aWindows := {}, nRow := -22, nCol := -24, nColors := 0, ;
   aColors := { { 255 , 255 , 0 }, { 255 , 128 , 192 }, { 255 , 0 , 0 }, ;
   { 255 , 0 , 255 }, { 255 , 128 , 64 }, { 0 , 255 , 0 }, { 128 , 0 , 128 }, ;
   { 255 , 255 , 255 }, { 128 , 128 , 128}, { 0 , 0 , 255 }, { 192 , 192 , 192 } }, ;
   aNotes := { {"ID","N",4,0}, {"DATE","D",8,0}, {"TIME","C",8,0}, ;
   {"ROW","N",4,0}, {"COL","N",4,0}, {"COLOR","N",2,0}, ;
   {"TEXT1","C",24,0}, {"TEXT2","C",24,0}, {"TEXT3","C",24,0}, {"TEXT4","C",24,0} }

FUNCTION Main( cPack )

   LOCAL lPack := .f.
   PRIVATE lExit := .f., lSound := .t., lHidden := .f., nSheets := 0

   SET DATE German
   SET Delete On

   MsgInfo( "This program is based on a notify menu, Look at system tray to use..."  )

   DEFAULT cPack TO ""
   lPack := ( Empty(cPack) .OR. Upper( SubStr(cPack, 2) ) # "NOPACK" )

   DEFINE WINDOW Form_0 ;
         AT 0,0 ;
         WIDTH 0 HEIGHT 0 ;
         TITLE PROGRAM ;
         MAIN NOSHOW ;
         ON INIT OpenNotes(lPack) ;
         ON RELEASE {|| HideNotes(), lExit := .t., dbCloseAll(), Ferase( "Notes"+INDEXEXT() )} ;
         NOTIFYICON 'TRAY' ;
         NOTIFYTOOLTIP PROGRAM + ": Left click for a new sheet" ;
         ON NOTIFYCLICK NewNotes()

      DEFINE NOTIFY MENU
         ITEM 'S&top All Sounds'  ACTION (lSound := !lSound, ;
            ( Form_0.Sound.Checked := !lSound)) NAME Sound
         SEPARATOR
         ITEM '&Show All Notes'     ACTION ShowNotes()
         ITEM '&Hide All Notes'     ACTION HideNotes()
         SEPARATOR
         ITEM '&Mail to author...' ACTION ShellExecute(0, "open", "rundll32.exe", ;
            "url.dll,FileProtocolHandler " + ;
            "mailto:gfilatov@rambler.ru?cc=&bcc=" + ;
            "&subject=Notes%20Utility" + ;
            "&body=How%20are%20you%2C%20Grigory%3F", , 1)
         ITEM 'A&bout...'      ACTION ShellAbout( "", PROGRAM + ' version 1.4' + ;
            CRLF + Chr(169) + COPYRIGHT, LoadTrayIcon(GetInstance(), "MAIN") )
         SEPARATOR
         ITEM 'E&xit'        ACTION Form_0.Release
      END MENU

      DEFINE TIMER Timer_1 ;
         INTERVAL 1000 ;
         ACTION CheckTopLeftCorner()

   END WINDOW

   Form_0.Sound.Checked := !lSound

   ACTIVATE WINDOW Form_0

   RETURN NIL

FUNCTION NewNotes()

   LOCAL cForm, nForm, nColor

   nWindows++
   nForm := nWindows
   cForm := 'Form_' + NTRIM(nForm)

   nSheets++
   IF nSheets > MAXSHEETS
      MsgStop( "Quantity of Sheets is Very Big!", "Stop!" )

      RETURN NIL
   ENDIF

   Form_0.NotifyTooltip := PROGRAM + ": " + NTRIM(nSheets) + " sheet(s)"

   nColors++
   IF nColors > 11
      nColors := 1
   ENDIF
   nColor := nColors

   nRow := nRow + 22
   nCol := nCol + 24
   IF nRow > GetDesktopHeight() - 200
      nRow := 0
      nCol := 200
   ENDIF

   DEFINE WINDOW &cForm ;
         AT nRow, nCol ;
         WIDTH 200 HEIGHT 180 ;
         TITLE DtoC(Date()) + " " + Time() ;
         ICON "TRAY" ;
         CHILD ;
         TOPMOST ;
         NOMINIMIZE NOMAXIMIZE NOSIZE ;
         ON INIT InitNotes(cForm) ;
         ON RELEASE CloseNotes(cForm, nForm) ;
         ON MOUSECLICK EditNotes(cForm) ;
         BACKCOLOR aColors[nColor] ;
         FONT 'MS Sans Serif' SIZE 10

      @ 6,12 LABEL Label_1 VALUE "" WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 6,10 TEXTBOX Text_1 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_2' , 'SetFocus' )
      @ 36,12 LABEL Label_2 VALUE "" WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 36,10 TEXTBOX Text_2 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_3' , 'SetFocus' )
      @ 66,12 LABEL Label_3 VALUE "" WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 66,10 TEXTBOX Text_3 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_4' , 'SetFocus' )
      @ 96,12 LABEL Label_4 VALUE "" WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 96,10 TEXTBOX Text_4 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Button_1' , 'SetFocus' )
      @ 125,35 LABEL Label_5 VALUE "Mouse Click for Editing" WIDTH 120 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         FONT "MS Sans Serif" SIZE 9 ;
         BACKCOLOR aColors[nColor]

      @ 126,60 BUTTON Button_1 CAPTION "OK" ACTION ExitEdit(cForm, nForm, nColor) WIDTH 70 HEIGHT 22 ;
         FONT "MS Sans Serif" SIZE 9

      DEFINE CONTEXT MENU
         ITEM '&Hide a sheet' ACTION DoMethod (cForm,'Hide')
         SEPARATOR
         ITEM '&Stick a sheet' ACTION CompactNotes(cForm, nForm, nColor)
      END MENU

   END WINDOW

   SetProperty ( cForm , 'Text_1' , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_2' , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_3' , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_4' , 'Visible' , .f. )
   SetProperty ( cForm , 'Button_1' , 'Visible' , .f. )

   ACTIVATE WINDOW &cForm

   RETURN NIL

PROCEDURE InitNotes(cForm)

   IF lSound
      IF FILE("Open.wav")
         PLAY WAVE "Open.wav"
      ELSE
         PlayOk()
      ENDIF
   ENDIF

   AADD( aWindows, cForm )

   RETURN

PROCEDURE CloseNotes(cForm, nId)

   LOCAL nForm := ASCAN( aWindows, cForm )

   IF lSound
      IF FILE("Open.wav")
         PLAY WAVE "Close.wav"
      ELSE
         PlayBeep()
      ENDIF
   ENDIF

   IF !lExit
      ADEL( aWindows, nForm )
      ASIZE( aWindows, Len(aWindows) - 1 )

      nSheets--
      Form_0.NotifyTooltip := PROGRAM + ": " + ;
         IF( Empty(nSheets), "Emptily", NTRIM(nSheets) + " sheet(s)" )

      SEEK nId
      IF FOUND()
         IF Rlock()
            DELETE
            UNLOCK
         ENDIF
      ENDIF
   ENDIF

   RETURN

PROCEDURE EditNotes(cForm)

   SetProperty ( cForm ,'Label_5' , 'Visible' , .f. )

   SetProperty ( cForm ,'Text_1' , 'Visible' , .t. )
   SetProperty ( cForm ,'Text_2' , 'Visible' , .t. )
   SetProperty ( cForm ,'Text_3' , 'Visible' , .t. )
   SetProperty ( cForm ,'Text_4' , 'Visible' , .t. )
   SetProperty ( cForm ,'Button_1' , 'Visible' , .t. )

   DoMethod ( cForm , 'Text_1' , 'SetFocus' )

   IF lSound
      PlayBeep()
   ENDIF

   RETURN

PROCEDURE ExitEdit(cForm, nId, nColor)

   LOCAL h := GetFormHandle( cForm )
   LOCAL SaveRow := GetWindowRow( h ), ;
      SaveCol := GetWindowCol( h )
   LOCAL cText1 := GetProperty ( cForm , 'Text_1' , 'Value' ), ;
      cText2 := GetProperty( cForm , 'Text_2' , 'Value' ), ;
      cText3 := GetProperty( cForm , 'Text_3' , 'Value' ), ;
      cText4 := GetProperty( cForm , 'Text_4' , 'Value' ), ;
      cTime := Time()

   SEEK nId
   IF !FOUND()
      DBappend()
      IF Rlock()
         REPLACE ID WITH nId
         UNLOCK
      ENDIF
   ENDIF
   IF Rlock()
      REPLACE DATE WITH Date(), TIME WITH cTime, ;
         ROW WITH SaveRow, COL WITH SaveCol, ;
         COLOR WITH nColor, ;
         TEXT1 WITH cText1, TEXT2 WITH cText2, ;
         TEXT3 WITH cText3, TEXT4 WITH cText4
      COMMIT
      UNLOCK
   ENDIF

   SetProperty ( cForm , 'Label_1','Value' , cText1 )
   SetProperty ( cForm , 'Label_2','Value' , cText2 )
   SetProperty ( cForm , 'Label_3','Value' , cText3 )
   SetProperty ( cForm , 'Label_4','Value' , cText4 )

   SetProperty ( cForm , 'Text_1','Visible' , .f.   )
   SetProperty ( cForm , 'Text_2','Visible' , .f.   )
   SetProperty ( cForm , 'Text_3','Visible' , .f.   )
   SetProperty ( cForm , 'Text_4','Visible' , .f.   )
   SetProperty ( cForm , 'Button_1','Visible' , .f. )

   SetProperty ( cForm , 'Label_5','Value' , PadC( "Last Update: " + cTime, 25 ) )
   SetProperty ( cForm , 'Label_5','Visible' , .t. )

   IF lSound
      PlayBeep()
   ENDIF

   RETURN

PROCEDURE SaveRowCol(cForm, nId)

   LOCAL h := GetFormHandle( cForm )
   LOCAL SaveRow := GetWindowRow( h ), ;
      SaveCol := GetWindowCol( h )

   SEEK nId
   IF FOUND()
      IF Rlock()
         REPLACE ROW WITH SaveRow, COL WITH SaveCol
         UNLOCK
      ENDIF
   ENDIF

   RETURN

PROCEDURE HideNotes()

   LOCAL i, nForm := Len(aWindows), cForm

   IF nForm > 0
      lHidden := .t.
      FOR i := nForm To 1 Step -1
         cForm := aWindows[i]
         IF IsWIndowDefined(&cForm)
            SysWait()
            SaveRowCol( cForm, Val( SubStr( cForm, At( "_", cForm ) + 1 ) ) )
            DoMethod ( cForm , 'Hide' )
         ENDIF
      NEXT
   ENDIF

   RETURN

PROCEDURE ShowNotes()

   LOCAL i, nForm := Len(aWindows), cForm

   IF nForm > 0
      lHidden := .f.
      FOR i := 1 To nForm
         cForm := aWindows[i]
         IF IsWIndowDefined(&cForm)
            SysWait()
            DoMethod ( cForm , 'Show' )
         ENDIF
      NEXT
   ENDIF

   RETURN

PROCEDURE OpenNotes(lPack)

   LOCAL cDataBase := "Notes.dat"
   PRIVATE cActForm := {}

   IF !File( cDataBase )
      DBcreate( cDataBase, aNotes )
   ENDIF

   IF lPack
      USE ( cDataBase ) NEW
      IF !NetErr()
         PACK
         DBEVAL( {|| FIELD->ID := RecNo() } )
         CLOSE
      ENDIF
   ENDIF

   USE ( cDataBase ) ALIAS NOTES SHARED NEW

   IF !NetErr()
      IF !File( ( "Notes"+INDEXEXT() ) )
         INDEX ON FIELD->ID TO NOTES
      ENDIF
      SET INDEX TO NOTES
   ELSE
      MsgStop("Data file is locked", "Please, try again")

      RETURN
   ENDIF

   GO BOTTOM
   nWindows := FIELD->ID

   GO TOP
   DO WHILE !EOF()
      LoadNotes( FIELD->ID, FIELD->DATE, FIELD->TIME, ;
         FIELD->ROW, FIELD->COL, FIELD->COLOR, ;
         FIELD->TEXT1, FIELD->TEXT2, FIELD->TEXT3, FIELD->TEXT4 )
      SKIP
   ENDDO

   IF LEN( cActForm ) > 0
      _ActivateWindow( cActForm )
   ENDIF

   RETURN

PROCEDURE LoadNotes(nId, dDate, cTime, SaveRow, SaveCol, nColor, cText1, cText2, cText3, cText4)

   LOCAL cForm := 'Form_' + NTRIM(nId)

   nSheets++
   IF nSheets > MAXSHEETS
      MsgStop( "Quantity of Sheets is Very Big!", "Stop!" )

      RETURN
   ENDIF

   Form_0.NotifyTooltip := PROGRAM + ": " + NTRIM(nSheets) + " sheet(s)"

   DEFINE WINDOW &cForm ;
         AT SaveRow, SaveCol ;
         WIDTH 200 HEIGHT 180 ;
         TITLE DtoC(dDate) + " " + cTime ;
         ICON "TRAY" ;
         CHILD ;
         TOPMOST ;
         NOMINIMIZE NOMAXIMIZE NOSIZE ;
         ON INIT InitNotes(cForm) ;
         ON RELEASE CloseNotes(cForm, nId) ;
         ON MOUSECLICK EditNotes(cForm) ;
         BACKCOLOR aColors[nColor] ;
         FONT 'MS Sans Serif' SIZE 10

      @ 6,12 LABEL Label_1 VALUE cText1 WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 6,10 TEXTBOX Text_1 VALUE cText1 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_2' , 'SetFocus' )
      @ 36,12 LABEL Label_2 VALUE cText2 WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 36,10 TEXTBOX Text_2 VALUE cText2 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_3' , 'SetFocus' )
      @ 66,12 LABEL Label_3 VALUE cText3 WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 66,10 TEXTBOX Text_3 VALUE cText3 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Text_4' , 'SetFocus' )
      @ 96,12 LABEL Label_4 VALUE cText4 WIDTH 168 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         BACKCOLOR aColors[nColor]
      @ 96,10 TEXTBOX Text_4 VALUE cText4 HEIGHT 22 WIDTH 172 MAXLENGTH 24 ;
         ON ENTER DoMethod ( cForm , 'Button_1' , 'SetFocus' )
      @ 125,35 LABEL Label_5 VALUE "Mouse Click for Editing" WIDTH 120 HEIGHT 22 ;
         ACTION EditNotes(cForm) ;
         FONT "MS Sans Serif" SIZE 9 ;
         BACKCOLOR aColors[nColor]

      @ 126,60 BUTTON Button_1 CAPTION "OK" ACTION ExitEdit(cForm, nId, nColor) WIDTH 70 HEIGHT 22 ;
         FONT "MS Sans Serif" SIZE 9

      DEFINE CONTEXT MENU
         ITEM '&Hide a sheet' ACTION DoMethod (cForm,'Hide')
         SEPARATOR
         ITEM '&Stick a sheet' ACTION CompactNotes(cForm, nId, nColor)
      END MENU

   END WINDOW

   SetProperty ( cForm , 'Text_1'   , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_2'   , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_3'   , 'Visible' , .f. )
   SetProperty ( cForm , 'Text_4'   , 'Visible' , .f. )
   SetProperty ( cForm , 'Button_1' , 'Visible' , .f. )

   AADD( cActForm, cForm )

   RETURN

PROCEDURE CompactNotes(cForm, nForm, nColor)

   LOCAL h := GetFormHandle( cForm ), dDate, cTime
   LOCAL SaveRow := GetWindowRow( h ), ;
      SaveCol := GetWindowCol( h )
   LOCAL cText1 := GetProperty ( cForm , 'Text_1', 'Value' ), ;
      cText2 := GetProperty ( cForm , 'Text_2', 'Value' ), ;
      cText3 := GetProperty ( cForm , 'Text_3', 'Value' ), ;
      cText4 := GetProperty ( cForm , 'Text_4', 'Value' )
   PRIVATE cActForm := {}

   SEEK nForm
   IF FOUND()
      dDate := FIELD->DATE
      cTime := FIELD->TIME

      lExit := .t.
      DoMethod ( cForm , 'Release' )

      DEFINE WINDOW &cForm ;
            AT SaveRow+22, SaveCol ;
            WIDTH 196 HEIGHT 106 ;
            CHILD ;
            TOPMOST NOCAPTION ;
            NOMINIMIZE NOMAXIMIZE NOSIZE ;
            ON INIT (lExit := .f.) ;
            ON MOUSECLICK ( DoMethod( cForm ,'Release'), ADEL( aWindows, nForm ), ;
            ASIZE( aWindows, Len(aWindows) - 1 ), nSheets--, ;
            LoadNotes( nForm, dDate, cTime, SaveRow, SaveCol, nColor, ;
            cText1, cText2, cText3, cText4 ), _ActivateWindow( cForm ) ) ;
            BACKCOLOR aColors[nColor] ;
            FONT 'MS Sans Serif' SIZE 10

         @ 6,12 LABEL Label_1 VALUE cText1 WIDTH 168 HEIGHT 22 ;
            ACTION ( DoMethod( cForm,'Release' ), ADEL( aWindows, nForm ), ;
            ASIZE( aWindows, Len(aWindows) - 1 ), nSheets--, ;
            LoadNotes( nForm, dDate, cTime, SaveRow, SaveCol, nColor, ;
            cText1, cText2, cText3, cText4 ), _ActivateWindow( cForm ) ) ;
            BACKCOLOR aColors[nColor]
         @ 30,12 LABEL Label_2 VALUE cText2 WIDTH 168 HEIGHT 22 ;
            ACTION ( DoMethod( cForm ,'Release'), ADEL( aWindows, nForm ), ;
            ASIZE( aWindows, Len(aWindows) - 1 ), nSheets--, ;
            LoadNotes( nForm, dDate, cTime, SaveRow, SaveCol, nColor, ;
            cText1, cText2, cText3, cText4 ), _ActivateWindow( cForm ) ) ;
            BACKCOLOR aColors[nColor]
         @ 54,12 LABEL Label_3 VALUE cText3 WIDTH 168 HEIGHT 22 ;
            ACTION ( DoMethod( cForm ,'Release'), ADEL( aWindows, nForm ), ;
            ASIZE( aWindows, Len(aWindows) - 1 ), nSheets--, ;
            LoadNotes( nForm, dDate, cTime, SaveRow, SaveCol, nColor, ;
            cText1, cText2, cText3, cText4 ), _ActivateWindow( cForm ) ) ;
            BACKCOLOR aColors[nColor]
         @ 78,12 LABEL Label_4 VALUE cText4 WIDTH 168 HEIGHT 22 ;
            ACTION ( DoMethod( cForm ,'Release'), ADEL( aWindows, nForm ), ;
            ASIZE( aWindows, Len(aWindows) - 1 ), nSheets--, ;
            LoadNotes( nForm, dDate, cTime, SaveRow, SaveCol, nColor, ;
            cText1, cText2, cText3, cText4 ), _ActivateWindow( cForm ) ) ;
            BACKCOLOR aColors[nColor]

      END WINDOW

      ACTIVATE WINDOW &cForm
   ELSE
      MsgStop( "Empty notes!", "Stop!" )
   ENDIF

   RETURN

FUNCTION CheckTopLeftCorner()

   LOCAL aPos := GetCursorPos()

   IF aPos[1] = 0 .AND. aPos[2] = 0
      IF lHidden
         ShowNotes()
      ELSE
         HideNotes()
      ENDIF
   ENDIF

   RETURN NIL

PROCEDURE SysWait(nWait)

   LOCAL iTime := Seconds()

   DEFAULT nWait TO .1

   DO WHILE Seconds() - iTime < nWait
      DO EVENTS
   ENDDO

   RETURN
