/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Console.h"
#include "Strings.h"


export CHAR vt100_CSI[5];
static CHAR vt100_tmpstr[32];


export void vt100_CHA (INT16 n);
export void vt100_CNL (INT16 n);
export void vt100_CPL (INT16 n);
export void vt100_CUB (INT16 n);
export void vt100_CUD (INT16 n);
export void vt100_CUF (INT16 n);
export void vt100_CUP (INT16 n, INT16 m);
export void vt100_CUU (INT16 n);
export void vt100_DECTCEMh (void);
export void vt100_DECTCEMl (void);
export void vt100_DSR (INT16 n);
export void vt100_ED (INT16 n);
export void vt100_EL (INT16 n);
static void vt100_EscSeq (INT16 n, CHAR *letter, ADDRESS letter__len);
static void vt100_EscSeq0 (CHAR *letter, ADDRESS letter__len);
static void vt100_EscSeq2 (INT16 n, INT16 m, CHAR *letter, ADDRESS letter__len);
static void vt100_EscSeqSwapped (INT16 n, CHAR *letter, ADDRESS letter__len);
export void vt100_HVP (INT16 n, INT16 m);
export void vt100_IntToStr (INT32 int_, CHAR *str, ADDRESS str__len);
export void vt100_RCP (void);
static void vt100_Reverse0 (CHAR *str, ADDRESS str__len, INT16 start, INT16 end);
export void vt100_SCP (void);
export void vt100_SD (INT16 n);
export void vt100_SGR (INT16 n);
export void vt100_SGR2 (INT16 n, INT16 m);
export void vt100_SU (INT16 n);
export void vt100_SetAttr (CHAR *attr, ADDRESS attr__len);


static void vt100_Reverse0 (CHAR *str, ADDRESS str__len, INT16 start, INT16 end)
{
	CHAR h;
	while (start < end) {
		h = str[__X(start, str__len)];
		str[__X(start, str__len)] = str[__X(end, str__len)];
		str[__X(end, str__len)] = h;
		start += 1;
		end -= 1;
	}
}

void vt100_IntToStr (INT32 int_, CHAR *str, ADDRESS str__len)
{
	CHAR b[21];
	INT16 s, e;
	INT8 maxLength;
	maxLength = 11;
	if (int_ == (-2147483647-1)) {
		__MOVE("-2147483648", b, 12);
		e = 11;
	} else {
		if (int_ < 0) {
			b[0] = '-';
			int_ = -int_;
			s = 1;
		} else {
			s = 0;
		}
		e = s;
		do {
			b[__X(e, 21)] = (CHAR)((int)__MOD(int_, 10) + 48);
			int_ = __DIV(int_, 10);
			e += 1;
		} while (!(int_ == 0));
		b[__X(e, 21)] = 0x00;
		vt100_Reverse0((void*)b, 21, s, e - 1);
	}
	__COPY(b, str, str__len);
}

static void vt100_EscSeq0 (CHAR *letter, ADDRESS letter__len)
{
	CHAR cmd[9];
	__DUP(letter, letter__len, CHAR);
	__COPY(vt100_CSI, cmd, 9);
	Strings_Append(letter, letter__len, (void*)cmd, 9);
	Console_String(cmd, 9);
	__DEL(letter);
}

static void vt100_EscSeq (INT16 n, CHAR *letter, ADDRESS letter__len)
{
	CHAR nstr[2];
	CHAR cmd[7];
	__DUP(letter, letter__len, CHAR);
	vt100_IntToStr(n, (void*)nstr, 2);
	__COPY(vt100_CSI, cmd, 7);
	Strings_Append(nstr, 2, (void*)cmd, 7);
	Strings_Append(letter, letter__len, (void*)cmd, 7);
	Console_String(cmd, 7);
	__DEL(letter);
}

