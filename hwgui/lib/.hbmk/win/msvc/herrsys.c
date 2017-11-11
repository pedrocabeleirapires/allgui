/*
 * Harbour 3.2.0dev (r1310312321)
 * Microsoft Visual C 16.0.40219 (32-bit)
 * Generated C source from "source\herrsys.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HWG_ERRSYS );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_STATIC( DEFERROR );
HB_FUNC_EXTERN( CURDIR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( NETERR );
HB_FUNC( HWG_ERRMSG );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( PROCNAME );
HB_FUNC_EXTERN( PROCFILE );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( PROCLINE );
HB_FUNC_EXTERN( HWG_VERSION );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( TIME );
HB_FUNC_EXTERN( MEMOWRIT );
HB_FUNC_STATIC( ERRORPREVIEW );
HB_FUNC_EXTERN( HWG_ENDWINDOW );
HB_FUNC_EXTERN( HWG_POSTQUITMESSAGE );
HB_FUNC_EXTERN( HB_ISSTRING );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC( HWG_WRITELOG );
HB_FUNC_EXTERN( FILE );
HB_FUNC_EXTERN( FCREATE );
HB_FUNC_EXTERN( FOPEN );
HB_FUNC_EXTERN( FSEEK );
HB_FUNC_EXTERN( FWRITE );
HB_FUNC_EXTERN( FCLOSE );
HB_FUNC_EXTERN( HDIALOG );
HB_FUNC_EXTERN( HEDIT );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_EXTERN( HBUTTON );
HB_FUNC_EXTERN( HWG_ENDDIALOG );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HERRSYS )
{ "HWG_ERRSYS", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ERRSYS )}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "DEFERROR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( DEFERROR )}, NULL },
{ "CURDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CURDIR )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "GENCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CANDEFAULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NETERR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NETERR )}, NULL },
{ "HWG_ERRMSG", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ERRMSG )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "PROCNAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCNAME )}, NULL },
{ "PROCFILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCFILE )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "PROCLINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCLINE )}, NULL },
{ "HWG_VERSION", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_VERSION )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "TIME", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIME )}, NULL },
{ "MEMOWRIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( MEMOWRIT )}, NULL },
{ "ERRORPREVIEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ERRORPREVIEW )}, NULL },
{ "HWG_ENDWINDOW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ENDWINDOW )}, NULL },
{ "HWG_POSTQUITMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_POSTQUITMESSAGE )}, NULL },
{ "SEVERITY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ISSTRING", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISSTRING )}, NULL },
{ "SUBSYSTEM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "SUBCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DESCRIPTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FILENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPERATION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_WRITELOG", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_WRITELOG )}, NULL },
{ "FILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILE )}, NULL },
{ "FCREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCREATE )}, NULL },
{ "FOPEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( FOPEN )}, NULL },
{ "FSEEK", {HB_FS_PUBLIC}, {HB_FUNCNAME( FSEEK )}, NULL },
{ "FWRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FWRITE )}, NULL },
{ "FCLOSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCLOSE )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HDIALOG )}, NULL },
{ "HEDIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HEDIT )}, NULL },
{ "HWG_SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SENDMESSAGE )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBUTTON )}, NULL },
{ "HWG_ENDDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ENDDIALOG )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HERRSYS, "source\\herrsys.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HERRSYS
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HERRSYS )
   #include "hbiniseg.h"
#endif

HB_FUNC( HWG_ERRSYS )
{
	static const HB_BYTE pcode[] =
	{
		116,48,0,36,20,0,176,1,0,89,15,0,1,0,
		0,0,176,2,0,95,1,12,1,6,20,1,36,21,
		0,106,2,92,0,176,3,0,12,0,72,176,4,0,
		176,3,0,12,0,12,1,28,7,106,1,0,25,6,
		106,2,92,0,72,82,1,0,36,23,0,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( DEFERROR )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,116,48,0,36,32,0,48,5,0,95,1,
		112,0,92,5,8,28,8,36,33,0,121,110,7,36,
		39,0,48,5,0,95,1,112,0,92,21,8,28,38,
		48,6,0,95,1,112,0,92,32,8,28,26,48,7,
		0,95,1,112,0,28,17,36,40,0,176,8,0,120,
		20,1,36,41,0,9,110,7,36,46,0,48,5,0,
		95,1,112,0,92,40,8,28,26,48,7,0,95,1,
		112,0,28,17,36,47,0,176,8,0,120,20,1,36,
		48,0,9,110,7,36,51,0,176,9,0,95,1,12,
		1,80,2,36,52,0,176,4,0,48,6,0,95,1,
		112,0,12,1,31,44,36,53,0,106,12,40,68,79,
		83,32,69,114,114,111,114,32,0,176,10,0,176,11,
		0,48,6,0,95,1,112,0,12,1,12,1,72,106,
		2,41,0,72,80,3,36,56,0,176,4,0,48,6,
		0,95,1,112,0,12,1,31,16,36,57,0,96,2,
		0,106,2,32,0,95,3,72,135,36,60,0,92,2,
		80,4,36,61,0,176,4,0,176,12,0,95,4,12,
		1,12,1,31,81,36,62,0,96,2,0,106,15,13,
		10,67,97,108,108,101,100,32,102,114,111,109,32,0,
		176,13,0,95,4,12,1,72,106,3,45,62,0,72,
		176,12,0,95,4,12,1,72,106,2,40,0,72,176,
		14,0,176,11,0,176,15,0,95,4,174,4,0,12,
		1,12,1,12,1,72,106,2,41,0,72,135,25,162,
		36,67,0,96,2,0,106,3,13,10,0,135,36,69,
		0,96,2,0,106,3,13,10,0,176,16,0,122,12,
		1,72,135,36,70,0,96,2,0,106,8,13,10,68,
		97,116,101,58,0,176,17,0,176,18,0,12,0,12,
		1,72,135,36,71,0,96,2,0,106,8,13,10,84,
		105,109,101,58,0,176,19,0,12,0,72,135,36,74,
		0,176,20,0,103,1,0,106,10,69,114,114,111,114,
		46,108,111,103,0,72,95,2,20,2,36,76,0,176,
		21,0,95,2,20,1,36,77,0,176,22,0,20,0,
		36,78,0,176,23,0,121,20,1,36,80,0,9,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_ERRMSG )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,87,0,48,24,0,95,1,112,0,122,
		15,28,12,106,6,69,114,114,111,114,0,25,12,106,
		8,87,97,114,110,105,110,103,0,106,2,32,0,72,
		80,2,36,90,0,176,25,0,48,26,0,95,1,112,
		0,12,1,28,18,36,91,0,96,2,0,48,26,0,
		95,1,112,0,135,25,15,36,93,0,96,2,0,106,
		4,63,63,63,0,135,36,97,0,176,27,0,48,28,
		0,95,1,112,0,12,1,106,2,78,0,8,28,33,
		36,98,0,96,2,0,106,2,47,0,176,10,0,176,
		11,0,48,28,0,95,1,112,0,12,1,12,1,72,
		135,25,16,36,100,0,96,2,0,106,5,47,63,63,
		63,0,135,36,104,0,176,25,0,48,29,0,95,1,
		112,0,12,1,28,22,36,105,0,96,2,0,106,3,
		32,32,0,48,29,0,95,1,112,0,72,135,36,110,
		0,176,4,0,48,30,0,95,1,112,0,12,1,31,
		24,36,111,0,96,2,0,106,3,58,32,0,48,30,
		0,95,1,112,0,72,135,25,39,36,112,0,176,4,
		0,48,31,0,95,1,112,0,12,1,31,22,36,113,
		0,96,2,0,106,3,58,32,0,48,31,0,95,1,
		112,0,72,135,36,122,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_WRITELOG )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,116,48,0,36,127,0,103,1,0,95,2,
		100,8,28,12,106,6,97,46,108,111,103,0,25,4,
		95,2,72,80,2,36,128,0,176,33,0,95,2,12,
		1,31,16,36,129,0,176,34,0,95,2,12,1,80,
		3,25,15,36,131,0,176,35,0,95,2,122,12,2,
		80,3,36,133,0,176,36,0,95,3,121,92,2,20,
		3,36,134,0,176,37,0,95,3,95,1,106,2,10,
		0,72,20,2,36,135,0,176,38,0,95,3,20,1,
		36,137,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ERRORPREVIEW )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,143,0,48,39,0,176,40,0,12,0,
		92,11,100,92,92,92,61,93,244,1,93,244,1,106,
		10,69,114,114,111,114,46,108,111,103,0,100,100,100,
		100,100,100,100,100,9,100,100,9,100,100,9,100,100,
		9,112,25,80,2,36,147,0,48,39,0,176,41,0,
		12,0,100,100,95,1,100,97,4,8,48,0,92,10,
		92,10,93,224,1,93,184,1,100,100,100,100,89,27,
		0,0,0,1,0,3,0,176,42,0,48,43,0,95,
		255,112,0,93,177,0,121,121,12,4,6,100,100,97,
		128,255,255,0,121,100,9,100,9,100,100,100,112,25,
		80,3,48,44,0,95,3,106,6,111,69,100,105,116,
		0,112,1,73,36,149,0,48,39,0,176,45,0,12,
		0,100,100,100,93,200,0,93,204,1,92,100,92,32,
		106,6,67,108,111,115,101,0,100,100,100,100,90,8,
		176,46,0,12,0,6,100,100,100,112,16,73,36,151,
		0,48,47,0,95,2,112,0,73,36,152,0,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,48,0,1,0,116,48,0,106,1,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

