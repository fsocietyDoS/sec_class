/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtpamM */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"
#include "Files.h"
#include "Platform.h"
#include "oocRealMath.h"


static REAL beep_t, beep_a, beep_b, beep_freq, beep_xkm1, beep_ykm1, beep_est, beep_gf;
static INT32 beep_i, beep_e;
static INT16 beep_ai;
static Files_File beep_outvar;
static Files_Rider beep_outfile;
static BOOLEAN beep_first;
static INT32 beep__for__1;


static void beep_highpass (REAL t, REAL fhp, REAL xk, REAL *yk);


static void beep_highpass (REAL t, REAL fhp, REAL xk, REAL *yk)
{
	if (beep_first) {
		beep_est = oocRealMath_exp(-((  6.2831802e+000 * fhp) * t));
		beep_gf = ((REAL)1 + beep_est) / (REAL)((REAL)1 - beep_est);
		beep_first = 0;
	}
	*yk = (xk - beep_xkm1) / (REAL)(REAL)2;
	beep_xkm1 = xk;
	xk = *yk;
	*yk = beep_est * beep_ykm1 + ((REAL)1 - beep_est) * xk;
	beep_ykm1 = *yk;
	*yk = beep_gf * *yk;
}

static void EnumPtrs(void (*P)(void*))
{
	P(beep_outvar);
	__ENUMR(&beep_outfile, Files_Rider__typ, 24, 1, P);
}


export int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__MODULE_IMPORT(Files);
	__MODULE_IMPORT(Platform);
	__MODULE_IMPORT(oocRealMath);
	__REGMAIN("beep", EnumPtrs);
/* BEGIN */
	beep_t =   2.2675737e-005;
	beep_xkm1 = (REAL)0;
	beep_ykm1 = (REAL)0;
	beep_first = 1;
	beep_outvar = Files_New((CHAR*)"beepfile", 9);
	if (beep_outvar != NIL) {
		Files_Set(&beep_outfile, Files_Rider__typ, beep_outvar, 0);
	} else {
		__HALT(1);
	}
	beep_e = 88200;
	beep_freq = (REAL)1000;
	beep__for__1 = beep_e;
	beep_i = 1;
	while (beep_i <= beep__for__1) {
		beep_a = (REAL)3000 * oocRealMath_sin(((  6.2831802e+000 * beep_freq) * beep_i) / (REAL)44100);
		beep_ai = (INT16)(__ENTIER(beep_a));
		if (beep_i > 22050) {
			Files_WriteInt(&beep_outfile, Files_Rider__typ, beep_ai);
		}
		beep_i += 1;
	}
	Files_Register(beep_outvar);
	beep_i = Platform_System((CHAR*)"oggenc -r -C 1 beepfile", 24);
	beep_i = Platform_System((CHAR*)"ogg123 beepfile.ogg", 20);
	__FINI;
}
