/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspa */

#ifndef vt100__h
#define vt100__h

#include "SYSTEM.h"


import CHAR vt100_CSI[5];


import void vt100_CHA (INT16 n);
import void vt100_CNL (INT16 n);
import void vt100_CPL (INT16 n);
import void vt100_CUB (INT16 n);
import void vt100_CUD (INT16 n);
import void vt100_CUF (INT16 n);
import void vt100_CUP (INT16 n, INT16 m);
import void vt100_CUU (INT16 n);
import void vt100_DECTCEMh (void);
import void vt100_DECTCEMl (void);
import void vt100_DSR (INT16 n);
import void vt100_ED (INT16 n);
import void vt100_EL (INT16 n);
import void vt100_HVP (INT16 n, INT16 m);
import void vt100_IntToStr (INT32 int_, CHAR *str, ADDRESS str__len);
import void vt100_RCP (void);
import void vt100_SCP (void);
import void vt100_SD (INT16 n);
import void vt100_SGR (INT16 n);
import void vt100_SGR2 (INT16 n, INT16 m);
import void vt100_SU (INT16 n);
import void vt100_SetAttr (CHAR *attr, ADDRESS attr__len);
import void *vt100__init(void);


#endif // vt100
