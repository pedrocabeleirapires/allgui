/*
* MINIGUI - Harbour Win32 GUI library Demo
* Copyright 2016 Grigory Filatov <gfilatov@inbox.ru>
*/

ANNOUNCE RDDSYS

#include "minigui.ch"
#include "rmchart.ch"

#define RMC_USERWM         ""               // Your watermark
#define RMC_USERWMCOLOR    COLOR_BLACK      // Color for the watermark
#define RMC_USERWMLUCENT   30               // Lucent factor between 1(=not visible) and 255(=opaque)
#define RMC_USERWMALIGN    RMC_TEXTCENTER   // Alignment for the watermark
#define RMC_USERFONTSIZE   0                // Fontsize; if 0: maximal size is used

#define APP_TITLE "Example 4 RMCHART"

#define ID_CHART   1001
#define ID_CHART_2 1002

STATIC oRMChart, lDraw := .F.

SET PROCEDURE TO rmchart.prg

PROCEDURE Main

   SET FONT TO "Times New Roman" , 10

   oRMChart := RMChart():New()

   DEFINE WINDOW Win_1 ;
         AT 0,0 ;
         WIDTH 680 ;
         HEIGHT 550 ;
         TITLE APP_TITLE ;
         ICON "demo.ico" ;
         MAIN ;
         NOMAXIMIZE NOSIZE ;
         ON INTERACTIVECLOSE iif( MsgYesNo("Really want to quit ?", "Exit"), EndWindow( .F. ), .F. )

      @ 475, 100 BUTTON Btn_Chart ;
         CAPTION "RMCHART" ;
         ACTION Chart( thiswindow.Handle ) ;
         WIDTH 150 HEIGHT 30 DEFAULT

      @ 475, 270 BUTTON Btn_Print ;
         CAPTION "PRINT" ;
         ACTION PrintChart( thiswindow.Handle ) ;
         WIDTH 150 HEIGHT 30

      @ 475, 440 BUTTON Btn_Cancel ;
         CAPTION "Close" ;
         ACTION EndWindow() ;
         WIDTH 150 HEIGHT 30

      ON KEY ESCAPE ACTION Win_1.Btn_Cancel.OnClick

   END WINDOW

   CENTER WINDOW Win_1
   ACTIVATE WINDOW Win_1

   RETURN

PROCEDURE Chart( hWnd )

   IF !lDraw
      lDraw := .T.
      Graphic4( hWnd, oRMChart, ID_CHART )
      oRMChart:Draw( ID_CHART )
   ENDIF

   RETURN

   #define RMC_PORTRAIT  1
   #define RMC_LANDSCAPE 2

PROCEDURE PrintChart( hWnd )

   Graphic4( hWnd, oRMChart, ID_CHART_2, .T. )

   IF CallDll32( "RMC_DRAW2PRINTER", "RMCHART.DLL", ID_CHART_2, RMC_LANDSCAPE, 10, 10, 220, 150, RMC_EMFPLUS ) < 0

      MsgStop("Print error!")

   ENDIF

   oRmChart:DeleteChart( ID_CHART_2 )

   RETURN

PROCEDURE endwindow( lClose )

   DEFAULT lClose To .T.

   IF lDraw
      oRmChart:DeleteChart( ID_CHART )
      oRMChart:Destroy()
   ENDIF

   IF lClose
      Win_1.Release
   ENDIF

   RETURN

FUNCTION Graphic4( hWnd, oRMChart, nIdChart, nExportOnly, MAX_SIZE_ONE, MAX_SIZE_TWO )

   DEFAULT nExportOnly TO .F., MAX_SIZE_ONE TO 650, MAX_SIZE_TWO TO 450

   oRMChart:CreateChart(hWnd,nIdChart,10,10,MAX_SIZE_ONE,MAX_SIZE_TWO,COLOR_TRANSPARENT,RMC_CTRLSTYLEIMAGE,nExportOnly,"seasky.jpg","Tahoma", 0, COLOR_DEFAULT)
   oRMChart:AddRegion(nIdChart,5,5,-15,-15,"",.F.)
   oRMChart:AddGrid(nIdChart,1,COLOR_TRANSPARENT,.F.,0,0,0,0,RMC_BICOLOR_NONE)
   oRMChart:AddDataAxis(nIdChart,1,RMC_DATAAXISLEFT,0,100,11,8,COLOR_CHALK,COLOR_CHALK,RMC_LINESTYLEDOT,0,"","","",RMC_TEXTCENTER)
   oRMChart:AddLabelAxis(nIdChart,1, "Label 1*Label 2*Label 3*Label 4*Label 5",1,5,RMC_LABELAXISBOTTOM,8,COLOR_YELLOW,RMC_TEXTCENTER,COLOR_CHALK,RMC_LINESTYLENONE,"")
   oRMChart:AddBarSeries(nIdChart,1,{ 50, 70, 40, 60, 30 }, 5,RMC_BARSINGLE,RMC_BAR_FLAT_GRADIENT2,.T.,COLOR_TRANSPARENT,.F.,1,RMC_VLABEL_NONE,1,RMC_HATCHBRUSH_OFF)
   oRMChart:SetWatermark(RMC_USERWM,RMC_USERWMCOLOR,RMC_USERWMLUCENT,RMC_USERWMALIGN,RMC_USERFONTSIZE)

   RETURN NIL

