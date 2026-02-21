#include "exercise.h"
#include "stdlib.h"

void allocate_int(int **pointer_pointer, int value) {
  // ?
  int *value_ptr = malloc(sizeof(int));
    if(!value_ptr){
        printf("Error when allocating value_ptr");
    }
    *pointer_pointer = value_ptr;
    *value_ptr = value;
}
