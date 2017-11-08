#include "hwgui.ch"

PROCEDURE main()

   LOCAL oDlg, oPanel
   LOCAL oBut1, oBut2, oBut3
   LOCAL oCtrl
   
   INIT WINDOW oDlg MAIN ;
        TITLE "Test animation" ;
        AT 0, 0 ;
        SIZE 300, 430

   @ 0,0 PANEL oPanel
   
   SET RESOURCES TO "shell32"

   @ 10, 5 ANIMATION SIZE 272, 60  AUTOPLAY CENTER TRANSPARENT FROM RESOURCE 161

   SET RESOURCES TO

   @ 10, 70 SAY "Autoplay from external (shell32) resource" SIZE 280, 20


   @ 130, 105 ANIMATION SIZE 30, 30  AUTOPLAY CENTER TRANSPARENT FROM RESOURCE 10001

   @ 33, 145 SAY "Autoplay from internal resource" SIZE 250, 20

   oCtrl := HAnimation():New( , , , 130, 180, 30, 30, "processando.avi", .f., .t., .t.)

   @ 93, 230 BUTTON oBut1 CAPTION " Play " of oPanel SIZE 110, 30 ;
                           ON CLICK { || oBut3:enable(), oBut1:disable(), oCtrl:play() }
   @ 93, 270 BUTTON oBut2 CAPTION " Seek 5th frame " of oPanel SIZE 110, 30 ;
                           ON CLICK { || oBut3:disable(), oBut1:enable(), oCtrl:seek(5) }
   @ 93, 310 BUTTON oBut3 CAPTION " Stop " of oPanel SIZE 110, 30 ;
                           ON CLICK { || oBut1:enable(), oBut3:disable(), oCtrl:stop() }   ;
                           ON INIT { |o| o:disable() }

   @ 43, 360 SAY "User driven play from AVI file" SIZE 250, 20

   oDlg:activate()