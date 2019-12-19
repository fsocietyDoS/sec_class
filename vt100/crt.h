/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspa */

#ifndef crt__h
#define crt__h

#include "SYSTEM.h"




import void crt_ClrEol (void);
import void crt_ClrScr (void);
import void crt_DelLine (void);
import void crt_Delay (INT16 ms);
import void crt_EraseDisplay (void);
import void crt_GotoXY (INT16 x, INT16 y);
import void crt_HighVideo (void);
import void crt_InsLine (void);
import void crt_LowVideo (void);
import void crt_NormVideo (void);
import void crt_TextBackground (INT8 color);
import void crt_TextColor (INT8 color);
import void crt_cursoroff (void);
import void crt_cursoron (void);
import void *crt__init(void);


#endif // crt
