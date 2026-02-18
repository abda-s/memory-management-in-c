#include <stdio.h>

int main(){

    int data[5] = {1, 3, 5, 7, 9};
    int *ptr = data;
    printf("1. Subscript notation: %d\n", data[2]);
    printf("2. Pointer notation (data + 2): %d\n", *(data+2));
    printf("3. Pointer notation (ptr + 2): %d\n", *(ptr+2));

    return 0;
}