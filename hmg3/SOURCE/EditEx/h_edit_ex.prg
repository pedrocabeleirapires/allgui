/*
 * Implementaci�n del comando EDIT EXTENDED para la librer�a HMG.
 * (c) Crist�bal Moll� [cemese@terra.es]

 This program is free software; you can redistribute it and/or modify it under 
 the terms of the GNU General Public License as published by the Free Software 
 Foundation; either version 2 of the License, or (at your option) any later 
 version. 

 This program is distributed in the hope that it will be useful, but WITHOUT 
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with 
 this software; see the file COPYING. If not, write to the Free Software 
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA (or 
 visit the web site http://www.gnu.org/).

 As a special exception, you have permission for additional uses of the text 
 contained in this file.

 The exception is that, if you link this code with other 
 files to produce an executable, this does not by itself cause the resulting 
 executable to be covered by the GNU General Public License.
 Your use of that executable is in no way restricted on account of linking  
 this code into it.

 *
 * - Descripci�n -
 * ===============
 *      EDIT EXTENDED, es un comando que permite realizar el mantenimiento de una bdd. En principio
 *      est� dise�ado para administrar bases de datos que usen los divers DBFNTX y DBFCDX,
 *      presentando otras bases de datos con diferentes drivers resultados inesperados.
 *
 * - Sint�xis -
 * ============
 *      Todos los par�metros del comando EDIT son opcionales.
 *
 *      EDIT EXTENDED                           ;
 *       [ WORKAREA cWorkArea ]                 ;
 *       [ TITLE cTitle ]                       ;
 *       [ FIELDNAMES acFieldNames ]            ;
 *       [ FIELDMESSAGES acFieldMessages ]      ;
 *       [ FIELDENABLED alFieldEnabled ]        ;
 *       [ TABLEVIEW alTableView ]              ;
 *       [ OPTIONS aOptions ]                   ;
 *       [ ON SAVE bSave ]                      ;
 *       [ ON FIND bFind ]                      ;
 *       [ ON PRINT bPrint ]
 *
 *      Si no se pasa ning�n par�metro, el comando EDIT toma como bdd de trabajo la del
 *      area de trabajo actual.
 *
 *      [cWorkArea]             Cadena de texto con el nombre del alias de la base de datos
 *                              a editar. Por defecto el alias de la base de datos activa.
 *      [cTitle]                Cadena de texto con el t�tulo de la ventana de visualizaci�n
 *                              de registros. Por defecto se toma el alias de la base de datos
 *                              activa.
 *      [acFieldNames]          Matriz de cadenas de texto con el nombre descriptivo de los
 *                              campos de la base de datos. Tiene que tener el mismo n�mero
 *                              de elementos que campos la bdd. Por defecto se toma el nombre
 *                              de los campos de la estructura de la bdd.
 *      [acFieldMessages]       Matriz de cadenas de texto con el texto que aparaecer� en la
 *                              barra de estado cuando se este a�adiento o editando un registro.
 *                              Tiene que tener el mismo numero de elementos que campos la bdd.
 *                              Por defecto se rellena con valores internos.
 *      [alFieldEnabled]        Matriz de valores l�gicos que indica si el campo referenciado
 *                              por la matriz esta activo durante la edici�n de registro. Tiene
 *                              que tener el mismo numero de elementos que campos la bdd. Por
 *                              defecto toma todos los valores como verdaderos ( .t. ).
 *      [aTableView]            Matriz de valores l�gicos que indica si el campo referenciado
 *                              por la matriz es visible en la tabla. Tiene que tener el mismo
 *                              numero de elementos que campos la bdd. Por defecto toma todos
 *                              los valores como verdaderos ( .t. ).
 *      [aOptions]              Matriz de 2 niveles. el primero de tipo texto es la descripci�n
 *                              de la opci�n. El segundo de tipo bloque de c�digo es la opci�n
 *                              a ejecutar cuando se selecciona. Si no se pasa esta variable,
 *                              se desactiva la lista desplegable de opciones.
 *      [bSave]                 Bloque de codigo con el formato {|aValores, lNuevo| Accion } que
 *                              se ejecutar� al pulsar la tecla de guardar registro. Se pasan
 *                              las variables aValores con el contenido del registro a guardar y
 *                              lNuevo que indica si se est� a�adiendo (.t.) o editando (.f.).
 *                              Esta variable ha de devolver .t. para salir del modo de edici�n.
 *                              Por defecto se graba con el c�digo de la funci�n.
 *      [bFind]                 Bloque de codigo a ejecutar cuando se pulsa la tecla de busqueda.
 *                              Por defecto se usa el c�digo de la funci�n.
 *      [bPrint]                Bloque de c�digo a ejecutar cuando se pulsa la tecla de listado.
 *                              Por defecto se usa el codigo de la funci�n.
 *
 *      Ver DEMO.PRG para ejemplo de llamada al comando.
 *
 *
 * - Historial -
 * =============
 *      Mar 03  - Definici�n de la funci�n.
 *              - Pruebas.
 *              - Soporte para lenguaje en ingl�s.
 *              - Corregido bug al borrar en bdds con CDX.
 *              - Mejora del control de par�metros.
 *              - Mejorada la funci�n de de busqueda.
 *              - Soprte para multilenguaje.
 *              - Versi�n 1.0 lista.
 *      Abr 03  - Corregido bug en la funci�n de busqueda (Nombre del bot�n).
 *              - A�adido soporte para idioma Ruso (Grigory Filiatov).
 *              - A�adido soporte para idioma Catal�n (Por corregir).
 *              - A�adido soporte para idioma Portugu�s (Clovis Nogueira Jr).
 *              - A�adido soporte para idioma Polaco (Janusz Poura).
 *              - A�adido soporte para idioma Franc�s (C. Jouniauxdiv).
 *      May 03  - A�adido soporte para idioma Italiano (Lupano Piero).
 *              - A�adido soporte para idioma Alem�n (Janusz Poura).
 *              - Cambio del formato de llamada al comando.
 *              - La creaci�n de ventanas se realiza en funci�n del alto y ancho
 *                de la pantalla.
 *              - Se elimina la restricci�n de tama�o en los nombre de etiquetas.
 *              - Se elimina la restricci�n de numero de campos del area de la bdd.
 *              - Se elimina la restricci�n de que los campos tipo MEMO tienen que ir
 *                al final de la base de datos.
 *              - Se a�ade la opci�n de visualizar comentarios en la barra de estado.
 *              - Se a�ade opci�n de control de visualizaci�n de campos en el browse.
 *              - Se modifica el par�metro nombre del area de la bdd que pasa a ser
 *                opcional.
 *              - Se a�ade la opci�n de saltar al siguiente foco mediante la pulsaci�n
 *                de la tecla ENTER (Solo a controles tipo TEXTBOX).
 *              - Se a�ade la opci�n de cambio del indice activo.
 *              - Mejora de la rutina de busqueda.
 *              - Mejora en la ventana de definici�n de listados.
 *              - Peque�os cambios en el formato del listado.
 *              - Actualizaci�n del soporte multilenguaje.
 *      Jun 03  - Pruebas de la versi�n 1.5
 *              - Se implementan las nuevas opciones de la librer�a de Ryszard Rylko
 *              - Se implementa el filtrado de la base de datos.
 *      Ago 03  - Se corrige bug en establecimiento de filtro.
 *              - Actualizado soporte para italiano (Arcangelo Molinaro).
 *              - Actualizado soporte multilenguage.
 *              - Actualizado el soporte para filtrado.
 *      Sep 03  - Idioma Vasco listo. Gracias a Gerardo Fern�ndez.
 *              - Idioma Italaino listo. Gracias a Arcangelo Molinaro.
 *              - Idioma Franc�s listo. Gracias a Chris Jouniauxdiv.
 *              - Idioma Polaco listo. Gracias a Jacek Kubica.
 *      Oct 03  - Solucionado problema con las clausulas ON FIND y ON PRINT, ahora
 *                ya tienen el efecto deseado. Gracias a Grigory Filiatov.
 *              - Se cambia la referencia a _ExtendedNavigation por _HMG_SYSDATA [ 255 ]
 *                para adecuarse a la sintaxis de la construci�n 76.
 *              - Idioma Alem�n listo. Gracias a Andreas Wiltfang.
 *      Nov 03  - Problema con dbs en set exclusive. Gracias a cas_HMG.
 *              - Problema con tablas con pocos campos. Gracias a cas_HMG.
 *              - Cambio en demo para ajustarse a nueva sintaxis RDD Harbour (DBFFPT).
 *      Dic 03  - Ajuste de la longitud del control para fecha. Gracias a Laszlo Henning.
 *      Ene 04  - Problema de bloqueo con SET DELETED ON. Gracias a Grigory Filiatov y Roberto L�pez.
 *
 *
 * - Limitaciones -
 * ================
 *      - No se pueden realizar busquedas por campos l�gico o memo.
 *      - No se pueden realizar busquedas en indices con claves compuestas, la busqueda
 *        se realiza por el primer campo de la clave compuesta.
 *
 *
 * - Por hacer -
 * =============
 *      - Implementar busqueda del siguiente registro.
 *
 *
*/


MEMVAR _HMG_SYSDATA
MEMVAR _HMG_CMACROTEMP

// Ficheros de definiciones.---------------------------------------------------
#include "hmg.ch"
#include "dbstruct.ch"

// Declaraci�n de definiciones.------------------------------------------------
// Generales.
#define ABM_CRLF                HB_OsNewLine()

// Estructura de la etiquetas.
#define ABM_LBL_LEN             5
#define ABM_LBL_NAME            1
#define ABM_LBL_ROW             2
#define ABM_LBL_COL             3
#define ABM_LBL_WIDTH           4
#define ABM_LBL_HEIGHT          5

// Estructura de los controles de edici�n.
#define ABM_CON_LEN             7
#define ABM_CON_NAME            1
#define ABM_CON_ROW             2
#define ABM_CON_COL             3
#define ABM_CON_WIDTH           4
#define ABM_CON_HEIGHT          5
#define ABM_CON_DES             6
#define ABM_CON_TYPE            7

// Tipos de controles de edici�n.
#define ABM_TEXTBOXC            1
#define ABM_TEXTBOXN            2
#define ABM_DATEPICKER          3
#define ABM_CHECKBOX            4
#define ABM_EDITBOX             5

// Estructura de las opciones de usuario.
#define ABM_OPC_TEXTO           1
#define ABM_OPC_BLOQUE          2

// Tipo de acci�n al definir las columnas del listado.
#define ABM_LIS_ADD             1
#define ABM_LIS_DEL             2

// Tipo de acci�n al definir los registros del listado.
#define ABM_LIS_SET1            1
#define ABM_LIS_SET2            2

// Declaraci�n de variables globales.------------------------------------------
static _cArea           as character            // Nombre del area de la bdd.
static _aEstructura     as array                // Estructura de la bdd.
static _aIndice         as array                // Nombre de los indices de la bdd.
static _aIndiceCampo    as array                // N�mero del campo indice.
static _nIndiceActivo   as array                // Indice activo.
static _aNombreCampo    as array                // Nombre desciptivo de los campos de la bdd.
static _aEditable       as array                // Indicador de si son editables.
static _cTitulo         as character            // T�tulo de la ventana.
static _nAltoPantalla   as numeric              // Alto de la pantalla.
static _nAnchoPantalla  as numeric              // Ancho de la pantalla.
static _aEtiqueta       as array                // Datos de las etiquetas.
static _aControl        as array                // Datos de los controles.
static _aCampoTabla     as array                // Nombre de los campos para la tabla.
static _aAnchoTabla     as array                // Anchos de los campos para la tabla.
static _aCabeceraTabla  as array                // Texto de las columnas de la tabla.
static _aAlineadoTabla  as array                // Alineaci�n de las columnas de la tabla.
static _aVisibleEnTabla as array                // Campos visibles en la tabla.
static _nControlActivo  as numeric              // Control con foco.
static _aOpciones       as array                // Opciones del usuario.
static _bGuardar        as codeblock            // Acci�n para guardar registro.
static _bBuscar         as codeblock            // Acci�n para buscar registro.
static _bImprimir       as codeblock            // Acci�n para imprimir listado.
static _lFiltro         as logical              // Indicativo de filtro activo.
static _cFiltro         as character            // Condici�n de filtro.



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM()
 * Descripci�n: Funci�n inicial. Comprueba los par�metros pasados, crea la estructura
 *              para las etiquetas y controles de edici�n y crea la ventana de visualizaci�n
 *              de registro.
 *  Par�metros: cArea           Nombre del area de la bdd. Por defecto se toma el area
 *                              actual.
 *              cTitulo         T�tulo de la ventana de edici�n. Por defecto se toma el
 *                              nombre de la base de datos actual.
 *              aNombreCampo    Matriz de valores car�cter con los nombres descriptivos de
 *                              los campos de la bdd.
 *              aAvisoCampo     Matriz con los textos que se presentar�n en la barra de
 *                              estado al editar o a�adir un registro.
 *              aEditable       Matriz de val�re l�gicos que indica si el campo referenciado
 *                              esta activo en la ventana de edici�n de registro.
 *              aVisibleEnTabla Matriz de valores l�gicos que indica la visibilidad de los
 *                              campos del browse de la ventana de edici�n.
 *              aOpciones       Matriz con los valores de las opciones de usuario.
 *              bGuardar        Bloque de c�digo para la acci�n de guardar registro.
 *              bBuscar         Bloque de c�digo para la acci�n de buscar registro.
 *              bImprimir       Bloque de c�digo para la acci�n imprimir.
 *    Devuelve: NIL
