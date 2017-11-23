/*
* HMG - Harbour Win32 GUI library Demo
* Copyright 2002 Roberto Lopez <mail.box.hmg@gmail.com>
* http://www.hmgforum.com//
*/

#include "hmg.ch"

FUNCTION Main

   DEFINE WINDOW FORM_MAIN ;
         AT 0,0 ;
         WIDTH 640 HEIGHT 480 ;
         TITLE "IPADDRESS CONTROL DEMO" ;
         MAIN

      DEFINE EDITBOX EDITBOX_1
         ROW 10
         COL 10
         VALUE ""
         WIDTH 150
         HEIGHT 400
      END EDITBOX

      // ip 1

      DEFINE LABEL LABEL_1
         ROW 10
         COL 200
         VALUE "IP ADDRESS 1"
      END LABEL

      DEFINE IPADDRESS IPADDRESS_1
         TOOLTIP "IPADDRESS CONTROL 1"
         ROW 40
         COL 200
         ONGOTFOCUS  AddText("IP1 GOTFOCUS")
         ONCHANGE    AddText("IP1 CHANGE")
         ONLOSTFOCUS AddText("IP1 LOSTFOCUS")
      END IPADDRESS

      DEFINE BUTTON BUTTON_1A
         ROW 70
         COL 200
         CAPTION "SET IP 1"
         ACTION SetIp1()
      END BUTTON

      DEFINE BUTTON BUTTON_1B
         ROW 70
         COL 350
         CAPTION "GET IP 1"
         ACTION GetIp1()
      END BUTTON

      // ip 2

      DEFINE LABEL LABEL_2
         ROW 120
         COL 200
         VALUE "IP ADDRESS 2"
      END LABEL

      DEFINE IPADDRESS IPADDRESS_2
         VALUE { 127 , 0 , 0 , 1 }
         ROW 120
         COL 200
         ONGOTFOCUS  AddText("IP2 GOTFOCUS")
         ONCHANGE    AddText("IP2 CHANGE")
         ONLOSTFOCUS AddText("IP2 LOSTFOCUS")
         TOOLTIP "IPADDRESS CONTROL 2"
      END IPADDRESS

      DEFINE BUTTON BUTTON_2A
         ROW 180
         COL 200
         CAPTION "SET IP 2"
         ACTION SetIp2()
      END BUTTON

      DEFINE BUTTON BUTTON_2B
         CAPTION "GET IP 2"
         ROW 180
         COL 350
         ACTION GetIp2()
      END BUTTON

      // ip 3

      DEFINE LABEL LABEL_3
         ROW 230
         COL 200
         VALUE "IP ADDRESS 3"
      END LABEL

      DEFINE IPADDRESS IPADDRESS_3
         VALUE { 255 , 255 , 255 , 255 }
         ROW 260
         COL 200
         ONGOTFOCUS  AddText("IP3 GOTFOCUS")
         ONCHANGE    AddText("IP3 CHANGE")
         ONLOSTFOCUS AddText("IP3 LOSTFOCUS")
         TOOLTIP "IPADDRESS CONTROL 3"
      END IPADDRESS

      DEFINE BUTTON BUTTON_3A
         ROW 290
         COL 200
         CAPTION "SET IP 3"
         ACTION SetIp3()
      END BUTTON

      DEFINE BUTTON BUTTON_3B
         ROW 290
         COL 350
         CAPTION "GET IP 3"
         ACTION GetIp3()
      END BUTTON

      DEFINE BUTTON BUTTON_4
         ROW 350
         COL 200
         CAPTION "Clear Text"
         ACTION FORM_MAIN.EDITBOX_1.VALUE := ""
      END BUTTON

   END WINDOW

   CENTER WINDOW FORM_MAIN

   ACTIVATE WINDOW FORM_MAIN

   RETURN NIL

FUNCTION AddText( t )

   LOCAL a := FORM_MAIN.EDITBOX_1.VALUE

   a := a + t + Chr(13) + Chr(10)
   FORM_MAIN.EDITBOX_1.Value := a

   RETURN NIL

   // SET

FUNCTION SetIp1

   FORM_MAIN.IPADDRESS_1.VALUE := {} // clear ip address

   RETURN NIL

FUNCTION SetIp2

   FORM_MAIN.IPADDRESS_2.VALUE := {127,0,0,1}

   RETURN NIL

FUNCTION SetIp3

   FORM_MAIN.IPADDRESS_3.VALUE := {255,255,255,255}

   RETURN NIL

   // GET

FUNCTION GetIp1

   LOCAL a := FORM_MAIN.IPADDRESS_1.VALUE

   MsgInfo(StrZero(a[1],3)+"."+StrZero(a[2],3)+"."+StrZero(a[3],3)+"."+StrZero(a[4],3),"Info")

   RETURN NIL

FUNCTION GetIp2

   LOCAL a := FORM_MAIN.IPADDRESS_2.VALUE

   MsgInfo(StrZero(a[1],3)+"."+StrZero(a[2],3)+"."+StrZero(a[3],3)+"."+StrZero(a[4],3),"Info")

   RETURN NIL

FUNCTION GetIp3

   LOCAL a := FORM_MAIN.IPADDRESS_3.VALUE

   MsgInfo(StrZero(a[1],3)+"."+StrZero(a[2],3)+"."+StrZero(a[3],3)+"."+StrZero(a[4],3),"Info")

   RETURN NIL
