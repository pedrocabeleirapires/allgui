/*
 * Harbour 3.2.0dev (r1310312321)
 * Microsoft Visual C 16.0.40219 (32-bit)
 * Generated C source from "source\hgrid.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HGRID );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HGRID_NEW );
HB_FUNC_STATIC( HGRID_ACTIVATE );
HB_FUNC_STATIC( HGRID_INIT );
HB_FUNC_EXTERN( AADD );
HB_FUNC_STATIC( HGRID_REFRESH );
HB_FUNC_EXTERN( HWG_LISTVIEW_UPDATE );
HB_FUNC_EXTERN( HWG_LISTVIEW_GETFIRSTITEM );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETITEMCOUNT );
HB_FUNC_STATIC( HGRID_NOTIFY );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_LISTVIEW_CREATE );
HB_FUNC_EXTERN( HWG_LOADIMAGE );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG_GETBITMAPSIZE );
HB_FUNC_EXTERN( HWG_CREATEIMAGELIST );
HB_FUNC_EXTERN( HWG_IMAGELIST_ADD );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETIMAGELIST );
HB_FUNC_EXTERN( HWG_LISTVIEW_INIT );
HB_FUNC_EXTERN( HWG_LISTVIEW_ADDCOLUMN );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETTEXTCOLOR );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETBKCOLOR );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETTEXTBKCOLOR );
HB_FUNC_EXTERN( HWG_LISTVIEW_GETTOPINDEX );
HB_FUNC_EXTERN( HWG_LISTVIEW_GETCOUNTPERPAGE );
HB_FUNC_EXTERN( HWG_LISTVIEW_REDRAWITEMS );
HB_FUNC( HWG_LISTVIEWNOTIFY );
HB_FUNC_EXTERN( HWG_GETNOTIFYCODE );
HB_FUNC_EXTERN( HWG_LISTVIEW_GETGRIDKEY );
HB_FUNC_EXTERN( HWG_LISTVIEW_HITTEST );
HB_FUNC_EXTERN( HWG_GETCURSORPOS );
HB_FUNC_EXTERN( HWG_GETWINDOWRECT );
HB_FUNC_EXTERN( HWG_LISTVIEW_GETDISPINFO );
HB_FUNC_EXTERN( HWG_LISTVIEW_SETDISPINFO );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HGRID )
{ "HGRID", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HGRID_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID_NEW )}, NULL },
{ "HGRID_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID_ACTIVATE )}, NULL },
{ "HGRID_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID_INIT )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ACOLUMNS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HGRID_REFRESH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID_REFRESH )}, NULL },
{ "HWG_LISTVIEW_UPDATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_UPDATE )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_GETFIRSTITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_GETFIRSTITEM )}, NULL },
{ "HWG_LISTVIEW_SETITEMCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETITEMCOUNT )}, NULL },
{ "HGRID_NOTIFY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HGRID_NOTIFY )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ITEMCOUNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ABITMAPS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BGFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_COLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BKCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LNOSCROLL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LNOBORDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LNOLINES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LNOHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BENTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BKEYDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BPOSCHG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BDISPINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_CREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_CREATE )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LNOHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LNOSCROLL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LOADIMAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LOADIMAGE )}, NULL },
{ "ABITMAPS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "HWG_GETBITMAPSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETBITMAPSIZE )}, NULL },
{ "_HIM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_CREATEIMAGELIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CREATEIMAGELIST )}, NULL },
{ "HWG_IMAGELIST_ADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_IMAGELIST_ADD )}, NULL },
{ "HIM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_SETIMAGELIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETIMAGELIST )}, NULL },
{ "HWG_LISTVIEW_INIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_INIT )}, NULL },
{ "ITEMCOUNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LNOLINES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_ADDCOLUMN", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_ADDCOLUMN )}, NULL },
{ "COLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_SETTEXTCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETTEXTCOLOR )}, NULL },
{ "BKCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_SETBKCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETBKCOLOR )}, NULL },
{ "HWG_LISTVIEW_SETTEXTBKCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETTEXTBKCOLOR )}, NULL },
{ "HWG_LISTVIEW_GETTOPINDEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_GETTOPINDEX )}, NULL },
{ "HWG_LISTVIEW_GETCOUNTPERPAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_GETCOUNTPERPAGE )}, NULL },
{ "HWG_LISTVIEW_REDRAWITEMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_REDRAWITEMS )}, NULL },
{ "HWG_LISTVIEWNOTIFY", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_LISTVIEWNOTIFY )}, NULL },
{ "HWG_GETNOTIFYCODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETNOTIFYCODE )}, NULL },
{ "BKEYDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_GETGRIDKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_GETGRIDKEY )}, NULL },
{ "BENTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_HITTEST", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_HITTEST )}, NULL },
{ "HWG_GETCURSORPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETCURSORPOS )}, NULL },
{ "HWG_GETWINDOWRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETWINDOWRECT )}, NULL },
{ "_NROW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BGFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ROW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPOSCHG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BDISPINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_LISTVIEW_GETDISPINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_GETDISPINFO )}, NULL },
{ "HWG_LISTVIEW_SETDISPINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_LISTVIEW_SETDISPINFO )}, NULL },
{ "NROW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HGRID, "source\\hgrid.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HGRID
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HGRID )
   #include "hbiniseg.h"
#endif

HB_FUNC( HGRID )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,98,0,36,37,0,103,1,0,100,8,
		29,127,4,176,1,0,104,1,0,12,1,29,116,4,
		166,54,4,0,122,80,1,48,2,0,176,3,0,12,
		0,106,6,72,71,114,105,100,0,108,4,4,1,0,
		108,0,112,3,80,2,36,39,0,48,5,0,95,2,
		100,106,14,83,89,83,76,73,83,84,86,73,69,87,
		51,50,0,95,1,121,72,121,72,121,72,121,72,106,
		9,119,105,110,99,108,97,115,115,0,4,1,0,9,
		112,5,73,36,40,0,48,6,0,95,2,100,4,0,
		0,95,1,121,72,121,72,121,72,106,9,97,66,105,
		116,77,97,112,115,0,4,1,0,9,112,5,73,36,
		41,0,48,6,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,10,73,116,101,109,67,111,117,110,116,
		0,4,1,0,9,112,5,73,36,42,0,48,6,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,6,
		99,111,108,111,114,0,4,1,0,9,112,5,73,36,
		43,0,48,6,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,8,98,107,99,111,108,111,114,0,4,
		1,0,9,112,5,73,36,44,0,48,6,0,95,2,
		100,4,0,0,95,1,121,72,121,72,121,72,106,9,
		97,67,111,108,117,109,110,115,0,4,1,0,9,112,
		5,73,36,45,0,48,6,0,95,2,100,121,95,1,
		121,72,121,72,121,72,106,5,110,82,111,119,0,4,
		1,0,9,112,5,73,36,46,0,48,6,0,95,2,
		100,121,95,1,121,72,121,72,121,72,106,5,110,67,
		111,108,0,4,1,0,9,112,5,73,36,48,0,48,
		6,0,95,2,100,9,95,1,121,72,121,72,121,72,
		106,10,108,78,111,83,99,114,111,108,108,0,4,1,
		0,9,112,5,73,36,49,0,48,6,0,95,2,100,
		9,95,1,121,72,121,72,121,72,106,10,108,78,111,
		66,111,114,100,101,114,0,4,1,0,9,112,5,73,
		36,50,0,48,6,0,95,2,100,9,95,1,121,72,
		121,72,121,72,106,9,108,78,111,76,105,110,101,115,
		0,4,1,0,9,112,5,73,36,51,0,48,6,0,
		95,2,100,9,95,1,121,72,121,72,121,72,106,10,
		108,78,111,72,101,97,100,101,114,0,4,1,0,9,
		112,5,73,36,53,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,7,98,69,110,116,101,
		114,0,4,1,0,9,112,5,73,36,54,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		9,98,75,101,121,68,111,119,110,0,4,1,0,9,
		112,5,73,36,55,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,8,98,80,111,115,67,
		104,103,0,4,1,0,9,112,5,73,36,56,0,48,
		6,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,10,98,68,105,115,112,73,110,102,111,0,4,1,
		0,9,112,5,73,36,58,0,48,6,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,8,98,71,102,
		111,99,117,115,0,4,1,0,9,112,5,73,36,59,
		0,48,6,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,8,98,76,102,111,99,117,115,0,4,1,
		0,9,112,5,73,36,63,0,48,7,0,95,2,106,
		4,78,101,119,0,108,8,95,1,121,72,121,72,121,
		72,112,3,73,36,65,0,48,7,0,95,2,106,9,
		65,99,116,105,118,97,116,101,0,108,9,95,1,121,
		72,121,72,121,72,112,3,73,36,66,0,48,7,0,
		95,2,106,5,73,110,105,116,0,108,10,95,1,121,
		72,121,72,121,72,112,3,73,36,67,0,48,11,0,
		95,2,106,10,65,100,100,67,111,108,117,109,110,0,
		89,31,0,5,0,0,0,176,12,0,48,13,0,95,
		1,112,0,95,2,95,3,95,4,95,5,4,4,0,
		12,2,6,95,1,121,72,121,72,121,72,112,3,73,
		36,68,0,48,7,0,95,2,106,8,82,101,102,114,
		101,115,104,0,108,14,95,1,121,72,121,72,121,72,
		112,3,73,36,69,0,48,11,0,95,2,106,12,82,
		101,102,114,101,115,104,76,105,110,101,0,89,32,0,
		1,0,0,0,176,15,0,48,16,0,95,1,112,0,
		176,17,0,48,16,0,95,1,112,0,12,1,12,2,
		6,95,1,121,72,121,72,121,72,112,3,73,36,70,
		0,48,11,0,95,2,106,13,83,101,116,73,116,101,
		109,67,111,117,110,116,0,89,22,0,2,0,0,0,
		176,18,0,48,16,0,95,1,112,0,95,2,12,2,
		6,95,1,121,72,121,72,121,72,112,3,73,36,71,
		0,48,11,0,95,2,106,4,82,111,119,0,89,20,
		0,1,0,0,0,176,17,0,48,16,0,95,1,112,
		0,12,1,6,95,1,121,72,121,72,121,72,112,3,
		73,36,72,0,48,7,0,95,2,106,7,78,111,116,
		105,102,121,0,108,19,95,1,121,72,121,72,121,72,
		112,3,73,36,73,0,48,20,0,95,2,112,0,73,
		167,14,0,0,176,21,0,104,1,0,95,2,20,2,
		168,48,22,0,95,2,112,0,80,3,176,23,0,95,
		3,106,10,73,110,105,116,67,108,97,115,115,0,12,
		2,28,12,48,24,0,95,3,164,146,1,0,73,95,
		3,110,7,48,22,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HGRID_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,25,36,80,0,176,25,0,95,3,100,8,28,
		5,121,25,4,95,3,97,8,0,1,0,95,16,28,
		5,121,25,7,97,0,0,128,0,72,122,72,93,0,
		16,72,92,4,72,12,2,80,3,36,82,0,48,2,
		0,48,26,0,102,112,0,95,1,95,2,95,3,95,
		4,95,5,95,6,95,7,95,8,95,9,95,10,95,
		11,112,11,73,36,83,0,95,25,100,8,28,7,4,
		0,0,80,25,36,84,0,48,27,0,102,95,20,112,
		1,73,36,85,0,48,28,0,102,95,25,112,1,73,
		36,86,0,48,29,0,102,95,13,112,1,73,36,87,
		0,48,30,0,102,95,14,112,1,73,36,89,0,48,
		31,0,102,95,22,112,1,73,36,90,0,48,32,0,
		102,95,23,112,1,73,36,92,0,48,33,0,102,95,
		15,112,1,73,36,93,0,48,34,0,102,95,16,112,
		1,73,36,94,0,48,35,0,102,95,21,112,1,73,
		36,95,0,48,36,0,102,95,24,112,1,73,36,97,
		0,48,37,0,102,95,12,112,1,73,36,98,0,48,
		38,0,102,95,17,112,1,73,36,99,0,48,39,0,
		102,95,18,112,1,73,36,100,0,48,40,0,102,95,
		19,112,1,73,36,102,0,176,41,0,20,0,36,104,
		0,48,42,0,102,112,0,73,36,106,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HGRID_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,109,0,176,43,0,48,16,0,48,44,0,102,112,
		0,112,0,12,1,31,86,36,110,0,48,45,0,102,
		176,46,0,48,16,0,48,44,0,102,112,0,112,0,
		48,47,0,102,112,0,48,48,0,102,112,0,48,49,
		0,102,112,0,48,50,0,102,112,0,48,51,0,102,
		112,0,48,52,0,102,112,0,48,53,0,102,112,0,
		48,54,0,102,112,0,12,9,112,1,73,36,112,0,
		48,55,0,102,112,0,73,36,114,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HGRID_INIT )
{
	static const HB_BYTE pcode[] =
	{
		13,5,0,36,118,0,4,0,0,80,3,36,122,0,
		48,56,0,102,112,0,32,65,2,36,123,0,48,55,
		0,48,26,0,102,112,0,112,0,73,36,124,0,122,
		165,80,5,25,39,36,125,0,176,12,0,95,3,176,
		57,0,100,48,58,0,102,112,0,95,5,1,121,121,
		121,93,64,32,12,6,20,2,36,124,0,175,5,0,
		176,59,0,48,58,0,102,112,0,12,1,15,28,207,
		36,128,0,176,59,0,95,3,12,1,121,15,29,8,
		1,36,130,0,176,60,0,95,3,122,1,12,1,80,
		4,36,132,0,95,4,92,3,1,92,4,8,28,34,
		36,133,0,48,61,0,102,176,62,0,4,0,0,95,
		4,122,1,95,4,92,2,1,122,92,5,12,5,112,
		1,73,25,91,36,134,0,95,4,92,3,1,92,8,
		8,28,34,36,135,0,48,61,0,102,176,62,0,4,
		0,0,95,4,122,1,95,4,92,2,1,122,92,9,
		12,5,112,1,73,25,46,36,136,0,95,4,92,3,
		1,92,24,8,28,33,36,137,0,48,61,0,102,176,
		62,0,4,0,0,95,4,122,1,95,4,92,2,1,
		122,93,255,0,12,5,112,1,73,36,140,0,122,165,
		80,2,25,76,36,142,0,176,60,0,95,3,95,2,
		1,12,1,80,4,36,144,0,95,4,92,3,1,92,
		24,8,28,23,36,146,0,176,63,0,48,64,0,102,
		112,0,95,3,95,2,1,20,2,25,21,36,148,0,
		176,63,0,48,64,0,102,112,0,95,3,95,2,1,
		20,2,36,140,0,175,2,0,176,59,0,95,3,12,
		1,15,28,174,36,153,0,176,65,0,48,16,0,102,
		112,0,48,64,0,102,112,0,20,2,36,157,0,176,
		66,0,48,16,0,102,112,0,48,67,0,102,112,0,
		48,68,0,102,112,0,20,3,36,159,0,122,165,80,
		1,25,90,36,160,0,176,69,0,48,16,0,102,112,
		0,95,1,48,13,0,102,112,0,95,1,1,92,2,
		1,48,13,0,102,112,0,95,1,1,122,1,48,13,
		0,102,112,0,95,1,1,92,3,1,48,13,0,102,
		112,0,95,1,1,92,4,1,100,69,28,16,48,13,
		0,102,112,0,95,1,1,92,4,1,25,3,121,20,
		6,36,159,0,175,1,0,176,59,0,48,13,0,102,
		112,0,12,1,15,28,156,36,163,0,48,70,0,102,
		112,0,100,69,28,22,36,164,0,176,71,0,48,16,
		0,102,112,0,48,70,0,102,112,0,20,2,36,168,
		0,48,72,0,102,112,0,100,69,28,42,36,169,0,
		176,73,0,48,16,0,102,112,0,48,72,0,102,112,
		0,20,2,36,170,0,176,74,0,48,16,0,102,112,
		0,48,72,0,102,112,0,20,2,36,173,0,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HGRID_REFRESH )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,178,0,176,75,0,48,16,0,102,112,
		0,12,1,80,1,36,180,0,95,1,176,76,0,48,
		16,0,102,112,0,12,1,72,80,2,36,182,0,176,
		77,0,48,16,0,102,112,0,95,1,95,2,20,3,
		36,183,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HGRID_NOTIFY )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,186,0,176,78,0,102,95,1,20,2,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_LISTVIEWNOTIFY )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,192,0,176,79,0,95,2,12,1,93,
		101,255,5,28,41,48,80,0,95,1,112,0,100,69,
		28,30,36,193,0,48,81,0,48,80,0,95,1,112,
		0,95,1,176,82,0,95,2,12,1,112,2,73,26,
		171,1,36,195,0,176,79,0,95,2,12,1,92,253,
		8,29,129,0,48,83,0,95,1,112,0,100,69,28,
		117,36,197,0,176,84,0,48,16,0,95,1,112,0,
		176,85,0,12,0,92,2,1,176,86,0,48,16,0,
		95,1,112,0,12,1,92,2,1,49,176,85,0,12,
		0,122,1,176,86,0,48,16,0,95,1,112,0,12,
		1,122,1,49,12,3,80,3,36,198,0,48,87,0,
		95,1,95,3,122,1,112,1,73,36,199,0,48,88,
		0,95,1,95,3,92,2,1,112,1,73,36,201,0,
		48,81,0,48,83,0,95,1,112,0,95,1,112,1,
		73,26,29,1,36,203,0,176,79,0,95,2,12,1,
		92,249,8,28,34,48,89,0,95,1,112,0,100,69,
		28,23,36,204,0,48,81,0,48,89,0,95,1,112,
		0,95,1,112,1,73,26,238,0,36,206,0,176,79,
		0,95,2,12,1,92,248,8,28,34,48,90,0,95,
		1,112,0,100,69,28,23,36,207,0,48,81,0,48,
		90,0,95,1,112,0,95,1,112,1,73,26,191,0,
		36,209,0,176,79,0,95,2,12,1,92,155,5,28,
		67,36,210,0,48,87,0,95,1,48,91,0,95,1,
		112,0,112,1,73,36,212,0,48,92,0,95,1,112,
		0,100,69,29,143,0,36,213,0,48,81,0,48,92,
		0,95,1,112,0,95,1,176,17,0,48,16,0,95,
		1,112,0,12,1,112,2,73,25,110,36,216,0,176,
		79,0,95,2,12,1,93,106,255,5,28,94,48,93,
		0,95,1,112,0,100,69,28,83,36,217,0,176,94,
		0,95,2,12,1,80,3,36,219,0,48,87,0,95,
		1,95,3,122,1,112,1,73,36,220,0,48,88,0,
		95,1,95,3,92,2,1,112,1,73,36,222,0,176,
		95,0,95,2,48,81,0,48,93,0,95,1,112,0,
		95,1,48,96,0,95,1,112,0,48,97,0,95,1,
		112,0,112,3,20,2,36,225,0,121,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,98,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

