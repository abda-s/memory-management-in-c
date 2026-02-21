#include <munit.h>
#include "exercise.h"

static MunitResult test_toggle_bit(const MunitParameter params[], void* data) {
    munit_assert_uint8(toggle_bit(0, 0), ==, 1, "Failed");
    munit_assert_uint8(toggle_bit(1, 0), ==, 0, "Failed");
    munit_assert_uint8(toggle_bit(15, 3), ==, 7, "Failed");
    return MUNIT_OK;
}

static MunitResult test_read_bit(const MunitParameter params[], void* data) {
    munit_assert_uint8(read_bit(8, 3), ==, 1, "Failed");
    munit_assert_uint8(read_bit(8, 2), ==, 0, "Failed");
    munit_assert_uint8(read_bit(15, 1), ==, 1, "Failed");
    munit_assert_uint8(read_bit(254, 0), ==, 0, "Failed");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_toggle_bit", test_toggle_bit, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_read_bit", test_read_bit, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_toggle_read", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
