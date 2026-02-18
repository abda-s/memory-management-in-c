#include "munit.h"
#include "exercise.h"
#include <string.h>

// =========================================================
//  BOOT.DEV COMPATIBILITY LAYER (Final Fix)
// =========================================================

// 1. Fix munit_assert_int
// We redirect to 'munit_assert_type' which exists in munit.h
#undef munit_assert_int
#define munit_assert_int(a, op, b, msg) munit_assert_type(int, "d", a, op, b)

// 2. Fix munit_assert_string_equal
// We implement this manually using strcmp because the original macro is incompatible
#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg) \
    do { \
        const char* s1 = a; \
        const char* s2 = b; \
        if (strcmp(s1, s2) != 0) { \
            munit_errorf("assertion failed: \"%s\" != \"%s\" (%s)", s1, s2, msg); \
        } \
    } while (0)

// 3. Define the shortcuts Boot.dev uses for test definitions
#define RUN 0
#define SUBMIT 1

#define munit_case(TYPE, NAME, BLOCK) \
    static MunitResult NAME(const MunitParameter params[], void* user_data) { \
        BLOCK \
        return MUNIT_OK; \
    }

// 4. Helper to create a test struct entry
#define munit_test(name, func) \
    { name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// 5. Helper for the null terminator
#define munit_null_test \
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// 6. Helper to create the suite
#define munit_suite(name, tests) \
    { name, tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }

// =========================================================
//  TEST CASES
// =========================================================

munit_case(RUN, test_assign_employee1, {
  employee_t emp = create_employee(2, "CEO Dax");
  department_t dept = create_department("C Suite");
  assign_employee(&emp, &dept);
  munit_assert_string_equal(emp.department->name, "C Suite",
                            "should match names");
});

munit_case(RUN, test_assign_manager1, {
  employee_t manager = create_employee(3, "Influencer Prime");
  department_t dept = create_department("Marketing");
  assign_manager(&dept, &manager);
  munit_assert_string_equal(dept.manager->name, "Influencer Prime",
                            "should match names");
});

munit_case(SUBMIT, test_assign_employee2, {
  employee_t emp = create_employee(4, "Vegan Intern Adam");
  department_t dept = create_department("Marketing");
  assign_employee(&emp, &dept);
  munit_assert_string_equal(emp.department->name, "Marketing",
                            "should match names");
});

munit_case(SUBMIT, test_assign_manager2, {
  employee_t manager = create_employee(5, "CDO David");
  department_t dept = create_department("C Suite");
  assign_manager(&dept, &manager);
  munit_assert_string_equal(dept.manager->name, "CDO David",
                            "should match names");
  munit_assert_int(manager.id, ==, 5, "should match ids");
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_assign_employee1", test_assign_employee1),
      munit_test("/test_assign_manager1", test_assign_manager1),
      munit_test("/test_assign_employee2", test_assign_employee2),
      munit_test("/test_assign_manager2", test_assign_manager2),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("employee_department_tests", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
