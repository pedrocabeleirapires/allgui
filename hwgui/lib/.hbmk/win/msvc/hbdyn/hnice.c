/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\hnice.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HNICEBUTTON );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HNICEBUTTON_NEW );
HB_FUNC_STATIC( HNICEBUTTON_REDEFINE );
HB_FUNC_STATIC( HNICEBUTTON_ACTIVATE );
HB_FUNC_STATIC( HNICEBUTTON_INIT );
HB_FUNC_STATIC( HNICEBUTTON_CREATE );
HB_FUNC_STATIC( HNICEBUTTON_SIZE );
HB_FUNC_STATIC( HNICEBUTTON_MOVING );
HB_FUNC_STATIC( HNICEBUTTON_PAINT );
HB_FUNC_STATIC( HNICEBUTTON_MOUSEMOVE );
HB_FUNC_STATIC( HNICEBUTTON_MDOWN );
HB_FUNC_STATIC( HNICEBUTTON_MUP );
HB_FUNC_STATIC( HNICEBUTTON_RELEASE );
HB_FUNC_STATIC( HNICEBUTTON_END );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG_REGNICE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CREATENICEBTN );
HB_FUNC( NICEBUTTPROC );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( FINDSELF );
HB_FUNC_EXTERN( GETCLIENTRECT );
HB_FUNC_EXTERN( CREATEROUNDRECTRGN );
HB_FUNC_EXTERN( SETWINDOWRGN );
HB_FUNC_EXTERN( INVALIDATERECT );
HB_FUNC( SETNICEBTNSELECTED );
HB_FUNC_EXTERN( POSTMESSAGE );
HB_FUNC_EXTERN( DEFINEPAINTSTRU );
HB_FUNC_EXTERN( BEGINPAINT );
HB_FUNC_EXTERN( GETWINDOWTEXT );
HB_FUNC_EXTERN( GETTEXTSIZE );
HB_FUNC_EXTERN( DRAW_GRADIENT );
HB_FUNC_EXTERN( SETBKMODE );
HB_FUNC_EXTERN( SETTEXTCOLOR );
HB_FUNC_EXTERN( VCOLOR );
HB_FUNC_EXTERN( TEXTOUT );
HB_FUNC_EXTERN( ENDPAINT );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HNICE )
{ "HNICEBUTTON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HNICEBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_NEW )}, NULL },
{ "HNICEBUTTON_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_REDEFINE )}, NULL },
{ "HNICEBUTTON_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_ACTIVATE )}, NULL },
{ "HNICEBUTTON_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_INIT )}, NULL },
{ "HNICEBUTTON_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_CREATE )}, NULL },
{ "HNICEBUTTON_SIZE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_SIZE )}, NULL },
{ "HNICEBUTTON_MOVING", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MOVING )}, NULL },
{ "HNICEBUTTON_PAINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_PAINT )}, NULL },
{ "HNICEBUTTON_MOUSEMOVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MOUSEMOVE )}, NULL },
{ "HNICEBUTTON_MDOWN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MDOWN )}, NULL },
{ "HNICEBUTTON_MUP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_MUP )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LPRESS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HNICEBUTTON_RELEASE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_RELEASE )}, NULL },
{ "HNICEBUTTON_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HNICEBUTTON_END )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "G", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "B", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "R", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LFLAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NORDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "ACONTROLS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_EXSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_TEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_R", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_G", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_B", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_REGNICE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_REGNICE )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATENICEBTN", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATENICEBTN )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NICEBUTTPROC", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( NICEBUTTPROC )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "FINDSELF", {HB_FS_PUBLIC}, {HB_FUNCNAME( FINDSELF )}, NULL },
{ "PAINT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MOUSEMOVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SIZE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCLIENTRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETCLIENTRECT )}, NULL },
{ "CREATEROUNDRECTRGN", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEROUNDRECTRGN )}, NULL },
{ "SETWINDOWRGN", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWRGN )}, NULL },
{ "INVALIDATERECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( INVALIDATERECT )}, NULL },
{ "_STATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LFLAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETNICEBTNSELECTED", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SETNICEBTNSELECTED )}, NULL },
{ "LPRESS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "POSTMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( POSTMESSAGE )}, NULL },
{ "BCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINEPAINTSTRU", {HB_FS_PUBLIC}, {HB_FUNCNAME( DEFINEPAINTSTRU )}, NULL },
{ "BEGINPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( BEGINPAINT )}, NULL },
{ "GETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWINDOWTEXT )}, NULL },
{ "GETTEXTSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETTEXTSIZE )}, NULL },
{ "DRAW_GRADIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DRAW_GRADIENT )}, NULL },
{ "SETBKMODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETBKMODE )}, NULL },
{ "SETTEXTCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETTEXTCOLOR )}, NULL },
{ "VCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( VCOLOR )}, NULL },
{ "TEXTOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TEXTOUT )}, NULL },
{ "ENDPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ENDPAINT )}, NULL },
{ "OSELECTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_OSELECTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HNICE, "source\\hnice.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HNICE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HNICE )
   #include "hbiniseg.h"
#endif

HB_FUNC( HNICEBUTTON )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,97,0,36,19,0,103,1,0,100,8,
		29,251,3,176,1,0,104,1,0,12,1,29,240,3,
		166,178,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,12,72,78,105,99,101,66,117,116,116,111,110,
		0,108,4,4,1,0,108,0,112,3,80,2,36,21,
		0,48,5,0,95,2,100,106,9,78,73,67,69,66,
		85,84,84,0,95,1,121,72,121,72,121,72,106,9,
		119,105,110,99,108,97,115,115,0,4,1,0,9,112,
		5,73,36,22,0,48,5,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,5,84,69,88,84,0,106,
		3,105,100,0,106,5,110,84,111,112,0,106,6,110,
		76,101,102,116,0,106,7,110,119,105,100,116,104,0,
		106,8,110,104,101,105,103,104,116,0,4,6,0,9,
		112,5,73,36,23,0,48,6,0,95,2,100,100,95,
		1,121,72,92,32,72,121,72,121,72,106,10,111,83,
		101,108,101,99,116,101,100,0,4,1,0,9,112,5,
		73,36,24,0,48,5,0,95,2,100,121,95,1,121,
		72,121,72,121,72,106,6,83,116,97,116,101,0,4,
		1,0,9,112,5,73,36,25,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,8,69,120,
		83,116,121,108,101,0,4,1,0,9,112,5,73,36,
		26,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,7,98,67,108,105,99,107,0,106,9,
		99,84,111,111,108,116,105,112,0,4,2,0,9,112,
		5,73,36,28,0,48,5,0,95,2,100,9,95,1,
		121,72,121,72,121,72,106,7,108,80,114,101,115,115,
		0,4,1,0,9,112,5,73,36,29,0,48,5,0,
		95,2,100,92,30,95,1,121,72,121,72,121,72,106,
		2,114,0,4,1,0,9,112,5,73,36,30,0,48,
		5,0,95,2,100,92,90,95,1,121,72,121,72,121,
		72,106,2,103,0,4,1,0,9,112,5,73,36,31,
		0,48,5,0,95,2,100,92,90,95,1,121,72,121,
		72,121,72,106,2,98,0,4,1,0,9,112,5,73,
		36,32,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,6,108,70,108,97,116,0,4,1,
		0,9,112,5,73,36,33,0,48,5,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,7,110,79,114,
		100,101,114,0,4,1,0,9,112,5,73,36,37,0,
		48,7,0,95,2,106,4,78,101,119,0,108,8,95,
		1,121,72,121,72,121,72,112,3,73,36,41,0,48,
		7,0,95,2,106,9,82,101,100,101,102,105,110,101,
		0,108,9,95,1,121,72,121,72,121,72,112,3,73,
		36,43,0,48,7,0,95,2,106,9,65,99,116,105,
		118,97,116,101,0,108,10,95,1,121,72,121,72,121,
		72,112,3,73,36,44,0,48,7,0,95,2,106,5,
		73,78,73,84,0,108,11,95,1,121,72,121,72,121,
		72,112,3,73,36,45,0,48,7,0,95,2,106,7,
		67,114,101,97,116,101,0,108,12,95,1,121,72,121,
		72,121,72,112,3,73,36,46,0,48,7,0,95,2,
		106,5,83,105,122,101,0,108,13,95,1,121,72,121,
		72,121,72,112,3,73,36,47,0,48,7,0,95,2,
		106,7,77,111,118,105,110,103,0,108,14,95,1,121,
		72,121,72,121,72,112,3,73,36,48,0,48,7,0,
		95,2,106,6,80,97,105,110,116,0,108,15,95,1,
		121,72,121,72,121,72,112,3,73,36,49,0,48,7,
		0,95,2,106,10,77,111,117,115,101,77,111,118,101,
		0,108,16,95,1,121,72,121,72,121,72,112,3,73,
		36,50,0,48,7,0,95,2,106,6,77,68,111,119,
		110,0,108,17,95,1,121,72,121,72,121,72,112,3,
		73,36,51,0,48,7,0,95,2,106,4,77,85,112,
		0,108,18,95,1,121,72,121,72,121,72,112,3,73,
		36,52,0,48,19,0,95,2,106,6,80,114,101,115,
		115,0,89,24,0,1,0,0,0,48,20,0,95,1,
		120,112,1,73,48,21,0,95,1,112,0,6,95,1,
		121,72,121,72,121,72,112,3,73,36,53,0,48,7,
		0,95,2,106,8,82,69,76,69,65,83,69,0,108,
		22,95,1,121,72,121,72,121,72,112,3,73,36,54,
		0,48,7,0,95,2,106,4,69,78,68,0,108,23,
		95,1,121,72,121,72,121,72,112,3,73,36,56,0,
		48,24,0,95,2,112,0,73,167,14,0,0,176,25,
		0,104,1,0,95,2,20,2,168,48,26,0,95,2,
		112,0,80,3,176,27,0,95,3,106,10,73,110,105,
		116,67,108,97,115,115,0,12,2,28,12,48,28,0,
		95,3,164,146,1,0,73,95,3,110,7,48,26,0,
		103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,15,36,62,0,48,2,0,48,29,0,102,112,
		0,95,1,95,2,95,3,95,5,95,6,95,7,95,
		8,100,95,9,100,100,95,12,112,12,73,36,63,0,
		95,14,100,8,28,10,48,30,0,102,112,0,25,4,
		95,14,80,14,36,64,0,95,15,100,8,28,10,48,
		31,0,102,112,0,25,4,95,15,80,15,36,66,0,
		95,13,100,8,28,10,48,32,0,102,112,0,25,4,
		95,13,80,13,36,67,0,48,33,0,102,120,112,1,
		73,36,68,0,48,34,0,102,95,10,112,1,73,36,
		69,0,48,35,0,102,95,1,100,8,28,5,121,25,
		14,176,36,0,48,37,0,95,1,112,0,12,1,112,
		1,73,36,71,0,48,38,0,102,95,4,112,1,73,
		36,72,0,48,39,0,102,95,11,112,1,73,36,73,
		0,48,40,0,102,95,13,112,1,73,36,74,0,48,
		41,0,102,95,14,112,1,73,36,75,0,48,42,0,
		102,95,15,112,1,73,36,76,0,48,43,0,102,95,
		6,112,1,73,36,77,0,48,44,0,102,95,5,112,
		1,73,36,78,0,48,45,0,102,95,7,112,1,73,
		36,79,0,48,46,0,102,95,8,112,1,73,36,81,
		0,176,47,0,20,0,36,82,0,48,48,0,102,112,
		0,73,36,84,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,10,36,91,0,48,2,0,48,29,0,102,112,
		0,95,1,95,2,121,121,121,121,121,100,95,4,100,
		100,95,7,112,12,73,36,93,0,95,9,100,8,28,
		10,48,30,0,102,112,0,25,4,95,9,80,9,36,
		94,0,95,10,100,8,28,10,48,31,0,102,112,0,
		25,4,95,10,80,10,36,95,0,95,8,100,8,28,
		10,48,32,0,102,112,0,25,4,95,8,80,8,36,
		97,0,48,33,0,102,120,112,1,73,36,99,0,48,
		34,0,102,95,5,112,1,73,36,101,0,48,38,0,
		102,95,3,112,1,73,36,102,0,48,39,0,102,95,
		6,112,1,73,36,103,0,48,40,0,102,95,8,112,
		1,73,36,104,0,48,41,0,102,95,9,112,1,73,
		36,105,0,48,42,0,102,95,10,112,1,73,36,107,
		0,176,47,0,20,0,36,109,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,113,0,176,49,0,48,50,0,48,51,0,102,112,
		0,112,0,12,1,31,86,36,115,0,48,52,0,102,
		176,53,0,48,50,0,48,51,0,102,112,0,112,0,
		48,54,0,102,112,0,48,55,0,102,112,0,48,56,
		0,102,112,0,48,57,0,102,112,0,48,58,0,102,
		112,0,48,59,0,102,112,0,48,60,0,102,112,0,
		48,61,0,102,112,0,12,9,112,1,73,36,116,0,
		48,62,0,102,112,0,73,36,118,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,122,0,48,63,0,102,112,0,31,27,36,123,0,
		48,62,0,48,29,0,102,112,0,112,0,73,36,124,
		0,48,24,0,102,112,0,73,36,126,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( NICEBUTTPROC )
{
	static const HB_BYTE pcode[] =
	{
		13,1,4,36,131,0,95,2,122,69,29,215,0,36,
		132,0,176,65,0,93,0,2,92,15,93,1,2,93,
		2,2,93,3,2,92,2,93,22,2,92,5,4,8,
		0,95,2,12,2,121,15,29,176,0,36,133,0,176,
		66,0,95,1,12,1,165,80,5,100,8,28,8,36,
		134,0,9,110,7,36,137,0,95,2,92,15,8,28,
		16,36,138,0,48,67,0,95,5,112,0,73,26,129,
		0,36,139,0,95,2,93,2,2,8,28,15,36,140,
		0,48,68,0,95,5,112,0,73,25,104,36,141,0,
		95,2,93,1,2,8,28,15,36,142,0,48,21,0,
		95,5,112,0,73,25,80,36,143,0,95,2,93,0,
		2,8,28,19,36,144,0,48,69,0,95,5,95,3,
		95,4,112,2,73,25,52,36,145,0,95,2,92,5,
		8,28,15,36,146,0,48,70,0,95,5,112,0,73,
		25,29,36,148,0,95,2,92,2,8,28,19,36,149,
		0,48,71,0,95,5,112,0,73,36,150,0,120,110,
		7,36,155,0,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,36,164,0,176,72,0,48,50,0,102,112,
		0,12,1,80,2,36,165,0,95,2,92,3,1,95,
		2,122,1,49,80,3,36,166,0,95,2,92,4,1,
		95,2,92,2,1,49,80,4,36,167,0,176,73,0,
		121,121,95,3,95,4,95,4,101,205,204,204,204,204,
		204,236,63,10,2,65,95,4,101,205,204,204,204,204,
		204,236,63,10,2,65,12,6,80,1,36,168,0,176,
		74,0,48,50,0,102,112,0,95,1,120,20,3,36,
		169,0,176,75,0,48,50,0,102,112,0,121,121,20,
		3,36,171,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_SIZE )
{
	static const HB_BYTE pcode[] =
	{
		36,175,0,48,76,0,102,122,112,1,73,36,176,0,
		176,75,0,48,50,0,102,112,0,121,121,20,3,36,
		178,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MOVING )
{
	static const HB_BYTE pcode[] =
	{
		36,182,0,48,76,0,102,9,112,1,73,36,183,0,
		176,75,0,48,50,0,102,112,0,121,121,20,3,36,
		185,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MOUSEMOVE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,194,0,48,77,0,102,112,0,29,181,
		0,48,78,0,102,112,0,121,69,29,170,0,36,195,
		0,176,79,0,12,0,80,3,36,197,0,95,3,100,
		69,28,83,48,54,0,95,3,112,0,48,54,0,102,
		112,0,69,28,67,48,80,0,95,3,112,0,31,58,
		36,198,0,48,76,0,95,3,122,112,1,73,36,199,
		0,176,75,0,48,50,0,95,3,112,0,121,20,2,
		36,200,0,176,81,0,48,50,0,95,3,112,0,92,
		15,121,121,20,4,36,201,0,176,79,0,100,20,1,
		36,204,0,48,78,0,102,112,0,122,8,28,56,36,
		205,0,48,76,0,102,92,2,112,1,73,36,208,0,
		176,75,0,48,50,0,102,112,0,121,20,2,36,209,
		0,176,81,0,48,50,0,102,112,0,92,15,121,121,
		20,4,36,210,0,176,79,0,102,20,1,36,214,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MUP )
{
	static const HB_BYTE pcode[] =
	{
		36,218,0,48,78,0,102,112,0,92,3,8,29,130,
		0,36,219,0,48,80,0,102,112,0,31,58,36,220,
		0,48,76,0,102,48,77,0,102,112,0,28,6,92,
		2,25,3,122,112,1,73,36,221,0,176,75,0,48,
		50,0,102,112,0,121,20,2,36,222,0,176,81,0,
		48,50,0,102,112,0,92,15,121,121,20,4,36,224,
		0,48,77,0,102,112,0,31,11,36,225,0,176,79,
		0,100,20,1,36,227,0,48,82,0,102,112,0,100,
		69,28,29,36,228,0,48,83,0,48,82,0,102,112,
		0,48,51,0,102,112,0,48,54,0,102,112,0,112,
		2,73,36,232,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_MDOWN )
{
	static const HB_BYTE pcode[] =
	{
		36,236,0,48,78,0,102,112,0,92,3,69,28,57,
		36,237,0,48,76,0,102,92,3,112,1,73,36,239,
		0,176,75,0,48,50,0,102,112,0,121,121,20,3,
		36,240,0,176,81,0,48,50,0,102,112,0,92,15,
		121,121,20,4,36,241,0,176,79,0,102,20,1,36,
		244,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,11,0,36,248,0,176,84,0,12,0,80,1,36,
		249,0,176,85,0,48,50,0,102,112,0,95,1,12,
		2,80,2,36,5,1,176,72,0,48,50,0,102,112,
		0,12,1,80,3,36,6,1,95,3,122,1,80,8,
		36,7,1,95,3,92,2,1,80,9,36,8,1,95,
		3,92,3,1,95,3,122,1,49,80,10,36,9,1,
		95,3,92,4,1,95,3,92,2,1,49,80,11,36,
		10,1,95,3,122,1,95,3,92,3,1,72,92,2,
		18,80,6,36,11,1,95,3,92,2,1,95,3,92,
		4,1,72,92,2,18,80,7,36,12,1,176,86,0,
		48,50,0,102,112,0,12,1,80,5,36,17,1,48,
		78,0,102,112,0,121,8,28,13,36,18,1,48,76,
		0,102,122,112,1,73,36,21,1,176,87,0,95,2,
		95,5,12,2,80,4,36,23,1,176,88,0,95,2,
		95,8,95,9,95,10,95,11,48,32,0,102,112,0,
		48,30,0,102,112,0,48,31,0,102,112,0,20,8,
		36,24,1,176,89,0,95,2,122,20,2,36,26,1,
		48,78,0,102,112,0,92,2,8,28,65,36,27,1,
		176,90,0,95,2,176,91,0,106,7,70,70,48,48,
		48,48,0,12,1,20,2,36,28,1,176,92,0,95,
		2,95,6,95,4,122,1,92,2,18,49,122,72,95,
		7,95,4,92,2,1,92,2,18,49,122,72,95,5,
		20,4,25,59,36,30,1,176,90,0,95,2,176,91,
		0,106,7,48,48,48,48,70,70,0,12,1,20,2,
		36,31,1,176,92,0,95,2,95,6,95,4,122,1,
		92,2,18,49,95,7,95,4,92,2,1,92,2,18,
		49,95,5,20,4,36,34,1,176,93,0,48,50,0,
		102,112,0,95,1,20,2,36,36,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_END )
{
	static const HB_BYTE pcode[] =
	{
		36,40,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HNICEBUTTON_RELEASE )
{
	static const HB_BYTE pcode[] =
	{
		36,44,1,48,20,0,102,9,112,1,73,36,45,1,
		48,76,0,102,122,112,1,73,36,46,1,176,75,0,
		48,50,0,102,112,0,121,20,2,36,47,1,176,81,
		0,48,50,0,102,112,0,92,15,121,121,20,4,36,
		49,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( SETNICEBTNSELECTED )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,53,1,48,94,0,176,0,0,12,0,
		112,0,80,2,36,55,1,176,95,0,12,0,121,15,
		28,18,36,56,1,48,96,0,176,0,0,12,0,95,
		1,112,1,73,36,59,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,97,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

