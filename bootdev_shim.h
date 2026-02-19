/* bootdev_shim.h */
#ifndef BOOTDEV_SHIM_H
#define BOOTDEV_SHIM_H

#include "munit.h"
#include <string.h>

// =========================================================
//  1. FIX INTEGER & SIZE ASSERTS (Ignore 'msg' argument)
// =========================================================

#undef munit_assert_int
#define munit_assert_int(a, op, b, msg) munit_assert_type(int, "d", a, op, b)

#undef munit_assert_size
#define munit_assert_size(a, op, b, msg) munit_assert_type(size_t, "zu", a, op, b)

#undef munit_assert_uint8
#define munit_assert_uint8(a, op, b, msg) munit_assert_type(munit_uint8_t, "02X", a, op, b)

#undef munit_assert_uint16
#define munit_assert_uint16(a, op, b, msg) munit_assert_type(munit_uint16_t, "u", a, op, b)

#undef munit_assert_uint32
#define munit_assert_uint32(a, op, b, msg) munit_assert_type(munit_uint32_t, "u", a, op, b)

// =========================================================
//  2. FIX FLOAT & DOUBLE ASSERTS
// =========================================================

// Fix: munit_assert_float (Ignores 'msg')
#undef munit_assert_float
#define munit_assert_float(a, op, b, msg) munit_assert_type(float, "f", a, op, b)

// Fix: munit_assert_double (Ignores 'msg')
#undef munit_assert_double
#define munit_assert_double(a, op, b, msg) munit_assert_type(double, "g", a, op, b)

// =========================================================
//  3. FIX POINTER ASSERTS
// =========================================================

#undef assert_ptr_not_null
#define assert_ptr_not_null(ptr, msg) munit_assert_ptr_not_null(ptr)

#undef assert_ptr_null
#define assert_ptr_null(ptr, msg) munit_assert_ptr_null(ptr)

#undef munit_assert_not_null
#define munit_assert_not_null(ptr, msg) munit_assert_ptr_not_null(ptr)

#undef munit_assert_ptr_not_equal
#define munit_assert_ptr_not_equal(a, b, msg) munit_assert_ptr(a, !=, b)

// =========================================================
//  4. FIX STRING ASSERTS
// =========================================================

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg) \
    do { \
        const char* s1 = a; \
        const char* s2 = b; \
        if (strcmp(s1, s2) != 0) { \
            munit_errorf("assertion failed: \"%s\" != \"%s\" (%s)", s1, s2, msg); \
        } \
    } while (0)

// =========================================================
//  5. FIX SHORT ALIASES
// =========================================================
#undef assert_int
#define assert_int(a, op, b, msg) munit_assert_int(a, op, b, msg)

#undef assert_string_equal
#define assert_string_equal(a, b, msg) munit_assert_string_equal(a, b, msg)

// =========================================================
//  6. DEFINE BOOT.DEV TEST HELPERS
// =========================================================
#define RUN 0
#define SUBMIT 1

#define munit_case(TYPE, NAME, ...) \
    static MunitResult NAME(const MunitParameter params[], void* user_data) { \
        __VA_ARGS__ \
        return MUNIT_OK; \
    }

#define munit_test(name, func) \
    { name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_null_test \
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define munit_suite(name, tests) \
    { name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

#endif