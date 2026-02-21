#include <stdio.h>

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int other_var = 10;
    int *ptr = &other_var;

    printf("Address of arr[0]: %p\n", arr);
    printf("Address of other_var: %p\n", &other_var);

    //uncomment to get the error 
    // arr = ptr;

    //Explenation: the address of the arr will point to the first value and it's constatnt we can't change that
    return 0;
}