****************************************************************************************/
function ABM2( cArea, cTitulo, aNombreCampo, ;
               aAvisoCampo, aEditable, aVisibleEnTabla, ;
               aOpciones, bGuardar, bBuscar, ;
               bImprimir )

////////// Declaraci�n de variables locales.-----------------------------------
        local   i              as numeric       // Indice de iteraci�n.
        local   k              as numeric       // Indice de iteraci�n.
        local   nArea          as numeric       // Numero del area de la bdd.
        local   nRegistro      as numeric       // N�mero de regisrto de la bdd.
        local   lSalida        as logical       // Control de bucle.
        local   nVeces         as numeric       // Indice de iteraci�n.
        local   cIndice        as character     // Nombre del indice.
        local   cIndiceActivo  as character     // Nombre del indice activo.
        local   cClave         as character     // Clave del indice.
        local   nInicio        as numeric       // Inicio de la cadena de busqueda.
        local   nAnchoCampo    as numeric       // Ancho del campo actual.
        local   nAnchoEtiqueta as numeric       // Ancho m�ximo de las etiquetas.
        local   nFila          as numeric       // Fila de creaci�n del control de edici�n.
        local   nColumna       as numeric       // Columna de creaci�n del control de edici�n.
        local   aTextoOp       as numeric       // Texto de las opciones de usuario.
        local   _BakExtendedNavigation          // Estado de SET NAVIAGTION.
        Local _BackDeleted
        Local cFiltroAnt     as character     // Condici�n del filtro anterior.
        public  nImpLen


////////// Gusrdar estado actual de SET DELETED y activarlo
        _BackDeleted := set( _SET_DELETED )
        SET DELETED ON

////////// Inicializaci�n del soporte multilenguaje.---------------------------
	InitMessages()

////////// Desactivaci�n de SET NAVIGATION.------------------------------------
        _BakExtendedNavigation := _HMG_SYSDATA [ 255 ]
        _HMG_SYSDATA [ 255 ]    := .F.

////////// Control de par�metros.----------------------------------------------
        // Area de la base de datos.
        if ( ValType( cArea ) != "C" ) .or. Empty( cArea )
                _cArea := Alias()
                if _cArea == ""
                        msgExclamation( _HMG_SYSDATA [ 130 ][1], "EDIT EXTENDED" )
                        return NIL
                endif
        else
                _cArea := cArea
        endif
        _aEstructura := (_cArea)->( dbStruct() )

        // T�tulo de la ventana.
        if ( cTitulo == NIL )
                _cTitulo := _cArea
        else
                if ( Valtype( cTitulo ) != "C" )
                        _cTitulo := _cArea
                else
                        _cTitulo := cTitulo
                endif
        endif

        // Nombres de los campos.
        lSalida := .t.
        if ( ValType( aNombreCampo ) != "A" )
                lSalida := .f.
        else
                if ( HMG_LEN( aNombreCampo ) != HMG_LEN( _aEstructura ) )
                        lSalida := .f.
                else
                        for i := 1 to HMG_LEN( aNombreCampo )
                                if ValType( aNombreCampo[i] ) != "C"
                                        lSalida := .f.
                                        exit
                                endif
                        next
                endif
        endif
        if lSalida
                _aNombreCampo := aNombreCampo
        else
                _aNombreCampo := {}
                for i := 1 to HMG_LEN( _aEstructura )
                        aAdd( _aNombreCampo, HMG_UPPER( HB_ULEFT( _aEstructura[i,DBS_NAME], 1 ) ) + ;
                                             HMG_LOWER( HB_USUBSTR( _aEstructura[i,DBS_NAME], 2 ) ) )
                next
        endif

        // Texto de aviso en la barra de estado de la ventana de edici�n de registro.
        lSalida := .t.
        if ( ValType( aAvisoCampo ) != "A" )
                lSalida := .f.
        else
                if ( HMG_LEN( aAvisoCampo ) != HMG_LEN( _aEstructura ) )
                        lSalida := .f.
                else
                        for i := 1 to HMG_LEN( aAvisoCampo )
                                if Valtype( aAvisoCampo[i] ) != "C"
                                        lSalida := .f.
                                        exit
                                endif
                        next
                endif
        endif
        if !lSalida
                aAvisoCampo := {}
                for i := 1 to HMG_LEN( _aEstructura )
                        do case
                                case _aEstructura[i,DBS_TYPE] == "C"
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][2] )
                                case _aEstructura[i,DBS_TYPE] == "N"
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][3] )
                                case _aEstructura[i,DBS_TYPE] == "D"
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][4] )
                                case _aEstructura[i,DBS_TYPE] == "L"
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][5] )
                                case _aEstructura[i,DBS_TYPE] == "M"
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][6] )
                                otherwise
                                        aAdd( aAvisoCampo, _HMG_SYSDATA [ 130 ][7] )
                        endcase
                next
        endif

        // Campos visibles en la tabla de la ventana de visualizaci�n de registros.
        lSalida := .t.
        if ( Valtype( aVisibleEnTabla ) != "A" )
                lSalida := .f.
        else
                if HMG_LEN( aVisibleEnTabla ) != HMG_LEN( _aEstructura )
                        lSalida := .f.
                else
                        for i := 1 to HMG_LEN( aVisibleEnTabla )
                                if ValType( aVisibleEnTabla[i] ) != "L"
                                        lSalida := .f.
                                        exit
                                endif
                        next
                endif
        endif
        if lSalida
                _aVisibleEnTabla := aVisibleEnTabla
        else
                _aVisibleEnTabla := {}
                for i := 1 to HMG_LEN( _aEstructura )
                        aAdd( _aVisibleEnTabla, .t. )
                next
        endif

        // Estado de los campos en la ventana de edici�n de registro.
        lSalida := .t.
        if ( ValType( aEditable ) != "A" )
                lSalida := .f.
        else
                if HMG_LEN( aEditable ) != HMG_LEN( _aEstructura )
                        lSalida := .f.
                else
                        for i := 1 to HMG_LEN( aEditable )
                                if ValType( aEditable[i] ) != "L"
                                        lSalida := .f.
                                        exit
                                endif
                        next
                endif
        endif
        if lSalida
                _aEditable := aEditable
        else
                _aEditable := {}
                for i := 1 to HMG_LEN( _aEstructura )
                        aAdd( _aEditable, .t.)
                next
        endif

**** JK 104

	// Opciones del usuario.
	lSalida := .t.

	if ValType( aOpciones ) != "A" 
		lSalida := .f.
	elseif HMG_LEN(aOpciones)<1
		lSalida := .f.
	elseif HMG_LEN( aOpciones[1] ) != 2
		lSalida := .f.
	else
		for i := 1 to HMG_LEN( aOpciones )
			if ValType( aOpciones [i,ABM_OPC_TEXTO] ) != "C"
				lSalida := .f.
				exit
			endif
			if ValType( aOpciones [i,ABM_OPC_BLOQUE] ) != "B"
				lSalida := .f.
				exit
			endif
		next
	endif

**** END JK 104

        if lSalida
                _aOpciones := aOpciones
        else
                _aOpciones := {}
        endif

        // Acci�n al guardar.
        if ValType( bGuardar ) == "B"
                _bGuardar := bGuardar
        else
                _bGuardar := NIL
        endif

        // Acci�n al buscar.
        if ValType( bBuscar ) == "B"
                _bBuscar := bBuscar
        else
                _bBuscar := NIL
        endif

        // Acci�n al buscar.
        if ValType( bImprimir ) == "B"
                _bImprimir := bImprimir
        else
                _bImprimir := NIL
        endif

////////// Selecci�n del area de la bdd.---------------------------------------
        nRegistro     := (_cArea)->( RecNo() )
        nArea         := Select()
        cIndiceActivo := (_cArea)->( ordSetFocus() )
        cFiltroAnt    := (_cArea)->( dbFilter() )
        dbSelectArea( _cArea )
        (_cArea)->( dbGoTop() )

////////// Inicializaci�n de variables.----------------------------------------
        // Filtro.
        if (_cArea)->( dbFilter() ) == ""
                _lFiltro := .f.
        else
                _lFiltro := .t.
        endif
        _cFiltro := (_cArea)->( dbFilter() )

        // Indices de la base de datos.
        lSalida       := .t.
        k             := 1
        _aIndice      := {}
        _aIndiceCampo := {}
        nVeces        := 1
        aAdd( _aIndice, _HMG_SYSDATA [ 129 ][1] )
        aAdd( _aIndiceCampo, 0 )
        do while lSalida
                if ( (_cArea)->( ordName( k ) ) == "" )
                        lSalida := .f.
                else
                        cIndice := (_cArea)->( ordName( k ) )
                        aAdd( _aIndice, cIndice )
                        cClave := HMG_UPPER( (_cArea)->( ordKey( k ) ) )
                        for i := 1 to HMG_LEN( _aEstructura )
                                if nVeces <= 1
                                        nInicio := HB_UAT( _aEstructura[i,DBS_NAME], cClave )
                                        if  nInicio != 0
                                                aAdd( _aIndiceCampo, i )
                                                nVeces++
                                        endif
                                endif
                        next
                endif
                k++
                nVeces := 1
        enddo

        // Numero de indice.
        if ( (_cArea)->( ordSetFocus() ) == "" )
                _nIndiceActivo := 1
        else
                _nIndiceActivo := aScan( _aIndice, (_cArea)->( ordSetFocus() ) )
        endif

        // Tama�o de la pantalla.
        _nAltoPantalla  := getDesktopHeight()
        _nAnchoPantalla := getDesktopWidth()

        // Datos de las etiquetas y los controles de la ventana de edici�n.
        _aEtiqueta     := Array( HMG_LEN( _aEstructura ), ABM_LBL_LEN )
        _aControl      := Array( HMG_LEN( _aEstructura ), ABM_CON_LEN )
        nFila          := 10
        nColumna       := 10
        nAnchoEtiqueta := 0
        for i := 1 to HMG_LEN( _aNombreCampo )
                nAnchoEtiqueta := iif( nAnchoEtiqueta > ( HMG_LEN( _aNombreCampo[i] ) * 9 ),;
                                       nAnchoEtiqueta,;
                                       HMG_LEN( _aNombreCampo[i] ) * 9 )
        next
        for i := 1 to HMG_LEN( _aEstructura )
                _aEtiqueta[i,ABM_LBL_NAME]   := "ABM2Etiqueta" + ALLTRIM( STR( i ,4,0) )
                _aEtiqueta[i,ABM_LBL_ROW]    := nFila
                _aEtiqueta[i,ABM_LBL_COL]    := nColumna
                _aEtiqueta[i,ABM_LBL_WIDTH]  := HMG_LEN( _aNombreCampo[i] ) * 9
                _aEtiqueta[i,ABM_LBL_HEIGHT] := 25
                do case
                        case _aEstructura[i,DBS_TYPE] == "C"
                                _aControl[i,ABM_CON_NAME]   := "ABM2Control" + ALLTRIM( STR( i ,4,0) )
                                _aControl[i,ABM_CON_ROW]    := nFila
                                _aControl[i,ABM_CON_COL]    := nColumna + nAnchoEtiqueta + 20
                                _aControl[i,ABM_CON_WIDTH]  := iif( ( _aEstructura[i,DBS_LEN] * 10 ) < 50, 50, _aEstructura[i,DBS_LEN] * 10 )
                                _aControl[i,ABM_CON_HEIGHT] := 25
                                _aControl[i,ABM_CON_DES]    := aAvisoCampo[i]
                                _aControl[i,ABM_CON_TYPE]   := ABM_TEXTBOXC
                                nFila += 35
                        case _aEstructura[i,DBS_TYPE] == "D"
                                _aControl[i,ABM_CON_NAME]   := "ABM2Control" + ALLTRIM( STR( i ,4,0) )
                                _aControl[i,ABM_CON_ROW]    := nFila
                                _aControl[i,ABM_CON_COL]    := nColumna + nAnchoEtiqueta + 20
                                _aControl[i,ABM_CON_WIDTH]  := _aEstructura[i,DBS_LEN] * 10
                                _aControl[i,ABM_CON_HEIGHT] := 25
                                _aControl[i,ABM_CON_DES]    := aAvisoCampo[i]
                                _aControl[i,ABM_CON_TYPE]   := ABM_DATEPICKER
                                nFila += 35
                        case _aEstructura[i,DBS_TYPE] == "N"
                                _aControl[i,ABM_CON_NAME]   := "ABM2Control" + ALLTRIM( STR( i ,4,0) )
                                _aControl[i,ABM_CON_ROW]    := nFila
                                _aControl[i,ABM_CON_COL]    := nColumna + nAnchoEtiqueta + 20
                                _aControl[i,ABM_CON_WIDTH]  := iif( ( _aEstructura[i,DBS_LEN] * 10 ) < 50, 50, _aEstructura[i,DBS_LEN] * 10 )
                                _aControl[i,ABM_CON_HEIGHT] := 25
                                _aControl[i,ABM_CON_DES]    := aAvisoCampo[i]
                                _aControl[i,ABM_CON_TYPE]   := ABM_TEXTBOXN
                                nFila += 35
                        case _aEstructura[i,DBS_TYPE] == "L"
                                _aControl[i,ABM_CON_NAME]   := "ABM2Control" + ALLTRIM( STR( i ,4,0) )
                                _aControl[i,ABM_CON_ROW]    := nFila
                                _aControl[i,ABM_CON_COL]    := nColumna + nAnchoEtiqueta + 20
                                _aControl[i,ABM_CON_WIDTH]  := 25
                                _aControl[i,ABM_CON_HEIGHT] := 25
                                _aControl[i,ABM_CON_DES]    := aAvisoCampo[i]
                                _aControl[i,ABM_CON_TYPE]   := ABM_CHECKBOX
                                nFila += 35
                        case _aEstructura[i,DBS_TYPE] == "M"
                                _aControl[i,ABM_CON_NAME]   := "ABM2Control" + ALLTRIM( STR( i ,4,0) )
                                _aControl[i,ABM_CON_ROW]    := nFila
                                _aControl[i,ABM_CON_COL]    := nColumna + nAnchoEtiqueta + 20
                                _aControl[i,ABM_CON_WIDTH]  := 300
                                _aControl[i,ABM_CON_HEIGHT] := 70
                                _aControl[i,ABM_CON_DES]    := aAvisoCampo[i]
                                _aControl[i,ABM_CON_TYPE]   := ABM_EDITBOX
                                nFila += 80
                endcase
         next

        // Datos de la tabla de la ventana de visualizaci�n.
        _aCampoTabla    := {}
        _aAnchoTabla    := {}
        _aCabeceraTabla := {}
        _aAlineadoTabla := {}
        for i := 1 to HMG_LEN( _aEstructura )
                if _aVisibleEnTabla[i]
                        aAdd( _aCampoTabla, _cArea + "->" + _aEstructura[i, DBS_NAME] )
                        nAnchoCampo    := iif( ( _aEstructura[i,DBS_LEN] * 10 ) < 50,   ;
                                                 50,                                    ;
                                                 _aEstructura[i,DBS_LEN] * 10 )
                        nAnchoEtiqueta := HMG_LEN( _aNombreCampo[i] ) * 10
                        aAdd( _aAnchoTabla, iif( nAnchoEtiqueta > nAnchoCampo,          ;
                                                 nAnchoEtiqueta,                        ;
                                                 nAnchoCampo ) )
                        aAdd( _aCabeceraTabla, _aNombreCampo[i] )
                        aAdd( _aAlineadoTabla, iif( _aEstructura[i,DBS_TYPE] == "N",     ;
                                                    BROWSE_JTFY_RIGHT,                   ;
                                                    BROWSE_JTFY_LEFT ) )
                endif
        next

