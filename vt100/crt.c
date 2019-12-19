/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Console.h"
#include "Platform.h"
#include "Strings.h"
#include "vt100.h"


static CHAR crt_tmpstr[23];


export void crt_ClrEol (void);
export void crt_ClrScr (void);
export void crt_DelLine (void);
export void crt_Delay (INT16 ms);
export void crt_EraseDisplay (void);
export void crt_GotoXY (INT16 x, INT16 y);
export void crt_HighVideo (void);
export void crt_InsLine (void);
export void crt_LowVideo (void);
export void crt_NormVideo (void);
export void crt_TextBackground (INT8 color);
export void crt_TextColor (INT8 color);
export void crt_cursoroff (void);
export void crt_cursoron (void);


void crt_EraseDisplay (void)
{
	vt100_ED(2);
}

void crt_ClrScr (void)
{
	vt100_ED(2);
}

void crt_ClrEol (void)
{
	vt100_EL(0);
}

void crt_cursoroff (void)
{
	vt100_DECTCEMl();
}

void crt_cursoron (void)
{
	vt100_DECTCEMh();
}

void crt_Delay (INT16 ms)
{
	Platform_Delay(ms);
}

void crt_GotoXY (INT16 x, INT16 y)
{
	vt100_CUP(y, x);
}

void crt_HighVideo (void)
{
	CHAR tmpstr[5];
	__COPY(vt100_CSI, tmpstr, 5);
	Strings_Append((CHAR*)"1m", 3, (void*)tmpstr, 5);
	Console_String(tmpstr, 5);
}

void crt_DelLine (void)
{
	vt100_EL(2);
}

void crt_InsLine (void)
{
	vt100_SCP();
	Console_Ln();
	vt100_RCP();
}

void crt_LowVideo (void)
{
	CHAR tmpstr[7];
	__COPY(vt100_CSI, tmpstr, 7);
	Strings_Append((CHAR*)"21m", 4, (void*)tmpstr, 7);
	Console_String(tmpstr, 7);
}

void crt_NormVideo (void)
{
	CHAR tmpstr[7];
	__COPY(vt100_CSI, tmpstr, 7);
	Strings_Append((CHAR*)"0m", 3, (void*)tmpstr, 7);
	Console_String(tmpstr, 7);
}

void crt_TextBackground (INT8 color)
{
	if (color == 0) {
		vt100_SetAttr((CHAR*)"40m", 4);
	} else if (color == 1) {
		vt100_SetAttr((CHAR*)"44m", 4);
	} else if (color == 2) {
		vt100_SetAttr((CHAR*)"42m", 4);
	} else if (color == 3) {
		vt100_SetAttr((CHAR*)"46m", 4);
	} else if (color == 4) {
		vt100_SetAttr((CHAR*)"41m", 4);
	} else if (color == 5) {
		vt100_SetAttr((CHAR*)"45m", 4);
	} else if (color == 6) {
		vt100_SetAttr((CHAR*)"43m", 4);
	} else if (color == 7) {
		vt100_SetAttr((CHAR*)"47m", 4);
	} else if (color == 8) {
		vt100_SetAttr((CHAR*)"100m", 5);
	} else if (color == 9) {
		vt100_SetAttr((CHAR*)"104m", 5);
	} else if (color == 10) {
		vt100_SetAttr((CHAR*)"104m", 5);
	} else if (color == 11) {
		vt100_SetAttr((CHAR*)"106m", 5);
	} else if (color == 12) {
		vt100_SetAttr((CHAR*)"101m", 5);
	} else if (color == 13) {
		vt100_SetAttr((CHAR*)"105m", 5);
	} else if (color == 14) {
		vt100_SetAttr((CHAR*)"103m", 5);
	} else if (color == 15) {
		vt100_SetAttr((CHAR*)"107m", 5);
	}
}

void crt_TextColor (INT8 color)
{
	if (color == 0) {
		vt100_SetAttr((CHAR*)"30m", 4);
	} else if (color == 1) {
		vt100_SetAttr((CHAR*)"34m", 4);
	} else if (color == 2) {
		vt100_SetAttr((CHAR*)"32m", 4);
	} else if (color == 3) {
		vt100_SetAttr((CHAR*)"36m", 4);
	} else if (color == 4) {
		vt100_SetAttr((CHAR*)"31m", 4);
	} else if (color == 5) {
		vt100_SetAttr((CHAR*)"35m", 4);
	} else if (color == 6) {
		vt100_SetAttr((CHAR*)"33m", 4);
	} else if (color == 7) {
		vt100_SetAttr((CHAR*)"37m", 4);
	} else if (color == 8) {
		vt100_SetAttr((CHAR*)"90m", 4);
	} else if (color == 9) {
		vt100_SetAttr((CHAR*)"94m", 4);
	} else if (color == 10) {
		vt100_SetAttr((CHAR*)"94m", 4);
	} else if (color == 11) {
		vt100_SetAttr((CHAR*)"96m", 4);
	} else if (color == 12) {
		vt100_SetAttr((CHAR*)"91m", 4);
	} else if (color == 13) {
		vt100_SetAttr((CHAR*)"95m", 4);
	} else if (color == 14) {
		vt100_SetAttr((CHAR*)"93m", 4);
	} else if (color == 15) {
		vt100_SetAttr((CHAR*)"97m", 4);
	}
}


export void *crt__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(Console);
	__MODULE_IMPORT(Platform);
	__MODULE_IMPORT(Strings);
	__MODULE_IMPORT(vt100);
	__REGMOD("crt", 0);
	__REGCMD("ClrEol", crt_ClrEol);
	__REGCMD("ClrScr", crt_ClrScr);
	__REGCMD("DelLine", crt_DelLine);
	__REGCMD("EraseDisplay", crt_EraseDisplay);
	__REGCMD("HighVideo", crt_HighVideo);
	__REGCMD("InsLine", crt_InsLine);
	__REGCMD("LowVideo", crt_LowVideo);
	__REGCMD("NormVideo", crt_NormVideo);
	__REGCMD("cursoroff", crt_cursoroff);
	__REGCMD("cursoron", crt_cursoron);
/* BEGIN */
	__ENDMOD;
}
