/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\menu.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HMENU );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HOBJECT );
HB_FUNC_EXTERN( HWG_DESTROYMENU );
HB_FUNC_STATIC( HMENU_SHOW );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( HWG_GETCURSORPOS );
HB_FUNC_EXTERN( HWG_TRACKMENU );
HB_FUNC_EXTERN( CLIENTTOSCREEN );
HB_FUNC( HWG_CREATEMENU );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG__CREATEMENU );
HB_FUNC( HWG_SETMENU );
HB_FUNC_EXTERN( HWG__SETMENU );
HB_FUNC( HWG_ADDMENUITEM );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG__ADDMENUITEM );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( ATAIL );
HB_FUNC_EXTERN( AINS );
HB_FUNC( HWG_FINDMENUITEM );
HB_FUNC( HWG_GETSUBMENUHANDLE );
HB_FUNC( BUILDMENU );
HB_FUNC_EXTERN( HWG__CREATEPOPUPMENU );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC( HWG_SEARCHPOSBITMAP );
HB_FUNC_EXTERN( SETMENUITEMBITMAPS );
HB_FUNC_EXTERN( HWG_SETMENUINFO );
HB_FUNC( HWG_BEGINMENU );
HB_FUNC_EXTERN( HWG_ISWIN7 );
HB_FUNC_EXTERN( GETSYSTEMMETRICS );
HB_FUNC( HWG_CONTEXTMENU );
HB_FUNC( HWG_ENDMENU );
HB_FUNC_EXTERN( ACLONE );
HB_FUNC_EXTERN( CREATEACCELERATORTABLE );
HB_FUNC( HWG_DEFINEMENUITEM );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( HBITMAP );
HB_FUNC( HWG_DEFINEACCELITEM );
HB_FUNC( HWG_SETMENUITEMBITMAPS );
HB_FUNC( HWG_INSERTBITMAPMENU );
HB_FUNC_EXTERN( HWG__INSERTBITMAPMENU );
HB_FUNC( DELETEMENUITEM );
HB_FUNC_EXTERN( ADEL );
HB_FUNC_EXTERN( ASIZE );
HB_FUNC_EXTERN( HWG_DELETEMENU );
HB_FUNC_EXTERN( GETMENUHANDLE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_MENU )
{ "HMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMENU )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DESTROYMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DESTROYMENU )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HMENU_SHOW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMENU_SHOW )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPOPUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HWG_GETCURSORPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETCURSORPOS )}, NULL },
{ "HWG_TRACKMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_TRACKMENU )}, NULL },
{ "CLIENTTOSCREEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( CLIENTTOSCREEN )}, NULL },
{ "HWG_CREATEMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_CREATEMENU )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HWG__CREATEMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG__CREATEMENU )}, NULL },
{ "HWG_SETMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_SETMENU )}, NULL },
{ "HWG__SETMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG__SETMENU )}, NULL },
{ "_MENU", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_ADDMENUITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ADDMENUITEM )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "HWG__ADDMENUITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG__ADDMENUITEM )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ATAIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATAIL )}, NULL },
{ "AINS", {HB_FS_PUBLIC}, {HB_FUNCNAME( AINS )}, NULL },
{ "HWG_FINDMENUITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_FINDMENUITEM )}, NULL },
{ "HWG_GETSUBMENUHANDLE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_GETSUBMENUHANDLE )}, NULL },
{ "BUILDMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( BUILDMENU )}, NULL },
{ "HWG__CREATEPOPUPMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG__CREATEPOPUPMENU )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "HWG_SEARCHPOSBITMAP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_SEARCHPOSBITMAP )}, NULL },
{ "SETMENUITEMBITMAPS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETMENUITEMBITMAPS )}, NULL },
{ "HWG_SETMENUINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETMENUINFO )}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AMENU", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BEGINMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_BEGINMENU )}, NULL },
{ "HWG_ISWIN7", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ISWIN7 )}, NULL },
{ "GETSYSTEMMETRICS", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSYSTEMMETRICS )}, NULL },
{ "HWG_CONTEXTMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_CONTEXTMENU )}, NULL },
{ "HWG_ENDMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ENDMENU )}, NULL },
{ "ACLONE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ACLONE )}, NULL },
{ "_HACCEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEACCELERATORTABLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEACCELERATORTABLE )}, NULL },
{ "HWG_DEFINEMENUITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_DEFINEMENUITEM )}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "STRTRAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTRAN )}, NULL },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "ADDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBITMAP )}, NULL },
{ "ADDFILE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DEFINEACCELITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_DEFINEACCELITEM )}, NULL },
{ "HWG_SETMENUITEMBITMAPS", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_SETMENUITEMBITMAPS )}, NULL },
{ "HWG_INSERTBITMAPMENU", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_INSERTBITMAPMENU )}, NULL },
{ "HWG__INSERTBITMAPMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG__INSERTBITMAPMENU )}, NULL },
{ "DELETEMENUITEM", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DELETEMENUITEM )}, NULL },
{ "MENU", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADEL )}, NULL },
{ "ASIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASIZE )}, NULL },
{ "HWG_DELETEMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DELETEMENU )}, NULL },
{ "GETMENUHANDLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETMENUHANDLE )}, NULL },
{ "(_INITSTATICS00011)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_MENU, "source\\menu.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_MENU
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_MENU )
   #include "hbiniseg.h"
#endif

HB_FUNC( HMENU )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,68,0,36,23,0,103,11,0,100,8,
		29,37,1,176,1,0,104,11,0,12,1,29,26,1,
		166,220,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,6,72,77,101,110,117,0,108,4,4,1,0,
		108,0,112,3,80,2,36,24,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,7,104,97,
		110,100,108,101,0,4,1,0,9,112,5,73,36,25,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,6,97,77,101,110,117,0,4,1,0,9,
		112,5,73,36,26,0,48,6,0,95,2,106,4,78,
		101,119,0,89,10,0,1,0,0,0,95,1,6,95,
		1,121,72,121,72,121,72,112,3,73,36,27,0,48,
		6,0,95,2,106,4,69,78,68,0,89,20,0,1,
		0,0,0,176,7,0,48,8,0,95,1,112,0,12,
		1,6,95,1,121,72,121,72,121,72,112,3,73,36,
		28,0,48,9,0,95,2,106,5,83,104,111,119,0,
		108,10,95,1,121,72,121,72,121,72,112,3,73,36,
		29,0,48,11,0,95,2,112,0,73,167,14,0,0,
		176,12,0,104,11,0,95,2,20,2,168,48,13,0,
		95,2,112,0,80,3,176,14,0,95,3,106,10,73,
		110,105,116,67,108,97,115,115,0,12,2,28,12,48,
		15,0,95,3,164,146,1,0,73,95,3,110,7,48,
		13,0,103,11,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HMENU_SHOW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,4,36,34,0,48,16,0,95,1,102,112,1,
		73,36,35,0,176,17,0,12,0,122,8,31,12,95,
		4,100,8,31,6,95,4,31,70,36,36,0,176,17,
		0,12,0,122,8,28,31,36,37,0,176,18,0,12,
		0,80,5,36,38,0,95,5,122,1,80,2,36,39,
		0,95,5,92,2,1,80,3,36,41,0,176,19,0,
		48,8,0,102,112,0,95,2,95,3,48,8,0,95,
		1,112,0,20,4,25,53,36,43,0,176,20,0,48,
		8,0,95,1,112,0,95,2,95,3,12,3,80,5,
		36,44,0,176,19,0,48,8,0,102,112,0,95,5,
		122,1,95,5,92,2,1,48,8,0,95,1,112,0,
		20,4,36,47,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_CREATEMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,52,0,176,22,0,176,23,0,12,0,
		165,80,1,12,1,28,8,36,53,0,100,110,7,36,
		56,0,4,0,0,100,100,95,1,4,4,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_SETMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,60,0,176,22,0,48,8,0,95,1,
		112,0,12,1,31,45,36,61,0,176,25,0,48,8,
		0,95,1,112,0,95,2,92,5,1,12,2,28,17,
		36,62,0,48,26,0,95,1,95,2,112,1,73,25,
		21,36,64,0,9,110,7,36,67,0,48,26,0,95,
		1,95,2,112,1,73,36,70,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_ADDMENUITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,1,6,36,81,0,95,6,100,8,28,18,36,82,
		0,176,28,0,95,1,122,1,12,1,122,72,80,6,
		36,85,0,95,1,92,5,1,80,7,36,86,0,176,
		29,0,95,7,95,2,95,6,122,49,120,95,3,100,
		95,4,12,7,80,7,36,88,0,95,6,176,28,0,
		95,1,122,1,12,1,15,28,71,36,89,0,95,4,
		28,29,36,90,0,176,30,0,95,1,122,1,4,0,
		0,95,2,95,3,121,95,7,4,5,0,20,2,25,
		24,36,92,0,176,30,0,95,1,122,1,95,5,95,
		2,95,3,121,4,4,0,20,2,36,94,0,176,31,
		0,95,1,122,1,20,1,7,36,96,0,176,30,0,
		95,1,122,1,100,20,2,36,97,0,176,32,0,95,
		1,122,1,95,6,20,2,36,98,0,95,4,28,27,
		36,99,0,4,0,0,95,2,95,3,121,95,7,4,
		5,0,95,1,122,1,95,6,2,25,22,36,101,0,
		95,5,95,2,95,3,121,4,4,0,95,1,122,1,
		95,6,2,36,103,0,95,1,122,1,95,6,1,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_FINDMENUITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,2,3,36,110,0,122,80,3,36,111,0,95,3,
		176,28,0,95,1,122,1,12,1,34,28,96,36,112,
		0,95,1,122,1,95,3,1,92,3,1,95,2,8,
		28,9,36,113,0,95,1,110,7,36,114,0,176,28,
		0,95,1,122,1,95,3,1,12,1,92,4,15,28,
		43,36,115,0,176,33,0,95,1,122,1,95,3,1,
		95,2,96,4,0,12,3,165,80,5,100,69,28,16,
		36,116,0,95,4,80,3,36,117,0,95,5,110,7,
		36,120,0,174,3,0,25,147,36,122,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_GETSUBMENUHANDLE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,125,0,176,33,0,95,1,95,2,12,
		2,80,3,36,127,0,95,3,100,8,28,5,121,25,
		7,95,3,92,5,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( BUILDMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,4,5,116,68,0,36,132,0,95,4,100,8,28,
		55,36,133,0,95,5,100,8,31,6,95,5,31,14,
		36,134,0,176,23,0,12,0,80,6,25,12,36,136,
		0,176,36,0,12,0,80,6,36,138,0,95,1,100,
		100,100,95,6,4,5,0,80,8,26,137,0,36,140,
		0,95,1,92,5,1,80,6,36,141,0,176,28,0,
		95,1,122,1,12,1,80,7,36,142,0,95,1,122,
		1,95,4,1,80,8,36,144,0,176,37,0,95,8,
		92,4,1,12,1,106,2,76,0,8,28,8,9,95,
		8,92,4,2,36,145,0,176,29,0,95,6,95,8,
		92,2,1,95,7,122,72,120,95,8,92,3,1,95,
		8,92,4,1,120,12,7,80,6,36,146,0,176,28,
		0,95,8,12,1,92,5,35,28,16,36,147,0,176,
		30,0,95,8,95,6,20,2,25,12,36,149,0,95,
		6,95,8,92,5,2,36,153,0,122,80,7,36,154,
		0,95,7,176,28,0,95,8,122,1,12,1,34,29,
		221,0,36,155,0,176,37,0,95,8,122,1,95,7,
		1,122,1,12,1,106,2,65,0,8,28,19,36,156,
		0,176,35,0,95,8,100,100,95,7,20,4,26,171,
		0,36,158,0,95,8,122,1,95,7,1,122,1,100,
		8,31,17,95,8,122,1,95,7,1,92,2,1,100,
		69,29,140,0,36,160,0,176,37,0,95,8,122,1,
		95,7,1,92,4,1,12,1,106,2,76,0,8,28,
		13,9,95,8,122,1,95,7,1,92,4,2,36,162,
		0,176,29,0,95,6,95,8,122,1,95,7,1,92,
		2,1,95,7,120,95,8,122,1,95,7,1,92,3,
		1,95,8,122,1,95,7,1,92,4,1,9,20,7,
		36,163,0,176,38,0,95,8,122,1,95,7,1,92,
		3,1,12,1,80,9,36,164,0,95,9,122,1,28,
		30,36,165,0,176,39,0,95,6,95,8,122,1,95,
		7,1,92,3,1,95,9,92,2,1,106,1,0,20,
		4,36,170,0,174,7,0,26,23,255,36,172,0,95,
		2,100,69,28,50,95,3,100,69,28,44,36,173,0,
		176,24,0,95,3,95,8,20,2,36,174,0,103,10,
		0,100,69,28,63,36,175,0,176,40,0,48,8,0,
		95,3,112,0,103,10,0,20,2,25,43,36,177,0,
		103,6,0,100,69,28,33,36,178,0,48,41,0,103,
		6,0,95,8,92,5,1,112,1,73,36,179,0,48,
		42,0,103,6,0,95,8,112,1,73,36,181,0,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_BEGINMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,2,6,116,68,0,36,185,0,95,1,100,69,29,
		141,0,36,186,0,4,0,0,82,1,0,36,187,0,
		4,0,0,82,3,0,36,188,0,4,0,0,82,7,
		0,36,189,0,95,1,82,2,0,36,190,0,100,82,
		6,0,36,191,0,121,82,4,0,36,192,0,95,2,
		100,8,28,7,93,0,125,25,4,95,2,82,5,0,
		36,193,0,95,5,100,5,31,9,176,44,0,12,0,
		31,11,176,45,0,92,71,12,1,25,4,95,5,82,
		8,0,36,194,0,95,6,100,5,31,9,176,44,0,
		12,0,31,11,176,45,0,92,72,12,1,25,4,95,
		6,82,9,0,36,195,0,95,4,82,10,0,25,92,
		36,197,0,95,2,100,8,28,8,104,5,0,172,25,
		4,95,2,80,2,36,198,0,103,1,0,80,7,36,
		199,0,122,165,80,8,25,22,36,200,0,176,31,0,
		95,7,12,1,122,1,80,7,36,199,0,175,8,0,
		103,4,0,15,28,232,36,202,0,104,4,0,170,36,
		203,0,176,30,0,95,7,4,0,0,95,3,95,2,
		121,4,4,0,20,2,36,205,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_CONTEXTMENU )
{
	static const HB_BYTE pcode[] =
	{
		116,68,0,36,208,0,4,0,0,82,1,0,36,209,
		0,4,0,0,82,7,0,36,210,0,100,82,2,0,
		36,211,0,121,82,4,0,36,212,0,97,132,128,0,
		0,82,5,0,36,213,0,48,2,0,176,0,0,12,
		0,112,0,82,6,0,36,214,0,103,6,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_ENDMENU )
{
	static const HB_BYTE pcode[] =
	{
		116,68,0,36,217,0,103,4,0,121,15,28,12,36,
		218,0,104,4,0,169,26,134,0,36,221,0,176,35,
		0,176,48,0,103,1,0,12,1,103,2,0,100,69,
		28,12,48,8,0,103,2,0,112,0,25,3,100,103,
		2,0,100,103,2,0,100,69,28,5,9,25,3,120,
		20,5,36,222,0,103,2,0,100,69,28,39,103,3,
		0,100,69,28,32,176,22,0,103,3,0,12,1,31,
		22,36,223,0,48,49,0,103,2,0,176,50,0,103,
		3,0,12,1,112,1,73,36,225,0,100,82,1,0,
		36,226,0,100,82,7,0,36,227,0,100,82,3,0,
		36,228,0,100,82,2,0,36,229,0,100,82,6,0,
		36,231,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_DEFINEMENUITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,4,9,116,68,0,36,236,0,95,9,100,8,28,
		5,9,25,4,95,9,80,9,36,237,0,95,4,100,
		8,28,5,9,25,4,95,4,80,4,36,238,0,176,
		52,0,95,9,28,6,92,2,25,3,121,95,4,28,
		5,122,25,3,121,12,2,80,13,36,240,0,103,1,
		0,80,10,36,241,0,122,165,80,11,25,22,36,242,
		0,176,31,0,95,10,12,1,122,1,80,10,36,241,
		0,175,11,0,103,4,0,15,28,232,36,244,0,176,
		22,0,95,1,12,1,31,23,36,245,0,176,53,0,
		95,1,106,3,92,116,0,106,2,9,0,12,3,80,
		1,36,247,0,95,2,100,8,28,14,95,1,100,69,
		28,8,104,5,0,172,25,4,95,2,80,2,36,248,
		0,176,30,0,95,10,95,3,95,1,95,2,95,13,
		4,4,0,20,2,36,249,0,95,7,100,69,31,11,
		176,22,0,95,7,12,1,31,120,36,250,0,95,8,
		100,8,28,5,9,80,8,36,251,0,95,8,31,17,
		176,54,0,106,2,46,0,95,7,12,2,121,5,28,
		33,36,252,0,48,55,0,176,56,0,12,0,95,7,
		97,32,144,0,0,100,103,8,0,103,9,0,112,5,
		80,12,25,27,36,254,0,48,57,0,176,56,0,12,
		0,95,7,100,120,103,8,0,103,9,0,112,5,80,
		12,36,0,1,176,30,0,103,7,0,120,48,8,0,
		95,12,112,0,95,1,95,2,4,4,0,20,2,25,
		24,36,2,1,176,30,0,103,7,0,9,106,1,0,
		95,1,95,2,4,4,0,20,2,36,4,1,95,5,
		100,69,28,28,95,6,100,69,28,22,36,5,1,176,
		30,0,103,3,0,95,5,95,6,95,2,4,3,0,
		20,2,36,7,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_DEFINEACCELITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,2,4,116,68,0,36,11,1,103,1,0,80,5,
		36,12,1,122,165,80,6,25,22,36,13,1,176,31,
		0,95,5,12,1,122,1,80,5,36,12,1,175,6,
		0,103,4,0,15,28,232,36,15,1,95,1,100,8,
		28,8,104,5,0,172,25,4,95,1,80,1,36,16,
		1,176,30,0,95,5,95,2,100,95,1,121,4,4,
		0,20,2,36,17,1,176,30,0,103,3,0,95,3,
		95,4,95,1,4,3,0,20,2,36,18,1,120,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_SETMENUITEMBITMAPS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,4,36,22,1,176,33,0,95,1,95,2,12,
		2,80,5,36,25,1,95,5,100,8,28,5,121,25,
		7,95,5,92,5,1,80,6,36,26,1,176,39,0,
		95,6,95,2,95,3,95,4,20,4,36,27,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_INSERTBITMAPMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,3,4,36,30,1,176,33,0,95,1,95,2,12,
		2,80,5,36,34,1,95,4,100,8,31,6,95,4,
		31,21,36,35,1,48,57,0,176,56,0,12,0,95,
		3,112,1,80,7,25,19,36,37,1,48,55,0,176,
		56,0,12,0,95,3,112,1,80,7,36,39,1,95,
		5,100,8,28,5,121,25,7,95,5,92,5,1,80,
		6,36,40,1,176,61,0,95,6,95,2,48,8,0,
		95,7,112,0,20,3,36,41,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_SEARCHPOSBITMAP )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,116,68,0,36,45,1,122,80,2,9,106,
		1,0,4,2,0,80,3,36,47,1,103,7,0,100,
		69,28,77,36,48,1,95,2,176,28,0,103,7,0,
		12,1,34,28,61,36,50,1,103,7,0,95,2,1,
		92,4,1,95,1,8,28,36,36,51,1,103,7,0,
		95,2,1,122,1,103,7,0,95,2,1,92,2,1,
		103,7,0,95,2,1,92,3,1,4,3,0,80,3,
		36,54,1,174,2,0,25,183,36,59,1,95,3,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DELETEMENUITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,64,1,176,33,0,48,63,0,95,1,
		112,0,95,2,96,4,0,12,3,165,80,3,100,69,
		28,61,36,65,1,176,64,0,95,3,122,1,95,4,
		20,2,36,66,1,176,65,0,95,3,122,1,176,28,
		0,95,3,122,1,12,1,122,49,20,2,36,68,1,
		176,66,0,176,67,0,48,8,0,95,1,112,0,12,
		1,95,2,20,2,36,70,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,68,0,11,0,7
	};

	hb_vmExecute( pcode, symbols );
}