////////// Definici�n de la ventana de visualizaci�n.--------------------------
        define window wndABM2Edit               ;
                AT 60, 30                       ;
                width _nAnchoPantalla - 60      ;
                height _nAltoPantalla - 140     ;
                title _cTitulo                  ;
                modal                           ;
                nosize                          ;
                nosysmenu                       ;
                on init {|| ABM2Redibuja() }    ;
                on release {|| ABM2salir(nRegistro, cIndiceActivo, cFiltroAnt, nArea) }   ;
                font "ms sans serif" size 9

                // Define la barra de estado de la ventana de visualizaci�n.
                define statusbar font "ms sans serif" size 9
                        statusitem _HMG_SYSDATA [ 129 ][19]                           // 1
                        statusitem _HMG_SYSDATA [ 129 ][20]         width 100 raised  // 2
                        statusitem _HMG_SYSDATA [ 129 ][2] +': '     width 200 raised // 3
                end statusbar

                // Define la barra de botones de la ventana de visualizaci�n.
                define toolbar tbEdit buttonsize 90, 32 flat righttext border
                        button tbbCerrar  caption _HMG_SYSDATA [ 128 ][1]   ;
                                          picture "HMG_EDIT_CLOSE"          ;
                                          action  wndABM2Edit.Release
                        button tbbNuevo   caption _HMG_SYSDATA [ 128 ][2]               ;
                                          picture "HMG_EDIT_NEW"            ;
                                          action  {|| ABM2Editar( .t. ) }
                        button tbbEditar  caption _HMG_SYSDATA [ 128 ][3]               ;
                                          picture "HMG_EDIT_EDIT"           ;
                                          action  {|| ABM2Editar( .f. ) }
                        button tbbBorrar  caption _HMG_SYSDATA [ 128 ][4]               ;
                                          picture "HMG_EDIT_DELETE"         ;
                                          action  {|| ABM2Borrar() }
                        button tbbBuscar  caption _HMG_SYSDATA [ 128 ][5]               ;
                                          picture "HMG_EDIT_FIND"           ;
                                          action  {|| ABM2Buscar() }
                        button tbbListado caption _HMG_SYSDATA [ 128 ][6]               ;
                                          picture "HMG_EDIT_PRINT"          ;
                                          action  {|| ABM2Imprimir() }
                end toolbar

        end window

////////// Creaci�n de los controles de la ventana de visualizaci�n.-----------
        @ 45, 10 frame frmEditOpciones          ;
                of wndABM2Edit                  ;
                caption ""                      ;
                width wndABM2Edit.Width - 25    ;
                height 65
        @ 112, 10 frame frmEditTabla            ;
                of wndABM2Edit                  ;
                caption ""                      ;
                width wndABM2Edit.Width - 25    ;
                height wndABM2Edit.Height - 165
         @ 60, 20 label lblIndice               ;
                of wndABM2Edit                  ;
                value _HMG_SYSDATA [ 130 ] [26]            ;
                width 150                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 75, 20 combobox cbIndices                     ;
                of wndABM2Edit                          ;
                items _aIndice                          ;
                value _nIndiceActivo                    ;
                width 150                               ;
                font "arial" size 9                     ;
                on change {|| ABM2CambiarOrden() }
        nColumna := wndABM2Edit.Width - 175
        aTextoOp := {}
        for i := 1 to HMG_LEN( _aOpciones )
                aAdd( aTextoOp, _aOpciones[i,ABM_OPC_TEXTO] )
        next
        @ 60, nColumna label lblOpciones        ;
                of wndABM2Edit                  ;
                value _HMG_SYSDATA [ 129 ] [5]            ;
                width 150                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 75, nColumna combobox cbOpciones              ;
                of wndABM2Edit                          ;
                items aTextoOp                          ;
                value 1                                 ;
                width 150                               ;
                font "arial" size 9                     ;
                on change {|| ABM2EjecutaOpcion() }
        @ 65, (wndABM2Edit.Width / 2)-110 button btnFiltro1     ;
                of wndABM2Edit                                  ;
                caption _HMG_SYSDATA [ 128 ][10]                       ;
                action {|| ABM2ActivarFiltro() }                ;
                width 100                                       ;
                height 32                                       ;
                font "ms sans serif" size 9
        @ 65, (wndABM2Edit.Width / 2)+5 button btnFiltro2       ;
                of wndABM2Edit                                  ;
                caption _HMG_SYSDATA [ 128 ][11]                    ;
                action {|| ABM2DesactivarFiltro() }             ;
                width 100                                       ;
                height 32                                       ;
                font "ms sans serif" size 9
        @ 132, 20 browse brwABM2Edit                                                    ;
                of wndABM2Edit                                                          ;
                width wndABM2Edit.Width - 45                                            ;
                height wndABM2Edit.Height - 195                                         ;
                headers _aCabeceraTabla                                                 ;
                widths _aAnchoTabla                                                     ;
                workarea &_cArea                                                        ;
                fields _aCampoTabla                                                     ;
                value ( _cArea)->( RecNo() )                                            ;
                font "arial" size 9                                                     ;
                on change {|| (_cArea)->( dbGoto( wndABM2Edit.brwABM2Edit.Value ) ),    ;
                              ABM2Redibuja( .f. ) }                                     ;
                on dblclick ABM2Editar( .f. )                                           ;
                justify _aAlineadoTabla

        // Comprueba el estado de las opciones de usuario.
        if HMG_LEN( _aOpciones ) == 0
                wndABM2Edit.cbOpciones.Enabled := .f.
        endif

////////// Activaci�n de la ventana de visualizaci�n.--------------------------
        activate window wndABM2Edit

////////// Restauraci�n de SET NAVIGATION.-------------------------------------
        _HMG_SYSDATA [ 255 ] := _BakExtendedNavigation

////////// Restaurar SET DELETED a su valor inicial

        set( _SET_DELETED , _BackDeleted  )

return NIL


/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2salir()
 * Descripci�n: Cierra la ventana de visualizaci�n de registros y sale.
 *  Par�metros: Ninguno.
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2salir( nRegistro, cIndiceActivo, cFiltroAnt, nArea )

////////// Declaraci�n de variables locales.-----------------------------------
        local bFiltroAnt as codeblock           // Bloque de c�digo del filtro.

////////// Inicializaci�n de variables.----------------------------------------
        bFiltroAnt := iif( Empty( cFiltroAnt ),;
                           &("{||NIL}"),;
                           &("{||" + cFiltroAnt + "}") )

////////// Restaura el area de la bdd inicial.---------------------------------
        (_cArea)->( dbGoTo( nRegistro ) )
        (_cArea)->( ordSetFocus( cIndiceActivo ) )
        (_cArea)->( dbSetFilter( bFiltroAnt, cFiltroAnt ) )
        dbSelectArea( nArea )

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Redibuja()
 * Descripci�n: Actualizaci�n de la ventana de visualizaci�n de registros.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2Redibuja( lTabla )

////////// Control de par�metros.----------------------------------------------
        if ValType( lTabla ) != "L"
                lTabla := .f.
        endif

////////// Refresco de la barra de botones.------------------------------------
        if (_cArea)->( RecCount() ) == 0
                wndABM2Edit.tbbEditar.Enabled  := .f.
                wndABM2Edit.tbbBorrar.Enabled  := .f.
                wndABM2Edit.tbbBuscar.Enabled  := .f.
                wndABM2Edit.tbbListado.Enabled := .f.
        else
                wndABM2Edit.tbbEditar.Enabled  := .t.
                wndABM2Edit.tbbBorrar.Enabled  := .t.
                wndABM2Edit.tbbBuscar.Enabled  := .t.
                wndABM2Edit.tbbListado.Enabled := .t.
        endif

////////// Refresco de la barra de estado.-------------------------------------
        wndABM2Edit.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 129 ][19] + _cFiltro
        wndABM2Edit.StatusBar.Item( 2 ) := _HMG_SYSDATA [ 129 ][20] + iif( _lFiltro, _HMG_SYSDATA [ 130 ][29], _HMG_SYSDATA [ 130 ][30] )
        wndABM2Edit.StatusBar.Item( 3 ) := _HMG_SYSDATA [ 129 ][2] + ': '+                                  ;
                                           ALLTRIM( STR( (_cArea)->( RecNo() ) ) ) + "/" + ;
                                           ALLTRIM( STR( (_cArea)->( RecCount() ) ) )


////////// Refresca el browse si se indica.
        if lTabla
                wndABM2Edit.brwABM2Edit.Value := (_cArea)->( RecNo() )
                wndABM2Edit.brwABM2Edit.Refresh
        endif

////////// Coloca el foco en el browse.
        wndABM2Edit.brwABM2Edit.SetFocus

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2CambiarOrden()
 * Descripci�n: Cambia el orden activo.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2CambiarOrden()

////////// Declaraci�n de variables locales.-----------------------------------
        local cIndice as character              // Nombre del indice.
        local nIndice as numeric                // N�mero del indice.

////////// Inicializa las variables.-------------------------------------------
        nIndice := wndABM2Edit.cbIndices.Value
        cIndice := wndABM2Edit.cbIndices.Item( nIndice )

////////// Cambia el orden del area de trabajo.--------------------------------
        nIndice--
        (_cArea)->( ordSetFocus( nIndice ) )
        // (_cArea)->( dbGoTop() )
        nIndice++
        _nIndiceActivo := nIndice
        ABM2Redibuja( .t. )

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2EjecutaOpcion()
 * Descripci�n: Ejecuta las opciones del usuario.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2EjecutaOpcion()

////////// Declaraci�n de variables locales.-----------------------------------
        local nItem    as numeric               // Numero del item seleccionado.
        local bBloque  as codebloc              // Bloque de codigo a ejecutar.

////////// Inicializaci�n de variables.----------------------------------------
        nItem   := wndABM2Edit.cbOpciones.Value
        bBloque := _aOpciones[nItem,ABM_OPC_BLOQUE]

////////// Ejecuta la opci�n.--------------------------------------------------
        Eval( bBloque )

////////// Refresca el browse.
        ABM2Redibuja( .t. )

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Editar( lNuevo )
 * Descripci�n: Creaci�n de la ventana de edici�n de registro.
 *  Par�metros: lNuevo          Valor l�gico que indica si se est� a�adiendo un registro
 *                              o editando el actual.
 *    Devuelve:
****************************************************************************************/
static function ABM2Editar( lNuevo )

////////// Declaraci�n de variables locales.-----------------------------------
        local i              as numeric         // Indice de iteraci�n.
        local nAnchoEtiqueta as numeric         // Ancho m�ximo de las etiquetas.
        local nAltoControl   as numeric         // Alto total de los controles de edici�n.
        local nAncho         as numeric         // Ancho de la ventana de edici�n .
        local nAlto          as numeric         // Alto de la ventana de edici�n.
        local nAnchoTope     as numeric         // Ancho m�ximo de la ventana de edici�n.
        local nAltoTope      as numeric         // Alto m�ximo de la ventana de edici�n.
        local nAnchoSplit    as numeric         // Ancho de la ventana Split.
        local nAltoSplit     as numeric         // Alto de la ventana Split.
        local cTitulo        as character       // T�tulo de la ventana.
        local cMascara       as array           // M�scara de edici�n de los controles num�ricos.
	local NANCHOCONTROL

