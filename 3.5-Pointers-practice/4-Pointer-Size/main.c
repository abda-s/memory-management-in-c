#include <stdio.h>

int main(){
        printf("Size of int pointer (int *): %d bytes\n", sizeof(int*));
        printf("Size of char pointer (char *): %d bytes\n", sizeof(char*));
        printf("Size of float pointer (float *): %d bytes\n", sizeof(float*));

        printf("Size of 'int' variable: %d bytes\n", sizeof(int));
        printf("Size of 'float' variable: %d bytes\n", sizeof(float));


    return 0;
}