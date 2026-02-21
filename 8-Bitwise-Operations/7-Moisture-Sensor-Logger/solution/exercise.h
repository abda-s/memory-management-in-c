#ifndef EXERCISE_H
#define EXERCISE_H
#include <stdint.h>

void pack_reading(uint32_t *logger_word, uint8_t index, uint8_t value);
uint8_t read_reading(uint32_t logger_word, uint8_t index);

#endif