////////// Control de par�metros.----------------------------------------------
        if ( ValType( lNuevo ) != "L" )
                lNuevo := .t.
        endif

////////// Incializaci�n de variables.-----------------------------------------
        nAnchoEtiqueta := 0
        nAnchoControl  := 0
        nAltoControl   := 0
        for i := 1 to HMG_LEN( _aEtiqueta )
                nAnchoEtiqueta := iif( nAnchoEtiqueta > _aEtiqueta[i,ABM_LBL_WIDTH],;
                                       nAnchoEtiqueta,;
                                       _aEtiqueta[i,ABM_LBL_WIDTH] )
                nAnchoControl  := iif( nAnchoControl > _aControl[i,ABM_CON_WIDTH],;
                                       nAnchoControl,;
                                       _aControl[i,ABM_CON_WIDTH] )
                nAltoControl   += _aControl[i,ABM_CON_HEIGHT] + 10
        next
        nAltoSplit  := 10 + nAltoControl + 10 + 15
        nAnchoSplit := 10 + nAnchoEtiqueta + 10 + nAnchoControl + 10 + 15
        nAlto       := 15 + 65 + nAltoSplit + 15
        nAltoTope   := _nAltoPantalla - 130
        nAncho      := 15 + nAnchoSplit + 15
        nAncho      := iif( nAncho < 300, 300, nAncho )
        nAnchoTope  := _nAnchoPantalla - 60
        cTitulo     := iif( lNuevo, _HMG_SYSDATA [ 129 ][6], _HMG_SYSDATA [ 129 ][7] )

////////// Define la ventana de edici�n de registro.---------------------------
        define window wndABM2EditNuevo                                  ;
                AT 70, 40                                               ;
                width iif( nAncho > nAnchoTope, nAnchoTope, nAncho )    ;
                height iif( nAlto > nAltoTope, nAltoTope, nAlto )       ;
                title cTitulo                                           ;
                modal                                                   ;
                nosize                                                  ;
                nosysmenu                                               ;
                font "ms sans serif" size 9

                // Define la barra de estado de la ventana de edici�n de registro.
                define statusbar font "ms sans serif" size 9
                        statusitem ""
                end statusbar

                define splitbox

                        // Define la barra de botones de la ventana de edici�n de registro.
                        define toolbar tbEditNuevo buttonsize 90, 32 flat righttext
                                button tbbCancelar caption _HMG_SYSDATA [ 128 ][7]              ;
                                                   picture "HMG_EDIT_CANCEL"        ;
                                                   action  wndABM2EditNuevo.Release
                                button tbbAceptar  caption _HMG_SYSDATA [ 128 ][8]              ;
                                                   picture "HMG_EDIT_OK"            ;
                                                   action  ABM2EditarGuardar( lNuevo )
                                button tbbCopiar   caption _HMG_SYSDATA [ 128 ][9]              ;
                                                   picture "HMG_EDIT_COPY"          ;
                                                   action  ABM2EditarCopiar()
                        end toolbar

                        // Define la ventana donde van contenidos los controles de edici�n.
                        define window wndABM2EditNuevoSplit             ;
                                width iif( nAncho > nAnchoTope,         ;
                                           nAnchoTope - 10,             ;
                                           nAnchoSplit  - 1 )           ;
                                height iif( nAlto > nAltoTope,          ;
                                            nAltoTope - 95,             ;
                                            nAltoSplit - 1 )            ;
                                virtual width nAnchoSplit               ;
                                virtual height nAltoSplit               ;
                                splitchild                              ;
                                nocaption                               ;
                                font "ms sans serif" size 9             ;
                                focused
                        end window
                end splitbox
        end window

////////// Define las etiquetas de los controles.------------------------------
        for i := 1 to HMG_LEN( _aEtiqueta )

                _HMG_cMacroTemp := _aEtiqueta[i,ABM_LBL_NAME]

                @ _aEtiqueta[i,ABM_LBL_ROW], _aEtiqueta[i,ABM_LBL_COL]  ;
                        label &_HMG_cMacroTemp ;
                        of wndABM2EditNuevoSplit                        ;
                        value _aNombreCampo[i]                          ;
                        width _aEtiqueta[i,ABM_LBL_WIDTH]               ;
                        height _aEtiqueta[i,ABM_LBL_HEIGHT]             ;
                        font "ms sans serif" size 9
        next

////////// Define los controles de edici�n.------------------------------------
        for i := 1 to HMG_LEN( _aControl )
                do case
                        case _aControl[i,ABM_CON_TYPE] == ABM_TEXTBOXC

                                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                        textbox &_HMG_cMacroTemp                      ;
                                        of wndABM2EditNuevoSplit                        ;
                                        value ""                                        ;
                                        height _aControl[i,ABM_CON_HEIGHT]              ;
                                        width _aControl[i,ABM_CON_WIDTH]                ;
                                        font "arial" size 9                             ;
                                        maxlength _aEstructura[i,DBS_LEN]               ;
                                        on gotfocus ABM2ConFoco()                       ;
                                        on lostfocus ABM2SinFoco()                      ;
                                        on enter ABM2AlEntrar( )
                        case _aControl[i,ABM_CON_TYPE] == ABM_DATEPICKER
                                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                        datepicker &_HMG_cMacroTemp           ;
                                        of wndABM2EditNuevoSplit                        ;
                                        height _aControl[i,ABM_CON_HEIGHT]              ;
                                        width _aControl[i,ABM_CON_WIDTH] + 25           ;
                                        font "arial" size 9                             ;
					SHOWNONE 					;
                                        on gotfocus ABM2ConFoco()                       ;
                                        on lostfocus ABM2SinFoco()
                        case _aControl[i,ABM_CON_TYPE] == ABM_TEXTBOXN
                                if ( _aEstructura[i,DBS_DEC] == 0 )
                                        _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                        @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                                textbox &_HMG_cMacroTemp           ;
                                                of wndABM2EditNuevoSplit                        ;
                                                value ""                                        ;
                                                height _aControl[i,ABM_CON_HEIGHT]              ;
                                                width _aControl[i,ABM_CON_WIDTH]                ;
                                                numeric                                         ;
                                                font "arial" size 9                             ;
                                                maxlength _aEstructura[i,DBS_LEN]               ;
                                                on gotfocus ABM2ConFoco( i )                    ;
                                                on lostfocus ABM2SinFoco( i )                   ;
                                                on enter ABM2AlEntrar()
                                else
                                        cMascara := ""
                                        cMascara := REPLICATE( "9", _aEstructura[i,DBS_LEN] -   ;
                                                            ( _aEstructura[i,DBS_DEC] + 1 ) )
                                        cMascara += "."
                                        cMascara += REPLICATE( "9", _aEstructura[i,DBS_DEC] )
                                        _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                        @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                                textbox &_HMG_cMacroTemp              ;
                                                of wndABM2EditNuevoSplit                        ;
                                                value ""                                        ;
                                                height _aControl[i,ABM_CON_HEIGHT]              ;
                                                width _aControl[i,ABM_CON_WIDTH]                ;
                                                numeric                                         ;
                                                inputmask cMascara                              ;
                                                on gotfocus ABM2ConFoco()                       ;
                                                on lostfocus ABM2SinFoco()                      ;
                                                on enter ABM2AlEntrar()
                                endif
                        case _aControl[i,ABM_CON_TYPE] == ABM_CHECKBOX
                                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                        checkbox &_HMG_cMacroTemp             ;
                                        of wndABM2EditNuevoSplit                        ;
                                        caption ""                                      ;
                                        height _aControl[i,ABM_CON_HEIGHT]              ;
                                        width _aControl[i,ABM_CON_WIDTH]                ;
                                        value .f.                                       ;
                                        on gotfocus ABM2ConFoco()                       ;
                                        on lostfocus ABM2SinFoco()
                        case _aControl[i,ABM_CON_TYPE] == ABM_EDITBOX
                                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                @ _aControl[i,ABM_CON_ROW], _aControl[i,ABM_CON_COL]    ;
                                        editbox &_HMG_cMacroTemp              ;
                                        of wndABM2EditNuevoSplit                        ;
                                        width _aControl[i,ABM_CON_WIDTH]                ;
                                        height _aControl[i,ABM_CON_HEIGHT]              ;
                                        value ""                                        ;
                                        font "arial" size 9                             ;
                                        on gotfocus ABM2ConFoco()                       ;
                                        on lostfocus ABM2SinFoco()
                endcase
        next

////////// Actualiza los controles si se est� editando.------------------------
        if !lNuevo
                for i := 1 to HMG_LEN( _aControl )
                        _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                        wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).Value := ;
                                                      (_cArea)->( FieldGet( i ) )
                next
        endif

////////// Establece el estado inicial de los controles.-----------------------
        for i := 1 to HMG_LEN( _aControl )
                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).Enabled := _aEditable[i]
        next

////////// Establece el estado del bot�n de copia.-----------------------------
        if !lNuevo
                wndABM2EditNuevo.tbbCopiar.Enabled := .f.
        endif

////////// Activa la ventana de edici�n de registro.---------------------------
        activate window wndABM2EditNuevo

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2ConFoco()
 * Descripci�n: Actualiza las etiquetas de los controles y presenta los mensajes en la
 *              barra de estado de la ventana de edici�n de registro al obtener un
 *              control de edici�n el foco.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2ConFoco()

////////// Declaraci�n de variables locales.-----------------------------------
        local i         as numeric              // Indice de iteraci�n.
        local cControl  as character            // Nombre del control activo.
        local acControl as array                // Matriz con los nombre de los controles.

////////// Inicializaci�n de variables.----------------------------------------
        cControl := This.Name
        acControl := {}
        for i := 1 to HMG_LEN( _aControl )
                aAdd( acControl, _aControl[i,ABM_CON_NAME] )
        next
        _nControlActivo := aScan( acControl, cControl )

////////// Pone la etiqueta en negrita.----------------------------------------
        _HMG_cMacroTemp := _aEtiqueta[_nControlActivo,ABM_LBL_NAME]
        wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).FontBold := .t.

////////// Presenta el mensaje en la barra de estado.--------------------------
        wndABM2EditNuevo.StatusBar.Item( 1 ) := _aControl[_nControlActivo,ABM_CON_DES]

return nil



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2SinFoco()
 * Descripci�n: Restaura el estado de las etiquetas y de la barra de estado de la ventana
 *              de edici�n de registros al dejar un control de edici�n sin foco.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2SinFoco()

////////// Restaura el estado de la etiqueta.----------------------------------
        _HMG_cMacroTemp := _aEtiqueta[_nControlActivo,ABM_LBL_NAME]
        wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).FontBold := .f.

////////// Restaura el texto de la barra de estado.----------------------------
        wndABM2EditNuevo.StatusBar.Item( 1 ) := ""

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2AlEntrar()
 * Descripci�n: Cambia al siguiente control de edici�n tipo TEXTBOX al pulsar la tecla
 *              ENTER.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2AlEntrar()

////////// Declaraci�n de variables locales.-----------------------------------
        local lSalida   as logical              // * Tipo de salida.
        local nTipo     as numeric              // * Tipo del control.

////////// Inicializa las variables.-------------------------------------------
        lSalida  := .t.

////////// Restaura el estado de la etiqueta.----------------------------------
        _HMG_cMacroTemp := _aEtiqueta[_nControlActivo,ABM_LBL_NAME]
        wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).FontBold := .f.

////////// Activa el siguiente control editable con evento ON ENTER.-----------
        do while lSalida
                _nControlActivo++
                if _nControlActivo > HMG_LEN( _aControl )
                        _nControlActivo := 1
                endif
                nTipo := _aControl[_nControlActivo,ABM_CON_TYPE]
                if nTipo == ABM_TEXTBOXC .or. nTipo == ABM_TEXTBOXN
                        if _aEditable[_nControlActivo]
                                lSalida := .f.
                        endif
                endif
        enddo
        _HMG_cMacroTemp := _aControl[_nControlActivo,ABM_CON_NAME]
        wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).SetFocus

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2EditarGuardar( lNuevo )
 * Descripci�n: A�ade o guarda el registro en la bdd.
 *  Par�metros: lNuevo          Valor l�gico que indica si se est� a�adiendo un registro
 *                              o editando el actual.
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2EditarGuardar( lNuevo )

////////// Declaraci�n de variables locales.-----------------------------------
        local i          as numeric             // * Indice de iteraci�n.
        local xValor                            // * Valor a guardar.
        local lResultado as logical             // * Resultado del bloque del usuario.
        local aValores   as array               // * Valores del registro.

