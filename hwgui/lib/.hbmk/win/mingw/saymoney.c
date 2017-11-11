/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( SAYDOLLAR );
HB_FUNC_EXTERN( RIGHT );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( LEFT );
HB_FUNC( SAYRUPIAH );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( ABS );
HB_FUNC_EXTERN( INT );
HB_FUNC_STATIC( TIGADES );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_STATIC( BIL );
HB_FUNC_EXTERN( VAL );

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_SAYMONEY )
{ "SAYDOLLAR", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( SAYDOLLAR ) }, NULL },
{ "RIGHT", { HB_FS_PUBLIC }, { HB_FUNCNAME( RIGHT ) }, NULL },
{ "LTRIM", { HB_FS_PUBLIC }, { HB_FUNCNAME( LTRIM ) }, NULL },
{ "STR", { HB_FS_PUBLIC }, { HB_FUNCNAME( STR ) }, NULL },
{ "LEN", { HB_FS_PUBLIC }, { HB_FUNCNAME( LEN ) }, NULL },
{ "LEFT", { HB_FS_PUBLIC }, { HB_FUNCNAME( LEFT ) }, NULL },
{ "SAYRUPIAH", { HB_FS_PUBLIC | HB_FS_LOCAL }, { HB_FUNCNAME( SAYRUPIAH ) }, NULL },
{ "STRTRAN", { HB_FS_PUBLIC }, { HB_FUNCNAME( STRTRAN ) }, NULL },
{ "ABS", { HB_FS_PUBLIC }, { HB_FUNCNAME( ABS ) }, NULL },
{ "INT", { HB_FS_PUBLIC }, { HB_FUNCNAME( INT ) }, NULL },
{ "TIGADES", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( TIGADES ) }, NULL },
{ "SUBSTR", { HB_FS_PUBLIC }, { HB_FUNCNAME( SUBSTR ) }, NULL },
{ "BIL", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( BIL ) }, NULL },
{ "VAL", { HB_FS_PUBLIC }, { HB_FUNCNAME( VAL ) }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_SAYMONEY, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_SAYMONEY
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_SAYMONEY )
   #include "hbiniseg.h"
#endif

