#include <stdio.h>
#include <string.h>


void main () {

char ref_myStr[] = "hello";
ref_changeArr(ref_myStr);

	} 

void ref_changeArr (char* a){
	int i=0;
	printf("mtanq funckia\n");

	
	printf("%s\n",a);
	
	do {
	a[i] = 'o';
	i += 1;
	}
	
	while (i != strlen(a) - 1);
	printf("durs ekanq funkciayic\n");
	printf("%s",a);
}


