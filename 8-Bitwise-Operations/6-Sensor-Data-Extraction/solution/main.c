#include <munit.h>
#include "exercise.h"

static MunitResult test_extract_temperature(const MunitParameter params[], void* data) {
    // Example: status=0xAA, humidity=0x123, temp=0xABC -> 0xAA123ABC
    munit_assert_uint32(extract_temperature(0xAA123ABC), ==, 0xABC, "Failed"); // 2748
    return MUNIT_OK;
}

static MunitResult test_extract_humidity(const MunitParameter params[], void* data) {
    // Example: status=0xAA, humidity=0x123, temp=0xABC -> 0xAA123ABC
    munit_assert_uint32(extract_humidity(0xAA123ABC), ==, 0x123, "Failed"); // 291
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_extract_temperature", test_extract_temperature, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_extract_humidity", test_extract_humidity, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_sensor_32bit", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
