#include <munit.h>
#include "exercise.h"

static MunitResult test_turn_on(const MunitParameter params[], void* data) {
    uint32_t simulated_hardware_out = 0;
    
    turn_on_led(3);
    _sim_apply_registers(&simulated_hardware_out);
    munit_assert_uint32(simulated_hardware_out, ==, 8, "Failed");
    
    turn_on_led(31);
    _sim_apply_registers(&simulated_hardware_out);
    munit_assert_uint32(simulated_hardware_out, ==, 0x80000008, "Failed");
    return MUNIT_OK;
}

static MunitResult test_turn_off(const MunitParameter params[], void* data) {
    uint32_t simulated_hardware_out = 0xFFFFFFFF;
    
    turn_off_led(3);
    _sim_apply_registers(&simulated_hardware_out);
    munit_assert_uint32(simulated_hardware_out, ==, 0xFFFFFFF7, "Failed");
    
    turn_off_led(31);
    _sim_apply_registers(&simulated_hardware_out);
    munit_assert_uint32(simulated_hardware_out, ==, 0x7FFFFFF7, "Failed");
    return MUNIT_OK;
}

static MunitResult test_is_button_pressed(const MunitParameter params[], void* data) {
    GPIO_IN_REG = 0x80000008; // Bit 3 and Bit 31 are high
    munit_assert_int(is_button_pressed(3), ==, 1, "Failed");
    munit_assert_int(is_button_pressed(31), ==, 1, "Failed");
    munit_assert_int(is_button_pressed(0), ==, 0, "Failed");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_turn_on", test_turn_on, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_turn_off", test_turn_off, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_is_button_pressed", test_is_button_pressed, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_gpio_esp32", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
