/*
*/

#include "oohg.ch"

FUNCTION Main

   PUBLIC x := 1

   DEFINE WINDOW Win_1 ;
         AT 0,0 ;
         WIDTH 400 ;
         HEIGHT 400 ;
         TITLE 'Hello World!' ;
         MAIN

      DEFINE MAIN MENU
         DEFINE POPUP 'File'
            MENUITEM 'Test 1' ACTION Test1()
            MENUITEM 'Test 2' ACTION Test2()
         END POPUP
      END MENU

   END WINDOW

   ACTIVATE WINDOW Win_1

   RETURN

PROCEDURE Test1()

   LOCAL x

   x := Getfile ( { {'All Files','*.*'} } , 'Open File' , 'c:\' , .f. , .t. )
   msginfo (x)

   RETURN

PROCEDURE Test2()

   LOCAL x , i

   x := Getfile ( { {'All Files','*.*'} } , 'Open File' , 'c:\' , .t. , .t. )

   FOR i := 1 To len (x)
      msginfo (x [i])
   NEXT x

   RETURN
