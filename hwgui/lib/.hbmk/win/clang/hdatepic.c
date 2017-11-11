/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( HDATEPICKER );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HDATEPICKER_NEW );
HB_FUNC_STATIC( HDATEPICKER_ACTIVATE );
HB_FUNC_STATIC( HDATEPICKER_INIT );
HB_FUNC_STATIC( HDATEPICKER_ONEVENT );
HB_FUNC_STATIC( HDATEPICKER_REFRESH );
HB_FUNC_STATIC( HDATEPICKER_GETVALUE );
HB_FUNC_STATIC( HDATEPICKER_SETVALUE );
HB_FUNC_STATIC( HDATEPICKER_REDEFINE );
HB_FUNC_STATIC( HDATEPICKER_ONCHANGE );
HB_FUNC_STATIC( HDATEPICKER_WHEN );
HB_FUNC_STATIC( HDATEPICKER_VALID );
HB_FUNC_STATIC( HDATEPICKER_VALUE );
HB_FUNC_STATIC( HDATEPICKER_CHECKVALUE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( CTOD );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_CREATEDATEPICKER );
HB_FUNC_EXTERN( HWG_SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITDATEPICKERPROC );
HB_FUNC_EXTERN( HWG_GETSKIP );
HB_FUNC_EXTERN( HWG_ISCTRLSHIFT );
HB_FUNC_EXTERN( HWG_PROCKEYLIST );
HB_FUNC_EXTERN( HWG_GETDATEPICKER );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_EXTERN( HWG_SETDATEPICKER );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( HWG_GETTIMEPICKER );
HB_FUNC_EXTERN( HWG_SETDATEPICKERNULL );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( TIME );
HB_FUNC_EXTERN( HWG_POSTMESSAGE );
HB_FUNC_EXTERN( HWG_CHECKFOCUS );
HB_FUNC_EXTERN( HWG_GETKEYSTATE );
HB_FUNC_EXTERN( HWG_WHENSETFOCUS );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HDATEPIC )
{ "HDATEPICKER", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER ) }, NULL },
{ "__CLSLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSLOCKDEF ) }, NULL },
{ "NEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBCLASS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBCLASS ) }, NULL },
{ "HCONTROL", { HB_FS_PUBLIC }, { HB_FUNCNAME( HCONTROL ) }, NULL },
{ "ADDMULTICLSDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMULTIDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMETHOD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HDATEPICKER_NEW", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_NEW ) }, NULL },
{ "HDATEPICKER_ACTIVATE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_ACTIVATE ) }, NULL },
{ "HDATEPICKER_INIT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_INIT ) }, NULL },
{ "HDATEPICKER_ONEVENT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_ONEVENT ) }, NULL },
{ "HDATEPICKER_REFRESH", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_REFRESH ) }, NULL },
{ "HDATEPICKER_GETVALUE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_GETVALUE ) }, NULL },
{ "HDATEPICKER_SETVALUE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_SETVALUE ) }, NULL },
{ "HDATEPICKER_REDEFINE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_REDEFINE ) }, NULL },
{ "HDATEPICKER_ONCHANGE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_ONCHANGE ) }, NULL },
{ "HDATEPICKER_WHEN", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_WHEN ) }, NULL },
{ "HDATEPICKER_VALID", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_VALID ) }, NULL },
{ "HDATEPICKER_VALUE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_VALUE ) }, NULL },
{ "HDATEPICKER_CHECKVALUE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HDATEPICKER_CHECKVALUE ) }, NULL },
{ "CREATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__CLSUNLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSUNLOCKDEF ) }, NULL },
{ "INSTANCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__OBJHASMSG", { HB_FS_PUBLIC }, { HB_FUNCNAME( __OBJHASMSG ) }, NULL },
{ "INITCLASS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITOR ) }, NULL },
{ "SUPER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LSHOWTIME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITAND", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITAND ) }, NULL },
{ "_DVALUE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALTYPE", { HB_FS_PUBLIC }, { HB_FUNCNAME( VALTYPE ) }, NULL },
{ "CTOD", { HB_FS_PUBLIC }, { HB_FUNCNAME( CTOD ) }, NULL },
{ "SPACE", { HB_FS_PUBLIC }, { HB_FUNCNAME( SPACE ) }, NULL },
{ "_TVALUE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LSHOWTIME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "DVALUE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TVALUE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BSETGET", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_INITCOMMONCONTROLSEX", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX ) }, NULL },
{ "ACTIVATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDEVENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OPARENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "WHEN", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "FINDCONTROL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LNOVALID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ONCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EMPTY", { HB_FS_PUBLIC }, { HB_FUNCNAME( EMPTY ) }, NULL },
{ "HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CREATEDATEPICKER", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CREATEDATEPICKER ) }, NULL },
{ "ID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "INIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LINIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NHOLDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETWINDOWOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETWINDOWOBJECT ) }, NULL },
{ "HWG_INITDATEPICKERPROC", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INITDATEPICKERPROC ) }, NULL },
{ "REFRESH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BOTHER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EVAL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETSKIP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSKIP ) }, NULL },
{ "HWG_ISCTRLSHIFT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ISCTRLSHIFT ) }, NULL },
{ "HWG_PROCKEYLIST", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_PROCKEYLIST ) }, NULL },
{ "HWG_GETDATEPICKER", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETDATEPICKER ) }, NULL },
{ "HWG_SENDMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SENDMESSAGE ) }, NULL },
{ "HWG_SETDATEPICKER", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETDATEPICKER ) }, NULL },
{ "STRTRAN", { HB_FS_PUBLIC }, { HB_FUNCNAME( STRTRAN ) }, NULL },
{ "SETVALUE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETTIMEPICKER", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETTIMEPICKER ) }, NULL },
{ "HWG_SETDATEPICKERNULL", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETDATEPICKERNULL ) }, NULL },
{ "DATE", { HB_FS_PUBLIC }, { HB_FUNCNAME( DATE ) }, NULL },
{ "BSETGET", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TIME", { HB_FS_PUBLIC }, { HB_FUNCNAME( TIME ) }, NULL },
{ "HWG_POSTMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_POSTMESSAGE ) }, NULL },
{ "SETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LSUSPENDMSGSHANDLING", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CHECKFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CHECKFOCUS ) }, NULL },
{ "BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETKEYSTATE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETKEYSTATE ) }, NULL },
{ "HWG_WHENSETFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_WHENSETFOCUS ) }, NULL },
{ "LNOVALID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "(_INITSTATICS00001)", { HB_FS_INITEXIT | HB_FS_LOCAL }, { hb_INITSTATICS }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HDATEPIC, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HDATEPIC
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HDATEPIC )
   #include "hbiniseg.h"
#endif

HB_FUNC( HDATEPICKER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,93,0,36,29,0,103,1,0,100,8,29,15,3,176,1,
		0,104,1,0,12,1,29,4,3,166,198,2,0,122,80,1,48,2,0,
		176,3,0,12,0,106,12,72,68,97,116,101,80,105,99,107,101,114,0,
		108,4,4,1,0,108,0,112,3,80,2,36,31,0,48,5,0,95,2,
		100,106,18,83,89,83,68,65,84,69,84,73,77,69,80,73,67,75,51,
		50,0,95,1,121,72,121,72,121,72,121,72,106,9,119,105,110,99,108,
		97,115,115,0,4,1,0,9,112,5,73,36,32,0,48,6,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,8,98,83,101,116,71,101,116,
		0,4,1,0,9,112,5,73,36,33,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,7,100,86,97,108,117,101,0,106,7,116,
		86,97,108,117,101,0,4,2,0,9,112,5,73,36,34,0,48,6,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,8,98,67,104,97,110,
		103,101,0,4,1,0,9,112,5,73,36,35,0,48,6,0,95,2,100,
		120,95,1,121,72,121,72,121,72,106,10,108,83,104,111,119,84,105,109,
		101,0,4,1,0,9,112,5,73,36,38,0,48,7,0,95,2,106,4,
		78,101,119,0,108,8,95,1,121,72,121,72,121,72,112,3,73,36,39,
		0,48,7,0,95,2,106,9,65,99,116,105,118,97,116,101,0,108,9,
		95,1,121,72,121,72,121,72,112,3,73,36,40,0,48,7,0,95,2,
		106,5,73,110,105,116,0,108,10,95,1,121,72,121,72,121,72,112,3,
		73,36,41,0,48,7,0,95,2,106,8,79,110,69,118,101,110,116,0,
		108,11,95,1,121,72,121,72,121,72,112,3,73,36,42,0,48,7,0,
		95,2,106,8,82,101,102,114,101,115,104,0,108,12,95,1,121,72,121,
		72,121,72,112,3,73,36,43,0,48,7,0,95,2,106,9,71,101,116,
		86,97,108,117,101,0,108,13,95,1,121,72,121,72,121,72,112,3,73,
		36,44,0,48,7,0,95,2,106,9,83,101,116,86,97,108,117,101,0,
		108,14,95,1,121,72,121,72,121,72,112,3,73,36,46,0,48,7,0,
		95,2,106,9,82,101,100,101,102,105,110,101,0,108,15,95,1,121,72,
		121,72,121,72,112,3,73,36,47,0,48,7,0,95,2,106,9,111,110,
		67,104,97,110,103,101,0,108,16,95,1,121,72,121,72,121,72,112,3,
		73,36,48,0,48,7,0,95,2,106,5,87,104,101,110,0,108,17,95,
		1,121,72,121,72,121,72,112,3,73,36,49,0,48,7,0,95,2,106,
		6,86,97,108,105,100,0,108,18,95,1,121,72,121,72,121,72,112,3,
		73,36,50,0,48,7,0,95,2,106,6,86,97,108,117,101,0,108,19,
		95,1,121,72,121,72,112,3,73,48,7,0,95,2,106,7,95,86,97,
		108,117,101,0,108,19,95,1,121,72,121,72,121,72,112,3,73,36,51,
		0,48,7,0,95,2,106,11,67,104,101,99,107,118,97,108,117,101,0,
		108,20,95,1,121,72,121,72,112,3,73,48,7,0,95,2,106,12,95,
		67,104,101,99,107,118,97,108,117,101,0,108,20,95,1,121,72,121,72,
		121,72,112,3,73,36,53,0,48,21,0,95,2,112,0,73,167,14,0,
		0,176,22,0,104,1,0,95,2,20,2,168,48,23,0,95,2,112,0,
		80,3,176,24,0,95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,25,0,95,3,164,146,1,0,73,95,3,110,7,48,
		23,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,18,36,56,0,102,80,19,36,59,0,176,26,0,95,5,100,8,
		28,5,121,25,4,95,5,95,4,100,69,28,9,97,0,0,1,0,25,
		3,121,95,18,100,8,31,6,95,18,31,5,121,25,4,92,9,72,12,
		2,80,5,36,61,0,48,2,0,48,27,0,95,19,112,0,95,1,95,
		2,95,5,95,6,95,7,95,8,95,9,95,10,95,11,100,100,95,15,
		95,16,95,17,112,14,73,36,63,0,48,28,0,95,19,176,29,0,95,
		5,92,9,12,2,121,15,112,1,73,36,64,0,48,30,0,95,19,95,
		3,100,8,31,16,176,31,0,95,3,12,1,106,2,68,0,69,28,16,
		176,32,0,176,33,0,92,8,12,1,12,1,25,4,95,3,112,1,73,
		36,65,0,48,34,0,95,19,95,3,100,8,31,16,176,31,0,95,3,
		12,1,106,2,67,0,69,28,11,176,33,0,92,6,12,1,25,4,95,
		3,112,1,73,36,66,0,48,35,0,95,19,48,36,0,95,19,112,0,
		31,11,48,37,0,95,19,112,0,25,9,48,38,0,95,19,112,0,112,
		1,73,36,68,0,48,39,0,95,19,95,4,112,1,73,36,69,0,48,
		40,0,95,19,95,14,112,1,73,36,71,0,176,41,0,20,0,36,72,
		0,48,42,0,95,19,112,0,73,36,74,0,95,4,100,69,29,152,0,
		36,75,0,48,43,0,95,19,95,12,112,1,73,36,76,0,48,44,0,
		95,19,95,13,112,1,73,36,77,0,48,45,0,48,46,0,95,19,112,
		0,92,249,95,19,89,26,0,2,0,1,0,19,0,48,47,0,95,255,
		48,48,0,95,1,95,2,112,1,112,1,6,120,106,11,111,110,71,111,
		116,70,111,99,117,115,0,112,5,73,36,78,0,48,45,0,48,46,0,
		95,19,112,0,92,248,95,19,89,26,0,2,0,1,0,19,0,48,49,
		0,95,255,48,48,0,95,1,95,2,112,1,112,1,6,120,106,12,111,
		110,76,111,115,116,70,111,99,117,115,0,112,5,73,25,105,36,80,0,
		95,12,100,69,28,50,36,81,0,48,50,0,95,19,120,112,1,73,36,
		82,0,48,45,0,48,46,0,95,19,112,0,92,249,95,19,95,12,120,
		106,11,111,110,71,111,116,70,111,99,117,115,0,112,5,73,36,84,0,
		95,13,100,69,28,39,36,85,0,48,45,0,48,46,0,95,19,112,0,
		92,248,95,19,95,13,120,106,12,111,110,76,111,115,116,70,111,99,117,
		115,0,112,5,73,36,88,0,48,45,0,48,46,0,95,19,112,0,93,
		9,253,95,19,89,20,0,0,0,1,0,19,0,48,51,0,95,255,93,
		9,253,112,1,6,120,106,9,111,110,67,104,97,110,103,101,0,112,5,
		73,36,89,0,48,45,0,48,46,0,95,19,112,0,93,15,253,95,19,
		89,20,0,0,0,1,0,19,0,48,51,0,95,255,93,15,253,112,1,
		6,120,106,8,111,110,67,108,111,115,101,0,112,5,73,36,91,0,95,
		19,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,14,36,94,0,102,80,15,36,96,0,48,2,0,48,27,0,95,
		15,112,0,95,1,95,2,121,121,121,121,121,95,5,95,7,95,6,100,
		95,11,95,12,95,13,112,14,73,36,98,0,176,41,0,20,0,36,99,
		0,48,30,0,95,15,95,3,100,8,31,16,176,31,0,95,3,12,1,
		106,2,68,0,69,28,16,176,32,0,176,33,0,92,8,12,1,12,1,
		25,4,95,3,112,1,73,36,100,0,48,34,0,95,15,95,3,100,8,
		31,16,176,31,0,95,3,12,1,106,2,67,0,69,28,11,176,33,0,
		92,6,12,1,25,4,95,3,112,1,73,36,101,0,48,39,0,95,15,
		95,4,112,1,73,36,102,0,48,40,0,95,15,95,10,112,1,73,36,
		103,0,48,28,0,95,15,95,14,112,1,73,36,104,0,95,8,100,69,
		28,38,36,105,0,48,45,0,48,46,0,95,15,112,0,92,249,95,15,
		95,8,120,106,11,111,110,71,111,116,70,111,99,117,115,0,112,5,73,
		36,107,0,48,45,0,48,46,0,95,15,112,0,93,9,253,95,15,89,
		20,0,0,0,1,0,15,0,48,51,0,95,255,93,9,253,112,1,6,
		120,106,9,111,110,67,104,97,110,103,101,0,112,5,73,36,108,0,48,
		45,0,48,46,0,95,15,112,0,93,15,253,95,15,89,20,0,0,0,
		1,0,15,0,48,51,0,95,255,93,15,253,112,1,6,120,106,8,111,
		110,67,108,111,115,101,0,112,5,73,36,109,0,95,4,100,69,28,78,
		36,110,0,48,44,0,95,15,95,9,112,1,73,36,111,0,48,45,0,
		48,46,0,95,15,112,0,92,248,95,15,89,26,0,2,0,1,0,15,
		0,48,49,0,95,255,48,48,0,95,1,95,2,112,1,112,1,6,120,
		106,12,111,110,76,111,115,116,70,111,99,117,115,0,112,5,73,25,48,
		36,113,0,95,9,100,69,28,39,36,114,0,48,45,0,48,46,0,95,
		15,112,0,92,248,95,15,95,9,120,106,12,111,110,76,111,115,116,70,
		111,99,117,115,0,112,5,73,36,118,0,95,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,121,0,176,52,0,48,53,0,48,46,0,102,112,0,112,0,12,1,
		31,74,36,123,0,48,54,0,102,176,55,0,48,53,0,48,46,0,102,
		112,0,112,0,48,56,0,102,112,0,48,57,0,102,112,0,48,58,0,
		102,112,0,48,59,0,102,112,0,48,60,0,102,112,0,48,61,0,102,
		112,0,12,7,112,1,73,36,124,0,48,62,0,102,112,0,73,36,127,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,130,0,48,63,0,102,112,0,31,67,36,132,0,48,64,0,102,122,
		112,1,73,36,133,0,176,65,0,48,53,0,102,112,0,102,20,2,36,
		134,0,176,66,0,48,53,0,102,112,0,20,1,36,135,0,48,67,0,
		102,112,0,73,36,136,0,48,62,0,48,27,0,102,112,0,112,0,73,
		36,140,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,144,0,48,68,0,102,112,0,100,69,28,34,36,145,0,
		48,69,0,48,68,0,102,112,0,102,95,1,95,2,95,3,112,4,92,
		255,69,28,8,36,146,0,121,110,7,36,149,0,95,1,93,2,1,8,
		28,91,36,150,0,95,2,92,9,5,28,43,36,151,0,176,70,0,48,
		46,0,102,112,0,48,53,0,102,112,0,100,176,71,0,9,120,12,2,
		28,6,92,255,25,3,122,20,4,36,152,0,121,110,7,36,153,0,95,
		2,92,13,8,28,95,36,154,0,176,70,0,48,46,0,102,112,0,48,
		53,0,102,112,0,100,122,20,4,36,155,0,121,110,7,36,157,0,95,
		1,93,0,1,5,28,21,36,158,0,176,72,0,102,95,2,12,2,28,
		43,36,159,0,121,110,7,36,161,0,95,1,93,135,0,5,28,26,36,
		162,0,95,2,92,13,5,31,9,95,2,92,9,5,28,9,36,163,0,
		92,4,110,7,36,168,0,92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_CHECKVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,172,0,176,29,0,48,61,0,102,112,0,92,2,12,2,
		121,5,28,8,36,173,0,9,110,7,36,175,0,95,1,100,69,28,96,
		36,176,0,176,73,0,48,53,0,102,112,0,122,12,2,122,5,28,5,
		9,25,3,120,95,1,69,28,68,36,177,0,95,1,31,23,36,178,0,
		176,74,0,48,53,0,102,112,0,93,2,16,122,121,20,4,25,40,36,
		180,0,176,75,0,48,53,0,102,112,0,48,37,0,102,112,0,176,76,
		0,48,38,0,102,112,0,106,2,58,0,106,1,0,12,3,20,3,36,
		184,0,176,73,0,48,53,0,102,112,0,122,12,2,122,5,28,5,9,
		25,3,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_VALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,188,0,95,1,100,69,28,14,36,189,0,48,77,0,102,
		95,1,112,1,73,36,192,0,48,36,0,102,112,0,28,10,48,38,0,
		102,112,0,25,8,48,37,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_GETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		36,196,0,48,36,0,102,112,0,31,15,176,73,0,48,53,0,102,112,
		0,12,1,25,13,176,78,0,48,53,0,102,112,0,12,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_SETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,200,0,176,52,0,95,1,12,1,28,18,36,201,0,176,
		79,0,48,53,0,102,112,0,20,1,25,82,36,202,0,48,36,0,102,
		112,0,28,37,36,203,0,176,75,0,48,53,0,102,112,0,176,80,0,
		12,0,176,76,0,95,1,106,2,58,0,106,1,0,12,3,20,3,25,
		36,36,205,0,176,75,0,48,53,0,102,112,0,95,1,176,76,0,48,
		38,0,102,112,0,106,2,58,0,106,1,0,12,3,20,3,36,207,0,
		48,30,0,102,176,73,0,48,53,0,102,112,0,12,1,112,1,73,36,
		208,0,48,34,0,102,176,78,0,48,53,0,102,112,0,12,1,112,1,
		73,36,209,0,48,35,0,102,48,36,0,102,112,0,28,10,48,38,0,
		102,112,0,25,8,48,37,0,102,112,0,112,1,73,36,210,0,48,81,
		0,102,112,0,100,69,28,40,36,211,0,48,69,0,48,81,0,102,112,
		0,48,36,0,102,112,0,28,10,48,38,0,102,112,0,25,8,48,37,
		0,102,112,0,102,112,2,73,36,214,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_REFRESH )
{
	static const HB_BYTE pcode[] =
	{
		36,218,0,48,81,0,102,112,0,100,69,28,61,36,219,0,48,36,0,
		102,112,0,31,27,36,220,0,48,30,0,102,48,69,0,48,81,0,102,
		112,0,100,102,112,2,112,1,73,25,25,36,222,0,48,34,0,102,48,
		69,0,48,81,0,102,112,0,100,102,112,2,112,1,73,36,225,0,176,
		52,0,48,37,0,102,112,0,12,1,28,48,48,36,0,102,112,0,31,
		40,36,227,0,176,75,0,48,53,0,102,112,0,176,80,0,12,0,176,
		76,0,176,82,0,12,0,106,2,58,0,106,1,0,12,3,20,3,25,
		34,36,229,0,48,77,0,102,48,36,0,102,112,0,31,10,48,37,0,
		102,112,0,25,8,48,38,0,102,112,0,112,1,73,36,232,0,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_ONCHANGE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,239,0,95,1,93,9,253,8,28,22,176,74,0,48,53,
		0,102,112,0,93,8,16,121,121,12,4,121,8,31,11,95,1,93,15,
		253,8,29,220,0,36,240,0,95,1,93,15,253,5,28,32,36,241,0,
		176,83,0,48,53,0,102,112,0,93,0,1,92,39,121,20,4,36,242,
		0,48,84,0,102,112,0,73,36,244,0,48,30,0,102,176,73,0,48,
		53,0,102,112,0,12,1,112,1,73,36,245,0,48,34,0,102,176,78,
		0,48,53,0,102,112,0,12,1,112,1,73,36,246,0,48,81,0,102,
		112,0,100,69,28,40,36,247,0,48,69,0,48,81,0,102,112,0,48,
		36,0,102,112,0,28,10,48,38,0,102,112,0,25,8,48,37,0,102,
		112,0,102,112,2,73,36,249,0,48,85,0,102,112,0,100,69,28,72,
		36,250,0,48,86,0,48,46,0,102,112,0,120,112,1,73,36,251,0,
		48,69,0,48,85,0,102,112,0,48,36,0,102,112,0,28,10,48,38,
		0,102,112,0,25,8,48,37,0,102,112,0,102,112,2,73,36,252,0,
		48,86,0,48,46,0,102,112,0,9,112,1,73,36,0,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_WHEN )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,3,1,120,80,1,36,5,1,176,87,0,102,9,12,2,
		31,8,36,6,1,120,110,7,36,8,1,48,88,0,102,112,0,100,69,
		29,204,0,36,9,1,176,89,0,92,38,12,1,121,35,31,24,176,89,
		0,92,9,12,1,121,35,28,17,176,89,0,92,16,12,1,121,35,28,
		6,92,255,25,3,122,80,2,36,10,1,48,86,0,48,46,0,102,112,
		0,120,112,1,73,36,11,1,48,50,0,102,120,112,1,73,36,12,1,
		48,69,0,48,88,0,102,112,0,48,36,0,102,112,0,28,10,48,38,
		0,102,112,0,25,8,48,37,0,102,112,0,102,112,2,80,1,36,13,
		1,48,50,0,102,95,1,68,112,1,73,36,14,1,48,86,0,48,46,
		0,102,112,0,9,112,1,73,36,15,1,176,31,0,95,1,12,1,106,
		2,76,0,5,28,38,95,1,31,34,36,16,1,176,90,0,102,95,2,
		20,2,36,17,1,176,74,0,48,53,0,102,112,0,93,13,16,121,121,
		20,4,25,12,36,19,1,48,84,0,102,112,0,73,36,23,1,95,1,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HDATEPICKER_VALID )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,26,1,120,80,1,36,28,1,176,87,0,102,120,12,2,
		28,10,48,91,0,102,112,0,28,8,36,29,1,120,110,7,36,31,1,
		48,30,0,102,176,73,0,48,53,0,102,112,0,12,1,112,1,73,36,
		32,1,48,81,0,102,112,0,100,69,28,40,36,33,1,48,69,0,48,
		81,0,102,112,0,48,36,0,102,112,0,28,10,48,38,0,102,112,0,
		25,8,48,37,0,102,112,0,102,112,2,73,36,35,1,48,92,0,102,
		112,0,100,69,29,136,0,36,36,1,48,86,0,48,46,0,102,112,0,
		120,112,1,73,36,37,1,48,69,0,48,92,0,102,112,0,48,36,0,
		102,112,0,28,10,48,38,0,102,112,0,25,8,48,37,0,102,112,0,
		102,112,2,80,1,36,38,1,176,31,0,95,1,12,1,106,2,76,0,
		8,28,6,95,1,25,3,120,80,1,36,39,1,48,86,0,48,46,0,
		102,112,0,9,112,1,73,36,40,1,95,1,31,33,36,41,1,176,83,
		0,48,53,0,102,112,0,93,0,1,92,39,121,20,4,36,42,1,48,
		84,0,102,120,112,1,73,36,46,1,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,93,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}
