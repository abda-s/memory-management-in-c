#include <munit.h>
#include "exercise.h"

static MunitResult test_set_bit(const MunitParameter params[], void* data) {
    munit_assert_uint8(set_bit(0, 0), ==, 1, "Failed");
    munit_assert_uint8(set_bit(0, 3), ==, 8, "Failed");
    munit_assert_uint8(set_bit(5, 1), ==, 7, "Failed");
    return MUNIT_OK;
}

static MunitResult test_clear_bit(const MunitParameter params[], void* data) {
    munit_assert_uint8(clear_bit(255, 0), ==, 254, "Failed");
    munit_assert_uint8(clear_bit(15, 3), ==, 7, "Failed");
    munit_assert_uint8(clear_bit(7, 1), ==, 5, "Failed");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_set_bit", test_set_bit, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_clear_bit", test_clear_bit, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_set_clear", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
