#include "exercise.h"

void pack_reading(uint32_t *logger_word, uint8_t index, uint8_t value) {
    // TODO: implement
    // every value is 2 bits, 4 possible values in the same 32 bit int
    // so 32/2 is 16 data reading for each 32 int 
    *logger_word = (*logger_word & ~(3U << index*2)) // 3U is 11 in binary 
                    | (value << index*2);
}

uint8_t read_reading(uint32_t logger_word, uint8_t index) {
    // TODO: implement
    return (logger_word >> index*2) & 3U; // 3U is 11 in binary 
    return 0;
}