////////// Guarda el registro.-------------------------------------------------
        if _bGuardar == NIL

                // No hay bloque de c�digo del usuario.
                if lNuevo
                        (_cArea)->( dbAppend() )
                endif

                if (_cArea)->(rlock())

                    for i := 1 to HMG_LEN( _aEstructura )
                            _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                            xValor := wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).Value
                            (_cArea)->( FieldPut( i, xValor ) )
                    next

                    Unlock

                      // Refresca la ventana de visualizaci�n.
                    wndABM2EditNuevo.Release
                    ABM2Redibuja( .t. )

                else
                        Msgstop ('Record locked by another user')
                endif
        else

                // Hay bloque de c�digo del usuario.
                aValores := {}
                for i := 1 to HMG_LEN( _aControl )
                        _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                        xValor := wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).Value
                        aAdd( aValores, xValor )
                next
                lResultado := Eval( _bGuardar, aValores, lNuevo )
                if ValType( lResultado ) != "L"
                        lResultado := .t.
                endif

                // Refresca la ventana de visualizaci�n.
                if lResultado
                        wndABM2EditNuevo.Release
                        ABM2Redibuja( .t. )
                endif
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Seleccionar()
 * Descripci�n: Presenta una ventana para la selecci�n de un registro.
 *  Par�metros: Ninguno
 *    Devuelve: [nReg]          Numero de registro seleccionado, o cero si no se ha
 *                              seleccionado ninguno.
****************************************************************************************/
static function ABM2Seleccionar()

////////// Declaraci�n de variables locales.-----------------------------------
        local lSalida   as logical              // Control de bucle.
        local nReg      as numeric              // Valores del registro
        local nRegistro as numeric              // N�mero de registro.

////////// Inicializaci�n de variables.----------------------------------------
        lSalida   := .f.
        nReg      := 0
        nRegistro := (_cArea)->( RecNo() )

////////// Se situa en el primer registro.-------------------------------------
        (_cArea)->( dbGoTop() )

////////// Creaci�n de la ventana de selecci�n de registro.--------------------
        define window wndSeleccionar            ;
                AT 0, 0                         ;
                width 500                       ;
                height 300                      ;
                title _HMG_SYSDATA [ 129 ][8]            ;
                modal                           ;
                nosize                          ;
                nosysmenu                       ;
                font "ms sans serif" size 9

                // Define la barra de botones de la ventana de selecci�n.
                define toolbar tbSeleccionar buttonsize 90, 32 flat righttext border
                        button tbbCancelarSel caption _HMG_SYSDATA [ 128 ][7]                   ;
                                              picture "HMG_EDIT_CANCEL"             ;
                                              action  {|| lSalida := .f.,               ;
                                                          nReg    := 0,                 ;
                                                          wndSeleccionar.Release }
                        button tbbAceptarSel  caption _HMG_SYSDATA [ 128 ][8]                                           ;
                                              picture "HMG_EDIT_OK"                                         ;
                                              action  {|| lSalida := .t.,                                       ;
                                                          nReg    := wndSeleccionar.brwSeleccionar.Value,       ;
                                                          wndSeleccionar.Release }
                end toolbar

                // Define la barra de estado de la ventana de selecci�n.
                define statusbar font "ms sans serif" size 9
                        statusitem _HMG_SYSDATA [ 130 ][7]
                end statusbar

                // Define la tabla de la ventana de selecci�n.
                @ 55, 20 browse brwSeleccionar                                          ;
                        width 460                                                       ;
                        height 190                                                      ;
                        headers _aCabeceraTabla                                         ;
                        widths _aAnchoTabla                                             ;
                        workarea &_cArea                                                ;
                        fields _aCampoTabla                                             ;
                        value (_cArea)->( RecNo() )                                     ;
                        font "arial" size 9                                             ;
                        on dblclick {|| lSalida := .t.,                                 ;
                                        nReg := wndSeleccionar.brwSeleccionar.Value,    ;
                                        wndSeleccionar.Release }                        ;
                        justify _aAlineadoTabla

        end window

////////// Activa la ventana de selecci�n de registro.-------------------------
        center window wndSeleccionar
        activate window wndSeleccionar

////////// Restuara el puntero de registro.------------------------------------
        (_cArea)->( dbGoTo( nRegistro ) )

return ( nReg )



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2EditarCopiar()
 * Descripci�n: Copia el registro seleccionado en los controles de edici�n del nuevo
 *              registro.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2EditarCopiar()

////////// Declaraci�n de variables locales.-----------------------------------
        local i         as numeric              // Indice de iteraci�n.
        local nRegistro as numeric              // Puntero de registro.
        local nReg      as numeric              // Numero de registro.

////////// Obtiene el registro a copiar.---------------------------------------
        nReg := ABM2Seleccionar()

////////// Actualiza los controles de edici�n.---------------------------------
        if nReg != 0
                nRegistro := (_cArea)->( RecNo() )
                (_cArea)->( dbGoTo( nReg ) )
                for i := 1 to HMG_LEN( _aControl )
                        if _aEditable[i]
                                _HMG_cMacroTemp := _aControl[i,ABM_CON_NAME]
                                wndABM2EditNuevoSplit.&(_HMG_cMacroTemp).Value := ;
                                        (_cArea)->( FieldGet( i ) )
                        endif
                next
                (_cArea)->( dbGoTo( nRegistro ) )
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Borrar()
 * Descripci�n: Borra el registro activo.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
function ABM2Borrar()

////////// Declaraci�n de variables locales.-----------------------------------

////////// Borra el registro si se acepta.-------------------------------------

        if MsgOKCancel( _HMG_SYSDATA [ 130 ][8], _HMG_SYSDATA [ 129 ][16] )
                if (_cArea)->( rlock() )
                   (_cArea)->( dbDelete() )
                   (_cArea)->( dbCommit() )
                   (_cArea)->( dbunlock() )
                   if .not. set( _SET_DELETED )
                      set deleted on
                   endif
                   (_cArea)->( dbSkip() )
                   if (_cArea)->( eof() )
                      (_cArea)->( dbGoBottom() )
                   endif
                   ABM2Redibuja( .t. )
                else
                   Msgstop( _HMG_SYSDATA [ 130 ] [41] , _cTitulo )
                endif
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Buscar()
 * Descripci�n: Busca un registro por la clave del indice activo.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2Buscar()

////////// Declaraci�n de variables locales.-----------------------------------
        local nControl   as numeric             // Numero del control.
        local lSalida    as logical             // Tipo de salida de la ventana.
        local xValor                            // Valor de busqueda.
        local cMascara   as character           // Mascara de edici�n del control.
        local lResultado as logical             // Resultado de la busqueda.
        local nRegistro  as numeric             // Numero de registro.

////////// Inicializaci�n de variables.----------------------------------------
        nControl := _aIndiceCampo[_nIndiceActivo]

////////// Comprueba si se ha pasado una acci�n del usuario.--------------------
        if _bBuscar != NIL
                // msgInfo( "ON FIND" )
                Eval( _bBuscar )
                ABM2Redibuja( .t. )
                return NIL
        endif

////////// Comprueba si hay un indice activo.----------------------------------
        if _nIndiceActivo == 1
                msgExclamation( _HMG_SYSDATA [ 130 ][9], _cTitulo )
                return NIL
        endif

////////// Comprueba que el campo indice no es del tipo memo o logico.---------
        if _aEstructura[nControl,DBS_TYPE] == "L" .or. _aEstructura[nControl,DBS_TYPE] == "M"
                msgExclamation( _HMG_SYSDATA [ 130 ][10], _cTitulo )
                return nil
        endif

////////// Crea la ventana de busqueda.----------------------------------------
        define window wndABMBuscar              ;
                AT 0, 0                         ;
                width 500                       ;
                height 170                      ;
                title _HMG_SYSDATA [ 129 ][9]            ;
                modal                           ;
                nosize                          ;
                nosysmenu                       ;
                font "ms sans serif" size 9

                // Define la barra de botones de la ventana de busqueda.
                define toolbar tbBuscar buttonsize 90, 32 flat righttext border
                        button tbbCancelarBus caption _HMG_SYSDATA [ 128 ][7]                           ;
                                              picture "HMG_EDIT_CANCEL"                     ;
                                              action  {|| lSalida := .f.,                       ;
                                                          xValor := wndABMBuscar.conBuscar.Value,  ;
                                                          wndABMBuscar.Release }
                        button tbbAceptarBus  caption _HMG_SYSDATA [ 128 ][8]                                ;
                                              picture "HMG_EDIT_OK"                         ;
                                              action  {|| lSalida := .t.,                       ;
                                                          xValor := wndABMBuscar.conBuscar.Value,  ;
                                                          wndABMBuscar.Release }
                end toolbar

                // Define la barra de estado de la ventana de busqueda.
                define statusbar font "ms sans serif" size 9
                        statusitem ""
                end statusbar
        end window

////////// Crea los controles de la ventana de busqueda.-----------------------
        // Frame.
        @ 45, 10 frame frmBuscar                        ;
                of wndABMBuscar                         ;
                caption ""                              ;
                width wndABMBuscar.Width - 25           ;
                height wndABMBuscar.Height - 100

        // Etiqueta.
        @ 60, 20 label lblBuscar                                ;
                of wndABMBuscar                                 ;
                value _aNombreCampo[nControl]                   ;
                width _aEtiqueta[nControl,ABM_LBL_WIDTH]        ;
                height _aEtiqueta[nControl,ABM_LBL_HEIGHT]      ;
                font "ms sans serif" size 9

        // Tipo de dato a buscar.
        do case

                // Car�cter.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_TEXTBOXC
                        @ 75, 20  textbox conBuscar                             ;
                                of wndABMBuscar                                    ;
                                value ""                                        ;
                                height _aControl[nControl,ABM_CON_HEIGHT]       ;
                                width _aControl[nControl,ABM_CON_WIDTH]         ;
                                font "arial" size 9                             ;
                                maxlength _aEstructura[nControl,DBS_LEN]

                // Fecha.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_DATEPICKER
                        @ 75, 20 datepicker conBuscar                           ;
                                of wndABMBuscar                                    ;
                                value Date()                                    ;
                                height _aControl[nControl,ABM_CON_HEIGHT]       ;
                                width _aControl[nControl,ABM_CON_WIDTH] + 25    ;
                                font "arial" size 9

                // Numerico.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_TEXTBOXN
                        if ( _aEstructura[nControl,DBS_DEC] == 0 )

                                // Sin decimales.
                                @ 75, 20 textbox conBuscar                              ;
                                        of wndABMBuscar                                    ;
                                        value ""                                        ;
                                        height _aControl[nControl,ABM_CON_HEIGHT]       ;
                                        width _aControl[nControl,ABM_CON_WIDTH]         ;
                                        numeric                                         ;
                                        font "arial" size 9                             ;
                                        maxlength _aEstructura[nControl,DBS_LEN]
                        else

                                // Con decimales.
                                cMascara := ""
                                cMascara := REPLICATE( "9", _aEstructura[nControl,DBS_LEN] - ;
                                                       ( _aEstructura[nControl,DBS_DEC] + 1 ) )
                                cMascara += "."
                                cMascara += REPLICATE( "9", _aEstructura[nControl,DBS_DEC] )
                                @ 75, 20 textbox conBuscar                              ;
                                        of wndABMBuscar                                    ;
                                        value ""                                        ;
                                        height _aControl[nControl,ABM_CON_HEIGHT]       ;
                                        width _aControl[nControl,ABM_CON_WIDTH]         ;
                                        numeric                                         ;
                                        inputmask cMascara
                        endif
        endcase

////////// Actualiza la barra de estado.---------------------------------------
        wndABMBuscar.StatusBar.Item( 1 ) := _aControl[nControl,ABM_CON_DES]

////////// Comprueba el tama�o del control de edici�n del dato a buscar.-------
        if wndABMBuscar.conBuscar.Width > wndABM2Edit.Width - 45
                wndABMBuscar.conBuscar.Width := wndABM2Edit.Width - 45
        endif

////////// Activa la ventana de busqueda.--------------------------------------
        center window wndABMBuscar
        activate window wndABMBuscar

////////// Busca el registro.--------------------------------------------------
        if lSalida
                nRegistro := (_cArea)->( RecNo() )
                lResultado := (_cArea)->( dbSeek( xValor ) )
                if !lResultado
                        msgExclamation( _HMG_SYSDATA [ 130 ][11], _cTitulo )
                        (_cArea)->( dbGoTo( nRegistro ) )
                else
                        ABM2Redibuja( .t. )
                endif
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Filtro()
 * Descripci�n: Filtra la base de datos.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2ActivarFiltro()

////////// Declaraci�n de variables locales.-----------------------------------
        local aCompara   as array               // Comparaciones.
        local aCampos    as array               // Nombre de los campos.

////////// Comprueba que no hay ningun filtro activo.--------------------------
        if _cFiltro != ""
                MsgInfo( _HMG_SYSDATA [ 130 ][34], '' )
        endif

////////// Inicializaci�n de variables.----------------------------------------
        aCampos    := _aNombreCampo
        aCompara   := { _HMG_SYSDATA [ 129 ][27],;
                        _HMG_SYSDATA [ 129 ][28],;
                        _HMG_SYSDATA [ 129 ][29],;
                        _HMG_SYSDATA [ 129 ][30],;
                        _HMG_SYSDATA [ 129 ][31],;
                        _HMG_SYSDATA [ 129 ][32] }


