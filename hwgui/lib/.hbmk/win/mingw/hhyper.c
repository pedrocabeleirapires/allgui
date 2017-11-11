/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( HSTATICLINK );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HSTATICEX );
HB_FUNC_EXTERN( HWG_LOADCURSOR );
HB_FUNC_STATIC( HSTATICLINK_NEW );
HB_FUNC_STATIC( HSTATICLINK_REDEFINE );
HB_FUNC_STATIC( HSTATICLINK_INIT );
HB_FUNC_STATIC( HSTATICLINK_ONEVENT );
HB_FUNC_STATIC( HSTATICLINK_GOTOLINKURL );
HB_FUNC_STATIC( HSTATICLINK_GETLINKTEXT );
HB_FUNC_STATIC( HSTATICLINK_SETLINKURL );
HB_FUNC_STATIC( HSTATICLINK_GETLINKURL );
HB_FUNC_STATIC( HSTATICLINK_SETVISITEDCOLOR );
HB_FUNC_STATIC( HSTATICLINK_SETHOVERCOLOR );
HB_FUNC_STATIC( HSTATICLINK_ONCLICKED );
HB_FUNC_STATIC( HSTATICLINK_ONSETCURSOR );
HB_FUNC_STATIC( HSTATICLINK_SETLINKTEXT );
HB_FUNC_STATIC( HSTATICLINK_SETLINKCOLOR );
HB_FUNC_STATIC( HSTATICLINK_PAINT );
HB_FUNC_STATIC( HSTATICLINK_ONMOUSEMOVE );
HB_FUNC_STATIC( HSTATICLINK_RESIZE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_RGB );
HB_FUNC_EXTERN( HFONT );
HB_FUNC_EXTERN( HWG_SETWINDOWTEXT );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( HWG_REDRAWWINDOW );
HB_FUNC_EXTERN( HWG_SETCURSOR );
HB_FUNC_EXTERN( HWG_INVALIDATERECT );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_EXTERN( HWG_MAKELPARAM );
HB_FUNC_EXTERN( HWG_GETSKIP );
HB_FUNC_EXTERN( HWG_ISCTRLSHIFT );
HB_FUNC_EXTERN( HWG_SHELLEXECUTE );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HWG_LOWORD );
HB_FUNC_EXTERN( HWG_HIWORD );
HB_FUNC_EXTERN( HWG_PTINRECT );
HB_FUNC_EXTERN( HWG_TRACKMOUSEVENT );
HB_FUNC_EXTERN( HWG_GETDRAWITEMINFO );
HB_FUNC_EXTERN( HWG_GETBITMAPSIZE );
HB_FUNC_EXTERN( HWG_COPYRECT );
HB_FUNC_EXTERN( HWG_SELFFOCUS );
HB_FUNC_EXTERN( HWG_SETBKMODE );
HB_FUNC_EXTERN( HWG_DRAWFOCUSRECT );
HB_FUNC_EXTERN( HWG_ISTHEMEDLOAD );
HB_FUNC_EXTERN( HWG_OPENTHEMEDATA );
HB_FUNC_EXTERN( HWG_DRAWTHEMEBACKGROUND );
HB_FUNC_EXTERN( HWG_CLOSETHEMEDATA );
HB_FUNC_EXTERN( HWG_PREPAREIMAGERECT );
HB_FUNC_EXTERN( HWG_DRAWTRANSPARENTBITMAP );
HB_FUNC_EXTERN( HWG_DRAWBITMAP );
HB_FUNC_EXTERN( HWG_SETBKCOLOR );
HB_FUNC_EXTERN( HWG_GETSYSCOLOR );
HB_FUNC_EXTERN( HWG_FILLRECT );
HB_FUNC_EXTERN( HWG_SELECTOBJECT );
HB_FUNC_EXTERN( HWG_SETTEXTCOLOR );
HB_FUNC_EXTERN( HWG_DRAWTEXT );
HB_FUNC_EXTERN( HWG_TXTRECT );
HB_FUNC_EXTERN( MIN );
HB_FUNC_EXTERN( MAX );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HHYPER )
{ "HSTATICLINK", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK ) }, NULL },
{ "__CLSLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSLOCKDEF ) }, NULL },
{ "NEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBCLASS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBCLASS ) }, NULL },
{ "HSTATICEX", { HB_FS_PUBLIC }, { HB_FUNCNAME( HSTATICEX ) }, NULL },
{ "ADDMULTIDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_LOADCURSOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_LOADCURSOR ) }, NULL },
{ "ADDMULTICLSDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMETHOD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HSTATICLINK_NEW", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_NEW ) }, NULL },
{ "HSTATICLINK_REDEFINE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_REDEFINE ) }, NULL },
{ "HSTATICLINK_INIT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_INIT ) }, NULL },
{ "HSTATICLINK_ONEVENT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_ONEVENT ) }, NULL },
{ "HSTATICLINK_GOTOLINKURL", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_GOTOLINKURL ) }, NULL },
{ "HSTATICLINK_GETLINKTEXT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_GETLINKTEXT ) }, NULL },
{ "HSTATICLINK_SETLINKURL", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_SETLINKURL ) }, NULL },
{ "HSTATICLINK_GETLINKURL", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_GETLINKURL ) }, NULL },
{ "HSTATICLINK_SETVISITEDCOLOR", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_SETVISITEDCOLOR ) }, NULL },
{ "HSTATICLINK_SETHOVERCOLOR", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_SETHOVERCOLOR ) }, NULL },
{ "ADDINLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_BFIRECHILD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HSTATICLINK_ONCLICKED", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_ONCLICKED ) }, NULL },
{ "HSTATICLINK_ONSETCURSOR", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_ONSETCURSOR ) }, NULL },
{ "HSTATICLINK_SETLINKTEXT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_SETLINKTEXT ) }, NULL },
{ "HSTATICLINK_SETLINKCOLOR", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_SETLINKCOLOR ) }, NULL },
{ "HSTATICLINK_PAINT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_PAINT ) }, NULL },
{ "HSTATICLINK_ONMOUSEMOVE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_ONMOUSEMOVE ) }, NULL },
{ "HSTATICLINK_RESIZE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HSTATICLINK_RESIZE ) }, NULL },
{ "CREATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__CLSUNLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSUNLOCKDEF ) }, NULL },
{ "INSTANCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__OBJHASMSG", { HB_FS_PUBLIC }, { HB_FUNCNAME( __OBJHASMSG ) }, NULL },
{ "INITCLASS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITOR ) }, NULL },
{ "_LALLUNDERLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EMPTY", { HB_FS_PUBLIC }, { HB_FUNCNAME( EMPTY ) }, NULL },
{ "LALLUNDERLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_HBITMAP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SUPER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_RGB", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_RGB ) }, NULL },
{ "_M_CSURL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_SHOVERCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_SLINKCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_SVISITEDCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_STATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OPARENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HFONT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HFONT ) }, NULL },
{ "NAME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "WIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "WEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CHARSET", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ITALIC", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STRIKEOUT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "UNDERLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "RELEASE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_OFONTUNDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NWIDTHOVER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BACKSTYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_STYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LINIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "RESIZE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "INIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETWINDOWTEXT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETWINDOWTEXT ) }, NULL },
{ "HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITAND", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITAND ) }, NULL },
{ "STYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_REDRAWWINDOW", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_REDRAWWINDOW ) }, NULL },
{ "NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETCURSOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETCURSOR ) }, NULL },
{ "M_HHYPERCURSOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONMOUSEMOVE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_INVALIDATERECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INVALIDATERECT ) }, NULL },
{ "ONSETCURSOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONCLICKED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SENDMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SENDMESSAGE ) }, NULL },
{ "HWG_MAKELPARAM", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_MAKELPARAM ) }, NULL },
{ "HWG_GETSKIP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSKIP ) }, NULL },
{ "HWG_ISCTRLSHIFT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ISCTRLSHIFT ) }, NULL },
{ "HWG_SHELLEXECUTE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SHELLEXECUTE ) }, NULL },
{ "M_CSURL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALTYPE", { HB_FS_PUBLIC }, { HB_FUNCNAME( VALTYPE ) }, NULL },
{ "BCLICK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "M_BFIRECHILD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SENDMESSAGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "GOTOLINKURL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_BVISITED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SETTEXT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_LOWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_LOWORD ) }, NULL },
{ "HWG_HIWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_HIWORD ) }, NULL },
{ "HWG_PTINRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_PTINRECT ) }, NULL },
{ "NWIDTHOVER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "M_BVISITED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_TRACKMOUSEVENT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_TRACKMOUSEVENT ) }, NULL },
{ "HWG_GETDRAWITEMINFO", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETDRAWITEMINFO ) }, NULL },
{ "HBITMAP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETBITMAPSIZE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETBITMAPSIZE ) }, NULL },
{ "HWG_COPYRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_COPYRECT ) }, NULL },
{ "HWG_SELFFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SELFFOCUS ) }, NULL },
{ "HWG_SETBKMODE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETBKMODE ) }, NULL },
{ "HWG_DRAWFOCUSRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWFOCUSRECT ) }, NULL },
{ "HWG_ISTHEMEDLOAD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ISTHEMEDLOAD ) }, NULL },
{ "WINDOWSMANIFEST", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_OPENTHEMEDATA", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_OPENTHEMEDATA ) }, NULL },
{ "HWG_DRAWTHEMEBACKGROUND", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTHEMEBACKGROUND ) }, NULL },
{ "HWG_CLOSETHEMEDATA", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CLOSETHEMEDATA ) }, NULL },
{ "HWG_PREPAREIMAGERECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_PREPAREIMAGERECT ) }, NULL },
{ "ISTYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BACKSTYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_DRAWTRANSPARENTBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTRANSPARENTBITMAP ) }, NULL },
{ "HWG_DRAWBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWBITMAP ) }, NULL },
{ "HWG_SETBKCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETBKCOLOR ) }, NULL },
{ "BCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETSYSCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSYSCOLOR ) }, NULL },
{ "HWG_FILLRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_FILLRECT ) }, NULL },
{ "HWG_SELECTOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SELECTOBJECT ) }, NULL },
{ "HWG_SETTEXTCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETTEXTCOLOR ) }, NULL },
{ "M_SVISITEDCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "M_SLINKCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "M_SHOVERCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OFONTUNDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_DRAWTEXT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTEXT ) }, NULL },
{ "MOVE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_TXTRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_TXTRECT ) }, NULL },
{ "MIN", { HB_FS_PUBLIC }, { HB_FUNCNAME( MIN ) }, NULL },
{ "MAX", { HB_FS_PUBLIC }, { HB_FUNCNAME( MAX ) }, NULL },
{ "(_INITSTATICS00001)", { HB_FS_INITEXIT | HB_FS_LOCAL }, { hb_INITSTATICS }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HHYPER, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HHYPER
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HHYPER )
   #include "hbiniseg.h"
#endif

HB_FUNC( HSTATICLINK )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,141,0,36,28,0,103,1,0,100,8,29,231,5,176,1,
		0,104,1,0,12,1,29,220,5,166,158,5,0,122,80,1,48,2,0,
		176,3,0,12,0,106,12,72,83,116,97,116,105,99,76,105,110,107,0,
		108,4,4,1,0,108,0,112,3,80,2,36,30,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,6,115,116,97,116,101,0,4,
		1,0,9,112,5,73,36,31,0,48,5,0,95,2,100,9,95,1,121,
		72,121,72,121,72,106,13,109,95,98,70,105,114,101,67,104,105,108,100,
		0,4,1,0,9,112,5,73,36,33,0,48,5,0,95,2,100,176,6,
		0,93,137,127,12,1,95,1,121,72,121,72,121,72,106,15,109,95,104,
		72,121,112,101,114,67,117,114,115,111,114,0,4,1,0,9,112,5,73,
		36,35,0,48,5,0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		13,109,95,98,77,111,117,115,101,79,118,101,114,0,4,1,0,9,112,
		5,73,36,36,0,48,5,0,95,2,100,9,95,1,121,72,121,72,121,
		72,106,11,109,95,98,86,105,115,105,116,101,100,0,4,1,0,9,112,
		5,73,36,38,0,48,5,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,12,109,95,111,84,101,120,116,70,111,110,116,0,4,1,0,9,
		112,5,73,36,39,0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,8,109,95,99,115,85,114,108,0,4,1,0,9,112,5,73,
		36,40,0,48,5,0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		3,100,99,0,4,1,0,9,112,5,73,36,42,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,14,109,95,115,72,111,118,101,
		114,67,111,108,111,114,0,4,1,0,9,112,5,73,36,43,0,48,5,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,13,109,95,115,76,
		105,110,107,67,111,108,111,114,0,4,1,0,9,112,5,73,36,44,0,
		48,5,0,95,2,100,100,95,1,121,72,121,72,121,72,106,16,109,95,
		115,86,105,115,105,116,101,100,67,111,108,111,114,0,4,1,0,9,112,
		5,73,36,46,0,48,5,0,95,2,100,9,95,1,121,72,121,72,121,
		72,106,13,97,108,108,77,111,117,115,101,79,118,101,114,0,4,1,0,
		9,112,5,73,36,47,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,8,104,66,105,116,109,97,112,0,4,1,0,9,112,5,
		73,36,48,0,48,5,0,95,2,100,121,95,1,121,72,121,72,121,72,
		106,7,105,83,116,121,108,101,0,4,1,0,9,112,5,73,36,49,0,
		48,5,0,95,2,100,120,95,1,121,72,121,72,121,72,106,14,108,65,
		108,108,85,110,100,101,114,108,105,110,101,0,4,1,0,9,112,5,73,
		36,50,0,48,5,0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		11,111,70,111,110,116,85,110,100,101,114,0,4,1,0,9,112,5,73,
		36,51,0,48,5,0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		6,108,108,111,115,116,0,4,1,0,9,112,5,73,36,52,0,48,5,
		0,95,2,100,9,95,1,121,72,121,72,121,72,106,11,108,79,118,101,
		114,84,105,116,108,101,0,4,1,0,9,112,5,73,36,53,0,48,5,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,11,110,87,105,100,
		116,104,79,118,101,114,0,4,1,0,9,112,5,73,36,56,0,48,7,
		0,95,2,100,106,7,83,84,65,84,73,67,0,95,1,121,72,121,72,
		121,72,121,72,106,9,119,105,110,99,108,97,115,115,0,4,1,0,9,
		112,5,73,36,59,0,48,8,0,95,2,106,4,78,101,119,0,108,9,
		95,1,121,72,121,72,121,72,112,3,73,36,61,0,48,8,0,95,2,
		106,9,82,101,100,101,102,105,110,101,0,108,10,95,1,121,72,121,72,
		121,72,112,3,73,36,62,0,48,8,0,95,2,106,5,73,78,73,84,
		0,108,11,95,1,121,72,121,72,121,72,112,3,73,36,63,0,48,8,
		0,95,2,106,8,111,110,69,118,101,110,116,0,108,12,95,1,121,72,
		121,72,121,72,112,3,73,36,64,0,48,8,0,95,2,106,12,71,111,
		84,111,76,105,110,107,85,114,108,0,108,13,95,1,121,72,121,72,121,
		72,112,3,73,36,65,0,48,8,0,95,2,106,12,71,101,116,76,105,
		110,107,84,101,120,116,0,108,14,95,1,121,72,121,72,121,72,112,3,
		73,36,66,0,48,8,0,95,2,106,11,83,101,116,76,105,110,107,85,
		114,108,0,108,15,95,1,121,72,121,72,121,72,112,3,73,36,67,0,
		48,8,0,95,2,106,11,71,101,116,76,105,110,107,85,114,108,0,108,
		16,95,1,121,72,121,72,121,72,112,3,73,36,68,0,48,8,0,95,
		2,106,16,83,101,116,86,105,115,105,116,101,100,67,111,108,111,114,0,
		108,17,95,1,121,72,121,72,121,72,112,3,73,36,69,0,48,8,0,
		95,2,106,14,83,101,116,72,111,118,101,114,67,111,108,111,114,0,108,
		18,95,1,121,72,121,72,121,72,112,3,73,36,70,0,48,19,0,95,
		2,106,13,83,101,116,70,105,114,101,67,104,105,108,100,0,89,17,0,
		2,0,0,0,48,20,0,95,1,95,2,112,1,6,95,1,121,72,121,
		72,121,72,112,3,73,36,71,0,48,8,0,95,2,106,10,79,110,67,
		108,105,99,107,101,100,0,108,21,95,1,121,72,121,72,121,72,112,3,
		73,36,72,0,48,8,0,95,2,106,12,79,110,83,101,116,67,117,114,
		115,111,114,0,108,22,95,1,121,72,121,72,121,72,112,3,73,36,73,
		0,48,8,0,95,2,106,12,83,101,116,76,105,110,107,84,101,120,116,
		0,108,23,95,1,121,72,121,72,121,72,112,3,73,36,74,0,48,8,
		0,95,2,106,13,83,101,116,76,105,110,107,67,111,108,111,114,0,108,
		24,95,1,121,72,121,72,121,72,112,3,73,36,75,0,48,8,0,95,
		2,106,6,80,65,105,110,116,0,108,25,95,1,121,72,121,72,121,72,
		112,3,73,36,76,0,48,8,0,95,2,106,12,79,110,77,111,117,115,
		101,77,111,118,101,0,108,26,95,1,121,72,121,72,121,72,112,3,73,
		36,77,0,48,8,0,95,2,106,7,82,101,115,105,122,101,0,108,27,
		95,1,121,72,121,72,121,72,112,3,73,36,79,0,48,28,0,95,2,
		112,0,73,167,14,0,0,176,29,0,104,1,0,95,2,20,2,168,48,
		30,0,95,2,112,0,80,3,176,31,0,95,3,106,10,73,110,105,116,
		67,108,97,115,115,0,12,2,28,12,48,32,0,95,3,164,146,1,0,
		73,95,3,110,7,48,30,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,22,36,85,0,176,33,0,95,3,93,2,1,12,2,80,3,36,
		86,0,48,34,0,102,176,35,0,95,17,12,1,28,5,9,25,8,48,
		36,0,102,112,0,112,1,73,36,87,0,48,37,0,102,95,8,100,69,
		28,6,95,8,25,19,106,15,72,87,71,85,73,32,72,111,109,101,80,
		97,103,101,0,112,1,73,36,88,0,48,38,0,102,95,21,112,1,73,
		36,91,0,48,2,0,48,39,0,102,112,0,95,1,95,2,95,3,95,
		4,95,5,95,6,95,7,95,8,95,9,95,10,95,11,95,12,95,13,
		95,14,95,15,95,16,95,22,112,17,73,36,93,0,95,18,100,8,28,
		16,176,40,0,92,5,92,34,93,143,0,12,3,80,18,36,94,0,95,
		19,100,8,28,14,176,40,0,121,121,93,255,0,12,3,80,19,36,95,
		0,95,20,100,8,28,14,176,40,0,93,255,0,121,121,12,3,80,20,
		36,96,0,48,41,0,102,95,17,112,1,73,36,97,0,48,42,0,102,
		95,20,112,1,73,36,98,0,48,43,0,102,95,19,112,1,73,36,99,
		0,48,44,0,102,95,18,112,1,73,36,101,0,48,45,0,102,121,112,
		1,73,36,102,0,48,37,0,102,95,8,100,8,28,7,106,1,0,25,
		4,95,8,112,1,73,36,105,0,48,46,0,102,112,0,100,8,29,207,
		0,36,106,0,48,46,0,48,47,0,102,112,0,112,0,100,69,29,139,
		0,36,108,0,48,48,0,102,48,49,0,176,50,0,12,0,48,51,0,
		48,46,0,48,47,0,102,112,0,112,0,112,0,48,52,0,48,46,0,
		48,47,0,102,112,0,112,0,112,0,48,53,0,48,46,0,48,47,0,
		102,112,0,112,0,112,0,48,54,0,48,46,0,48,47,0,102,112,0,
		112,0,112,0,48,55,0,48,46,0,48,47,0,102,112,0,112,0,112,
		0,48,56,0,48,46,0,48,47,0,102,112,0,112,0,112,0,122,48,
		57,0,48,46,0,48,47,0,102,112,0,112,0,112,0,112,8,112,1,
		73,26,174,0,36,110,0,48,48,0,102,48,49,0,176,50,0,12,0,
		106,6,65,114,105,97,108,0,121,92,244,100,100,100,48,36,0,102,112,
		0,28,5,122,25,3,100,100,112,8,112,1,73,25,124,36,113,0,48,
		58,0,48,46,0,102,112,0,112,0,121,8,28,106,48,36,0,102,112,
		0,28,98,36,114,0,48,46,0,102,112,0,80,23,36,115,0,48,59,
		0,48,46,0,102,112,0,112,0,73,36,117,0,48,48,0,102,48,49,
		0,176,50,0,12,0,48,51,0,95,23,112,0,48,52,0,95,23,112,
		0,48,53,0,95,23,112,0,48,54,0,95,23,112,0,48,55,0,95,
		23,112,0,48,56,0,95,23,112,0,122,48,57,0,95,23,112,0,112,
		8,112,1,73,36,120,0,48,60,0,102,48,49,0,176,50,0,12,0,
		48,51,0,48,46,0,102,112,0,112,0,121,48,53,0,48,46,0,102,
		112,0,112,0,100,100,100,122,112,7,112,1,73,36,121,0,48,61,0,
		102,95,6,112,1,73,36,122,0,95,16,100,69,28,17,95,16,28,13,
		36,124,0,48,62,0,102,122,112,1,73,36,127,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,15,36,134,0,48,2,0,48,39,0,102,112,0,95,1,95,2,
		121,121,121,121,121,95,4,95,5,95,6,95,7,95,8,95,9,95,10,
		112,14,73,36,136,0,95,13,100,8,28,16,176,40,0,92,5,92,34,
		93,143,0,12,3,80,13,36,137,0,95,14,100,8,28,14,176,40,0,
		121,121,93,255,0,12,3,80,14,36,138,0,95,15,100,8,28,14,176,
		40,0,93,255,0,121,121,12,3,80,15,36,139,0,48,45,0,102,121,
		112,1,73,36,140,0,48,41,0,102,95,12,112,1,73,36,141,0,48,
		42,0,102,95,15,112,1,73,36,142,0,48,43,0,102,95,14,112,1,
		73,36,143,0,48,44,0,102,95,13,112,1,73,36,145,0,48,46,0,
		102,112,0,100,8,29,157,0,36,146,0,48,46,0,48,47,0,102,112,
		0,112,0,100,69,29,252,0,36,148,0,48,48,0,102,48,49,0,176,
		50,0,12,0,48,51,0,48,46,0,48,47,0,102,112,0,112,0,112,
		0,48,52,0,48,46,0,48,47,0,102,112,0,112,0,112,0,48,53,
		0,48,46,0,48,47,0,102,112,0,112,0,112,0,48,54,0,48,46,
		0,48,47,0,102,112,0,112,0,112,0,48,55,0,48,46,0,48,47,
		0,102,112,0,112,0,112,0,48,56,0,48,46,0,48,47,0,102,112,
		0,112,0,112,0,122,48,57,0,48,46,0,48,47,0,102,112,0,112,
		0,112,0,112,8,112,1,73,25,116,36,151,0,48,58,0,48,46,0,
		102,112,0,112,0,121,8,28,98,36,152,0,48,46,0,102,112,0,80,
		16,36,153,0,48,59,0,48,46,0,102,112,0,112,0,73,36,155,0,
		48,48,0,102,48,49,0,176,50,0,12,0,48,51,0,95,16,112,0,
		48,52,0,95,16,112,0,48,53,0,95,16,112,0,48,54,0,95,16,
		112,0,48,55,0,95,16,112,0,48,56,0,95,16,112,0,122,48,57,
		0,95,16,112,0,112,8,112,1,73,36,159,0,48,37,0,102,95,3,
		112,1,73,36,160,0,48,63,0,102,48,64,0,102,48,65,0,102,48,
		66,0,102,48,67,0,102,121,112,1,112,1,112,1,112,1,112,1,73,
		36,162,0,95,11,100,69,28,17,95,11,28,13,36,164,0,48,62,0,
		102,122,112,1,73,36,167,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,171,0,48,68,0,102,112,0,31,60,36,172,0,48,69,0,102,112,
		0,73,36,173,0,48,70,0,48,39,0,102,112,0,112,0,73,36,174,
		0,48,71,0,102,112,0,100,69,28,22,36,175,0,176,72,0,48,73,
		0,102,112,0,48,71,0,102,112,0,20,2,36,180,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,184,0,95,1,92,7,5,31,9,95,1,92,8,5,28,
		70,176,74,0,48,75,0,102,112,0,97,0,0,1,0,12,2,121,69,
		28,50,36,185,0,176,76,0,48,73,0,48,47,0,102,112,0,112,0,
		92,7,48,77,0,102,112,0,48,78,0,102,112,0,48,79,0,102,112,
		0,48,80,0,102,112,0,20,6,26,203,1,36,187,0,95,1,92,15,
		8,32,192,1,36,190,0,95,1,93,0,2,8,28,33,36,191,0,176,
		81,0,48,82,0,102,112,0,20,1,36,192,0,48,83,0,102,95,2,
		95,3,112,2,73,26,150,1,36,193,0,95,1,93,163,2,5,31,10,
		95,1,93,162,2,5,28,76,36,194,0,48,45,0,102,122,112,1,73,
		36,195,0,176,84,0,48,73,0,102,112,0,121,20,2,36,196,0,176,
		76,0,48,73,0,48,47,0,102,112,0,112,0,92,7,48,77,0,102,
		112,0,48,78,0,102,112,0,48,79,0,102,112,0,48,80,0,102,112,
		0,20,6,26,57,1,36,198,0,95,1,93,161,2,5,32,45,1,36,
		199,0,95,1,92,32,8,28,21,36,200,0,48,85,0,102,95,1,95,
		2,95,3,112,3,73,26,16,1,36,202,0,95,1,93,1,2,8,28,
		29,36,203,0,176,81,0,48,82,0,102,112,0,20,1,36,204,0,48,
		86,0,102,112,0,73,26,234,0,36,205,0,95,1,92,5,8,32,223,
		0,36,207,0,95,1,93,0,1,5,29,171,0,36,209,0,95,2,92,
		32,8,31,9,95,2,92,13,8,28,33,36,210,0,176,87,0,48,73,
		0,102,112,0,93,1,2,121,176,88,0,122,122,12,2,20,4,36,211,
		0,121,110,7,36,212,0,95,2,92,40,5,28,26,36,213,0,176,89,
		0,48,47,0,102,112,0,48,73,0,102,112,0,100,122,20,4,25,82,
		36,214,0,95,2,92,38,5,28,27,36,215,0,176,89,0,48,47,0,
		102,112,0,48,73,0,102,112,0,100,92,255,20,4,25,47,36,216,0,
		95,2,92,9,5,28,37,36,217,0,176,89,0,48,47,0,102,112,0,
		48,73,0,102,112,0,100,176,90,0,9,120,12,2,28,6,92,255,25,
		3,122,20,4,36,219,0,121,110,7,36,220,0,95,1,93,1,1,8,
		31,31,36,228,0,95,1,93,135,0,5,28,20,36,229,0,95,2,92,
		13,8,28,6,92,4,25,4,92,3,110,7,36,232,0,92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_GOTOLINKURL )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,236,0,176,91,0,95,1,106,5,111,112,101,110,0,100,
		100,92,2,12,5,80,2,36,239,0,95,2,92,33,35,28,8,36,240,
		0,9,110,7,36,243,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_GETLINKTEXT )
{
	static const HB_BYTE pcode[] =
	{
		36,247,0,176,35,0,48,71,0,102,112,0,12,1,28,10,36,248,0,
		106,1,0,110,7,36,251,0,48,71,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_SETLINKURL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,255,0,48,41,0,102,95,1,112,1,73,36,1,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_GETLINKURL )
{
	static const HB_BYTE pcode[] =
	{
		36,5,1,48,92,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_SETVISITEDCOLOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,9,1,48,44,0,102,95,1,112,1,73,36,10,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_SETHOVERCOLOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,14,1,48,42,0,102,95,1,112,1,73,36,16,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_ONCLICKED )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,21,1,176,93,0,48,94,0,102,112,0,12,1,106,2,
		66,0,8,28,16,36,22,1,48,45,0,102,122,112,1,73,26,169,0,
		36,24,1,176,35,0,48,92,0,102,112,0,12,1,32,152,0,36,25,
		1,48,95,0,102,112,0,28,42,36,26,1,48,96,0,102,112,0,80,
		1,36,27,1,48,97,0,102,48,73,0,48,47,0,102,112,0,112,0,
		93,101,4,95,1,121,112,4,73,25,18,36,29,1,48,98,0,102,48,
		92,0,102,112,0,112,1,73,36,31,1,48,99,0,102,120,112,1,73,
		36,32,1,48,45,0,102,122,112,1,73,36,33,1,176,84,0,48,73,
		0,102,112,0,121,20,2,36,34,1,176,76,0,48,73,0,48,47,0,
		102,112,0,112,0,92,7,48,77,0,102,112,0,48,78,0,102,112,0,
		48,79,0,102,112,0,48,80,0,102,112,0,20,6,36,36,1,48,100,
		0,102,112,0,73,36,38,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_ONSETCURSOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,46,1,176,81,0,48,82,0,102,112,0,20,1,36,48,
		1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_SETLINKTEXT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,52,1,48,37,0,102,95,1,112,1,73,36,53,1,48,
		101,0,102,95,1,112,1,73,36,55,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_SETLINKCOLOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,59,1,48,43,0,102,95,1,112,1,73,36,61,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_ONMOUSEMOVE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,67,1,9,80,5,36,71,1,48,102,0,102,112,0,121,
		69,29,35,1,36,72,1,176,103,0,95,2,12,1,80,3,36,73,1,
		176,104,0,95,2,12,1,80,4,36,74,1,176,105,0,121,121,48,106,
		0,102,112,0,48,80,0,102,112,0,4,4,0,95,3,95,4,4,2,
		0,12,2,31,21,48,102,0,102,112,0,92,3,69,28,10,36,75,1,
		120,80,5,25,64,36,77,1,176,81,0,48,82,0,102,112,0,20,1,
		36,78,1,176,105,0,92,4,92,4,48,106,0,102,112,0,92,4,49,
		48,80,0,102,112,0,92,4,49,4,4,0,95,3,95,4,4,2,0,
		12,2,31,8,36,80,1,120,80,5,36,83,1,95,5,28,10,48,107,
		0,102,112,0,28,14,95,5,28,21,48,107,0,102,112,0,28,13,36,
		84,1,48,45,0,102,122,112,1,73,36,91,1,48,102,0,102,112,0,
		122,8,28,6,95,5,28,24,48,102,0,102,112,0,122,8,28,86,95,
		5,31,82,48,107,0,102,112,0,28,74,36,92,1,48,45,0,102,92,
		3,112,1,73,36,93,1,176,84,0,48,73,0,102,112,0,121,20,2,
		36,94,1,176,76,0,48,73,0,48,47,0,102,112,0,112,0,92,7,
		48,77,0,102,112,0,48,78,0,102,112,0,48,79,0,102,112,0,48,
		80,0,102,112,0,20,6,36,98,1,176,108,0,48,73,0,102,112,0,
		92,2,20,2,36,100,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,12,1,36,103,1,176,109,0,95,1,12,1,80,2,36,104,1,95,
		2,92,3,1,80,3,36,105,1,48,71,0,102,112,0,80,4,36,113,
		1,176,35,0,48,110,0,102,112,0,12,1,31,15,176,111,0,48,110,
		0,102,112,0,12,1,25,7,121,121,4,2,0,80,8,36,114,1,176,
		112,0,95,2,92,4,1,95,2,92,5,1,95,2,92,6,1,95,2,
		92,7,1,4,4,0,12,1,80,9,36,115,1,95,2,92,4,1,95,
		2,92,5,1,95,2,92,6,1,95,2,92,7,1,4,4,0,80,10,
		36,118,1,48,102,0,102,112,0,121,8,28,13,36,119,1,48,45,0,
		102,122,112,1,73,36,121,1,176,112,0,95,2,92,4,1,95,2,92,
		5,1,95,2,92,6,1,95,2,92,7,1,4,4,0,12,1,80,12,
		36,122,1,176,112,0,95,2,92,4,1,95,2,92,5,1,95,2,92,
		6,1,95,2,92,7,1,4,4,0,12,1,80,6,36,125,1,176,113,
		0,48,73,0,102,112,0,12,1,28,115,176,74,0,48,75,0,102,112,
		0,97,0,0,1,0,12,2,121,69,28,95,36,126,1,176,114,0,95,
		3,122,20,2,36,127,1,176,115,0,95,3,95,12,20,2,36,128,1,
		176,116,0,12,0,28,62,48,117,0,102,112,0,28,54,36,129,1,176,
		118,0,48,73,0,102,112,0,106,5,77,69,78,85,0,12,2,80,13,
		36,130,1,176,119,0,95,13,95,3,92,14,92,2,95,12,100,20,6,
		36,131,1,176,120,0,95,13,20,1,36,135,1,176,93,0,48,110,0,
		102,112,0,12,1,106,2,78,0,8,29,211,0,36,136,1,176,93,0,
		95,4,12,1,106,2,67,0,8,21,28,11,73,176,35,0,95,4,12,
		1,68,80,7,36,137,1,95,8,92,2,1,122,72,95,9,92,4,2,
		36,138,1,176,121,0,48,73,0,102,112,0,95,3,95,7,96,9,0,
		96,10,0,100,100,48,110,0,102,112,0,48,122,0,102,112,0,12,9,
		80,11,36,139,1,95,2,92,7,1,95,9,92,4,2,36,140,1,48,
		123,0,102,112,0,122,5,28,31,36,141,1,176,124,0,95,3,48,110,
		0,102,112,0,95,11,122,1,95,11,92,2,1,122,72,20,4,25,30,
		36,143,1,176,125,0,95,3,48,110,0,102,112,0,100,95,11,122,1,
		95,11,92,2,1,122,72,20,5,36,145,1,95,6,122,148,48,122,0,
		102,112,0,121,5,28,11,95,8,122,1,92,8,72,25,3,122,135,36,
		146,1,95,6,92,2,148,92,2,135,25,45,36,147,1,176,74,0,48,
		75,0,102,112,0,97,0,0,1,0,12,2,121,69,28,22,36,148,1,
		95,6,122,148,92,3,135,36,149,1,95,6,92,2,148,122,135,36,151,
		1,176,114,0,95,3,48,123,0,102,112,0,20,2,36,152,1,48,123,
		0,102,112,0,122,69,28,66,36,153,1,176,126,0,95,3,48,127,0,
		102,112,0,100,5,28,11,176,128,0,92,15,12,1,25,8,48,127,0,
		102,112,0,20,2,36,154,1,176,129,0,95,3,95,6,122,1,95,6,
		92,2,1,95,6,92,3,1,95,6,92,4,1,20,5,36,156,1,92,
		16,80,5,36,158,1,96,5,0,97,4,128,0,0,135,36,161,1,176,
		130,0,95,3,48,73,0,48,46,0,102,112,0,112,0,20,2,36,162,
		1,48,102,0,102,112,0,122,8,28,49,36,163,1,48,107,0,102,112,
		0,28,20,36,165,1,176,131,0,95,3,48,132,0,102,112,0,20,2,
		25,50,36,168,1,176,131,0,95,3,48,133,0,102,112,0,20,2,25,
		32,36,170,1,48,102,0,102,112,0,92,3,8,28,18,36,172,1,176,
		131,0,95,3,48,134,0,102,112,0,20,2,36,176,1,48,102,0,102,
		112,0,92,3,5,28,70,48,36,0,102,112,0,31,62,36,177,1,176,
		130,0,95,3,48,73,0,48,135,0,102,112,0,112,0,20,2,36,178,
		1,176,136,0,95,3,95,4,95,6,95,5,20,4,36,179,1,176,130,
		0,95,3,48,73,0,48,46,0,102,112,0,112,0,20,2,25,18,36,
		181,1,176,136,0,95,3,95,4,95,6,95,5,20,4,36,186,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSTATICLINK_RESIZE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,192,1,48,80,0,102,112,0,80,5,36,194,1,95,1,
		100,69,28,17,95,1,95,2,72,121,5,28,8,36,195,1,100,110,7,
		36,198,1,95,1,100,8,28,5,121,25,13,95,1,48,79,0,102,112,
		0,49,122,72,80,1,36,199,1,176,35,0,48,110,0,102,112,0,12,
		1,31,15,176,111,0,48,110,0,102,112,0,12,1,25,7,121,121,4,
		2,0,80,3,36,200,1,95,3,122,148,95,3,122,1,121,15,28,6,
		92,6,25,3,121,135,36,201,1,48,137,0,102,100,100,48,79,0,102,
		112,0,95,1,72,100,121,112,5,73,36,202,1,176,138,0,48,71,0,
		102,112,0,102,12,2,80,4,36,203,1,95,4,92,2,148,48,36,0,
		102,112,0,28,5,121,25,4,92,3,135,36,204,1,95,4,122,1,122,
		72,48,79,0,102,112,0,95,3,122,1,49,35,28,22,36,205,1,48,
		67,0,102,95,4,92,2,1,92,2,72,112,1,73,25,22,36,207,1,
		48,67,0,102,95,4,92,2,1,92,2,65,122,72,112,1,73,36,209,
		1,48,61,0,102,176,139,0,95,4,122,1,122,72,95,3,122,1,72,
		48,79,0,102,112,0,12,2,112,1,73,36,210,1,48,67,0,102,176,
		140,0,48,80,0,102,112,0,95,4,92,2,1,12,2,112,1,73,36,
		211,1,48,67,0,102,176,140,0,48,80,0,102,112,0,95,3,92,2,
		1,92,4,72,12,2,112,1,73,36,213,1,95,5,48,80,0,102,112,
		0,69,28,37,36,214,1,48,137,0,102,100,100,100,48,80,0,102,112,
		0,121,112,5,73,36,215,1,176,84,0,48,73,0,102,112,0,121,20,
		2,36,218,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,141,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}
