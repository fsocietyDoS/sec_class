/* voc 2.1.0 [2019/11/13] for gcc LP64 on parrot xtspa */

#define SHORTINT INT8
#define INTEGER  INT16
#define LONGINT  INT32
#define SET      UINT32

#include "SYSTEM.h"

typedef
	struct ooptest_animal {
		INT16 age;
	} ooptest_animal;

typedef
	struct ooptest_mammal {
		INT16 age;
		INT16 legs;
	} ooptest_mammal;

typedef
	CHAR ooptest_string[16];

typedef
	struct ooptest_dog {
		INT16 age;
		INT16 legs;
		ooptest_string name;
		BOOLEAN tail;
	} ooptest_dog;


static ooptest_dog ooptest_jeko;
static ooptest_mammal ooptest_whaley;

export ADDRESS *ooptest_animal__typ;
export ADDRESS *ooptest_mammal__typ;
export ADDRESS *ooptest_dog__typ;



__TDESC(ooptest_animal, 1, 0) = {__TDFLDS("animal", 2), {-8}};
__TDESC(ooptest_mammal, 1, 0) = {__TDFLDS("mammal", 4), {-8}};
__TDESC(ooptest_dog, 1, 0) = {__TDFLDS("dog", 22), {-8}};

export void *ooptest__init(void)
{
	__DEFMOD;
	__REGMOD("ooptest", 0);
	__INITYP(ooptest_animal, ooptest_animal, 0);
	__INITYP(ooptest_mammal, ooptest_animal, 1);
	__INITYP(ooptest_dog, ooptest_mammal, 2);
/* BEGIN */
	ooptest_jeko.age = 5;
	ooptest_whaley = *(ooptest_mammal*)&ooptest_jeko;
	__ENDMOD;
}
