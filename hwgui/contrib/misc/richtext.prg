/*
* $Id: richtext.prg 2012 2013-03-07 09:03:56Z alkresin $
*/
/*
旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
�        Class: RichText                                                   �
�  Description: System for generating simple RTF files.                    �
�     Language: Clipper/Fivewin                                            �
�      Version: 0.90 -- This is a usable, but incomplete, version that is  �
�               being distributed in case anyone cares to use it as-is,    �
�               or wants to comment on it.                                 �
�         Date: 01/28/97                                                   �
�       Author: Tom Marchione                                              �
�     Internet: 73313,3626@compuserve.com                                  �
�                                                                          �
�    Copyright: (C) 1997, Thomas R. Marchione                              �
�       Rights: Use/modify freely for applicaton work, under the condition �
�               that you include the original author's credits (i.e., this �
�               header), and you do not offer the source code for sale.    �
�               The author may or may not supply updates and revisions     �
�               to this code as "freeware".                                �
�                                                                          �
�   Warranties: None. The code has not been rigorously tested in a formal  �
�               development environment, and is offered as-is.  The author �
�               assumes no responsibility for its use.                     �
�                                                                          �
�    Revisions:                                                            �
�                                                                          �
�    DATE       AUTHOR  COMMENTS                                           �
냐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴캐
�    01/28/97   TRM     Date of initial release                            �
�    20/10/00   JIJA    Add new methods and rewrites the table methods     �
�                       to make compatible with MSWORD.                    �
�    01/12/00   JIJA    Add Image managament for WMF,JPG,TIFF,PCX                                                                      �
�                                                                          �
�                                                                          �
읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
*/

#include "hbclass.ch"
#include "common.ch"
#include "guilib.ch"
#include "windows.ch"

#include "richtext.ch"
#define CRLF hb_osnewline()

CLASS RichText

   DATA cFileName, hFile
   DATA nFontSize
   DATA nFontColor
   DATA aTranslate
   DATA nFontNum
   DATA nScale
   DATA lTrimSpaces
   DATA nFontAct
   DATA cLastApar INIT ""
   DATA cLastBook INIT ""
   // Table Management
   DATA cTblHAlign, nTblFntNum, nTblFntSize, nTblRows, nTblColumns
   DATA nTblRHgt, aTableCWid, cRowBorder, cCellBorder, aColPct, nCellPct
   DATA lTblNoSplit, nTblHdRows, nTblHdHgt, nTblHdPct, nTblHdFont
   DATA nTblHdFSize, nTblHdColor, nTblHdFColor
   DATA cCellAppear, cHeadAppear
   DATA cCellHAlign, cHeadHAlign
   DATA nCurrRow, nCurrColumn
   DATA TblCJoin
   // textbox Variables
   DATA txtbox, aSztBox, aCltBox, cTpltBox, nWltBox, nFPtbox
   DATA aOfftbox
   // Facing
   DATA lFacing AS LOGICAL INIT .F.
   //Styles Managament
   DATA NStlDef INIT 1
   DATA nStlAct INIT 0
   DATA nCharStl INIT 1
   DATA nCharAct INIT 0
   DATA nStlSec INIT 1
   DATA nSectAct INIT 0
   DATA ParStyles AS Array INIT { }
   DATA CharStyles AS Array INIT { }
   DATA SectStyles AS Array INIT { }
   DATA oPrinter
   // Methods for opening & closing output file, and setting defaults

   METHOD New( cFileName, aFontData, aFontFam, aFontChar, nFontSize, nFontColor, nScale, aHigh ) CONSTRUCTOR

   METHOD END() INLINE ::TextCode( "par\pard" ), ::CloseGroup(), FClose( ::hFile )

   // Core methods for writing control codes & data to the output file

   METHOD TextCode( cCode ) //INLINE FWRITE(::hFile, FormatCode(cCode) )

   METHOD NumCode( cCode, nValue, lScale )

   METHOD LogicCode( cCode, lTest )

   METHOD Write( xData, lCodesOK )

   // Groups and Sections (basic RTF structures)

   METHOD OpenGroup() INLINE FWrite( ::hFile, "{" )

   METHOD CloseGroup() INLINE FWrite( ::hFile, "}" )

   METHOD NewSection( lLandscape, nColumns, nLeft, nRight, nTop, nBottom, ;
      nWidth, nHeight, cVertAlign, lDefault )
   // Higher-level page setup methods

   METHOD PageSetup( nLeft, nRight, nTop, nBottom, nWidth, nHeight, ;
      nTabWidth, lLandscape, lNoWidow, cVertAlign, ;
      cPgNumPos, lPgNumTop )

   METHOD BeginHeader() INLINE ::OpenGroup(), ;
      IIf( ! ::lFacing, ::TextCode( "header \pard" ), ::TextCode( "headerr \pard" ) )

   METHOD EndHeader() INLINE ::TextCode( "par" ), ::CloseGroup()

   METHOD BeginFooter() INLINE ::OpenGroup(), ;
      IIf( ! ::lFacing, ::TextCode( "footer \pard" ), ::TextCode( "footerr \pard" ) )

   METHOD EndFooter() INLINE ::TextCode( "par" ), ::CloseGroup()

   METHOD Paragraph( cText, nFontNumber, nFontSize, cAppear, ;
      cHorzAlign, aTabPos, nIndent, nFIndent, nRIndent, nSpace, ;
      lSpExact, nBefore, nAfter, lNoWidow, lBreak, ;
      lBullet, cBulletChar, lHang, lDefault, lNoPar, ;
      nFontColor, cTypeBorder, cBordStyle, nBordCol, nShdPct, cShadPat, ;
      nStyle, lChar )
   // Table Management

   METHOD DefineTable( cTblHAlign, nTblFntNum, nTblFntSize, ;
      cCellAppear, cCellHAlign, nTblRows, ;
      nTblColumns, nTblRHgt, aTableCWid, cRowBorder, cCellBorder, aColPct, nCellPct, ;
      lTblNoSplit, nTblHdRows, nTblHdHgt, nTblHdPct, nTblHdFont, ;
      nTblHdFSize, cHeadAppear, cHeadHAlign, nTblHdColor , nTblHdFColor )

   METHOD BeginRow() INLINE ::TextCode( "trowd" ), ::nCurrRow += 1

   METHOD EndRow()   INLINE ::TextCode( "row" )

   METHOD WriteCell( cText, nFontNumber, nFontSize, cAppear, cHorzAlign, ;
      nSpace, lSpExact, cCellBorder, nCellPct, nFontColor, lDefault )
   // Methods for formatting data

   METHOD Appearance( cAppear )

   METHOD HAlignment( cAlign )

   METHOD LineSpacing( nSpace, lSpExact )

   METHOD Borders( cEntity, cBorder )

   METHOD NewFont( nFontNumber )

   METHOD SetFontSize( nFontSize )

   METHOD SetFontColor( nFontColor )

   METHOD NewLine() INLINE FWrite( ::hFile, CRLF ), ::TextCode( "par" )

   METHOD NewPage() INLINE ::TextCode( "page" + CRLF )

   METHOD NumPage() INLINE ::TextCode( "chpgn" )

   METHOD CurrDate( cFormat )

   // General service methods

   METHOD BorderCode( cBorderID )

   METHOD ShadeCode( cShadeID )

   METHOD ParaBorder( cBorder, cType )

   METHOD BegBookMark( texto )

   METHOD EndBookMark()

   // Someday maybe we'll handle:
   // Styles

   METHOD SetStlDef()

   METHOD IncStyle( cName, styletype, nFontNumber, nFontSize, ;
      nFontColor, cAppear, cHorzAlign, nIndent, cKeys, ;
      cTypeBorder, cBordStyle, nBordColor, nShdPct, cShadPat, lAdd, LUpdate )

   METHOD BeginStly()

   METHOD WriteStly()

   METHOD ParaStyle( nStyle )

   METHOD CharStyle( nStyle )

   // Alternating shading of table rows
   // Footnotes & Endnotes

   METHOD FootNote( cTexto, cChar, nFontNumber, nFontSize, cAppear, nFontColor, lEnd, lAuto, lUpper )

   // Shaded text
   // Frames
   // Text Boxes

   METHOD BegTextBox( cTexto, aOffset, ASize, cTipo, aColores, nWidth, nPatron, ;
      lSombra, aSombra, nFontNumber, nFontSize, cAppear, nFontColor, nIndent, lRounded, lEnd )

   METHOD EndTextBox()

   METHOD SetFrame( ASize, cHorzAlign, cVertAlign, lNoWrap, cXAlign, xpos, cYAlign, ypos )

   // Font Colors

   METHOD SetClrTab()

   // Lines, Bitmaps & Graphics

   METHOD Linea( aInicio, aFinal, nxoffset, nyoffset, ASize, cTipo, ;
      aColores, nWidth, nPatron, lSombra, aSombra )

   METHOD Image( cName, ASize, nPercent, lCell, lInclude, lFrame, aFSize, cHorzAlign, ;
      cVertAlign, lNoWrap, cXAlign, xpos, cYAlign, ypos )
   // METHOD RtfJpg(cName,aSize,nPercent)
   // METHOD Wmf2Rtf(cName,aSize,nPercent)
   // METHOD Bmp2Wmf(cName,aSize,nPercent)
   // Information

   METHOD InfoDoc( cTitle, cSubject, cAuthor, cManager, cCompany, cOperator, ;
      cCategor, cKeyWords, cComment )

   METHOD DocFormat( nTab, nLineStart, lBackup, nDefLang, nDocType, ;
      cFootType, cFootNotes, cEndNotes, cFootNumber, nPage, cProtect, lFacing, nGutter )
   // Lots of other cool stuff
   // New Methods for table managament

   METHOD EndTable() INLINE ::CloseGroup()

   METHOD TableDef( lHeader, nRowHead, cCellBorder, aColPct )

   METHOD TableCell( cText, nFontNumber, nFontSize, cAppear, cHorzAlign, ;
      nSpace, lSpExact, nFontColor, ;
      lDefault, lHeader, lPage, lDate )

   METHOD CellFormat( cCellBorder, aCellPct )

   METHOD DefNewTable( cTblHAlign, nTblFntNum, nTblFntSize, ;
      cCellAppear, cCellHAlign, nTblRows, ;
      nTblColumns, nTblRHgt, aTableCWid, cRowBorder, cCellBorder, aColPct, nCellPct, ;
      lTblNoSplit, nTblHdRows, aHeadTit, nTblHdHgt, nTblHdPct, nTblHdFont, ;
      nTblHdFSize, cHeadAppear, cHeadHAlign, nTblHdColor , nTblHdFColor, aTblCJoin )

   HIDDEN:
   DATA nFile INIT 1

