/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\hpager.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HPAGER );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HPAGER_NEW );
HB_FUNC_STATIC( HPAGER_REDEFINE );
HB_FUNC_STATIC( HPAGER_ACTIVATE );
HB_FUNC_STATIC( HPAGER_INIT );
HB_FUNC_STATIC( HPAGER_NOTIFY );
HB_FUNC_EXTERN( PAGERSETCHILD );
HB_FUNC_EXTERN( PAGERRECALCSIZE );
HB_FUNC_EXTERN( PAGERFORWARDMOUSE );
HB_FUNC_EXTERN( PAGERSETBKCOLOR );
HB_FUNC_EXTERN( PAGERGETBKCOLOR );
HB_FUNC_EXTERN( PAGERSETBORDER );
HB_FUNC_EXTERN( PAGERGETBORDER );
HB_FUNC_EXTERN( PAGERSETPOS );
HB_FUNC_EXTERN( PAGERGETPOS );
HB_FUNC_EXTERN( PAGERSETBUTTONSIZE );
HB_FUNC_EXTERN( PAGERGETBUTTONSIZE );
HB_FUNC_EXTERN( PAGERGETBUTTONSTATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CREATEPAGER );
HB_FUNC_EXTERN( GETNOTIFYCODE );
HB_FUNC_EXTERN( PAGERONPAGERCALCSIZE );
HB_FUNC_EXTERN( PAGERONPAGERSCROLL );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HPAGER )
{ "HPAGER", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HPAGER_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER_NEW )}, NULL },
{ "HPAGER_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER_REDEFINE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_M_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_M_NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HPAGER_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER_ACTIVATE )}, NULL },
{ "HPAGER_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER_INIT )}, NULL },
{ "HPAGER_NOTIFY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HPAGER_NOTIFY )}, NULL },
{ "_HTOOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PAGERSETCHILD", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERSETCHILD )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PAGERRECALCSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERRECALCSIZE )}, NULL },
{ "PAGERFORWARDMOUSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERFORWARDMOUSE )}, NULL },
{ "PAGERSETBKCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERSETBKCOLOR )}, NULL },
{ "PAGERGETBKCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERGETBKCOLOR )}, NULL },
{ "PAGERSETBORDER", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERSETBORDER )}, NULL },
{ "PAGERGETBORDER", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERGETBORDER )}, NULL },
{ "PAGERSETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERSETPOS )}, NULL },
{ "PAGERGETPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERGETPOS )}, NULL },
{ "PAGERSETBUTTONSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERSETBUTTONSIZE )}, NULL },
{ "PAGERGETBUTTONSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERGETBUTTONSIZE )}, NULL },
{ "PAGERGETBUTTONSTATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERGETBUTTONSTATE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LVERT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEPAGER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEPAGER )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LVERT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETNOTIFYCODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETNOTIFYCODE )}, NULL },
{ "PAGERONPAGERCALCSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERONPAGERCALCSIZE )}, NULL },
{ "HTOOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PAGERONPAGERSCROLL", {HB_FS_PUBLIC}, {HB_FUNCNAME( PAGERONPAGERSCROLL )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HPAGER, "source\\hpager.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HPAGER
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HPAGER )
   #include "hbiniseg.h"
#endif

HB_FUNC( HPAGER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,62,0,36,19,0,103,1,0,100,8,
		29,96,5,176,1,0,104,1,0,12,1,29,85,5,
		166,23,5,0,122,80,1,48,2,0,176,3,0,12,
		0,106,7,72,80,97,103,101,114,0,108,4,4,1,
		0,108,0,112,3,80,2,36,21,0,48,5,0,95,
		2,100,106,9,83,121,115,80,97,103,101,114,0,95,
		1,121,72,121,72,121,72,106,9,119,105,110,99,108,
		97,115,115,0,4,1,0,9,112,5,73,36,22,0,
		48,5,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,5,84,69,88,84,0,106,3,105,100,0,106,
		5,110,84,111,112,0,106,6,110,76,101,102,116,0,
		106,7,110,119,105,100,116,104,0,106,8,110,104,101,
		105,103,104,116,0,4,6,0,9,112,5,73,36,23,
		0,48,6,0,95,2,100,100,95,1,121,72,92,32,
		72,121,72,121,72,106,10,111,83,101,108,101,99,116,
		101,100,0,4,1,0,9,112,5,73,36,24,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,8,69,120,83,116,121,108,101,0,4,1,0,9,
		112,5,73,36,25,0,48,5,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,7,98,67,108,105,99,
		107,0,4,1,0,9,112,5,73,36,26,0,48,5,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		6,108,86,101,114,116,0,4,1,0,9,112,5,73,
		36,27,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,6,104,84,111,111,108,0,4,1,
		0,9,112,5,73,36,28,0,48,5,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,9,109,95,110,
		87,105,100,116,104,0,106,10,109,95,110,72,101,105,
		103,104,116,0,4,2,0,9,112,5,73,36,31,0,
		48,7,0,95,2,106,4,78,101,119,0,108,8,95,
		1,121,72,121,72,121,72,112,3,73,36,33,0,48,
		7,0,95,2,106,9,82,101,100,101,102,105,110,101,
		0,108,9,95,1,121,72,121,72,121,72,112,3,73,
		36,34,0,48,10,0,95,2,106,14,83,101,116,83,
		99,114,111,108,108,65,114,101,97,0,89,27,0,3,
		0,0,0,48,11,0,95,1,95,2,112,1,73,48,
		12,0,95,1,95,3,112,1,6,95,1,121,72,121,
		72,121,72,112,3,73,36,35,0,48,7,0,95,2,
		106,9,65,99,116,105,118,97,116,101,0,108,13,95,
		1,121,72,121,72,121,72,112,3,73,36,36,0,48,
		7,0,95,2,106,5,73,78,73,84,0,108,14,95,
		1,121,72,121,72,121,72,112,3,73,36,38,0,48,
		7,0,95,2,106,7,78,111,116,105,102,121,0,108,
		15,95,1,121,72,121,72,121,72,112,3,73,36,39,
		0,48,10,0,95,2,106,14,80,65,71,69,82,83,
		69,84,67,72,73,76,68,0,89,32,0,2,0,0,
		0,48,16,0,95,1,95,2,112,1,73,176,17,0,
		48,18,0,95,1,112,0,95,2,12,2,6,95,1,
		121,72,121,72,121,72,112,3,73,36,40,0,48,10,
		0,95,2,106,16,80,65,71,69,82,82,69,67,65,
		76,67,83,73,90,69,0,89,20,0,1,0,0,0,
		176,19,0,48,18,0,95,1,112,0,12,1,6,95,
		1,121,72,121,72,121,72,112,3,73,36,41,0,48,
		10,0,95,2,106,18,80,65,71,69,82,70,79,82,
		87,65,82,68,77,79,85,83,69,0,89,22,0,2,
		0,0,0,176,20,0,48,18,0,95,1,112,0,95,
		2,12,2,6,95,1,121,72,121,72,121,72,112,3,
		73,36,42,0,48,10,0,95,2,106,16,80,65,71,
		69,82,83,69,84,66,75,67,79,76,79,82,0,89,
		22,0,2,0,0,0,176,21,0,48,18,0,95,1,
		112,0,95,2,12,2,6,95,1,121,72,121,72,121,
		72,112,3,73,36,43,0,48,10,0,95,2,106,16,
		80,65,71,69,82,71,69,84,66,75,67,79,76,79,
		82,0,89,20,0,1,0,0,0,176,22,0,48,18,
		0,95,1,112,0,12,1,6,95,1,121,72,121,72,
		121,72,112,3,73,36,44,0,48,10,0,95,2,106,
		15,80,65,71,69,82,83,69,84,66,79,82,68,69,
		82,0,89,22,0,2,0,0,0,176,23,0,48,18,
		0,95,1,112,0,95,2,12,2,6,95,1,121,72,
		121,72,121,72,112,3,73,36,45,0,48,10,0,95,
		2,106,15,80,65,71,69,82,71,69,84,66,79,82,
		68,69,82,0,89,20,0,1,0,0,0,176,24,0,
		48,18,0,95,1,112,0,12,1,6,95,1,121,72,
		121,72,121,72,112,3,73,36,46,0,48,10,0,95,
		2,106,12,80,65,71,69,82,83,69,84,80,79,83,
		0,89,22,0,2,0,0,0,176,25,0,48,18,0,
		95,1,112,0,95,2,12,2,6,95,1,121,72,121,
		72,121,72,112,3,73,36,47,0,48,10,0,95,2,
		106,12,80,65,71,69,82,71,69,84,80,79,83,0,
		89,20,0,1,0,0,0,176,26,0,48,18,0,95,
		1,112,0,12,1,6,95,1,121,72,121,72,121,72,
		112,3,73,36,48,0,48,10,0,95,2,106,19,80,
		65,71,69,82,83,69,84,66,85,84,84,79,78,83,
		73,90,69,0,89,22,0,2,0,0,0,176,27,0,
		48,18,0,95,1,112,0,95,2,12,2,6,95,1,
		121,72,121,72,121,72,112,3,73,36,49,0,48,10,
		0,95,2,106,19,80,65,71,69,82,71,69,84,66,
		85,84,84,79,78,83,73,90,69,0,89,20,0,1,
		0,0,0,176,28,0,48,18,0,95,1,112,0,12,
		1,6,95,1,121,72,121,72,121,72,112,3,73,36,
		50,0,48,10,0,95,2,106,20,80,65,71,69,82,
		71,69,84,66,85,84,84,79,78,83,84,65,84,69,
		0,89,20,0,1,0,0,0,176,29,0,48,18,0,
		95,1,112,0,12,1,6,95,1,121,72,121,72,121,
		72,112,3,73,36,52,0,48,30,0,95,2,112,0,
		73,167,14,0,0,176,31,0,104,1,0,95,2,20,
		2,168,48,32,0,95,2,112,0,80,3,176,33,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,34,0,95,3,164,146,1,0,73,
		95,3,110,7,48,32,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPAGER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,16,36,60,0,95,16,100,8,28,5,9,80,
		16,36,61,0,48,35,0,102,95,16,112,1,73,36,
		63,0,176,36,0,95,3,100,8,28,5,121,25,4,
		95,3,97,0,0,0,80,95,16,28,5,121,25,3,
		122,72,12,2,80,3,36,65,0,48,2,0,48,37,
		0,102,112,0,95,1,95,2,95,3,95,4,95,5,
		95,6,95,7,95,9,95,10,95,11,95,12,95,13,
		95,14,95,15,112,14,73,36,66,0,176,38,0,20,
		0,36,69,0,48,39,0,102,112,0,73,36,71,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPAGER_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,11,36,80,0,95,11,100,8,28,5,9,80,
		11,36,82,0,48,2,0,48,37,0,102,112,0,95,
		1,95,2,121,121,121,121,121,95,4,95,5,95,6,
		95,7,95,8,95,9,95,10,112,14,73,36,83,0,
		176,38,0,20,0,36,85,0,48,40,0,102,48,41,
		0,102,48,42,0,102,48,43,0,102,48,44,0,102,
		121,112,1,112,1,112,1,112,1,112,1,73,36,87,
		0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPAGER_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,92,0,176,45,0,48,18,0,48,46,0,102,112,
		0,112,0,12,1,31,86,36,95,0,48,47,0,102,
		176,48,0,48,18,0,48,46,0,102,112,0,112,0,
		48,49,0,102,112,0,48,50,0,102,112,0,48,51,
		0,102,112,0,48,52,0,102,112,0,48,53,0,102,
		112,0,48,54,0,102,112,0,48,55,0,102,112,0,
		28,5,121,25,3,122,12,8,112,1,73,36,97,0,
		48,56,0,102,112,0,73,36,99,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPAGER_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,103,0,48,57,0,102,112,0,31,17,36,104,0,
		48,56,0,48,37,0,102,112,0,112,0,73,36,106,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HPAGER_NOTIFY )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,110,0,176,58,0,95,1,12,1,80,
		2,36,112,0,95,2,93,122,252,8,28,20,36,113,
		0,176,59,0,95,1,48,60,0,102,112,0,20,2,
		25,23,36,114,0,95,2,93,123,252,8,28,12,36,
		115,0,176,61,0,95,1,20,1,36,118,0,121,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,62,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

