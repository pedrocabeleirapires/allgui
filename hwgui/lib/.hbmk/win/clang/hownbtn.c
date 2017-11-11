/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( HOWNBUTTON );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HOWNBUTTON_NEW );
HB_FUNC_STATIC( HOWNBUTTON_ACTIVATE );
HB_FUNC_STATIC( HOWNBUTTON_ONEVENT );
HB_FUNC_STATIC( HOWNBUTTON_INIT );
HB_FUNC_STATIC( HOWNBUTTON_REDEFINE );
HB_FUNC_STATIC( HOWNBUTTON_PAINT );
HB_FUNC_STATIC( HOWNBUTTON_DRAWITEMS );
HB_FUNC_STATIC( HOWNBUTTON_MOUSEMOVE );
HB_FUNC_STATIC( HOWNBUTTON_MDOWN );
HB_FUNC_STATIC( HOWNBUTTON_MUP );
HB_FUNC_STATIC( HOWNBUTTON_RELEASE );
HB_FUNC_STATIC( HOWNBUTTON_END );
HB_FUNC_STATIC( HOWNBUTTON_ENABLE );
HB_FUNC_STATIC( HOWNBUTTON_DISABLE );
HB_FUNC_STATIC( HOWNBUTTON_ONCLICK );
HB_FUNC_STATIC( HOWNBUTTON_ONGETFOCUS );
HB_FUNC_STATIC( HOWNBUTTON_ONLOSTFOCUS );
HB_FUNC_STATIC( HOWNBUTTON_REFRESH );
HB_FUNC_EXTERN( HWG_REDRAWWINDOW );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG_GETSYSCOLOR );
HB_FUNC_EXTERN( HBRUSH );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HBITMAP );
HB_FUNC_EXTERN( HWG_REGOWNBTN );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_CREATEOWNBTN );
HB_FUNC_EXTERN( HWG_ENABLEWINDOW );
HB_FUNC_EXTERN( HWG_CLOSETHEMEDATA );
HB_FUNC_EXTERN( HWG_SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_DEFINEPAINTSTRU );
HB_FUNC_EXTERN( HWG_BEGINPAINT );
HB_FUNC_EXTERN( HWG_GETCLIENTRECT );
HB_FUNC_EXTERN( HWG_ISTHEMEDLOAD );
HB_FUNC_EXTERN( HWG_OPENTHEMEDATA );
HB_FUNC_EXTERN( HWG_GETFOCUS );
HB_FUNC_EXTERN( HWG_DRAWTHEMEBACKGROUND );
HB_FUNC_EXTERN( HWG_DRAWBUTTON );
HB_FUNC_EXTERN( HWG_SELFFOCUS );
HB_FUNC_EXTERN( HWG_ENDPAINT );
HB_FUNC_EXTERN( HWG_FILLRECT );
HB_FUNC_EXTERN( ROUND );
HB_FUNC_EXTERN( HWG_DRAWICON );
HB_FUNC_EXTERN( HWG_DRAWTRANSPARENTBITMAP );
HB_FUNC_EXTERN( HWG_DRAWBITMAP );
HB_FUNC_EXTERN( HWG_DRAWGRAYBITMAP );
HB_FUNC_EXTERN( HWG_SELECTOBJECT );
HB_FUNC_EXTERN( HWG_SETTEXTCOLOR );
HB_FUNC_EXTERN( HWG_SETTRANSPARENTMODE );
HB_FUNC_EXTERN( HWG_DRAWTEXT );
HB_FUNC_EXTERN( HWG_LOWORD );
HB_FUNC_EXTERN( HWG_HIWORD );
HB_FUNC_EXTERN( HWG_RELEASECAPTURE );
HB_FUNC_EXTERN( HWG_INVALIDATERECT );
HB_FUNC_EXTERN( HWG_SETCAPTURE );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_EXTERN( HWG_POSTMESSAGE );
HB_FUNC_EXTERN( __MVXRELEASE );
HB_FUNC_EXTERN( HWG_CHECKFOCUS );
HB_FUNC_EXTERN( HWG_GETKEYSTATE );
HB_FUNC_EXTERN( HWG_WHENSETFOCUS );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HOWNBTN )
{ "HOWNBUTTON", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON ) }, NULL },
{ "__CLSLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSLOCKDEF ) }, NULL },
{ "NEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBCLASS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBCLASS ) }, NULL },
{ "HCONTROL", { HB_FS_PUBLIC }, { HB_FUNCNAME( HCONTROL ) }, NULL },
{ "ADDMULTICLSDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMULTIDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMETHOD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HOWNBUTTON_NEW", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_NEW ) }, NULL },
{ "HOWNBUTTON_ACTIVATE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ACTIVATE ) }, NULL },
{ "HOWNBUTTON_ONEVENT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ONEVENT ) }, NULL },
{ "HOWNBUTTON_INIT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_INIT ) }, NULL },
{ "HOWNBUTTON_REDEFINE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_REDEFINE ) }, NULL },
{ "HOWNBUTTON_PAINT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_PAINT ) }, NULL },
{ "HOWNBUTTON_DRAWITEMS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_DRAWITEMS ) }, NULL },
{ "HOWNBUTTON_MOUSEMOVE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_MOUSEMOVE ) }, NULL },
{ "HOWNBUTTON_MDOWN", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_MDOWN ) }, NULL },
{ "HOWNBUTTON_MUP", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_MUP ) }, NULL },
{ "ADDINLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LPRESS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "MDOWN", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HOWNBUTTON_RELEASE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_RELEASE ) }, NULL },
{ "HOWNBUTTON_END", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_END ) }, NULL },
{ "HOWNBUTTON_ENABLE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ENABLE ) }, NULL },
{ "HOWNBUTTON_DISABLE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_DISABLE ) }, NULL },
{ "HOWNBUTTON_ONCLICK", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ONCLICK ) }, NULL },
{ "HOWNBUTTON_ONGETFOCUS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ONGETFOCUS ) }, NULL },
{ "HOWNBUTTON_ONLOSTFOCUS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_ONLOSTFOCUS ) }, NULL },
{ "HOWNBUTTON_REFRESH", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HOWNBUTTON_REFRESH ) }, NULL },
{ "_TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_REDRAWWINDOW", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_REDRAWWINDOW ) }, NULL },
{ "HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OPARENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CREATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__CLSUNLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSUNLOCKDEF ) }, NULL },
{ "INSTANCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__OBJHASMSG", { HB_FS_PUBLIC }, { HB_FUNCNAME( __OBJHASMSG ) }, NULL },
{ "INITCLASS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SUPER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LFLAT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BCLICK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_STATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NORDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LEN", { HB_FS_PUBLIC }, { HB_FUNCNAME( LEN ) }, NULL },
{ "ACONTROLS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_TCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETSYSCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSYSCOLOR ) }, NULL },
{ "_BCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BRUSH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBRUSH", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBRUSH ) }, NULL },
{ "_XT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_YT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_WIDTHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_HEIGHTT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LENABLED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LCHECK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_THEMED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALTYPE", { HB_FS_PUBLIC }, { HB_FUNCNAME( VALTYPE ) }, NULL },
{ "_OBITMAP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDRESOURCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBITMAP ) }, NULL },
{ "ADDFILE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CPATH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_XB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_YB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_WIDTHB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_HEIGHTB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LTRANSP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_TRCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDEVENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONCLICK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_REGOWNBTN", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_REGOWNBTN ) }, NULL },
{ "ACTIVATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EMPTY", { HB_FS_PUBLIC }, { HB_FUNCNAME( EMPTY ) }, NULL },
{ "_HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CREATEOWNBTN", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CREATEOWNBTN ) }, NULL },
{ "ID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "INIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LENABLED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_ENABLEWINDOW", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ENABLEWINDOW ) }, NULL },
{ "DISABLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "THEMED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HTHEME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CLOSETHEMEDATA", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CLOSETHEMEDATA ) }, NULL },
{ "_HTHEME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_M_BFIRSTTIME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BPAINT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EVAL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "PAINT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "MOUSEMOVE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "MUP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "END", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LCHECK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "RELEASE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "PRESS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BOTHER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LINIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NHOLDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETWINDOWOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETWINDOWOBJECT ) }, NULL },
{ "HWG_DEFINEPAINTSTRU", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DEFINEPAINTSTRU ) }, NULL },
{ "HWG_BEGINPAINT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BEGINPAINT ) }, NULL },
{ "HWG_GETCLIENTRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETCLIENTRECT ) }, NULL },
{ "STATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "M_BFIRSTTIME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_ISTHEMEDLOAD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ISTHEMEDLOAD ) }, NULL },
{ "WINDOWSMANIFEST", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_OPENTHEMEDATA", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_OPENTHEMEDATA ) }, NULL },
{ "LFLAT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETFOCUS ) }, NULL },
{ "HWG_DRAWTHEMEBACKGROUND", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTHEMEBACKGROUND ) }, NULL },
{ "HWG_DRAWBUTTON", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWBUTTON ) }, NULL },
{ "HWG_SELFFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SELFFOCUS ) }, NULL },
{ "DRAWITEMS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_ENDPAINT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ENDPAINT ) }, NULL },
{ "BRUSH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_FILLRECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_FILLRECT ) }, NULL },
{ "OBITMAP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "WIDTHB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "XB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ROUND", { HB_FS_PUBLIC }, { HB_FUNCNAME( ROUND ) }, NULL },
{ "YB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HEIGHTB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CLASSNAME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_DRAWICON", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWICON ) }, NULL },
{ "LTRANSP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_DRAWTRANSPARENTBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTRANSPARENTBITMAP ) }, NULL },
{ "TRCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_DRAWBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWBITMAP ) }, NULL },
{ "HWG_DRAWGRAYBITMAP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWGRAYBITMAP ) }, NULL },
{ "TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SELECTOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SELECTOBJECT ) }, NULL },
{ "HWG_SETTEXTCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETTEXTCOLOR ) }, NULL },
{ "TCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "XT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "YT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETTRANSPARENTMODE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETTRANSPARENTMODE ) }, NULL },
{ "HWG_DRAWTEXT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_DRAWTEXT ) }, NULL },
{ "HWG_LOWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_LOWORD ) }, NULL },
{ "HWG_HIWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_HIWORD ) }, NULL },
{ "HWG_RELEASECAPTURE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_RELEASECAPTURE ) }, NULL },
{ "LPRESS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_INVALIDATERECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INVALIDATERECT ) }, NULL },
{ "HWG_SETCAPTURE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETCAPTURE ) }, NULL },
{ "HWG_SENDMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SENDMESSAGE ) }, NULL },
{ "HWG_POSTMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_POSTMESSAGE ) }, NULL },
{ "BCLICK", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__MVXRELEASE", { HB_FS_PUBLIC }, { HB_FUNCNAME( __MVXRELEASE ) }, NULL },
{ "BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CHECKFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CHECKFOCUS ) }, NULL },
{ "HWG_GETKEYSTATE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETKEYSTATE ) }, NULL },
{ "_LSUSPENDMSGSHANDLING", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_WHENSETFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_WHENSETFOCUS ) }, NULL },
{ "BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "(_INITSTATICS00001)", { HB_FS_INITEXIT | HB_FS_LOCAL }, { hb_INITSTATICS }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HOWNBTN, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HOWNBTN
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HOWNBTN )
   #include "hbiniseg.h"
#endif

HB_FUNC( HOWNBUTTON )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,166,0,36,18,0,103,1,0,100,8,29,103,5,176,1,
		0,104,1,0,12,1,29,92,5,166,30,5,0,122,80,1,48,2,0,
		176,3,0,12,0,106,11,72,79,119,110,66,117,116,116,111,110,0,108,
		4,4,1,0,108,0,112,3,80,2,36,20,0,48,5,0,95,2,100,
		100,95,1,121,72,92,32,72,121,72,121,72,106,6,99,80,97,116,104,
		0,4,1,0,9,112,5,73,36,21,0,48,6,0,95,2,100,106,7,
		79,87,78,66,84,78,0,95,1,121,72,121,72,121,72,106,9,119,105,
		110,99,108,97,115,115,0,4,1,0,9,112,5,73,36,22,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,6,108,70,108,97,
		116,0,4,1,0,9,112,5,73,36,23,0,48,6,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,6,115,116,97,116,101,0,4,1,0,
		9,112,5,73,36,24,0,48,6,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,7,98,67,108,105,99,107,0,4,1,0,9,112,5,73,
		36,25,0,48,6,0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		7,108,80,114,101,115,115,0,4,1,0,9,112,5,73,36,26,0,48,
		6,0,95,2,100,9,95,1,121,72,121,72,121,72,106,7,108,67,104,
		101,99,107,0,4,1,0,9,112,5,73,36,27,0,48,6,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,3,120,116,0,106,3,121,116,
		0,106,7,119,105,100,116,104,116,0,106,8,104,101,105,103,104,116,116,
		0,4,4,0,9,112,5,73,36,28,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,8,111,66,105,116,109,97,112,0,106,3,
		120,98,0,106,3,121,98,0,106,7,119,105,100,116,104,98,0,106,8,
		104,101,105,103,104,116,98,0,106,8,108,84,114,97,110,115,112,0,106,
		8,116,114,67,111,108,111,114,0,4,7,0,9,112,5,73,36,29,0,
		48,6,0,95,2,100,120,95,1,121,72,121,72,121,72,106,9,108,69,
		110,97,98,108,101,100,0,4,1,0,9,112,5,73,36,30,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,7,110,79,114,100,
		101,114,0,4,1,0,9,112,5,73,36,32,0,48,6,0,95,2,100,
		120,95,1,121,72,121,72,121,72,106,13,109,95,98,70,105,114,115,116,
		84,105,109,101,0,4,1,0,9,112,5,73,36,33,0,48,6,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,7,104,84,104,101,109,101,
		0,4,1,0,9,112,5,73,36,34,0,48,6,0,95,2,100,9,95,
		1,121,72,121,72,121,72,106,7,84,104,101,109,101,100,0,4,1,0,
		9,112,5,73,36,41,0,48,7,0,95,2,106,4,78,101,119,0,108,
		8,95,1,121,72,121,72,121,72,112,3,73,36,43,0,48,7,0,95,
		2,106,9,65,99,116,105,118,97,116,101,0,108,9,95,1,121,72,121,
		72,121,72,112,3,73,36,44,0,48,7,0,95,2,106,8,111,110,69,
		118,101,110,116,0,108,10,95,1,121,72,121,72,121,72,112,3,73,36,
		45,0,48,7,0,95,2,106,5,73,110,105,116,0,108,11,95,1,121,
		72,121,72,121,72,112,3,73,36,49,0,48,7,0,95,2,106,9,82,
		101,100,101,102,105,110,101,0,108,12,95,1,121,72,121,72,121,72,112,
		3,73,36,50,0,48,7,0,95,2,106,6,80,97,105,110,116,0,108,
		13,95,1,121,72,121,72,121,72,112,3,73,36,51,0,48,7,0,95,
		2,106,10,68,114,97,119,73,116,101,109,115,0,108,14,95,1,121,72,
		121,72,121,72,112,3,73,36,52,0,48,7,0,95,2,106,10,77,111,
		117,115,101,77,111,118,101,0,108,15,95,1,121,72,121,72,121,72,112,
		3,73,36,53,0,48,7,0,95,2,106,6,77,68,111,119,110,0,108,
		16,95,1,121,72,121,72,121,72,112,3,73,36,54,0,48,7,0,95,
		2,106,4,77,85,112,0,108,17,95,1,121,72,121,72,121,72,112,3,
		73,36,55,0,48,18,0,95,2,106,6,80,114,101,115,115,0,89,24,
		0,1,0,0,0,48,19,0,95,1,120,112,1,73,48,20,0,95,1,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,36,56,0,48,7,
		0,95,2,106,8,82,101,108,101,97,115,101,0,108,21,95,1,121,72,
		121,72,121,72,112,3,73,36,57,0,48,7,0,95,2,106,4,69,78,
		68,0,108,22,95,1,121,72,121,72,121,72,112,3,73,36,58,0,48,
		7,0,95,2,106,7,69,110,97,98,108,101,0,108,23,95,1,121,72,
		121,72,121,72,112,3,73,36,59,0,48,7,0,95,2,106,8,68,105,
		115,97,98,108,101,0,108,24,95,1,121,72,121,72,121,72,112,3,73,
		36,60,0,48,7,0,95,2,106,8,111,110,67,108,105,99,107,0,108,
		25,95,1,121,72,121,72,121,72,112,3,73,36,61,0,48,7,0,95,
		2,106,11,111,110,71,101,116,70,111,99,117,115,0,108,26,95,1,121,
		72,121,72,121,72,112,3,73,36,62,0,48,7,0,95,2,106,12,111,
		110,76,111,115,116,70,111,99,117,115,0,108,27,95,1,121,72,121,72,
		121,72,112,3,73,36,63,0,48,7,0,95,2,106,8,82,101,102,114,
		101,115,104,0,108,28,95,1,121,72,121,72,121,72,112,3,73,36,65,
		0,48,18,0,95,2,106,8,83,101,116,84,101,120,116,0,89,65,0,
		2,0,0,0,48,29,0,95,1,95,2,112,1,73,176,30,0,48,31,
		0,48,32,0,95,1,112,0,112,0,92,5,48,33,0,95,1,112,0,
		48,34,0,95,1,112,0,48,35,0,95,1,112,0,48,36,0,95,1,
		112,0,12,6,6,95,1,121,72,121,72,121,72,112,3,73,36,68,0,
		48,37,0,95,2,112,0,73,167,14,0,0,176,38,0,104,1,0,95,
		2,20,2,168,48,39,0,95,2,112,0,80,3,176,40,0,95,3,106,
		10,73,110,105,116,67,108,97,115,115,0,12,2,28,12,48,41,0,95,
		3,164,146,1,0,73,95,3,110,7,48,39,0,103,1,0,112,0,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,34,36,74,0,102,80,35,36,77,0,48,2,0,48,42,0,95,
		35,112,0,95,1,95,2,95,3,95,4,95,5,95,6,95,7,95,15,
		95,8,95,9,95,10,95,28,112,12,73,36,82,0,95,15,100,8,28,
		25,36,83,0,48,43,0,95,35,48,44,0,48,32,0,95,35,112,0,
		112,0,112,1,73,36,85,0,48,45,0,95,35,95,12,100,8,28,5,
		9,25,4,95,12,112,1,73,36,86,0,48,46,0,95,35,95,11,112,
		1,73,36,87,0,48,47,0,95,35,95,32,112,1,73,36,88,0,48,
		48,0,95,35,95,33,112,1,73,36,90,0,48,49,0,95,35,121,112,
		1,73,36,91,0,48,50,0,95,35,95,1,100,8,28,5,121,25,14,
		176,51,0,48,52,0,95,1,112,0,12,1,112,1,73,36,93,0,48,
		29,0,95,35,95,13,112,1,73,36,94,0,48,53,0,95,35,95,14,
		100,8,28,11,176,54,0,92,18,12,1,25,4,95,14,112,1,73,36,
		95,0,95,31,100,69,28,38,36,96,0,48,55,0,95,35,95,31,112,
		1,73,36,97,0,48,56,0,95,35,48,57,0,176,58,0,12,0,95,
		31,112,1,112,1,73,36,100,0,48,59,0,95,35,95,16,100,8,28,
		5,121,25,4,95,16,112,1,73,36,101,0,48,60,0,95,35,95,17,
		100,8,28,5,121,25,4,95,17,112,1,73,36,102,0,48,61,0,95,
		35,95,18,100,8,28,5,121,25,4,95,18,112,1,73,36,103,0,48,
		62,0,95,35,95,19,100,8,28,5,121,25,4,95,19,112,1,73,36,
		105,0,95,29,100,69,28,15,36,106,0,48,63,0,95,35,95,29,112,
		1,73,36,108,0,95,30,100,69,28,15,36,109,0,48,64,0,95,35,
		95,30,112,1,73,36,111,0,48,65,0,95,35,95,34,100,5,28,5,
		9,25,4,95,34,112,1,73,36,112,0,95,20,100,69,28,118,36,113,
		0,176,66,0,95,20,12,1,106,2,79,0,8,28,17,36,114,0,48,
		67,0,95,35,95,20,112,1,73,25,86,36,118,0,48,67,0,95,35,
		95,21,100,69,28,6,95,21,31,16,176,66,0,95,20,12,1,106,2,
		78,0,8,28,16,48,68,0,176,69,0,12,0,95,20,112,1,25,37,
		48,70,0,176,69,0,12,0,48,71,0,95,35,112,0,100,69,28,14,
		48,71,0,95,35,112,0,95,20,72,25,4,95,20,112,1,112,1,73,
		36,121,0,48,72,0,95,35,95,22,112,1,73,36,122,0,48,73,0,
		95,35,95,23,112,1,73,36,123,0,48,74,0,95,35,95,24,100,8,
		28,5,121,25,4,95,24,112,1,73,36,124,0,48,75,0,95,35,95,
		25,100,8,28,5,121,25,4,95,25,112,1,73,36,125,0,48,76,0,
		95,35,95,26,100,69,28,6,95,26,25,3,9,112,1,73,36,126,0,
		48,77,0,95,35,95,27,112,1,73,36,127,0,95,11,100,69,28,40,
		36,128,0,48,78,0,48,32,0,95,35,112,0,121,95,35,89,17,0,
		0,0,1,0,35,0,48,79,0,95,255,112,0,6,100,100,112,5,73,
		36,130,0,176,80,0,20,0,36,131,0,48,81,0,95,35,112,0,73,
		36,133,0,95,35,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,136,0,176,82,0,48,31,0,48,32,0,102,112,0,112,0,12,1,
		31,104,36,138,0,48,83,0,102,176,84,0,48,31,0,48,32,0,102,
		112,0,112,0,48,85,0,102,112,0,48,33,0,102,112,0,48,34,0,
		102,112,0,48,35,0,102,112,0,48,36,0,102,112,0,12,6,112,1,
		73,36,139,0,48,86,0,102,112,0,73,36,140,0,48,87,0,102,112,
		0,31,27,36,141,0,176,88,0,48,31,0,102,112,0,9,20,2,36,
		142,0,48,89,0,102,112,0,73,36,145,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,149,0,95,1,93,26,3,8,28,103,36,150,0,48,90,
		0,102,112,0,28,59,36,151,0,176,66,0,48,91,0,102,112,0,12,
		1,106,2,80,0,8,28,27,36,152,0,176,92,0,48,91,0,102,112,
		0,20,1,36,153,0,48,93,0,102,100,112,1,73,36,155,0,48,65,
		0,102,9,112,1,73,36,157,0,48,94,0,102,120,112,1,73,36,158,
		0,176,30,0,48,31,0,102,112,0,92,5,20,2,36,159,0,121,110,
		7,36,161,0,95,1,92,20,8,28,8,36,162,0,121,110,7,36,163,
		0,95,1,92,15,8,28,47,36,164,0,48,95,0,102,112,0,100,69,
		28,21,36,165,0,48,96,0,48,95,0,102,112,0,102,112,1,73,26,
		32,1,36,167,0,48,97,0,102,112,0,73,26,19,1,36,169,0,95,
		1,93,0,2,8,28,19,36,170,0,48,98,0,102,95,2,95,3,112,
		2,73,26,247,0,36,171,0,95,1,93,1,2,8,28,15,36,172,0,
		48,20,0,102,112,0,73,26,223,0,36,173,0,95,1,93,2,2,8,
		28,15,36,174,0,48,99,0,102,112,0,73,26,199,0,36,175,0,95,
		1,92,2,8,28,15,36,176,0,48,100,0,102,112,0,73,26,176,0,
		36,177,0,95,1,92,7,8,28,15,36,183,0,48,101,0,102,112,0,
		73,26,153,0,36,184,0,95,1,92,8,8,28,35,36,190,0,48,102,
		0,102,112,0,31,12,36,191,0,48,103,0,102,112,0,73,36,193,0,
		48,104,0,102,112,0,73,25,109,36,194,0,95,1,93,2,1,5,31,
		18,95,1,93,0,1,5,31,10,95,1,93,1,1,5,28,44,36,195,
		0,95,2,92,32,5,28,72,36,196,0,48,105,0,102,112,0,73,36,
		197,0,48,79,0,102,112,0,73,36,198,0,48,103,0,102,112,0,73,
		25,40,36,201,0,176,82,0,48,106,0,102,112,0,12,1,31,24,36,
		202,0,48,96,0,48,106,0,102,112,0,102,95,1,95,2,95,3,112,
		4,73,36,206,0,92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,210,0,48,107,0,102,112,0,31,43,36,211,0,48,108,0,102,122,
		112,1,73,36,212,0,176,109,0,48,31,0,102,112,0,102,20,2,36,
		213,0,48,86,0,48,42,0,102,112,0,112,0,73,36,216,0,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,24,36,223,0,48,2,0,48,42,0,102,112,0,95,1,95,2,
		121,121,121,121,121,100,95,3,95,4,95,5,95,22,112,12,73,36,225,
		0,48,45,0,102,95,7,100,8,28,5,9,25,4,95,7,112,1,73,
		36,226,0,48,46,0,102,95,6,112,1,73,36,227,0,48,49,0,102,
		121,112,1,73,36,229,0,48,29,0,102,95,8,112,1,73,36,230,0,
		48,53,0,102,95,9,100,8,28,11,176,54,0,92,18,12,1,25,4,
		95,9,112,1,73,36,231,0,48,43,0,102,95,10,112,1,73,36,232,
		0,48,59,0,102,95,11,100,8,28,5,121,25,4,95,11,112,1,73,
		36,233,0,48,60,0,102,95,12,100,8,28,5,121,25,4,95,12,112,
		1,73,36,234,0,48,61,0,102,95,13,100,8,28,5,121,25,4,95,
		13,112,1,73,36,235,0,48,62,0,102,95,14,100,8,28,5,121,25,
		4,95,14,112,1,73,36,237,0,95,23,100,69,28,14,36,238,0,48,
		63,0,102,95,23,112,1,73,36,240,0,95,23,100,69,28,14,36,241,
		0,48,63,0,102,95,23,112,1,73,36,243,0,95,24,100,69,28,14,
		36,244,0,48,64,0,102,95,24,112,1,73,36,247,0,95,15,100,69,
		28,73,36,248,0,176,66,0,95,15,12,1,106,2,79,0,8,28,16,
		36,249,0,48,67,0,102,95,15,112,1,73,25,42,36,252,0,48,67,
		0,102,95,16,28,16,48,68,0,176,69,0,12,0,95,15,112,1,25,
		14,48,70,0,176,69,0,12,0,95,15,112,1,112,1,73,36,255,0,
		48,72,0,102,95,17,112,1,73,36,0,1,48,73,0,102,95,18,112,
		1,73,36,1,1,48,74,0,102,95,19,100,8,28,5,121,25,4,95,
		19,112,1,73,36,2,1,48,75,0,102,95,20,100,8,28,5,121,25,
		4,95,20,112,1,73,36,3,1,48,76,0,102,95,21,100,69,28,6,
		95,21,25,3,9,112,1,73,36,4,1,176,80,0,20,0,36,6,1,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,36,12,1,176,110,0,12,0,80,1,36,14,1,176,111,0,
		48,31,0,102,112,0,95,1,12,2,80,2,36,16,1,176,112,0,48,
		31,0,102,112,0,12,1,80,3,36,18,1,48,113,0,102,112,0,121,
		8,28,13,36,19,1,48,49,0,102,122,112,1,73,36,21,1,48,35,
		0,102,112,0,95,3,92,3,1,69,31,16,48,36,0,102,112,0,95,
		3,92,4,1,69,28,32,36,22,1,48,114,0,102,95,3,92,3,1,
		112,1,73,36,23,1,48,115,0,102,95,3,92,4,1,112,1,73,36,
		25,1,48,90,0,102,112,0,29,168,0,48,116,0,102,112,0,29,159,
		0,36,26,1,48,94,0,102,9,112,1,73,36,27,1,176,117,0,12,
		0,28,110,36,28,1,176,66,0,48,91,0,102,112,0,12,1,106,2,
		80,0,8,28,16,36,29,1,176,92,0,48,91,0,102,112,0,20,1,
		36,31,1,48,118,0,102,112,0,28,32,36,32,1,48,93,0,102,176,
		119,0,48,31,0,102,112,0,106,7,66,85,84,84,79,78,0,12,2,
		112,1,73,36,34,1,48,93,0,102,176,82,0,48,91,0,102,112,0,
		12,1,28,5,100,25,8,48,91,0,102,112,0,112,1,73,36,36,1,
		176,82,0,48,91,0,102,112,0,12,1,28,13,36,37,1,48,65,0,
		102,9,112,1,73,36,40,1,48,90,0,102,112,0,28,61,36,41,1,
		48,87,0,102,112,0,31,11,36,42,1,92,4,80,4,25,23,36,44,
		1,48,113,0,102,112,0,92,3,8,28,6,92,3,25,3,122,80,4,
		36,46,1,48,102,0,102,112,0,28,9,36,47,1,92,3,80,4,36,
		51,1,48,120,0,102,112,0,29,36,1,36,52,1,48,90,0,102,112,
		0,28,116,36,54,1,48,31,0,102,112,0,176,121,0,12,0,5,28,
		35,48,102,0,102,112,0,28,27,36,55,1,176,122,0,48,91,0,102,
		112,0,95,2,122,92,3,95,3,100,20,6,26,140,1,36,56,1,48,
		113,0,102,112,0,122,69,28,27,36,57,1,176,122,0,48,91,0,102,
		112,0,95,2,122,95,4,95,3,100,20,6,26,102,1,36,60,1,176,
		123,0,95,2,121,121,95,3,92,3,1,95,3,92,4,1,121,20,6,
		26,76,1,36,63,1,48,113,0,102,112,0,122,8,28,73,36,64,1,
		176,124,0,48,31,0,102,112,0,176,121,0,12,0,12,2,31,27,36,
		66,1,176,123,0,95,2,121,121,95,3,92,3,1,95,3,92,4,1,
		121,20,6,25,104,36,68,1,176,123,0,95,2,121,121,95,3,92,3,
		1,95,3,92,4,1,122,20,6,25,79,36,70,1,48,113,0,102,112,
		0,92,2,8,28,27,36,71,1,176,123,0,95,2,121,121,95,3,92,
		3,1,95,3,92,4,1,122,20,6,25,40,36,72,1,48,113,0,102,
		112,0,92,3,8,28,26,36,73,1,176,123,0,95,2,121,121,95,3,
		92,3,1,95,3,92,4,1,92,2,20,6,26,168,0,36,77,1,48,
		90,0,102,112,0,28,79,36,79,1,176,124,0,48,31,0,102,112,0,
		176,121,0,12,0,12,2,28,34,48,102,0,102,112,0,28,26,36,80,
		1,176,122,0,48,91,0,102,112,0,95,2,122,92,3,95,3,100,20,
		6,25,103,36,82,1,176,122,0,48,91,0,102,112,0,95,2,122,95,
		4,95,3,100,20,6,25,79,36,87,1,48,113,0,102,112,0,122,8,
		28,28,36,88,1,176,123,0,95,2,121,121,95,3,92,3,1,95,3,
		92,4,1,92,5,20,6,25,40,36,89,1,48,113,0,102,112,0,92,
		3,8,28,26,36,90,1,176,123,0,95,2,121,121,95,3,92,3,1,
		95,3,92,4,1,92,6,20,6,36,95,1,48,125,0,102,95,2,112,
		1,73,36,97,1,176,126,0,48,31,0,102,112,0,95,1,20,2,36,
		98,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_DRAWITEMS )
{
	static const HB_BYTE pcode[] =
	{
		13,5,1,36,103,1,176,112,0,48,31,0,102,112,0,12,1,80,6,
		36,104,1,176,82,0,48,127,0,102,112,0,12,1,31,54,36,105,1,
		176,128,0,95,1,95,6,122,1,92,2,72,95,6,92,2,1,92,2,
		72,95,6,92,3,1,92,2,49,95,6,92,4,1,92,2,49,48,31,
		0,48,127,0,102,112,0,112,0,20,6,36,108,1,48,129,0,102,112,
		0,100,69,29,85,1,36,109,1,48,130,0,102,112,0,121,8,28,44,
		36,110,1,48,74,0,102,48,35,0,48,129,0,102,112,0,112,0,112,
		1,73,36,111,1,48,75,0,102,48,36,0,48,129,0,102,112,0,112,
		0,112,1,73,36,114,1,48,131,0,102,112,0,100,69,28,20,48,131,
		0,102,112,0,121,69,28,10,48,131,0,102,112,0,25,24,176,132,0,
		48,35,0,102,112,0,48,130,0,102,112,0,49,92,2,18,121,12,2,
		80,2,36,116,1,48,133,0,102,112,0,100,69,28,20,48,133,0,102,
		112,0,121,69,28,10,48,133,0,102,112,0,25,24,176,132,0,48,36,
		0,102,112,0,48,134,0,102,112,0,49,92,2,18,121,12,2,80,3,
		36,117,1,48,87,0,102,112,0,29,139,0,36,118,1,48,135,0,48,
		129,0,102,112,0,112,0,106,6,72,73,67,79,78,0,8,28,29,36,
		119,1,176,136,0,95,1,48,31,0,48,129,0,102,112,0,112,0,95,
		2,95,3,20,4,25,111,36,121,1,48,137,0,102,112,0,28,35,36,
		122,1,176,138,0,95,1,48,31,0,48,129,0,102,112,0,112,0,95,
		2,95,3,48,139,0,102,112,0,20,5,25,40,36,124,1,176,140,0,
		95,1,48,31,0,48,129,0,102,112,0,112,0,100,95,2,95,3,48,
		130,0,102,112,0,48,134,0,102,112,0,20,7,25,27,36,128,1,176,
		141,0,95,1,48,31,0,48,129,0,102,112,0,112,0,95,2,95,3,
		20,4,36,132,1,48,142,0,102,112,0,100,69,29,237,0,36,133,1,
		48,44,0,102,112,0,100,69,28,23,36,134,1,176,143,0,95,1,48,
		31,0,48,44,0,102,112,0,112,0,20,2,36,136,1,48,87,0,102,
		112,0,28,20,36,137,1,176,144,0,95,1,48,145,0,102,112,0,20,
		2,25,19,36,140,1,176,144,0,95,1,176,54,0,92,3,12,1,20,
		2,36,142,1,48,146,0,102,112,0,121,69,28,10,48,146,0,102,112,
		0,25,4,92,4,80,2,36,143,1,48,147,0,102,112,0,121,69,28,
		10,48,147,0,102,112,0,25,4,92,4,80,3,36,144,1,48,35,0,
		102,112,0,92,4,49,80,4,36,145,1,48,36,0,102,112,0,92,4,
		49,80,5,36,146,1,176,148,0,95,1,120,20,2,36,148,1,176,149,
		0,95,1,48,142,0,102,112,0,95,2,95,3,95,4,95,5,48,146,
		0,102,112,0,121,69,28,5,121,25,3,122,48,147,0,102,112,0,121,
		69,28,5,121,25,4,92,36,72,20,7,36,149,1,176,148,0,95,1,
		9,20,2,36,152,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_MOUSEMOVE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,156,1,9,80,5,36,160,1,48,113,0,102,112,0,121,
		69,29,197,0,36,161,1,176,150,0,95,2,12,1,80,3,36,162,1,
		176,151,0,95,2,12,1,80,4,36,163,1,95,3,48,35,0,102,112,
		0,15,31,13,95,4,48,36,0,102,112,0,15,28,16,36,164,1,176,
		152,0,20,0,36,165,1,120,80,5,36,168,1,95,5,28,52,48,153,
		0,102,112,0,31,44,36,169,1,48,49,0,102,122,112,1,73,36,170,
		1,176,154,0,48,31,0,102,112,0,121,20,2,36,171,1,176,30,0,
		48,31,0,102,112,0,92,5,20,2,36,174,1,48,113,0,102,112,0,
		122,8,28,63,95,5,31,59,36,175,1,48,49,0,102,92,2,112,1,
		73,36,176,1,176,154,0,48,31,0,102,112,0,121,20,2,36,178,1,
		176,30,0,48,31,0,102,112,0,92,5,20,2,36,179,1,176,155,0,
		48,31,0,102,112,0,20,1,36,182,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_MDOWN )
{
	static const HB_BYTE pcode[] =
	{
		36,185,1,48,113,0,102,112,0,92,3,69,28,65,36,186,1,48,49,
		0,102,92,3,112,1,73,36,187,1,176,156,0,48,31,0,102,112,0,
		92,7,121,121,20,4,36,188,1,176,154,0,48,31,0,102,112,0,121,
		20,2,36,189,1,176,30,0,48,31,0,102,112,0,92,5,20,2,25,
		57,36,190,1,48,102,0,102,112,0,28,46,36,191,1,48,49,0,102,
		122,112,1,73,36,192,1,176,154,0,48,31,0,102,112,0,121,20,2,
		36,193,1,176,157,0,48,31,0,102,112,0,92,15,121,121,20,4,36,
		195,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_MUP )
{
	static const HB_BYTE pcode[] =
	{
		36,199,1,48,153,0,102,112,0,31,25,36,201,1,48,49,0,102,48,
		120,0,102,112,0,28,6,92,2,25,3,122,112,1,73,36,203,1,48,
		102,0,102,112,0,28,35,36,204,1,48,153,0,102,112,0,28,14,36,
		205,1,48,103,0,102,112,0,73,25,12,36,207,1,48,105,0,102,112,
		0,73,36,210,1,48,158,0,102,112,0,100,69,28,50,36,211,1,176,
		152,0,20,0,36,212,1,48,96,0,48,158,0,102,112,0,48,32,0,
		102,112,0,48,85,0,102,112,0,112,2,73,36,213,1,176,159,0,106,
		3,40,41,0,20,1,36,215,1,176,30,0,48,31,0,102,112,0,93,
		7,5,20,2,36,217,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_REFRESH )
{
	static const HB_BYTE pcode[] =
	{
		36,220,1,176,154,0,48,31,0,102,112,0,121,20,2,36,221,1,176,
		30,0,48,31,0,102,112,0,93,7,5,20,2,36,222,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_RELEASE )
{
	static const HB_BYTE pcode[] =
	{
		36,226,1,48,19,0,102,9,112,1,73,36,227,1,48,49,0,102,122,
		112,1,73,36,228,1,176,154,0,48,31,0,102,112,0,121,20,2,36,
		229,1,176,30,0,48,31,0,102,112,0,93,3,5,20,2,36,231,1,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ONGETFOCUS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,235,1,120,80,1,36,237,1,48,160,0,102,112,0,100,
		8,31,11,176,161,0,102,9,12,2,31,8,36,238,1,120,110,7,36,
		240,1,176,162,0,92,38,12,1,121,35,31,24,176,162,0,92,9,12,
		1,121,35,28,17,176,162,0,92,16,12,1,121,35,28,6,92,255,25,
		3,122,80,2,36,241,1,48,160,0,102,112,0,100,69,28,70,36,242,
		1,48,163,0,48,32,0,102,112,0,120,112,1,73,36,243,1,48,96,
		0,48,160,0,102,112,0,48,142,0,102,112,0,102,112,2,80,1,36,
		244,1,95,1,100,69,28,22,176,82,0,95,1,12,1,28,13,36,245,
		1,176,164,0,102,95,2,20,2,36,248,1,48,163,0,48,32,0,102,
		112,0,9,112,1,73,36,249,1,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ONLOSTFOCUS )
{
	static const HB_BYTE pcode[] =
	{
		36,253,1,48,165,0,102,112,0,100,69,28,17,176,161,0,102,120,12,
		2,31,8,36,254,1,120,110,7,36,0,2,48,165,0,102,112,0,100,
		69,28,56,36,1,2,48,163,0,48,32,0,102,112,0,120,112,1,73,
		36,2,2,48,96,0,48,165,0,102,112,0,48,142,0,102,112,0,102,
		112,2,73,36,3,2,48,163,0,48,32,0,102,112,0,9,112,1,73,
		36,5,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ONCLICK )
{
	static const HB_BYTE pcode[] =
	{
		36,8,2,48,158,0,102,112,0,100,69,28,40,36,10,2,48,96,0,
		48,158,0,102,112,0,102,48,85,0,102,112,0,112,2,73,36,11,2,
		48,163,0,48,32,0,102,112,0,9,112,1,73,36,13,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_END )
{
	static const HB_BYTE pcode[] =
	{
		36,18,2,48,100,0,48,42,0,102,112,0,112,0,73,36,19,2,48,
		43,0,102,100,112,1,73,36,20,2,48,129,0,102,112,0,100,69,28,
		28,36,21,2,48,103,0,48,129,0,102,112,0,112,0,73,36,22,2,
		48,67,0,102,100,112,1,73,36,24,2,176,157,0,48,31,0,102,112,
		0,92,16,121,121,20,4,36,25,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_ENABLE )
{
	static const HB_BYTE pcode[] =
	{
		36,29,2,176,88,0,48,31,0,102,112,0,120,20,2,36,30,2,48,
		63,0,102,120,112,1,73,36,31,2,176,154,0,48,31,0,102,112,0,
		121,20,2,36,32,2,176,30,0,48,31,0,102,112,0,92,5,20,2,
		36,35,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HOWNBUTTON_DISABLE )
{
	static const HB_BYTE pcode[] =
	{
		36,39,2,48,49,0,102,121,112,1,73,36,40,2,48,63,0,102,9,
		112,1,73,36,41,2,176,154,0,48,31,0,102,112,0,121,20,2,36,
		42,2,176,30,0,48,31,0,102,112,0,92,5,20,2,36,43,2,176,
		88,0,48,31,0,102,112,0,9,20,2,36,45,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,166,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}