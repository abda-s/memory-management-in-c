#ifndef EXERCISE_H
#define EXERCISE_H
#include <stdint.h>

void turn_on_setting(uint32_t *settings_word, uint8_t index);
void turn_off_setting(uint32_t *settings_word, uint8_t index);
int is_setting_on(uint32_t settings_word, uint8_t index);

#endif
