/* bootdev_shim.h */
#ifndef BOOTDEV_SHIM_H
#define BOOTDEV_SHIM_H

#include "munit.h"
#include <string.h>

// 1. Fix munit_assert_int (Ignores the extra 'msg')
#undef munit_assert_int
#define munit_assert_int(a, op, b, msg) munit_assert_type(int, "d", a, op, b)

// 2. Fix munit_assert_string_equal (Manual strcmp implementation)
#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg) \
    do { \
        const char* s1 = a; \
        const char* s2 = b; \
        if (strcmp(s1, s2) != 0) { \
            munit_errorf("assertion failed: \"%s\" != \"%s\" (%s)", s1, s2, msg); \
        } \
    } while (0)

// 3. Fix short aliases (assert_int, etc)
#undef assert_int
#define assert_int(a, op, b, msg) munit_assert_int(a, op, b, msg)

#undef assert_string_equal
#define assert_string_equal(a, b, msg) munit_assert_string_equal(a, b, msg)

// 4. Define shortcuts
#define RUN 0
#define SUBMIT 1

#define munit_case(TYPE, NAME, BLOCK) \
    static MunitResult NAME(const MunitParameter params[], void* user_data) { \
        BLOCK \
        return MUNIT_OK; \
    }

#define munit_test(name, func) \
    { name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
    { name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

#endif