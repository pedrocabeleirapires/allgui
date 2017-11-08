/*
 * $Id: printdos.prg,v 1.22 2007/11/26 04:48:43 andijahja Exp $
 *
 * CLASS PrintDos
 *
 * Copyright (c) Sandro Freire <sandrorrfreire@yahoo.com.br>
 * for HwGUI By Alexander Kresin
 *
 */
#include "hbclass.ch"
#include "windows.ch"
#include "guilib.ch"
#include "fileio.ch"

#define PF_BUFFERS   2048

#define oFORMFEED               "12"
#define oLASER10CPI             "27,40,115,49,48,72"
#define oLASER12CPI             "27,40,115,49,50,72"
#define oLASER18CPI             "27,40,115,49,56,72"
#define oLASERBOLD              "27,40,49,54,46,54,55,72"   //Added by  por Fernando Athayde 27(16.67H
#define oLASERUNBOLD            "27,40,115,49,50,72"        //Added by  por Fernando Athayde 27(s12H
#define oINKJETDOUBLE           "27,33,32"
#define oINKJETNORMAL           "27,33,00"
#define oINKJETCOMPRESS         "27,33,04"
#define oINKJETBOLD             "27,40,115,55,66"   //Added by  por Fernando Athayde
#define oINKJETUNBOLD           "27,40,115,48,66"   //Added by  por Fernando Athayde
#define oMATRIXDOUBLE           "14"
#define oMATRIXNORMAL           "18"
#define oMATRIXCOMPRESS         "15"
#define oMATRIXBOLD             "27,71"   //Added by  por Fernando Athayde
#define oMATRIXUNBOLD           "27,72"   //Added by  por Fernando Athayde

CLASS PrintDos

     DATA cCompr, cNormal,oText, cDouble, cBold, cUnBold AS CHARACTER
     DATA oPorta, oPicture      AS CHARACTER
     DATA orow, oCol            AS NUMERIC
     DATA cEject, nProw, nPcol, fText, gText
     DATA oTopMar               AS NUMERIC
     DATA oLeftMar              AS NUMERIC
     DATA oAns2Oem              AS LOGIC
     DATA LastError
     DATA oPrintStyle INIT 1 //1 = Matricial   2 = InkJet    3 = LaserJet
     DATA colorPreview
     DATA nStartPage init 1
     DATA nEndPage init 0
     DATA nCopy init 1

     METHOD New(oPorta) CONSTRUCTOR

     METHOD Say(oProw, oCol, oTexto, oPicture)

     METHOD SetCols(nRow, nCol)

     METHOD gWrite(oText)

     METHOD NewLine()

     METHOD Eject()

     METHOD Compress()

     METHOD Double()

     METHOD DesCompress()

     METHOD Bold()       //Added by  por Fernando Athayde

     METHOD UnBold()     //Added by  por Fernando Athayde

     METHOD Comando()

     METHOD SetPrc(x,y)

     METHOD PrinterFile(oFile)

     METHOD TxttoGraphic(oFile,osize,oPreview)

     METHOD Preview(fname, cTitle)

     METHOD End()

ENDCLASS

METHOD New(oPorta) CLASS PrintDos
     Local oDouble  :={oMATRIXDOUBLE,   oINKJETDOUBLE,   oLASER10CPI }
     Local oNormal  :={oMATRIXNORMAL,   oINKJETNORMAL,   oLASER12CPI }
     Local oCompress:={oMATRIXCOMPRESS, oINKJETCOMPRESS, oLASER18CPI }
     Local oBold    :={oMATRIXBOLD,     oINKJETBOLD,     oLASERBOLD  }       //Added by  por Fernando Athayde
     Local oUnBold  :={oMATRIXUNBOLD,   oINKJETUNBOLD,   oLASERUNBOLD }       //Added by  por Fernando Athayde
     Local oPtrSetup, oPtrName

     ::cCompr   := oCompress[::oPrintStyle]
     ::cNormal  := oNormal[::oPrintStyle]
     ::cDouble  := oDouble[::oPrintStyle]
     ::cBold    := oBold[::oPrintStyle]       //Added by  por Fernando Athayde
     ::cUnBold  := oUnBold[::oPrintStyle]       //Added by  por Fernando Athayde
     ::cEject   := oFORMFEED
     ::nProw    := 0
     ::nPcol    := 0
     ::oTopMar  := 0
     ::oAns2Oem :=.t.
     ::oLeftMar := 0
     ::oText    := ""

     if Empty(oPorta) //
        ::oPorta       := "LPT1"
     Else
        If oPorta=="DEFAULT"
          oPtrName:=PrintPortName()
          if oPtrName==Nil
             MsgInfo("Error, file to:ERROR.TXT")
             ::oPorta :="Error.txt"
          else
             ::oPorta := oPtrName
          EndIf
        ElseIf oPorta=="SELECT"

