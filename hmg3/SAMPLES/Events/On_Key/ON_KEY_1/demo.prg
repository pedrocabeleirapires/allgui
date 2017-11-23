/*
* HMG ON KEY Demo
*/

/*

Available Keys

F1
F2
F3
F4
F5
F6
F7
F8
F9
F10
F11
F12
BACK
TAB

RETURN
ESCAPE
END
HOME
LEFT
UP
RIGHT
DOWN
INSERT
DELETE
PRIOR
NEXT
ALT+A
ALT+B
ALT+C
ALT+D
ALT+E
ALT+F
ALT+G
ALT+H
ALT+I
ALT+J
ALT+K
ALT+L
ALT+M
ALT+N
ALT+O
ALT+P
ALT+Q
ALT+R
ALT+S
ALT+T
ALT+U
ALT+V
ALT+W
ALT+X
ALT+Y
ALT+Z
ALT+0
ALT+1
ALT+2
ALT+3
ALT+4
ALT+5
ALT+6
ALT+7
ALT+8
ALT+9
ALT+F1
ALT+F2
ALT+F3
ALT+F4
ALT+F5
ALT+F6
ALT+F7
ALT+F8
ALT+F9
ALT+F10
ALT+F11
ALT+F12
ALT+BACK
ALT+TAB
ALT+RETURN
ALT+ESCAPE
ALT+END
ALT+HOME
ALT+LEFT
ALT+UP
ALT+RIGHT
ALT+DOWN
ALT+INSERT
ALT+DELETE
ALT+PRIOR
ALT+NEXT
SHIFT+A
SHIFT+B
SHIFT+C
SHIFT+D
SHIFT+E
SHIFT+F
SHIFT+G
SHIFT+H
SHIFT+I
SHIFT+J
SHIFT+K
SHIFT+L
SHIFT+M
SHIFT+N
SHIFT+O
SHIFT+P
SHIFT+Q
SHIFT+R
SHIFT+S
SHIFT+T
SHIFT+U
SHIFT+V
SHIFT+W
SHIFT+X
SHIFT+Y
SHIFT+Z
SHIFT+0
SHIFT+1
SHIFT+2
SHIFT+3
SHIFT+4
SHIFT+5
SHIFT+6
SHIFT+7
SHIFT+8
SHIFT+9
SHIFT+F1
SHIFT+F2
SHIFT+F3
SHIFT+F4
SHIFT+F5
SHIFT+F6
SHIFT+F7
SHIFT+F8
SHIFT+F9
SHIFT+F10
SHIFT+F11
SHIFT+F12
SHIFT+BACK
SHIFT+TAB
SHIFT+RETURN
SHIFT+ESCAPE
SHIFT+END
SHIFT+HOME
SHIFT+LEFT
SHIFT+UP
SHIFT+RIGHT
SHIFT+DOWN
SHIFT+INSERT
SHIFT+DELETE
SHIFT+PRIOR
SHIFT+NEXT
CONTROL+A
CONTROL+B
CONTROL+C
CONTROL+D
CONTROL+E
CONTROL+F
CONTROL+G
CONTROL+H
CONTROL+I
CONTROL+J
CONTROL+K
CONTROL+L
CONTROL+M
CONTROL+N
CONTROL+O
CONTROL+P
CONTROL+Q
CONTROL+R
CONTROL+S
CONTROL+T
CONTROL+U
CONTROL+V
CONTROL+W
CONTROL+X
CONTROL+Y
CONTROL+Z
CONTROL+0
CONTROL+1
CONTROL+2
CONTROL+3
CONTROL+4
CONTROL+5
CONTROL+6
CONTROL+7
CONTROL+8
CONTROL+9
CONTROL+F1
CONTROL+F2
CONTROL+F3
CONTROL+F4
CONTROL+F5
CONTROL+F6
CONTROL+F7
CONTROL+F8
CONTROL+F9
CONTROL+F10
CONTROL+F11
CONTROL+F12
CONTROL+BACK
CONTROL+TAB
CONTROL+RETURN
CONTROL+ESCAPE
CONTROL+END
CONTROL+HOME
CONTROL+LEFT
CONTROL+UP
CONTROL+RIGHT
CONTROL+DOWN
CONTROL+INSERT
CONTROL+DELETE
CONTROL+PRIOR
CONTROL+NEXT

*/

#include "hmg.ch"

FUNCTION Main

   LOCAL bBlock

   DEFINE WINDOW Win_1 ;
         AT 0,0 ;
         WIDTH 400 ;
         HEIGHT 400 ;
         TITLE 'Hello World!' ;
         MAIN

      ON KEY SHIFT+A ACTION MsgInfo ('Shift+A')
      ON KEY TAB ACTION MsgInfo ('TAB')
      ON KEY RETURN ACTION MsgInfo ('RETURN')
      ON KEY CONTROL+END ACTION MsgInfo ('CONTROL+END')
      ON KEY ESCAPE ACTION MsgInfo ('ESCAPE')
      ON KEY ALT+C ACTION MsgInfo ('ALT+C')

      DEFINE BUTTON Button_1
         ROW 10
         COL 10
         CAPTION 'Activate F2'
         ACTION EnableF2()
      END BUTTON

      DEFINE BUTTON Button_2
         ROW 40
         COL 10
         CAPTION 'Release F2'
         ACTION DisableF2()
      END BUTTON

      DEFINE BUTTON Button_3
         ROW 70
         COL 10
         CAPTION 'Store Key Test'
         ACTION StoreTest()
      END BUTTON

   END WINDOW

   ACTIVATE WINDOW Win_1

   RETURN

PROCEDURE EnableF2()

   ON KEY F2 OF Win_1 ACTION MsgInfo ('F2')

   RETURN

PROCEDURE DisableF2()

   RELEASE KEY F2 OF Win_1

   RETURN

PROCEDURE StoreTest()

   LOCAL bBlock

   STORE KEY RETURN OF Win_1 TO bBlock

   RELEASE KEY RETURN OF Win_1

   ON KEY RETURN OF Win_1 ACTION Eval ( bBlock )

   RETURN
