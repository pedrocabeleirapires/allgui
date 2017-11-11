/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\hsplash.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HSPLASH );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( HSPLASH_CREATE );
HB_FUNC_STATIC( HSPLASH_COUNTSECONDS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HBITMAP );
HB_FUNC_EXTERN( HDIALOG );
HB_FUNC_EXTERN( HSAYBMP );
HB_FUNC_EXTERN( HTIMER );
HB_FUNC_EXTERN( ENDDIALOG );
HB_FUNC_EXTERN( GETMODALHANDLE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HSPLASH )
{ "HSPLASH", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLASH )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HSPLASH_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLASH_CREATE )}, NULL },
{ "HSPLASH_COUNTSECONDS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLASH_COUNTSECONDS )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ADDFILE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBITMAP )}, NULL },
{ "ADDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HDIALOG )}, NULL },
{ "COUNTSECONDS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HSAYBMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSAYBMP )}, NULL },
{ "_NAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTIMER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OTIMER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HTIMER", {HB_FS_PUBLIC}, {HB_FUNCNAME( HTIMER )}, NULL },
{ "ENDDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( ENDDIALOG )}, NULL },
{ "GETMODALHANDLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETMODALHANDLE )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HSPLASH, "source\\hsplash.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HSPLASH
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HSPLASH )
   #include "hbiniseg.h"
#endif

HB_FUNC( HSPLASH )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,35,0,36,16,0,103,1,0,100,8,
		29,46,1,176,1,0,104,1,0,12,1,29,35,1,
		166,229,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,8,72,83,112,108,97,115,104,0,108,4,4,
		1,0,108,0,112,3,80,2,36,18,0,48,5,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,7,
		111,84,105,109,101,114,0,4,1,0,9,112,5,73,
		36,19,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,5,111,68,108,103,0,4,1,0,
		9,112,5,73,36,21,0,48,6,0,95,2,106,7,
		67,114,101,97,116,101,0,108,7,95,1,92,8,72,
		121,72,121,72,112,3,73,36,22,0,48,6,0,95,
		2,106,13,67,111,117,110,116,83,101,99,111,110,100,
		115,0,108,8,95,1,121,72,121,72,121,72,112,3,
		73,36,23,0,48,9,0,95,2,106,8,82,101,108,
		101,97,115,101,0,89,20,0,1,0,0,0,48,10,
		0,48,11,0,95,1,112,0,112,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,25,0,48,12,0,
		95,2,112,0,73,167,14,0,0,176,13,0,104,1,
		0,95,2,20,2,168,48,14,0,95,2,112,0,80,
		3,176,15,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,16,0,95,3,164,
		146,1,0,73,95,3,110,7,48,14,0,103,1,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLASH_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,4,6,36,27,0,102,80,7,36,31,0,176,17,
		0,95,2,12,1,31,8,95,2,100,8,28,7,93,
		208,7,80,2,36,33,0,95,3,100,8,31,6,95,
		3,31,27,36,34,0,48,18,0,176,19,0,12,0,
		95,1,100,100,95,4,95,5,112,5,80,10,25,25,
		36,36,0,48,20,0,176,19,0,12,0,95,1,100,
		100,95,4,95,5,112,5,80,10,36,39,0,95,4,
		100,5,28,11,48,21,0,95,10,112,0,25,4,95,
		4,80,8,36,40,0,95,5,100,5,28,11,48,22,
		0,95,10,112,0,25,4,95,5,80,9,36,42,0,
		95,4,100,5,31,8,95,5,100,5,28,92,36,45,
		0,48,23,0,95,7,48,2,0,176,24,0,12,0,
		92,11,128,0,8,64,144,0,0,0,0,121,121,95,
		8,95,9,106,1,0,100,89,28,0,0,0,2,0,
		7,0,2,0,48,25,0,95,255,95,254,48,11,0,
		95,255,112,0,112,2,6,100,100,100,100,100,100,9,
		95,10,100,9,100,100,9,100,100,9,112,25,112,1,
		73,26,141,0,36,50,0,48,23,0,95,7,48,2,
		0,176,24,0,12,0,92,11,128,0,8,64,144,0,
		0,0,0,121,121,95,8,95,9,106,1,0,100,89,
		28,0,0,0,2,0,7,0,2,0,48,25,0,95,
		255,95,254,48,11,0,95,255,112,0,112,2,6,100,
		100,100,100,100,100,9,100,100,9,100,100,9,100,100,
		9,112,25,112,1,73,36,51,0,48,2,0,176,26,
		0,12,0,100,100,121,121,95,4,95,5,95,1,9,
		100,100,100,100,100,9,121,95,6,112,16,80,10,48,
		27,0,95,10,106,7,66,105,116,109,97,112,0,112,
		1,73,36,54,0,48,28,0,48,11,0,95,7,112,
		0,95,2,121,35,112,1,73,36,55,0,48,29,0,
		48,30,0,95,7,112,0,112,0,73,36,57,0,95,
		7,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLASH_COUNTSECONDS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,61,0,48,31,0,102,48,2,0,176,
		32,0,12,0,95,2,100,95,1,90,13,176,33,0,
		176,34,0,12,0,12,1,6,112,4,112,1,73,48,
		27,0,48,30,0,102,112,0,106,9,58,58,111,84,
		105,109,101,114,0,112,1,73,36,63,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,35,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