ENDCLASS

METHOD New( cFileName, aFontData, aFontFam, aFontChar, nFontSize, nFontColor, nScale, aHigh ) CLASS RichText

   /* ********************************************************************
   * Description:  Initialize a new RTF object, and create an associated
   *               file, with a valid RTF header.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */
   LOCAL i
   LOCAL cTopFile := "rtf1\ansi\ansicpg1252\deff0"
   LOCAL cColors  := ::SetClrTab() // Metodo nuevo. Establece los colores que puede

   // usar el documento.
   DEFAULT ;
      cFileName TO "REPORT.RTF", ;
      aFontData TO { "Courier New" }, ;
      nFontSize TO 12, ;
      nScale    TO INCH_TO_TWIP, ;
      nFontColor TO 0

   ::cFileName := cFileName
   ::nFontSize := nFontSize
   ::nScale    := nScale
   ::nFontColor := nFontColor

   ::lTrimSpaces := .F.

   IF aFontFam == NIL
      aFontFam := Array( aFontData )
      AFill( aFontFam, "fNIL" )
   ENDIF
   IF aFontChar == NIL
      aFontChar := Array( aFontData )
      AFill( aFontChar, 0 )
   ENDIF

   IF ValType( aHigh ) == "A"
      ::aTranslate := aHigh
   ENDIF

   // If no extension specified in file name, use ".RTF"
   IF ! ( "." $ ::cFileName )
      ::cFileName += ".RTF"
   ENDIF

   // Create/open a file for writing
   ::hFile := FCreate( ::cFileName )
   ::oPrinter := NIL

   IF ::hFile >= 0
      // Generate RTF file header
      // This opens the top-most level group for the report
      // This group must be explicitly closed by the application!
      ::OpenGroup()
      ::TextCode( cTopFile )
      // Generate a font table, and write it to the header
      ::nFontNum := Len( aFontData )
      ::OpenGroup()
      ::TextCode( "fonttbl" )
      FOR i := 1 TO ::nFontNum
         ::OpenGroup()
         ::NewFont( i )
         ::NumCode( "charset", aFontChar[ i ], .F. )
         ::TextCode( aFontFam[ i ] )
         ::Write( aFontData[ i ] + ";" )
         ::CloseGroup()
      NEXT
      ::CloseGroup()
      // Use default color info, for now...
      ::OpenGroup()
      ::TextCode( cColors )
      ::CloseGroup()
      // NOTE:  At this point, we have an open group (the report itself)
      // that must be closed at the end of the report.
   ENDIF

   RETURN Self
   /* *************************  END OF New()  ************************** */

METHOD PageSetup( nLeft, nRight, nTop, nBottom, nWidth, nHeight, ;
      nTabWidth, lLandscape, lNoWidow, cVertAlign, ;
      cPgNumPos, lPgNumTop ) CLASS RichText
   /* ********************************************************************
   * Description:  Define default page setup info for file
   *               This information is placed in the "document formatting
   *               group" of the RTF file, except for vertical alignment,
   *               which, if supplied, is treated as a new section.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */

   HB_SYMBOL_UNUSED( cPgNumPos )

   DEFAULT lLandscape TO .F.
   DEFAULT lNoWidow TO .F.
   DEFAULT lPgNumTop TO .F.

   // Note -- "landscape" should not be specified here if landscape and
   // portrait orientations are to be mixed.  If "landscape' is specified,
   // the paper width and height should also be specified, and consistent
   // (i.e., with landscape/letter, width==11 and height==8.5)

   ::LogicCode( "landscape", lLandscape )
   ::NumCode( "paperw", nWidth )
   ::NumCode( "paperh", nHeight )
   ::LogicCode( "widowctrl", lNoWidow )
   ::NumCode( "margl", nLeft )
   ::NumCode( "margr", nRight )
   ::NumCode( "margt", nTop )
   ::NumCode( "margb", nBottom )
   ::NumCode( "deftab", nTabWidth )

   // Vertical alignment and page number position are "section-specific"
   // codes.  But we'll put them here anyway for now...

   IF ! Empty( cVertAlign )
      ::TextCode( "vertal" + Lower( Left( cVertAlign, 1 ) ) )
   ENDIF

   // Set the initial font size
   ::SetFontSize( ::nFontSize )
   // Forget page numbers for now...

   RETURN NIL
   /* *********************  END OF PageSetup()  ************************ */

METHOD Paragraph( cText, nFontNumber, nFontSize, cAppear, ;
      cHorzAlign, aTabPos, nIndent, nFIndent, nRIndent, nSpace, ;
      lSpExact, nBefore, nAfter, lNoWidow, lBreak, ;
      lBullet, cBulletChar, lHang, lDefault, lNoPar, ;
      nFontColor, cTypeBorder, cBordStyle, nBordCol, nShdPct, cShadPat, ;
      nStyle, lChar ) CLASS RichText
   /* ********************************************************************
   * Description:  Write a new, formatted paragraph to the output file.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/12/97   TRM         Creation
   ******************************************************************** */
   LOCAL i

   DEFAULT ;
      lDefault TO .F., ;
      lNoWidow TO .F., ;
      lBreak TO .F., ;
      lBullet TO .F., ;
      lHang TO .F., ;
      cAppear TO "", ;
      cHorzAlign TO "", ;
      cBulletChar TO "\bullet", ;
      lNoPar TO .F., ;
      nFontColor TO 0, ;
      cTypeBorder TO NIL, ;
      cBordStyle TO "SINGLE", ;
      nBordCol TO 0, ;
      nShdPct TO 0, ;
      cShadPat TO "", ;
      lChar TO .F., ;
      nStyle TO 0

   nShdPct := IIf( nShdPct < 1, nShdPct * 10000, nShdPct * 100 )

   ::LogicCode( "pagebb", lBreak )

   IF ! lNoPar
      ::TextCode( "par" )
   ENDIF

   ::LogicCode( "pard", lDefault )

   IF ! lChar
      ::ParaStyle( nStyle )
   ENDIF

   ::NewFont( nFontNumber )
   ::SetFontSize( nFontSize )
   ::SetFontColor( nFontColor )
   ::Appearance( cAppear )
   ::HAlignment( cHorzAlign )

   IF ValType( aTabPos ) == "A"
      AEval( aTabPos, { | x | ::NumCode( "tx", x ) } )
   ENDIF

   ::NumCode( "li", nIndent )
   ::NumCode( "fi", nFIndent )
   ::NumCode( "ri", nRIndent )
   ::LineSpacing( nSpace, lSpExact )

   ::NumCode( "sb", nBefore )
   ::NumCode( "sa", nAfter )
   ::LogicCode( "keep", lNoWidow )

   IF cTypeBorder # NIL // Hay bordes de parrafo
      IF AScan( cTypeBorder, "ALL" ) # 0
         ::ParaBorder( "ALL", cBordStyle )
      ELSEIF AScan( cTypeBorder, "CHARACTER" ) # 0
         ::ParaBorder( "CHARACTER", cBordStyle )
      ELSE
         FOR i = 1 TO Len( cTypeBorder )
            ::ParaBorder( cTypeBorder[ i ], cBordStyle )
         NEXT i
      ENDIF
   ENDIF

   IF lBullet
      ::OpenGroup()
      ::TextCode( "*" )
      ::TextCode( "pnlvlblt" )
      ::LogicCode( "pnhang", lHang )
      ::TextCode( "pntxtb " + cBulletChar )
      ::CloseGroup()
   ENDIF

   IF nShdPct > 0
      ::NumCode( IIf( ! lChar, "shading", "chshdng" ), nShdPct, .F. )
      IF ! Empty( cShadPat )
         ::TextCode( "bg" + ::ShadeCode( cShadPat ) )
      ENDIF
   ENDIF

   ::Write( cText )

   IF lChar
      IF cTypeBorder # NIL
         ::TextCode( "chrbdr" )
      ENDIF
      IF nShdPct > 0
         ::NumCode( "chshdng", 0 )
      ENDIF
      ::CharStyle( nStyle )
   ENDIF

   RETURN NIL
   /* *********************  END OF Paragraph()  ************************ */

METHOD SetFontSize( nFontSize ) CLASS RichText

   /* ********************************************************************
   * Description:    Size in points -- must double value because
   *                 RTF font sizes are expressed in half-points
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */

   IF ValType( nFontSize ) == "N"
      ::nFontSize := nFontSize
      ::NumCode( "fs", ::nFontSize * 2, .F. )
   ENDIF

   RETURN NIL
   /* *********************  END OF SetFontSize()  ********************** */

METHOD SetFontColor( nFontColor ) CLASS RichText

   /* ********************************************************************
   * Description:    Size in points -- must double value because
   *                 RTF font sizes are expressed in half-points
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */

   IF ValType( nFontColor ) == "N"
      ::nFontColor := nFontColor
      ::NumCode( "cf", ::nFontColor, .F. )
   ENDIF

   RETURN NIL
   /* *********************  END OF SetFontColor()  ********************** */

