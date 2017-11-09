/*
* $Id: hfreeimg.prg,v 1.10 2008/06/20 23:43:00 mlacecilia Exp $
* HWGUI - Harbour Win32 GUI library source code:
* HFreeImage - Image handling class
* To use this class you need to have the FreeImage library
* http://freeimage.sourceforge.net/
* Authors: Floris van den Berg (flvdberg@wxs.nl) and
*          Herv� Drolon (drolon@infonie.fr)
* Copyright 2003 Alexander S.Kresin <alex@belacy.belgorod.su>
* www - http://kresin.belgorod.su
*/

#include "hbclass.ch"
#include "windows.ch"
#include "guilib.ch"

CLASS HFreeImage INHERIT HObject

CLASS VAR aImages   INIT {}

   DATA handle
   DATA hBitmap
   DATA name
   DATA nWidth, nHeight
   DATA nCounter   INIT 1

METHOD AddFile( name )

METHOD AddFromVar( cImage,cType )

METHOD FromBitmap( oBitmap )

METHOD Draw( hDC,nLeft,nTop,nWidth,nHeight )

METHOD Release()

ENDCLASS

METHOD AddFile( name ) CLASS HFreeImage

   LOCAL i

   #ifdef __XHARBOUR__
   FOR EACH i IN ::aImages
      IF i:name == name
         i:nCounter ++

         RETURN i
      ENDIF
   NEXT
   #else
   FOR i := 1 TO Len( ::aImages )
      IF ::aImages[i]:name == name
         ::aImages[i]:nCounter ++

         RETURN ::aImages[i]
      ENDIF
   NEXT
   #endif
   IF Empty( ::handle := FI_Load( name ) )

      RETURN NIL
   ENDIF
   ::name := name
   ::nWidth  := FI_GetWidth( ::handle )
   ::nHeight := FI_GetHeight( ::handle )
   Aadd( ::aImages,Self )

   RETURN Self

METHOD AddFromVar( cImage,cType ) CLASS HFreeImage

   IF Empty( ::handle := FI_LoadFromMem( cImage,cType ) )

      RETURN NIL
   ENDIF
   ::name := Ltrim( Str( ::handle ) )
   ::nWidth  := FI_GetWidth( ::handle )
   ::nHeight := FI_GetHeight( ::handle )
   Aadd( ::aImages,Self )

   RETURN Self

METHOD FromBitmap( oBitmap ) CLASS HFreeImage

   ::handle := FI_Bmp2FI( oBitmap:handle )
   ::name := Ltrim( Str( oBitmap:handle ) )
   ::nWidth  := FI_GetWidth( ::handle )
   ::nHeight := FI_GetHeight( ::handle )
   Aadd( ::aImages,Self )

   RETURN Self

METHOD Draw( hDC,nLeft,nTop,nWidth,nHeight ) CLASS HFreeImage

   FI_Draw( ::handle, hDC, ::nWidth, ::nHeight, nLeft, nTop, nWidth, nHeight )
   // DrawBitmap( hDC, ::hBitmap,, nLeft, nTop, ::nWidth, ::nHeight )

   RETURN NIL

METHOD Release() CLASS HFreeImage

   LOCAL i, nlen := Len( ::aImages )

   ::nCounter --
   IF ::nCounter == 0
      #ifdef __XHARBOUR__
      FOR EACH i IN ::aImages
         IF i:handle == ::handle
            FI_Unload( ::handle )
            IF ::hBitmap != Nil
               DELETEObject( ::hBitmap )
            ENDIF
            Adel( ::aImages,hB_enumIndex())
            Asize( ::aImages,nlen-1 )
            EXIT
         ENDIF
      NEXT
      #else
      FOR i := 1 TO nlen
         IF ::aImages[i]:handle == ::handle
            FI_Unload( ::handle )
            IF ::hBitmap != Nil
               DELETEObject( ::hBitmap )
            ENDIF
            Adel( ::aImages,i )
            Asize( ::aImages,nlen-1 )
            EXIT
         ENDIF
      NEXT
      #endif
   ENDIF

   RETURN NIL

   //- HSayFImage

CLASS HSayFImage INHERIT HSayImage

   DATA nOffsetV  INIT 0
   DATA nOffsetH  INIT 0
   DATA nZoom

METHOD New( oWndParent,nId,nLeft,nTop,nWidth,nHeight,Image,bInit, ;
      bSize,ctooltip )

METHOD Redefine( oWndParent,nId,Image,bInit,bSize,ctooltip )

METHOD ReplaceImage( Image )

METHOD Paint( lpdis )

ENDCLASS

METHOD New( oWndParent,nId,nLeft,nTop,nWidth,nHeight,Image,bInit, ;
      bSize,ctooltip,cType ) CLASS HSayFImage

   IF Image != Nil
      ::oImage := Iif( Valtype(Image) == "C", ;
         Iif( cType!=Nil, HFreeImage():AddFromVar( Image,cType ), HFreeImage():AddFile( Image ) ), Image )
      IF nWidth == Nil
         nWidth  := ::oImage:nWidth
         nHeight := ::oImage:nHeight
      ENDIF
   ENDIF
   Super:New( oWndParent,nId,SS_OWNERDRAW,nLeft,nTop,nWidth,nHeight,bInit,bSize,ctooltip )
   // ::classname:= "HSAYFIMAGE"

   ::bPaint  := {|o,lpdis|o:Paint(lpdis)}

   ::Activate()

   RETURN Self

METHOD Redefine( oWndParent,nId,Image,bInit,bSize,ctooltip ) CLASS HSayFImage

   ::oImage := Iif( Valtype(Image) == "C", HFreeImage():AddFile( Image ), Image )

   Super:Redefine( oWndParent,nId,bInit,bSize,ctooltip )
   // ::classname:= "HSAYFIMAGE"

   ::bPaint  := {|o,lpdis|o:Paint(lpdis)}

   RETURN Self

METHOD ReplaceImage( Image, cType )

   IF ::oImage != Nil
      ::oImage:Release()
   ENDIF
   ::oImage := Iif( Valtype(Image) == "C", ;
      Iif( cType!=Nil, HFreeImage():AddFromVar( Image,cType ), HFreeImage():AddFile( Image ) ), Image )

   RETURN NIL

METHOD Paint( lpdis ) CLASS HSayFImage

   LOCAL drawInfo := GetDrawItemInfo( lpdis )
   LOCAL hDC := drawInfo[3], x1 := drawInfo[4], y1 := drawInfo[5], x2 := drawInfo[6], y2 := drawInfo[7]

   IF ::oImage != Nil
      IF ::nZoom == Nil
         ::oImage:Draw( hDC, ::nOffsetH, ::nOffsetV, ::nWidth, ::nHeight )
      ELSE
         ::oImage:Draw( hDC, ::nOffsetH, ::nOffsetV, ::oImage:nWidth*::nZoom, ::oImage:nHeight*::nZoom )
      ENDIF
   ENDIF

   RETURN Self

   EXIT PROCEDURE CleanImages
   LOCAL i

   FOR i := 1 TO Len( HFreeImage():aImages )
      FI_Unload( HFreeImage():aImages[i]:handle )
      IF HFreeImage():aImages[i]:hBitmap != Nil
         DELETEObject( HFreeImage():aImages[i]:hBitmap )
      ENDIF
   NEXT
   FI_End()

   RETURN

