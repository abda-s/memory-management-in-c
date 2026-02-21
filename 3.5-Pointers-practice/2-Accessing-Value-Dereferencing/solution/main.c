#include <stdio.h>

int main(){
    int num = 100;
    printf("Original value of num: %d\n", num);
    int *num_ptr = &num;
    *num_ptr=500;
    printf("New value of num after pointer assignment: %d\n", num);


    
    return 0;
}