METHOD Write( xData, lCodesOK ) CLASS RichText

   /* ********************************************************************
   * Description:  Write data to output file, accounting for any characters
   *               above ASCII 127 (RTF only deals with 7-bit characters
   *               directly) -- 8-bit characters must be handled as hex data.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */
   LOCAL cWrite := ""
   LOCAL i, cChar, nChar
   LOCAL cString := cStr( xData ) //cValToChar( xData )
   LOCAL aCodes := { "\", "{", "}" }

   DEFAULT lCodesOK TO .F.

   IF ::lTrimSpaces
      cString := RTrim( cString )
   ENDIF

   // cString := " " + cString

   FOR i := 1 TO Len( cString )
      cChar := SubStr( cString, i, 1 )
      nChar := Asc( cChar )
      IF nChar < 128
         IF nChar > 91
            // Process special RTF symbols
            IF ! lCodesOK
               IF AScan( aCodes, cChar ) > 0
                  cChar := "\" + cChar
               ENDIF
            ENDIF
         ELSEIF nChar < 33
            IF nChar == 13 // Turn carriage returns into new paragraphs
               cChar := "\par "
            ELSEIF nChar == 10 // Ignore line feeds
               LOOP
            ENDIF
         ENDIF
         cWrite += cChar
      ELSE
         // We have a high-order character, which is a no-no in RTF.
         // If no international translation table for high-order characters
         // is specified, write data verbatim in hex format.  If a
         // translation table is specified, look up the appropriate
         // hex value to write.
         IF Empty( ::aTranslate )
            // Ignore soft line breaks
            IF nChar == 141
               LOOP
            ELSE
               cWrite += "\plain\f" + AllTrim( Str( ::nFontAct - 1 ) ) + ;
                  "\fs" + AllTrim( Str( ::nFontSize * 2 ) ) + ;
                  "\cf" + AllTrim( Str( ::nFontColor ) ) + AllTrim( ::cLastApar ) + "\'" + Lower( NewBase( nChar, 16 ) )
            ENDIF
         ELSE
            cWrite += ::aTranslate[ Asc( cChar ) - 127 ]
         ENDIF
      ENDIF
   NEXT

   ::OpenGroup()
   FWrite( ::hFile, cWrite )
   ::CloseGroup()

   RETURN NIL
   /* ************************  END OF Write()  ************************* */

METHOD NumCode( cCode, nValue, lScale ) CLASS RichText

   /* ********************************************************************
   * Description:  Write an RTF code with a numeric parameter
   *               to the output file,
   *               NOTE: Most RTF numeric measurements must be specified
   *               in "Twips" (1/20th of a point, 1/1440 of an inch).
   *               However, the interface layer of the RichText class
   *               defaults to accept inches.  Therefore, all such
   *               measurements must be converted to Twips.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/12/97   TRM         Creation
   ******************************************************************** */
   LOCAL cWrite := ""

   IF ValType( cCode ) == "C" .AND. ValType( nValue ) == "N"
      cCode := FormatCode( cCode )
      cWrite += cCode
      DEFAULT lScale TO .T.
      IF lScale
         nValue := Int( nValue * ::nScale )
      ENDIF
      cWrite += AllTrim( Str( nValue ) ) //+ " "
      FWrite( ::hFile, cWrite )
   ENDIF

   RETURN cWrite
   /* **********************  END OF NumCode()  ************************ */

METHOD LogicCode( cCode, lTest ) CLASS RichText

   /* ********************************************************************
   * Description:  Write an RTF code if the supplied value is true
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/12/97   TRM         Creation
   ******************************************************************** */
   LOCAL cWrite := ""

   IF ValType( cCode ) == "C" .AND. ValType( lTest ) == "L"
      IF lTest
         cWrite := ::TextCode( cCode )
      ENDIF
   ENDIF

   RETURN cWrite
   /* **********************  END OF LogicCode()  ************************ */

FUNCTION FormatCode( cCode )

   /* ********************************************************************
   * Description:  Remove extraneous spaces from a code, and make sure
   *               that it has a leading backslash ("\").
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/12/97   TRM         Creation
   ******************************************************************** */

   cCode := AllTrim( cCode )
   IF ! ( Left( cCode, 1 ) == "\" )
      cCode := "\" + cCode
   ENDIF

   RETURN cCode
   /* **********************  END OF FormatCode()  ********************** */

METHOD DefineTable( cTblHAlign, nTblFntNum, nTblFntSize, ;
      cCellAppear, cCellHAlign, nTblRows, ;
      nTblColumns, nTblRHgt, aTableCWid, cRowBorder, cCellBorder, aColPct, nCellPct, ;
      lTblNoSplit, nTblHdRows, nTblHdHgt, nTblHdPct, nTblHdFont, ;
      nTblHdFSize, cHeadAppear, cHeadHAlign, nTblHdColor , nTblHdFColor ) CLASS RichText
   /* ********************************************************************
   * Description:  Define the default setup for a table.
   *               This simply saves the parameters to the object's
   *               internal instance variables.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/18/97   TRM         Creation
   ******************************************************************** */
   LOCAL i

   DEFAULT ;
      cTblHAlign TO "CENTER", ;
      nTblFntNum TO 1, ;
      nTblFntSize TO ::nFontSize, ;
      nTblRows TO 1, ;
      nTblColumns TO 1, ;
      nTblRHgt TO NIL, ;
      aTableCWid  TO  Array( nTblColumns ), ; // see below
   cRowBorder  TO  "NONE", ;
      cCellBorder  TO  "SINGLE", ;
      lTblNoSplit  TO  .F., ;
      nCellPct  TO  0, ;
      nTblHdRows  TO  0, ;
      nTblHdHgt  TO  nTblRHgt, ;
      nTblHdPct  TO  0, ;
      nTblHdFont  TO  nTblFntNum, ;
      nTblHdFSize  TO  ::nFontSize + 2, ;
      nTblHdColor   TO  0, ;
      nTblHdFColor  TO  0

   IF aTableCWid[ 1 ] == NIL
      AFill( aTableCWid, 6.5 / nTblColumns )
   ELSEIF ValType( aTableCWid[ 1 ] ) == "A"
      aTableCWid := AClone( aTableCWid[ 1 ] )
   ENDIF

   // Turn independent column widths into "right boundary" info...
   FOR i := 2 TO Len( aTableCWid )
      aTableCWid[ i ] += aTableCWid[ i - 1 ]
   NEXT

   IF aColPct == NIL
      aColPct   := Array( nTblColumns )
      AFill( aColPct, 0 )
   ENDIF

   ::cTblHAlign := Lower( Left( cTblHAlign, 1 ) )
   ::nTblFntNum := nTblFntNum
   ::nTblFntSize := nTblFntSize
   ::cCellAppear := cCellAppear
   ::cCellHAlign := cCellHAlign
   ::nTblRows := nTblRows
   ::nTblColumns := nTblColumns
   ::nTblRHgt := nTblRHgt
   ::aTableCWid := aTableCWid
   ::cRowBorder := ::BorderCode( cRowBorder )
   ::cCellBorder := ::BorderCode( cCellBorder )
   ::aColPct := AClone( aColPct )
   ::nCellPct := IIf( nCellPct < 1, nCellPct * 10000, nCellPct * 100 )
   // Porcentajes para cada celda
   i := 1
   AEval( ::aColPct, { || ::aColPct[ i ] := IIf( ::aColPct[ i ] < 1, ::aColPct[ i ] * 10000, ;
      ::aColPct[ i ] * 100 ), i ++ } )
   ::lTblNoSplit := lTblNoSplit
   ::nTblHdRows := nTblHdRows
   ::nTblHdHgt := nTblHdHgt
   ::nTblHdPct := IIf( nTblHdPct < 1, nTblHdPct * 10000, nTblHdPct * 100 )
   ::nTblHdFont := nTblHdFont
   ::nTblHdFSize := nTblHdFSize
   ::nTblHdColor := nTblHdColor
   ::nTblHdFColor := nTblHdFColor
   ::cHeadAppear := cHeadAppear
   ::cHeadHAlign := cHeadHAlign
   ::nCurrColumn := 0
   ::nCurrRow    := 0

   RETURN NIL
   /* *********************  END OF DefineTable()  ********************** */

METHOD WriteCell( cText, nFontNumber, nFontSize, cAppear, cHorzAlign, ;
      nSpace, lSpExact, cCellBorder, nCellPct, nFontColor, lDefault ) CLASS RichText
   /* ********************************************************************
   * Description:  Write a formatted cell of data to the current row
   *               of the current table.  Also takes care of the logic
   *               required for headers & header formatting.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */
   LOCAL i

   HB_SYMBOL_UNUSED( cCellBorder )
   HB_SYMBOL_UNUSED( nCellPct )

   DEFAULT cText TO "", ;
      lDefault TO .F.

   // Increment/reset the column #
   IF ::nCurrColumn == ::nTblColumns
      ::nCurrColumn := 1
   ELSE
      ::nCurrColumn += 1
   ENDIF

   // Apply any one-time formatting for header/body

   IF ::nCurrColumn == 1
      IF ::nCurrRow == 0 .AND. ::nTblHdRows > 0
         // Start a separate group for the header rows
         ::OpenGroup()
         ::BeginRow()
         // We need to apply header formats
         // The "\trgaph108" & "trleft-108" are the defaults used by MS-Word,
         // so if it's good enough for Word, it's good enough for me...
         ::TextCode( "trgaph108\trleft-108" )
         ::TextCode( "trq" + ::cTblHAlign )
         ::Borders( "tr", ::cRowBorder )
         ::NumCode( "trrh", ::nTblHdHgt )
         ::TextCode( "trhdr" )
         ::LogicCode( "trkeep", ::lTblNoSplit )
         // Set the default border & width info for each header cell
         FOR i := 1 TO Len( ::aTableCWid )
            ::NumCode( "clshdng", ::nTblHdPct, .F. )
            IF ::nTblHdColor > 0
               ::NumCode( "clcbpat", ::nTblHdColor, .F. )
            ENDIF
            ::Borders( "cl", ::cCellBorder )
            ::NumCode( "cellx", ::aTableCWid[ i ] )
         NEXT
         // Identify the header-specific font
         ::NewFont( ::nTblHdFont )
         ::SetFontSize( ::nTblHdFSize )
         IF ::nTblHdFColor > 0
            ::SetFontColor( ::nTblHdFColor )
         ENDIF
         ::Appearance( ::cHeadAppear )
         ::HAlignment( ::cHeadHAlign )
         ::TextCode( "intbl" )
      ELSEIF ::nCurrRow == ::nTblHdRows
         // The header rows are over,
         // so we need to apply formats to the body of the table.
         // First close the header section, if one exists
         IF ::nTblHdRows > 0
            ::EndRow()
            ::CloseGroup()
         ENDIF
         ::BeginRow()
         ::TextCode( "trgaph108\trleft-108" )
         ::TextCode( "trq" + ::cTblHAlign )
         ::Borders( "tr", ::cRowBorder )
         ::NumCode( "trrh", ::nTblRHgt )
         ::LogicCode( "trkeep", ::lTblNoSplit )
         // Set the default shading, border & width info for each body cell
         FOR i := 1 TO Len( ::aTableCWid )
            ::NumCode( "clshdng", ::aColPct[ i ], .F. )
            ::Borders( "cl", ::cCellBorder )
            ::NumCode( "cellx", ::aTableCWid[ i ] )
         NEXT
         // Write the body formatting codes
         ::NewFont( ::nTblFntNum )
         ::SetFontSize( ::nTblFntSize )
         // * ::SetFontColor( nFontColor )
         ::Appearance( ::cCellAppear )
         ::HAlignment( ::cCellHAlign )
         ::TextCode( "intbl" )
      ELSE
         // End of a row of the table body.
         ::EndRow()
         // Prepare the next row for inclusion in table
         ::TextCode( "intbl" )
      ENDIF
   ENDIF
   // Apply any cell-specific formatting, and write the text
   ::OpenGroup()
   ::LogicCode( "pard", lDefault )
   ::NewFont( nFontNumber )
   ::SetFontSize( nFontSize )
   ::SetFontColor( nFontColor )
   ::Appearance( cAppear )
   ::HAlignment( cHorzAlign )
   ::LineSpacing( nSpace, lSpExact )
   // Now write the text
   ::Write( cText )
   ::CloseGroup()
   // Close the cell
   ::TextCode( "cell" )

   RETURN NIL
   /* **********************  END OF WriteCell()  *********************** */

METHOD NewSection( lLandscape, nColumns, nLeft, nRight, nTop, nBottom, ;
      nWidth, nHeight, cVertAlign, lDefault ) CLASS RichText
   /* ********************************************************************
   * Description:  Open a new section, with optional new formatting
   *               properties.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/26/97   TRM         Creation
   ******************************************************************** */

   DEFAULT lDefault TO .F.

   //::OpenGroup()
   ::TextCode( "sect" )
   IF lDefault
      ::TextCode( "sectd" )
   ENDIF
   ::LogicCode( "lndscpsxn", lLandscape )
   ::NumCode( "cols", nColumns, .F. )
   ::NumCode( "marglsxn", nLeft )
   ::NumCode( "margrsxn", nRight )
   ::NumCode( "margtsxn", nTop )
   ::NumCode( "margbsxn", nBottom )
   ::NumCode( "pgwsxn", nWidth )
   ::NumCode( "pghsxn", nHeight )

   IF ! Empty( cVertAlign )
      ::TextCode( "vertal" + Lower( Left( cVertAlign, 1 ) ) )
   ENDIF

   // Formato de numero de pagina
   ::TextCode( "sbkpage" )
   ::TextCode( "pgncont" )
   ::TextCode( "pgndec" )

   RETURN NIL
   /* **********************  END OF NewSection()  ********************* */

METHOD NewFont( nFontNumber ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the current font.
   *               Converts app-level font number into RTF font number.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */

   IF ! Empty( nFontNumber ) .AND. nFontNumber <= ::nFontNum
      ::NumCode( "f", nFontNumber - 1, .F. )
      ::nFontAct := nFontNumber
   ENDIF

   RETURN NIL
   /* ***********************  END OF NewFont()  ************************ */

METHOD Appearance( cAppear ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the "appearance" (bold, italic, etc.)
   *               Appearance codes are concatenable at the app-level
   *               and already contain backslashes.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */
   LOCAL cWrite := ""

   // Special case (see .CH file) -- first remove leading slash ...ugh.
   IF ! Empty( cAppear )
      cWrite := ::TextCode( SubStr( cAppear, 2 ) )
      ::cLastApar := cAppear
   ENDIF

   RETURN cWrite
   /* **********************  END OF Appearance()  ********************** */

METHOD HAlignment( cAlign ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the horizontal alignment
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */

   IF ! Empty( cAlign )
      ::TextCode( "q" + Lower( Left( cAlign, 1 ) ) )
   ENDIF

   RETURN NIL
   /* *********************  END OF HAlignment()  *********************** */

METHOD LineSpacing( nSpace, lSpExact ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the line spacing (spacing can either be "exact"
   *               or "multiple" (of single spacing).  If exact, the units
   *               of the supplied value must be converted to twips.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */

   DEFAULT lSpExact TO .F.

   ::NumCode( "sl", nSpace, lSpExact )
   IF ! Empty( nSpace )
      ::NumCode( "slmult", IIf( lSpExact, 0, 1 ), .F. )
   ENDIF

   RETURN NIL
   /* *********************  END OF LineSpacing()  ********************** */

METHOD Borders( cEntity, cBorder ) CLASS RichText

   * Description:  Apply borders to rows or cells.  Currently limited to
   *               one type of border per rectangle.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   LOCAL i, aBorder := { "t", "b", "l", "r" }

   IF ValType( cBorder ) == "C"
      FOR i := 1 TO 4
         ::TextCode( cEntity + "brdr" + aBorder[ i ] + "\brdr" + cBorder )
      NEXT
   ENDIF

   RETURN NIL
   /* ***********************  END OF Borders()  ************************ */

METHOD ParaBorder( cBorder, cType ) CLASS RichText

   /* ********************************************************************
   * Description:  Apply borders to paragraphs.  Currently limited to
   *               one type of border per rectangle.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */
   LOCAL codigo

   cBorder := Upper( AllTrim( cBorder ) )
   DO CASE
   CASE cBorder == "CHARACTER"
      codigo := "chbrdr"
   CASE cBorder == "ALL"
      codigo := "box"
   CASE cBorder == "TOP"
      codigo := "brdrt"
   CASE cBorder == "BOTTOM"
      codigo := "brdrb"
   CASE cBorder == "LEFT"
      codigo := "brdrl"
   CASE cBorder == "RIGHT"
      codigo := "RIGHT"
   ENDCASE

   RETURN ::TextCode( codigo + "\brdr" + ::BorderCode( cType ) )

   /* ***********************  END OF Borders()  ************************ */

METHOD BorderCode( cBorderID ) CLASS RichText

   /* ********************************************************************
   * Description:  Convert an application-level border ID into
   *               a valid RTF border code.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/19/97   TRM         Creation
   ******************************************************************** */
   LOCAL cBorderCode := "", n
   LOCAL aBorder := ;
      { ;
      { "NONE",        NIL   }, ;
      { "SINGLE",      "s"   }, ;
      { "DOUBLETHICK", "th"  }, ;
      { "SHADOW",      "sh"  }, ;
      { "DOUBLE",      "db"  }, ;
      { "DOTTED",      "dot" }, ;
      { "DASHED",      "dash" }, ;
      { "HAIRLINE",    "hair" }  ;
      }

   cBorderID := Upper( RTrim( cBorderID ) )
   n := AScan( aBorder, { | x | x[ 1 ] == cBorderID } )
   IF n > 0
      cBorderCode := aBorder[ n ][ 2 ]
   ENDIF

   RETURN cBorderCode
   /* ***********************  END  OF BorderCode()  ******************** */

METHOD ShadeCode( cShadeID ) CLASS RichText

   /* ********************************************************************
   * Description:  Convert an application-level border ID into
   *               a valid RTF border code.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 06/07/00   JJA         Creation
   ******************************************************************** */
   LOCAL cShadeCode := "", n
   LOCAL aShade := ;
      { ;
      { "NONE",         ""        }, ;
      { "HORIZ",        "horiz"   }, ;
      { "VERT",         "vert"    }, ;
      { "CROSS",        "cross"   }, ;
      { "FORDIAG",      "fdiag"   }, ;
      { "BACKDIAG",     "bdiag"      } ;
      }

   cShadeID := Upper( RTrim( cShadeID ) )
   n := AScan( aShade, { | x | x[ 1 ] == cShadeID } )
   IF n > 0
      cShadeCode := aShade[ n ][ 2 ]
   ENDIF

   RETURN cShadeCode
   /* ***********************  END  OF BorderCode()  ******************** */

FUNCTION IntlTranslate()

   /* ********************************************************************
   * Description:  Example of an array that could be used to map
   *               high-order characters.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/06/97   TRM         Creation
   ******************************************************************** */
   LOCAL i
   LOCAL aTranslate[ 128 ]
   LOCAL aHighTable := ;
      { ;
      "\'fc", "\'e9", "\'e2", "\'e4", "\'e0", "\'e5", "\'e7", "\'ea", ;
      "\'eb", "\'e8", "\'ef", "\'ee", "\'ec", "\'c4", "\'c5", "\'c9", ;
      "\'e6", "\'c6", "\'f4", "\'f6", "\'f2", "\'fb", "\'f9", "\'ff", ;
      "\'d6", "\'dc", "\'a2", "\'a3", "\'a5", "\'83", "\'ed", "\'e1", ;
      "\'f3", "\'fa", "\'f1", "\'d1", "\'aa", "\'ba", "\'bf" ;
      }

   AFill( aTranslate, "" )
   FOR i := 1 TO Len( aHighTable )
      aTranslate[ i ] := aHighTable[ i ]
   NEXT

   RETURN aTranslate
   /* *********************  END OF IntlTranslate()  ******************** */

FUNCTION NewBase( nDec, nBase )

   /* ********************************************************************
   * Description:  Convert a decimal numeric to a string in another
   *               base system
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/12/97   TRM         Creation
   ******************************************************************** */
   LOCAL cNewBase := "", nDividend, nRemain, lContinue := .T., cRemain

   DO WHILE lContinue
      nDividend := Int( nDec / nBase )
      nRemain := nDec % nBase
      IF nDividend >= 1
         nDec := nDividend
      ELSE
         lContinue := .F.
      ENDIF
      IF nRemain < 10
         cRemain := AllTrim( Str( nRemain, 2, 0 ) )
      ELSE
         cRemain := Chr( nRemain + 55 )
      ENDIF
      cNewBase := cRemain + cNewBase
   ENDDO

   RETURN cNewBase
   /* ***********************  END OF NewBase()  ************************ */

METHOD BegBookMark( texto )  CLASS RichText

   DEFAULT texto TO "marca"

   ::cLastBook := StrTran( texto, " ", "_" )
   // Iniciar grupo
   ::OpenGroup()
   ::TextCode( "*\bkmkstart " + Lower( ::cLastBook ) )
   ::CloseGroup()

   RETURN NIL

METHOD EndBookMark()  CLASS RichText

   ::OpenGroup()
   ::TextCode( "*\bkmkend " + Lower( ::cLastBook ) )
   ::CloseGroup()

   RETURN NIL

METHOD Linea( aInicio, aFinal, nxoffset, nyoffset, ASize, cTipo, ;
      aColores, nWidth, nPatron, lSombra, aSombra ) CLASS RichText

   DEFAULT cTipo TO "SOLIDA", ;
      nxoffset TO 0, ;
      nyoffset TO 0, ;
      nWidth TO  0.01, ;
      aColores TO { 0, 0, 0 }, ;
      ASize TO { 2.0, 0 }, ;
      nPatron TO 1, ;
      lSombra TO .F., ;
      aSombra TO { 0, 0 }

   ::OpenGroup()
   ::TextCode( "do\dobxmargin\dobypara\dpline" )
   ::NumCode( "dpptx", aInicio[ 1 ], .T. )
   ::NumCode( "dppty", aInicio[ 2 ], .T. )
   ::NumCode( "dpptx", aFinal[ 1 ], .T. )
   ::NumCode( "dppty", aFinal[ 2 ], .T. )
   ::NumCode( "dpx", nxoffset, .T. )
   ::NumCode( "dpy", nyoffset, .T. )
   ::NumCode( "dpxsize", ASize[ 1 ], .T. )
   ::NumCode( "dpysize", ASize[ 2 ], .T. )
   DO CASE
   CASE cTipo == "SOLIDA"
      ::TextCode( "dplinesolid" )
   CASE cTipo == "PUNTOS"
      ::TextCode( "dplinedot" )
   CASE cTipo == "LINEAS"
      ::TextCode( "dplinedash" )
   CASE cTipo == "PUNTOLINEA"
      ::TextCode( "dplinedado" )
   ENDCASE
   // Colores
   ::NumCode( "dplinecob", aColores[ 1 ], .F. )
   ::NumCode( "dplinecog", aColores[ 2 ], .F. )
   ::NumCode( "dplinecor", aColores[ 3 ], .F. )
   // Ancho de la linea
   ::NumCode( "dplinew", nWidth, .T. )
   // Patron
   ::NumCode( "dpfillpat", nPatron, .F. )
   // Linea con sombra
   ::LogicCode( "dpshadow", lSombra )
   IF lSombra
      ::NumCode( "dpshadx", aSombra[ 1 ], .T. )
      ::NumCode( "dpshady", aSombra[ 2 ], .T. )
   ENDIF
   ::CloseGroup()

   RETURN NIL

METHOD SetClrTab() CLASS RichText

   LOCAL colors

   colors := "colortbl;\red0\green0\blue0;\red0\green0\blue128;\red0\green128\blue0;"
   colors += "\red0\green128\blue128;\red128\green0\blue0;\red128\green0\blue128;\red128\green128\blue0;"
   colors += "\red192\green192\blue192;\red128\green128\blue128;\red0\green0\blue255;"
   colors += "\red0\green255\blue0;\red0\green255\blue255;\red255\green0\blue0;"
   colors += "\red255\green0\blue255;\red255\green255\blue0;\red255\green255\blue255;"

   RETURN colors

METHOD SetStlDef() CLASS Richtext

   ::IncStyle( "Normal" )
   ::IncStyle( "Default Paragraph Font", "CHARACTER" )

   RETURN NIL

METHOD InfoDoc( cTitle, cSubject, cAuthor, cManager, cCompany, cOperator, ;
      cCategor, cKeyWords, cComment ) CLASS RichText

   DEFAULT cTitle TO "Informe", ;
      cSubject TO "", ;
      cAuthor TO "", ;
      cManager TO "", ;
      cCompany TO "", ;
      cOperator TO "", ;
      cCategor TO "", ;
      cKeyWords TO "", ;
      cComment TO ""

   ::OpenGroup()
   ::TextCode( "info" )
   ::OpenGroup()
   ::TextCode( "title " + cTitle )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "subject " + cSubject )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "author " + cAuthor )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "manager " + cManager )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "company " + cCompany )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "operator " + cOperator )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "category " + cCategor )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "keywords " + cKeyWords )
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "comment " + cComment )
   ::CloseGroup()
   ::CloseGroup()

   RETURN NIL

