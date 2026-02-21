#include "exercise.h"

void turn_on_setting(uint32_t *settings_word, uint8_t index) {
    // TODO: implement
    *settings_word |= (1U << index);
}

void turn_off_setting(uint32_t *settings_word, uint8_t index) {
    // TODO: implement
    *settings_word &= ~(1U << index);
}

int is_setting_on(uint32_t settings_word, uint8_t index) {
    // TODO: implement
    return (settings_word >> index) & 1U;
    return 0;
}
