
/*
* MINIGUI - Harbour Win32 GUI library Demo
* Copyright 2002-2008 Roberto Lopez <harbourminigui@gmail.com>
* http://harbourminigui.googlepages.com/
* Activex Sample: Inspired by Freewin Activex inplementation by
* Oscar Joel Lira Lira http://sourceforge.net/projects/freewin
*/

#include "minigui.ch"

FUNCTION Main()

   DEFINE WINDOW Win1 ;
         AT 0,0 ;
         WIDTH 800 ;
         HEIGHT 500 ;
         TITLE 'HMG ActiveX Support Demo' ;
         MAIN ;
         ON MAXIMIZE ( Win1.Test.Width := (Win1.Width) - 100, Win1.Test.Height := (Win1.Height) - 100 ) ;
         ON SIZE ( Win1.Test.Width := (Win1.Width) - 100, Win1.Test.Height := (Win1.Height) - 100 ) ;
         ON RELEASE Win1.Test.Release

      DEFINE MAIN MENU
         POPUP "Test"
            MENUITEM "Play File" ACTION Test()
         END POPUP
      END MENU

      DEFINE LABEL label_1
         ROW       5
         COL      250
         VALUE      "OSCAR THE BOXER"
         FONTNAME   "Courier New"
         FONTSIZE   20
         WIDTH      300
         HEIGHT      30
      END LABEL

      DEFINE ACTIVEX Test
         ROW       40
         COL       50
         WIDTH       700
         HEIGHT       380
         PROGID       "ShockwaveFlash.ShockwaveFlash.10"
      END ACTIVEX

   END WINDOW

   CENTER WINDOW Win1

   ACTIVATE WINDOW Win1

   RETURN NIL

PROCEDURE Test()

   Win1.Test.XObject:Movie := "http://www.youtube.com/v/58CZcCvwND4&hl=en&fs=1"

   RETURN
