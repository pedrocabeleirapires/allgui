/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( HRICHEDIT );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HRICHEDIT_NEW );
HB_FUNC_STATIC( HRICHEDIT_ACTIVATE );
HB_FUNC_STATIC( HRICHEDIT_ONEVENT );
HB_FUNC_STATIC( HRICHEDIT_INIT );
HB_FUNC_STATIC( HRICHEDIT_ONGOTFOCUS );
HB_FUNC_STATIC( HRICHEDIT_ONLOSTFOCUS );
HB_FUNC_STATIC( HRICHEDIT_WHEN );
HB_FUNC_STATIC( HRICHEDIT_VALID );
HB_FUNC_STATIC( HRICHEDIT_UPDATEPOS );
HB_FUNC_STATIC( HRICHEDIT_ONCHANGE );
HB_FUNC_STATIC( HRICHEDIT_READONLY );
HB_FUNC_STATIC( HRICHEDIT_SETCOLOR );
HB_FUNC_STATIC( HRICHEDIT_SAVEFILE );
HB_FUNC_STATIC( HRICHEDIT_OPENFILE );
HB_FUNC_STATIC( HRICHEDIT_PRINT );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( HWG_GETSYSCOLOR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HWG_BITAND );
HB_FUNC_EXTERN( HWG_INITRICHEDIT );
HB_FUNC_EXTERN( HWG_CREATERICHEDIT );
HB_FUNC_EXTERN( HWG_SETWINDOWOBJECT );
HB_FUNC_EXTERN( HWG_INITRICHPROC );
HB_FUNC_EXTERN( HWG_SENDMESSAGE );
HB_FUNC_EXTERN( HWG_GETPARENTFORM );
HB_FUNC_EXTERN( HWG_POSTMESSAGE );
HB_FUNC_EXTERN( HWG_ISCTRLSHIFT );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( HWG_GETSKIP );
HB_FUNC_EXTERN( HWG_RE_INSERTTEXT );
HB_FUNC_EXTERN( HWG_GETPARENT );
HB_FUNC_EXTERN( HWG_HIWORD );
HB_FUNC_EXTERN( HWG_RE_SETDEFAULT );
HB_FUNC_EXTERN( HWG_LOWORD );
HB_FUNC_EXTERN( HWG_RE_GETTEXTRANGE );
HB_FUNC_EXTERN( HWG_CHECKFOCUS );
HB_FUNC_EXTERN( HWG_SAVERICHEDIT );
HB_FUNC_EXTERN( HWG_LOADRICHEDIT );
HB_FUNC_EXTERN( HWG_STARTDOC );
HB_FUNC_EXTERN( HWG_PRINTRTF );
HB_FUNC_EXTERN( HWG_ENDDOC );
HB_FUNC_EXTERN( HWG_ABORTDOC );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HRICHED )
{ "HRICHEDIT", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT ) }, NULL },
{ "__CLSLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSLOCKDEF ) }, NULL },
{ "NEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBCLASS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBCLASS ) }, NULL },
{ "HCONTROL", { HB_FS_PUBLIC }, { HB_FUNCNAME( HCONTROL ) }, NULL },
{ "ADDMULTICLSDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMULTIDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMETHOD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HRICHEDIT_NEW", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_NEW ) }, NULL },
{ "HRICHEDIT_ACTIVATE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_ACTIVATE ) }, NULL },
{ "HRICHEDIT_ONEVENT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_ONEVENT ) }, NULL },
{ "HRICHEDIT_INIT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_INIT ) }, NULL },
{ "HRICHEDIT_ONGOTFOCUS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_ONGOTFOCUS ) }, NULL },
{ "HRICHEDIT_ONLOSTFOCUS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_ONLOSTFOCUS ) }, NULL },
{ "HRICHEDIT_WHEN", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_WHEN ) }, NULL },
{ "HRICHEDIT_VALID", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_VALID ) }, NULL },
{ "HRICHEDIT_UPDATEPOS", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_UPDATEPOS ) }, NULL },
{ "HRICHEDIT_ONCHANGE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_ONCHANGE ) }, NULL },
{ "HRICHEDIT_READONLY", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_READONLY ) }, NULL },
{ "HRICHEDIT_SETCOLOR", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_SETCOLOR ) }, NULL },
{ "HRICHEDIT_SAVEFILE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_SAVEFILE ) }, NULL },
{ "HRICHEDIT_OPENFILE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_OPENFILE ) }, NULL },
{ "HRICHEDIT_PRINT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HRICHEDIT_PRINT ) }, NULL },
{ "CREATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__CLSUNLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSUNLOCKDEF ) }, NULL },
{ "INSTANCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__OBJHASMSG", { HB_FS_PUBLIC }, { HB_FUNCNAME( __OBJHASMSG ) }, NULL },
{ "INITCLASS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITOR ) }, NULL },
{ "SUPER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETSYSCOLOR", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSYSCOLOR ) }, NULL },
{ "_TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BOTHER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LALLOWTABS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EMPTY", { HB_FS_PUBLIC }, { HB_FUNCNAME( EMPTY ) }, NULL },
{ "LALLOWTABS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LREADONLY", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_BITAND", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_BITAND ) }, NULL },
{ "HWG_INITRICHEDIT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INITRICHEDIT ) }, NULL },
{ "ACTIVATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDEVENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OPARENT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "WHEN", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_HANDLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CREATERICHEDIT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CREATERICHEDIT ) }, NULL },
{ "ID", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STYLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TITLE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "INIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LINIT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NHOLDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SETWINDOWOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SETWINDOWOBJECT ) }, NULL },
{ "HWG_INITRICHPROC", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_INITRICHPROC ) }, NULL },
{ "SETCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BCOLOR", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SENDMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SENDMESSAGE ) }, NULL },
{ "ONCHANGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "UPDATEPOS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "TYPE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_GETPARENTFORM", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETPARENTFORM ) }, NULL },
{ "SETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LSETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LSETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_POSTMESSAGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_POSTMESSAGE ) }, NULL },
{ "_LCTRLTAB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LDISABLECTRLTAB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LDISABLECTRLTAB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LCTRLTAB", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LCHANGED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_ISCTRLSHIFT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ISCTRLSHIFT ) }, NULL },
{ "BOTHER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EVAL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "VALTYPE", { HB_FS_PUBLIC }, { HB_FUNCNAME( VALTYPE ) }, NULL },
{ "HWG_GETSKIP", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETSKIP ) }, NULL },
{ "HWG_RE_INSERTTEXT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_RE_INSERTTEXT ) }, NULL },
{ "HWG_GETPARENT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_GETPARENT ) }, NULL },
{ "HWG_HIWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_HIWORD ) }, NULL },
{ "END", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_RE_SETDEFAULT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_RE_SETDEFAULT ) }, NULL },
{ "LREADONLY", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_LOWORD", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_LOWORD ) }, NULL },
{ "_LINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LINESTOTAL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_SELTEXT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_RE_GETTEXTRANGE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_RE_GETTEXTRANGE ) }, NULL },
{ "_SELSTART", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_SELLENGTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_COL", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LSUSPENDMSGSHANDLING", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "GETTEXT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_CHECKFOCUS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_CHECKFOCUS ) }, NULL },
{ "BGETFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "BLOSTFOCUS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_SAVERICHEDIT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_SAVERICHEDIT ) }, NULL },
{ "HWG_LOADRICHEDIT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_LOADRICHEDIT ) }, NULL },
{ "HDCPRINTER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWG_STARTDOC", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_STARTDOC ) }, NULL },
{ "HWG_PRINTRTF", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_PRINTRTF ) }, NULL },
{ "HWG_ENDDOC", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ENDDOC ) }, NULL },
{ "HWG_ABORTDOC", { HB_FS_PUBLIC }, { HB_FUNCNAME( HWG_ABORTDOC ) }, NULL },
{ "(_INITSTATICS00001)", { HB_FS_INITEXIT | HB_FS_LOCAL }, { hb_INITSTATICS }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HRICHED, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HRICHED
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HRICHED )
   #include "hbiniseg.h"
