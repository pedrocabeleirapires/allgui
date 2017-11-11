/*
 * Harbour 3.2.0dev (r1310312321)
 * Microsoft Visual C 16.0.40219 (32-bit)
 * Generated C source from "source\procmisc\scrdebug.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HWG_SCRDEBUG );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HFONT );
HB_FUNC_EXTERN( HBITMAP );
HB_FUNC_EXTERN( HDIALOG );
HB_FUNC_STATIC( DLGDEBUGCLOSE );
HB_FUNC_EXTERN( HWG_BEGINMENU );
HB_FUNC_EXTERN( HWG_DEFINEMENUITEM );
HB_FUNC_EXTERN( SETDEBUGRUN );
HB_FUNC_EXTERN( HWG_ENDMENU );
HB_FUNC_EXTERN( HBROWSE );
HB_FUNC_EXTERN( HCOLUMN );
HB_FUNC_EXTERN( HSPLITTER );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_STATIC( ADDBREAKPOINT );
HB_FUNC_EXTERN( HPANEL );
HB_FUNC_EXTERN( HBUTTON );
HB_FUNC_STATIC( ADDWATCH );
HB_FUNC_STATIC( CALCULATE );
HB_FUNC_EXTERN( HEDIT );
HB_FUNC_EXTERN( HWG_SETWINDOWTEXT );
HB_FUNC_STATIC( CALCWATCH );
HB_FUNC_EXTERN( SECONDS );
HB_FUNC_EXTERN( HWG_PROCESSMESSAGE );
HB_FUNC_EXTERN( SETDEBUGGER );
HB_FUNC_EXTERN( ADEL );
HB_FUNC_EXTERN( HWG_GETEDITTEXT );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_STATIC( MACROERROR );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( BREAK );
HB_FUNC( SCRBREAKPOINT );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_SCRDEBUG )
{ "HWG_SCRDEBUG", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_SCRDEBUG )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ADD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HFONT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HFONT )}, NULL },
{ "ADDSTANDARD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBITMAP )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( HDIALOG )}, NULL },
{ "DLGDEBUGCLOSE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( DLGDEBUGCLOSE )}, NULL },
{ "HWG_BEGINMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BEGINMENU )}, NULL },
{ "HWG_DEFINEMENUITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_DEFINEMENUITEM )}, NULL },
{ "CLOSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETDEBUGRUN", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETDEBUGRUN )}, NULL },
{ "HWG_ENDMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_ENDMENU )}, NULL },
{ "HBROWSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBROWSE )}, NULL },
{ "MOVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AARRAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCOLUMN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HCOLUMN", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCOLUMN )}, NULL },
{ "AARRAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCURRENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HSPLITTER", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSPLITTER )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "_ABITMAPS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACOLUMNS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEFT )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "_BENTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDBREAKPOINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADDBREAKPOINT )}, NULL },
{ "HPANEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HPANEL )}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBUTTON )}, NULL },
{ "ADDWATCH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADDWATCH )}, NULL },
{ "CALCULATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CALCULATE )}, NULL },
{ "HEDIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HEDIT )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_SETWINDOWTEXT )}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CALCWATCH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CALCWATCH )}, NULL },
{ "REFRESH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ROWPOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCURRENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ROWCOUNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ROWPOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SECONDS", {HB_FS_PUBLIC}, {HB_FUNCNAME( SECONDS )}, NULL },
{ "HWG_PROCESSMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_PROCESSMESSAGE )}, NULL },
{ "SETDEBUGGER", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETDEBUGGER )}, NULL },
{ "RELEASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADEL )}, NULL },
{ "HWG_GETEDITTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_GETEDITTEXT )}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "MACROERROR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( MACROERROR )}, NULL },
{ "SETTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "BREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( BREAK )}, NULL },
{ "SCRBREAKPOINT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SCRBREAKPOINT )}, NULL },
{ "(_INITSTATICS00019)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_SCRDEBUG, "source\\procmisc\\scrdebug.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_SCRDEBUG
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_SCRDEBUG )
   #include "hbiniseg.h"
#endif

HB_FUNC( HWG_SCRDEBUG )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,116,68,0,36,28,0,176,1,0,95,1,
		12,1,92,3,35,28,8,36,29,0,9,110,7,36,
		30,0,176,1,0,95,1,12,1,92,3,8,28,13,
		36,31,0,176,2,0,95,1,100,20,2,36,33,0,
		176,3,0,95,1,92,4,1,12,1,28,20,36,34,
		0,104,19,0,170,36,35,0,103,19,0,95,1,92,
		4,2,36,37,0,103,18,0,100,8,28,10,36,38,
		0,95,1,82,18,0,36,41,0,103,1,0,100,8,
		29,178,6,95,2,121,15,29,171,6,36,43,0,48,
		4,0,176,5,0,12,0,106,8,71,101,111,114,103,
		105,97,0,121,92,241,100,93,204,0,112,5,82,10,
		0,36,44,0,48,4,0,176,5,0,12,0,106,12,
		67,111,117,114,105,101,114,32,78,101,119,0,121,92,
		241,100,93,204,0,112,5,82,11,0,36,46,0,48,
		6,0,176,7,0,12,0,93,229,127,112,1,82,12,
		0,36,47,0,48,6,0,176,7,0,12,0,93,248,
		127,112,1,82,13,0,36,51,0,48,8,0,176,9,
		0,12,0,92,11,128,0,0,204,144,0,0,0,0,
		93,210,0,92,10,93,244,1,93,44,1,106,19,83,
		99,114,105,112,116,32,68,101,98,117,103,103,101,114,
		32,45,32,0,95,1,122,1,72,103,10,0,100,89,
		13,0,1,0,0,0,176,10,0,12,0,6,100,100,
		100,100,100,9,100,100,9,100,100,9,100,100,9,112,
		25,82,1,0,36,53,0,176,11,0,103,1,0,100,
		100,100,100,100,20,6,36,54,0,176,12,0,106,6,
		69,38,120,105,116,0,47,100,90,11,48,13,0,103,
		1,0,112,0,6,9,100,100,100,9,9,20,9,36,
		55,0,176,12,0,106,6,38,83,116,101,112,0,47,
		100,90,12,121,82,8,0,176,14,0,12,0,6,9,
		100,100,100,9,9,20,9,36,56,0,176,11,0,100,
		100,106,9,38,65,110,105,109,97,116,101,0,47,100,
		100,100,20,6,36,57,0,176,12,0,106,13,38,48,
		46,53,32,115,101,99,111,110,100,115,0,100,90,26,
		101,0,0,0,0,0,0,224,63,10,1,82,14,0,
		122,82,8,0,176,14,0,12,0,6,9,100,100,100,
		9,9,20,9,36,58,0,176,12,0,106,11,38,49,
		32,115,101,99,111,110,100,115,0,100,90,16,122,82,
		14,0,122,82,8,0,176,14,0,12,0,6,9,100,
		100,100,9,9,20,9,36,59,0,176,12,0,106,11,
		38,51,32,115,101,99,111,110,100,115,0,100,90,17,
		92,3,82,14,0,122,82,8,0,176,14,0,12,0,
		6,9,100,100,100,9,9,20,9,36,60,0,176,15,
		0,20,0,36,61,0,176,12,0,106,5,38,82,117,
		110,0,47,100,90,13,92,2,82,8,0,176,14,0,
		12,0,6,9,100,100,100,9,9,20,9,36,62,0,
		176,15,0,20,0,36,65,0,48,8,0,176,16,0,
		12,0,122,100,100,97,0,0,160,0,121,121,93,244,
		1,121,100,100,89,19,0,3,0,0,0,48,17,0,
		95,1,100,100,95,2,112,3,6,100,100,100,100,9,
		9,9,9,100,100,100,9,9,100,100,100,100,100,100,
		100,100,100,100,112,34,82,2,0,48,18,0,103,2,
		0,106,9,111,66,114,119,68,97,116,97,0,112,1,
		73,36,67,0,48,19,0,103,2,0,103,17,0,112,
		1,73,36,68,0,48,20,0,103,2,0,48,8,0,
		176,21,0,12,0,106,1,0,89,25,0,2,0,0,
		0,48,22,0,95,2,112,0,48,23,0,95,2,112,
		0,1,122,1,6,106,2,67,0,92,30,121,112,5,
		112,1,73,36,69,0,48,20,0,103,2,0,48,8,
		0,176,21,0,12,0,106,1,0,89,26,0,2,0,
		0,0,48,22,0,95,2,112,0,48,23,0,95,2,
		112,0,1,92,3,1,6,106,2,67,0,122,121,112,
		5,112,1,73,36,70,0,48,20,0,103,2,0,48,
		8,0,176,21,0,12,0,106,1,0,89,26,0,2,
		0,0,0,48,22,0,95,2,112,0,48,23,0,95,
		2,112,0,1,92,4,1,6,106,2,67,0,92,60,
		121,112,5,112,1,73,36,73,0,48,8,0,176,16,
		0,12,0,122,100,100,97,0,0,176,0,121,92,4,
		93,244,1,93,236,0,103,11,0,100,89,42,0,3,
		0,0,0,48,17,0,95,1,100,100,95,2,95,3,
		48,24,0,103,4,0,112,0,49,48,25,0,103,4,
		0,112,0,49,92,64,49,112,4,6,100,100,100,100,
		9,9,9,9,100,100,100,9,9,100,100,100,100,100,
		100,100,100,100,100,112,34,82,3,0,48,18,0,103,
		3,0,106,11,111,66,114,119,83,99,114,105,112,116,
		0,112,1,73,36,76,0,48,8,0,176,26,0,12,
		0,100,100,121,121,93,88,2,92,3,89,19,0,3,
		0,0,0,48,17,0,95,1,100,100,95,2,112,3,
		6,100,100,100,103,2,0,4,1,0,103,3,0,4,
		1,0,9,9,112,14,82,4,0,48,18,0,103,4,
		0,106,7,111,83,112,108,105,116,0,112,1,73,36,
		78,0,48,19,0,103,3,0,95,1,92,3,1,112,
		1,73,36,83,0,48,20,0,103,3,0,48,8,0,
		176,21,0,12,0,106,1,0,89,59,0,2,0,0,
		0,48,23,0,95,2,112,0,103,9,0,8,28,5,
		122,25,37,103,15,0,100,69,28,29,176,27,0,103,
		15,0,92,2,1,48,23,0,103,3,0,112,0,12,
		2,121,69,28,6,92,2,25,3,121,6,106,2,78,
		0,122,121,112,5,112,1,73,36,84,0,48,28,0,
		48,29,0,103,3,0,112,0,122,1,89,12,0,1,
		0,0,0,95,1,122,8,6,103,12,0,4,2,0,
		89,13,0,1,0,0,0,95,1,92,2,8,6,103,
		13,0,4,2,0,4,2,0,112,1,73,36,86,0,
		48,20,0,103,3,0,48,8,0,176,21,0,12,0,
		106,1,0,89,30,0,2,0,0,0,176,30,0,48,
		22,0,95,2,112,0,48,23,0,95,2,112,0,1,
		92,4,12,2,6,106,2,67,0,92,4,121,112,5,
		112,1,73,36,87,0,48,20,0,103,3,0,48,8,
		0,176,21,0,12,0,106,1,0,89,30,0,2,0,
		0,0,176,31,0,48,22,0,95,2,112,0,48,23,
		0,95,2,112,0,1,92,6,12,2,6,106,2,67,
		0,92,80,121,112,5,112,1,73,36,89,0,48,32,
		0,103,3,0,90,8,176,33,0,12,0,6,112,1,
		73,36,92,0,48,8,0,176,34,0,12,0,103,1,
		0,100,100,121,93,240,0,48,35,0,103,1,0,112,
		0,92,64,100,89,23,0,3,0,0,0,48,17,0,
		95,1,100,95,3,92,64,49,95,2,112,3,6,100,
		100,112,11,82,5,0,48,18,0,103,5,0,106,7,
		111,80,97,110,101,108,0,112,1,73,36,98,0,48,
		8,0,176,36,0,12,0,103,5,0,100,100,92,10,
		92,10,92,100,92,24,106,4,65,100,100,0,100,100,
		100,100,90,8,176,37,0,12,0,6,100,100,100,112,
		16,73,36,99,0,48,8,0,176,36,0,12,0,103,
		5,0,100,100,92,10,92,36,92,100,92,24,106,10,
		67,97,108,99,117,108,97,116,101,0,100,100,100,100,
		90,8,176,38,0,12,0,6,100,100,100,112,16,73,
		36,101,0,48,8,0,176,39,0,12,0,103,5,0,
		100,106,1,0,100,100,92,110,92,10,93,124,1,92,
		24,100,100,89,22,0,3,0,0,0,48,17,0,95,
		1,100,100,95,2,92,120,49,112,3,6,100,100,100,
		100,100,100,100,9,100,9,100,100,100,112,25,82,6,
		0,48,18,0,103,6,0,106,10,111,69,100,105,116,
		69,120,112,114,0,112,1,73,36,102,0,48,8,0,
		176,39,0,12,0,103,5,0,100,106,1,0,100,100,
		92,110,92,36,93,124,1,92,24,100,100,89,22,0,
		3,0,0,0,48,17,0,95,1,100,100,95,2,92,
		120,49,112,3,6,100,100,100,100,100,100,100,9,100,
		9,100,100,100,112,25,82,7,0,48,18,0,103,7,
		0,106,9,111,69,100,105,116,82,101,115,0,112,1,
		73,36,104,0,48,40,0,103,1,0,120,100,100,112,
		3,73,36,106,0,48,17,0,103,1,0,100,100,100,
		93,144,1,112,4,73,36,109,0,103,18,0,92,4,
		1,95,1,92,4,1,69,29,175,0,36,110,0,176,
		3,0,103,15,0,12,1,31,111,36,111,0,176,27,
		0,103,16,0,89,18,0,1,0,0,0,95,1,122,
		1,103,15,0,122,1,8,6,12,2,165,80,4,121,
		8,28,16,36,112,0,176,2,0,103,16,0,103,15,
		0,20,2,36,114,0,176,27,0,103,16,0,89,20,
		0,1,0,1,0,1,0,95,1,122,1,95,255,92,
		4,1,8,6,12,2,165,80,4,121,8,28,11,36,
		115,0,100,82,15,0,25,14,36,117,0,103,16,0,
		95,4,1,82,15,0,36,120,0,95,1,82,18,0,
		36,121,0,176,41,0,48,42,0,103,1,0,112,0,
		106,19,83,99,114,105,112,116,32,68,101,98,117,103,
		103,101,114,32,45,32,0,95,1,122,1,72,20,2,
		36,124,0,48,19,0,103,3,0,95,1,92,3,1,
		112,1,73,36,125,0,95,2,165,82,9,0,121,8,
		28,24,36,126,0,121,82,8,0,36,127,0,48,43,
		0,103,3,0,112,0,73,26,42,1,36,129,0,103,
		15,0,100,69,28,27,176,27,0,103,15,0,92,2,
		1,103,9,0,12,2,121,69,28,9,36,130,0,121,
		82,8,0,36,132,0,103,8,0,92,2,35,29,232,
		0,36,133,0,122,165,80,4,25,18,36,134,0,176,
		44,0,95,4,20,1,36,133,0,175,4,0,176,1,
		0,103,17,0,12,1,15,28,231,36,136,0,176,3,
		0,103,17,0,12,1,31,14,36,137,0,48,45,0,
		103,2,0,112,0,73,36,139,0,48,23,0,103,3,
		0,112,0,48,46,0,103,3,0,112,0,49,122,72,
		80,3,36,140,0,48,47,0,103,3,0,103,9,0,
		112,1,73,36,141,0,103,9,0,95,3,49,48,48,
		0,103,3,0,112,0,16,28,17,36,142,0,48,49,
		0,103,3,0,122,112,1,73,25,27,36,144,0,48,
		49,0,103,3,0,48,23,0,103,3,0,112,0,95,
		3,49,122,72,112,1,73,36,146,0,48,45,0,103,
		3,0,112,0,73,36,147,0,103,8,0,122,8,28,
		68,36,148,0,176,50,0,12,0,80,3,36,149,0,
		176,50,0,12,0,95,3,49,103,14,0,35,28,12,
		36,150,0,176,51,0,20,0,25,231,36,152,0,176,
		14,0,20,0,25,21,36,154,0,103,8,0,92,2,
		8,28,10,36,155,0,176,14,0,20,0,36,159,0,
		120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( DLGDEBUGCLOSE )
{
	static const HB_BYTE pcode[] =
	{
		116,68,0,36,163,0,100,82,1,0,36,164,0,176,
		52,0,9,20,1,36,165,0,176,14,0,20,0,36,
		166,0,100,165,82,18,0,82,15,0,36,167,0,4,
		0,0,82,16,0,36,168,0,4,0,0,82,17,0,
		36,169,0,48,53,0,103,11,0,112,0,73,36,170,
		0,48,53,0,103,10,0,112,0,73,36,172,0,48,
		53,0,103,12,0,112,0,73,36,173,0,48,53,0,
		103,13,0,112,0,73,36,176,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ADDBREAKPOINT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,116,68,0,36,181,0,103,15,0,100,8,
		28,20,36,182,0,103,18,0,92,4,1,4,0,0,
		4,2,0,82,15,0,36,184,0,176,27,0,103,15,
		0,92,2,1,48,23,0,103,3,0,112,0,12,2,
		165,80,1,121,8,28,112,36,185,0,122,165,80,1,
		25,46,36,186,0,103,15,0,92,2,1,95,1,1,
		121,8,28,24,36,187,0,48,23,0,103,3,0,112,
		0,103,15,0,92,2,1,95,1,2,25,22,36,185,
		0,175,1,0,176,1,0,103,15,0,92,2,1,12,
		1,15,28,200,36,191,0,95,1,176,1,0,103,15,
		0,92,2,1,12,1,15,28,64,36,192,0,176,2,
		0,103,15,0,92,2,1,48,23,0,103,3,0,112,
		0,20,2,25,40,36,195,0,176,54,0,103,15,0,
		92,2,1,95,1,20,2,36,196,0,121,103,15,0,
		92,2,1,176,1,0,103,15,0,92,2,1,12,1,
		2,36,198,0,48,45,0,103,3,0,112,0,73,36,
		199,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ADDWATCH )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,116,68,0,36,202,0,120,80,4,36,207,
		0,176,3,0,176,55,0,48,42,0,48,56,0,103,
		6,0,112,0,112,0,48,57,0,103,6,0,112,0,
		12,2,165,80,1,12,1,31,80,36,209,0,176,58,
		0,89,15,0,1,0,0,0,176,59,0,95,1,12,
		1,6,12,1,80,3,36,210,0,113,29,0,0,36,
		211,0,106,4,123,124,124,0,95,1,72,106,2,125,
		0,72,40,11,80,2,114,15,0,0,36,212,0,115,
		73,36,213,0,9,80,4,36,215,0,176,58,0,95,
		3,20,1,36,218,0,95,4,29,204,0,36,219,0,
		176,27,0,103,17,0,89,17,0,1,0,1,0,1,
		0,95,1,122,1,95,255,8,6,12,2,121,8,28,
		38,36,220,0,176,2,0,103,17,0,95,1,95,2,
		100,100,4,4,0,20,2,36,221,0,176,44,0,176,
		1,0,103,17,0,12,1,20,1,36,223,0,48,25,
		0,103,2,0,112,0,92,20,35,28,105,36,224,0,
		48,17,0,103,4,0,100,92,56,112,2,73,36,225,
		0,48,17,0,103,3,0,100,92,60,100,48,25,0,
		103,1,0,112,0,48,24,0,103,4,0,112,0,49,
		48,25,0,103,4,0,112,0,49,92,64,49,112,4,
		73,36,226,0,48,17,0,103,2,0,100,100,100,92,
		56,112,4,73,36,227,0,48,17,0,103,1,0,100,
		100,100,48,25,0,103,1,0,112,0,92,4,72,112,
		4,73,36,229,0,48,45,0,103,2,0,112,0,73,
		25,25,36,231,0,48,60,0,103,7,0,106,9,69,
		114,114,111,114,46,46,46,0,112,1,73,36,233,0,
		120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CALCWATCH )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,116,68,0,36,236,0,120,80,4,36,238,
		0,176,58,0,89,15,0,1,0,0,0,176,59,0,
		95,1,12,1,6,12,1,80,3,36,239,0,113,27,
		0,0,36,240,0,48,61,0,103,17,0,95,1,1,
		92,2,1,112,0,80,2,114,15,0,0,36,241,0,
		115,73,36,242,0,9,80,4,36,244,0,176,58,0,
		95,3,20,1,36,246,0,95,4,29,195,0,36,247,
		0,176,62,0,95,2,12,1,165,80,5,106,2,78,
		0,8,28,29,36,248,0,176,63,0,176,64,0,95,
		2,12,1,12,1,103,17,0,95,1,1,92,4,2,
		26,132,0,36,249,0,95,5,106,2,68,0,8,28,
		23,36,250,0,176,65,0,95,2,12,1,103,17,0,
		95,1,1,92,4,2,25,98,36,251,0,95,5,106,
		2,76,0,8,28,34,36,252,0,95,2,28,10,106,
		4,46,84,46,0,25,8,106,4,46,70,46,0,103,
		17,0,95,1,1,92,4,2,25,54,36,253,0,95,
		5,106,2,67,0,8,28,18,36,254,0,95,2,103,
		17,0,95,1,1,92,4,2,25,26,36,0,1,106,
		10,85,110,100,101,102,105,110,101,100,0,103,17,0,
		95,1,1,92,4,2,36,2,1,95,5,103,17,0,
		95,1,1,92,3,2,25,41,36,4,1,106,9,69,
		114,114,111,114,46,46,46,0,103,17,0,95,1,1,
		92,4,2,36,5,1,106,2,85,0,103,17,0,95,
		1,1,92,3,2,36,8,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CALCULATE )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,116,68,0,36,11,1,120,80,3,36,16,
		1,176,3,0,176,55,0,48,42,0,48,56,0,103,
		6,0,112,0,112,0,48,57,0,103,6,0,112,0,
		12,2,165,80,1,12,1,31,68,36,18,1,176,58,
		0,89,15,0,1,0,0,0,176,59,0,95,1,12,
		1,6,12,1,80,2,36,19,1,113,17,0,0,36,
		20,1,95,1,40,11,80,1,114,15,0,0,36,21,
		1,115,73,36,22,1,9,80,3,36,24,1,176,58,
		0,95,2,20,1,36,27,1,95,3,29,142,0,36,
		28,1,176,62,0,95,1,12,1,165,80,4,106,2,
		78,0,8,28,28,36,29,1,48,60,0,103,7,0,
		176,63,0,176,64,0,95,1,12,1,12,1,112,1,
		73,25,118,36,30,1,95,4,106,2,68,0,8,28,
		23,36,31,1,48,60,0,103,7,0,176,65,0,95,
		1,12,1,112,1,73,25,85,36,32,1,95,4,106,
		2,76,0,8,28,34,36,33,1,48,60,0,103,7,
		0,95,1,28,10,106,4,46,84,46,0,25,8,106,
		4,46,70,46,0,112,1,73,25,41,36,35,1,48,
		60,0,103,7,0,95,1,112,1,73,25,25,36,38,
		1,48,60,0,103,7,0,106,9,69,114,114,111,114,
		46,46,46,0,112,1,73,36,41,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( MACROERROR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,44,1,176,66,0,20,0,36,45,1,
		120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( SCRBREAKPOINT )
{
	static const HB_BYTE pcode[] =
	{
		116,68,0,36,48,1,121,82,8,0,36,49,1,120,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,68,0,19,0,116,68,0,100,82,1,0,121,82,
		8,0,121,82,9,0,4,0,0,82,16,0,4,0,
		0,82,17,0,121,82,19,0,7
	};

	hb_vmExecute( pcode, symbols );
}