static void vt100_EscSeqSwapped (INT16 n, CHAR *letter, ADDRESS letter__len)
{
	CHAR nstr[2];
	CHAR cmd[7];
	__DUP(letter, letter__len, CHAR);
	vt100_IntToStr(n, (void*)nstr, 2);
	__COPY(vt100_CSI, cmd, 7);
	Strings_Append(letter, letter__len, (void*)cmd, 7);
	Strings_Append(nstr, 2, (void*)cmd, 7);
	Console_String(cmd, 7);
	__DEL(letter);
}

static void vt100_EscSeq2 (INT16 n, INT16 m, CHAR *letter, ADDRESS letter__len)
{
	CHAR nstr[5], mstr[5];
	CHAR cmd[12];
	__DUP(letter, letter__len, CHAR);
	vt100_IntToStr(n, (void*)nstr, 5);
	vt100_IntToStr(m, (void*)mstr, 5);
	__COPY(vt100_CSI, cmd, 12);
	Strings_Append(nstr, 5, (void*)cmd, 12);
	Strings_Append((CHAR*)";", 2, (void*)cmd, 12);
	Strings_Append(mstr, 5, (void*)cmd, 12);
	Strings_Append(letter, letter__len, (void*)cmd, 12);
	Console_String(cmd, 12);
	__DEL(letter);
}

void vt100_CUU (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"A", 2);
}

void vt100_CUD (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"B", 2);
}

void vt100_CUF (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"C", 2);
}

void vt100_CUB (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"D", 2);
}

void vt100_CNL (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"E", 2);
}

void vt100_CPL (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"F", 2);
}

void vt100_CHA (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"G", 2);
}

void vt100_CUP (INT16 n, INT16 m)
{
	vt100_EscSeq2(n, m, (CHAR*)"H", 2);
}

void vt100_ED (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"J", 2);
}

void vt100_EL (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"K", 2);
}

void vt100_SU (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"S", 2);
}

void vt100_SD (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"T", 2);
}

void vt100_HVP (INT16 n, INT16 m)
{
	vt100_EscSeq2(n, m, (CHAR*)"f", 2);
}

void vt100_SGR (INT16 n)
{
	vt100_EscSeq(n, (CHAR*)"m", 2);
}

void vt100_SGR2 (INT16 n, INT16 m)
{
	vt100_EscSeq2(n, m, (CHAR*)"m", 2);
}

void vt100_DSR (INT16 n)
{
	vt100_EscSeq(6, (CHAR*)"n", 2);
}

void vt100_SCP (void)
{
	vt100_EscSeq0((CHAR*)"s", 2);
}

void vt100_RCP (void)
{
	vt100_EscSeq0((CHAR*)"u", 2);
}

void vt100_DECTCEMl (void)
{
	vt100_EscSeq0((CHAR*)"\?25l", 5);
}

void vt100_DECTCEMh (void)
{
	vt100_EscSeq0((CHAR*)"\?25h", 5);
}

void vt100_SetAttr (CHAR *attr, ADDRESS attr__len)
{
	CHAR tmpstr[16];
	__DUP(attr, attr__len, CHAR);
	__COPY(vt100_CSI, tmpstr, 16);
	Strings_Append(attr, attr__len, (void*)tmpstr, 16);
	Console_String(tmpstr, 16);
	__DEL(attr);
}


export void *vt100__init(void)
{
	__DEFMOD;
	__MODULE_IMPORT(Console);
	__MODULE_IMPORT(Strings);
	__REGMOD("vt100", 0);
	__REGCMD("DECTCEMh", vt100_DECTCEMh);
	__REGCMD("DECTCEMl", vt100_DECTCEMl);
	__REGCMD("RCP", vt100_RCP);
	__REGCMD("SCP", vt100_SCP);
/* BEGIN */
	__COPY("\033", vt100_CSI, 5);
	Strings_Append((CHAR*)"[", 2, (void*)vt100_CSI, 5);
	__ENDMOD;
}
