#ifndef EXERCISE_H
#define EXERCISE_H
#include <stdint.h>

// Simulated ESP32 hardware registers
extern uint32_t GPIO_OUT_W1TS_REG;
extern uint32_t GPIO_OUT_W1TC_REG;
extern uint32_t GPIO_IN_REG;

// Simulator helper (don't worry about this function)
void _sim_apply_registers(uint32_t *actual_out);

void turn_on_led(uint8_t pin);
void turn_off_led(uint8_t pin);
int is_button_pressed(uint8_t pin);

#endif
