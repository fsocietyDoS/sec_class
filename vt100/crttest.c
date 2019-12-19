/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspamM */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Console.h"
#include "Strings.h"
#include "crt.h"
#include "vt100.h"


static CHAR crttest_tmpstr[32];





export int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__MODULE_IMPORT(Console);
	__MODULE_IMPORT(Strings);
	__MODULE_IMPORT(crt);
	__MODULE_IMPORT(vt100);
	__REGMAIN("crttest", 0);
/* BEGIN */
	crt_EraseDisplay();
	crt_GotoXY(0, 0);
	__COPY(vt100_CSI, crttest_tmpstr, 32);
	Strings_Append((CHAR*)"33m", 4, (void*)crttest_tmpstr, 32);
	Strings_Append(vt100_CSI, 5, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"5m", 3, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"hello", 6, (void*)crttest_tmpstr, 32);
	Strings_Append(vt100_CSI, 5, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"0m", 3, (void*)crttest_tmpstr, 32);
	Console_String(crttest_tmpstr, 32);
	Console_Ln();
	Console_Ln();
	__COPY(vt100_CSI, crttest_tmpstr, 32);
	Strings_Append((CHAR*)"41m", 4, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"            ", 13, (void*)crttest_tmpstr, 32);
	Console_String(crttest_tmpstr, 32);
	Console_Ln();
	__COPY(vt100_CSI, crttest_tmpstr, 32);
	Strings_Append((CHAR*)"44m", 4, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"            ", 13, (void*)crttest_tmpstr, 32);
	Console_String(crttest_tmpstr, 32);
	Console_Ln();
	__COPY(vt100_CSI, crttest_tmpstr, 32);
	Strings_Append((CHAR*)"43m", 4, (void*)crttest_tmpstr, 32);
	Strings_Append((CHAR*)"            ", 13, (void*)crttest_tmpstr, 32);
	Console_String(crttest_tmpstr, 32);
	Console_Ln();
	__COPY(vt100_CSI, crttest_tmpstr, 32);
	Strings_Append((CHAR*)"0m", 3, (void*)crttest_tmpstr, 32);
	Console_String(crttest_tmpstr, 32);
	Console_Ln();
	crt_HighVideo();
	Console_String((CHAR*)"high video", 11);
	Console_Ln();
	Console_Ln();
	crt_LowVideo();
	Console_String((CHAR*)"low video", 10);
	Console_Ln();
	crt_TextColor(4);
	Console_String((CHAR*)"red", 4);
	Console_Ln();
	crt_TextColor(2);
	Console_String((CHAR*)"green", 6);
	Console_Ln();
	crt_TextBackground(14);
	crt_TextColor(1);
	Console_String((CHAR*)"blue on yellow", 15);
	Console_Ln();
	Console_Ln();
	Console_Ln();
	crt_Delay(2000);
	__FINI;
}
