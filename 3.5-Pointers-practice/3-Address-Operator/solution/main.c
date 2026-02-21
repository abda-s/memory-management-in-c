#include <stdio.h>

int main(){
    int a = 10;
    float b = 20.5f;
    int *a_ptr = &a;
    float *b_ptr = &b;

    printf("Address of integer variable 'a': %p\n", &a);
    printf("Address of integer variable 'b': %p\n", &b);
    printf("Address stored IN pointer 'a_ptr': %p\n", a_ptr); // this is the same as &a
    printf("Address of pointer variable 'a_ptr' itself: %p\n", &a_ptr);

    return 0;
}