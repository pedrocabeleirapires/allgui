/*
* $Id: grid_6.prg,v 1.3 2008/10/08 18:06:39 lculik Exp $
* HWGUI - Harbour Win32 GUI library source code:
* HGrid class
* Copyright 2002 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://www.geocities.com/alkresin/
* Copyright 2004 Rodrigo Moreno <rodrigo_moreno@yahoo.com>
*/

#include "windows.ch"
#include "guilib.ch"
#define LVS_REPORT              1
#define LVS_ICON                0x0000
#define LVS_SMALLICON           0x0002
#define LVS_LIST                0x0003

STATIC oMain, oForm, oFont, oGrid

FUNCTION Main()

   INIT WINDOW oMain MAIN TITLE "Grid Sample" ;
      AT 0,0 ;
      SIZE GetDesktopWidth(), GetDesktopHeight() - 28

   MENU OF oMain
   MENUITEM "&Exit"      ACTION oMain:Close()
   MENUITEM "&Grid Demo" ACTION Test()
ENDMENU

ACTIVATE WINDOW oMain

RETURN NIL

FUNCTION Test()

   LOCAL aHead :={}
   LOCAL n
   LOCAL aItems :={}
   LOCAL aStru

   USE test new
   aStru := dbstruct()
   FOR n :=1 to len(astru)
      aadd(aHead,aStru[n,1])
   NEXT
   GO TOP
   WHILE !eof()
      aadd(aItems,{first,last,city,str(salary,10,2)})
      SKIP
   ENDDO

   PREPARE FONT oFont NAME "Courier New" WIDTH 0 HEIGHT -11

   INIT DIALOG oForm CLIPPER NOEXIT TITLE "Grid Demo";
      FONT oFont ;
      AT 0, 0 SIZE 700, 425 ;
      STYLE DS_CENTER + WS_POPUP + WS_VISIBLE + WS_CAPTION + WS_SYSMENU
   //             on init {||SetGrid(oForm,oGrid,aItems)}

   @ 10,10 GRIDEX oGrid OF oForm ID 800 SIZE 680,375 ;
      ITEMCOUNT 10000 ;
      ON KEYDOWN {|oCtrl, key| OnKey(oCtrl, key) } ;
      ON POSCHANGE {|oCtrl, nRow| OnPoschange(oCtrl, nRow) } ;
      ON CLICK {|oCtrl| OnClick(oCtrl) } ;
      COLOR VColor('D3D3D3');
      ON DISPINFO {|oCtrl, nRow, nCol| OnDispInfo( oCtrl, nRow, nCol ) } ;
      BACKCOLOR VColor('BEBEBE')  ;
      BITMAP { 2, 3, 4, 5 }   ITEMS aItems

   ADD COLUMN TO GRID oGrid HEADER aHead[1] WIDTH 150  bitmap 1
   ADD COLUMN TO GRID oGrid HEADER aHead[2] WIDTH 150  bitmap 2
   ADD COLUMN TO GRID oGrid HEADER aHead[3] WIDTH 150  bitmap 3
   ADD COLUMN TO GRID oGrid HEADER aHead[4] WIDTH 150  bitmap 4

   FOR n:=1 to len(aItems)
      ADDROWEX TO GRID  oGrid header aItems[n,1] bitmap 0 color rgb(255,12,123) backcolor rgb(192,0,255) ,header aItems[n,2]  ,header aItems[n,3] bitmap 3  ,header aItems[n,1] bitmap 1 color rgb(123,122,123)  backcolor rgb(192,0,255)
   NEXT

   @ 0, 395 button "LVS_REPORT" size 95,25 on click  {|| LISTVIEW_SETVIEW(oGrid:handle,LVS_REPORT)}
   @ 100, 395 button "LVS_ICON" size 95,25 on click  {|| LISTVIEW_SETVIEW(oGrid:handle,LVS_ICON)}
   @ 200, 395 button "LVS_SMALLICON" size 95,25 on click  {|| LISTVIEW_SETVIEW(oGrid:handle,LVS_SMALLICON)}
   @ 300, 395 button "LVS_LIST" size 95,25 on click  {|| LISTVIEW_SETVIEW(oGrid:handle,LVS_LIST)}
   @ 700, 395 BUTTON 'Close' SIZE 95,25 ON CLICK {|| oForm:Close() }

   ACTIVATE DIALOG oForm

   RETURN NIL

FUNCTION OnKey( o, k )

   //    msginfo(str(k))

   RETURN NIL

FUNCTION OnPosChange( o, row )

   //    msginfo( str(row) )

   RETURN NIL

FUNCTION OnClick( o )

   //    msginfo( 'click' )

   RETURN NIL

FUNCTION OnDispInfo( o, x, y )

   RETURN 'Row: ' + ltrim(str(x)) + ' Col: ' + ltrim(str(y))

