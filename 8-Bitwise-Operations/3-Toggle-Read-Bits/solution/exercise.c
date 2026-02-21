#include "exercise.h"

uint8_t toggle_bit(uint8_t word, uint8_t n) {
    // TODO: implement
    return word ^ (1 << n);
    return 0;
}

uint8_t read_bit(uint8_t word, uint8_t n) {
    // TODO: implement
    return (word >> n) & 1; 
    return 0;
}