METHOD FootNote( cTexto, cChar, nFontNumber, ;
      nFontSize, cAppear, nFontColor, lEnd, lAuto, lUpper ) CLASS RichText

   DEFAULT cTexto TO "", ;
      cChar TO "*", ;
      nFontNumber TO 0, ;
      nFontSize TO 8, ;
      cAppear TO "", ;
      nFontColor TO 0, ;
      lUpper TO .T., ;
      lAuto TO .F., ;
      lEnd TO .F.

   cChar := IIf( lAuto, "", cChar )
   ::OpenGroup()
   ::OpenGroup()
   IF lUpper
      ::TextCode( "super " + cChar )
   ELSE
      IF ! Empty( cChar )
         ::Write( cChar )
      ENDIF
   ENDIF

   IF lAuto ; ::TextCode( "chftn" ) ; ENDIF
   ::CloseGroup()
   ::OpenGroup()
   ::TextCode( "footnote" )
   IF lEnd ; ::TextCode( "ftnalt" ) ; ENDIF
   ::NewFont( nFontNumber )
   ::SetFontSize( nFontSize )
   ::SetFontColor( nFontColor )
   ::Appearance( cAppear )
   ::OpenGroup()
   IF lUpper
      ::TextCode( "super " + cChar )
   ELSE
      IF ! Empty( cChar )
         ::Write( cChar )
      ENDIF
   ENDIF

   IF lAuto ; ::TextCode( "chftn" ) ; ENDIF
   ::CloseGroup()
   ::Write( cTexto )
   ::CloseGroup()
   ::CloseGroup()

   RETURN NIL