#ifdef __XHARBOUR__
        oPtrSetup:=PrintSetupDos(@::nStartPage,@::nEndPage,@::nCopy)
#else
        oPtrSetup:=PrintSetupDos()
#endif
          If oPtrSetup==Nil
             MsgInfo("Error, file to:ERROR.TXT")
             ::oPorta :="Error.txt"
          Else
             oPtrName:=PrintPortName()
             if oPtrName==Nil
                MsgInfo("Error, file to:ERROR.TXT")
                ::oPorta :="Error.txt"
             else
                oPtrName:= Alltrim(oPtrName)
                if Substr( oPtrName, 1, 3 ) == "LPT"
                   oPtrName:=Left( oPtrName, Len( oPtrName) -1 )
                EndIF
                ::oPorta := oPtrName
             EndIf
          EndIf
        Else
          ::oPorta     := oPorta
        EndIf
     EndIf

     If oPorta=="GRAPHIC" .or. oPorta=="PREVIEW"
          ::gText := ""
     Else
          // tracelog([          ::gText:=fCreate(::oPorta)])
          ::gText:=fCreate(::oPorta)
          //tracelog([depois           ::gText:=fCreate(::oPorta)],::gtext)
          if ::gText<0
             ::LastError:=fError()
          Else
             ::LastError:=0
          EndIf
     EndIf


RETURN SELF


METHOD Comando(oComm1,oComm2, oComm3, oComm4, oComm5, oComm6, oComm7,;
               oComm8,oComm9, oComm10)  CLASS PrintDos

   local nCont := 1
   local oStr := oComm1

   oStr:=Chr( Val (oComm1) )

   IF oComm2  != NIL ;  oStr +=Chr(Val(oComm2 ));   ENDIF
   IF oComm3  != NIL ;  oStr +=Chr(Val(oComm3 ));   ENDIF
   IF oComm4  != NIL ;  oStr +=Chr(Val(oComm4 ));   ENDIF
   IF oComm5  != NIL ;  oStr +=Chr(Val(oComm5 ));   ENDIF
   IF oComm6  != NIL ;  oStr +=Chr(Val(oComm6 ));   ENDIF
   IF oComm7  != NIL ;  oStr +=Chr(Val(oComm7 ));   ENDIF
   IF oComm8  != NIL ;  oStr +=Chr(Val(oComm8 ));   ENDIF
   IF oComm9  != NIL ;  oStr +=Chr(Val(oComm9 ));   ENDIF
   IF oComm10 != NIL ;  oStr +=Chr(Val(oComm10));   ENDIF


   If ::oAns2Oem
     ::oText += HB_ANSITOOEM(oStr)
   Else
     ::oText += oStr
   EndIf

Return Nil


METHOD gWrite(oText)  CLASS PrintDos

    //tracelog(otext)
    If ::oAns2Oem
       ::oText += HB_ANSITOOEM(oText)
       ::nPcol += len(HB_ANSITOOEM(oText))
    Else
       ::oText += oText
       ::nPcol += len(oText)
    EndIf
    //tracelog(otext)

Return Nil

METHOD Eject()   CLASS PrintDos
//tracelog( ::gText, ::oText )

     fWrite( ::gText, ::oText )

     If ::oAns2Oem
        fWrite( ::gText, HB_ANSITOOEM(Chr(13)+Chr(10)+Chr(Val(::cEject))))
        fWrite(::gText, HB_ANSITOOEM(Chr(13)+Chr(10)))
     Else
        fWrite( ::gText,Chr(13)+Chr(10)+Chr(Val(::cEject)))
        fWrite(::gText, Chr(13)+Chr(10))
     EndIf

     ::oText :=""
     ::nProw := 0
     ::nPcol := 0
    //tracelog( ::gText, ::oText )
Return Nil

METHOD Compress() CLASS PrintDos

     ::Comando(::cCompr)

Return Nil

METHOD Double() CLASS PrintDos

     ::Comando(::cDouble)

Return Nil

METHOD DesCompress() CLASS PrintDos

     ::Comando(::cNormal)

Return Nil

//*** Contribution Fernando Athayde ***

METHOD Bold() CLASS PrintDos

     ::Comando(::cBold)

Return Nil

METHOD UnBold() CLASS PrintDos

     ::Comando(::cUnBold)