#endif

HB_FUNC( HRICHEDIT )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,111,0,36,15,0,103,1,0,100,8,29,103,4,176,1,
		0,104,1,0,12,1,29,92,4,166,30,4,0,122,80,1,48,2,0,
		176,3,0,12,0,106,10,72,82,105,99,104,69,100,105,116,0,108,4,
		4,1,0,108,0,112,3,80,2,36,20,0,48,5,0,95,2,100,106,
		12,82,105,99,104,69,100,105,116,50,48,65,0,95,1,121,72,121,72,
		121,72,121,72,106,9,119,105,110,99,108,97,115,115,0,4,1,0,9,
		112,5,73,36,22,0,48,6,0,95,2,100,9,95,1,121,72,121,72,
		121,72,106,9,108,67,104,97,110,103,101,100,0,4,1,0,9,112,5,
		73,36,23,0,48,6,0,95,2,100,120,95,1,121,72,121,72,121,72,
		106,10,108,83,101,116,70,111,99,117,115,0,4,1,0,9,112,5,73,
		36,24,0,48,6,0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		11,108,65,108,108,111,119,84,97,98,115,0,4,1,0,9,112,5,73,
		36,25,0,48,6,0,95,2,100,100,92,4,106,9,108,99,116,114,108,
		116,97,98,0,4,1,0,9,112,5,73,36,26,0,48,6,0,95,2,
		100,9,95,1,121,72,121,72,121,72,106,10,108,82,101,97,100,79,110,
		108,121,0,4,1,0,9,112,5,73,36,27,0,48,6,0,95,2,100,
		121,95,1,121,72,121,72,121,72,106,4,67,111,108,0,4,1,0,9,
		112,5,73,36,28,0,48,6,0,95,2,100,121,95,1,121,72,121,72,
		121,72,106,5,76,105,110,101,0,4,1,0,9,112,5,73,36,29,0,
		48,6,0,95,2,100,121,95,1,121,72,121,72,121,72,106,11,76,105,
		110,101,115,84,111,116,97,108,0,4,1,0,9,112,5,73,36,30,0,
		48,6,0,95,2,100,121,95,1,121,72,121,72,121,72,106,9,83,101,
		108,83,116,97,114,116,0,4,1,0,9,112,5,73,36,31,0,48,6,
		0,95,2,100,121,95,1,121,72,121,72,121,72,106,8,83,101,108,84,
		101,120,116,0,4,1,0,9,112,5,73,36,32,0,48,6,0,95,2,
		100,121,95,1,121,72,121,72,121,72,106,10,83,101,108,76,101,110,103,
		116,104,0,4,1,0,9,112,5,73,36,34,0,48,6,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,11,104,100,99,80,114,105,110,116,
		101,114,0,4,1,0,9,112,5,73,36,36,0,48,6,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,8,98,67,104,97,110,103,101,0,
		4,1,0,9,112,5,73,36,40,0,48,7,0,95,2,106,4,78,101,
		119,0,108,8,95,1,121,72,121,72,121,72,112,3,73,36,41,0,48,
		7,0,95,2,106,9,65,99,116,105,118,97,116,101,0,108,9,95,1,
		121,72,121,72,121,72,112,3,73,36,42,0,48,7,0,95,2,106,8,
		111,110,69,118,101,110,116,0,108,10,95,1,121,72,121,72,121,72,112,
		3,73,36,43,0,48,7,0,95,2,106,5,73,110,105,116,0,108,11,
		95,1,121,72,121,72,121,72,112,3,73,36,44,0,48,7,0,95,2,
		106,11,111,110,71,111,116,70,111,99,117,115,0,108,12,95,1,121,72,
		121,72,121,72,112,3,73,36,45,0,48,7,0,95,2,106,12,111,110,
		76,111,115,116,70,111,99,117,115,0,108,13,95,1,121,72,121,72,121,
		72,112,3,73,36,46,0,48,7,0,95,2,106,5,87,104,101,110,0,
		108,14,95,1,121,72,121,72,121,72,112,3,73,36,47,0,48,7,0,
		95,2,106,6,86,97,108,105,100,0,108,15,95,1,121,72,121,72,121,
		72,112,3,73,36,48,0,48,7,0,95,2,106,10,85,112,100,97,116,
		101,80,111,115,0,108,16,95,1,121,72,121,72,121,72,112,3,73,36,
		49,0,48,7,0,95,2,106,9,111,110,67,104,97,110,103,101,0,108,
		17,95,1,121,72,121,72,121,72,112,3,73,36,50,0,48,7,0,95,
		2,106,9,82,101,97,100,79,110,108,121,0,108,18,95,1,121,72,121,
		72,112,3,73,48,7,0,95,2,106,10,95,82,101,97,100,79,110,108,
		121,0,108,18,95,1,121,72,121,72,121,72,112,3,73,36,51,0,48,
		7,0,95,2,106,9,83,101,116,67,111,108,111,114,0,108,19,95,1,
		121,72,121,72,121,72,112,3,73,36,52,0,48,7,0,95,2,106,9,
		83,97,118,101,102,105,108,101,0,108,20,95,1,121,72,121,72,121,72,
		112,3,73,36,53,0,48,7,0,95,2,106,9,79,112,101,110,70,105,
		108,101,0,108,21,95,1,121,72,121,72,121,72,112,3,73,36,54,0,
		48,7,0,95,2,106,6,80,114,105,110,116,0,108,22,95,1,121,72,
		121,72,121,72,112,3,73,36,56,0,48,23,0,95,2,112,0,73,167,
		14,0,0,176,24,0,104,1,0,95,2,20,2,168,48,25,0,95,2,
		112,0,80,3,176,26,0,95,3,106,10,73,110,105,116,67,108,97,115,
		115,0,12,2,28,12,48,27,0,95,3,164,146,1,0,73,95,3,110,
		7,48,25,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,21,36,60,0,102,80,22,36,63,0,176,28,0,95,4,100,8,
		28,5,121,25,4,95,4,97,0,0,1,80,95,21,100,5,31,6,95,
		21,31,9,97,0,0,128,0,25,3,121,72,12,2,80,4,36,65,0,
		48,2,0,48,29,0,95,22,112,0,95,1,95,2,95,4,95,5,95,
		6,95,7,95,8,95,9,95,10,95,11,95,12,95,15,95,16,95,17,
		100,8,28,11,176,30,0,92,20,12,1,25,4,95,17,112,14,73,36,
		67,0,48,31,0,95,22,95,3,112,1,73,36,68,0,48,32,0,95,
		22,95,18,112,1,73,36,69,0,48,33,0,95,22,95,20,112,1,73,
		36,70,0,48,34,0,95,22,176,35,0,95,19,12,1,28,11,48,36,
		0,95,22,112,0,25,4,95,19,112,1,73,36,71,0,48,37,0,95,
		22,176,38,0,95,4,93,0,8,12,2,121,69,112,1,73,36,73,0,
		176,39,0,20,0,36,75,0,48,40,0,95,22,112,0,73,36,77,0,
		95,13,100,69,28,69,36,79,0,48,41,0,95,22,95,13,112,1,73,
		36,80,0,48,42,0,48,43,0,95,22,112,0,93,0,1,95,22,89,
		19,0,1,0,1,0,22,0,48,44,0,95,255,95,1,112,1,6,100,
		106,11,111,110,71,111,116,70,111,99,117,115,0,112,5,73,36,82,0,
		95,14,100,69,28,70,36,84,0,48,45,0,95,22,95,14,112,1,73,
		36,85,0,48,42,0,48,43,0,95,22,112,0,93,0,2,95,22,89,
		19,0,1,0,1,0,22,0,48,46,0,95,255,95,1,112,1,6,100,
		106,12,111,110,76,111,115,116,70,111,99,117,115,0,112,5,73,36,88,
		0,95,22,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,91,0,176,35,0,48,47,0,48,43,0,102,112,0,112,0,12,1,
		31,80,36,93,0,48,48,0,102,176,49,0,48,47,0,48,43,0,102,
		112,0,112,0,48,50,0,102,112,0,48,51,0,102,112,0,48,52,0,
		102,112,0,48,53,0,102,112,0,48,54,0,102,112,0,48,55,0,102,
		112,0,48,56,0,102,112,0,12,8,112,1,73,36,94,0,48,57,0,
		102,112,0,73,36,96,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_INIT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,98,0,102,80,1,36,99,0,48,58,0,95,1,112,0,
		32,169,0,36,100,0,48,59,0,95,1,122,112,1,73,36,101,0,176,
		60,0,48,47,0,95,1,112,0,95,1,20,2,36,102,0,176,61,0,
		48,47,0,95,1,112,0,20,1,36,103,0,48,57,0,48,29,0,95,
		1,112,0,112,0,73,36,104,0,48,62,0,95,1,48,63,0,95,1,
		112,0,48,64,0,95,1,112,0,112,2,73,36,105,0,48,65,0,95,
		1,112,0,100,69,28,69,36,106,0,176,66,0,48,47,0,95,1,112,
		0,93,69,4,121,97,1,0,8,0,20,4,36,107,0,48,42,0,48,
		43,0,95,1,112,0,93,0,3,48,50,0,95,1,112,0,89,17,0,
		0,0,1,0,1,0,48,67,0,95,255,112,0,6,112,3,73,36,110,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_ONEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,2,3,36,116,0,95,1,93,1,1,5,31,18,95,1,93,1,2,
		8,31,10,95,1,93,2,2,8,28,14,36,117,0,48,68,0,102,112,
		0,73,25,38,36,118,0,95,1,92,33,8,28,28,48,69,0,176,70,
		0,102,12,1,112,0,92,10,35,28,12,36,119,0,48,71,0,102,112,
		0,73,36,123,0,95,1,93,176,0,5,31,65,95,1,93,201,0,5,
		31,57,95,1,93,187,0,5,31,49,95,1,93,186,0,5,31,41,95,
		1,93,177,0,5,31,33,95,1,93,68,4,5,31,25,95,1,93,63,
		4,5,31,17,95,1,92,14,5,31,10,95,1,93,206,0,5,28,9,
		36,124,0,92,255,110,7,36,126,0,95,1,92,7,5,28,43,48,72,
		0,102,112,0,28,35,36,127,0,48,73,0,102,9,112,1,73,36,128,
		0,176,74,0,48,47,0,102,112,0,93,177,0,121,121,20,4,26,136,
		0,36,129,0,95,1,92,7,5,28,70,48,36,0,102,112,0,28,62,
		48,69,0,176,70,0,102,12,1,112,0,92,10,35,28,46,36,130,0,
		48,75,0,102,48,76,0,176,70,0,102,12,1,112,0,112,1,73,36,
		131,0,48,77,0,176,70,0,102,12,1,48,36,0,102,112,0,112,1,
		73,25,57,36,132,0,95,1,92,8,5,28,47,48,36,0,102,112,0,
		28,39,48,69,0,176,70,0,102,12,1,112,0,92,10,35,28,23,36,
		133,0,48,77,0,176,70,0,102,12,1,48,78,0,102,112,0,112,1,
		73,36,135,0,95,1,93,0,1,8,28,27,95,2,92,46,5,31,9,
		95,2,92,8,5,28,13,36,136,0,48,79,0,102,120,112,1,73,36,
		138,0,95,1,93,2,1,8,28,79,36,139,0,95,2,92,9,5,28,
		44,48,69,0,176,70,0,102,12,1,112,0,92,10,35,28,28,36,140,
		0,176,80,0,120,9,12,2,31,10,48,36,0,102,112,0,31,8,36,
		141,0,121,110,7,36,144,0,176,80,0,120,9,12,2,31,82,36,145,
		0,48,79,0,102,120,112,1,73,25,69,36,147,0,48,81,0,102,112,
		0,100,69,28,56,36,148,0,48,82,0,48,81,0,102,112,0,102,95,
		1,95,2,95,3,112,4,80,5,36,149,0,176,83,0,95,5,12,1,
		106,2,78,0,69,31,9,95,5,92,255,15,28,9,36,150,0,95,5,
		110,7,36,153,0,95,1,93,1,1,8,28,84,36,154,0,95,2,92,
		9,5,29,111,1,48,69,0,176,70,0,102,12,1,112,0,92,10,35,
		29,94,1,36,155,0,176,80,0,120,9,12,2,29,81,1,36,157,0,
		176,84,0,48,43,0,102,112,0,48,47,0,102,112,0,100,176,80,0,
		9,120,12,2,28,6,92,255,25,3,122,20,4,36,158,0,121,110,7,
		36,161,0,95,1,93,0,1,8,29,186,0,36,162,0,95,2,92,9,
		5,28,60,176,80,0,120,9,12,2,31,10,48,36,0,102,112,0,31,
		43,36,164,0,176,84,0,48,43,0,102,112,0,48,47,0,102,112,0,
		100,176,80,0,9,120,12,2,28,6,92,255,25,3,122,20,4,36,165,
		0,121,110,7,36,166,0,95,2,92,9,5,28,42,48,69,0,176,70,
		0,102,12,1,112,0,92,10,16,28,26,36,167,0,176,85,0,48,47,
		0,102,112,0,106,2,9,0,20,2,36,168,0,121,110,7,36,170,0,
		95,2,92,27,8,29,155,0,48,47,0,176,70,0,102,12,1,112,0,
		48,47,0,48,43,0,102,112,0,112,0,69,29,129,0,36,171,0,176,
		86,0,48,47,0,48,43,0,102,112,0,112,0,12,1,100,69,73,36,
		174,0,121,110,7,36,176,0,95,1,93,10,2,8,28,69,36,177,0,
		176,87,0,95,2,12,1,80,4,36,178,0,95,4,97,0,128,0,0,
		15,28,14,36,179,0,96,4,0,97,255,255,0,0,136,36,181,0,176,
		66,0,48,47,0,102,112,0,93,181,0,95,4,121,15,28,5,121,25,
		3,122,121,20,4,25,22,36,183,0,95,1,92,2,8,28,12,36,184,
		0,48,88,0,102,112,0,73,36,187,0,92,255,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_SETCOLOR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,191,0,95,1,100,69,28,18,36,192,0,176,89,0,48,
		47,0,102,112,0,95,1,20,2,36,194,0,95,2,100,69,28,22,36,
		195,0,176,66,0,48,47,0,102,112,0,93,67,4,121,95,2,20,4,
		36,197,0,48,62,0,48,29,0,102,112,0,95,1,95,2,95,3,112,
		3,73,36,199,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_READONLY )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,203,0,95,1,100,69,28,47,36,204,0,176,35,0,176,
		66,0,48,47,0,102,112,0,93,207,0,95,1,28,5,122,25,3,121,
		121,12,4,12,1,31,14,36,205,0,48,37,0,102,95,1,112,1,73,
		36,208,0,48,90,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_UPDATEPOS )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,211,0,176,66,0,48,47,0,102,112,0,93,176,0,121,
		121,12,4,80,1,36,212,0,176,91,0,95,1,12,1,122,72,80,2,
		176,87,0,95,1,12,1,122,72,80,3,36,214,0,48,92,0,102,176,
		66,0,48,47,0,102,112,0,93,201,0,95,2,122,49,121,12,4,122,
		72,112,1,73,36,215,0,48,93,0,102,176,66,0,48,47,0,102,112,
		0,93,186,0,121,121,12,4,112,1,73,36,216,0,48,94,0,102,176,
		95,0,48,47,0,102,112,0,95,2,95,3,12,3,112,1,73,36,217,
		0,48,96,0,102,95,2,112,1,73,36,218,0,48,97,0,102,95,3,
		95,2,49,112,1,73,36,219,0,48,98,0,102,95,2,176,66,0,48,
		47,0,102,112,0,93,187,0,92,255,121,12,4,49,112,1,73,36,221,
		0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_ONCHANGE )
{
	static const HB_BYTE pcode[] =
	{
		36,225,0,48,65,0,102,112,0,100,69,28,56,36,226,0,48,99,0,
		48,43,0,102,112,0,120,112,1,73,36,227,0,48,82,0,48,65,0,
		102,112,0,48,100,0,102,112,0,102,112,2,73,36,228,0,48,99,0,
		48,43,0,102,112,0,9,112,1,73,36,230,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_ONGOTFOCUS )
{
	static const HB_BYTE pcode[] =
	{
		36,233,0,48,44,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_ONLOSTFOCUS )
{
	static const HB_BYTE pcode[] =
	{
		36,236,0,48,46,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_WHEN )
{
	static const HB_BYTE pcode[] =
	{
		36,241,0,176,101,0,102,9,12,2,31,8,36,242,0,120,110,7,36,
		244,0,48,31,0,102,48,100,0,102,112,0,112,1,73,36,245,0,48,
		99,0,48,43,0,102,112,0,120,112,1,73,36,246,0,48,82,0,48,
		102,0,102,112,0,48,56,0,102,112,0,102,112,2,73,36,247,0,48,
		99,0,48,43,0,102,112,0,9,112,1,73,36,248,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_VALID )
{
	static const HB_BYTE pcode[] =
	{
		36,253,0,48,103,0,102,112,0,100,69,28,17,176,101,0,102,120,12,
		2,31,8,36,254,0,120,110,7,36,0,1,48,31,0,102,48,100,0,
		102,112,0,112,1,73,36,1,1,48,99,0,48,43,0,102,112,0,120,
		112,1,73,36,2,1,48,82,0,48,103,0,102,112,0,48,56,0,102,
		112,0,102,112,2,73,36,3,1,48,99,0,48,43,0,102,112,0,9,
		112,1,73,36,5,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_SAVEFILE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,9,1,176,35,0,95,1,12,1,31,31,36,10,1,176,
		35,0,176,104,0,48,47,0,102,112,0,95,1,12,2,12,1,31,8,
		36,11,1,120,110,7,36,14,1,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_OPENFILE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,18,1,176,35,0,95,1,12,1,31,31,36,19,1,176,
		35,0,176,105,0,48,47,0,102,112,0,95,1,12,2,12,1,31,8,
		36,20,1,120,110,7,36,23,1,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HRICHEDIT_PRINT )
{
	static const HB_BYTE pcode[] =
	{
		36,27,1,48,106,0,102,112,0,100,5,73,36,30,1,176,107,0,48,
		106,0,102,112,0,12,1,121,69,28,56,36,31,1,176,108,0,48,47,
		0,102,112,0,48,106,0,102,112,0,12,2,121,69,28,18,36,32,1,
		176,109,0,48,106,0,102,112,0,20,1,25,16,36,34,1,176,110,0,
		48,106,0,102,112,0,20,1,36,37,1,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,111,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}
