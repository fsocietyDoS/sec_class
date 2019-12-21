MODULE fact;
IMPORT Out, SYSTEM;

VAR  result, x, j : INTEGER;

PROCEDURE facto(VAR i: INTEGER) : INTEGER;

FOR j := 1 TO i DO
result := result * j;

END;
END facto;


BEGIN 
x := 5;
Out.Int(fact(x), 0); Out.Ln;
 
END fact.
