#include "exercise.h"

// Simulated ESP32 hardware registers (write-only)
uint32_t GPIO_OUT_W1TS_REG = 0;
uint32_t GPIO_OUT_W1TC_REG = 0;
// Simulated ESP32 hardware register (read-only)
uint32_t GPIO_IN_REG = 0;

void turn_on_led(uint8_t pin) {
    // TODO: implement using direct assignment (=) and 1U
}

void turn_off_led(uint8_t pin) {
    // TODO: implement using direct assignment (=) and 1U
}

int is_button_pressed(uint8_t pin) {
    // TODO: implement using 1U and bitwise AND
    return 0;
}

// ------------------------------------------
// Hardware simulator internals (ignore this)
void _sim_apply_registers(uint32_t *actual_out) {
    *actual_out |= GPIO_OUT_W1TS_REG;
    *actual_out &= ~(GPIO_OUT_W1TC_REG);
    GPIO_OUT_W1TS_REG = 0; // Hardware auto-clears W1TS
    GPIO_OUT_W1TC_REG = 0; // Hardware auto-clears W1TC
}
