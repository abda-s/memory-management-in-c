#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  // ?
    void *temp = malloc(size);
    if(!temp){return;}
    memcpy(temp, vp2, size);

    memcpy(vp2, vp1, size);
    memcpy(vp1, temp, size);

    free(temp);
}
