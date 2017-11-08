/*
 * $Id: h_checklist.prg,v 1.26 2017/08/25 19:42:18 fyurisich Exp $
 */
/*
 * ooHG source code:
 * CheckList control
 *
 * Copyright 2012-2017 Fernando Yurisich <fyurisich@oohg.org>
 * https://sourceforge.net/projects/oohg/
 *
 * Portions of this project are based upon Harbour MiniGUI library.
 * Copyright 2002-2005 Roberto Lopez <roblez@ciudad.com.ar>
 *
 * Portions of this project are based upon Harbour GUI framework for Win32.
 * Copyright 2001 Alexander S. Kresin <alex@belacy.belgorod.su>
 * Copyright 2001 Antonio Linares <alinares@fivetech.com>
 *
 * Portions of this project are based upon Harbour Project.
 * Copyright 1999-2017, https://harbour.github.io/
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1335,USA (or download from http://www.gnu.org/licenses/).
 *
 * As a special exception, the ooHG Project gives permission for
 * additional uses of the text contained in its release of ooHG.
 *
 * The exception is that, if you link the ooHG libraries with other
 * files to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the ooHG library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the ooHG
 * Project under the name ooHG. If you copy code from other
 * ooHG Project or Free Software Foundation releases into a copy of
 * ooHG, as the General Public License permits, the exception does
 * not apply to the code that you add in this way. To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for ooHG, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 */


#include "oohg.ch"
#include "hbclass.ch"
#include "i_windefs.ch"

CLASS TCheckList FROM TGrid
   DATA Type                   INIT "CHECKLIST" READONLY
   DATA lCheckBoxes            INIT .T. READONLY
   DATA FullMove               INIT .F. READONLY
   DATA InPlace                INIT .F. READONLY
   DATA AllowEdit              INIT .F. READONLY
   DATA LastChangedItem        INIT 0

   METHOD Define
   METHOD Value                SETGET
   METHOD Events
   METHOD Events_Notify
   METHOD Width                SETGET
   METHOD CheckItem            SETGET
   METHOD DeleteAllItems
   METHOD AddItem
   METHOD InsertItem
   METHOD Sort
   METHOD DeleteItem
   METHOD ItemVisible
   METHOD Item
   METHOD SetRangeColor
   METHOD ItemCaption          SETGET
   METHOD ItemImage            SETGET
   METHOD DoChange

/*
   This methods of TGrid class are also available:

   METHOD Define2
   METHOD SetItemColor
   METHOD SetSelectedColors
   METHOD InsertBlank
   METHOD ItemCount            BLOCK { | Self | ListViewGetItemCount( ::hWnd ) }
   METHOD CountPerPage         BLOCK { | Self | ListViewGetCountPerPage( ::hWnd ) }
   METHOD FirstSelectedItem    BLOCK { | Self | ListView_GetFirstItem( ::hWnd ) }
   METHOD FontColor            SETGET
   METHOD BackColor            SETGET
   METHOD Events_Enter
   METHOD OnEnter
   METHOD Release
*/

