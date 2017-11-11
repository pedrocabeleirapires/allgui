/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\htrackbr.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HTRACKBAR );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HTRACKBAR_NEW );
HB_FUNC_STATIC( HTRACKBAR_ACTIVATE );
HB_FUNC_STATIC( HTRACKBAR_ONEVENT );
HB_FUNC_STATIC( HTRACKBAR_INIT );
HB_FUNC_STATIC( HTRACKBAR_SETVALUE );
HB_FUNC_STATIC( HTRACKBAR_GETVALUE );
HB_FUNC_EXTERN( SENDMESSAGE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( INITTRACKBAR );
HB_FUNC_EXTERN( HWG_SETCURSOR );
HB_FUNC_EXTERN( GETCLIENTRECT );
HB_FUNC_EXTERN( FILLRECT );
HB_FUNC_EXTERN( GETSKIP );
HB_FUNC_EXTERN( ISCTRLSHIFT );
HB_FUNC_EXTERN( PROCKEYLIST );
HB_FUNC_EXTERN( TRACKBARSETRANGE );
HB_FUNC_EXTERN( SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITTRACKPROC );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HTRACKBR )
{ "HTRACKBAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HTRACKBAR_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_NEW )}, NULL },
{ "HTRACKBAR_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_ACTIVATE )}, NULL },
{ "HTRACKBAR_ONEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_ONEVENT )}, NULL },
{ "HTRACKBAR_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_INIT )}, NULL },
{ "HTRACKBAR_SETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_SETVALUE )}, NULL },
{ "HTRACKBAR_GETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTRACKBAR_GETVALUE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SENDMESSAGE )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_VALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BTHUMBDRAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLOW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHIGH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INITTRACKBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( INITTRACKBAR )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLOW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHIGH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HCURSOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETCURSOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETCURSOR )}, NULL },
{ "BRUSH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCLIENTRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETCLIENTRECT )}, NULL },
{ "FILLRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILLRECT )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSKIP", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSKIP )}, NULL },
{ "ISCTRLSHIFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISCTRLSHIFT )}, NULL },
{ "PROCKEYLIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCKEYLIST )}, NULL },
{ "BOTHER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TRACKBARSETRANGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRACKBARSETRANGE )}, NULL },
{ "VALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHOLDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETWINDOWOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETWINDOWOBJECT )}, NULL },
{ "HWG_INITTRACKPROC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITTRACKPROC )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HTRACKBR, "source\\htrackbr.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HTRACKBR
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HTRACKBR )
   #include "hbiniseg.h"
#endif

HB_FUNC( HTRACKBAR )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,63,0,36,23,0,103,1,0,100,8,
		29,112,2,176,1,0,104,1,0,12,1,29,101,2,
		166,39,2,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,72,84,114,97,99,107,66,97,114,0,108,
		4,4,1,0,108,0,112,3,80,2,36,25,0,48,
		5,0,95,2,100,106,18,109,115,99,116,108,115,95,
		116,114,97,99,107,98,97,114,51,50,0,95,1,121,
		72,121,72,121,72,121,72,106,9,119,105,110,99,108,
		97,115,115,0,4,1,0,9,112,5,73,36,26,0,
		48,6,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,6,118,97,108,117,101,0,4,1,0,9,112,
		5,73,36,27,0,48,6,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,8,98,67,104,97,110,103,
		101,0,4,1,0,9,112,5,73,36,28,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		11,98,84,104,117,109,98,68,114,97,103,0,4,1,
		0,9,112,5,73,36,29,0,48,6,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,5,110,76,111,
		119,0,4,1,0,9,112,5,73,36,30,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		6,110,72,105,103,104,0,4,1,0,9,112,5,73,
		36,31,0,48,6,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,8,104,67,117,114,115,111,114,0,
		4,1,0,9,112,5,73,36,35,0,48,7,0,95,
		2,106,4,78,101,119,0,108,8,95,1,121,72,121,
		72,121,72,112,3,73,36,36,0,48,7,0,95,2,
		106,9,65,99,116,105,118,97,116,101,0,108,9,95,
		1,121,72,121,72,121,72,112,3,73,36,37,0,48,
		7,0,95,2,106,8,111,110,69,118,101,110,116,0,
		108,10,95,1,121,72,121,72,121,72,112,3,73,36,
		38,0,48,7,0,95,2,106,5,73,110,105,116,0,
		108,11,95,1,121,72,121,72,121,72,112,3,73,36,
		39,0,48,7,0,95,2,106,9,83,101,116,86,97,
		108,117,101,0,108,12,95,1,121,72,121,72,121,72,
		112,3,73,36,40,0,48,7,0,95,2,106,9,71,
		101,116,86,97,108,117,101,0,108,13,95,1,121,72,
		121,72,121,72,112,3,73,36,41,0,48,14,0,95,
		2,106,11,71,101,116,78,117,109,84,105,99,115,0,
		89,25,0,1,0,0,0,176,15,0,48,16,0,95,
		1,112,0,93,16,4,121,121,12,4,6,95,1,121,
		72,121,72,121,72,112,3,73,36,43,0,48,17,0,
		95,2,112,0,73,167,14,0,0,176,18,0,104,1,
		0,95,2,20,2,168,48,19,0,95,2,112,0,80,
		3,176,20,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,21,0,95,3,164,
		146,1,0,73,95,3,110,7,48,19,0,103,1,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,19,36,49,0,95,18,100,8,28,5,122,80,
		18,36,50,0,95,19,100,8,28,5,121,80,19,36,
		51,0,95,11,100,69,28,15,36,52,0,176,22,0,
		95,18,122,12,2,80,18,36,55,0,176,22,0,95,
		4,100,8,28,5,121,25,4,95,4,97,0,0,1,
		80,12,2,80,4,36,56,0,96,4,0,95,17,100,
		69,28,10,95,17,28,6,92,2,25,3,121,135,36,
		57,0,96,4,0,95,18,95,19,72,135,36,60,0,
		48,2,0,48,23,0,102,112,0,95,1,95,2,95,
		4,95,5,95,6,95,7,95,8,100,95,9,95,10,
		95,11,95,12,112,12,73,36,62,0,48,24,0,102,
		176,25,0,95,3,12,1,106,2,78,0,8,28,6,
		95,3,25,3,121,112,1,73,36,63,0,48,26,0,
		102,95,13,112,1,73,36,64,0,48,27,0,102,95,
		14,112,1,73,36,65,0,48,28,0,102,95,15,100,
		8,28,5,121,25,4,95,15,112,1,73,36,66,0,
		48,29,0,102,95,16,100,8,28,6,92,100,25,4,
		95,16,112,1,73,36,68,0,176,30,0,20,0,36,
		69,0,48,31,0,102,112,0,73,36,71,0,102,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,74,0,176,32,0,48,16,0,48,33,0,102,112,
		0,112,0,12,1,31,86,36,77,0,48,34,0,102,
		176,35,0,48,16,0,48,33,0,102,112,0,112,0,
		48,36,0,102,112,0,48,37,0,102,112,0,48,38,
		0,102,112,0,48,39,0,102,112,0,48,40,0,102,
		112,0,48,41,0,102,112,0,48,42,0,102,112,0,
		48,43,0,102,112,0,12,9,112,1,73,36,78,0,
		48,44,0,102,112,0,73,36,81,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,86,0,95,1,92,15,8,28,38,36,
		87,0,48,45,0,102,112,0,100,69,29,52,1,36,
		88,0,48,46,0,48,45,0,102,112,0,102,112,1,
		73,36,89,0,121,110,7,36,91,0,95,1,93,0,
		2,8,28,33,36,92,0,48,47,0,102,112,0,100,
		69,29,5,1,36,93,0,176,48,0,48,47,0,102,
		112,0,20,1,26,244,0,36,95,0,95,1,92,20,
		8,28,82,36,96,0,48,49,0,102,112,0,100,69,
		29,220,0,36,97,0,176,50,0,48,16,0,102,112,
		0,12,1,80,4,36,99,0,176,51,0,95,2,95,
		4,122,1,95,4,92,2,1,95,4,92,3,1,122,
		72,95,4,92,4,1,122,72,48,16,0,48,49,0,
		102,112,0,112,0,20,6,36,100,0,122,110,7,36,
		102,0,95,1,92,2,8,28,15,36,103,0,48,52,
		0,102,112,0,73,26,131,0,36,104,0,95,1,93,
		2,1,8,28,53,36,105,0,95,2,92,9,5,28,
		109,36,107,0,176,53,0,48,33,0,102,112,0,48,
		16,0,102,112,0,100,176,54,0,9,120,12,2,28,
		6,92,255,25,3,122,20,4,36,108,0,121,110,7,
		36,110,0,95,1,93,0,1,5,28,21,36,111,0,
		176,55,0,102,95,2,12,2,28,44,36,112,0,121,
		110,7,36,114,0,48,56,0,102,112,0,100,69,28,
		25,36,115,0,48,46,0,48,56,0,102,112,0,102,
		95,1,95,2,95,3,112,4,110,7,36,118,0,92,
		255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,121,0,48,57,0,102,112,0,31,120,36,122,0,
		48,44,0,48,23,0,102,112,0,112,0,73,36,123,
		0,176,58,0,48,16,0,102,112,0,48,42,0,102,
		112,0,48,43,0,102,112,0,20,3,36,124,0,176,
		15,0,48,16,0,102,112,0,93,5,4,122,48,59,
		0,102,112,0,20,4,36,125,0,48,45,0,102,112,
		0,100,69,28,42,36,126,0,48,60,0,102,122,112,
		1,73,36,127,0,176,61,0,48,16,0,102,112,0,
		102,20,2,36,128,0,176,62,0,48,16,0,102,112,
		0,20,1,36,132,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_SETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,135,0,176,25,0,95,1,12,1,106,
		2,78,0,8,28,34,36,136,0,176,15,0,48,16,
		0,102,112,0,93,5,4,122,95,1,20,4,36,137,
		0,48,24,0,102,95,1,112,1,73,36,140,0,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTRACKBAR_GETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,143,0,48,24,0,102,176,15,0,48,16,0,102,
		112,0,93,0,4,121,121,12,4,112,1,73,36,145,
		0,48,59,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,63,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

#line 148 "source\\htrackbr.prg"

#include "hwingui.h"
#include <commctrl.h>

HB_FUNC ( INITTRACKBAR )
{
    HWND hTrackBar;

    hTrackBar = CreateWindow( TRACKBAR_CLASS,
                             0,
                             ( LONG )  hb_parnl( 3 ),
                                       hb_parni( 4 ),
                                       hb_parni( 5 ),
                                       hb_parni( 6 ),
                                       hb_parni( 7 ),
                             ( HWND )  HB_PARHANDLE( 1 ),
                             ( HMENU ) hb_parni( 2 ),
                             GetModuleHandle( NULL ),
                             NULL ) ;

    HB_RETHANDLE(  hTrackBar );
}

HB_FUNC ( TRACKBARSETRANGE )
{
    SendMessage( (HWND) HB_PARHANDLE( 1 ), TBM_SETRANGE, TRUE,
                  MAKELONG( hb_parni( 2 ), hb_parni( 3 ) ) );
}
