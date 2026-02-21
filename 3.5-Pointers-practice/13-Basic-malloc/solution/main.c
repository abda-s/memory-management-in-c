#include <stdio.h>
#include <stdlib.h> // for malloc

int main(){
    int *val_ptr = malloc(sizeof(int));
    if(!val_ptr){
        printf("there is an error allocating memory, we r fucked");
        exit(1);
    }
    *val_ptr = 108;


    printf("Value stored dynamically: %d\n", *val_ptr );
    printf("Memory address allocated: %p\n", val_ptr);

    free(val_ptr);
    val_ptr = NULL;
    return 0;
}