METHOD BegTextBox( cTexto, aOffset, ASize, cTipo, aColores, nWidth, nPatron, ;
      lSombra, aSombra, nFontNumber, nFontSize, cAppear, nFontColor, nIndent, lRounded, lEnd ) CLASS RichText

   DEFAULT cTexto TO "", ;
      aOffset TO { 0, 0 }, ;
      ASize TO { 2.0, 1.0 }, ;
      cTipo TO "SOLIDA", ;
      aColores TO { 0, 0, 0 }, ;
      nWidth TO 20, ;
      nPatron TO 1, ;
      lEnd TO .F., ;
      lRounded TO .F., ;
      lSombra TO .F., ;
      aSombra TO { 0, 0 }

   ::aOfftBox := aOffset
   ::aSztBox := ASize
   ::aCltBox := aColores
   ::cTpltBox := cTipo
   ::nWltBox := nWidth
   ::nFPtbox := nPatron
   ::OpenGroup()
   ::TextCode( "do\dobxmargin\dobypara\dptxbx\dptxbxmar40" )
   ::logicCode( "dproundr", lRounded )
   ::LogicCode( "dpshadow", lSombra )
   IF lSombra
      ::NumCode( "dpshadx", aSombra[ 1 ], .T. )
      ::NumCode( "dpshadx", aSombra[ 2 ], .T. )
   ENDIF
   ::OpenGroup()
   ::TextCode( "dptxbxtext \s0\ql" )
   IF ! Empty( cTexto )
      ::Paragraph( cTexto, nFontNumber, nFontSize, cAppear, ;
         ,, nIndent,,,,,,,,,,,, .F., .T. , nFontColor )
   ENDIF
   IF lEnd
      ::EndTextBox()
   ENDIF

   RETURN NIL

METHOD EndTextBox() CLASS RichText

   ::CloseGroup() // Cierra el grupo de texto
   ::NumCode( "dpx", ::aOfftbox[ 1 ], .T. )
   ::NumCode( "dpy", ::aOfftbox[ 2 ], .T. )
   ::NumCode( "dpxsize", ::aSztBox[ 1 ], .T. )
   ::NumCode( "dpysize", ::aSztBox[ 2 ], .T. )
   DO CASE
   CASE ::cTpltBox == "SOLIDA"
      ::TextCode( "dplinesolid" )
   CASE ::cTpltBox == "PUNTOS"
      ::TextCode( "dplinedot" )
   CASE ::cTpltBox == "LINEAS"
      ::TextCode( "dplinedash" )
   CASE ::cTpltBox == "PUNTOLINEA"
      ::TextCode( "dplinedado" )
   ENDCASE
   // Colores
   ::NumCode( "dplinecob", ::aCltBox[ 1 ], .F. )
   ::NumCode( "dplinecog", ::aCltBox[ 2 ], .F. )
   ::NumCode( "dplinecor", ::aCltBox[ 3 ], .F. )
   // Ancho de la linea
   ::NumCode( "dplinew", ::nWltBox, .F. )
   ::TextCode( "\dpfillbgcr255\dpfillbgcg255\dpfillbgcb255" )
   // Patron
   ::NumCode( "dpfillpat", ::nFPtbox, .F. )
   ::CloseGroup()

   RETURN NIL

METHOD SetFrame( ASize, cHorzAlign, cVertAlign, lNoWrap, ;
      cXAlign, xpos, cYAlign, ypos ) CLASS RichText
   LOCAL ancho

   IF Empty( ASize )

      RETURN NIL
   ENDIF
   ancho := Round( ( 1.25 * ASize[ 1 ] * ::nScale ) + 0.5, 0 )
   ::TextCode( "absh0" )
   ::NumCode( "absw", ancho, .F. )
   IF cXAlign == "MARGIN"
      ::TextCode( "phmrg" )
   ELSE
      ::TextCode( "phpg" )
   ENDIF
   IF xpos == NIL
      DO CASE
      CASE cHorzAlign == "LEFT"
         ::TextCode( "posxl" )
      CASE cHorzAlign == "RIGHT"
         ::TextCode( "posxr" )
      CASE cHorzAlign == "CENTER"
         ::TextCode( "posxc" )
      ENDCASE
   ELSE
      ::NumCode( "posx", xpos, .T. )
   ENDIF
   IF cYAlign == "MARGIN"
      ::TextCode( "pvmrg" )
   ELSEIF cYAlign == "PARRAFO"
      ::TextCode( "pvpara" )
   ELSE
      ::TextCode( "pvpg" )
   ENDIF
   IF ypos == NIL
      DO CASE
      CASE cVertAlign == "TOP"
         ::TextCode( "posyt" )
      CASE cVertAlign == "BOTTOM"
         ::TextCode( "posyb" )
      CASE cVertAlign == "CENTER"
         ::TextCode( "posyc" )
      ENDCASE
   ELSE
      ::NumCode( "posy", ypos, .T. )
   ENDIF
   IF lNoWrap
      ::TextCode( "nowrap" )
   ELSE
      ::TextCode( "dxfrtext180\dfrmtxtx180\dfrmtxty0" )
   ENDIF
   ::TextCode( "par\li0\ql" )
   ::ParaBorder( "ALL", "SINGLE" )

   RETURN NIL