////////// Crea la ventana de filtrado.----------------------------------------
        define window wndABM2Filtro                     ;
                AT 0, 0                                 ;
                width 400                               ;
                height 325                              ;
                title _HMG_SYSDATA [ 129 ][21]            ;
                modal                                   ;
                nosize                                  ;
                nosysmenu                               ;
                on init {|| ABM2ControlFiltro() }       ;
                font "ms sans serif" size 9

                // Define la barra de botones de la ventana de filtrado.
                define toolbar tbBuscar buttonsize 90, 32 flat righttext border
                        button tbbCancelarFil caption _HMG_SYSDATA [ 128 ][7]           ;
                                              picture "HMG_EDIT_CANCEL"     ;
                                              action  {|| wndABM2Filtro.Release,;
                                                          ABM2Redibuja( .f. ) }
                        button tbbAceptarFil  caption _HMG_SYSDATA [ 128 ][8]           ;
                                              picture "HMG_EDIT_OK"         ;
                                              action  {|| ABM2EstableceFiltro() }
                end toolbar

                // Define la barra de estado de la ventana de filtrado.
                define statusbar font "ms sans serif" size 9
                        statusitem ""
                end statusbar
        end window

////////// Controles de la ventana de filtrado.
        // Frame.
        @ 45, 10 frame frmFiltro                        ;
                of wndABM2Filtro                        ;
                caption ""                              ;
                width wndABM2Filtro.Width - 25          ;
                height wndABM2Filtro.Height - 100
        @ 65, 20 label lblCampos                ;
                of wndABM2Filtro                ;
                value _HMG_SYSDATA [ 129 ][22]        ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 65, 220 label lblCompara              ;
                of wndABM2Filtro                ;
                value _HMG_SYSDATA [ 129 ][23]    ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 200, 20 label lblValor                ;
                of wndABM2Filtro                ;
                value _HMG_SYSDATA [ 129 ][24]        ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 85, 20 listbox lbxCampos                      ;
                of wndABM2Filtro                        ;
                width 140                               ;
                height 100                              ;
                items aCampos                           ;
                value 1                                 ;
                font "Arial" size 9                     ;
                on change {|| ABM2ControlFiltro() }     ;
                on gotfocus wndABM2Filtro.StatusBar.Item(1) := _HMG_SYSDATA [ 129 ][25] ;
                on lostfocus wndABM2Filtro.StatusBar.Item(1) := ""
        @ 85, 220 listbox lbxCompara                    ;
                of wndABM2Filtro                        ;
                width 140                               ;
                height 100                              ;
                items aCompara                          ;
                value 1                                 ;
                font "Arial" size 9                     ;
                on gotfocus wndABM2Filtro.StatusBar.Item(1) := _HMG_SYSDATA [ 129 ][26] ;
                on lostfocus wndABM2Filtro.StatusBar.Item(1) := ""
        @ 220, 20 textbox conValor              ;
                of wndABM2Filtro                ;
                value ""                        ;
                height 25                       ;
                width 160                       ;
                font "arial" size 9             ;
                maxlength 16

////////// Activa la ventana.
        center window wndABM2Filtro
        activate window wndABM2Filtro


return NIL


/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2ControlFiltro()
 * Descripci�n: Comprueba que el filtro se puede aplicar.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2ControlFiltro()

////////// Declaraci�n de variables locales.-----------------------------------
        local nControl as numeric
        local cMascara as character
        local cMensaje as character

////////// Inicializa las variables.
        nControl := wndABM2Filtro.lbxCampos.Value

///////// Comprueba que se puede crear el control.-----------------------------
        if _aEstructura[nControl,DBS_TYPE] == "M"
                msgExclamation( _HMG_SYSDATA [ 130 ][35], _cTitulo )
                return NIL
        endif
        if nControl == 0
                msgExclamation( _HMG_SYSDATA [ 130 ][36], _cTitulo )
                return NIL
        endif

///////// Crea el nuevo control.-----------------------------------------------
        wndABM2Filtro.conValor.Release
        cMensaje := _aControl[nControl,ABM_CON_DES]
        do case

                // Car�cter.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_TEXTBOXC
                        @ 226, 20  textbox conValor                                     ;
                                of wndABM2Filtro                                        ;
                                value ""                                                ;
                                height _aControl[nControl,ABM_CON_HEIGHT]               ;
                                width _aControl[nControl,ABM_CON_WIDTH]                 ;
                                font "arial" size 9                                     ;
                                maxlength _aEstructura[nControl,DBS_LEN]                ;
                                on gotfocus wndABM2Filtro.StatusBar.Item( 1 ) :=        ;
                                            cMensaje                                    ;
                                on lostfocus wndABM2Filtro.StatusBar.Item( 1 ) := ""

                // Fecha.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_DATEPICKER
                        @ 226, 20 datepicker conValor                                   ;
                                of wndABM2Filtro                                        ;
                                value Date()                                            ;
                                height _aControl[nControl,ABM_CON_HEIGHT]               ;
                                width _aControl[nControl,ABM_CON_WIDTH] + 25            ;
                                font "arial" size 9                                     ;
                                on gotfocus wndABM2Filtro.StatusBar.Item( 1 ) :=        ;
                                            cMensaje                                    ;
                                on lostfocus wndABM2Filtro.StatusBar.Item( 1 ) := ""

                // Numerico.
                case _aControl[nControl,ABM_CON_TYPE] == ABM_TEXTBOXN
                        if ( _aEstructura[nControl,DBS_DEC] == 0 )

                                // Sin decimales.
                                @ 226, 20 textbox conValor                                      ;
                                        of wndABM2Filtro                                        ;
                                        value ""                                                ;
                                        height _aControl[nControl,ABM_CON_HEIGHT]               ;
                                        width _aControl[nControl,ABM_CON_WIDTH]                 ;
                                        numeric                                                 ;
                                        font "arial" size 9                                     ;
                                        maxlength _aEstructura[nControl,DBS_LEN]                ;
                                        on gotfocus wndABM2Filtro.StatusBar.Item( 1 ) :=        ;
                                                    cMensaje                                    ;
                                        on lostfocus wndABM2Filtro.StatusBar.Item( 1 ) := ""

                        else

                                // Con decimales.
                                cMascara := ""
                                cMascara := REPLICATE( "9", _aEstructura[nControl,DBS_LEN] - ;
                                                       ( _aEstructura[nControl,DBS_DEC] + 1 ) )
                                cMascara += "."
                                cMascara += REPLICATE( "9", _aEstructura[nControl,DBS_DEC] )
                                @ 226, 20 textbox conValor                                      ;
                                        of wndABM2Filtro                                        ;
                                        value ""                                                ;
                                        height _aControl[nControl,ABM_CON_HEIGHT]               ;
                                        width _aControl[nControl,ABM_CON_WIDTH]                 ;
                                        numeric                                                 ;
                                        inputmask cMascara                                      ;
                                        on gotfocus wndABM2Filtro.StatusBar.Item( 1 ) :=        ;
                                                    cMensaje                                    ;
                                        on lostfocus wndABM2Filtro.StatusBar.Item( 1 ) := ""
                        endif

                // Logico
                case _aControl[nControl,ABM_CON_TYPE] == ABM_CHECKBOX
                        @ 226, 20 checkbox conValor                                     ;
                                of wndABM2Filtro                                        ;
                                caption ""                                              ;
                                height _aControl[nControl,ABM_CON_HEIGHT]               ;
                                width _aControl[nControl,ABM_CON_WIDTH]                 ;
                                value .f.                                               ;
                                on gotfocus wndABM2Filtro.StatusBar.Item( 1 ) :=        ;
                                            cMensaje                                    ;
                                on lostfocus wndABM2Filtro.StatusBar.Item( 1 ) := ""

        endcase

////////// Actualiza el valor de la etiqueta.----------------------------------
        wndABM2Filtro.lblValor.Value := _aNombreCampo[nControl]

////////// Actualiza la barra de estado.---------------------------------------
        //wndABM2Filtro.StatusBar.Item( 1 ) := _aControl[nControl,ABM_CON_DES]

////////// Comprueba el tama�o del control de edici�n del dato a buscar.-------
        if wndABM2Filtro.conValor.Width > wndABM2Filtro.Width - 45
                wndABM2Filtro.conValor.Width := wndABM2Filtro.Width - 45
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2EstableceFiltro()
 * Descripci�n: Establece el filtro seleccionado.
 *  Par�metros: Ninguno.
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2EstableceFiltro()

////////// Declaraci�n de variables locales.-----------------------------------
        local aOperador  as array
        local nCampo     as numeric
        local nCompara   as numeric
        local cValor     as character

////////// Inicializaci�n de variables.----------------------------------------
        nCompara  := wndABM2Filtro.lbxCompara.Value
        nCampo    := wndABM2Filtro.lbxCampos.Value
        cValor    := HB_ValToStr( wndABM2Filtro.conValor.Value )
        aOperador := { "=", "<>", ">", "<", ">=", "<=" }

////////// Comprueba que se puede filtrar.-------------------------------------
        if nCompara == 0
                msgExclamation( _HMG_SYSDATA [ 130 ][37], _cTitulo )
                return NIL
        endif
        if nCampo == 0
                msgExclamation( _HMG_SYSDATA [ 130 ][36], _cTitulo )
                return NIL
        endif
        if cValor == ""
                msgExclamation( _HMG_SYSDATA [ 130 ][38], _cTitulo )
                return NIL
        endif
        if _aEstructura[nCampo,DBS_TYPE] == "M"
                msgExclamation( _HMG_SYSDATA [ 130 ][35], _cTitulo )
                return NIL
        endif

////////// Establece el filtro.------------------------------------------------
        do case
                case _aEstructura[nCampo,DBS_TYPE] == "C"
                    _cFiltro := "HMG_UPPER(" + _cArea + "->" + ;
                                _aEstructura[nCampo,DBS_NAME] + ")"+ ;
                                aOperador[nCompara]
                    _cFiltro += "'" + HMG_UPPER( ALLTRIM( cValor ) ) + "'"

                case _aEstructura[nCampo,DBS_TYPE] == "N"
                    _cFiltro := _cArea + "->" + ;
                                _aEstructura[nCampo,DBS_NAME] + ;
                                aOperador[nCompara]
                    _cFiltro += ALLTRIM( cValor )

                case _aEstructura[nCampo,DBS_TYPE] == "D"
                    _cFiltro := _cArea + "->" + ;
                                _aEstructura[nCampo,DBS_NAME] + ;
                                aOperador[nCompara]
                    _cFiltro += "CToD(" + "'" + cValor + "')"

                case _aEstructura[nCampo,DBS_TYPE] == "L"
                    _cFiltro := _cArea + "->" + ;
                                _aEstructura[nCampo,DBS_NAME] + ;
                                aOperador[nCompara]
                    _cFiltro += cValor
        endcase
        (_cArea)->( dbSetFilter( {|| &_cFiltro}, _cFiltro ) )
        _lFiltro := .t.
        wndABM2Filtro.Release
        ABM2Redibuja( .t. )

return NIL


/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n:
 * Descripci�n:
 *  Par�metros:
 *    Devuelve:
****************************************************************************************/
static function ABM2DesactivarFiltro()

////////// Desactiva el filtro si procede.
        if !_lFiltro
                msgExclamation( _HMG_SYSDATA [ 130 ][39], _cTitulo )
                ABM2Redibuja( .f. )
                return NIL
        endif
        if msgYesNo( _HMG_SYSDATA [ 130 ][40], _cTitulo )
                (_cArea)->( dbSetFilter( {|| NIL }, "" ) )
                _lFiltro := .f.
                _cFiltro := ""
                ABM2Redibuja( .t. )
        endif

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Imprimir()
 * Descripci�n: Presenta la ventana de recogida de datos para la definici�n del listado.
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2Imprimir()

////////// Declaraci�n de variables locales.-----------------------------------
        local aCampoBase    as array            // Campos de la bdd.
        local aCampoListado as array            // Campos del listado.
        local nRegistro     as numeric          // Numero de registro actual.
        local nCampo        as numeric          // Numero de campo.
        local cRegistro1    as character        // Valor del registro inicial.
        local cRegistro2    as character        // Valor del registro final.
        local aImpresoras   as array            // Impresoras disponibles.
	local NIMPLEN
        private hbprn

////////// Comprueba si se ha pasado la clausula ON PRINT.---------------------
        IF _bImprimir != NIL
                // msgInfo( "ON PRINT" )
                Eval( _bImprimir )
                ABM2Redibuja( .T. )
                RETURN NIL
        ENDIF

////////// Obtiene las impresoras disponibles.---------------------------------
        aImpresoras := {}
        aImpresoras := aPrinters()
        if ValType( nImpLen ) # 'N'
                nImpLen := HMG_LEN( aImpresoras )
        endif
        aSize( aImpresoras, nImpLen )

////////// Comprueba que hay un indice activo.---------------------------------
        if _nIndiceActivo == 1
                msgExclamation( _HMG_SYSDATA [ 130 ][9], _cTitulo )
                return NIL
        endif

////////// Inicializaci�n de variables.----------------------------------------
        aCampoListado := {}
        aCampoBase    := _aNombreCampo
        nRegistro     := (_cArea)->( RecNo() )

        // Registro inicial y final.
        nCampo := _aIndiceCampo[_nIndiceActivo]
        ( _cArea)->( dbGoTop() )
        cRegistro1 := HB_ValToStr( (_cArea)->( FieldGet( nCampo ) ) )
        ( _cArea)->( dbGoBottom() )
        cRegistro2 := HB_ValToStr( (_cArea)->( FieldGet( nCampo ) ) )
        (_cArea)->( dbGoTo( nRegistro ) )