HB_FUNC( SAYDOLLAR )
{
	static const HB_BYTE pcode[] =
	{
		13,13,1,36,22,0,176,1,0,176,2,0,176,3,0,95,1,92,15,
		12,2,12,1,92,11,12,2,80,2,36,23,0,122,80,3,36,24,0,
		176,4,0,95,2,12,1,80,4,36,25,0,106,1,0,80,5,36,26,
		0,121,80,11,36,27,0,121,80,12,36,28,0,121,80,13,36,29,0,
		121,80,14,36,31,0,95,4,121,15,29,46,6,36,32,0,106,1,0,
		80,6,36,33,0,106,1,0,80,7,36,34,0,106,4,79,78,69,0,
		80,8,36,35,0,176,5,0,95,2,122,12,2,80,9,36,37,0,95,
		4,92,6,5,28,11,95,9,106,2,48,0,5,31,24,95,4,92,5,
		5,28,23,95,9,106,2,48,0,5,28,14,95,13,122,5,28,8,36,
		38,0,122,80,13,36,41,0,95,4,92,5,5,28,17,95,9,106,2,
		48,0,5,28,8,36,42,0,122,80,14,36,45,0,95,4,92,5,5,
		28,23,95,9,106,2,48,0,69,28,14,36,46,0,122,80,11,36,47,
		0,121,80,13,36,50,0,95,9,106,2,48,0,69,31,36,95,9,106,
		2,48,0,5,28,9,95,4,92,7,5,31,20,95,9,106,2,48,0,
		5,29,41,1,95,4,92,4,5,29,33,1,36,51,0,122,80,3,36,
		54,0,95,4,92,8,5,31,16,95,4,92,5,5,31,9,95,4,92,
		2,5,28,23,36,55,0,106,4,84,89,32,0,80,6,36,56,0,92,
		2,80,3,26,238,0,36,57,0,95,4,92,7,5,28,57,36,58,0,
		95,8,106,4,79,78,69,0,5,28,22,36,59,0,106,10,32,77,73,
		76,76,73,79,78,32,0,80,6,26,194,0,36,61,0,106,11,32,77,
		73,76,76,73,79,78,83,32,0,80,6,26,173,0,36,63,0,95,4,
		92,6,5,31,16,95,4,92,3,5,31,9,95,4,92,9,5,28,67,
		36,64,0,121,80,14,36,65,0,95,8,106,4,79,78,69,0,5,28,
		21,36,66,0,106,10,32,72,85,78,68,82,69,68,32,0,80,6,25,
		20,36,68,0,106,11,32,72,85,78,68,82,69,68,83,32,0,80,6,
		36,70,0,121,80,12,25,83,36,72,0,95,4,92,4,5,28,73,36,
		73,0,95,13,121,5,31,11,95,9,106,2,48,0,69,28,55,36,74,
		0,95,8,106,4,79,78,69,0,5,28,22,36,75,0,106,11,32,84,
		72,79,85,83,65,78,68,32,0,80,6,25,21,36,77,0,106,12,32,
		84,72,79,85,83,65,78,68,83,32,0,80,6,36,84,0,95,9,106,
		2,49,0,5,29,170,0,36,85,0,95,4,92,7,5,31,15,95,4,
		122,5,31,9,95,4,92,10,5,28,21,36,86,0,121,80,13,36,87,
		0,106,4,79,78,69,0,80,7,25,13,36,89,0,106,4,79,78,69,
		0,80,7,36,91,0,95,4,92,8,5,31,23,95,4,92,5,5,31,
		16,95,4,92,2,5,31,9,95,4,92,11,5,28,8,36,92,0,122,
		80,12,36,94,0,95,14,122,5,28,19,36,95,0,106,4,79,78,69,
		0,80,7,36,96,0,121,80,14,36,98,0,95,4,92,4,5,28,19,
		95,11,122,5,28,13,36,99,0,106,4,79,78,69,0,80,7,36,101,
		0,95,13,122,5,29,39,1,36,102,0,106,4,79,78,69,0,80,7,
		26,25,1,36,104,0,95,9,106,2,50,0,5,28,40,36,105,0,106,
		4,84,87,79,0,80,7,36,106,0,95,3,92,2,5,29,247,0,36,
		107,0,106,6,84,87,69,69,78,0,80,7,26,231,0,36,109,0,95,
		9,106,2,51,0,5,28,41,36,110,0,106,6,84,72,82,69,69,0,
		80,7,36,111,0,95,3,92,2,5,29,195,0,36,112,0,106,5,84,
		72,73,82,0,80,7,26,180,0,36,114,0,95,9,106,2,52,0,5,
		28,17,36,115,0,106,5,70,79,85,82,0,80,7,26,153,0,36,116,
		0,95,9,106,2,53,0,5,28,37,36,117,0,106,5,70,73,86,69,
		0,80,7,36,118,0,95,3,92,2,5,28,118,36,119,0,106,4,70,
		73,70,0,80,7,25,105,36,121,0,95,9,106,2,54,0,5,28,15,
		36,122,0,106,4,83,73,88,0,80,7,25,80,36,123,0,95,9,106,
		2,55,0,5,28,17,36,124,0,106,6,83,69,86,69,78,0,80,7,
		25,53,36,125,0,95,9,106,2,56,0,5,28,17,36,126,0,106,6,
		69,73,71,72,84,0,80,7,25,26,36,127,0,95,9,106,2,57,0,
		5,28,14,36,128,0,106,5,78,73,78,69,0,80,7,36,130,0,176,
		1,0,95,2,95,4,122,49,12,2,80,2,36,131,0,95,7,80,8,
		36,133,0,95,9,106,2,48,0,69,31,36,95,9,106,2,48,0,5,
		28,9,95,4,92,7,5,31,20,95,9,106,2,48,0,5,29,34,1,
		95,4,92,4,5,29,26,1,36,134,0,122,80,3,36,136,0,95,4,
		92,8,5,31,16,95,4,92,5,5,31,9,95,4,92,2,5,28,23,
		36,137,0,106,4,84,89,32,0,80,6,36,138,0,92,2,80,3,26,
		231,0,36,139,0,95,4,92,7,5,28,57,36,140,0,95,8,106,4,
		79,78,69,0,5,28,22,36,141,0,106,10,32,77,73,76,76,73,79,
		78,32,0,80,6,26,187,0,36,143,0,106,11,32,77,73,76,76,73,
		79,78,83,32,0,80,6,26,166,0,36,145,0,95,4,92,6,5,31,
		9,95,4,92,3,5,28,67,36,146,0,121,80,14,36,147,0,95,8,
		106,4,79,78,69,0,5,28,21,36,148,0,106,10,32,72,85,78,68,
		82,69,68,32,0,80,6,25,20,36,150,0,106,11,32,72,85,78,68,
		82,69,68,83,32,0,80,6,36,152,0,121,80,12,25,83,36,153,0,
		95,4,92,4,5,28,73,36,154,0,95,13,121,5,31,11,95,9,106,
		2,48,0,69,28,55,36,155,0,95,8,106,4,79,78,69,0,5,28,
		22,36,156,0,106,11,32,84,72,79,85,83,65,78,68,32,0,80,6,
		25,21,36,158,0,106,12,32,84,72,79,85,83,65,78,68,83,32,0,
		80,6,36,163,0,95,12,121,5,28,15,36,164,0,95,5,95,7,72,
		95,6,72,80,5,36,167,0,95,4,122,5,31,17,95,4,92,4,5,
		31,10,95,4,92,7,5,29,240,0,36,169,0,95,12,122,5,29,224,
		0,36,170,0,95,9,106,2,53,0,34,29,182,0,36,171,0,95,9,
		106,2,48,0,5,28,14,36,172,0,106,5,84,69,78,32,0,80,10,
		36,174,0,95,9,106,2,49,0,5,28,17,36,175,0,106,8,69,76,
		69,86,69,78,32,0,80,10,36,177,0,95,9,106,2,50,0,5,28,
		17,36,178,0,106,8,84,87,69,76,86,69,32,0,80,10,36,180,0,
		95,9,106,2,51,0,5,28,19,36,181,0,106,10,84,72,73,82,84,
		69,69,78,32,0,80,10,36,183,0,95,9,106,2,52,0,5,28,19,
		36,184,0,106,10,70,79,85,82,84,69,69,78,32,0,80,10,36,186,
		0,95,9,106,2,53,0,5,28,18,36,187,0,106,9,70,73,70,84,
		69,69,78,32,0,80,10,36,189,0,95,5,95,10,72,95,6,72,80,
		5,25,31,36,191,0,106,6,84,69,69,78,32,0,80,10,36,192,0,
		95,5,95,7,72,95,10,72,95,6,72,80,5,36,195,0,121,80,12,
		36,197,0,176,4,0,95,2,12,1,80,4,26,206,249,36,200,0,95,
		5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( SAYRUPIAH )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,210,0,95,1,121,35,28,13,106,7,77,105,110,117,115,
		32,0,25,5,106,1,0,80,4,36,211,0,176,7,0,176,3,0,176,
		8,0,176,9,0,95,1,12,1,12,1,92,15,12,2,106,2,32,0,
		106,2,48,0,12,3,80,5,36,213,0,122,165,80,2,26,137,0,36,
		214,0,96,4,0,176,10,0,176,11,0,95,5,95,2,92,3,65,92,
		2,49,92,3,12,3,95,2,12,2,135,36,215,0,176,11,0,95,5,
		95,2,92,3,65,92,2,49,92,3,12,3,106,4,48,48,48,0,8,
		28,7,106,1,0,25,54,106,9,84,82,73,76,73,85,78,32,0,106,
		8,77,73,76,89,65,82,32,0,106,6,74,85,84,65,32,0,106,6,
		82,73,66,85,32,0,106,7,82,85,80,73,65,72,0,4,5,0,95,
		2,1,80,3,36,216,0,96,4,0,95,3,135,36,213,0,175,2,0,
		92,5,15,29,119,255,36,219,0,106,2,48,0,176,1,0,176,3,0,
		95,1,92,18,92,2,12,3,92,2,12,2,72,80,5,36,221,0,96,
		4,0,95,5,106,4,48,48,48,0,69,28,29,106,7,32,107,111,109,
		97,32,0,176,10,0,95,5,122,12,2,72,106,4,115,101,110,0,72,
		25,5,106,1,0,135,36,223,0,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIGADES )
{
	static const HB_BYTE pcode[] =
	{
		13,4,2,36,229,0,106,1,0,80,3,176,5,0,95,1,122,12,2,
		80,4,176,11,0,95,1,92,2,122,12,3,80,5,176,1,0,95,1,
		122,12,2,80,6,36,231,0,95,2,92,4,8,28,20,95,1,106,4,
		48,48,49,0,8,28,9,106,3,115,101,0,110,7,36,232,0,95,1,
		106,4,48,48,48,0,8,28,7,106,1,0,110,7,36,234,0,95,4,
		106,2,48,0,8,31,55,36,235,0,95,4,106,2,49,0,8,28,19,
		96,3,0,106,9,83,69,82,65,84,85,83,32,0,135,25,26,36,236,
		0,96,3,0,176,12,0,95,4,12,1,106,7,82,65,84,85,83,32,
		0,72,135,36,239,0,95,5,106,2,48,0,8,28,16,96,3,0,176,
		12,0,95,6,12,1,135,26,131,0,36,240,0,95,5,106,2,49,0,
		8,28,86,36,241,0,95,6,106,2,48,0,8,28,19,96,3,0,106,
		9,83,69,80,85,76,85,72,32,0,135,25,89,36,242,0,95,6,106,
		2,49,0,8,28,19,96,3,0,106,9,83,69,66,69,76,65,83,32,
		0,135,25,60,36,243,0,96,3,0,176,12,0,95,6,12,1,106,7,
		66,69,76,65,83,32,0,72,135,25,34,36,245,0,96,3,0,176,12,
		0,95,5,12,1,106,7,80,85,76,85,72,32,0,72,176,12,0,95,
		6,12,1,72,135,36,248,0,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( BIL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,255,0,95,1,106,2,48,0,69,28,91,106,5,83,65,
		84,85,0,106,4,68,85,65,0,106,5,84,73,71,65,0,106,6,69,
		77,80,65,84,0,106,5,76,73,77,65,0,106,5,69,78,65,77,0,
		106,6,84,85,74,85,72,0,106,8,68,69,76,65,80,65,78,0,106,
		9,83,69,77,66,73,76,65,78,0,4,9,0,176,13,0,95,1,12,
		1,1,106,2,32,0,72,25,5,106,1,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}
