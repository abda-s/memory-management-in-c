#include <munit.h>
#include "exercise.h"

static MunitResult test_pack_reading(const MunitParameter params[], void* data) {
    uint32_t word = 0;
    
    pack_reading(&word, 0, 3); // 11 in bottom
    munit_assert_uint32(word, ==, 3, "Failed"); // 00...0011
    
    pack_reading(&word, 1, 2); // 10 in next slot
    munit_assert_uint32(word, ==, 11, "Failed"); // 00...1011
    
    pack_reading(&word, 15, 1); // 01 in top slot (bits 30-31)
    munit_assert_uint32(word, ==, 0x4000000B, "Failed"); // 0100...1011
    
    // Now test overwriting
    pack_reading(&word, 0, 0); // clear bottom
    munit_assert_uint32(word, ==, 0x40000008, "Failed");
    return MUNIT_OK;
}

static MunitResult test_read_reading(const MunitParameter params[], void* data) {
    uint32_t word = 0x4000000B; // 0100...1011
    
    munit_assert_uint8(read_reading(word, 0), ==, 3, "Failed");
    munit_assert_uint8(read_reading(word, 1), ==, 2, "Failed");
    munit_assert_uint8(read_reading(word, 2), ==, 0, "Failed");
    munit_assert_uint8(read_reading(word, 15), ==, 1, "Failed");
    
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { (char*) "/test_pack_reading", test_pack_reading, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_read_reading", test_read_reading, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*) "/bitwise_moisture_32bit", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