////////// Definici�n de la ventana de formato de listado.---------------------
        define window wndABM2Listado            ;
                AT 0, 0                         ;
                width 390                       ;
                height 365                      ;
                title _HMG_SYSDATA [ 129 ][10]   ;
                icon "HMG_EDIT_PRINT"       ;
                modal                           ;
                nosize                          ;
                nosysmenu                       ;
                font "ms sans serif" size 9

                // Define la barra de botones de la ventana de formato de listado.
                define toolbar tbListado buttonsize 90, 32 flat righttext border
                        button tbbCancelarLis caption _HMG_SYSDATA [ 128 ][7]                   ;
                                              picture "HMG_EDIT_CANCEL"             ;
                                              action  wndABM2Listado.Release
                        button tbbAceptarLis  caption _HMG_SYSDATA [ 128 ][8]                   ;
                                              picture "HMG_EDIT_OK"                 ;
                                              action  ABM2Listado( aImpresoras )

                end toolbar

                // Define la barra de estado de la ventana de formato de listado.
                define statusbar font "ms sans serif" size 9
                        statusitem ""
                end statusbar
        end window

////////// Define los controles de edici�n de la ventana de formato de listado.-
        // Frame.
        @ 45, 10 frame frmListado                       ;
                of wndABM2Listado                       ;
                caption ""                              ;
                width wndABM2Listado.Width - 25         ;
                height wndABM2Listado.Height - 100

        // Label
        @ 65, 20 label lblCampoBase             ;
                of wndABM2Listado               ;
                value _HMG_SYSDATA [ 129 ][11]       ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 65, 220 label lblCampoListado         ;
                of wndABM2Listado               ;
                value _HMG_SYSDATA [ 129 ][12]           ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 200, 20 label lblImpresoras           ;
                of wndABM2Listado               ;
                value _HMG_SYSDATA [ 129 ][13]   ;
                width 140                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 200, 170 label lblInicial             ;
                of wndABM2Listado               ;
                value _HMG_SYSDATA [ 129 ][14]           ;
                width 160                       ;
                height 25                       ;
                font "ms sans serif" size 9
        @ 255, 170 label lblFinal               ;
                of wndABM2Listado               ;
                value _HMG_SYSDATA [ 129 ][15]           ;
                width 160                       ;
                height 25                       ;
                font "ms sans serif" size 9

        // Listbox.
        @ 85, 20 listbox lbxCampoBase                                           ;
                of wndABM2Listado                                               ;
                width 140                                                       ;
                height 100                                                      ;
                items aCampoBase                                                ;
                value 1                                                         ;
                font "Arial" size 9                                             ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][12] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""
        @ 85, 220 listbox lbxCampoListado                                       ;
                of wndABM2Listado                                               ;
                width 140                                                       ;
                height 100                                                      ;
                items aCampoListado                                             ;
                value 1                                                         ;
                font "Arial" size 9                                             ;
                on gotFocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][13];
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""

        // ComboBox.
        @ 220, 20 combobox cbxImpresoras                                        ;
                of wndABM2Listado                                               ;
                items aImpresoras                                               ;
                value 1                                                         ;
                width 140                                                       ;
                font "Arial" size 9                                             ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][14] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""

        // PicButton.
        @ 90, 170 button btnMas                                                 ;
                of wndABM2Listado                                               ;
                picture "HMG_EDIT_ADD"                                      ;
                action ABM2DefinirColumnas( ABM_LIS_ADD )                       ;
                width 40                                                        ;
                height 40                                                       ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][15] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""
        @ 140, 170 button btnMenos                                              ;
                of wndABM2Listado                                               ;
                picture "HMG_EDIT_DEL"                                      ;
                action ABM2DefinirColumnas( ABM_LIS_DEL )                       ;
                width 40                                                        ;
                height 40                                                       ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][16] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""
        @ 220, 170 button btnSet1                                               ;
                of wndABM2Listado                                               ;
                picture "HMG_EDIT_SET"                                      ;
                action ABM2DefinirRegistro( ABM_LIS_SET1 )                      ;
                width 25                                                        ;
                height 25                                                       ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][17] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""
        @ 275, 170 button btnSet2                                               ;
                of wndABM2Listado                                               ;
                picture "HMG_EDIT_SET"                                      ;
                action ABM2DefinirRegistro( ABM_LIS_SET2 )                      ;
                width 25                                                        ;
                height 25                                                       ;
                on gotfocus wndABM2Listado.StatusBar.Item( 1 ) := _HMG_SYSDATA [ 130 ][18] ;
                on lostfocus wndABM2Listado.StatusBar.Item( 1 ) := ""

        // CheckBox.

        @ 275, 20 checkbox chkPrevio            ;
                of wndABM2Listado               ;
                caption _HMG_SYSDATA [ 129 ][17]      ;
                width 140                       ;
                height 25                       ;
                value .t.                       ;
                font "ms sans serif" size 9

        // Editbox.
        @ 220, 196 textbox txtRegistro1         ;
                of wndABM2Listado               ;
                value cRegistro1                ;
                height 25                       ;
                width 160                       ;
                font "arial" size 9             ;
                maxlength 16
        @ 275, 196 textbox txtRegistro2         ;
                of wndABM2Listado               ;
                value cRegistro2                ;
                height 25                       ;
                width 160                       ;
                font "arial" size 9             ;
                maxlength 16

////////// Estado de los controles.--------------------------------------------
        wndABM2Listado.txtRegistro1.Enabled := .f.
        wndABM2Listado.txtRegistro2.Enabled := .f.

////////// Comrprueba que la selecci�n de registros es posible.----------------
        nCampo := _aIndiceCampo[_nIndiceActivo]
        if _aEstructura[nCampo,DBS_TYPE] == "L" .or. _aEstructura[nCampo,DBS_TYPE] == "M"
                wndABM2Listado.btnSet1.Enabled := .f.
                wndABM2Listado.btnSet2.Enabled := .f.
        endif

////////// Activaci�n de la ventana de formato de listado.---------------------
        center window wndABM2Listado
        activate window wndABM2Listado

////////// Restaura.-----------------------------------------------------------
        (_cArea)->( dbGoTo( nRegistro ) )
        ABM2Redibuja( .f. )

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2DefinirRegistro( nAccion )
 * Descripci�n:
 *  Par�metros:
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2DefinirRegistro( nAccion )

////////// Declaraci�n de variables locales.-----------------------------------
        local nRegistro as character            // * Puntero de registros.
        local nReg      as character            // * Registro seleccionado.
        local cValor    as character            // * Valor del registro seleccionado.
        local nCampo    as numeric              // * Numero del campo indice.

////////// Inicializa las variables.-------------------------------------------
        nRegistro := (_cArea)->( RecNo() )
        cValor    := ""

////////// Selecciona el registro.---------------------------------------------
        nReg := ABM2Seleccionar()
        if nReg == 0
                (_cArea)->( dbGoTo( nRegistro ) )
                return NIL
        else
                (_cArea)->( dbGoTo( nReg ) )
                nCampo := _aIndiceCampo[_nIndiceActivo]
                cValor := HB_ValToStr( (_cArea)->( FieldGet( nCampo ) ) )
        endif

////////// Actualiza seg�n la acci�n.------------------------------------------
        do case
                case nAccion == ABM_LIS_SET1
                        wndABM2Listado.txtRegistro1.Value := cValor
                case nAccion == ABM_LIS_SET2
                        wndABM2Listado.txtRegistro2.Value := cValor
        endcase

////////// Restaura el registro.
        (_cArea)->( dbGoTo( nRegistro ) )

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2DefinirColumnas( nAccion )
 * Descripci�n: Controla el contenido de las listas al pulsar los botones de a�adir y
 *              eliminar campos del listado.
 *  Par�metros: [nAccion]       Numerico. Indica el tipo de accion realizado.
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2DefinirColumnas( nAccion )

////////// Declaraci�n de variables locales.-----------------------------------
        local aCampoBase    as array            // * Campos de la bbd.
        local aCampoListado as array            // * Campos del listado.
        local i             as numeric          // * Indice de iteraci�n.
        local nItem         as numeric          // * Numero del item seleccionado.
	local cvalor

////////// Inicializaci�n de variables.----------------------------------------
        aCampoBase  := {}
        aCampoListado := {}
        for i := 1 to wndABM2Listado.lbxCampoBase.ItemCount
                aAdd( aCampoBase, wndABM2Listado.lbxCampoBase.Item( i ) )
        next
        for i := 1 to wndABM2Listado.lbxCampoListado.ItemCount
                aAdd( aCampoListado, wndABM2Listado.lbxCampoListado.Item( i ) )
        next

////////// Ejecuta seg�n la acci�n.--------------------------------------------
        do case
                case nAccion == ABM_LIS_ADD

                        // Obtiene la columna a a�adir.
                        nItem := wndABM2Listado.lbxCampoBase.Value
                        cValor := wndABM2Listado.lbxCampoBase.Item( nItem )

                        // Actualiza los datos de los campos de la base.
                        if HMG_LEN( aCampoBase ) == 0
                                msgExclamation( _HMG_SYSDATA [ 130 ][23], _cTitulo )
                                return NIL
                        else
                                wndABM2Listado.lbxCampoBase.DeleteAllItems
                                for i := 1 to HMG_LEN( aCampoBase )
                                        if i != nItem
                                                wndABM2Listado.lbxCampoBase.AddItem( aCampoBase[i] )
                                        endif
                                next
                                nItem := iif( nItem > 1, nItem--, 1 )
                                wndABM2Listado.lbxCampoBase.Value := nItem
                        endif

                        // Actualiza los datos de los campos del listado.
                        if Empty( cValor )
                                msgExclamation( _HMG_SYSDATA [ 130 ][23], _cTitulo )
                                return NIL
                        else
                                wndABM2Listado.lbxCampoListado.AddItem( cValor )
                                wndABM2Listado.lbxCampoListado.Value := ;
                                        wndABM2Listado.lbxCampoListado.ItemCount
                        endif
                case nAccion == ABM_LIS_DEL

                        // Obtiene la columna a quitar.
                        nItem := wndABM2Listado.lbxCampoListado.Value
                        cValor := wndABM2Listado.lbxCampoListado.Item( nItem )

                        // Actualiza los datos de los campos del listado.
                        if HMG_LEN( aCampoListado ) == 0
                                msgExclamation( _HMG_SYSDATA [ 130 ][23], _cTitulo )
                                return NIL
                        else
                                wndABM2Listado.lbxCampoListado.DeleteAllItems
                                for i := 1 to HMG_LEN( aCampoListado )
                                        if i != nItem
                                                wndABM2Listado.lbxCampoListado.AddItem( aCampoListado[i] )
                                        endif
                                next
                                nItem := iif( nItem > 1, nItem--, 1 )
                                wndABM2Listado.lbxCampoListado.Value := ;
                                        wndABM2Listado.lbxCampoListado.ItemCount
                        endif

                        // Actualiza los datos de los campos de la base.
                        if Empty( cValor )
                                msgExclamation( _HMG_SYSDATA [ 130 ][23], _cTitulo )
                                return NIL
                        else
                                wndABM2Listado.lbxCampoBase.DeleteAllItems
                                for i := 1 to HMG_LEN( _aNombreCampo )
                                        if aScan( aCampoBase, _aNombreCampo[i] ) != 0
                                                wndABM2Listado.lbxCampoBase.AddItem( _aNombreCampo[i] )
                                        endif
                                        if _aNombreCampo[i] == cValor
                                                wndABM2Listado.lbxCampoBase.AddItem( _aNombreCampo[i] )
                                        endif
                                next
                                wndABM2Listado.lbxCampoBase.Value := 1
                        endif
        endcase

return NIL



/****************************************************************************************
 *  Aplicaci�n: Comando EDIT para HMG
 *       Autor: Crist�bal Moll� [cemese@terra.es]
 *     Funci�n: ABM2Listado()
 * Descripci�n: Imprime la selecciona realizada por ABM2Imprimir()
 *  Par�metros: Ninguno
 *    Devuelve: NIL
****************************************************************************************/
static function ABM2Listado( aImpresoras )

////////// Declaraci�n de variables locales.-----------------------------------
        local i             as numeric          // * Indice de iteraci�n.
        local cCampo        as character        // * Nombre del campo indice.
        local aCampo        as array            // * Nombres de los campos.
        local nCampo        as numeric          // * Numero del campo actual.
        local nPosicion     as numeric          // * Posici�n del campo.
        local aNumeroCampo  as array            // * Numeros de los campos.
        local aAncho        as array            // * Anchos de las columnas.
        local nAncho        as array            // * Ancho de las columna actual.
        local lPrevio       as logical          // * Previsualizar.
//        local lVistas       as logical          // * Vistas en miniatura.
        local nImpresora    as numeric          // * Numero de la impresora.
        local cImpresora    as character        // * Nombre de la impresora.
        local lOrientacion  as logical          // * Orientaci�n de la p�gina.
        local lSalida       as logical          // * Control de bucle.
        local lCabecera     as logical          // * �Imprimir cabecera?.
        local nFila         as numeric          // * Numero de la fila.
        local nColumna      as numeric          // * Numero de la columna.
        local nPagina       as numeric          // * Numero de p�gina.
        local nPaginas      as numeric          // * P�ginas totales.
        local cPie          as character        // * Texto del pie de p�gina.
        local nPrimero      as numeric          // * Numero del primer registro a imprimir.
        local nUltimo       as numeric          // * Numero del ultimo registro a imprimir.
        local nTotales      as numeric          // * Registros totales a imprimir.
        local nRegistro     as numeric          // * Numero del registro actual.
        local cRegistro1    as character        // * Valor del registro inicial.
        local cRegistro2    as character        // * Valor del registro final.
        local xRegistro1                        // * Valor de comparaci�n.
        local xRegistro2                        // * Valor de comparaci�n.
	local lSuccess
	local HBPRNMAXCOL	:= 100
	LOCAL RF		:= 4
	LOCAL CF		:= 2