Return Nil


METHOD NewLine() CLASS PrintDos

    If ::oAns2Oem
      ::oText += HB_ANSITOOEM(Chr(13)+Chr(10))
    Else
      ::oText += Chr(13)+Chr(10)
    EndIf
    ::nPcol:=0
Return Nil

METHOD Say(oProw, oPcol, oTexto, oPicture) CLASS PrintDos
    // tracelog(oProw, oPcol, oTexto, oPicture)
    If Valtype(oTexto)=="N"

       If !Empty(oPicture) .or. oPicture#Nil
          oTexto:=Transform(oTexto, oPicture)
       Else
          oTexto:=Str(oTexto)
       Endif

    Elseif Valtype(oTexto)=="D"
       oTexto:=DTOC(oTexto)
    Else
       If !Empty(oPicture) .or. oPicture#Nil
          oTexto:=Transform(oTexto, oPicture)
       Endif
    EndIf
    //tracelog([antes     ::SetCols(oProw, oPcol)])
    ::SetCols(oProw, oPcol)
    //tracelog([depois de ::SetCols(oProw, oPcol) e  antes         ::gWrite(oTexto))])
    ::gWrite(oTexto)

Return Nil

METHOD SetCols(nProw, nPcol) CLASS PrintDos

     IF ::nProw > nProw
        ::Eject()
     ENDIF

     IF ::nProw < nProw
        Do While ::nProw<nProw
           ::NewLine()
           ++::nProw
        EndDo
     ENDIF

     IF nProw == ::nProw  .AND. nPcol < ::nPcol
          ::Eject()
     ENDIF

     IF nPcol > ::nPcol
          ::gWrite(Space(nPcol-::nPcol))
     ENDIF

Return Nil

METHOD SetPrc(x,y) CLASS PrintDos
::nProw:=x
::nPCol:=y
Return Nil

METHOD End() CLASS PrintDos

   fWrite( ::gText, ::oText )
   fClose( ::gText )

Return Nil

METHOD PrinterFile(fname) CLASS PrintDos
LOCAL strbuf := Space(PF_BUFFERS)
Local han, nRead

   IF !File( fname )
      MsgStop("Error open file "+fname,"Error")
      Return .F.
   EndIf

   han := FOPEN( fname, FO_READWRITE + FO_EXCLUSIVE )

   IF han <> - 1

         DO while .t.

            nRead := fRead(han, @strBuf, PF_BUFFERS)

            if nRead=0 ; Exit ; Endif

            IF fWrite(::gText, Left(strbuf, nRead)) < nRead
               ::ErrosAnt := fError()
               fClose(han)
               RETURN .F.
            ENDIF

         EndDo

   ELSE

         MsgStop( "Can't Open port" )
         Fclose( han )

   ENDIF

RETURN .T.

Function wProw(oPrinter)
Return oPrinter:nProw

Function wPCol(oPrinter)
Return oPrinter:nPcol

Function wSetPrc(x,y,oPrinter)
oPrinter:SetPrc(x,y)
Return Nil

METHOD TxttoGraphic(fName,osize,oPreview) CLASS PrintDos

LOCAL strbuf := Space(2052), poz := 2052, stroka
Local han := FOPEN( fname, FO_READ + FO_SHARED )
Local res := .T.
Local oCol:=0, oPage:=1  //Added by  Por Fernando Athayde
Local oPrinter
Local oFont

INIT PRINTER oPrinter // HPrinter():New()
// added by Giuseppe Mastrangelo
if oPrinter == nil
   return .f.
endif
// end of added code
oFont := oPrinter:AddFont( "Courier New", oSize )

oPrinter:StartDoc( oPreview  )
oPrinter:StartPage()

SelectObject( oPrinter:hDC,oFont:handle )

IF han <> - 1
   DO WHILE .T.
      stroka := RDSTR( han,@strbuf,@poz,2052 )
      IF LEN( stroka ) = 0
         EXIT
      ENDIF
      if oSize <0
      oPrinter:Say( stroka, 0, ocol,2400, ocol+(-oSize+2),,oFont )  //Added by  Por Fernando Athayde
      oCol:=oCol+(-oSize+2)   //Added by  Por Fernando Athayde
      else
         oPrinter:Say( stroka, 0, ocol,2400, ocol+(oSize+2),,oFont )  //Added by  Por Fernando Athayde
         oCol:=oCol+(oSize+2)   //Added by  Por Fernando Athayde
      endif

      IF Left( stroka,1 ) == Chr(12)
         oPrinter:EndPage()
         oPrinter:StartPage()
         ++oPage
         oCol:=0  //Added by  Por Fernando Athayde
      ENDIF

   ENDDO
   Fclose( han )
