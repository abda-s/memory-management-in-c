#include <munit.h>
#include "exercise.h"

static MunitResult test_turn_on_setting(const MunitParameter params[], void* data) {
    uint32_t settings = 0;
    turn_on_setting(&settings, 4);
    munit_assert_uint32(settings, ==, 16, "Failed");
    turn_on_setting(&settings, 31);
    munit_assert_uint32(settings, ==, 0x80000010, "Failed");
    return MUNIT_OK;
}

static MunitResult test_turn_off_setting(const MunitParameter params[], void* data) {
    uint32_t settings = 0xFFFFFFFF;
    turn_off_setting(&settings, 4);
    munit_assert_uint32(settings, ==, 0xFFFFFFEF, "Failed");
    turn_off_setting(&settings, 31);
    munit_assert_uint32(settings, ==, 0x7FFFFFEF, "Failed");
    return MUNIT_OK;
}

static MunitResult test_is_setting_on(const MunitParameter params[], void* data) {
    uint32_t settings = 0x80000010; // Bits 4 and 31
    munit_assert_int(is_setting_on(settings, 4), ==, 1, "Failed");
    munit_assert_int(is_setting_on(settings, 3), ==, 0, "Failed");
    munit_assert_int(is_setting_on(settings, 31), ==, 1, "Failed");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_turn_on_setting", test_turn_on_setting, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_turn_off_setting", test_turn_off_setting, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_is_setting_on", test_is_setting_on, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_toggles_32", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
