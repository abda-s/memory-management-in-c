#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

char *get_full_greeting(char *greeting, char *name, int size) {
  char *full_greeting = malloc(size);
  snprintf(full_greeting, size, "%s %s", greeting, name); // this functions writes to the Heap memory adr it just needs the adr and the values 
  return full_greeting;
}
