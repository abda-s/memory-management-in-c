#include <stdio.h>
int main(){
    int var = 42;
    int *var_ptr = &var;

    printf("Variable 'var' value: %d\n", var);
    printf("Variable 'var' address: %p\n", &var);
    printf("Pointer 'ptr' address (value of ptr): %p\n", var_ptr);
    printf("Value accessed via pointer (*ptr): %d\n", *var_ptr);


    return 0;
}