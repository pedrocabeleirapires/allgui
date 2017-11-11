/*
 * Harbour 3.2.0dev (Rev. 18769)
 * Microsoft Visual C++ 16.0.40219 (32-bit)
 * Generated C source from "source\htimer.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HTIMER );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HOBJECT );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( __OBJADDDATA );
HB_FUNC_EXTERN( SETTIMER );
HB_FUNC_STATIC( HTIMER_NEW );
HB_FUNC_STATIC( HTIMER_INIT );
HB_FUNC_STATIC( HTIMER_ONACTION );
HB_FUNC_STATIC( HTIMER_END );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWINDOW );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( KILLTIMER );
HB_FUNC_EXTERN( ADEL );
HB_FUNC_EXTERN( ASIZE );
HB_FUNC_EXTERN( LEN );
HB_FUNC( TIMERPROC );
HB_FUNC_EXIT( CLEANTIMERS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HTIMER )
{ "HTIMER", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTIMER )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HOBJECT )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "XNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "_XNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJADDDATA", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJADDDATA )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_VALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTIMER", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETTIMER )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HTIMER_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTIMER_NEW )}, NULL },
{ "HTIMER_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTIMER_INIT )}, NULL },
{ "HTIMER_ONACTION", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTIMER_ONACTION )}, NULL },
{ "HTIMER_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HTIMER_END )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFAULTPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETMAIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWINDOW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWINDOW )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "ATIMERS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BACTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ADDOBJECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "KILLTIMER", {HB_FS_PUBLIC}, {HB_FUNCNAME( KILLTIMER )}, NULL },
{ "ADEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADEL )}, NULL },
{ "ASIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASIZE )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "TIMERPROC", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIMERPROC )}, NULL },
{ "INTERVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BACTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLEANTIMERS$", {HB_FS_EXIT | HB_FS_LOCAL}, {HB_EXIT_FUNCNAME( CLEANTIMERS )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HTIMER, "source\\htimer.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HTIMER
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HTIMER )
   #include "hbiniseg.h"
#endif

HB_FUNC( HTIMER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,51,0,36,18,0,103,1,0,100,8,
		29,241,2,176,1,0,104,1,0,12,1,29,230,2,
		166,168,2,0,122,80,1,48,2,0,176,3,0,12,
		0,106,7,72,84,105,109,101,114,0,108,4,4,1,
		0,108,0,112,3,80,2,36,20,0,48,5,0,95,
		2,100,4,0,0,95,1,121,72,121,72,121,72,121,
		72,106,8,97,84,105,109,101,114,115,0,4,1,0,
		9,112,5,73,36,21,0,48,6,0,95,2,100,9,
		95,1,121,72,121,72,121,72,106,6,108,73,110,105,
		116,0,4,1,0,9,112,5,73,36,22,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		3,105,100,0,4,1,0,9,112,5,73,36,23,0,
		48,6,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,6,118,97,108,117,101,0,4,1,0,9,112,
		5,73,36,24,0,48,6,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,8,111,80,97,114,101,110,
		116,0,4,1,0,9,112,5,73,36,25,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		8,98,65,99,116,105,111,110,0,4,1,0,9,112,
		5,73,36,27,0,48,6,0,95,2,100,100,92,4,
		106,6,120,78,97,109,101,0,4,1,0,9,112,5,
		73,36,28,0,48,7,0,95,2,106,5,78,97,109,
		101,0,89,15,0,1,0,0,0,48,8,0,95,1,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,
		36,30,0,48,7,0,95,2,106,6,95,78,97,109,
		101,0,89,95,0,2,0,0,0,176,9,0,95,2,
		12,1,31,79,176,10,0,95,2,12,1,106,2,67,
		0,8,28,65,106,2,58,0,95,2,24,31,56,106,
		2,91,0,95,2,24,31,47,48,11,0,95,1,95,
		2,112,1,73,176,12,0,48,13,0,95,1,112,0,
		95,2,20,2,106,2,95,0,95,2,72,46,48,13,
		0,95,1,112,0,95,1,112,1,25,3,100,6,95,
		1,121,72,121,72,121,72,112,3,73,36,31,0,48,
		7,0,95,2,106,9,73,110,116,101,114,118,97,108,
		0,89,15,0,1,0,0,0,48,14,0,95,1,112,
		0,6,95,1,121,72,121,72,121,72,112,3,73,36,
		32,0,48,7,0,95,2,106,10,95,73,110,116,101,
		114,118,97,108,0,89,49,0,2,0,0,0,48,15,
		0,95,1,95,2,112,1,73,176,16,0,48,17,0,
		48,13,0,95,1,112,0,112,0,48,18,0,95,1,
		112,0,48,14,0,95,1,112,0,12,3,6,95,1,
		121,72,121,72,121,72,112,3,73,36,34,0,48,19,
		0,95,2,106,4,78,101,119,0,108,20,95,1,121,
		72,121,72,121,72,112,3,73,36,35,0,48,19,0,
		95,2,106,5,73,110,105,116,0,108,21,95,1,121,
		72,121,72,121,72,112,3,73,36,36,0,48,19,0,
		95,2,106,9,111,110,65,99,116,105,111,110,0,108,
		22,95,1,121,72,121,72,121,72,112,3,73,36,37,
		0,48,19,0,95,2,106,4,69,78,68,0,108,23,
		95,1,121,72,121,72,121,72,112,3,73,36,39,0,
		48,24,0,95,2,112,0,73,167,14,0,0,176,25,
		0,104,1,0,95,2,20,2,168,48,26,0,95,2,
		112,0,80,3,176,27,0,95,3,106,10,73,110,105,
		116,67,108,97,115,115,0,12,2,28,12,48,28,0,
		95,3,164,146,1,0,73,95,3,110,7,48,26,0,
		103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTIMER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,4,36,44,0,48,29,0,102,95,1,100,8,
		28,19,48,30,0,48,31,0,176,32,0,12,0,112,
		0,112,0,25,4,95,1,112,1,73,36,45,0,95,
		2,100,8,28,58,36,46,0,97,108,132,0,0,80,
		2,36,47,0,176,33,0,48,34,0,102,112,0,89,
		20,0,1,0,1,0,2,0,48,18,0,95,1,112,
		0,95,255,8,6,12,2,121,69,28,10,36,48,0,
		174,2,0,25,212,36,51,0,48,35,0,102,95,2,
		112,1,73,36,52,0,48,15,0,102,176,10,0,95,
		3,12,1,106,2,78,0,5,28,6,95,3,25,3,
		121,112,1,73,36,53,0,48,36,0,102,95,4,112,
		1,73,36,60,0,48,37,0,102,112,0,73,36,61,
		0,176,38,0,48,34,0,102,112,0,102,20,2,36,
		62,0,48,39,0,48,13,0,102,112,0,102,112,1,
		73,36,64,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTIMER_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,68,0,48,40,0,102,112,0,31,75,176,9,0,
		48,17,0,48,13,0,102,112,0,112,0,12,1,31,
		57,36,69,0,48,14,0,102,112,0,121,15,28,33,
		36,70,0,176,16,0,48,17,0,48,13,0,102,112,
		0,112,0,48,18,0,102,112,0,48,14,0,102,112,
		0,20,3,36,72,0,48,41,0,102,120,112,1,73,
		36,75,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTIMER_END )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,77,0,102,80,1,36,80,0,176,33,
		0,48,34,0,95,1,112,0,89,25,0,1,0,1,
		0,1,0,48,18,0,95,1,112,0,48,18,0,95,
		255,112,0,8,6,12,2,165,80,2,121,15,28,89,
		36,81,0,48,13,0,95,1,112,0,100,69,28,29,
		36,82,0,176,42,0,48,17,0,48,13,0,95,1,
		112,0,112,0,48,18,0,95,1,112,0,20,2,36,
		84,0,176,43,0,48,34,0,95,1,112,0,95,2,
		20,2,36,85,0,176,44,0,48,34,0,95,1,112,
		0,176,45,0,48,34,0,95,1,112,0,12,1,122,
		49,20,2,36,88,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HTIMER_ONACTION )
{
	static const HB_BYTE pcode[] =
	{
		36,92,0,176,46,0,100,48,18,0,102,112,0,48,
		47,0,102,112,0,20,3,36,94,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( TIMERPROC )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,98,0,176,33,0,48,34,0,176,0,
		0,12,0,112,0,89,20,0,1,0,1,0,2,0,
		48,18,0,95,1,112,0,95,255,8,6,12,2,80,
		4,36,103,0,95,4,121,69,28,118,48,14,0,48,
		34,0,176,0,0,12,0,112,0,95,4,1,112,0,
		121,15,28,96,48,48,0,48,34,0,176,0,0,12,
		0,112,0,95,4,1,112,0,100,69,28,74,176,10,
		0,48,48,0,48,34,0,176,0,0,12,0,112,0,
		95,4,1,112,0,12,1,106,2,66,0,8,28,44,
		36,104,0,48,49,0,48,48,0,48,34,0,176,0,
		0,12,0,112,0,95,4,1,112,0,48,34,0,176,
		0,0,12,0,112,0,95,4,1,95,3,112,2,73,
		36,107,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_EXIT( CLEANTIMERS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,112,0,122,165,80,2,25,53,36,113,
		0,48,34,0,176,0,0,12,0,112,0,95,2,1,
		80,1,36,114,0,176,42,0,48,17,0,48,13,0,
		95,1,112,0,112,0,48,18,0,95,1,112,0,20,
		2,36,112,0,175,2,0,176,45,0,48,34,0,176,
		0,0,12,0,112,0,12,1,15,28,189,36,117,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,51,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

