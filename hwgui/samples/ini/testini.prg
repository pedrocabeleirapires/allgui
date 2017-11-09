/*
*$Id: testini.prg,v 1.1 2008/09/19 19:55:50 sandrorrfreire Exp $
* HwGUI Samples
* testini.prg - Test to use files ini
*/

#include "windows.ch"
#include "guilib.ch"

FUNCTION Main

   LOCAL oMainWindow
   LOCAL cIniFile:="HwGui.ini"

   //Create the inifile
   IF !file( cIniFile )

      Hwg_WriteIni( 'Config', 'WallParer' , "No Paper", cIniFile )
      Hwg_WriteIni( 'Config', 'DirHwGUima', "C:\HwGUI" , cIniFile )
      Hwg_WriteIni( 'Print',  'Spoll'   ,   "Epson LX 80" , cIniFile )

   ENDIF

   INIT WINDOW oMainWindow MAIN TITLE "Example" ;
      AT 200,0 SIZE 400,150

   MENU OF oMainWindow
   MENUITEM "&Exit" ACTION EndWindow()
   MENUITEM "&Read Ini" ACTION ReadIni()
ENDMENU

ACTIVATE WINDOW oMainWindow

RETURN NIL

FUNCTION ReadIni()

   LOCAL cIniFile:="HwGui.ini"

   MsgInfo( Hwg_GetIni( 'Config', 'WallParer' ,, cIniFile ) )
   MsgInfo( Hwg_GetIni( 'Config', 'DirHwGUima',, cIniFile ) )
   MsgInfo( Hwg_GetIni( 'Print',  'Spoll'     ,, cIniFile ) )

   RETURN NIL

