/*
* HMG - Harbour Win32 GUI library Demo
* Copyright 2002-2008 Roberto Lopez <mail.box.hmg@gmail.com>
* http://www.hmgforum.com//
* Activex Sample: Inspired by Freewin Activex inplementation by
* Oscar Joel Lira Lira (http://sourceforge.net/projects/freewin).
*/

#include "hmg.ch"

FUNCTION Main()

   DEFINE WINDOW Win1 ;
         AT 0,0 ;
         WIDTH 800 ;
         HEIGHT 500 ;
         TITLE 'HMG ActiveX Support Demo' ;
         MAIN

      DEFINE MAIN MENU

         POPUP "Test"
            MENUITEM "Navigate" ACTION TestNavigate()
         END POPUP

      END MENU

      @ 10 , 50 ACTIVEX Test ;
         WIDTH 700  ;
         HEIGHT 400  ;
         PROGID "shell.explorer.2"

   END WINDOW

   CENTER WINDOW Win1

   ACTIVATE WINDOW Win1

   RETURN NIL

PROCEDURE TestNavigate()

   LOCAL oObject
   LOCAL cAddress := ''

   * Look at other samples for alternatives

   cAddress := InputBox ('Navigate:','Enter Address','http://www.hmgforum.com/')

   IF .Not. Empty ( cAddress )

      Win1.Test.Object:Navigate(cAddress)

   ENDIF

   RETURN

