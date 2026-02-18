#include <stdio.h>

void increment_value(int *ptr){
    *ptr += 1;
}

int main(){

    int count = 10;
    printf("Before function call, count = %d\n",count);
    int *count_ptr = &count;
    increment_value(count_ptr);
    printf("After function call, count = %d\n",count);

    return 0;
}