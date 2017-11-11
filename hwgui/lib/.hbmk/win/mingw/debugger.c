/*
 * Harbour 3.4.0dev (f75b945) (2016-01-05 16:47)
 * MinGW GNU C 5.3 (32-bit)
 * Generated C source from "source\debug\debugger.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( __DBGALTDENTRY );
HB_FUNC_EXTERN( __DBGINVOKEDEBUG );
HB_FUNC_EXTERN( SET );
HB_FUNC( __DBGENTRY );
HB_FUNC_EXTERN( __DBGSETENTRY );
HB_FUNC( HBDEBUGGER );
HB_FUNC_EXTERN( __DBGSETGO );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_STATIC( HBDEBUGGER_NEW );
HB_FUNC_STATIC( HBDEBUGGER_ACTIVATE );
HB_FUNC_STATIC( HBDEBUGGER_CODEBLOCKTRACE );
HB_FUNC_STATIC( HBDEBUGGER_GETEXPRVALUE );
HB_FUNC_STATIC( HBDEBUGGER_GETSOURCEFILES );
HB_FUNC_STATIC( HBDEBUGGER_GO );
HB_FUNC_STATIC( HBDEBUGGER_HANDLEEVENT );
HB_FUNC_STATIC( HBDEBUGGER_LOADCALLSTACK );
HB_FUNC_STATIC( HBDEBUGGER_QUIT );
HB_FUNC_STATIC( HBDEBUGGER_SHOWCODELINE );
HB_FUNC_STATIC( HBDEBUGGER_VARGETINFO );
HB_FUNC_STATIC( HBDEBUGGER_VARGETVALUE );
HB_FUNC_STATIC( HBDEBUGGER_VARSETVALUE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_DBG_NEW );
HB_FUNC_EXTERN( __DBGSETCBTRACE );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( __BREAKBLOCK );
HB_FUNC_EXTERN( __DBGGETEXPRVALUE );
HB_FUNC_EXTERN( HB_ISARRAY );
HB_FUNC_EXTERN( AEVAL );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC( __DBGVALTOSTR );
HB_FUNC_EXTERN( __DBGGETSOURCEFILES );
HB_FUNC_EXTERN( HWG_DBG_INPUT );
HB_FUNC_EXTERN( __DBGSETTRACE );
HB_FUNC_EXTERN( __DBGSETNEXTROUTINE );
HB_FUNC_EXTERN( __DBGISVALIDSTOPLINE );
HB_FUNC_EXTERN( __DBGSETTOCURSOR );
HB_FUNC_EXTERN( HWG_DBG_SETACTIVELINE );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( HWG_DBG_ANSWER );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( __DBGADDBREAK );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( ADEL );
HB_FUNC_EXTERN( ASIZE );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( __DBGDELBREAK );
HB_FUNC_EXTERN( __DBGADDWATCH );
HB_FUNC_STATIC( SENDWATCH );
HB_FUNC_EXTERN( __DBGDELWATCH );
HB_FUNC_STATIC( SENDSTACK );
HB_FUNC_STATIC( SENDLOCAL );
HB_FUNC_STATIC( SENDAREAS );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( ARRAY );
HB_FUNC_EXTERN( __DBGPROCLEVEL );
HB_FUNC_EXTERN( PROCNAME );
HB_FUNC_EXTERN( HB_NTOS );
HB_FUNC_EXTERN( PROCLINE );
HB_FUNC_EXTERN( __DBGSETQUIT );
HB_FUNC_EXTERN( HWG_DBG_QUIT );
HB_FUNC_EXTERN( HWG_DBG_MSG );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( __DBGVMVARGGET );
HB_FUNC_EXTERN( __DBGVMVARLGET );
HB_FUNC_EXTERN( __DBGVMVARSGET );
HB_FUNC_EXTERN( __DBGVMVARGSET );
HB_FUNC_EXTERN( __DBGVMVARLSET );
HB_FUNC_EXTERN( __DBGVMVARSSET );
HB_FUNC( __DBG );
HB_FUNC_EXTERN( USED );
HB_FUNC_EXTERN( SELECT );
HB_FUNC_EXTERN( DBSELECTAREA );
HB_FUNC_EXTERN( ALIAS );
HB_FUNC_EXTERN( RDDNAME );
HB_FUNC_EXTERN( RECCOUNT );
HB_FUNC_EXTERN( RECNO );
HB_FUNC_EXTERN( BOF );
HB_FUNC_EXTERN( EOF );
HB_FUNC_EXTERN( FOUND );
HB_FUNC_EXTERN( DELETED );
HB_FUNC_EXTERN( DBFILTER );
HB_FUNC_EXTERN( ORDNAME );
HB_FUNC_EXTERN( ORDKEY );
HB_FUNC_STATIC( STARTS );
HB_FUNC_STATIC( STRIP_PATH );
HB_FUNC_EXTERN( HB_FNAMESPLIT );
HB_FUNC_EXTERN( MIN );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( HB_TTOC );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DEBUGGER )
{ "__DBGALTDENTRY", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( __DBGALTDENTRY )}, NULL },
{ "__DBGINVOKEDEBUG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGINVOKEDEBUG )}, NULL },
{ "SET", {HB_FS_PUBLIC}, {HB_FUNCNAME( SET )}, NULL },
{ "__DBGENTRY", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( __DBGENTRY )}, NULL },
{ "__DBGSETENTRY", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETENTRY )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBDEBUGGER", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER )}, NULL },
{ "_PINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NPROCLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ACALLSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AMODULES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ABREAKPOINTS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LRUNATSTARTUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__DBGSETGO", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETGO )}, NULL },
{ "_LGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBDEBUGGER_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_NEW )}, NULL },
{ "HBDEBUGGER_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_ACTIVATE )}, NULL },
{ "HBDEBUGGER_CODEBLOCKTRACE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_CODEBLOCKTRACE )}, NULL },
{ "HBDEBUGGER_GETEXPRVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_GETEXPRVALUE )}, NULL },
{ "HBDEBUGGER_GETSOURCEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_GETSOURCEFILES )}, NULL },
{ "HBDEBUGGER_GO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_GO )}, NULL },
{ "HBDEBUGGER_HANDLEEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_HANDLEEVENT )}, NULL },
{ "HBDEBUGGER_LOADCALLSTACK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_LOADCALLSTACK )}, NULL },
{ "HBDEBUGGER_QUIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_QUIT )}, NULL },
{ "HBDEBUGGER_SHOWCODELINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_SHOWCODELINE )}, NULL },
{ "HBDEBUGGER_VARGETINFO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_VARGETINFO )}, NULL },
{ "HBDEBUGGER_VARGETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_VARGETVALUE )}, NULL },
{ "HBDEBUGGER_VARSETVALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HBDEBUGGER_VARSETVALUE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DBG_NEW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_NEW )}, NULL },
{ "LOADCALLSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LACTIVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LACTIVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SHOWCODELINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HANDLEEVENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__DBGSETCBTRACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETCBTRACE )}, NULL },
{ "PINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LCBTRACE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "__BREAKBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( __BREAKBLOCK )}, NULL },
{ "__DBGGETEXPRVALUE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGGETEXPRVALUE )}, NULL },
{ "OPERATION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DESCRIPTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ISARRAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISARRAY )}, NULL },
{ "ARGS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AEVAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( AEVAL )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "__DBGVALTOSTR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( __DBGVALTOSTR )}, NULL },
{ "__DBGGETSOURCEFILES", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGGETSOURCEFILES )}, NULL },
{ "HWG_DBG_INPUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_INPUT )}, NULL },
{ "QUIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__DBGSETTRACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETTRACE )}, NULL },
{ "__DBGSETNEXTROUTINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETNEXTROUTINE )}, NULL },
{ "__DBGISVALIDSTOPLINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGISVALIDSTOPLINE )}, NULL },
{ "__DBGSETTOCURSOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETTOCURSOR )}, NULL },
{ "HWG_DBG_SETACTIVELINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_SETACTIVELINE )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ABREAKPOINTS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DBG_ANSWER", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_ANSWER )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "__DBGADDBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGADDBREAK )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "ADEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADEL )}, NULL },
{ "ASIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASIZE )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "__DBGDELBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGDELBREAK )}, NULL },
{ "__DBGADDWATCH", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGADDWATCH )}, NULL },
{ "_NWATCHES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWATCHES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDWATCH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SENDWATCH )}, NULL },
{ "__DBGDELWATCH", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGDELWATCH )}, NULL },
{ "_LVIEWSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDSTACK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SENDSTACK )}, NULL },
{ "_LSHOWLOCALS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDLOCAL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SENDLOCAL )}, NULL },
{ "_LSHOWWATCH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDAREAS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SENDAREAS )}, NULL },
{ "LEFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEFT )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "GETEXPRVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_APROCSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ARRAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( ARRAY )}, NULL },
{ "NPROCLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__DBGPROCLEVEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGPROCLEVEL )}, NULL },
{ "ACALLSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APROCSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PROCNAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCNAME )}, NULL },
{ "HB_NTOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_NTOS )}, NULL },
{ "PROCLINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROCLINE )}, NULL },
{ "__DBGSETQUIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGSETQUIT )}, NULL },
{ "HWG_DBG_QUIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_QUIT )}, NULL },
{ "LGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DBG_MSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DBG_MSG )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "LVIEWSTACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSHOWLOCALS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSHOWWATCH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VARGETVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "__DBGVMVARGGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARGGET )}, NULL },
{ "__DBGVMVARLGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARLGET )}, NULL },
{ "__DBGVMVARSGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARSGET )}, NULL },
{ "__DBGVMVARGSET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARGSET )}, NULL },
{ "__DBGVMVARLSET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARLSET )}, NULL },
{ "__DBGVMVARSSET", {HB_FS_PUBLIC}, {HB_FUNCNAME( __DBGVMVARSSET )}, NULL },
{ "__DBG", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( __DBG )}, NULL },
{ "USED", {HB_FS_PUBLIC}, {HB_FUNCNAME( USED )}, NULL },
{ "SELECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SELECT )}, NULL },
{ "DBSELECTAREA", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBSELECTAREA )}, NULL },
{ "ALIAS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALIAS )}, NULL },
{ "RDDNAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( RDDNAME )}, NULL },
{ "RECCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RECCOUNT )}, NULL },
{ "RECNO", {HB_FS_PUBLIC}, {HB_FUNCNAME( RECNO )}, NULL },
{ "BOF", {HB_FS_PUBLIC}, {HB_FUNCNAME( BOF )}, NULL },
{ "EOF", {HB_FS_PUBLIC}, {HB_FUNCNAME( EOF )}, NULL },
{ "FOUND", {HB_FS_PUBLIC}, {HB_FUNCNAME( FOUND )}, NULL },
{ "DELETED", {HB_FS_PUBLIC}, {HB_FUNCNAME( DELETED )}, NULL },
{ "DBFILTER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFILTER )}, NULL },
{ "ORDNAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORDNAME )}, NULL },
{ "ORDKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORDKEY )}, NULL },
{ "STARTS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STARTS )}, NULL },
{ "STRIP_PATH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STRIP_PATH )}, NULL },
{ "HB_FNAMESPLIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_FNAMESPLIT )}, NULL },
{ "MIN", {HB_FS_PUBLIC}, {HB_FUNCNAME( MIN )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "HB_TTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_TTOC )}, NULL },
{ "CLASSNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DEBUGGER, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DEBUGGER
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DEBUGGER )
   #include "hbiniseg.h"
#endif

HB_FUNC( __DBGALTDENTRY )
{
	static const HB_BYTE pcode[] =
	{
		36,156,0,176,1,0,176,2,0,92,13,12,1,20,
		1,36,158,0,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( __DBGENTRY )
{
	static const HB_BYTE pcode[] =
	{
		13,1,6,116,138,0,36,166,0,95,1,92,6,8,
		28,13,36,168,0,176,4,0,20,0,26,172,0,36,
		170,0,95,1,92,7,8,29,161,0,36,172,0,103,
		1,0,100,8,165,80,7,28,32,36,173,0,48,5,
		0,176,6,0,12,0,112,0,82,1,0,36,174,0,
		48,7,0,103,1,0,95,2,112,1,73,36,176,0,
		48,8,0,103,1,0,95,3,112,1,73,36,177,0,
		48,9,0,103,1,0,95,4,112,1,73,36,178,0,
		48,10,0,103,1,0,95,5,112,1,73,36,179,0,
		48,11,0,103,1,0,95,6,112,1,73,36,180,0,
		95,7,28,29,36,181,0,48,12,0,103,1,0,112,
		0,28,16,36,182,0,176,13,0,95,2,20,1,36,
		183,0,7,36,186,0,48,14,0,103,1,0,9,112,
		1,73,36,187,0,48,15,0,103,1,0,112,0,73,
		36,191,0,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HBDEBUGGER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,138,0,36,193,0,103,2,0,100,8,
		29,164,4,176,16,0,104,2,0,12,1,29,153,4,
		166,91,4,0,122,80,1,48,5,0,176,17,0,12,
		0,106,11,72,66,68,101,98,117,103,103,101,114,0,
		4,0,0,108,6,112,3,80,2,36,195,0,48,18,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		6,112,73,110,102,111,0,4,1,0,9,112,5,73,
		36,197,0,48,18,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,9,99,80,114,103,78,97,109,101,
		0,4,1,0,9,112,5,73,36,199,0,48,18,0,
		95,2,100,4,0,0,95,1,121,72,121,72,121,72,
		106,6,97,86,97,114,115,0,4,1,0,9,112,5,
		73,36,200,0,48,18,0,95,2,100,4,0,0,95,
		1,121,72,121,72,121,72,106,13,97,66,114,101,97,
		107,80,111,105,110,116,115,0,4,1,0,9,112,5,
		73,36,201,0,48,18,0,95,2,100,4,0,0,95,
		1,121,72,121,72,121,72,106,11,97,67,97,108,108,
		83,116,97,99,107,0,4,1,0,9,112,5,73,36,
		202,0,48,18,0,95,2,100,4,0,0,95,1,121,
		72,121,72,121,72,106,11,97,80,114,111,99,83,116,
		97,99,107,0,4,1,0,9,112,5,73,36,203,0,
		48,18,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,11,110,80,114,111,99,76,101,118,101,108,0,
		4,1,0,9,112,5,73,36,204,0,48,18,0,95,
		2,100,4,0,0,95,1,121,72,121,72,121,72,106,
		9,97,77,111,100,117,108,101,115,0,4,1,0,9,
		112,5,73,36,205,0,48,18,0,95,2,100,121,95,
		1,121,72,121,72,121,72,106,9,110,87,97,116,99,
		104,101,115,0,4,1,0,9,112,5,73,36,207,0,
		48,18,0,95,2,100,121,95,1,121,72,121,72,121,
		72,106,7,110,83,112,101,101,100,0,4,1,0,9,
		112,5,73,36,209,0,48,18,0,95,2,100,9,95,
		1,121,72,121,72,121,72,106,11,108,86,105,101,119,
		83,116,97,99,107,0,4,1,0,9,112,5,73,36,
		210,0,48,18,0,95,2,100,9,95,1,121,72,121,
		72,121,72,106,12,108,83,104,111,119,76,111,99,97,
		108,115,0,4,1,0,9,112,5,73,36,211,0,48,
		18,0,95,2,100,9,95,1,121,72,121,72,121,72,
		106,11,108,83,104,111,119,87,97,116,99,104,0,4,
		1,0,9,112,5,73,36,212,0,48,18,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,4,108,71,
		111,0,4,1,0,9,112,5,73,36,213,0,48,18,
		0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		8,108,65,99,116,105,118,101,0,4,1,0,9,112,
		5,73,36,214,0,48,18,0,95,2,100,120,95,1,
		121,72,121,72,121,72,106,9,108,67,66,84,114,97,
		99,101,0,4,1,0,9,112,5,73,36,215,0,48,
		18,0,95,2,100,9,95,1,121,72,121,72,121,72,
		106,14,108,82,117,110,65,116,83,116,97,114,116,117,
		112,0,4,1,0,9,112,5,73,36,217,0,48,19,
		0,95,2,106,4,78,101,119,0,108,20,95,1,121,
		72,121,72,121,72,112,3,73,36,218,0,48,19,0,
		95,2,106,9,65,99,116,105,118,97,116,101,0,108,
		21,95,1,121,72,121,72,121,72,112,3,73,36,220,
		0,48,19,0,95,2,106,15,67,111,100,101,98,108,
		111,99,107,84,114,97,99,101,0,108,22,95,1,121,
		72,121,72,121,72,112,3,73,36,221,0,48,19,0,
		95,2,106,13,71,101,116,69,120,112,114,86,97,108,
		117,101,0,108,23,95,1,121,72,121,72,121,72,112,
		3,73,36,222,0,48,19,0,95,2,106,15,71,101,
		116,83,111,117,114,99,101,70,105,108,101,115,0,108,
		24,95,1,121,72,121,72,121,72,112,3,73,36,224,
		0,48,19,0,95,2,106,3,71,111,0,108,25,95,
		1,121,72,121,72,121,72,112,3,73,36,225,0,48,
		19,0,95,2,106,12,72,97,110,100,108,101,69,118,
		101,110,116,0,108,26,95,1,121,72,121,72,121,72,
		112,3,73,36,226,0,48,19,0,95,2,106,14,76,
		111,97,100,67,97,108,108,83,116,97,99,107,0,108,
		27,95,1,121,72,121,72,121,72,112,3,73,36,228,
		0,48,19,0,95,2,106,5,81,117,105,116,0,108,
		28,95,1,121,72,121,72,121,72,112,3,73,36,229,
		0,48,19,0,95,2,106,13,83,104,111,119,67,111,
		100,101,76,105,110,101,0,108,29,95,1,121,72,121,
		72,121,72,112,3,73,36,231,0,48,19,0,95,2,
		106,11,86,97,114,71,101,116,73,110,102,111,0,108,
		30,95,1,121,72,121,72,121,72,112,3,73,36,232,
		0,48,19,0,95,2,106,12,86,97,114,71,101,116,
		86,97,108,117,101,0,108,31,95,1,121,72,121,72,
		121,72,112,3,73,36,233,0,48,19,0,95,2,106,
		12,86,97,114,83,101,116,86,97,108,117,101,0,108,
		32,95,1,121,72,121,72,121,72,112,3,73,36,235,
		0,48,33,0,95,2,112,0,73,167,14,0,0,176,
		34,0,104,2,0,95,2,20,2,168,48,35,0,95,
		2,112,0,80,3,176,36,0,95,3,106,10,73,110,
		105,116,67,108,97,115,115,0,12,2,28,12,48,37,
		0,95,3,164,146,1,0,73,95,3,110,7,48,35,
		0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		116,138,0,36,240,0,102,82,1,0,36,243,0,176,
		38,0,20,0,36,245,0,48,14,0,102,48,12,0,
		102,112,0,112,1,73,36,247,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,251,0,48,39,0,102,112,0,73,36,253,0,48,
		40,0,102,112,0,31,13,36,254,0,48,41,0,102,
		120,112,1,73,36,2,1,48,42,0,102,122,112,1,
		73,36,3,1,48,43,0,102,112,0,73,36,5,1,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_CODEBLOCKTRACE )
{
	static const HB_BYTE pcode[] =
	{
		36,10,1,176,44,0,48,45,0,102,112,0,48,46,
		0,102,112,0,20,2,36,12,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_GETEXPRVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,20,1,9,80,2,36,22,1,176,47,
		0,176,48,0,12,0,12,1,80,4,36,23,1,113,
		59,0,0,36,24,1,176,49,0,48,45,0,102,112,
		0,95,1,96,2,0,12,3,80,3,36,25,1,95,
		2,31,22,36,26,1,106,13,83,121,110,116,97,120,
		32,101,114,114,111,114,0,80,3,36,27,1,114,127,
		0,0,36,28,1,115,80,5,36,29,1,48,50,0,
		95,5,112,0,106,3,58,32,0,72,48,51,0,95,
		5,112,0,72,80,3,36,30,1,176,52,0,48,53,
		0,95,5,112,0,12,1,28,70,36,31,1,96,3,
		0,106,13,59,32,97,114,103,117,109,101,110,116,115,
		58,0,135,36,32,1,176,54,0,48,53,0,95,5,
		112,0,89,31,0,1,0,1,0,3,0,96,255,255,
		106,2,32,0,176,55,0,176,56,0,95,1,12,1,
		12,1,72,139,6,20,2,36,34,1,9,80,2,36,
		36,1,176,47,0,95,4,20,1,36,38,1,95,3,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_GETSOURCEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,42,1,176,57,0,48,45,0,102,112,0,20,1,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_GO )
{
	static const HB_BYTE pcode[] =
	{
		36,47,1,176,13,0,48,45,0,102,112,0,20,1,
		36,49,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_HANDLEEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,116,138,0,36,58,1,176,58,0,96,2,
		0,96,3,0,12,2,80,1,36,61,1,95,1,92,
		6,8,28,20,36,62,1,48,59,0,103,1,0,112,
		0,73,36,63,1,100,110,7,36,65,1,95,1,92,
		7,8,28,18,36,66,1,48,60,0,102,112,0,73,
		36,67,1,100,110,7,36,69,1,95,1,122,8,28,
		18,36,70,1,48,60,0,102,112,0,73,36,71,1,
		100,110,7,36,73,1,95,1,92,2,8,28,8,36,
		74,1,100,110,7,36,76,1,95,1,92,3,8,28,
		22,36,77,1,176,61,0,48,45,0,102,112,0,20,
		1,36,78,1,100,110,7,36,80,1,95,1,92,4,
		8,28,22,36,81,1,176,62,0,48,45,0,102,112,
		0,20,1,36,82,1,100,110,7,36,84,1,95,1,
		92,5,8,28,62,36,85,1,176,63,0,48,45,0,
		102,112,0,95,2,95,3,12,3,28,26,36,86,1,
		176,64,0,48,45,0,102,112,0,95,2,95,3,20,
		3,36,87,1,100,110,7,36,89,1,176,65,0,106,
		2,46,0,121,20,2,26,18,255,36,92,1,95,1,
		92,8,8,28,108,36,93,1,176,63,0,48,45,0,
		102,112,0,95,2,95,3,12,3,28,71,36,94,1,
		176,66,0,48,67,0,102,112,0,95,3,95,2,4,
		2,0,20,2,36,95,1,176,68,0,106,5,108,105,
		110,101,0,176,69,0,176,70,0,95,3,12,1,12,
		1,20,2,36,96,1,176,71,0,48,45,0,102,112,
		0,95,2,95,3,20,3,26,175,254,36,98,1,176,
		68,0,106,4,101,114,114,0,20,1,26,158,254,36,
		101,1,95,1,92,9,8,29,161,0,36,102,1,176,
		72,0,48,67,0,102,112,0,89,31,0,1,0,2,
		0,3,0,2,0,95,1,122,1,95,255,8,21,28,
		11,73,95,1,92,2,1,95,254,8,6,12,2,165,
		80,4,121,8,28,19,36,103,1,176,68,0,106,4,
		101,114,114,0,20,1,26,78,254,36,105,1,176,73,
		0,48,67,0,102,112,0,95,4,20,2,36,106,1,
		176,74,0,48,67,0,102,112,0,176,75,0,48,67,
		0,102,112,0,12,1,122,49,20,2,36,107,1,176,
		68,0,106,3,111,107,0,176,69,0,176,70,0,95,
		3,12,1,12,1,20,2,36,108,1,176,76,0,48,
		45,0,102,112,0,95,4,122,49,20,2,26,245,253,
		36,111,1,95,1,92,14,8,28,67,36,112,1,176,
		77,0,48,45,0,102,112,0,95,2,9,20,3,36,
		113,1,48,78,0,102,21,48,79,0,163,0,112,0,
		23,112,1,73,36,114,1,176,68,0,106,11,118,97,
		108,117,101,119,97,116,99,104,0,176,80,0,12,0,
		20,2,26,170,253,36,116,1,95,1,92,15,8,28,
		87,36,117,1,176,81,0,48,45,0,102,112,0,95,
		2,122,49,20,2,36,118,1,48,78,0,102,21,48,
		79,0,163,0,112,0,17,112,1,121,15,28,31,36,
		119,1,176,68,0,106,11,118,97,108,117,101,119,97,
		116,99,104,0,176,80,0,12,0,20,2,26,91,253,
		36,121,1,176,68,0,106,3,111,107,0,20,1,26,
		75,253,36,124,1,95,1,92,11,8,28,77,36,125,
		1,95,2,106,3,111,110,0,8,28,37,36,126,1,
		48,82,0,102,120,112,1,73,36,127,1,176,68,0,
		106,6,115,116,97,99,107,0,176,83,0,12,0,20,
		2,26,17,253,36,129,1,48,82,0,102,9,112,1,
		73,36,130,1,176,68,0,106,3,111,107,0,20,1,
		26,246,252,36,133,1,95,1,92,12,8,28,82,36,
		134,1,95,2,106,3,111,110,0,8,28,42,36,135,
		1,48,84,0,102,120,112,1,73,36,136,1,176,68,
		0,106,11,118,97,108,117,101,108,111,99,97,108,0,
		176,85,0,12,0,20,2,26,183,252,36,138,1,48,
		84,0,102,9,112,1,73,36,139,1,176,68,0,106,
		3,111,107,0,20,1,26,156,252,36,142,1,95,1,
		92,13,8,28,111,36,143,1,95,2,106,3,111,110,
		0,8,28,71,36,144,1,48,86,0,102,120,112,1,
		73,36,145,1,48,79,0,102,112,0,121,15,28,31,
		36,146,1,176,68,0,106,11,118,97,108,117,101,119,
		97,116,99,104,0,176,80,0,12,0,20,2,26,80,
		252,36,148,1,176,68,0,106,3,111,107,0,20,1,
		26,64,252,36,151,1,48,86,0,102,9,112,1,73,
		36,152,1,176,68,0,106,3,111,107,0,20,1,26,
		37,252,36,155,1,95,1,92,16,8,28,31,36,156,
		1,176,68,0,106,11,118,97,108,117,101,97,114,101,
		97,115,0,176,87,0,12,0,20,2,26,254,251,36,
		158,1,95,1,92,10,8,29,243,251,36,159,1,176,
		88,0,95,2,122,12,2,106,2,63,0,8,28,42,
		36,160,1,176,69,0,176,89,0,95,2,176,88,0,
		95,2,92,2,12,2,106,3,63,63,0,8,28,6,
		92,3,25,4,92,2,12,2,12,1,80,2,36,162,
		1,176,68,0,106,6,118,97,108,117,101,0,176,56,
		0,48,90,0,102,95,2,112,1,12,1,20,2,26,
		153,251,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_LOADCALLSTACK )
{
	static const HB_BYTE pcode[] =
	{
		13,5,0,36,177,1,48,91,0,102,176,92,0,48,
		93,0,102,112,0,12,1,112,1,73,36,179,1,176,
		94,0,12,0,122,49,80,3,36,180,1,95,3,48,
		93,0,102,112,0,49,122,72,80,2,36,182,1,95,
		2,165,80,1,26,148,0,36,183,1,95,3,95,1,
		49,122,72,80,4,36,184,1,176,72,0,48,95,0,
		102,112,0,89,18,0,1,0,1,0,4,0,95,1,
		92,4,1,95,255,8,6,12,2,80,5,36,185,1,
		95,5,121,15,28,30,36,187,1,48,95,0,102,112,
		0,95,5,1,48,96,0,102,112,0,95,1,95,2,
		49,122,72,2,25,58,36,189,1,100,176,97,0,95,
		1,12,1,106,2,40,0,72,176,98,0,176,99,0,
		95,1,12,1,12,1,72,106,2,41,0,72,100,95,
		4,100,100,4,6,0,48,96,0,102,112,0,95,1,
		95,2,49,122,72,2,36,182,1,175,1,0,95,3,
		15,29,108,255,36,193,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_QUIT )
{
	static const HB_BYTE pcode[] =
	{
		116,138,0,36,197,1,176,100,0,48,45,0,102,112,
		0,20,1,36,198,1,100,82,1,0,36,200,1,176,
		101,0,20,0,36,202,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_SHOWCODELINE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,212,1,48,102,0,102,112,0,32,177,
		0,36,213,1,48,96,0,102,112,0,95,1,1,92,
		3,1,80,2,36,214,1,48,96,0,102,112,0,95,
		1,1,122,1,80,3,36,215,1,95,2,100,8,28,
		52,36,217,1,176,103,0,48,96,0,102,112,0,95,
		1,1,92,2,1,106,21,58,32,67,111,100,101,32,
		110,111,116,32,97,118,97,105,108,97,98,108,101,0,
		72,20,1,36,218,1,100,110,7,36,221,1,176,104,
		0,95,3,12,1,31,72,36,225,1,176,65,0,95,
		3,95,2,48,105,0,102,112,0,28,9,176,83,0,
		12,0,25,3,100,48,106,0,102,112,0,28,9,176,
		85,0,12,0,25,3,100,48,107,0,102,112,0,28,
		19,48,79,0,102,112,0,121,15,28,9,176,80,0,
		12,0,25,3,100,20,5,36,229,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_VARGETINFO )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,234,1,176,88,0,95,1,92,3,1,
		122,12,2,80,2,36,235,1,48,108,0,102,95,1,
		112,1,80,3,36,238,1,95,2,106,2,71,0,8,
		28,45,95,1,122,1,106,11,32,60,71,108,111,98,
		97,108,44,32,0,72,176,109,0,95,3,12,1,72,
		106,4,62,58,32,0,72,176,56,0,95,3,12,1,
		72,110,7,36,239,1,95,2,106,2,76,0,8,28,
		44,95,1,122,1,106,10,32,60,76,111,99,97,108,
		44,32,0,72,176,109,0,95,3,12,1,72,106,4,
		62,58,32,0,72,176,56,0,95,3,12,1,72,110,
		7,36,240,1,95,2,106,2,83,0,8,28,45,95,
		1,122,1,106,11,32,60,83,116,97,116,105,99,44,
		32,0,72,176,109,0,95,3,12,1,72,106,4,62,
		58,32,0,72,176,56,0,95,3,12,1,72,110,7,
		36,241,1,95,1,122,1,106,3,32,60,0,72,95,
		1,92,3,1,72,106,3,44,32,0,72,176,109,0,
		95,3,12,1,72,106,4,62,58,32,0,72,176,56,
		0,95,3,12,1,72,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_VARGETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,251,1,176,88,0,95,1,92,3,1,
		122,12,2,80,2,36,254,1,95,2,106,2,71,0,
		8,28,18,176,110,0,95,1,92,4,1,95,1,92,
		2,1,20,2,7,36,255,1,95,2,106,2,76,0,
		8,28,24,176,111,0,176,94,0,12,0,95,1,92,
		4,1,49,95,1,92,2,1,20,2,7,36,0,2,
		95,2,106,2,83,0,8,28,18,176,112,0,95,1,
		92,4,1,95,1,92,2,1,20,2,7,36,1,2,
		95,1,92,2,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HBDEBUGGER_VARSETVALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,12,2,176,88,0,95,1,92,3,1,
		122,12,2,80,4,36,14,2,95,4,106,2,71,0,
		8,28,24,36,15,2,176,113,0,95,1,92,4,1,
		95,1,92,2,1,95,2,20,3,25,104,36,17,2,
		95,4,106,2,76,0,8,28,37,36,18,2,176,94,
		0,12,0,95,1,92,4,1,49,80,3,36,19,2,
		176,114,0,95,3,95,1,92,2,1,95,2,20,3,
		25,57,36,21,2,95,4,106,2,83,0,8,28,24,
		36,22,2,176,115,0,95,1,92,4,1,95,1,92,
		2,1,95,2,20,3,25,23,36,26,2,95,2,95,
		1,92,2,2,36,27,2,95,2,95,1,122,1,38,
		11,36,31,2,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( __DBG )
{
	static const HB_BYTE pcode[] =
	{
		116,138,0,36,35,2,103,1,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SENDSTACK )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,116,138,0,36,39,2,48,96,0,103,1,
		0,112,0,80,1,36,40,2,176,92,0,176,75,0,
		95,1,12,1,92,3,65,122,72,12,1,80,2,92,
		2,80,4,36,42,2,176,69,0,176,70,0,176,75,
		0,95,1,12,1,12,1,12,1,95,2,122,2,36,
		43,2,122,165,80,3,26,141,0,36,44,2,176,104,
		0,95,1,95,3,1,122,1,12,1,28,7,106,1,
		0,25,9,95,1,95,3,1,122,1,95,2,95,4,
		174,4,0,2,36,45,2,176,104,0,95,1,95,3,
		1,92,2,1,12,1,28,14,106,8,85,110,107,110,
		111,119,110,0,25,10,95,1,95,3,1,92,2,1,
		95,2,95,4,174,4,0,2,36,46,2,176,104,0,
		95,1,95,3,1,92,3,1,12,1,28,7,106,1,
		0,25,20,176,69,0,176,70,0,95,1,95,3,1,
		92,3,1,12,1,12,1,95,2,95,4,174,4,0,
		2,36,43,2,175,3,0,176,75,0,95,1,12,1,
		15,29,110,255,36,49,2,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SENDLOCAL )
{
	static const HB_BYTE pcode[] =
	{
		13,5,0,116,138,0,36,52,2,48,96,0,103,1,
		0,112,0,122,1,92,5,1,80,1,36,53,2,176,
		92,0,176,75,0,95,1,12,1,92,3,65,122,72,
		12,1,80,2,122,80,4,36,55,2,176,69,0,176,
		70,0,176,75,0,95,1,12,1,12,1,12,1,95,
		2,122,2,36,56,2,122,165,80,3,25,126,36,57,
		2,95,1,95,3,1,122,1,95,2,175,4,0,2,
		36,58,2,176,111,0,176,94,0,12,0,95,1,95,
		3,1,92,4,1,49,95,1,95,3,1,92,2,1,
		12,2,80,5,36,59,2,176,109,0,95,5,12,1,
		95,2,175,4,0,2,36,60,2,176,56,0,95,5,
		12,1,95,2,175,4,0,2,36,61,2,176,75,0,
		95,2,95,4,1,12,1,92,72,15,28,22,36,62,
		2,176,88,0,95,2,95,4,1,92,72,12,2,95,
		2,95,4,2,36,56,2,175,3,0,176,75,0,95,
		1,12,1,15,29,124,255,36,66,2,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SENDWATCH )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,116,138,0,36,69,2,176,92,0,48,79,
		0,103,1,0,112,0,122,72,12,1,80,1,36,71,
		2,176,69,0,176,70,0,48,79,0,103,1,0,112,
		0,12,1,12,1,95,1,122,2,36,73,2,122,165,
		80,2,25,33,36,74,2,176,56,0,48,90,0,103,
		1,0,95,2,112,1,12,1,95,1,95,2,122,72,
		2,36,73,2,175,2,0,48,79,0,103,1,0,112,
		0,15,28,216,36,77,2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SENDAREAS )
{
	static const HB_BYTE pcode[] =
	{
		13,6,0,36,82,2,93,0,2,3,1,0,80,2,
		121,80,5,36,84,2,122,165,80,3,25,34,36,85,
		2,85,95,3,74,176,117,0,12,0,119,28,13,36,
		86,2,95,3,95,2,175,5,0,2,36,84,2,175,
		3,0,93,0,2,15,28,220,36,90,2,176,118,0,
		12,0,80,6,36,91,2,176,92,0,92,2,95,5,
		92,12,65,72,12,1,80,1,36,92,2,176,98,0,
		95,5,12,1,95,1,122,2,36,93,2,176,98,0,
		92,12,12,1,95,1,92,2,2,36,94,2,92,2,
		80,3,36,95,2,122,165,80,4,26,29,1,36,96,
		2,176,119,0,95,2,95,4,1,20,1,36,97,2,
		95,2,95,4,1,95,6,8,28,8,106,2,42,0,
		25,5,106,1,0,176,120,0,12,0,72,95,1,175,
		3,0,2,36,98,2,176,98,0,95,2,95,4,1,
		12,1,95,1,175,3,0,2,36,99,2,176,121,0,
		12,0,95,1,175,3,0,2,36,100,2,176,98,0,
		176,122,0,12,0,12,1,95,1,175,3,0,2,36,
		101,2,176,98,0,176,123,0,12,0,12,1,95,1,
		175,3,0,2,36,102,2,176,124,0,12,0,28,10,
		106,4,89,101,115,0,25,7,106,3,78,111,0,95,
		1,175,3,0,2,36,103,2,176,125,0,12,0,28,
		10,106,4,89,101,115,0,25,7,106,3,78,111,0,
		95,1,175,3,0,2,36,104,2,176,126,0,12,0,
		28,10,106,4,89,101,115,0,25,7,106,3,78,111,
		0,95,1,175,3,0,2,36,105,2,176,127,0,12,
		0,28,10,106,4,89,101,115,0,25,7,106,3,78,
		111,0,95,1,175,3,0,2,36,106,2,176,128,0,
		12,0,95,1,175,3,0,2,36,107,2,176,129,0,
		12,0,95,1,175,3,0,2,36,108,2,176,130,0,
		12,0,95,1,175,3,0,2,36,95,2,175,4,0,
		95,5,15,29,227,254,36,110,2,176,119,0,95,6,
		20,1,36,112,2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STARTS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,117,2,95,2,176,88,0,95,1,176,
		75,0,95,2,12,1,12,2,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STRIP_PATH )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,126,2,95,1,100,8,28,7,106,1,
		0,80,1,36,128,2,176,133,0,95,1,100,96,2,
		0,96,3,0,20,4,36,130,2,95,2,95,3,72,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( __DBGVALTOSTR )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,134,2,176,109,0,95,1,12,1,80,
		2,36,137,2,95,1,100,8,28,10,106,4,78,73,
		76,0,110,7,36,138,2,95,2,106,2,66,0,8,
		28,16,106,10,123,124,124,32,46,46,46,32,125,0,
		110,7,36,139,2,95,2,106,2,65,0,8,29,170,
		0,36,140,2,106,1,0,80,4,36,141,2,176,134,
		0,92,8,176,75,0,95,1,12,1,12,2,80,5,
		36,142,2,122,165,80,3,25,53,36,143,2,96,4,
		0,106,2,34,0,176,109,0,95,1,95,3,1,12,
		1,72,106,2,34,0,72,95,3,95,5,8,28,7,
		106,1,0,25,7,106,3,44,32,0,72,135,36,142,
		2,175,3,0,95,5,15,28,202,36,145,2,95,5,
		176,75,0,95,1,12,1,35,28,17,36,146,2,96,
		4,0,106,6,44,32,46,46,46,0,135,36,148,2,
		106,7,65,114,114,97,121,40,0,176,98,0,176,75,
		0,95,1,12,1,12,1,72,106,6,41,58,32,123,
		32,0,72,95,4,72,106,3,32,125,0,72,110,7,
		36,149,2,95,2,106,3,67,77,0,24,28,16,106,
		2,34,0,95,1,72,106,2,34,0,72,110,7,36,
		150,2,95,2,106,2,76,0,8,28,22,95,1,28,
		10,106,4,46,84,46,0,25,8,106,4,46,70,46,
		0,110,7,36,151,2,95,2,106,2,68,0,8,28,
		10,176,135,0,95,1,20,1,7,36,153,2,95,2,
		106,2,84,0,8,28,10,176,136,0,95,1,20,1,
		7,36,155,2,95,2,106,2,78,0,8,28,10,176,
		70,0,95,1,20,1,7,36,156,2,95,2,106,2,
		79,0,8,28,32,106,7,67,108,97,115,115,32,0,
		48,137,0,95,1,112,0,72,106,8,32,111,98,106,
		101,99,116,0,72,110,7,36,157,2,95,2,106,2,
		72,0,8,28,30,106,6,72,97,115,104,40,0,176,
		98,0,176,75,0,95,1,12,1,12,1,72,106,2,
		41,0,72,110,7,36,158,2,95,2,106,2,80,0,
		8,28,14,106,8,80,111,105,110,116,101,114,0,110,
		7,36,161,2,106,2,85,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,138,0,2,0,116,138,0,179,1,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

