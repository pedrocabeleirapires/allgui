/*
 * $Id: hmonthc.prg,v 1.16 2008/06/28 15:17:53 mlacecilia Exp $
 *
 * HWGUI - Harbour Win32 GUI library source code:
 * HMonthCalendar class
 *
 * Copyright 2004 Marcos Antonio Gambeta <marcos_gambeta@hotmail.com>
 * www - http://geocities.yahoo.com.br/marcosgambeta/
*/

//--------------------------------------------------------------------------//

#include "windows.ch"
#include "hbclass.ch"
#include "guilib.ch"

#define MCS_DAYSTATE             1
#define MCS_MULTISELECT          2
#define MCS_WEEKNUMBERS          4
#define MCS_NOTODAYCIRCLE        8
#define MCS_NOTODAY             16

//--------------------------------------------------------------------------//

CLASS HMonthCalendar INHERIT HControl

   CLASS VAR winclass   INIT "SysMonthCal32"

   DATA value
   DATA bChange

   METHOD New( oWndParent, nId, vari, nStyle, nLeft, nTop, nWidth, nHeight, ;
               oFont, bInit, bChange, cTooltip, lNoToday, lNoTodayCircle, ;
               lWeekNumbers )
   METHOD Activate()
   METHOD Init()
   METHOD SetValue( dValue )
   METHOD GetValue()

ENDCLASS

//--------------------------------------------------------------------------//

METHOD New( oWndParent, nId, vari, nStyle, nLeft, nTop, nWidth, nHeight, ;
            oFont, bInit, bChange, cTooltip, lNoToday, lNoTodayCircle, ;
            lWeekNumbers ) CLASS HMonthCalendar

   nStyle := Hwg_BitOr( Iif( nStyle==Nil, 0, nStyle ), WS_TABSTOP )
   nStyle   += Iif( lNoToday==Nil.OR.!lNoToday, 0, MCS_NOTODAY )
   nStyle   += Iif( lNoTodayCircle==Nil.OR.!lNoTodayCircle, 0, MCS_NOTODAYCIRCLE )
   nStyle   += Iif( lWeekNumbers==Nil.OR.!lWeekNumbers, 0, MCS_WEEKNUMBERS )
   Super:New( oWndParent,nId,nStyle,nLeft,nTop,nWidth,nHeight,oFont,bInit, ;
                  ,,ctooltip )

   ::value   := Iif( Valtype(vari)=="D" .And. !Empty(vari), vari, Date() )

   ::bChange := bChange

   HWG_InitCommonControlsEx()


   If bChange != Nil 
      ::oParent:AddEvent( MCN_SELECT, self, bChange, .T.,"onChange" )
      ::oParent:AddEvent( MCN_SELCHANGE, self, bChange, .T.,"onChange" )
   EndIf 

   ::Activate()
Return Self

//--------------------------------------------------------------------------//

METHOD Activate CLASS HMonthCalendar

   IF !empty( ::oParent:handle ) 
      ::handle := InitMonthCalendar ( ::oParent:handle, ::id, ::style, ;
                  ::nLeft, ::nTop, ::nWidth, ::nHeight )
      ::Init()
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD Init() CLASS HMonthCalendar

   If !::lInit
      Super:Init()
      If !Empty( ::value )
         SetMonthCalendarDate( ::handle , ::value )
      EndIf
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD SetValue( dValue ) CLASS HMonthCalendar

   If Valtype(dValue)=="D" .And. !Empty(dValue)
      SetMonthCalendarDate( ::handle, dValue )
      ::value := dValue
   EndIf

Return Nil

//--------------------------------------------------------------------------//

METHOD GetValue() CLASS HMonthCalendar

   ::value := GetMonthCalendarDate( ::handle )

Return (::value)

//--------------------------------------------------------------------------//

#pragma BEGINDUMP

#define _WIN32_IE      0x0500
#define HB_OS_WIN_32_USED
#define _WIN32_WINNT   0x0400
#include "guilib.h"
#include <windows.h>
#include <commctrl.h>

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbdate.h"

#if defined(__DMC__)
#include "missing.h"
#endif

HB_FUNC ( INITMONTHCALENDAR )
{
   HWND hMC;
   RECT rc;

   hMC = CreateWindowEx( 0,
                         MONTHCAL_CLASS,
                         "",
                         (LONG) hb_parnl(3),
                         0,0,0,0,
                         (HWND) HB_PARHANDLE(1),
                         (HMENU) hb_parni(2),
                         GetModuleHandle(NULL),
                         NULL );

   MonthCal_GetMinReqRect( hMC, &rc );

   SetWindowPos( hMC, NULL, hb_parni(4), hb_parni(5), rc.right, rc.bottom, SWP_NOZORDER );

    HB_RETHANDLE(  hMC );
}

HB_FUNC ( SETMONTHCALENDARDATE ) // adaptation of function SetDatePicker of file Control.c
{
   PHB_ITEM pDate = hb_param( 2, HB_IT_DATE );

   if( pDate )
   {
      SYSTEMTIME sysTime;
      #ifndef HARBOUR_OLD_VERSION
      int lYear, lMonth, lDay;
      #else
      long lYear, lMonth, lDay;
      #endif

      hb_dateDecode( hb_itemGetDL( pDate ), &lYear, &lMonth, &lDay );

      sysTime.wYear = (unsigned short) lYear;
      sysTime.wMonth = (unsigned short) lMonth;
      sysTime.wDay = (unsigned short) lDay;
      sysTime.wDayOfWeek = 0;
      sysTime.wHour = 0;
      sysTime.wMinute = 0;
      sysTime.wSecond = 0;
      sysTime.wMilliseconds = 0;

      MonthCal_SetCurSel( (HWND) HB_PARHANDLE (1), &sysTime);

   }
}

HB_FUNC ( GETMONTHCALENDARDATE ) // adaptation of function GetDatePicker of file Control.c
{
   SYSTEMTIME st;
   char szDate[9];

   SendMessage( (HWND) HB_PARHANDLE (1), MCM_GETCURSEL, 0, (LPARAM) &st);

   hb_dateStrPut( szDate, st.wYear, st.wMonth, st.wDay );
   szDate[8] = 0;
   hb_retds( szDate );
}

#pragma ENDDUMP

