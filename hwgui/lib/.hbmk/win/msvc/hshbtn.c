/*
 * Harbour 3.2.0dev (r1310312321)
 * Microsoft Visual C 16.0.40219 (32-bit)
 * Generated C source from "source\hshbtn.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HSHADEBUTTON );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HOWNBUTTON );
HB_FUNC_STATIC( HSHADEBUTTON_NEW );
HB_FUNC_STATIC( HSHADEBUTTON_PAINT );
HB_FUNC_STATIC( HSHADEBUTTON_END );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_SHADE_NEW );
HB_FUNC_EXTERN( HWG_SHADE_SET );
HB_FUNC_EXTERN( HWG_DEFINEPAINTSTRU );
HB_FUNC_EXTERN( HWG_BEGINPAINT );
HB_FUNC_EXTERN( HWG_GETFOCUS );
HB_FUNC_EXTERN( HWG_SHADE_DRAW );
HB_FUNC_EXTERN( HWG_ENDPAINT );
HB_FUNC_EXTERN( HWG_SHADE_RELEASE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HSHBTN )
{ "HSHADEBUTTON", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HSHADEBUTTON )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HOWNBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HOWNBUTTON )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HSHADEBUTTON_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSHADEBUTTON_NEW )}, NULL },
{ "HSHADEBUTTON_PAINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSHADEBUTTON_PAINT )}, NULL },
{ "HSHADEBUTTON_END", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HSHADEBUTTON_END )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HSHADE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SHADE_NEW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SHADE_NEW )}, NULL },
{ "HWG_SHADE_SET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SHADE_SET )}, NULL },
{ "HSHADE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_DEFINEPAINTSTRU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DEFINEPAINTSTRU )}, NULL },
{ "HWG_BEGINPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BEGINPAINT )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_STATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LENABLED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_GETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETFOCUS )}, NULL },
{ "HWG_SHADE_DRAW", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SHADE_DRAW )}, NULL },
{ "DRAWITEMS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_ENDPAINT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ENDPAINT )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SHADE_RELEASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SHADE_RELEASE )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HSHBTN, "source\\hshbtn.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HSHBTN
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HSHBTN )
   #include "hbiniseg.h"
#endif

HB_FUNC( HSHADEBUTTON )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,32,0,36,21,0,103,1,0,100,8,
		29,242,0,176,1,0,104,1,0,12,1,29,231,0,
		166,169,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,13,72,83,104,97,100,101,66,117,116,116,111,
		110,0,108,4,4,1,0,108,0,112,3,80,2,36,
		23,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,7,104,83,104,97,100,101,0,4,1,
		0,9,112,5,73,36,30,0,48,6,0,95,2,106,
		4,78,101,119,0,108,7,95,1,121,72,121,72,121,
		72,112,3,73,36,31,0,48,6,0,95,2,106,6,
		80,97,105,110,116,0,108,8,95,1,121,72,121,72,
		121,72,112,3,73,36,32,0,48,6,0,95,2,106,
		4,69,78,68,0,108,9,95,1,121,72,121,72,121,
		72,112,3,73,36,34,0,48,10,0,95,2,112,0,
		73,167,14,0,0,176,11,0,104,1,0,95,2,20,
		2,168,48,12,0,95,2,112,0,80,3,176,13,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,14,0,95,3,164,146,1,0,73,
		95,3,110,7,48,12,0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSHADEBUTTON_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,33,36,47,0,48,2,0,48,15,0,102,112,
		0,95,1,95,2,95,3,95,4,95,5,95,6,95,
		7,95,8,95,9,95,10,95,11,95,12,95,13,95,
		14,95,15,95,16,95,17,100,100,95,18,95,19,95,
		20,95,21,95,22,95,23,95,24,95,25,95,26,95,
		27,112,29,73,36,49,0,48,16,0,102,176,17,0,
		121,121,95,6,95,7,95,12,12,5,112,1,73,36,
		50,0,176,18,0,48,19,0,102,112,0,95,28,95,
		29,95,30,95,31,95,32,95,33,20,7,36,52,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSHADEBUTTON_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,58,0,176,20,0,12,0,80,1,36,
		59,0,176,21,0,48,22,0,102,112,0,95,1,12,
		2,80,2,36,61,0,48,23,0,102,112,0,121,8,
		28,13,36,62,0,48,24,0,102,122,112,1,73,36,
		65,0,48,25,0,102,112,0,28,62,36,68,0,48,
		23,0,102,112,0,92,3,8,28,6,92,2,25,20,
		122,48,23,0,102,112,0,92,2,8,28,6,92,8,
		25,3,121,72,176,26,0,12,0,48,22,0,102,112,
		0,8,28,6,92,4,25,3,121,72,80,3,25,9,
		36,70,0,92,16,80,3,36,73,0,176,27,0,48,
		19,0,102,112,0,95,2,95,3,20,3,36,75,0,
		48,28,0,102,95,2,112,1,73,36,77,0,176,29,
		0,48,22,0,102,112,0,95,1,20,2,36,79,0,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HSHADEBUTTON_END )
{
	static const HB_BYTE pcode[] =
	{
		36,83,0,48,30,0,48,15,0,102,112,0,112,0,
		73,36,84,0,176,31,0,48,19,0,102,112,0,20,
		1,36,86,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,32,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

