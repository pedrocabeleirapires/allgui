/*
 * Harbour 3.2.0dev (r1310312321)
 * Microsoft Visual C 16.0.40219 (32-bit)
 * Generated C source from "source\hradio.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HRADIOGROUP );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HRADIOGROUP_NEW );
HB_FUNC_STATIC( HRADIOGROUP_NEWRG );
HB_FUNC_STATIC( HRADIOGROUP_ENDGROUP );
HB_FUNC_STATIC( HRADIOGROUP_SETVALUE );
HB_FUNC_STATIC( HRADIOGROUP_VALUE );
HB_FUNC_STATIC( HRADIOGROUP_REFRESH );
HB_FUNC_STATIC( HRADIOGROUP_ENABLE );
HB_FUNC_STATIC( HRADIOGROUP_DISABLE );
HB_FUNC_STATIC( HRADIOGROUP_INIT );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWINDOW );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HGROUP );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( HWG_CHECKRADIOBUTTON );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC( HRADIOBUTTON );
HB_FUNC_STATIC( HRADIOBUTTON_NEW );
HB_FUNC_STATIC( HRADIOBUTTON_ACTIVATE );
HB_FUNC_STATIC( HRADIOBUTTON_INIT );
HB_FUNC_STATIC( HRADIOBUTTON_REDEFINE );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_STATIC( HRADIOBUTTON_ONEVENT );
HB_FUNC_STATIC( HRADIOBUTTON_ONGOTFOCUS );
HB_FUNC_STATIC( HRADIOBUTTON_ONCLICK );
HB_FUNC_STATIC( HRADIOBUTTON_VALID );
HB_FUNC_STATIC( HRADIOBUTTON_WHEN );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_CHECKFOCUS );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( HWG_CREATEBUTTON );
HB_FUNC_EXTERN( HWG_SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITBUTTONPROC );
HB_FUNC_EXTERN( HWG_PROCOKCANCEL );
HB_FUNC_EXTERN( HWG_GETPARENTFORM );
HB_FUNC_EXTERN( HWG_GETDLGMESSAGE );
HB_FUNC_EXTERN( HWG_GETSKIP );
HB_FUNC_EXTERN( HWG_ISCTRLSHIFT );
HB_FUNC_EXTERN( HWG_PROCKEYLIST );
HB_FUNC_EXTERN( HWG_GETKEYSTATE );
HB_FUNC_EXTERN( HWG_WHENSETFOCUS );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( HWG_GETFOCUS );
HB_FUNC_EXTERN( HWG_SELFFOCUS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HRADIO )
{ "HRADIOGROUP", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HRADIOGROUP_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_NEW )}, NULL },
{ "HRADIOGROUP_NEWRG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_NEWRG )}, NULL },
{ "HRADIOGROUP_ENDGROUP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_ENDGROUP )}, NULL },
{ "HRADIOGROUP_SETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_SETVALUE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HRADIOGROUP_VALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_VALUE )}, NULL },
{ "HRADIOGROUP_REFRESH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_REFRESH )}, NULL },
{ "HRADIOGROUP_ENABLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_ENABLE )}, NULL },
{ "HRADIOGROUP_DISABLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_DISABLE )}, NULL },
{ "HRADIOGROUP_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOGROUP_INIT )}, NULL },
{ "ADDVIRTUAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGROUPCURRENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ABUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETMAIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWINDOW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWINDOW )}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITAND )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BGETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "_NVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSETGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OHGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HGROUP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGROUP )}, NULL },
{ "_LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OGROUPCURRENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "ABUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_CHECKRADIOBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CHECKRADIOBUTTON )}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BSETGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HRADIOBUTTON", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON )}, NULL },
{ "HRADIOBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_NEW )}, NULL },
{ "HRADIOBUTTON_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ACTIVATE )}, NULL },
{ "HRADIOBUTTON_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_INIT )}, NULL },
{ "HRADIOBUTTON_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_REDEFINE )}, NULL },
{ "HWG_SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SENDMESSAGE )}, NULL },
{ "HRADIOBUTTON_ONEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONEVENT )}, NULL },
{ "HRADIOBUTTON_ONGOTFOCUS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONGOTFOCUS )}, NULL },
{ "HRADIOBUTTON_ONCLICK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_ONCLICK )}, NULL },
{ "HRADIOBUTTON_VALID", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_VALID )}, NULL },
{ "HRADIOBUTTON_WHEN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HRADIOBUTTON_WHEN )}, NULL },
{ "_ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_TITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "OGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BACKSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BGETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLOSTFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDEVENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "WHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FINDCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LNOVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_CHECKFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CHECKFOCUS )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ONCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_CREATEBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_CREATEBUTTON )}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHOLDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETWINDOWOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETWINDOWOBJECT )}, NULL },
{ "HWG_INITBUTTONPROC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITBUTTONPROC )}, NULL },
{ "LENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OFONT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ANCHOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSIZE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BPAINT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_TOOLTIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BOTHER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_PROCOKCANCEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_PROCOKCANCEL )}, NULL },
{ "TYPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETPARENTFORM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETPARENTFORM )}, NULL },
{ "ISENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETDLGMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETDLGMESSAGE )}, NULL },
{ "VALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETSKIP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETSKIP )}, NULL },
{ "HWG_ISCTRLSHIFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ISCTRLSHIFT )}, NULL },
{ "HWG_PROCKEYLIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_PROCKEYLIST )}, NULL },
{ "_LWHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETKEYSTATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETKEYSTATE )}, NULL },
{ "_LSUSPENDMSGSHANDLING", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_WHENSETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_WHENSETFOCUS )}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LNOVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LWHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "GETVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETFOCUS )}, NULL },
{ "BLOSTFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SELFFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SELFFOCUS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HRADIO, "source\\hradio.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HRADIO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HRADIO )
   #include "hbiniseg.h"
#endif

HB_FUNC( HRADIOGROUP )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,137,0,36,16,0,103,1,0,100,8,
		29,16,3,176,1,0,104,1,0,12,1,29,5,3,
		166,199,2,0,122,80,1,48,2,0,176,3,0,12,
		0,106,12,72,82,97,100,105,111,71,114,111,117,112,
		0,108,4,4,1,0,108,0,112,3,80,2,36,18,
		0,48,5,0,95,2,100,106,7,83,84,65,84,73,
		67,0,95,1,121,72,121,72,121,72,121,72,106,9,
		119,105,110,99,108,97,115,115,0,4,1,0,9,112,
		5,73,36,19,0,48,5,0,95,2,100,100,95,1,
		121,72,121,72,121,72,121,72,106,14,111,71,114,111,
		117,112,67,117,114,114,101,110,116,0,4,1,0,9,
		112,5,73,36,20,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,9,97,66,117,116,116,
		111,110,115,0,4,1,0,9,112,5,73,36,21,0,
		48,6,0,95,2,100,122,95,1,121,72,121,72,121,
		72,106,7,110,86,97,108,117,101,0,4,1,0,9,
		112,5,73,36,22,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,8,98,83,101,116,71,
		101,116,0,4,1,0,9,112,5,73,36,23,0,48,
		6,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,8,111,72,71,114,111,117,112,0,4,1,0,9,
		112,5,73,36,24,0,48,6,0,95,2,100,120,95,
		1,121,72,121,72,121,72,106,9,108,69,110,97,98,
		108,101,100,0,4,1,0,9,112,5,73,36,25,0,
		48,6,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,7,98,67,108,105,99,107,0,4,1,0,9,
		112,5,73,36,27,0,48,7,0,95,2,106,4,78,
		101,119,0,108,8,95,1,121,72,121,72,121,72,112,
		3,73,36,29,0,48,7,0,95,2,106,6,78,101,
		119,114,103,0,108,9,95,1,121,72,121,72,121,72,
		112,3,73,36,30,0,48,7,0,95,2,106,9,69,
		110,100,71,114,111,117,112,0,108,10,95,1,121,72,
		121,72,121,72,112,3,73,36,31,0,48,7,0,95,
		2,106,9,83,101,116,86,97,108,117,101,0,108,11,
		95,1,121,72,121,72,121,72,112,3,73,36,32,0,
		48,12,0,95,2,106,9,71,101,116,86,97,108,117,
		101,0,89,15,0,1,0,0,0,48,13,0,95,1,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,
		36,33,0,48,7,0,95,2,106,6,86,97,108,117,
		101,0,108,14,95,1,121,72,121,72,112,3,73,48,
		7,0,95,2,106,7,95,86,97,108,117,101,0,108,
		14,95,1,121,72,121,72,121,72,112,3,73,36,34,
		0,48,7,0,95,2,106,8,82,101,102,114,101,115,
		104,0,108,15,95,1,121,72,121,72,121,72,112,3,
		73,36,36,0,48,7,0,95,2,106,7,69,110,97,
		98,108,101,0,108,16,95,1,121,72,121,72,121,72,
		112,3,73,36,37,0,48,7,0,95,2,106,8,68,
		105,115,97,98,108,101,0,108,17,95,1,121,72,121,
		72,121,72,112,3,73,36,39,0,48,7,0,95,2,
		106,5,73,110,105,116,0,108,18,95,1,121,72,121,
		72,121,72,112,3,73,36,40,0,48,19,0,95,2,
		106,9,65,99,116,105,118,97,116,101,0,112,1,73,
		36,42,0,48,20,0,95,2,112,0,73,167,14,0,
		0,176,21,0,104,1,0,95,2,20,2,168,48,22,
		0,95,2,112,0,80,3,176,23,0,95,3,106,10,
		73,110,105,116,67,108,97,115,115,0,12,2,28,12,
		48,24,0,95,3,164,146,1,0,73,95,3,110,7,
		48,22,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,6,36,46,0,48,25,0,102,102,112,1,73,
		36,47,0,48,26,0,102,4,0,0,112,1,73,36,
		48,0,48,27,0,102,48,28,0,176,29,0,12,0,
		112,0,100,69,28,19,48,30,0,48,28,0,176,29,
		0,12,0,112,0,112,0,25,3,100,112,1,73,36,
		49,0,48,31,0,102,176,32,0,95,6,97,0,0,
		0,8,12,2,121,15,68,112,1,73,36,51,0,48,
		2,0,48,33,0,102,112,0,48,34,0,102,112,0,
		100,100,100,100,100,100,100,95,3,112,9,73,36,53,
		0,48,35,0,102,95,3,112,1,73,36,54,0,48,
		36,0,102,95,4,112,1,73,36,55,0,48,37,0,
		102,95,5,112,1,73,36,57,0,95,1,100,69,28,
		31,36,58,0,176,38,0,95,1,12,1,106,2,78,
		0,8,28,14,36,59,0,48,39,0,102,95,1,112,
		1,73,36,63,0,48,40,0,102,95,2,112,1,73,
		36,65,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_NEWRG )
{
	static const HB_BYTE pcode[] =
	{
		13,0,18,36,71,0,48,25,0,102,102,112,1,73,
		36,72,0,48,26,0,102,4,0,0,112,1,73,36,
		73,0,48,31,0,102,176,32,0,95,3,97,0,0,
		0,8,12,2,121,15,68,112,1,73,36,75,0,48,
		2,0,48,33,0,102,112,0,48,34,0,102,112,0,
		100,100,95,6,95,7,95,8,95,9,95,11,95,12,
		112,9,73,36,77,0,48,41,0,102,48,2,0,176,
		42,0,12,0,95,1,95,2,95,3,95,6,95,7,
		95,8,95,9,95,10,95,11,95,12,95,13,100,95,
		14,95,15,95,18,102,112,16,112,1,73,36,79,0,
		48,43,0,102,120,112,1,73,36,80,0,48,35,0,
		102,95,12,112,1,73,36,81,0,48,36,0,102,95,
		16,112,1,73,36,82,0,48,37,0,102,95,17,112,
		1,73,36,84,0,95,4,100,69,28,31,36,85,0,
		176,38,0,95,4,12,1,106,2,78,0,8,28,14,
		36,86,0,48,39,0,102,95,4,112,1,73,36,89,
		0,48,40,0,102,95,5,112,1,73,36,91,0,102,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_ENDGROUP )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,96,0,48,44,0,102,112,0,100,69,
		29,165,1,176,45,0,48,46,0,48,44,0,102,112,
		0,112,0,12,1,165,80,2,121,15,29,141,1,36,
		99,0,95,1,100,69,28,19,95,1,95,2,34,28,
		12,95,1,121,15,28,6,95,1,25,13,48,13,0,
		48,44,0,102,112,0,112,0,80,1,36,100,0,95,
		1,121,69,29,47,1,95,1,95,2,34,29,39,1,
		36,101,0,48,47,0,48,46,0,48,44,0,102,112,
		0,112,0,95,2,1,112,0,121,15,28,93,36,105,
		0,176,48,0,48,47,0,48,34,0,48,46,0,48,
		44,0,102,112,0,112,0,95,2,1,112,0,112,0,
		48,49,0,48,46,0,48,44,0,102,112,0,112,0,
		122,1,112,0,48,49,0,48,46,0,48,44,0,102,
		112,0,112,0,95,2,1,112,0,48,49,0,48,46,
		0,48,44,0,102,112,0,112,0,95,1,1,112,0,
		20,4,26,178,0,36,111,0,48,35,0,48,46,0,
		48,44,0,102,112,0,112,0,95,2,1,106,43,123,
		124,111,124,104,119,103,95,67,104,101,99,107,114,97,
		100,105,111,98,117,116,116,111,110,40,111,58,111,80,
		97,114,101,110,116,58,104,97,110,100,108,101,44,0,
		176,50,0,176,51,0,48,49,0,48,46,0,48,44,
		0,102,112,0,112,0,122,1,112,0,12,1,12,1,
		72,106,2,44,0,72,176,50,0,176,51,0,48,49,
		0,48,46,0,48,44,0,102,112,0,112,0,95,2,
		1,112,0,12,1,12,1,72,106,2,44,0,72,176,
		50,0,176,51,0,48,49,0,48,46,0,48,44,0,
		102,112,0,112,0,95,1,1,112,0,12,1,12,1,
		72,106,3,41,125,0,72,40,11,112,1,73,36,114,
		0,176,52,0,48,34,0,102,112,0,12,1,28,31,
		36,115,0,48,27,0,102,48,34,0,48,46,0,48,
		44,0,102,112,0,112,0,95,2,1,112,0,112,1,
		73,36,119,0,48,25,0,102,100,112,1,73,36,121,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,125,0,48,53,0,102,112,0,31,17,36,132,0,
		48,54,0,48,33,0,102,112,0,112,0,73,36,135,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_SETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,140,0,176,45,0,48,46,0,102,112,
		0,12,1,165,80,2,121,15,29,132,0,95,1,121,
		15,28,125,95,1,95,2,34,28,118,36,144,0,176,
		48,0,48,47,0,48,34,0,48,46,0,102,112,0,
		95,2,1,112,0,112,0,48,49,0,48,46,0,102,
		112,0,122,1,112,0,48,49,0,48,46,0,102,112,
		0,95,2,1,112,0,48,49,0,48,46,0,102,112,
		0,95,1,1,112,0,20,4,36,145,0,48,39,0,
		102,95,1,112,1,73,36,146,0,48,55,0,102,112,
		0,100,69,28,89,36,147,0,48,56,0,48,55,0,
		102,112,0,48,13,0,102,112,0,112,1,73,25,66,
		36,149,0,95,2,121,15,28,57,36,153,0,176,48,
		0,48,47,0,48,34,0,48,46,0,102,112,0,95,
		2,1,112,0,112,0,48,49,0,48,46,0,102,112,
		0,122,1,112,0,48,49,0,48,46,0,102,112,0,
		95,2,1,112,0,121,20,4,36,156,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_VALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,160,0,95,1,100,69,28,14,36,161,
		0,48,57,0,102,95,1,112,1,73,36,164,0,48,
		13,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_REFRESH )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,169,0,48,55,0,102,112,0,100,69,
		28,66,36,170,0,48,56,0,48,55,0,102,112,0,
		100,102,112,2,80,1,36,171,0,95,1,100,5,31,
		16,176,38,0,95,1,12,1,106,2,78,0,69,28,
		13,36,172,0,48,13,0,102,112,0,80,1,36,174,
		0,48,57,0,102,95,1,112,1,73,36,177,0,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_ENABLE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,180,0,176,45,0,48,46,0,102,112,
		0,12,1,80,2,36,182,0,122,165,80,1,25,26,
		36,183,0,48,58,0,48,46,0,102,112,0,95,1,
		1,112,0,73,36,182,0,175,1,0,95,2,15,28,
		229,36,186,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOGROUP_DISABLE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,189,0,176,45,0,48,46,0,102,112,
		0,12,1,80,2,36,191,0,122,165,80,1,25,26,
		36,192,0,48,59,0,48,46,0,102,112,0,95,1,
		1,112,0,73,36,191,0,175,1,0,95,2,15,28,
		229,36,195,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HRADIOBUTTON )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,137,0,36,198,0,103,2,0,100,8,
		29,55,2,176,1,0,104,2,0,12,1,29,44,2,
		166,238,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,13,72,82,97,100,105,111,66,117,116,116,111,
		110,0,108,4,4,1,0,108,60,112,3,80,2,36,
		200,0,48,5,0,95,2,100,106,7,66,85,84,84,
		79,78,0,95,1,121,72,121,72,121,72,121,72,106,
		9,119,105,110,99,108,97,115,115,0,4,1,0,9,
		112,5,73,36,201,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,7,111,71,114,111,117,
		112,0,4,1,0,9,112,5,73,36,202,0,48,6,
		0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		6,108,87,104,101,110,0,4,1,0,9,112,5,73,
		36,205,0,48,7,0,95,2,106,4,78,101,119,0,
		108,61,95,1,121,72,121,72,121,72,112,3,73,36,
		206,0,48,7,0,95,2,106,9,65,99,116,105,118,
		97,116,101,0,108,62,95,1,121,72,121,72,121,72,
		112,3,73,36,207,0,48,7,0,95,2,106,5,73,
		110,105,116,0,108,63,95,1,121,72,121,72,121,72,
		112,3,73,36,208,0,48,7,0,95,2,106,9,82,
		101,100,101,102,105,110,101,0,108,64,95,1,121,72,
		121,72,121,72,112,3,73,36,209,0,48,12,0,95,
		2,106,9,71,101,116,86,97,108,117,101,0,89,27,
		0,1,0,0,0,176,65,0,48,47,0,95,1,112,
		0,93,240,0,121,121,12,4,122,8,6,95,1,121,
		72,121,72,121,72,112,3,73,36,211,0,48,7,0,
		95,2,106,8,111,110,101,118,101,110,116,0,108,66,
		95,1,121,72,121,72,121,72,112,3,73,36,212,0,
		48,7,0,95,2,106,11,111,110,71,111,116,70,111,
		99,117,115,0,108,67,95,1,121,72,121,72,121,72,
		112,3,73,36,213,0,48,7,0,95,2,106,8,111,
		110,67,108,105,99,107,0,108,68,95,1,121,72,121,
		72,121,72,112,3,73,36,214,0,48,7,0,95,2,
		106,6,86,97,108,105,100,0,108,69,95,1,121,72,
		121,72,121,72,112,3,73,36,215,0,48,7,0,95,
		2,106,5,87,104,101,110,0,108,70,95,1,121,72,
		121,72,121,72,112,3,73,36,217,0,48,20,0,95,
		2,112,0,73,167,14,0,0,176,21,0,104,2,0,
		95,2,20,2,168,48,22,0,95,2,112,0,80,3,
		176,23,0,95,3,106,10,73,110,105,116,67,108,97,
		115,115,0,12,2,28,12,48,24,0,95,3,164,146,
		1,0,73,95,3,110,7,48,22,0,103,2,0,112,
		0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,18,36,220,0,102,80,19,36,222,0,48,27,
		0,95,19,95,1,100,8,28,11,48,30,0,95,19,
		112,0,25,4,95,1,112,1,73,36,223,0,48,71,
		0,95,19,95,2,100,8,28,11,48,72,0,95,19,
		112,0,25,4,95,2,112,1,73,36,224,0,48,73,
		0,95,19,95,8,112,1,73,36,225,0,48,74,0,
		95,19,48,44,0,176,0,0,12,0,112,0,112,1,
		73,36,226,0,48,75,0,95,19,176,32,0,95,3,
		97,0,0,0,8,12,2,121,15,68,112,1,73,36,
		229,0,48,76,0,95,19,176,77,0,95,3,100,8,
		28,5,121,25,4,95,3,93,4,64,48,78,0,95,
		19,112,0,100,69,28,28,176,52,0,48,46,0,48,
		78,0,95,19,112,0,112,0,12,1,28,9,97,0,
		0,2,0,25,3,121,72,12,2,112,1,73,36,231,
		0,48,2,0,48,33,0,95,19,112,0,95,1,95,
		2,48,79,0,95,19,112,0,95,4,95,5,95,6,
		95,7,95,9,95,10,95,11,95,12,95,14,95,15,
		95,16,112,14,73,36,232,0,48,80,0,95,19,95,
		18,100,69,28,9,95,18,28,5,122,25,4,92,2,
		112,1,73,36,234,0,48,81,0,95,19,112,0,73,
		36,238,0,48,78,0,95,19,112,0,100,69,28,56,
		36,239,0,95,13,100,69,28,6,95,13,25,14,48,
		82,0,48,78,0,95,19,112,0,112,0,80,13,36,
		240,0,95,17,100,69,28,6,95,17,25,14,48,83,
		0,48,78,0,95,19,112,0,112,0,80,17,36,242,
		0,95,13,100,69,28,42,48,78,0,95,19,112,0,
		100,8,31,18,48,55,0,48,78,0,95,19,112,0,
		112,0,100,8,28,15,36,243,0,48,84,0,95,19,
		95,13,112,1,73,36,245,0,48,37,0,95,19,95,
		17,112,1,73,36,246,0,95,17,100,69,28,74,36,
		247,0,48,85,0,48,34,0,95,19,112,0,92,6,
		95,19,89,26,0,2,0,1,0,19,0,48,86,0,
		95,255,48,87,0,95,1,95,2,112,1,112,1,6,
		100,106,11,111,110,71,111,116,70,111,99,117,115,0,
		112,5,73,36,249,0,48,88,0,95,19,120,112,1,
		73,36,252,0,48,85,0,48,34,0,95,19,112,0,
		92,7,95,19,89,18,0,0,0,1,0,19,0,176,
		89,0,95,255,120,12,2,6,112,3,73,36,254,0,
		48,78,0,95,19,112,0,100,69,28,84,36,255,0,
		176,90,0,48,46,0,48,78,0,95,19,112,0,112,
		0,95,19,20,2,36,1,1,48,84,0,95,19,95,
		13,112,1,73,36,3,1,48,85,0,48,34,0,95,
		19,112,0,121,95,19,89,17,0,0,0,1,0,19,
		0,48,91,0,95,255,112,0,6,100,106,8,111,110,
		67,108,105,99,107,0,112,5,73,36,7,1,95,19,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,11,1,176,52,0,48,47,0,48,34,0,102,112,
		0,112,0,12,1,31,80,36,13,1,48,92,0,102,
		176,93,0,48,47,0,48,34,0,102,112,0,112,0,
		48,49,0,102,112,0,48,79,0,102,112,0,48,94,
		0,102,112,0,48,95,0,102,112,0,48,96,0,102,
		112,0,48,97,0,102,112,0,48,98,0,102,112,0,
		12,8,112,1,73,36,14,1,48,54,0,102,112,0,
		73,36,17,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,21,1,48,53,0,102,112,0,31,88,36,22,1,
		48,99,0,102,122,112,1,73,36,23,1,176,100,0,
		48,47,0,102,112,0,102,20,2,36,24,1,176,101,
		0,48,47,0,102,112,0,20,1,36,25,1,48,75,
		0,102,48,102,0,48,78,0,102,112,0,112,0,21,
		28,9,73,48,103,0,102,112,0,112,1,73,36,26,
		1,48,54,0,48,33,0,102,112,0,112,0,73,36,
		29,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,12,36,31,1,102,80,13,36,33,1,48,27,
		0,95,13,95,1,100,8,28,11,48,30,0,95,13,
		112,0,25,4,95,1,112,1,73,36,34,1,48,71,
		0,95,13,95,2,112,1,73,36,35,1,48,74,0,
		95,13,48,44,0,176,0,0,12,0,112,0,112,1,
		73,36,36,1,48,76,0,95,13,48,104,0,95,13,
		48,105,0,95,13,48,106,0,95,13,48,107,0,95,
		13,121,112,1,112,1,112,1,112,1,112,1,73,36,
		37,1,48,108,0,95,13,95,3,112,1,73,36,38,
		1,48,35,0,95,13,95,4,112,1,73,36,39,1,
		176,38,0,95,5,12,1,106,2,78,0,8,28,17,
		36,40,1,48,109,0,95,13,95,5,112,1,73,25,
		15,36,42,1,48,110,0,95,13,95,5,112,1,73,
		36,44,1,48,111,0,95,13,95,6,112,1,73,36,
		45,1,48,112,0,95,13,95,8,112,1,73,36,52,
		1,48,80,0,95,13,95,12,100,69,28,9,95,12,
		28,5,122,25,4,92,2,112,1,73,36,53,1,48,
		113,0,95,13,95,9,95,10,120,112,3,73,36,54,
		1,48,114,0,48,34,0,95,13,112,0,95,13,112,
		1,73,36,56,1,95,7,100,69,28,42,48,78,0,
		95,13,112,0,100,8,31,18,48,55,0,48,78,0,
		95,13,112,0,112,0,100,8,28,15,36,58,1,48,
		84,0,95,13,95,7,112,1,73,36,61,1,48,37,
		0,95,13,95,11,112,1,73,36,62,1,95,11,100,
		69,28,74,36,63,1,48,85,0,48,34,0,95,13,
		112,0,92,6,95,13,89,26,0,2,0,1,0,13,
		0,48,86,0,95,255,48,87,0,95,1,95,2,112,
		1,112,1,6,100,106,11,111,110,71,111,116,70,111,
		99,117,115,0,112,5,73,36,64,1,48,88,0,95,
		13,120,112,1,73,36,67,1,48,85,0,48,34,0,
		95,13,112,0,92,7,95,13,89,18,0,0,0,1,
		0,13,0,176,89,0,95,255,120,12,2,6,112,3,
		73,36,68,1,48,78,0,95,13,112,0,100,69,28,
		84,36,69,1,176,90,0,48,46,0,48,78,0,95,
		13,112,0,112,0,95,13,20,2,36,71,1,48,84,
		0,95,13,95,7,112,1,73,36,73,1,48,85,0,
		48,34,0,95,13,112,0,121,95,13,89,17,0,0,
		0,1,0,13,0,48,91,0,95,255,112,0,6,100,
		106,8,111,110,67,108,105,99,107,0,112,5,73,36,
		77,1,95,13,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,82,1,48,115,0,102,112,0,100,69,
		28,34,36,83,1,48,56,0,48,115,0,102,112,0,
		102,95,1,95,2,95,3,112,4,92,255,69,28,8,
		36,84,1,121,110,7,36,87,1,95,1,93,135,0,
		5,29,187,0,36,88,1,95,2,92,13,5,28,32,
		176,116,0,102,95,2,48,117,0,176,118,0,102,12,
		1,112,0,92,10,16,12,3,28,8,36,89,1,121,
		110,7,36,91,1,95,2,92,27,5,28,38,48,87,
		0,176,118,0,102,12,1,92,2,112,1,165,80,4,
		100,69,28,18,48,119,0,95,4,112,0,31,9,36,
		92,1,92,4,110,7,36,94,1,95,2,92,9,69,
		28,15,176,120,0,95,3,12,1,93,2,1,5,31,
		22,176,120,0,95,3,12,1,93,6,1,5,31,9,
		95,2,92,27,5,28,9,36,95,1,92,255,110,7,
		36,96,1,176,120,0,95,3,12,1,93,0,1,5,
		28,27,95,2,92,13,5,28,20,36,97,1,48,121,
		0,102,92,13,112,1,73,36,98,1,122,110,7,36,
		100,1,92,4,110,7,36,101,1,95,1,93,0,1,
		5,29,173,0,36,103,1,95,2,92,37,5,31,9,
		95,2,92,38,5,28,31,36,104,1,176,122,0,48,
		34,0,102,112,0,48,47,0,102,112,0,100,92,255,
		20,4,36,105,1,121,110,7,36,106,1,95,2,92,
		39,5,31,9,95,2,92,40,5,28,30,36,107,1,
		176,122,0,48,34,0,102,112,0,48,47,0,102,112,
		0,100,122,20,4,36,108,1,121,110,7,36,109,1,
		95,2,92,9,5,28,43,36,110,1,176,122,0,48,
		34,0,102,112,0,48,47,0,102,112,0,100,176,123,
		0,9,120,12,2,28,6,92,255,25,3,122,20,4,
		36,111,1,121,110,7,36,113,1,95,2,92,13,8,
		28,67,36,114,1,48,121,0,102,92,13,112,1,73,
		36,115,1,121,110,7,36,117,1,95,1,93,1,1,
		8,28,29,36,118,1,176,124,0,102,95,2,20,2,
		36,119,1,95,2,92,13,8,28,17,36,120,1,121,
		110,7,36,122,1,95,1,92,78,8,73,36,125,1,
		92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONGOTFOCUS )
{
	static const HB_BYTE pcode[] =
	{
		36,162,1,48,86,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_ONCLICK )
{
	static const HB_BYTE pcode[] =
	{
		36,166,1,48,125,0,102,9,112,1,73,36,167,1,
		48,88,0,102,9,112,1,73,36,169,1,48,121,0,
		102,121,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_WHEN )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,172,1,120,80,1,36,174,1,176,89,
		0,102,9,12,2,31,8,36,175,1,120,110,7,36,
		177,1,176,126,0,92,38,12,1,121,35,31,24,176,
		126,0,92,9,12,1,121,35,28,17,176,126,0,92,
		16,12,1,121,35,28,6,92,255,25,3,122,80,2,
		36,178,1,48,125,0,102,176,126,0,92,38,12,1,
		176,126,0,92,40,12,1,72,176,126,0,92,13,12,
		1,72,176,126,0,92,9,12,1,72,121,35,112,1,
		73,36,179,1,48,83,0,102,112,0,100,69,28,116,
		36,180,1,48,88,0,102,120,112,1,73,36,181,1,
		48,127,0,48,34,0,102,112,0,120,112,1,73,36,
		182,1,48,56,0,48,83,0,102,112,0,48,13,0,
		48,78,0,102,112,0,112,0,102,112,2,80,1,36,
		183,1,48,88,0,102,95,1,68,112,1,73,36,184,
		1,48,127,0,48,34,0,102,112,0,9,112,1,73,
		36,185,1,95,1,31,15,36,186,1,176,128,0,102,
		95,2,20,2,25,12,36,188,1,48,129,0,102,112,
		0,73,36,192,1,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRADIOBUTTON_VALID )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,194,1,102,80,2,36,195,1,95,1,
		100,5,28,5,122,25,4,95,1,80,3,36,199,1,
		48,130,0,95,2,112,0,31,65,176,126,0,92,37,
		12,1,176,126,0,92,39,12,1,72,176,126,0,92,
		38,12,1,72,176,126,0,92,40,12,1,72,176,126,
		0,92,9,12,1,72,121,35,31,22,48,78,0,95,
		2,112,0,100,5,31,11,48,131,0,95,2,112,0,
		28,20,36,200,1,48,125,0,95,2,9,112,1,73,
		36,201,1,120,110,7,36,203,1,48,127,0,48,34,
		0,95,2,112,0,120,112,1,73,36,204,1,176,132,
		0,48,46,0,48,78,0,95,2,112,0,112,0,89,
		25,0,1,0,1,0,2,0,48,49,0,95,1,112,
		0,48,49,0,95,255,112,0,8,6,12,2,80,5,
		36,205,1,95,3,92,13,5,28,75,36,207,1,48,
		133,0,95,2,112,0,32,181,0,36,208,1,48,39,
		0,48,78,0,95,2,112,0,95,5,112,1,73,36,
		209,1,48,57,0,48,78,0,95,2,112,0,48,13,
		0,48,78,0,95,2,112,0,112,0,112,1,73,36,
		210,1,48,129,0,95,2,120,112,1,73,25,120,36,
		212,1,95,3,121,5,28,111,176,126,0,92,13,12,
		1,121,35,31,100,36,213,1,48,133,0,95,2,112,
		0,31,88,36,214,1,48,39,0,48,78,0,95,2,
		112,0,176,132,0,48,46,0,48,78,0,95,2,112,
		0,112,0,89,25,0,1,0,1,0,2,0,48,49,
		0,95,1,112,0,48,49,0,95,255,112,0,8,6,
		12,2,112,1,73,36,215,1,48,57,0,48,78,0,
		95,2,112,0,48,13,0,48,78,0,95,2,112,0,
		112,0,112,1,73,36,219,1,48,55,0,48,78,0,
		95,2,112,0,112,0,100,69,28,35,36,220,1,48,
		56,0,48,55,0,48,78,0,95,2,112,0,112,0,
		48,13,0,48,78,0,95,2,112,0,112,0,112,1,
		73,36,222,1,176,134,0,12,0,80,4,36,223,1,
		48,135,0,95,2,112,0,100,69,28,60,95,3,121,
		5,31,24,95,5,176,45,0,48,46,0,48,78,0,
		95,2,112,0,112,0,12,1,5,28,32,36,224,1,
		48,56,0,48,135,0,95,2,112,0,95,2,48,13,
		0,48,78,0,95,2,112,0,112,0,112,2,73,36,
		226,1,95,3,92,13,5,28,30,176,136,0,95,4,
		12,1,28,21,36,227,1,176,122,0,48,34,0,95,
		2,112,0,95,4,100,122,20,4,36,229,1,48,127,
		0,48,34,0,95,2,112,0,9,112,1,73,36,231,
		1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,137,0,2,0,7
	};

	hb_vmExecute( pcode, symbols );
}

