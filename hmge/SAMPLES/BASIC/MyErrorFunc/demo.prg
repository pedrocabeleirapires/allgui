/*
* demo.prg - Load frmError
* ------------------------
* Para probar la captura de errores
* Adalberto del Rosario - Diciembre/2005
*/

#include "MiniGui.ch"

PROCEDURE Main()

   LOAD WINDOW frmError

   frmError.Activate

   RETURN

STATIC PROCEDURE fncSuma( )

   LOCAL oErrAntes, oErr   // oErrorAntes = Para almacenar el ErrorBlock Anterior

   LOCAL lMyError := .F.   // lMyError = .t. - Si ocurrio realmente un error, .f. - para controlar los BREAK

   LOCAL A := "UNO", B := 1, C := 0

   oErrAntes := ERRORBLOCK( { | objErr | BREAK( objErr ) } )

   BEGIN SEQUENCE

      IF MsgYesNo( "Seguro que dese continuar ?", "Pregunta" )
         C := A + B
      ELSE
         BREAK   // Si uso RETURN el compilador dice que no puedo incluirlo dentro de un BEGIN SEQUENCE
      ENDIF

   RECOVER USING oErr

      IF oErr <> NIL
         lMyError := .T.   // Especifica que realmente ha ocurrido un error

         MyErrorFunc( oErr )
      ENDIF

   END

   ERRORBLOCK( oErrAntes )

   IF lMyError
      MsgBox( "Ocurrio un error y el sistema no pudo completar la operacion", "Error" )
   ENDIF

   RETURN

   #include "fncMyError.prg"