METHOD Image( cName, ASize, nPercent, lCell, lInclude, lFrame, aFSize, cHorzAlign, ;
      cVertAlign, lNoWrap, cXAlign, xpos, cYAlign, ypos )
   LOCAL cExt

   DEFAULT cName TO "", ;
      ASize TO { }, ;
      cHorzAlign TO "CENTER", ;
      cVertAlign TO "TOP", ;
      lFrame TO .T., ;
      lNoWrap TO .F., ;
      lCell TO .F., ;
      xpos TO NIL, ;
      cXAlign TO "MARGIN", ;
      cYAlign TO "PARRAFO", ;
      ypos TO NIL, ;
      lInclude TO .F., ;
      nPercent TO 1

   IF Empty( cName )

      RETURN NIL
   ENDIF
   IF lCell
      ::nCurrColumn += 1
      ::LogicCode( "pard", .t. )
      ::TextCode( "intbl" )
      ::OpenGroup()
   ELSE
      IF lFrame
         DEFAULT aFSize TO ASize
         ::SetFrame( aFSize, cHorzAlign, cVertAlign, lNoWrap, ;
            cXAlign, xpos, cYAlign, ypos )
      ENDIF
   ENDIF
   IF ! lInclude
      ::NumCode( "sslinkpictw", ASize[ 1 ] )
      ::NumCode( "sslinkpicth", ASize[ 2 ] )
      ::OpenGroup()
      ::TextCode( "field" )

      ::OpenGroup()
      ::TextCode( "fldinst" )

      FWrite( ::hFile, " INCLUDEPICTURE " )
      cName := StrTran( cName, "\", "\\\\" )
      FWrite( ::hFile, " " + AllTrim( cName ) + " \\*MERGEFORMAT " )
      ::CloseGroup()
      ::OpenGroup()
      ::TextCode( "fldrslt" )
      ::CloseGroup()
      ::CloseGroup()
   ELSE
      cExt := Upper( cFileExt( cName ) )
      DO CASE
      CASE cExt == "BMP"
         ::Bmp2Wmf( cName, ASize, nPercent )
      CASE cExt == "WMF"
         ::Wmf2Rtf( cName, ASize, nPercent )
      OTHERWISE
         ::RtfJpg( cName, ASize, nPercent )
      ENDCASE
   ENDIF
   IF lCell
      ::CloseGroup()
      ::TextCode( "cell" )
      IF ::nCurrColumn == ::nTblColumns // Ha terminado una columna
         ::TextCode( "intbl\row" )
         ::nCurrColumn := 0
      ENDIF
   ELSE
      ::TextCode( "par\pard" )
   ENDIF

   RETURN NIL

METHOD IncStyle( cName, styletype, nFontNumber, nFontSize, ;
      nFontColor, cAppear, cHorzAlign, nIndent, cKeys, ;
      cTypeBorder, cBordStyle, nBordColor, nShdPct, cShadPat, lAdd, LUpdate ) CLASS RichText
   LOCAL lParrafo := .F., lChar := .F., i
   LOCAL cEstilo := ""

   DEFAULT cName TO "", ;
      styletype TO "PARAGRAPH", ;
      nFontNumber TO 1, ;
      nFontSize   TO ::nFontSize, ;
      nFontColor  TO ::nFontColor, ;
      cAppear  TO "", ;
      cHorzAlign TO "LEFT", ;
      nIndent TO 0, ;
      cKeys TO "", ;
      cTypeBorder TO NIL, ;
      cBordStyle TO "SINGLE", ;
      nBordColor TO 0, ;
      nShdPct TO 0, ;
      cShadPat TO "", ;
      lAdd TO .F., ;
      LUpdate TO .F.
   nShdPct := IIf( nShdPct < 1, nShdPct * 10000, nShdPct * 100 )
   ::OpenGroup()
   DO CASE
   CASE styletype == "PARAGRAPH"
      ::NumCode( "s", ::NStlDef, .F. )
      lParrafo := .T.
   CASE styletype == "CHARACTER"
      ::NumCode( "*\cs", ::nCharStl, .F. )
      lChar := .T.
   CASE styletype == "SECTION"
      ::NumCode( "ds", ::nStlSec, .F. )
   ENDCASE
   IF ! Empty( cKeys )
      ::OpenGroup()
      ::TextCode( "keycode " + cKeys )
      ::CloseGroup()
   ENDIF
   IF lParrafo
      IF cTypeBorder # NIL // Hay bordes de parrafo
         IF AScan( cTypeBorder, "ALL" ) # 0
            cEstilo += ::ParaBorder( "ALL", cBordStyle )
         ELSE
            FOR i := 1 TO Len( cTypeBorder )
               cEstilo += ::ParaBorder( cTypeBorder[ i ], cBordStyle )
            NEXT i
         ENDIF
      ENDIF
      cEstilo += ::NumCode( "\li", nIndent )
   ENDIF
   cEstilo += ::NumCode( "f", nFontNumber - 1, .F. )
   cEstilo += ::NumCode( "fs", nFontSize * 2, .F. )
   cEstilo += ::NumCode( "cf", nFontColor, .F. )
   cEstilo += ::Appearance( cAppear )
   IF lChar
      cEstilo += ::LogicCode( "\additive", lAdd )
      AAdd( ::CharStyles, cEstilo )
      ::nCharStl += 1

   ENDIF
   cEstilo += ::LogicCode( "\sautoupd", LUpdate )
   IF lParrafo
      IF nShdPct > 0
         cEstilo += ::NumCode( "shading", nShdPct, .F. )
         IF ! Empty( cShadPat )
            cEstilo += ::TextCode( "bg" + ::ShadeCode( cShadPat ) )
         ENDIF
      ENDIF
      AAdd( ::ParStyles, cEstilo )
      ::NStlDef += 1
   ENDIF
   FWrite( ::hFile, " " + cName + ";" )
   ::CloseGroup()

   RETURN NIL

METHOD BeginStly() CLASS RichText

   ::OpenGroup()
   ::TextCode( "stylesheet" )
   ::SetStlDef()

   RETURN NIL

METHOD WriteStly() CLASS RichText

   ::CloseGroup()

   RETURN NIL

METHOD ParaStyle( nStyle ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the paragraph style
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/09/99
   ******************************************************************** */

   IF nStyle == 0

      RETURN NIL
   ENDIF
   IF ::nStlAct # nStyle
      IF nStyle <= Len( ::ParStyles[ nStyle ] )
         ::Numcode( "par\pard\s", nStyle, .F. )
         FWrite( ::hFile, ::ParStyles[ nStyle ] )
         ::nStlAct := nStyle
      ENDIF
   ENDIF

   RETURN NIL

METHOD CharStyle( nStyle ) CLASS RichText

   /* ********************************************************************
   * Description:  Change the character style
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 01/09/99
   ******************************************************************** */

   IF nStyle == 0

      RETURN NIL
   ENDIF
   IF ::nCharAct # nStyle
      IF nStyle <= Len( ::CharStyles[ nStyle ] )
         ::Numcode( "\cs", nStyle, .F. )
         FWrite( ::hFile, ::CharStyles[ nStyle ] )
         ::nCharAct := nStyle
      ENDIF
   ENDIF

   RETURN NIL
   /* *********************  END OF HAlignment()  *********************** */

METHOD TextCode( cCode ) CLASS RichText

   LOCAL codigo

   codigo :=  FormatCode( cCode )
   FWrite( ::hFile, codigo )

   RETURN codigo

METHOD DefNewTable( cTblHAlign, nTblFntNum, nTblFntSize, ;
      cCellAppear, cCellHAlign, nTblRows, ;
      nTblColumns, nTblRHgt, aTableCWid, cRowBorder, cCellBorder, aColPct, nCellPct, ;
      lTblNoSplit, nTblHdRows, aHeadTit, nTblHdHgt, nTblHdPct, nTblHdFont, ;
      nTblHdFSize, cHeadAppear, cHeadHAlign, nTblHdColor , nTblHdFColor, ;
      aTblCJoin ) CLASS RichText
   /* ********************************************************************
   * Description:  Define the default setup for a table.
   *               Saves the parameters to the object's
   *               internal instance variables,and define the table
   *               defaults.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 22/10/00   JIJA        Modification of Define Table.
   *                        You can introduce more than one header row
   ******************************************************************** */
   LOCAL i, j

   DEFAULT ;
      cTblHAlign  TO  "CENTER", ;
      nTblFntNum  TO  1, ;
      nTblFntSize  TO  ::nFontSize, ;
      nTblRows  TO  1, ;
      nTblColumns TO  1, ;
      nTblRHgt  TO  NIL, ;
      aTableCWid  TO  Array( nTblColumns ), ; // see below
   cRowBorder  TO  "NONE", ;
      cCellBorder  TO  "SINGLE", ;
      lTblNoSplit  TO  .F., ;
      nCellPct  TO  0, ;
      nTblHdRows  TO  0, ;
      aHeadTit TO { }, ;
      nTblHdHgt  TO  nTblRHgt, ;
      nTblHdPct  TO  0, ;
      nTblHdFont  TO  nTblFntNum, ;
      nTblHdFSize  TO  ::nFontSize + 2, ;
      nTblHdColor   TO  0, ;
      nTblHdFColor  TO  0, ;
      aTblCJoin TO { }

   IF aTableCWid[ 1 ] == NIL
      AFill( aTableCWid, 6.5 / nTblColumns )
   ELSEIF ValType( aTableCWid[ 1 ] ) == "A"
      aTableCWid := AClone( aTableCWid[ 1 ] )
   ENDIF
   // Turn independent column widths into "right boundary" info...
   FOR i := 2 TO Len( aTableCWid )
      aTableCWid[ i ] += aTableCWid[ i - 1 ]
   NEXT
   IF aColPct == NIL
      aColPct   := Array( nTblColumns )
      AFill( aColPct, 0 )
   ENDIF
   ::cTblHAlign := Lower( Left( cTblHAlign, 1 ) )
   ::nTblFntNum := nTblFntNum
   ::nTblFntSize := nTblFntSize
   ::cCellAppear := cCellAppear
   ::cCellHAlign := cCellHAlign
   ::nTblRows := nTblRows
   ::nTblColumns := nTblColumns
   ::nTblRHgt := nTblRHgt
   ::aTableCWid := aTableCWid
   ::cRowBorder := ::BorderCode( cRowBorder )
   ::cCellBorder := ::BorderCode( cCellBorder )
   ::aColPct := AClone( aColPct )
   ::nCellPct := IIf( nCellPct < 1, nCellPct * 10000, nCellPct * 100 )
   // Porcentajes para cada celda
   i := 1
   AEval( ::aColPct, { || ::aColPct[ i ] := IIf( ::aColPct[ i ] < 1, ::aColPct[ i ] * 10000, ;
      ::aColPct[ i ] * 100 ), i ++ } )
   ::lTblNoSplit := lTblNoSplit
   ::nTblHdRows := nTblHdRows
   ::nTblHdHgt := nTblHdHgt
   ::nTblHdPct := IIf( nTblHdPct < 1, nTblHdPct * 10000, nTblHdPct * 100 )
   ::nTblHdFont := nTblHdFont
   ::nTblHdFSize := nTblHdFSize
   ::nTblHdColor := nTblHdColor
   ::nTblHdFColor := nTblHdFColor
   ::cHeadAppear := cHeadAppear
   ::cHeadHAlign := cHeadHAlign
   ::TblCJoin    := AClone( aTblCJoin )
   ::nCurrColumn := 0
   ::nCurrRow    := 0
   ::OpenGroup()
   FOR j := 1 TO ::nTblHdRows
      ::TableDef( .T., j )
      FOR i := 1 TO Len( ::aTableCWid )
         ::TableCell( aHeadTit[ j ][ i ],,,,,,,, .T., .T. )
      NEXT i
   NEXT j
   ::TableDef()

   RETURN NIL
   /* *********************  END OF DefNewTable()  ********************** */

METHOD TableDef( lHeader, nRowHead, cCellBorder, aColPct ) CLASS RichText

   /* ********************************************************************
   * Description:  Writes the row defaults on the output file.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 22/10/00   JIJA
   ******************************************************************** */
   LOCAL i, j, pos

   DEFAULT lHeader TO .F., ;
      nRowHead TO 1, ;
      cCellBorder TO ::cCellBorder, ;
      aColPct TO AClone( ::aColPct )

   ::TextCode( "trowd\trgaph108\trleft-108" )
   ::TextCode( "trq" + ::cTblHAlign )
   ::Borders( "tr", ::cRowBorder )
   ::NumCode( "trrh", ::nTblRHgt )
   ::LogicCode( "trhdr", lHeader )
   ::LogicCode( "trkeep", ::lTblNoSplit )

   // Set the default shading, border & width info for each body cell
   FOR i := 1 TO Len( ::aTableCWid )
      IF lHeader
         IF ! Empty( ::TblCJoin )
            FOR j := 1 TO Len( ::TblCJoin[ nRowHead ] )
               pos := AScan( ::TblCJoin[ nRowHead ][ j ], i )
               IF pos == 1
                  ::TextCode( "clvertalt" )
                  ::TextCode( "clmgf" )
               ELSEIF pos # 0
                  ::TextCode( "clmrg" )
               ELSE
                  ::TextCode( "clvertalt" )
               ENDIF
            NEXT j
         ELSE
            ::TextCode( "clvertalt" )
         ENDIF
      ELSE
         ::TextCode( "clvertalt" )
      ENDIF
      ::Borders( "cl", cCellBorder )
      IF lHeader
         ::NumCode( "clshdng", ::nTblHdPct, .F. )
         IF ::nTblHdColor > 0
            ::NumCode( "clcbpat", ::nTblHdColor, .F. )
         ENDIF
      ELSE
         ::NumCode( "clshdng", aColPct[ i ], .F. )
      ENDIF
      ::NumCode( "cellx", ::aTableCWid[ i ] )
   NEXT

   RETURN NIL
   /* *********************  END OF TableDef()  ********************** */

METHOD TableCell( cText, nFontNumber, nFontSize, cAppear, cHorzAlign, ;
      nSpace, lSpExact, nFontColor, ;
      lDefault, lHeader, lPage, lDate ) CLASS RichText
   /* ********************************************************************
   * Description:  Writes the cell data and format on the output file.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 22/10/00   JIJA
   ******************************************************************** */

   DEFAULT nFontNumber TO - 1, ;
      nFontSize TO - 1, ;
      cAppear TO NIL, ;
      cHorzAlign TO NIL, ;
      nSpace TO 0, ;
      nFontColor TO 0, ;
      lDefault TO .F., ;
      lHeader TO .F., ;
      lPage TO .F., ;
      lDate TO .F.

   ::nCurrColumn += 1
   ::LogicCode( "pard", lDefault )
   ::TextCode( "intbl" )
   IF lHeader
      ::NewFont( ::nTblHdFont )
      ::SetFontSize( ::nTblHdFSize )
      IF ::nTblHdFColor > 0
         ::SetFontColor( ::nTblHdFColor )
      ENDIF
      ::Appearance( ::cHeadAppear )
      ::HAlignment( ::cHeadHAlign )
   ELSE
      ::NewFont( IIf( nFontNumber == - 1, ::nTblFntNum, nFontNumber ) )
      ::SetFontSize( IIf( nFontSize == - 1, ::nTblFntSize, nFontSize ) )
      ::SetFontColor( nFontColor )
      ::Appearance( IIf( cAppear == NIL, ::cCellAppear, cAppear ) )
      ::HAlignment( IIf( cHorzAlign == NIL, ::cCellHAlign, cHorzAlign ) )
      ::LineSpacing( nSpace, lSpExact )
   ENDIF
   ::Write( cText )
   IF lPage
      ::NumPage()
   ENDIF

   IF lDate
      ::CurrDate()
   ENDIF
   ::TextCode( "cell" )
   IF ::nCurrColumn == ::nTblColumns // Ha terminado una columna
      ::TextCode( "intbl\row" )
      ::nCurrColumn := 0
   ENDIF

   RETURN NIL
   /* *********************  END OF TableCell()  ********************** */

METHOD CellFormat( cCellBorder, aCellPct ) CLASS RichText

   /* ********************************************************************
   * Description:  Changes the format of one row.
   *               Now we can change the celborders and shading for
   *               a row on run time.
   * Arguments:
   * Return:
   * Date       Developer   Comments
   * 22/10/00   JIJA
   ******************************************************************** */

   DEFAULT cCellBorder TO ::cCellBorder, ;
      aCellPct TO AClone( ::aColPct )

   ::TableDef(,, cCellBorder, aCellPct )

   RETURN NIL
   /* *********************  END OF CellFormat()  ********************** */

METHOD DocFormat( nTab, nLineStart, lBackup, nDefLang, nDocType, ;
      cFootType, cFootNotes, cEndNotes, cFootNumber, nPage, ;
      cProtect, lFacing, nGutter ) CLASS RichText

   DEFAULT nTab TO 0.5, ;
      nLineStart TO 1, ;
      lBackup TO .F., ;
      nDefLang TO 1034, ;
      nDocType TO 0, ;
      cFootType TO "FOOTNOTES", ;
      cEndNotes TO "SECTION", ;
      cFootNotes TO "SECTION", ;
      cFootNumber TO "SIMBOL", ;
      nPage TO 1, ;
      cProtect TO "NONE", ;
      lFacing TO .F., ;
      nGutter TO 0

   ::lFacing := lFacing
   ::NumCode( "deftab", nTab, .T. )
   ::NumCode( "linestart", nLineStart, .F. )
   ::LogicCode( "makebackup", lBackup )
   ::NumCode( "deflang", nDefLang, .F. )
   ::NumCode( "doctype", nDocType, .F. )
   DO CASE
   CASE cFootType == "FOOTNOTES"
      ::NumCode( "fet", 0, .F. )
      IF cFootNotes == "SECTION"
         ::TextCode( "endnotes" )
      ELSE
         ::TextCode( "enddoc" )
      ENDIF
      ::TextCode( "ftnbj" )
   CASE cFootType == "ENDNOTES"
      ::NumCode( "fet", 1, .F. )
      IF cEndNotes == "SECTION"
         ::TextCode( "aendnotes" )
      ELSE
         ::TextCode( "aenddoc" )
      ENDIF
      ::TextCode( "aftnbj" )
   CASE cFootType == "BOTH"
      ::NumCode( "fet", 2, .F. )
      IF cFootNotes == "SECTION"
         ::TextCode( "endnotes" )
      ELSE
         ::TextCode( "enddoc" )
      ENDIF
      IF cEndNotes == "SECTION"
         ::TextCode( "aendnotes" )
      ELSE
         ::TextCode( "aenddoc" )
      ENDIF
      ::TextCode( "ftnbj" )
      ::TextCode( "aftnbj" )
   ENDCASE
   DO CASE
   CASE cFootNumber == "SIMBOL"
      ::TextCode( "ftnnchi" )
      ::TextCode( "aftnnchi" )
   CASE cFootNumber == "ARABIC"
      ::TextCode( "ftnnar" )
      ::TextCode( "aftnnar" )
   CASE cFootNumber == "ALPHA"
      ::TextCode( "ftnnalc" )
      ::TextCode( "aftnnalc" )
   CASE cFootNumber == "ROMAN"
      ::TextCode( "ftnnrlc" )
      ::TextCode( "aftnnrlc" )
   ENDCASE
   ::LogicCode( "facingp", lFacing )
   IF lFacing
      ::NumCode( "gutter", nGutter, .T. )
   ENDIF
   ::Numcode( "pgnstart", nPage, .F. )
   DO CASE
   CASE cProtect == "REVISIONS"
      ::TextCode( "revprot" )
   CASE cProtect == "COMMENTS"
      ::TextCode( "annotprot" )
   ENDCASE

   RETURN NIL

METHOD CurrDate( cFormat ) CLASS RichText

   DEFAULT cFormat TO "LONGFORMAT"

   DO CASE
   CASE cFormat == "LONGFORMAT"
      ::TextCode( "chdpl" )
   CASE cFormat == "SHORTFORMAT"
      ::TextCode( "chdpa" )
   CASE cFormat == "HEADER"
      ::TextCode( "chdate" )
   ENDCASE

   RETURN NIL

   /*

   METHOD RtfJpg(cName,aSize,nPercent) CLASS RichText

   local aInches[2],in,nWidth,nHeight,i
   LOCAL cMenInter,n_bloque,nBytes,lHecho
   local codigo,scale,PictWidth,PictHeight
   LOCAL ScreenResY,ScreenResX

   DEFAULT  aSize:={}
   DEFAULT  nPercent=1

   n_bloque:=1
   cMenInter:=space(n_bloque)
   lHecho:=.F.

   IF LoadPicture(cName,@nWidth,@nHeight,@ScreenResX,@ScreenResY) //NViewLib32( AllTrim(cName ))
   aInches[1]:= ROUND(((nWidth/ScreenResX)*::nScale)+0.5,0)
   aInches[2]:= ROUND(((nHeight/ScreenResY)*::nScale)+0.5,0)
   // Dimensiones de la imagen en twips
   IF EMPTY(aSize)
   PictWidth:=ROUND(aInches[1]+0.5,0)*nPercent
   PictHeight:=ROUND(aInches[2]+0.5,0)*nPercent
   ELSE
   PictWidth:=ROUND((aSize[1]*::nScale)+0.5,0)
   PictHeight:=ROUND((aSize[2]*::nScale)+0.5,0)
   ENDIF
   in:=fopen(cName)
   ::OpenGroup()
   ::TextCode("pict\jpegblip")
   scale=ROUND((PictWidth*100/aInches[1])+0.5,0)
   ::NumCode("picw",nWidth,.F.)
   ::NumCode("picwgoal",aInches[1],.F.)
   ::NumCode("picscalex",scale,.F.)
   scale=ROUND((PictHeight*100/aInches[2])+0.5,0)
   ::NumCode("pich",nHeight,.F.)
   ::NumCode("pichgoal",aInches[2],.F.)
   ::NumCode("picscaley",scale,.F.)
   do while !lHecho
   nBytes:=fread(in,@cMenInter,n_bloque)
   IF nBytes > 0
   codigo:=PADL(L_DTOHEX(ASC(cMenInter)),2,"0")
   FWRITE(::hfile,codigo)
   else
   lHecho:= .T.
   endif
   ENDDO
   ::CloseGroup()

   fclose(in)
   ENDIF

   RETURN NIL

   METHOD Wmf2Rtf(cName,aSize,nPercent) CLASS RichText

   local in,cMenInter,n_bloque,nBytes,lHecho,i
   local codigo,cBRead,scale,PictWidth,PictHeight
   LOCAL ancho,alto,bmHeight,bmWidth,x,aInfo[5]

   DEFAULT  aSize to {}
   DEFAULT nPercent to 1

   n_bloque:=1
   cMenInter:=space(n_bloque)
   lHecho:=.F.
   cBRead:=0

   cBRead:=GETBMETAFILE(cName,aInfo)

   IF cBRead > 0

   IF EMPTY(aSize)
   alto=(aInfo[3]-aInfo[1])*nPercent  // Unidades
   ancho=(aInfo[4]-aInfo[2])*nPercent
   ELSE
   alto:=(aSize[2]*aInfo[5])
   ancho:=(aSize[1]*aInfo[5])
   ENDIF

   bmHeight=ROUND((alto*1440/2540)+0.5,0)
   bmWidth=ROUND((ancho*1440/2540)+0.5,0)

   PictHeight=ROUND((alto*1440/::oPrinter:nLogPixelY())+0.5,0)
   PictWidth=ROUND((ancho*1440/::oPrinter:nLogPixelX())+0.5,0)
   in:=fopen(cName)
   ::OpenGroup()
   ::TextCode("\pict\wmetafile8")
   x = ROUND((bmWidth*2540/1440)+0.5,0)
   ::NumCode("picw",x,.F.)
   ::NumCode("picwgoal",bmWidth,.F.)
   scale=ROUND((PictWidth*100/bmWidth)+0.5,0)
   ::NumCode("picscalex",scale,.F.)
   x = ROUND((bmHeight*2540/1440)+0.5,0)
   ::NumCode("pich",x,.F.)
   ::NumCode("pichgoal",bmHeight,.F.)
   scale=ROUND((PictHeight*100/bmHeight)+0.5,0)
   ::NumCode("picscaley",scale,.F.)
   ::OpenGroup()
   fseek(in,cBRead,0)
   do while !lHecho
   nBytes:=fread(in,@cMenInter,n_bloque)
   IF nBytes > 0
   codigo:=PADL(L_DTOHEX(ASC(cMenInter)),2,"0")
   FWRITE(::hFile,codigo)
   else
   lHecho:= .T.
   endif
   ENDDO
   ::CloseGroup()
   ::CloseGroup()
   fclose(in)
   ENDIF

   RETURN NIL
   */

   * Funtion to load a picture using nviewlib.

   /*

   FUNCTION LoadPicture(cName,nWidth,nHeight,ScreenResX,ScreenResy)

   LOCAL hDll,uResult,cFarProc
   LOCAL oWnd,hWnd,hdc

   hDLL := LoadLib32("nviewlib.dll")
   IF Abs(hDll) <= 32

   RETURN .F.
   ENDIF

   cFarProc:=GetProc32(hDll,"NViewLibLoad",.t.,LONG,STRING,LONG)
   uResult=CallDll32(cFarProc,cName,0)
   cFarProc:=GetProc32(hDll,"GetWidth",.t.,_INT)
   nWidth=CallDll32(cFarProc)
   cFarProc:=GetProc32(hDll,"GetHeight",.t.,_INT)
   nHeight=CallDll32(cFarProc)
   FreeLib32(hDll)
   oWnd:=GetWndDefault()
   hWnd:=oWnd:hWnd
   hdc:=hwg_Getdc(hWnd)
   ScreenResX:=GETDEVICEC(hdc,88)
   ScreenResY:=GETDEVICEC(hdc,90)

   RETURN .T.

   METHOD Bmp2Wmf(cName,aSize,nPercent) CLASS RichText

   LOCAL cMenInter,n_bloque,nBytes,lHecho
   LOCAL codigo,PictWidth,PictHeight
   LOCAL hDCOut,hDib,hPal,nRaster
   LOCAL cDir,temp,scalex,in,x,scaley
   LOCAL nWidth,nHeight
   LOCAL ResX,ResY
   LOCAL aInches[2]

   DEFAULT  aSize:={}
   DEFAULT nPercent:=1

   n_bloque := 1
   cMenInter := Space(n_bloque)
   lHecho := .F.
   cDir := GetEnv( "TEMP" )
   temp := cDir + "\tmp" + padl( ALLTRIM( STR( ::nFile, 4, 0 ) ), 4, "0" ) + ".wmf"
   hDCOut := hwg_CreateMetafile( temp )
   hDib := DibRead( cName )
   IF hDib > 0
   // Dimensiones en pixels
   nWidth := DIBWIDTH( hDib )
   nHeight := DIBHEIGHT( hDib )
   ResX := DIBXPIX( hDib ) / 39.37
   ResY := DIBYPIX( hDib ) / 39.37
   // Dimensiones reales de la imagen en pulgadas
   aInches[1]:=nWidth/ResX
   aInches[2]:=nHeight/ResY
   IF EMPTY(aSize)
   aInches[ 1 ] *= nPercent
   aInches[ 2 ] *= nPercent
   scalex := INT( nPercent*100 )
   scaley := INT( nPercent*100 )
   ELSE
   scalex := ROUND( ( ( aSize[ 1 ] * 100 ) / aInches[ 1 ] ) + 0.5, 0 )
   scaley := ROUND( ( ( aSize[ 2 ] * 100 ) / aInches[ 2 ] ) + 0.5, 0 )
   aInches[1 ] := aSize[ 1 ]
   aInches[ 2 ] := aSize[ 2 ]
   ENDIF
   aInches[ 1 ] := ROUND( aInches[ 1 ] * 1440, 0 )
   aInches[ 2 ] := ROUND( aInches[ 2 ] * 1440, 0 )
   // initialize the metafile
   SETWNDEX( hDCOut, 0, 0 )
   hwg_Setwindowextex( hDCOut, nWidth, nHeight );

   DibDraw( hDCOut, hDib, hPal, 0, 0, nWidth, nHeight, nRaster )
   GlobalFree( hDib )
   CloseMetafile( hDCOut )
   DELETEMETA( hDcOut )
   // La matriz que se necesita para el metafile
   in := fopen( temp )
   ::OpenGroup()
   ::TextCode( "\pict\wmetafile8" )
   x := ROUND( ( ( aInches[ 1 ] * 2540 ) / 1440 ) + 0.5, 0 )
   ::NumCode( "picw", x, .F. )
   ::NumCode( "picwgoal", aInches[ 1 ], .F. )
   ::NumCode( "picscalex", scalex, .F. )
   x := ROUND( ( ( aInches[ 2 ] * 2540 ) / 1440 ) + 0.5, 0 )
   ::NumCode( "pich", x, .F. )
   ::NumCode("pichgoal", aInches[2], .F. )
   ::NumCode( "picscaley", scaley, .F.)
   ::OpenGroup()
   DO WHILE !lHecho
   nBytes:=fread(in,@cMenInter,n_bloque)
   IF nBytes > 0
   codigo:=PADL(L_DTOHEX(ASC(cMenInter)),2,"0")
   FWRITE(::hFile,codigo)
   ELSE
   lHecho:= .T.
   ENDIF
   ENDDO
   ::CloseGroup()
   ::CloseGroup()
   fclose( in )
   FERASE( temp )
   ::nFile += 1
   ENDIF

   RETURN NIL
   */

FUNCTION cFileExt( cFile )

   RETURN SubStr( cFile, At( '.', cFile ) + 1 )

   #ifndef __XHARBOUR__

STATIC FUNCTION CStr( xExp )

   LOCAL cType

   IF xExp == NIL

      RETURN 'NIL'
   ENDIF
   cType := ValType( xExp )
   DO CASE
   CASE cType == 'C'

      RETURN xExp
   CASE cType == 'D'

      RETURN DToC( xExp )
   CASE cType == 'L'

      RETURN IIf( xExp, '.T.', '.F.' )
   CASE cType == 'N'

      RETURN Str( xExp )
   CASE cType == 'M'

      RETURN xExp
   CASE cType == 'A'

      RETURN "{ Array of " +  LTrim( Str( Len( xExp ) ) ) + " Items }"
   CASE cType == 'B'

      RETURN '{|| Block }'
   CASE cType == 'O'

      RETURN "{ " + xExp:ClassName() + " Object }"
   CASE cType == 'P'
      #if defined( __XHARBOUR__ )

      RETURN NumToHex( xExp )
      #else

      RETURN hb_NumToHex( xExp )
      #endif
   CASE cType == 'H'

      RETURN "{ Hash of " +  LTrim( Str( Len( xExp ) ) ) + " Items }"
   OTHERWISE

      RETURN "Type: " + cType
   ENDCASE

   RETURN ""
   #endif
