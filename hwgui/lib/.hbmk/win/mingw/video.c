/*
 * Harbour 3.4.0dev (aebbea8) (2017-03-22 15:49)
 * MinGW GNU C 6.3 (32-bit)
 * Generated C source from "source\video.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TVIDEO );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( TVIDEO_NEW );
HB_FUNC_STATIC( TVIDEO_REDEFINE );
HB_FUNC_STATIC( TVIDEO_INITIATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( TMCI );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_VIDEO )
{ "TVIDEO", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVIDEO_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_NEW )}, NULL },
{ "TVIDEO_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_REDEFINE )}, NULL },
{ "TVIDEO_INITIATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TVIDEO_INITIATE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PLAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMCI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CAVIFILE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OMCI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TMCI", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMCI )}, NULL },
{ "INITIATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "LOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETWINDOW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BWHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_VIDEO, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_VIDEO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_VIDEO )
   #include "hbiniseg.h"
#endif

HB_FUNC( TVIDEO )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,46,0,36,18,0,103,1,0,100,8,
		29,86,1,176,1,0,104,1,0,12,1,29,75,1,
		166,13,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,7,84,86,105,100,101,111,0,108,4,4,1,
		0,108,0,112,3,80,2,36,20,0,48,5,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,5,111,
		77,99,105,0,4,1,0,9,112,5,73,36,21,0,
		48,5,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,9,99,65,118,105,70,105,108,101,0,4,1,
		0,9,112,5,73,36,24,0,48,6,0,95,2,106,
		4,78,101,119,0,108,7,95,1,92,8,72,121,72,
		121,72,112,3,73,36,26,0,48,6,0,95,2,106,
		9,82,101,68,101,102,105,110,101,0,108,8,95,1,
		92,8,72,121,72,121,72,112,3,73,36,27,0,48,
		6,0,95,2,106,9,73,110,105,116,105,97,116,101,
		0,108,9,95,1,121,72,121,72,121,72,112,3,73,
		36,28,0,48,10,0,95,2,106,5,80,108,97,121,
		0,89,36,0,3,0,0,0,48,11,0,48,12,0,
		95,1,112,0,95,2,95,3,48,13,0,48,14,0,
		95,1,112,0,112,0,112,3,6,95,1,121,72,121,
		72,121,72,112,3,73,36,30,0,48,15,0,95,2,
		112,0,73,167,14,0,0,176,16,0,104,1,0,95,
		2,20,2,168,48,17,0,95,2,112,0,80,3,176,
		18,0,95,3,106,10,73,110,105,116,67,108,97,115,
		115,0,12,2,28,12,48,19,0,95,3,164,146,1,
		0,73,95,3,110,7,48,17,0,103,1,0,112,0,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,8,36,36,0,95,3,100,8,28,7,93,200,
		0,80,3,95,4,100,8,28,7,93,200,0,80,4,
		95,5,100,8,28,7,106,1,0,80,5,95,7,100,
		8,28,5,9,80,7,36,38,0,48,20,0,102,95,
		1,92,14,65,112,1,73,36,39,0,48,21,0,102,
		95,2,92,8,65,112,1,73,36,40,0,48,22,0,
		102,48,23,0,102,112,0,95,4,72,122,49,112,1,
		73,36,41,0,48,24,0,102,48,25,0,102,112,0,
		95,3,72,122,72,112,1,73,36,42,0,48,26,0,
		102,176,27,0,97,0,0,1,80,95,7,31,9,97,
		0,0,128,0,25,3,121,12,2,112,1,73,36,44,
		0,48,28,0,102,95,6,100,8,28,10,48,29,0,
		102,112,0,25,4,95,6,112,1,73,36,45,0,48,
		30,0,102,95,8,100,8,28,10,48,31,0,102,112,
		0,25,4,95,8,112,1,73,36,46,0,48,32,0,
		102,95,5,112,1,73,36,47,0,48,33,0,102,48,
		2,0,176,34,0,12,0,106,9,97,118,105,118,105,
		100,101,111,0,95,5,112,2,112,1,73,36,48,0,
		48,35,0,102,112,0,73,36,50,0,176,36,0,48,
		13,0,48,14,0,102,112,0,112,0,12,1,31,35,
		36,51,0,48,37,0,48,12,0,102,112,0,112,0,
		73,36,52,0,48,38,0,48,12,0,102,112,0,102,
		112,1,73,25,18,36,54,0,48,39,0,48,14,0,
		102,112,0,102,112,1,73,36,57,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,5,36,62,0,48,40,0,102,95,1,112,1,
		73,36,63,0,48,32,0,102,95,2,112,1,73,36,
		64,0,48,41,0,102,95,4,112,1,73,36,65,0,
		48,42,0,102,95,5,112,1,73,36,66,0,48,43,
		0,102,95,3,112,1,73,36,67,0,48,33,0,102,
		48,2,0,176,34,0,12,0,106,9,97,118,105,118,
		105,100,101,111,0,95,2,112,2,112,1,73,36,69,
		0,48,39,0,95,3,102,112,1,73,36,71,0,102,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TVIDEO_INITIATE )
{
	static const HB_BYTE pcode[] =
	{
		36,76,0,48,44,0,48,45,0,102,112,0,112,0,
		73,36,77,0,48,37,0,48,12,0,102,112,0,112,
		0,73,36,78,0,48,38,0,48,12,0,102,112,0,
		102,112,1,73,36,80,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,46,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