// This methods of TGrid class are not needed:

   METHOD Left                 BLOCK { || Nil }
   METHOD Right                BLOCK { || Nil }
   METHOD Up                   BLOCK { || Nil }
   METHOD Down                 BLOCK { || Nil }
   METHOD PageDown             BLOCK { || Nil }
   METHOD PageUp               BLOCK { || Nil }
   METHOD GoTop                BLOCK { || Nil }
   METHOD GoBottom             BLOCK { || Nil }
   METHOD AddColumn            BLOCK { || Nil }
   METHOD DeleteColumn         BLOCK { || Nil }
   METHOD Cell                 BLOCK { || Nil }
   METHOD EditCell             BLOCK { || Nil }
   METHOD EditCell2            BLOCK { || Nil }
   METHOD EditAllCells         BLOCK { || Nil }
   METHOD EditItem             BLOCK { || Nil }
   METHOD EditItem2            BLOCK { || Nil }
   METHOD EditGrid             BLOCK { || Nil }
   METHOD IsColumnReadOnly     BLOCK { || Nil }
   METHOD IsColumnWhen         BLOCK { || Nil }
   METHOD ToExcel              BLOCK { || Nil }
   METHOD ToOpenOffice         BLOCK { || Nil }
   METHOD AppendItem           BLOCK { || Nil }
   METHOD ColumnCount          BLOCK { || Nil }
   METHOD ColumnAutoFit        BLOCK { || Nil }
   METHOD ColumnAutoFitH       BLOCK { || Nil }
   METHOD ColumnsAutoFit       BLOCK { || Nil }
   METHOD ColumnsAutoFitH      BLOCK { || Nil }
   METHOD ColumnBetterAutoFit  BLOCK { || Nil }
   METHOD ColumnsBetterAutoFit BLOCK { || Nil }
   METHOD ColumnHide           BLOCK { || Nil }
   METHOD ColumnShow           BLOCK { || Nil }
   METHOD ColumnWidth          BLOCK { || Nil }
   METHOD SortColumn           BLOCK { || Nil }
   METHOD Header               BLOCK { || Nil }
   METHOD HeaderImage          BLOCK { || Nil }
   METHOD HeaderImageAlign     BLOCK { || Nil }
   METHOD LoadHeaderImages     BLOCK { || Nil }

   EMPTY( _OOHG_AllVars )
ENDCLASS

*------------------------------------------------------------------------------*
METHOD Define( ControlName, ParentForm, x, y, w, h, aRows, v, fontname, ;
               fontsize, tooltip, change, gotfocus, lostfocus, aImage, just, ;
               break, HelpId, bold, italic, underline, strikeout, backcolor, ;
               fontcolor, lRtl, lDisabled, lNoTabStop, lInvisible, sort, ;
               descending, aSelectedColors, dblbffr, click ) CLASS TCheckList