ELSE
   MsgStop( "Can't open "+fname )
   Return .F.
ENDIF
oPrinter:EndPage()
oPrinter:EndDoc()
oPrinter:Preview()
oPrinter:End()
oFont:Release()

Return .T.

METHOD Preview(fName,cTitle) CLASS PrintDos
Local oedit1
LOCAL strbuf := Space(2052), poz := 2052, stroka
Local han := FOPEN( fname, FO_READ + FO_SHARED )
Local res := .T.
Local oCol:=10, oPage:=1, nPage:=1
Local oFont := HFont():Add( "Courier New",0,-13 )
Local oText := {""}
Local oDlg, oColor1, oColor2
Local oEdit
Local oPrt:= iif(Empty(::oPorta) .or. ::oPorta == "PREVIEW", "LPT1", ::oPorta)

IF han <> - 1
   DO WHILE .T.
      stroka := RDSTR( han,@strbuf,@poz,2052 )
      IF LEN( stroka ) = 0
         EXIT
      ENDIF
      If ::oAns2Oem
          oText[oPage]+=HB_ANSITOOEM(stroka) + Chr(13) + Chr(10)
      Else
          oText[oPage]+=stroka + Chr(13) + Chr(10)
      EndIf
      IF Left( stroka,1 ) == Chr(12)
         AADD(oText,"")
         ++oPage
      ENDIF
      oCol:=oCol+30
   ENDDO
   Fclose( han )
ELSE
   MsgStop( "Can't open "+fname )
   Return .F.
ENDIF

oEdit:=SUBS(oText[nPage],2)  //Added by  Por Fernando Exclui 1 byte do oText nao sei de onde ele aparece

if !Empty(::colorpreview)
   oColor1:=::colorpreview[1]
   oColor2:=::colorpreview[2]
Else
   oColor1:=16777088
   oColor2:=0
EndIf

Iif(cTitle==Nil,cTitle:="Print Preview",cTitle:=cTitle)

INIT DIALOG oDlg TITLE cTitle ;
     AT 0,0 SIZE GETDESKTOPWIDTH(),GETDESKTOPHEIGHT() on init {||Sendmessage(oEdit1:handle,WM_VSCROLL  ,SB_TOP,0)}



*   @ 88,19 EDITBOX oEdit ID 1001 SIZE 548,465 STYLE WS_VSCROLL + WS_HSCROLL + ES_AUTOHSCROLL + ES_MULTILINE ;
*        COLOR oColor1 BACKCOLOR oColor2  //Blue to Black  && Original
//   @ 88,19 EDITBOX oEdit ID 1001 SIZE 548,465 STYLE WS_VSCROLL + WS_HSCROLL + ES_AUTOHSCROLL + ES_MULTILINE ;
//        COLOR oColor1 BACKCOLOR oColor2 FONT oFont //Blue to Black  //Added by  por Fernando Athayde
   @ 88,19 EDITBOX oedit1 CAPTION oEdit ID 1001 SIZE GETDESKTOPWIDTH()-100,GETDESKTOPHEIGHT()-100 STYLE WS_VSCROLL + WS_HSCROLL + ES_AUTOHSCROLL + ES_MULTILINE ;
        COLOR oColor1 BACKCOLOR oColor2 FONT oFont //Blue to Black  //Added by  por Fernando Athayde


*   @ 88,19 EDITBOX oEdit ID 1001 SIZE 548,465 STYLE WS_VSCROLL + WS_HSCROLL + ES_AUTOHSCROLL + ES_MULTILINE ;
*        COLOR oColor1 BACKCOLOR oColor2  //Blue to Black  && Original
//   @ 88,19 EDITBOX oEdit ID 1001 SIZE 548,465 STYLE WS_VSCROLL + WS_HSCROLL + ES_AUTOHSCROLL + ES_MULTILINE ;
//        COLOR oColor1 BACKCOLOR oColor2 FONT oFont //Blue to Black  //Added by  por Fernando Athayde
//       COLOR 16711680 BACKCOLOR 16777215  //Black to Write
   @ 6, 30 BUTTON "<<"    ON CLICK {||nPage:=PrintDosAnt(nPage,oText)} SIZE 69,32  STYLE if(nPage=1,WS_DISABLED,0)
   @ 6, 80 BUTTON ">>"    ON CLICK {||nPage:=PrintDosNext(oPage,nPage,oText)} SIZE 69,32 STYLE if(nPage=1,WS_DISABLED,0)
   @ 6,130 BUTTON "Imprimir" ON CLICK {||PrintDosPrint(oText,oPrt)} SIZE 69,32
