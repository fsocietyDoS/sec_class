#include <stdio.h>
#include <unistd.h>

int main(void){

    printf("Real user ID: %d\n", getuid());
    printf("Effective user ID: %d\n", geteuid());
    return 0;

}

