#include <stdio.h>
#include <string.h>

void main(){
	char myArr[10];
	ref_myArr(myArr);
}

static void ref_myArr(myArr* a){
        int i;
        while (i != strlen(myArr) - 1){
            a[i] = 'o';
            printf(myArr[i]);
            i = i+1;
} 
 }
