/*
* $Id: tmci.prg,v 1.3 2004/09/29 05:24:52 alkresin Exp $
* HWGUI - Harbour Win32 GUI library source code:
* Windows errorsys replacement
* Copyright 2003 Luiz Rafael Culik Guimaraes <culikr@brtrubo.com>
* www - http://sites.uol.com.br/culikr/
*/

#include "hbclass.ch"
#include "windows.ch"
#include "guilib.ch"
#include "common.ch"
#define BUF_SIZE  200

CLASS TMci

   DATA   nError, nId
   DATA   cType, cFileName
   DATA   oWnd
   DATA   cBuffer

METHOD New( cDevice, cFileName )  CONSTRUCTOR

METHOD lOpen()

METHOD Play( nFrom, nTo, hWnd ) inline;
      ::nError := nMciPlay( ::nId, nFrom, nTo, hWnd )

METHOD cGetError()

METHOD SetWindow( oWnd ) inline ;
      ::oWnd := oWnd,;
      ::nError := nMciWindow( ::nId, oWnd:handle )

METHOD SendStr( cMciStr )

ENDCLASS

METHOD New( cDevice, cFileName ) CLASS TMci

   DEFAULT cDevice to ""

   ::nError    = 0
   ::nId       = 0
   ::cType     = cDevice
   ::cFileName = cFileName
   ::cBuffer   = Space( BUF_SIZE )

   RETURN Self

METHOD SendStr( cMciStr ) CLASS TMci

   LOCAL cBuffer := ::cBuffer

   MciSendString( cMciStr, @cBuffer, ::oWnd:hWnd )
   ::cBuffer = cBuffer

   RETURN NIL

METHOD lOpen() CLASS TMci

   LOCAL nId

   ::nError := nMciOpen( ::cType, ::cFileName, @nId )
   ::nId := nId

   RETURN ::nError == 0

METHOD cGetError() Class Tmci

   LOCAL cError

   mciGetErrorString( ::nError, @cError )

   RETURN    cError

