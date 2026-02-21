#include "exercise.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind) {
  // ?
  switch(kind){
    case INTEGER:
      //logic
      ((snek_int_t*)ptr)->value = 0;
      break;
    case FLOAT:
      //logic
      ((snek_float_t*)ptr)->value = 0.0;
      break;
    case BOOL:
      //logic
      ((snek_bool_t*)ptr)->value = 0;
      break;
  }

}
