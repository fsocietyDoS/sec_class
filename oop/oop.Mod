MODULE ooptest;

TYPE 
	string = ARRAY 16 OF CHAR;

	animal = RECORD 
	age : INTEGER;
	END;

	mammal = RECORD(animal)
	legs : INTEGER;
	END;

	dog = RECORD(mammal)
	name : string;
	tail : BOOLEAN;
	END;

PROCEDURE walk(VAR a: dog);

VAR 
	jeko : dog;
	whaley : mammal;

BEGIN

	jeko.age := 5;
	whaley := jeko;


END ooptest.

