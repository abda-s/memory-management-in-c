#include <munit.h>
#include "exercise.h"

static MunitResult test_and(const MunitParameter params[], void* data) {
    munit_assert_uint8(bitwise_and(5, 3), ==, 1, "Failed");
    munit_assert_uint8(bitwise_and(0, 7), ==, 0, "Failed");
    return MUNIT_OK;
}

static MunitResult test_or(const MunitParameter params[], void* data) {
    munit_assert_uint8(bitwise_or(5, 3), ==, 7, "Failed");
    munit_assert_uint8(bitwise_or(0, 7), ==, 7, "Failed");
    return MUNIT_OK;
}

static MunitResult test_xor(const MunitParameter params[], void* data) {
    munit_assert_uint8(bitwise_xor(5, 3), ==, 6, "Failed");
    munit_assert_uint8(bitwise_xor(15, 15), ==, 0, "Failed");
    return MUNIT_OK;
}

static MunitResult test_shift_left(const MunitParameter params[], void* data) {
    munit_assert_uint8(bitwise_shift_left(1, 3), ==, 8, "Failed");
    munit_assert_uint8(bitwise_shift_left(5, 1), ==, 10, "Failed");
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_and", test_and, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_or", test_or, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_xor", test_xor, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_shift_left", test_shift_left, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_intro", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
