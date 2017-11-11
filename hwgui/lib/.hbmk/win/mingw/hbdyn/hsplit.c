/*
 * Harbour 3.4.0dev (f75b945) (2016-01-05 16:47)
 * MinGW GNU C 5.3 (32-bit)
 * Generated C source from "source\hsplit.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HSPLITTER );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HSPLITTER_NEW );
HB_FUNC_STATIC( HSPLITTER_ACTIVATE );
HB_FUNC_STATIC( HSPLITTER_ONEVENT );
HB_FUNC_STATIC( HSPLITTER_INIT );
HB_FUNC_STATIC( HSPLITTER_PAINT );
HB_FUNC_STATIC( HSPLITTER_DRAG );
HB_FUNC_STATIC( HSPLITTER_DRAGALL );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_CREATESTATIC );
HB_FUNC_EXTERN( HWG_SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITWINCTRL );
HB_FUNC_EXTERN( HWG_LOADCURSOR );
HB_FUNC_EXTERN( HWG_SETCURSOR );
HB_FUNC_EXTERN( HWG_SETCAPTURE );
HB_FUNC_EXTERN( HWG_INVALIDATERECT );
HB_FUNC_EXTERN( HWG_RELEASECAPTURE );
HB_FUNC_EXTERN( HWG_DEFINEPAINTSTRU );
HB_FUNC_EXTERN( HWG_BEGINPAINT );
HB_FUNC_EXTERN( HWG_GETPPSERASE );
HB_FUNC_EXTERN( HWG_GETPPSRECT );
HB_FUNC_EXTERN( HWG_SETBKMODE );
HB_FUNC_EXTERN( HBRUSH );
HB_FUNC_EXTERN( HWG_RGB );
HB_FUNC_EXTERN( HWG_SELECTOBJECT );
HB_FUNC_EXTERN( HWG_DRAWEDGE );
HB_FUNC_EXTERN( HWG_FILLRECT );
HB_FUNC_EXTERN( HWG_ENDPAINT );
HB_FUNC_EXTERN( HWG_LOWORD );
HB_FUNC_EXTERN( HWG_HIWORD );
HB_FUNC_EXTERN( LEN );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HSPLIT )
{ "HSPLITTER", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HSPLITTER_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_NEW )}, NULL },
{ "HSPLITTER_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_ACTIVATE )}, NULL },
{ "HSPLITTER_ONEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_ONEVENT )}, NULL },
{ "HSPLITTER_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_INIT )}, NULL },
{ "HSPLITTER_PAINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_PAINT )}, NULL },
{ "HSPLITTER_DRAG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_DRAG )}, NULL },
{ "HSPLITTER_DRAGALL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSPLITTER_DRAGALL )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_TITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ALEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ARIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LVERTICAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LSCROLLING", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BACKSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_EXTSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXTSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_CREATESTATIC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CREATESTATIC )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHOLDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETWINDOWOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETWINDOWOBJECT )}, NULL },
{ "HWG_INITWINCTRL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITWINCTRL )}, NULL },
{ "HCURSOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HCURSOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LOADCURSOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LOADCURSOR )}, NULL },
{ "LVERTICAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETCURSOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETCURSOR )}, NULL },
{ "LCAPTURED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DRAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSCROLLING", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DRAGALL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PAINT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETCAPTURE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETCAPTURE )}, NULL },
{ "_LCAPTURED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INVALIDATERECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INVALIDATERECT )}, NULL },
{ "HWG_RELEASECAPTURE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_RELEASECAPTURE )}, NULL },
{ "_LMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BENDDRAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DEFINEPAINTSTRU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DEFINEPAINTSTRU )}, NULL },
{ "HWG_BEGINPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BEGINPAINT )}, NULL },
{ "HWG_GETPPSERASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETPPSERASE )}, NULL },
{ "HWG_GETPPSRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETPPSRECT )}, NULL },
{ "HWG_SETBKMODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETBKMODE )}, NULL },
{ "BACKSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBRUSH", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBRUSH )}, NULL },
{ "HWG_RGB", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_RGB )}, NULL },
{ "HWG_SELECTOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SELECTOBJECT )}, NULL },
{ "HWG_DRAWEDGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DRAWEDGE )}, NULL },
{ "HWG_FILLRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_FILLRECT )}, NULL },
{ "LMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_ENDPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ENDPAINT )}, NULL },
{ "HWG_LOWORD", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LOWORD )}, NULL },
{ "HWG_HIWORD", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_HIWORD )}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MOVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "ALEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ARIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HSPLIT, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HSPLIT
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HSPLIT )
   #include "hbiniseg.h"
#endif

HB_FUNC( HSPLITTER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,87,0,36,18,0,103,1,0,100,8,
		29,146,2,176,1,0,104,1,0,12,1,29,135,2,
		166,73,2,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,72,83,112,108,105,116,116,101,114,0,108,
		4,4,1,0,108,0,112,3,80,2,36,20,0,48,
		5,0,95,2,100,106,7,83,84,65,84,73,67,0,
		95,1,121,72,121,72,121,72,121,72,106,9,119,105,
		110,99,108,97,115,115,0,4,1,0,9,112,5,73,
		36,21,0,48,6,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,6,97,76,101,102,116,0,4,1,
		0,9,112,5,73,36,22,0,48,6,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,7,97,82,105,
		103,104,116,0,4,1,0,9,112,5,73,36,23,0,
		48,6,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,10,108,86,101,114,116,105,99,97,108,0,4,
		1,0,9,112,5,73,36,24,0,48,6,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,8,104,67,
		117,114,115,111,114,0,4,1,0,9,112,5,73,36,
		25,0,48,6,0,95,2,100,9,95,1,121,72,121,
		72,121,72,106,10,108,67,97,112,116,117,114,101,100,
		0,4,1,0,9,112,5,73,36,26,0,48,6,0,
		95,2,100,9,95,1,121,72,121,72,121,72,106,7,
		108,77,111,118,101,100,0,4,1,0,9,112,5,73,
		36,27,0,48,6,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,9,98,69,110,100,68,114,97,103,
		0,4,1,0,9,112,5,73,36,28,0,48,6,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,11,
		108,83,99,114,111,108,108,105,110,103,0,4,1,0,
		9,112,5,73,36,31,0,48,7,0,95,2,106,4,
		78,101,119,0,108,8,95,1,121,72,121,72,121,72,
		112,3,73,36,32,0,48,7,0,95,2,106,9,65,
		99,116,105,118,97,116,101,0,108,9,95,1,121,72,
		121,72,121,72,112,3,73,36,33,0,48,7,0,95,
		2,106,8,111,110,69,118,101,110,116,0,108,10,95,
		1,121,72,121,72,121,72,112,3,73,36,34,0,48,
		7,0,95,2,106,5,73,110,105,116,0,108,11,95,
		1,121,72,121,72,121,72,112,3,73,36,35,0,48,
		7,0,95,2,106,6,80,97,105,110,116,0,108,12,
		95,1,121,72,121,72,121,72,112,3,73,36,36,0,
		48,7,0,95,2,106,5,68,114,97,103,0,108,13,
		95,1,121,72,121,72,121,72,112,3,73,36,37,0,
		48,7,0,95,2,106,8,68,114,97,103,65,108,108,
		0,108,14,95,1,121,72,121,72,121,72,112,3,73,
		36,39,0,48,15,0,95,2,112,0,73,167,14,0,
		0,176,16,0,104,1,0,95,2,20,2,168,48,17,
		0,95,2,112,0,80,3,176,18,0,95,3,106,10,
		73,110,105,116,67,108,97,115,115,0,12,2,28,12,
		48,19,0,95,3,164,146,1,0,73,95,3,110,7,
		48,17,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,14,36,45,0,48,2,0,48,20,0,102,112,
		0,95,1,95,2,97,13,0,0,16,95,3,95,4,
		95,5,95,6,100,100,95,7,95,8,100,95,9,95,
		10,112,14,73,36,47,0,48,21,0,102,106,1,0,
		112,1,73,36,49,0,48,22,0,102,95,11,100,8,
		28,7,4,0,0,25,4,95,11,112,1,73,36,50,
		0,48,23,0,102,95,12,100,8,28,7,4,0,0,
		25,4,95,12,112,1,73,36,51,0,48,24,0,102,
		48,25,0,102,112,0,48,26,0,102,112,0,15,112,
		1,73,36,52,0,48,27,0,102,95,14,100,8,28,
		5,9,25,4,95,14,112,1,73,36,53,0,95,13,
		100,69,28,38,95,13,28,34,36,54,0,48,28,0,
		102,122,112,1,73,36,55,0,48,29,0,102,21,48,
		30,0,163,0,112,0,92,32,72,112,1,73,36,57,
		0,48,31,0,102,112,0,73,36,59,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,62,0,176,32,0,48,33,0,48,34,0,102,112,
		0,112,0,12,1,31,80,36,64,0,48,35,0,102,
		176,36,0,48,33,0,48,34,0,102,112,0,112,0,
		48,37,0,102,112,0,48,38,0,102,112,0,48,39,
		0,102,112,0,48,40,0,102,112,0,48,26,0,102,
		112,0,48,25,0,102,112,0,48,30,0,102,112,0,
		12,8,112,1,73,36,65,0,48,41,0,102,112,0,
		73,36,68,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,72,0,48,42,0,102,112,0,31,57,36,73,0,
		48,41,0,48,20,0,102,112,0,112,0,73,36,74,
		0,48,43,0,102,122,112,1,73,36,75,0,176,44,
		0,48,33,0,102,112,0,102,20,2,36,76,0,176,
		45,0,48,33,0,102,112,0,20,1,36,79,0,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,85,0,95,1,93,0,2,8,28,110,
		36,86,0,48,46,0,102,112,0,100,8,28,33,36,
		87,0,48,47,0,102,176,48,0,48,49,0,102,112,
		0,28,7,93,132,127,25,5,93,133,127,12,1,112,
		1,73,36,89,0,176,50,0,48,46,0,102,112,0,
		20,1,36,90,0,48,51,0,102,112,0,29,229,0,
		36,91,0,48,52,0,102,95,3,112,1,73,36,92,
		0,48,53,0,102,112,0,29,205,0,36,93,0,48,
		54,0,102,120,112,1,73,26,191,0,36,96,0,95,
		1,92,15,8,28,15,36,97,0,48,55,0,102,112,
		0,73,26,168,0,36,98,0,95,1,92,20,8,32,
		157,0,36,99,0,95,1,93,1,2,8,28,58,36,
		100,0,176,50,0,48,46,0,102,112,0,20,1,36,
		101,0,176,56,0,48,33,0,102,112,0,20,1,36,
		102,0,48,57,0,102,120,112,1,73,36,103,0,176,
		58,0,48,33,0,102,112,0,122,20,2,25,89,36,
		104,0,95,1,93,2,2,8,28,58,36,105,0,176,
		59,0,20,0,36,106,0,48,57,0,102,9,112,1,
		73,36,107,0,48,60,0,102,9,112,1,73,36,108,
		0,48,54,0,102,9,112,1,73,36,109,0,48,61,
		0,102,112,0,100,69,31,24,25,22,36,112,0,95,
		1,92,2,8,28,12,36,113,0,48,62,0,102,112,
		0,73,36,116,0,92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,8,0,36,121,0,176,63,0,12,0,80,1,36,
		122,0,176,64,0,48,33,0,102,112,0,95,1,12,
		2,80,2,36,123,0,176,65,0,95,1,12,1,121,
		15,29,85,1,36,125,0,176,66,0,95,1,12,1,
		80,3,36,127,0,95,3,122,1,80,4,36,128,0,
		95,3,92,2,1,80,5,36,129,0,95,3,92,3,
		1,80,6,36,130,0,95,3,92,4,1,80,7,36,
		132,0,176,67,0,95,2,48,68,0,102,112,0,20,
		2,36,133,0,48,69,0,102,112,0,100,69,28,21,
		36,134,0,48,70,0,48,69,0,102,112,0,102,112,
		1,73,26,242,0,36,135,0,48,53,0,102,112,0,
		32,174,0,36,136,0,48,51,0,102,112,0,28,113,
		36,137,0,48,71,0,176,72,0,12,0,176,73,0,
		93,156,0,93,156,0,93,156,0,12,3,112,1,80,
		8,36,138,0,176,74,0,95,2,48,33,0,95,8,
		112,0,20,2,36,139,0,176,75,0,95,2,95,4,
		95,5,95,6,95,7,92,6,48,49,0,102,112,0,
		28,6,92,15,25,4,92,2,93,0,8,72,20,7,
		36,140,0,176,76,0,95,2,95,4,95,5,95,6,
		95,7,48,33,0,95,8,112,0,20,6,25,107,36,
		141,0,48,68,0,102,112,0,92,2,5,28,93,36,
		142,0,176,75,0,95,2,95,4,95,5,95,6,95,
		7,92,6,48,49,0,102,112,0,28,5,122,25,4,
		92,2,20,7,25,58,36,144,0,48,77,0,102,112,
		0,31,47,48,68,0,102,112,0,92,2,5,28,36,
		36,145,0,176,75,0,95,2,95,4,95,5,95,6,
		95,7,92,6,48,49,0,102,112,0,28,6,92,15,
		25,4,92,2,20,7,36,148,0,176,78,0,48,33,
		0,102,112,0,95,1,20,2,36,150,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_DRAG )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,153,0,176,79,0,95,1,12,1,80,
		2,176,80,0,95,1,12,1,80,3,36,155,0,48,
		49,0,102,112,0,28,54,36,156,0,95,2,93,0,
		125,15,28,14,36,157,0,96,2,0,97,255,255,0,
		0,136,36,159,0,48,81,0,102,21,48,39,0,163,
		0,112,0,95,2,72,112,1,73,36,160,0,121,80,
		3,25,52,36,162,0,95,3,93,0,125,15,28,14,
		36,163,0,96,3,0,97,255,255,0,0,136,36,165,
		0,48,82,0,102,21,48,40,0,163,0,112,0,95,
		3,72,112,1,73,36,166,0,121,80,2,36,168,0,
		48,83,0,102,48,39,0,102,112,0,95,2,72,48,
		40,0,102,112,0,95,3,72,48,26,0,102,112,0,
		48,25,0,102,112,0,112,4,73,36,169,0,48,53,
		0,102,112,0,31,60,36,170,0,176,58,0,48,33,
		0,48,34,0,102,112,0,112,0,122,48,39,0,102,
		112,0,48,40,0,102,112,0,48,39,0,102,112,0,
		48,26,0,102,112,0,72,48,40,0,102,112,0,48,
		25,0,102,112,0,72,20,6,36,172,0,48,60,0,
		102,120,112,1,73,36,174,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSPLITTER_DRAGALL )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,177,0,121,80,4,121,80,5,36,179,
		0,176,84,0,48,85,0,102,112,0,12,1,121,5,
		31,17,176,84,0,48,86,0,102,112,0,12,1,121,
		5,28,5,9,25,4,95,1,80,1,36,181,0,122,
		165,80,2,26,177,0,36,182,0,48,86,0,102,112,
		0,95,2,1,80,3,36,183,0,48,49,0,102,112,
		0,28,30,36,184,0,48,39,0,102,112,0,48,26,
		0,102,112,0,72,48,39,0,95,3,112,0,49,80,
		4,25,28,36,188,0,48,40,0,102,112,0,48,25,
		0,102,112,0,72,48,40,0,95,3,112,0,49,80,
		5,36,192,0,48,83,0,95,3,48,39,0,95,3,
		112,0,95,4,72,48,40,0,95,3,112,0,95,5,
		72,48,26,0,95,3,112,0,95,4,49,48,25,0,
		95,3,112,0,95,5,49,95,1,68,112,5,73,36,
		193,0,95,5,121,35,31,12,95,4,121,15,31,6,
		95,1,31,18,36,194,0,176,58,0,48,33,0,95,
		3,112,0,121,20,2,36,181,0,175,2,0,176,84,
		0,48,86,0,102,112,0,12,1,15,29,70,255,36,
		197,0,122,165,80,2,26,173,0,36,198,0,48,85,
		0,102,112,0,95,2,1,80,3,36,199,0,48,49,
		0,102,112,0,28,31,36,200,0,48,39,0,102,112,
		0,48,39,0,95,3,112,0,48,26,0,95,3,112,
		0,72,49,80,4,25,29,36,203,0,48,40,0,102,
		112,0,48,40,0,95,3,112,0,48,25,0,95,3,
		112,0,72,49,80,5,36,206,0,48,83,0,95,3,
		48,39,0,95,3,112,0,48,40,0,95,3,112,0,
		48,26,0,95,3,112,0,95,4,72,48,25,0,95,
		3,112,0,95,5,72,95,1,68,112,5,73,36,207,
		0,95,5,121,15,31,12,95,4,121,15,31,6,95,
		1,31,18,36,208,0,176,58,0,48,33,0,95,3,
		112,0,121,20,2,36,197,0,175,2,0,176,84,0,
		48,85,0,102,112,0,12,1,15,29,74,255,36,212,
		0,95,1,31,63,36,213,0,176,58,0,48,33,0,
		48,34,0,102,112,0,112,0,122,48,39,0,102,112,
		0,48,40,0,102,112,0,48,39,0,102,112,0,48,
		26,0,102,112,0,72,48,40,0,102,112,0,48,25,
		0,102,112,0,72,20,6,26,166,0,36,214,0,48,
		49,0,102,112,0,28,79,36,215,0,176,58,0,48,
		33,0,48,34,0,102,112,0,112,0,122,48,39,0,
		102,112,0,48,26,0,102,112,0,49,95,4,49,122,
		49,48,40,0,102,112,0,48,39,0,102,112,0,48,
		26,0,102,112,0,72,95,4,72,122,72,48,40,0,
		102,112,0,48,25,0,102,112,0,72,20,6,25,77,
		36,217,0,176,58,0,48,33,0,48,34,0,102,112,
		0,112,0,122,48,39,0,102,112,0,48,40,0,102,
		112,0,48,25,0,102,112,0,49,95,5,49,122,49,
		48,39,0,102,112,0,48,26,0,102,112,0,72,48,
		40,0,102,112,0,48,25,0,102,112,0,72,95,5,
		72,122,72,20,6,36,219,0,48,61,0,102,112,0,
		100,69,28,18,36,220,0,48,70,0,48,61,0,102,
		112,0,102,112,1,73,36,223,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,87,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