////////// Inicializaci�n de variables.----------------------------------------
        // Previsualizar.
        lPrevio := wndABM2Listado.chkPrevio.Value

        // Nombre de la impresora.
        nImpresora := wndABM2Listado.cbxImpresoras.Value
        if nImpresora == 0
                msgExclamation( _HMG_SYSDATA [ 130 ][32], '' )
        else
                cImpresora := aImpresoras[nImpresora]
        endif

        // Nombre del campo.
        aCampo := {}
        for i := 1 to wndABM2Listado.lbxCampoListado.ItemCount
                cCampo := wndABM2Listado.lbxCampoListado.Item( i )
                aAdd( aCampo, cCampo )
        next
        if HMG_LEN( aCampo ) == 0
                msgExclamation( _HMG_SYSDATA [ 130 ][23], _cTitulo )
                return NIL
        endif

        // N�mero del campo.
        aNumeroCampo := {}
        for i := 1 to HMG_LEN( aCampo )
                nPosicion := aScan( _aNombreCampo, aCampo[i] )
                aAdd( aNumeroCampo, nPosicion )
        next

////////// Obtiene el ancho de impresi�n.--------------------------------------
        aAncho := {}
        nAncho := 0
        for i := 1 to HMG_LEN( aNumeroCampo )
                nCampo := aNumeroCampo[i]
                do case
                        case _aEstructura[nCampo,DBS_TYPE] == "D"
                                nAncho := 9
                        case _aEstructura[nCampo,DBS_TYPE] == "M"
                                nAncho := 20
                        otherwise
                                nAncho := _aEstructura[nCampo,DBS_LEN]
                endcase
                nAncho := iif( HMG_LEN( _aNombreCampo[nCampo] ) > nAncho ,  ;
                               HMG_LEN( _aNombreCampo[nCampo] ),            ;
                               nAncho )
                aAdd( aAncho, 1 + nAncho )
        next

////////// Comprueba el ancho de impresi�n.------------------------------------
        nAncho := 0
        for i := 1 to HMG_LEN( aAncho )
                nAncho += aAncho[i]
        next
        if nAncho > 164
                MsgExclamation( _HMG_SYSDATA [ 130 ][24], _cTitulo )
                return NIL
        else
                if nAncho > 109                 // Horizontal.
                        lOrientacion := .t.
                else                            // Vertical.
                        lOrientacion := .f.
                endif
        endif

////////// Valores de inicio y fin de listado.---------------------------------
        nRegistro  := (_cArea)->( RecNo() )
        cRegistro1 := wndABM2Listado.txtRegistro1.Value
        cRegistro2 := wndABM2Listado.txtRegistro2.Value
        do case
                case _aEstructura[_aIndiceCampo[_nIndiceActivo],DBS_TYPE] == "C"
                        xRegistro1 := cRegistro1
                        xRegistro2 := cRegistro2
                case _aEstructura[_aIndiceCampo[_nIndiceActivo],DBS_TYPE] == "N"
                        xRegistro1 := Val( cRegistro1 )
                        xRegistro2 := Val( cRegistro2 )
                case _aEstructura[_aIndiceCampo[_nIndiceActivo],DBS_TYPE] == "D"
                        xRegistro1 := CToD( cRegistro1 )
                        xRegistro2 := CToD( cRegistro2 )
                case _aEstructura[_aIndiceCampo[_nIndiceActivo],DBS_TYPE] == "L"
                        xRegistro1 := iif( cRegistro1 == ".t.", .t., .f. )
                        xRegistro2 := iif( cRegistro2 == ".t.", .t., .f. )
        endcase
        (_cArea)->( dbSeek( xRegistro2 ) )
        nUltimo := (_cArea)->( RecNo() )
        (_cArea)->( dbSeek( xRegistro1 ) )
        nPrimero := (_cArea)->( RecNo() )

////////// Obtiene el n�mero de p�ginas.---------------------------------------
        nTotales := 0
        do while (_cArea)->( RecNo() ) != nUltimo .or. (_cArea)->( Eof() )
                nTotales++
                (_cArea)->( dbSkip( 1 ) )
        enddo
        if lOrientacion
                if Mod( nTotales, 33 ) == 0
                        nPaginas := Int( nTotales / 33 )
                else
                        nPaginas := Int( nTotales / 33 ) + 1
                endif
        else
                if Mod( nTotales, 55 ) == 0
                        nPaginas := Int( nTotales / 55 )
                else
                        nPaginas := Int( nTotales / 55 ) + 1
                endif
        endif
        (_cArea)->( dbGoTo( nPrimero ) )

////////// Inicializa el listado.----------------------------------------------

	// Opciones de la impresi�n.
	if lPrevio

		if lOrientacion

			SELECT PRINTER cImpresora ;
				TO lSuccess ;
				ORIENTATION PRINTER_ORIENT_LANDSCAPE ;
				PAPERSIZE PRINTER_PAPER_A4 ;
				PREVIEW

		else

			SELECT PRINTER cImpresora ;
				TO lSuccess ;
				ORIENTATION PRINTER_ORIENT_PORTRAIT ;
				PAPERSIZE PRINTER_PAPER_A4 ;
				PREVIEW

                endif

	else

		if lOrientacion

			SELECT PRINTER cImpresora ;
				TO lSuccess ;
				ORIENTATION PRINTER_ORIENT_LANDSCAPE ;
				PAPERSIZE PRINTER_PAPER_A4 

		else

			SELECT PRINTER cImpresora ;
				TO lSuccess ;
				ORIENTATION PRINTER_ORIENT_PORTRAIT ;
				PAPERSIZE PRINTER_PAPER_A4 

                endif

	 endif

	// Control de errores.
	if lSuccess == .F.
		msgExclamation( _HMG_SYSDATA [ 130 ][25], _cTitulo )
		return nil
	endif

	// Inicio del listado.
	lCabecera := .t.
	lSalida   := .t.
	nFila     := 13
	nPagina   := 1

	START PRINTDOC

		START PRINTPAGE

                        do while lSalida

                                // Cabecera el listado.
                                if lCabecera

                                        @ 5*RF, (HBPRNMAXCOL-HMG_LEN(_cTitulo)-6)*CF PRINT _cTitulo  FONT "COURIER NEW" SIZE 12 BOLD
                                        @ (6*RF) + 1 , 10*CF PRINT LINE TO (6*RF) + 1 , (HBPRNMAXCOL-5)*CF PENWIDTH 0.2

                                        @ 7*RF	, 11*CF PRINT _HMG_SYSDATA [ 130 ] [26]	FONT "COURIER NEW" SIZE 9 BOLD 
                                        @ 8*RF	, 11*CF PRINT _HMG_SYSDATA [ 130 ][27]	FONT "COURIER NEW" SIZE 9 BOLD 
                                        @ 9*RF	, 11*CF PRINT _HMG_SYSDATA [ 130 ][28]	FONT "COURIER NEW" SIZE 9 BOLD 
                                        @ 10*RF	, 11*CF PRINT _HMG_SYSDATA [ 130 ][33]	FONT "COURIER NEW" SIZE 9 BOLD 

                                        @ 7*RF	, 23*CF PRINT (_cArea)->( ordName() )	FONT "COURIER NEW" SIZE 9  
                                        @ 8*RF	, 23*CF PRINT cRegistro1		FONT "COURIER NEW" SIZE 9  
                                        @ 9*RF	, 23*CF PRINT cRegistro2		FONT "COURIER NEW" SIZE 9 
                                        @ 10*RF	, 23*CF PRINT _cFiltro			FONT "COURIER NEW" SIZE 9 

                                        nColumna := 10

                                        for i := 1 to HMG_LEN( aCampo )
                                                @ 12*RF, nColumna*CF PRINT RECTANGLE TO 12*RF, nColumna + aAncho[i] PENWIDTH 0.2 
                                                @ 12*RF, (nColumna + 1) *CF PRINT aCampo[i] FONT "COURIER NEW" SIZE 9 BOLD 
                                                nColumna += aAncho[i]
                                        next

                                        lCabecera := .f.

                                endif

                                // Registros.
                                nColumna := 10
                                for i := 1 to HMG_LEN( aNumeroCampo )
                                        nCampo := aNumeroCampo[i]
                                        do case
                                                case _aEstructura[nCampo,DBS_TYPE] == "N"

                                                        @ nFila*RF, ( nColumna + aAncho[i] ) *CF PRINT (_cArea)->( FieldGet( aNumeroCampo[i] ) ) FONT "COURIER NEW" SIZE 8 

                                                case _aEstructura[nCampo,DBS_TYPE] == "L"

                                                        @ nFila*RF, ( nColumna + 1 )  *CF PRINT iif( (_cArea)->( FieldGet( aNumeroCampo[i] ) ), _HMG_SYSDATA [ 130 ][29], _HMG_SYSDATA [ 130 ][30] ) FONT "COURIER NEW" SIZE 8 

                                                case _aEstructura[nCampo,DBS_TYPE] == "M"

                                                        @ nFila*RF, ( nColumna + 1 )  *CF PRINT HB_USUBSTR( (_cArea)->( FieldGet( aNumeroCampo[i] ) ), 1, 20 ) FONT "COURIER NEW" SIZE 8

                                                otherwise

                                                        @ nFila*RF, ( nColumna + 1 )  *CF PRINT (_cArea)->( FieldGet( aNumeroCampo[i] ) ) FONT "COURIER NEW" SIZE 8

                                        endcase

                                        nColumna += aAncho[i]

                                next

                                nFila++

                                // Comprueba el final del registro.
                                if (_cArea)->( RecNo() ) == nUltimo
                                        lSalida := .f.
                                endif
                                if (_cArea)->( EOF())
                                        lSalida := .f.
                                endif
                                (_cArea)->( dbSkip( 1 ) )

                                // Pie.
                                if lOrientacion
                                        if nFila > 44

                                                @ (46*RF) - 1 , 10 *CF  PRINT LINE TO (46*RF)-1, ( HBPRNMAXCOL - 5 ) *CF PENWIDTH 0.2 

                                                cPie := HB_ValToStr( Date() ) + " " + Time()

                                                @ 46*RF, 10 *CF  PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 


                                                cPie := "Pagina:" + " " +          ;
                                                        ALLTRIM( STR( nPagina) ) +      ;
                                                        "/" +                           ;
                                                        ALLTRIM( STR( nPaginas ) )

                                                @ 46*RF, ( HBPRNMAXCOL - HMG_LEN(cPie)-5 )  *CF PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                                                nPagina++
                                                nFila := 13
                                                lCabecera := .t.

                                                END PRINTPAGE

                                                START PRINTPAGE

                                        endif
                                else
                                        if nFila > 66

                                                @ (68*RF)-1, 10 *CF  PRINT LINE TO (68*RF)-1, ( HBPRNMAXCOL- 5 )  *CF PENWIDTH 0.2

                                                cPie := HB_ValToStr( Date() ) + " " + Time()

                                                @ 68*RF, 10 *CF PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                                                cPie := "Pagina: " +                    ;
                                                        ALLTRIM( STR( nPagina) ) +      ;
                                                        "/" +                           ;
                                                        ALLTRIM( STR( nPaginas ) )

                                                @ 68*RF, ( HBPRNMAXCOL - HMG_LEN(cPie)-5 )  *CF PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                                                nFila := 13
                                                nPagina++
                                                lCabecera := .t.

                                                END PRINTPAGE

                                                START PRINTPAGE

                                        endif

                                endif
                        enddo

                // Comprueba que se imprime el pie de la ultima hoja.----------
                if lOrientacion

                        @ (46*RF)-1, 10 *CF  PRINT LINE TO (46*RF)-1, ( HBPRNMAXCOL - 5 )  *CF PENWIDTH 0.2

                        cPie := HB_ValToStr( Date() ) + " " + Time()
                        @ 46*RF, 10 *CF  PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                        cPie := "P�gina: " +                    ;
                                ALLTRIM( STR( nPagina) ) +      ;
                                "/" +                           ;
                                ALLTRIM( STR( nPaginas ) )
                        @ 46*RF, ( HBPRNMAXCOL -HMG_LEN(cPie)-5 )  *CF PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 
                else

                        @ (68*RF)-1, 10  *CF PRINT LINE TO (68*RF)-1, ( HBPRNMAXCOL - 5 ) *CF PENWIDTH 0.2
                        cPie := HB_ValToStr( Date() ) + " " + Time()
                        @ 68*RF, 10 *CF  PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                        cPie := "P�gina: " +                    ;
                                ALLTRIM( STR( nPagina) ) +      ;
                                "/" +                           ;
                                ALLTRIM( STR( nPaginas ) )
                        @ 68*RF, ( HBPRNMAXCOL - HMG_LEN(cPie)-5)  *CF PRINT cPie FONT "COURIER NEW" SIZE 9 BOLD 

                endif


		END PRINTPAGE

	END PRINTDOC

////////// Cierra la ventana.--------------------------------------------------
        (_cArea)->( dbGoTo( nRegistro ) )
        wndABM2Listado.Release

return NIL