//   @ 6,180 BUTTON "Grafico" on Click {||EndDialog(),oDos2:TxttoGraphic(fName,2,.t.),oDos2:end()} SIZE 69,32
   @ 6,230 BUTTON "Fechar" ON CLICK {||EndDialog()} SIZE 69,32

   oDlg:Activate()

Return .T.

Static Function PrintDosPrint(oText, oPrt)
Local i
Local nText:=fCreate(oPrt)
FOR i:=1 to Len(oText)
    fWrite( nText, oText[i])
NEXT
fClose(nText)
Return Nil


Static Function PrintDosAnt(nPage, oText)
Local oDlg:=GetModalhandle()
nPage:=--nPage
If nPage<1; nPage :=1 ; Endif
IF nPage=1  //Added by  Por Fernando Exclui 1 byte do oText nao sei de onde ele aparece
   SetDlgItemText( oDlg, 1001, SUBS(oText[nPage],2) )  //Added by  Por Fernando Exclui 1 byte do oText nao sei de onde ele aparece
ELSE
   SetDlgItemText( oDlg, 1001, oText[nPage] )
ENDIF
Return nPage

Static Function PrintDosNext(oPage,nPage, oText)
Local oDlg:=GetModalhandle()
nPage:=++nPage
If nPage>oPage; nPage := oPage ; Endif
SetDlgItemText( oDlg, 1001, oText[nPage] )
Return nPage

function regenfile(o,new)
local leol := .f.
Local leof := .t.
local Aeol:={chr(13)+chr(10),chr(13)}
Local aText := AFillText( o )
Local stroka
Local o1 :=printdos():new(new)
local nLine :=0
Local nChr12 :=0
Local i

FOR i := 1 To Len( aText )

   stroka := aText[i]
   nchr12 := at( chr(12), stroka )

   if nChr12 >0
     stroka:=substr(stroka,1,nchr12-1)
   endif
      o1:say(nline,0,stroka)
   nLine++

   IF nchr12 >0
      o1:eject()
      nLine:=0
   ENDIF

NEXT

Return Nil

#PRAGMA BEGINDUMP
/*
   txtfile.c
   AFILLTEXT( cFile ) -> aArray
   NTXTLINE( cFile )  -> nLines
*/

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbstack.h"
#ifdef __XHARBOUR__
#include "hbfast.h"
#endif

#undef LINE_MAX
// #define LINE_MAX 4096
// #define LINE_MAX 8192
// #define LINE_MAX 16384
#define LINE_MAX    0x20000
//----------------------------------------------------------------------------//
static BOOL file_read ( FILE *stream, char *string )
{
   int ch, cnbr = 0;

   memset (string, ' ', LINE_MAX);

   for (;;)
   {
      ch = fgetc (stream);

      if ( (ch == '\n') ||  (ch == EOF) ||  (ch == 26) )
      {
         string [cnbr] = '\0';
         return (ch == '\n' || cnbr);
      }
      else
      {
         if ( cnbr < LINE_MAX && ch != '\r' )
         {
            string [cnbr++] = (char) ch;
         }
      }

      if (cnbr >= LINE_MAX)
      {
         string [LINE_MAX] = '\0';
         return (TRUE);
      }
   }
}

//----------------------------------------------------------------------------//
HB_FUNC( AFILLTEXT )
{
   FILE *inFile ;
   char *pSrc = hb_parc(1) ;
   PHB_ITEM pArray = hb_itemNew(NULL);
   PHB_ITEM pTemp = hb_itemNew(NULL);
   char *string ;

   if ( !pSrc )
   {
      hb_reta( 0 );
      return;
   }

   if ( strlen( pSrc ) == 0 )
   {
      hb_reta( 0 );
      return;
   }
   inFile = fopen( pSrc, "r" );

   if ( !inFile )
   {
      hb_reta( 0 );
      return;
   }

   string = (char*) hb_xgrab( LINE_MAX + 1 );
   hb_arrayNew( pArray, 0 );

   while ( file_read ( inFile, string ) )
   {
     hb_arrayAddForward( pArray, hb_itemPutC( pTemp, string ));
   }

   hb_itemForwardValue( hb_stackReturnItem(), pArray );
   hb_xfree( string );
   hb_itemRelease( pArray );
   hb_itemRelease( pTemp );
   fclose( inFile );
}

#PRAGMA ENDDUMP