*------------------------------------------------------------------------------*
LOCAL aHdr, aWidth, aJust, aPic, aEdC

   ASSIGN w          VALUE w          TYPE "N" DEFAULT ::nWidth
   ASSIGN v          VALUE v          TYPE "A" DEFAULT {}
   ASSIGN sort       VALUE sort       TYPE "L" DEFAULT .F.
   ASSIGN descending VALUE descending TYPE "L" DEFAULT .F.

   If HB_IsArray( aImage ) .AND. Len( aImage ) > 0
      aHdr := {''}
      aWidth := { 0 }
      aJust := { just }
      aPic := {.T.}
      aEdC := { {'IMAGEDATA', {'TEXTBOX', 'CHARACTER'}} }

      If HB_IsArray( aRows )
         If aScan( aRows, { |a| ! HB_IsArray( a ) .OR. ;
                                Len( a ) # 2 .OR. ;
                                ! ValType( a[1] ) $ "CM" .OR. ;
                                ValType( a[2] ) # "N" } ) > 0
            MsgOOHGError( "CheckList.Define: Invalid items. Program Terminated." )
         EndIf
      Else
         aRows := {}
      EndIf
   Else
      aHdr := {''}
      aWidth := { 0 }
      aJust := { just }
      aImage := Nil
      aPic := Nil
      aEdC := { {'TEXTBOX', 'CHARACTER'} }

      If HB_IsArray( aRows )
         If aScan( aRows, { |a| ! ValType( a ) $ "CM" } ) > 0
            MsgOOHGError( "CheckList.Define: Invalid items. Program Terminated." )
         EndIf
      Else
         aRows := {}
      EndIf
   EndIf

/*
METHOD Define( ControlName, ParentForm, x, y, w, h, aHeaders, aWidths, ;
               aRows, value, fontname, fontsize, tooltip, change, dblclick, ;
               aHeadClick, gotfocus, lostfocus, nogrid, aImage, aJust, ;
               break, HelpId, bold, italic, underline, strikeout, ownerdata, ;
               ondispinfo, itemcount, editable, backcolor, fontcolor, ;
               dynamicbackcolor, dynamicforecolor, aPicture, lRtl, inplace, ;
               editcontrols, readonly, valid, validmessages, editcell, ;
               aWhenFields, lDisabled, lNoTabStop, lInvisible, lHasHeaders, ;
               onenter, aHeaderImage, aHeaderImageAlign, FullMove, ;
               aSelectedColors, aEditKeys, lCheckBoxes, oncheck, lDblBffr, ;
               lFocusRect, lPLM, lFixedCols, abortedit, click, lFixedWidths, ;
               bBeforeColMove, bAfterColMove, bBeforeColSize, bAfterColSize, ;
               bBeforeAutofit, lLikeExcel, lButtons, AllowDelete, onDelete, ;
               bDelWhen, DelMsg, lNoDelMsg, AllowAppend, onappend, lNoModal, ;
               lFixedCtrls, bHeadRClick, lClickOnCheckbox, lRClickOnCheckbox, ;
               lExtDbl, lSilent, lAltA, lNoShowAlways, lNone, lCBE, onrclick ) CLASS TGrid
*/
   ::Super:Define( ControlName, ParentForm, x, y, w, h, aHdr, aWidth, ;
                   {}, Nil, fontname, fontsize, tooltip, change, Nil, ;
                   Nil, gotfocus, lostfocus, .T., aImage, aJust, ;
                   break, HelpId, bold, italic, underline, strikeout, .F., ;
                   Nil, Nil, .F., backcolor, fontcolor, ;
                   Nil, Nil, aPic, lRtl, .F., ;
                   aEdC, .T., Nil, Nil, Nil, ;
                   Nil, lDisabled, lNoTabStop, lInvisible, .F., ;
                   Nil, Nil, Nil, .F., ;
                   aSelectedColors, Nil, .T., Nil, dblbffr, ;
                   .F., .F., .T., Nil, click, .T., ;
                   Nil, Nil, Nil, Nil, ;
                   Nil, Nil, Nil, Nil, Nil, ;
                   Nil, Nil, Nil, Nil, Nil, Nil, ;
                   .T., Nil, Nil, Nil, ;
                   Nil, Nil, .F., .F., .F., Nil, Nil )

   aEval( aRows, { |u| ::AddItem( u ) } )

   ::Width := w

   If Sort
     ::Sort( descending )
   EndIf

   ::Value := v

Return Self

*------------------------------------------------------------------------------*
METHOD Value( aValue ) CLASS TCheckList
*------------------------------------------------------------------------------*
LOCAL lChanged, i, lOld, lSet, nFirst, aItems

   If HB_IsArray( aValue )
      // do not use ::CheckItem to set the new value to avoid firing OnChange event more than once
      lChanged := .F.
      nFirst := 0

      For i := 1 to ::ItemCount
         lOld := ListView_GetCheckState( ::hwnd, i )
         lSet := ( aScan( aValue, i ) > 0 )

         If lSet # lOld
            If ListView_SetCheckState( ::hwnd, i, lSet ) == lSet
               lChanged := .T.
               ::LastChangedItem := i
               If lSet .and. nFirst == 0
                 nFirst := i
               EndIf
            EndIf
         EndIf
      Next i

      If lChanged
         If nFirst > 0
            ::ItemVisible( nFirst )
         EndIf

         ::DoChange()
      EndIf
   EndIf

   aItems := {}
   For i := 1 to ::ItemCount
      If ListView_GetCheckState( ::hwnd, i )
         aAdd( aItems, i )
      EndIf
   Next

Return aItems

*------------------------------------------------------------------------------*
METHOD Events( hWnd, nMsg, wParam, lParam ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local nNext

   If nMsg == WM_LBUTTONDBLCLK
      // ignore double click on checkbox, it was processed as single click
      If ListView_HitOnCheckBox( ::hWnd, GetCursorRow() - GetWindowRow( ::hWnd ), GetCursorCol() - GetWindowCol( ::hWnd ) ) == 0
         If HB_IsBlock( ::OnDblClick )
            ::DoEventMouseCoords( ::OnDblClick, "DBLCLICK" )
         EndIf
      EndIf
      Return 1

   ElseIf nMsg == WM_CONTEXTMENU
      // ignore right click on checkbox
      If ListView_HitOnCheckBox( ::hWnd, GetCursorRow() - GetWindowRow( ::hWnd ), GetCursorCol() - GetWindowCol( ::hWnd ) ) > 0
         Return 1
      EndIf

   ElseIf nMsg == WM_MOUSEWHEEL
      If GET_WHEEL_DELTA_WPARAM( wParam ) > 0
         nNext := ::FirstSelectedItem - 1
         If nNext > 0
            ListView_SetCursel( ::hWnd, nNext )
         EndIf
      Else
         nNext := ::FirstSelectedItem + 1
         If nNext <= ::ItemCount
            ListView_SetCursel( ::hWnd, nNext )
         EndIf
      EndIf
      Return 1
   EndIf

Return ::Super:Events( hWnd, nMsg, wParam, lParam )

*------------------------------------------------------------------------------*
METHOD Events_Notify( wParam, lParam ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local nNotify := GetNotifyCode( lParam )
Local uValue, uRet, nItem

   Empty( wParam )

   If nNotify == NM_CUSTOMDRAW
      // hide the horizontal scrollbar if any is shown
      If ::Super:ColumnWidth( 1 ) # ::ClientWidth
         ::Super:ColumnWidth( 1, ::ClientWidth )
      EndIf

      // this is the same as TGrid's
      uValue := ::FirstSelectedItem
      uRet := TGrid_Notify_CustomDraw( Self, lParam, .F., uValue, 0, ::lCheckBoxes, ::lFocusRect, ::lNoGrid, ::lPLM )
      ListView_SetCursel( ::hWnd, uValue )
      Return uRet

   ElseIf nNotify == LVN_KEYDOWN .AND. GetGridvKey( lParam ) == VK_SPACE
      // detect item
      nItem := ::FirstSelectedItem
      If nItem > 0
         // change check mark
         ::CheckItem( nItem, ! ::CheckItem( nItem ) )
         // skip default action
         Return 1
      EndIf

   ElseIf nNotify == LVN_ENDSCROLL
      // There is a bug in ListView under XP that causes the gridlines to be
      // incorrectly scrolled when the left button is clicked to scroll.
      // This is supposedly documented at KB 813791.
      RedrawWindow( ::hWnd )

   ElseIf nNotify == NM_CLICK
      // detect item
      nItem := ListView_HitOnCheckBox( ::hWnd, GetCursorRow() - GetWindowRow( ::hWnd ), GetCursorCol() - GetWindowCol( ::hWnd ) )
      If nItem > 0
         // change check mark
         ::CheckItem( nItem, ! ::CheckItem( nItem ) )
      Else
         If HB_IsBlock( ::OnClick )
            If ! ::NestedClick
               ::NestedClick := ! _OOHG_NestedSameEvent()
               ::DoEventMouseCoords( ::OnClick, "CLICK" )
               ::NestedClick := .F.
            EndIf
         EndIf
      EndIf
      // skip default action
      Return 1

   ElseIf nNotify == NM_RCLICK
      // detect item
      nItem := ListView_HitOnCheckBox( ::hWnd, GetCursorRow() - GetWindowRow( ::hWnd ), GetCursorCol() - GetWindowCol( ::hWnd ) )
      If nItem > 0
         // change check mark
         ::CheckItem( nItem, ! ::CheckItem( nItem ) )
         // this changes the checkbox
         Return 1
      Else
         If HB_IsBlock( ::OnRClick )
            ::DoEventMouseCoords( ::OnRClick, "RCLICK" )
         EndIf
      EndIf

   ElseIf nNotify == NM_KILLFOCUS
      Return ::DoLostFocus()

   ElseIf nNotify == NM_SETFOCUS
      GetFormObjectByHandle( ::ContainerhWnd ):LastFocusedControl := ::hWnd
      ::FocusEffect()
      ::DoEvent( ::OnGotFocus, "GOTFOCUS" )

   EndIf

// TGrid's Event_Notify method must be skipped
Return Nil

*------------------------------------------------------------------------------*
METHOD Width( nWidth ) CLASS TCheckList
*------------------------------------------------------------------------------*
   If pcount() > 0
      ::Super:Width( nWidth )
      ::Super:ColumnWidth( 1, ::ClientWidth )
   EndIf

Return ::nWidth

*------------------------------------------------------------------------------*
METHOD CheckItem( nItem, lChecked ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local lRet, lOld

   If HB_IsNumeric( nItem ) .AND. nItem >= 1 .AND. nItem <= ::ItemCount
      lOld := ListView_GetCheckState( ::hwnd, nItem )

      If HB_IsLogical( lChecked ) .AND. lChecked # lOld
         ListView_SetCheckState( ::hwnd, nItem, lChecked )

         lRet := ListView_GetCheckState( ::hwnd, nItem )

         If lRet # lOld
            ::LastChangedItem := nItem
            ::DoChange()
         EndIf
      Else
         lRet := lOld
      EndIf
   Else
      lRet := .F.
   EndIf

Return lRet

*------------------------------------------------------------------------------*
METHOD DeleteAllItems() CLASS TCheckList
*------------------------------------------------------------------------------*
Local aValue

   If ::ItemCount > 0
      aValue := ::Value

      ListViewReset( ::hWnd )
      ::GridForeColor := Nil
      ::GridBackColor := Nil

      ::LastChangedItem := 0

      If ! ArraysAreEqual( ::Value, aValue )
         ::DoChange()
      EndIf
   EndIf

Return Nil

*------------------------------------------------------------------------------*
METHOD AddItem( uItem, lChecked, uForeColor, uBackColor ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local aRow

   If ValidHandler( ::ImageList )
      If Len( uItem ) # 2
         MsgOOHGError( "CheckList.AddItem: Item size mismatch. Program Terminated." )
      ElseIf ! HB_IsArray( uItem ) .OR. ! ValType( uItem[1] ) $ "CM" .OR. ValType( uItem[2] ) # "N"
         MsgOOHGError( "CheckList.AddItem: Invalid item. Program Terminated." )
      EndIf
   Else
      If ! ValType( uItem ) $ "CM"
         MsgOOHGError( "CheckList.AddItem: Invalid item. Program Terminated." )
      EndIf
   EndIf
   aRow := { uItem }

   ::Super:AddItem( aRow, uForeColor, uBackColor )

   // because the new item is added at the end of the list,
   // it's not necessary to change ::LastChangedItem unless
   // the new item is checked

   If HB_IsLogical( lChecked ) .and. lChecked
      ::CheckItem( ::ItemCount, .T. )
   EndIf

Return ::ItemCount

*------------------------------------------------------------------------------*
METHOD InsertItem( nItem, uItem, lChecked, uForeColor, uBackColor ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local aRow, aValue

   If ValidHandler( ::ImageList )
      If Len( uItem ) # 2
         MsgOOHGError( "CheckList.InsertItem: Item size mismatch. Program Terminated." )
      ElseIf ! HB_IsArray( uItem ) .OR. ! ValType( uItem[1] ) $ "CM" .OR. ValType( uItem[2] ) # "N"
         MsgOOHGError( "CheckList.InsertItem: Invalid item. Program Terminated." )
      EndIf
   Else
      If ! ValType( uItem ) $ "CM"
         MsgOOHGError( "CheckList.InsertItem: Invalid item. Program Terminated." )
      EndIf
   EndIf
   aRow := { uItem }

   aValue := ::Value

   nItem := ::Super:InsertItem( nItem, aRow, uForeColor, uBackColor )

   If nItem > 0
      If HB_IsLogical( lChecked ) .and. lChecked
         ::CheckItem( nItem, .T. )
      ElseIf ! ArraysAreEqual( ::Value, aValue )
         ::LastChangedItem := nItem
         ::DoChange()
      EndIf
   EndIf

Return nItem

*------------------------------------------------------------------------------*
METHOD Sort( lDescending ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local aValue, lRet

   ASSIGN lDescending VALUE lDescending TYPE "L" DEFAULT .F.
   aValue := ::Value

   lRet := ::Super:SortColumn( 1, lDescending )

   If ! ArraysAreEqual( ::Value, aValue )
      ::LastChangedItem := 0
      ::DoChange()
   EndIf

Return lRet

*------------------------------------------------------------------------------*
METHOD DeleteItem( nItem ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local lChanged

   lChanged := ( aScan( ::Value, nItem ) > 0 )

   ::Super:DeleteItem( nItem )

   ::LastChangedItem := 0

   If lChanged
      ::DoChange()
   EndIf

Return Nil

*------------------------------------------------------------------------------*
METHOD ItemVisible( nItem ) CLASS TCheckList
*------------------------------------------------------------------------------*

Return ListView_EnsureVisible( ::hWnd, nItem )

*------------------------------------------------------------------------------*
METHOD Item( nItem, uItem, lChecked, uForeColor, uBackColor ) CLASS TCheckList
*------------------------------------------------------------------------------*
Local aRow

   If ValidHandler( ::ImageList )
      If Len( uItem ) # 2
         MsgOOHGError( "CheckList.Item: Item size mismatch. Program Terminated." )
      ElseIf ! HB_IsArray( uItem ) .OR. ! ValType( uItem[1] ) $ "CM" .OR. ValType( uItem[2] ) # "N"
         MsgOOHGError( "CheckList.Item: Invalid item. Program Terminated." )
      EndIf
   Else
      If ! ValType( uItem ) $ "CM"
         MsgOOHGError( "CheckList.Item: Invalid item. Program Terminated." )
      EndIf
   EndIf
   aRow := { uItem }

   uItem := ::Super:Item( nItem, aRow, uForeColor, uBackColor)

   If HB_IsLogical( lChecked )
      ::CheckItem( nItem, lChecked )
   EndIf

Return uItem

*------------------------------------------------------------------------------*
METHOD SetRangeColor( uForeColor, uBackColor, nTop, nBottom ) CLASS TCheckList
*------------------------------------------------------------------------------*

Return ::Super:SetRangeColor( uForeColor, uBackColor, nTop, 1, nBottom, 1 )

*------------------------------------------------------------------------------*
METHOD DoChange() CLASS TCheckList
*------------------------------------------------------------------------------*
Local xValue, cType, cOldType
   xValue   := ::Value
   cType    := VALTYPE( xValue )
   cOldType := VALTYPE( ::xOldValue )
   cType    := IF( cType    == "M", "C", cType )
   cOldType := IF( cOldType == "M", "C", cOldType )
   IF cOldType == "U" .OR. ;
      ! cType == cOldType .OR. ;
      IF( cType == "A", ;
          ! ArraysAreEqual( xValue, ::xOldValue ), ;
          ! xValue == ::xOldValue )
      ::xOldValue := xValue
      ::DoEvent( ::OnChange, "CHANGE" )
   ENDIF
Return nil

*------------------------------------------------------------------------------*
METHOD ItemCaption( nItem, cCaption ) CLASS TCheckList
*------------------------------------------------------------------------------*

   If nItem < 1 .OR. nItem > ::ItemCount
      // return the same value as if the item exist and has no caption
      Return ""
   EndIf

Return ::Super:CellCaption( nItem, 1, cCaption )

*------------------------------------------------------------------------------*
METHOD ItemImage( nItem, nImage ) CLASS TCheckList
*------------------------------------------------------------------------------*

   If nItem < 1 .OR. nItem > ::ItemCount
      // return the same value as if the item exist and has no image
      Return -1
   EndIf

Return ::Super:CellImage( nItem, 1, nImage )

*------------------------------------------------------------------------------*
FUNCTION ArraysAreEqual( array1, array2 )
*------------------------------------------------------------------------------*

Return aEqual( array1, array2 )

/*
 * EOF
 */