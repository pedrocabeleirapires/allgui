/* C source generated by Harbour */

#include "hbvmpub.h"
#include "hbinit.h"

HB_FUNC( HWINPRN );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HOBJECT );
HB_FUNC_STATIC( HWINPRN_NEW );
HB_FUNC_STATIC( HWINPRN_INITVALUES );
HB_FUNC_STATIC( HWINPRN_SETMODE );
HB_FUNC_STATIC( HWINPRN_STARTDOC );
HB_FUNC_STATIC( HWINPRN_NEXTPAGE );
HB_FUNC_STATIC( HWINPRN_PRINTLINE );
HB_FUNC_STATIC( HWINPRN_PRINTTEXT );
HB_FUNC_STATIC( HWINPRN_PUTCODE );
HB_FUNC_STATIC( HWINPRN_ENDDOC );
HB_FUNC_STATIC( HWINPRN_END );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HPRINTER );
HB_FUNC_EXTERN( REPLICATE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( HB_TRANSLATE );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HWINPRN )
{ "HWINPRN", { HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN ) }, NULL },
{ "__CLSLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSLOCKDEF ) }, NULL },
{ "NEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HBCLASS", { HB_FS_PUBLIC }, { HB_FUNCNAME( HBCLASS ) }, NULL },
{ "HOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( HOBJECT ) }, NULL },
{ "ADDMULTICLSDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMULTIDATA", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDMETHOD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HWINPRN_NEW", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_NEW ) }, NULL },
{ "HWINPRN_INITVALUES", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_INITVALUES ) }, NULL },
{ "HWINPRN_SETMODE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_SETMODE ) }, NULL },
{ "HWINPRN_STARTDOC", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_STARTDOC ) }, NULL },
{ "HWINPRN_NEXTPAGE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_NEXTPAGE ) }, NULL },
{ "HWINPRN_PRINTLINE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_PRINTLINE ) }, NULL },
{ "HWINPRN_PRINTTEXT", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_PRINTTEXT ) }, NULL },
{ "HWINPRN_PUTCODE", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_PUTCODE ) }, NULL },
{ "HWINPRN_ENDDOC", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_ENDDOC ) }, NULL },
{ "HWINPRN_END", { HB_FS_STATIC | HB_FS_LOCAL }, { HB_FUNCNAME( HWINPRN_END ) }, NULL },
{ "CREATE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__CLSUNLOCKDEF", { HB_FS_PUBLIC }, { HB_FUNCNAME( __CLSUNLOCKDEF ) }, NULL },
{ "INSTANCE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "__OBJHASMSG", { HB_FS_PUBLIC }, { HB_FUNCNAME( __OBJHASMSG ) }, NULL },
{ "INITCLASS", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_OPRINTER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HPRINTER", { HB_FS_PUBLIC }, { HB_FUNCNAME( HPRINTER ) }, NULL },
{ "OPRINTER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_CPFROM", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_CPTO", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LELITE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LCOND", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NLINEINCH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LBOLD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LITALIC", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LUNDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LCHANGED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "INITVALUES", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LPAGESTART", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NSTDHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CPRINTERNAME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NSTDHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_CPRINTERNAME", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHRES", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ADDFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NVRES", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SETFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "GETTEXTWIDTH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "REPLICATE", { HB_FS_PUBLIC }, { HB_FUNCNAME( REPLICATE ) }, NULL },
{ "RELEASE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LELITE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LCOND", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NLINEHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NLINED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLINEINCH", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLINEHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LBOLD", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LITALIC", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LUNDER", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_OFONT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_NCHARW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LDOCSTART", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STARTDOC", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NEXTPAGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LDOCSTART", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "ENDPAGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LPAGESTART", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "STARTPAGE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SETMODE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_Y", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NTOP", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLINED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_LFIRSTLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "Y", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NHEIGHT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "_X", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NLEFT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LFIRSTLINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "EMPTY", { HB_FS_PUBLIC }, { HB_FUNCNAME( EMPTY ) }, NULL },
{ "LEN", { HB_FS_PUBLIC }, { HB_FUNCNAME( LEN ) }, NULL },
{ "SUBSTR", { HB_FS_PUBLIC }, { HB_FUNCNAME( SUBSTR ) }, NULL },
{ "PRINTTEXT", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "PUTCODE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "AT", { HB_FS_PUBLIC }, { HB_FUNCNAME( AT ) }, NULL },
{ "LINE", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "X", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "NCHARW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LCHANGED", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "SAY", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CPFROM", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "CPTO", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "HB_TRANSLATE", { HB_FS_PUBLIC }, { HB_FUNCNAME( HB_TRANSLATE ) }, NULL },
{ "LEFT", { HB_FS_PUBLIC }, { HB_FUNCNAME( LEFT ) }, NULL },
{ "ENDDOC", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "LPREVIEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "PREVIEW", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "END", { HB_FS_PUBLIC | HB_FS_MESSAGE }, { NULL }, NULL },
{ "(_INITSTATICS00003)", { HB_FS_INITEXIT | HB_FS_LOCAL }, { hb_INITSTATICS }, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HWINPRN, "", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HWINPRN
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HWINPRN )
   #include "hbiniseg.h"
#endif

HB_FUNC( HWINPRN )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,97,0,36,26,0,103,2,0,100,8,29,216,4,176,1,
		0,104,2,0,12,1,29,205,4,166,143,4,0,122,80,1,48,2,0,
		176,3,0,12,0,106,8,72,87,105,110,80,114,110,0,108,4,4,1,
		0,108,0,112,3,80,2,36,28,0,48,5,0,95,2,100,100,95,1,
		121,72,92,32,72,121,72,121,72,106,11,110,83,116,100,72,101,105,103,
		104,116,0,4,1,0,9,112,5,73,36,29,0,48,5,0,95,2,100,
		100,95,1,121,72,92,32,72,121,72,121,72,106,13,99,80,114,105,110,
		116,101,114,78,97,109,101,0,4,1,0,9,112,5,73,36,30,0,48,
		6,0,95,2,100,100,95,1,121,72,121,72,121,72,106,9,111,80,114,
		105,110,116,101,114,0,4,1,0,9,112,5,73,36,31,0,48,6,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,6,111,70,111,110,116,
		0,4,1,0,9,112,5,73,36,32,0,48,6,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,12,110,76,105,110,101,72,101,105,103,104,
		116,0,106,7,110,76,105,110,101,100,0,4,2,0,9,112,5,73,36,
		33,0,48,6,0,95,2,100,100,95,1,121,72,121,72,121,72,106,7,
		110,67,104,97,114,87,0,4,1,0,9,112,5,73,36,34,0,48,6,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,2,120,0,106,2,
		121,0,4,2,0,9,112,5,73,36,35,0,48,6,0,95,2,100,9,
		95,1,121,72,121,72,121,72,106,7,108,69,108,105,116,101,0,4,1,
		0,9,112,5,73,36,36,0,48,6,0,95,2,100,9,95,1,121,72,
		121,72,121,72,106,6,108,67,111,110,100,0,4,1,0,9,112,5,73,
		36,37,0,48,6,0,95,2,100,92,6,95,1,121,72,121,72,121,72,
		106,10,110,76,105,110,101,73,110,99,104,0,4,1,0,9,112,5,73,
		36,38,0,48,6,0,95,2,100,9,95,1,121,72,121,72,121,72,106,
		6,108,66,111,108,100,0,4,1,0,9,112,5,73,36,39,0,48,6,
		0,95,2,100,9,95,1,121,72,121,72,121,72,106,8,108,73,116,97,
		108,105,99,0,4,1,0,9,112,5,73,36,40,0,48,6,0,95,2,
		100,9,95,1,121,72,121,72,121,72,106,7,108,85,110,100,101,114,0,
		4,1,0,9,112,5,73,36,41,0,48,6,0,95,2,100,9,95,1,
		121,72,121,72,121,72,106,9,108,67,104,97,110,103,101,100,0,4,1,
		0,9,112,5,73,36,43,0,48,6,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,7,99,112,70,114,111,109,0,106,5,99,112,84,111,
		0,4,2,0,9,112,5,73,36,44,0,48,6,0,95,2,100,92,5,
		95,1,121,72,121,72,121,72,106,5,110,84,111,112,0,4,1,0,9,
		112,5,73,36,45,0,48,6,0,95,2,100,92,5,95,1,121,72,121,
		72,121,72,106,8,110,66,111,116,116,111,109,0,4,1,0,9,112,5,
		73,36,46,0,48,6,0,95,2,100,92,5,95,1,121,72,121,72,121,
		72,106,6,110,76,101,102,116,0,4,1,0,9,112,5,73,36,47,0,
		48,6,0,95,2,100,92,5,95,1,121,72,121,72,121,72,106,7,110,
		82,105,103,104,116,0,4,1,0,9,112,5,73,36,50,0,48,7,0,
		95,2,106,4,78,101,119,0,108,8,95,1,121,72,121,72,121,72,112,
		3,73,36,51,0,48,7,0,95,2,106,11,73,110,105,116,86,97,108,
		117,101,115,0,108,9,95,1,121,72,121,72,121,72,112,3,73,36,52,
		0,48,7,0,95,2,106,8,83,101,116,77,111,100,101,0,108,10,95,
		1,121,72,121,72,121,72,112,3,73,36,53,0,48,7,0,95,2,106,
		9,83,116,97,114,116,68,111,99,0,108,11,95,1,121,72,121,72,121,
		72,112,3,73,36,54,0,48,7,0,95,2,106,9,78,101,120,116,80,
		97,103,101,0,108,12,95,1,121,72,121,72,121,72,112,3,73,36,55,
		0,48,7,0,95,2,106,10,80,114,105,110,116,76,105,110,101,0,108,
		13,95,1,121,72,121,72,121,72,112,3,73,36,56,0,48,7,0,95,
		2,106,10,80,114,105,110,116,84,101,120,116,0,108,14,95,1,121,72,
		121,72,121,72,112,3,73,36,57,0,48,7,0,95,2,106,8,80,117,
		116,67,111,100,101,0,108,15,95,1,121,72,121,72,121,72,112,3,73,
		36,58,0,48,7,0,95,2,106,7,69,110,100,68,111,99,0,108,16,
		95,1,121,72,121,72,121,72,112,3,73,36,59,0,48,7,0,95,2,
		106,4,69,110,100,0,108,17,95,1,121,72,121,72,121,72,112,3,73,
		36,61,0,92,4,80,1,36,62,0,48,6,0,95,2,100,9,95,1,
		121,72,121,72,121,72,106,10,108,68,111,99,83,116,97,114,116,0,4,
		1,0,9,112,5,73,36,63,0,48,6,0,95,2,100,9,95,1,121,
		72,121,72,121,72,106,11,108,80,97,103,101,83,116,97,114,116,0,4,
		1,0,9,112,5,73,36,64,0,48,6,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,11,108,70,105,114,115,116,76,105,110,101,0,4,
		1,0,9,112,5,73,36,66,0,48,18,0,95,2,112,0,73,167,14,
		0,0,176,19,0,104,2,0,95,2,20,2,168,48,20,0,95,2,112,
		0,80,3,176,21,0,95,3,106,10,73,110,105,116,67,108,97,115,115,
		0,12,2,28,12,48,22,0,95,3,164,146,1,0,73,95,3,110,7,
		48,20,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,7,36,70,0,48,23,0,102,48,2,0,176,24,0,12,0,95,
		1,100,8,28,7,106,1,0,25,4,95,1,9,95,4,95,5,95,6,
		95,7,112,6,112,1,73,36,71,0,48,25,0,102,112,0,100,8,28,
		8,36,72,0,100,110,7,36,74,0,48,26,0,102,95,2,112,1,73,
		36,75,0,48,27,0,102,95,3,112,1,73,36,77,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_INITVALUES )
{
	static const HB_BYTE pcode[] =
	{
		13,0,6,36,81,0,95,1,100,69,28,11,48,28,0,102,95,1,112,
		1,73,36,82,0,95,2,100,69,28,11,48,29,0,102,95,2,112,1,
		73,36,83,0,95,3,100,69,28,11,48,30,0,102,95,3,112,1,73,
		36,84,0,95,4,100,69,28,11,48,31,0,102,95,4,112,1,73,36,
		85,0,95,5,100,69,28,11,48,32,0,102,95,5,112,1,73,36,86,
		0,95,6,100,69,28,11,48,33,0,102,95,6,112,1,73,36,87,0,
		48,34,0,102,120,112,1,73,36,89,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_SETMODE )
{
	static const HB_BYTE pcode[] =
	{
		13,6,6,36,95,0,106,15,76,117,99,105,100,97,32,67,111,110,115,
		111,108,101,0,80,7,36,97,0,122,101,133,235,81,184,30,133,243,63,
		10,2,101,92,143,194,245,40,92,251,63,10,2,92,2,4,4,0,80,
		8,36,98,0,121,80,9,36,100,0,48,35,0,102,95,1,95,2,95,
		3,95,4,95,5,95,6,112,6,73,36,102,0,48,36,0,102,112,0,
		29,45,2,36,104,0,48,37,0,102,112,0,100,8,31,23,48,38,0,
		102,112,0,48,38,0,48,25,0,102,112,0,112,0,69,29,242,0,36,
		105,0,48,39,0,102,92,4,112,1,73,36,106,0,48,40,0,102,48,
		38,0,48,25,0,102,112,0,112,0,112,1,73,36,107,0,48,41,0,
		48,25,0,102,112,0,112,0,48,42,0,48,25,0,102,112,0,112,0,
		18,92,10,49,80,12,36,108,0,95,12,93,210,0,15,31,10,95,12,
		93,190,0,35,28,10,36,109,0,93,200,0,80,12,36,114,0,48,43,
		0,48,25,0,102,112,0,95,7,48,37,0,102,112,0,48,44,0,48,
		25,0,102,112,0,112,0,65,112,2,80,10,36,116,0,48,45,0,48,
		25,0,102,112,0,95,10,112,1,73,36,117,0,48,46,0,48,25,0,
		102,112,0,176,47,0,106,2,65,0,92,80,12,2,112,1,48,42,0,
		48,25,0,102,112,0,112,0,18,80,11,36,118,0,95,11,95,12,92,
		2,72,15,31,12,95,11,95,12,92,15,49,35,28,24,36,119,0,48,
		39,0,102,48,37,0,102,112,0,95,12,95,11,18,65,112,1,73,36,
		121,0,48,48,0,95,10,112,0,73,36,124,0,48,49,0,102,112,0,
		28,5,174,9,0,36,125,0,48,50,0,102,112,0,28,6,126,9,2,
		0,36,127,0,48,51,0,102,48,37,0,102,112,0,95,8,95,9,122,
		72,1,18,48,44,0,48,25,0,102,112,0,112,0,65,112,1,73,36,
		128,0,48,52,0,102,101,102,102,102,102,102,102,57,64,10,1,48,44,
		0,48,25,0,102,112,0,112,0,65,48,53,0,102,112,0,18,48,54,
		0,102,112,0,49,112,1,73,36,136,0,48,43,0,48,25,0,102,112,
		0,106,15,76,117,99,105,100,97,32,67,111,110,115,111,108,101,0,48,
		54,0,102,112,0,48,55,0,102,112,0,48,56,0,102,112,0,48,57,
		0,102,112,0,93,204,0,112,6,80,10,36,139,0,48,58,0,102,112,
		0,100,69,28,17,36,140,0,48,48,0,48,58,0,102,112,0,112,0,
		73,36,142,0,48,59,0,102,95,10,112,1,73,36,144,0,48,45,0,
		48,25,0,102,112,0,48,58,0,102,112,0,112,1,73,36,145,0,48,
		60,0,102,48,46,0,48,25,0,102,112,0,106,11,65,66,67,68,69,
		70,71,72,73,74,0,112,1,92,10,18,112,1,73,36,146,0,48,34,
		0,102,9,112,1,73,36,150,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_STARTDOC )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,154,0,48,61,0,102,120,112,1,73,36,155,0,48,62,
		0,48,25,0,102,112,0,95,1,95,2,112,2,73,36,156,0,48,63,
		0,102,112,0,73,36,158,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_NEXTPAGE )
{
	static const HB_BYTE pcode[] =
	{
		36,162,0,48,64,0,102,112,0,31,8,36,163,0,100,110,7,36,165,
		0,48,36,0,102,112,0,28,17,36,166,0,48,65,0,48,25,0,102,
		112,0,112,0,73,36,169,0,48,66,0,102,120,112,1,73,36,170,0,
		48,67,0,48,25,0,102,112,0,112,0,73,36,172,0,48,58,0,102,
		112,0,100,8,28,14,36,173,0,48,68,0,102,112,0,73,25,23,36,
		175,0,48,45,0,48,25,0,102,112,0,48,58,0,102,112,0,112,1,
		73,36,178,0,48,69,0,102,48,70,0,102,112,0,48,44,0,48,25,
		0,102,112,0,112,0,65,48,54,0,102,112,0,49,48,71,0,102,112,
		0,49,112,1,73,36,179,0,48,72,0,102,120,112,1,73,36,181,0,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_PRINTLINE )
{
	static const HB_BYTE pcode[] =
	{
		13,5,2,116,97,0,36,186,0,48,64,0,102,112,0,31,12,36,187,
		0,48,62,0,102,112,0,73,36,190,0,48,73,0,102,112,0,92,2,
		48,54,0,102,112,0,48,71,0,102,112,0,72,65,72,48,74,0,48,
		25,0,102,112,0,112,0,15,28,12,36,191,0,48,63,0,102,112,0,
		73,36,193,0,48,75,0,102,48,76,0,102,112,0,48,42,0,48,25,
		0,102,112,0,112,0,65,112,1,73,36,194,0,48,77,0,102,112,0,
		28,15,36,195,0,48,72,0,102,9,112,1,73,25,47,36,196,0,95,
		2,100,8,31,6,95,2,28,34,36,197,0,48,69,0,102,21,48,73,
		0,163,0,112,0,48,54,0,102,112,0,48,71,0,102,112,0,72,72,
		112,1,73,36,200,0,95,1,100,69,29,156,7,176,78,0,95,1,12,
		1,32,146,7,36,201,0,176,79,0,95,1,12,1,80,6,36,202,0,
		122,80,3,36,203,0,121,80,4,36,204,0,95,3,95,6,34,29,78,
		7,36,205,0,176,80,0,95,1,95,3,122,12,3,165,80,7,106,2,
		32,0,35,28,65,36,206,0,95,4,121,69,28,32,36,207,0,48,81,
		0,102,176,80,0,95,1,95,4,95,3,95,4,49,12,3,112,1,73,
		36,208,0,121,80,4,36,210,0,96,3,0,48,82,0,102,176,80,0,
		95,1,95,3,12,2,112,1,135,25,161,36,212,0,176,83,0,95,7,
		103,1,0,12,2,165,80,5,121,69,29,202,6,36,213,0,95,4,121,
		69,28,32,36,214,0,48,81,0,102,176,80,0,95,1,95,4,95,3,
		95,4,49,12,3,112,1,73,36,215,0,121,80,4,36,217,0,95,5,
		92,3,35,29,155,0,36,218,0,95,3,80,4,36,219,0,95,3,95,
		6,34,28,25,176,80,0,95,1,95,3,122,12,3,95,7,8,28,10,
		36,220,0,174,3,0,25,225,36,222,0,48,84,0,48,25,0,102,112,
		0,48,85,0,102,112,0,48,73,0,102,112,0,48,54,0,102,112,0,
		92,2,18,72,48,85,0,102,112,0,95,3,95,4,49,48,86,0,102,
		112,0,65,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,
		72,112,4,73,36,223,0,48,75,0,102,21,48,85,0,163,0,112,0,
		95,3,95,4,49,48,86,0,102,112,0,65,72,112,1,73,36,224,0,
		121,80,4,26,195,254,36,227,0,95,5,92,5,35,28,78,36,228,0,
		48,84,0,48,25,0,102,112,0,48,85,0,102,112,0,48,86,0,102,
		112,0,92,2,18,72,48,73,0,102,112,0,48,85,0,102,112,0,48,
		86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,
		112,0,72,48,71,0,102,112,0,72,112,4,73,26,143,5,36,229,0,
		95,5,92,9,35,29,165,0,36,230,0,48,84,0,48,25,0,102,112,
		0,48,85,0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,
		0,102,112,0,48,54,0,102,112,0,92,2,18,72,48,85,0,102,112,
		0,48,86,0,102,112,0,72,48,73,0,102,112,0,48,54,0,102,112,
		0,92,2,18,72,112,4,73,36,231,0,48,84,0,48,25,0,102,112,
		0,48,85,0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,
		0,102,112,0,48,54,0,102,112,0,92,2,18,72,48,85,0,102,112,
		0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,54,
		0,102,112,0,72,48,71,0,102,112,0,72,112,4,73,26,226,4,36,
		232,0,95,5,92,13,35,29,158,0,36,233,0,48,84,0,48,25,0,
		102,112,0,48,85,0,102,112,0,48,73,0,102,112,0,48,54,0,102,
		112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,0,92,
		2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,72,
		112,4,73,36,234,0,48,84,0,48,25,0,102,112,0,48,85,0,102,
		112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,
		54,0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,
		112,0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,72,
		48,71,0,102,112,0,72,112,4,73,26,60,4,36,235,0,95,5,92,
		17,35,29,151,0,36,236,0,48,84,0,48,25,0,102,112,0,48,85,
		0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,
		0,48,54,0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,
		0,102,112,0,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,
		18,72,112,4,73,36,237,0,48,84,0,48,25,0,102,112,0,48,85,
		0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,
		0,48,85,0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,
		0,102,112,0,48,54,0,102,112,0,92,2,18,72,112,4,73,26,157,
		3,36,238,0,95,5,92,21,35,29,144,0,36,239,0,48,84,0,48,
		25,0,102,112,0,48,85,0,102,112,0,48,73,0,102,112,0,48,54,
		0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,
		0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,
		18,72,112,4,73,36,240,0,48,84,0,48,25,0,102,112,0,48,85,
		0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,
		0,48,85,0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,
		0,102,112,0,48,54,0,102,112,0,92,2,18,72,112,4,73,26,5,
		3,36,241,0,95,5,92,25,35,29,155,0,36,242,0,48,84,0,48,
		25,0,102,112,0,48,85,0,102,112,0,48,73,0,102,112,0,48,54,
		0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,
		0,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,72,112,
		4,73,36,243,0,48,84,0,48,25,0,102,112,0,48,85,0,102,112,
		0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,54,
		0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,
		0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,72,48,
		71,0,102,112,0,72,112,4,73,26,98,2,36,244,0,95,5,92,29,
		35,29,141,0,36,245,0,48,84,0,48,25,0,102,112,0,48,85,0,
		102,112,0,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,72,
		48,85,0,102,112,0,48,86,0,102,112,0,72,48,73,0,102,112,0,
		48,54,0,102,112,0,92,2,18,72,112,4,73,36,246,0,48,84,0,
		48,25,0,102,112,0,48,85,0,102,112,0,48,86,0,102,112,0,92,
		2,18,72,48,73,0,102,112,0,48,85,0,102,112,0,48,86,0,102,
		112,0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,92,
		2,18,72,112,4,73,26,205,1,36,247,0,95,5,92,33,35,29,155,
		0,36,248,0,48,84,0,48,25,0,102,112,0,48,85,0,102,112,0,
		48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,54,0,
		102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,0,
		72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,72,112,4,
		73,36,249,0,48,84,0,48,25,0,102,112,0,48,85,0,102,112,0,
		48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,48,85,0,
		102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,0,
		48,54,0,102,112,0,72,48,71,0,102,112,0,72,112,4,73,26,42,
		1,36,250,0,95,5,92,37,35,29,148,0,36,251,0,48,84,0,48,
		25,0,102,112,0,48,85,0,102,112,0,48,73,0,102,112,0,48,54,
		0,102,112,0,92,2,18,72,48,85,0,102,112,0,48,86,0,102,112,
		0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,92,2,
		18,72,112,4,73,36,252,0,48,84,0,48,25,0,102,112,0,48,85,
		0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,0,102,112,
		0,48,85,0,102,112,0,48,86,0,102,112,0,92,2,18,72,48,73,
		0,102,112,0,48,54,0,102,112,0,72,48,71,0,102,112,0,72,112,
		4,73,26,142,0,36,254,0,48,84,0,48,25,0,102,112,0,48,85,
		0,102,112,0,48,73,0,102,112,0,48,54,0,102,112,0,92,2,18,
		72,48,85,0,102,112,0,48,86,0,102,112,0,72,48,73,0,102,112,
		0,48,54,0,102,112,0,92,2,18,72,112,4,73,36,255,0,48,84,
		0,48,25,0,102,112,0,48,85,0,102,112,0,48,86,0,102,112,0,
		92,2,18,72,48,73,0,102,112,0,48,85,0,102,112,0,48,86,0,
		102,112,0,92,2,18,72,48,73,0,102,112,0,48,54,0,102,112,0,
		72,48,71,0,102,112,0,72,112,4,73,36,1,1,48,75,0,102,21,
		48,85,0,163,0,112,0,48,86,0,102,112,0,72,112,1,73,25,18,
		36,4,1,95,4,121,8,28,9,36,5,1,95,3,80,4,36,8,1,
		174,3,0,26,173,248,36,10,1,95,4,121,69,28,26,36,11,1,48,
		81,0,102,176,80,0,95,1,95,4,95,3,95,4,49,12,3,112,1,
		73,36,15,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_PRINTTEXT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,19,1,48,87,0,102,112,0,28,12,36,20,1,48,68,
		0,102,112,0,73,36,23,1,48,88,0,48,25,0,102,112,0,48,89,
		0,102,112,0,48,90,0,102,112,0,69,28,23,176,91,0,95,1,48,
		89,0,102,112,0,48,90,0,102,112,0,12,3,25,4,95,1,48,85,
		0,102,112,0,48,73,0,102,112,0,48,41,0,48,25,0,102,112,0,
		112,0,48,73,0,102,112,0,48,54,0,102,112,0,72,48,71,0,102,
		112,0,72,112,5,73,36,24,1,48,75,0,102,21,48,85,0,163,0,
		112,0,48,86,0,102,112,0,176,79,0,95,1,12,1,65,72,112,1,
		73,36,26,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_PUTCODE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,116,97,0,36,43,1,176,79,0,103,3,0,12,1,80,3,
		176,92,0,95,1,122,12,2,80,4,36,45,1,122,165,80,2,26,138,
		0,36,46,1,176,92,0,103,3,0,95,2,1,122,1,122,12,2,95,
		4,8,28,109,176,83,0,103,3,0,95,2,1,122,1,176,92,0,95,
		1,92,3,12,2,12,2,122,8,28,83,36,47,1,48,35,0,102,103,
		3,0,95,2,1,92,2,1,103,3,0,95,2,1,92,3,1,103,3,
		0,95,2,1,92,4,1,103,3,0,95,2,1,92,5,1,103,3,0,
		95,2,1,92,6,1,103,3,0,95,2,1,92,7,1,112,6,73,36,
		48,1,176,79,0,103,3,0,95,2,1,122,1,20,1,7,36,45,1,
		175,2,0,95,3,15,29,118,255,36,52,1,122,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_ENDDOC )
{
	static const HB_BYTE pcode[] =
	{
		36,56,1,48,36,0,102,112,0,28,28,36,57,1,48,65,0,48,25,
		0,102,112,0,112,0,73,36,58,1,48,66,0,102,9,112,1,73,36,
		60,1,48,64,0,102,112,0,28,82,36,61,1,48,93,0,48,25,0,
		102,112,0,112,0,73,36,62,1,48,61,0,102,9,112,1,73,36,63,
		1,176,21,0,48,25,0,102,112,0,106,8,80,82,69,86,73,69,87,
		0,12,2,28,30,48,94,0,48,25,0,102,112,0,112,0,28,17,36,
		64,1,48,95,0,48,25,0,102,112,0,112,0,73,36,68,1,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HWINPRN_END )
{
	static const HB_BYTE pcode[] =
	{
		36,72,1,48,93,0,102,112,0,73,36,73,1,48,48,0,48,58,0,
		102,112,0,112,0,73,36,74,1,48,96,0,48,25,0,102,112,0,112,
		0,73,36,75,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,97,0,3,0,116,97,0,106,41,196,205,179,186,218,201,213,214,191,
		187,183,184,192,200,211,212,217,188,189,190,194,203,209,210,193,202,207,208,
		195,204,198,199,180,185,181,182,197,206,215,216,0,82,1,0,106,3,27,
		64,0,9,9,92,6,9,9,9,4,7,0,106,3,27,77,0,120,100,
		100,100,100,100,4,7,0,106,2,15,0,100,120,100,100,100,100,4,7,
		0,106,2,18,0,100,9,100,100,100,100,4,7,0,106,3,27,48,0,
		100,100,92,8,100,100,100,4,7,0,106,3,27,50,0,100,100,92,6,
		100,100,100,4,7,0,106,4,27,45,49,0,100,100,100,100,100,120,4,
		7,0,106,4,27,45,48,0,100,100,100,100,100,9,4,7,0,106,3,
		27,52,0,100,100,100,100,120,100,4,7,0,106,3,27,53,0,100,100,
		100,100,9,100,4,7,0,106,3,27,71,0,100,100,100,100,120,100,4,
		7,0,106,3,27,72,0,100,100,100,9,100,100,4,7,0,4,12,0,
		82,3,0,7
	};

	hb_vmExecute( pcode, symbols );
}
