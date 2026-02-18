
# Boot.dev Memory Management In C Course (Local C Environment)

This repository contains the exercises and notes for the [Boot.dev Memory Management in C](https://boot.dev) course.

It is configured to run in **GitHub Codespaces** using a 32-bit environment to strictly match the course's requirements (4-byte pointers). It also includes a compatibility layer for the `munit` testing library used in the browser environment.

## 🛠️ One-Time Setup (If you fork this repo)

When you first open this repository in a GitHub Codespace, the environment is standard 64-bit Ubuntu. You need to install the C toolchain and 32-bit support libraries.

**1. Open a Terminal in Codespaces (`Ctrl` + `` ` ``) and run this entire block:**

```bash
# 1. Install 32-bit compiler tools and debuggers
sudo apt-get update && sudo apt-get install -y build-essential valgrind gdb gcc-multilib

# 2. Download the testing library to the root folder (if not already present)
wget -nc [https://raw.githubusercontent.com/nemequ/munit/master/munit.c](https://raw.githubusercontent.com/nemequ/munit/master/munit.c)
wget -nc [https://raw.githubusercontent.com/nemequ/munit/master/munit.h](https://raw.githubusercontent.com/nemequ/munit/master/munit.h)
```
# 3. Create the 'run_lesson' shortcut
```bash
echo 'alias run_lesson="gcc -m32 -g -I\$(git rev-parse --show-toplevel) -o test_runner *.c \$(git rev-parse --show-toplevel)/munit.c && ./test_runner"' >> ~/.bashrc
source ~/.bashrc
```

* **`gcc-multilib`**: Allows compiling 32-bit code on a 64-bit machine.
* **`valgrind`**: The memory leak detector used in the course.
* **`run_lesson`**: A custom shortcut that automatically finds `munit` in the root folder and compiles your current lesson.

---

## 📂 Directory Structure

To make the `run_lesson` command work, keep `munit.c` and `munit.h` in the **root** folder. Organize your lessons however you like inside subfolders.

```text
.
├── munit.c               <-- DO NOT MOVE (Testing Library Source)
├── munit.h               <-- DO NOT MOVE (Testing Library Header)
├── README.md
├── Chapter_1
│   ├── Lesson_1
│   │   ├── main.c       
│   │   ├── exercise.c
│   │   └── exercise.h
│   └── Lesson_2
│       └── ...
└── ...

```

---

## 🚀 How to Run Code

1. Navigate to the folder of the specific lesson you are working on:
```bash
cd Chapter_1/Lesson_1

```


2. Run the helper command:
```bash
run_lesson

```



This will:

1. Compile all `.c` files in your current folder.
2. Link them against the `munit.c` file in the root.
3. Force 32-bit mode (`-m32`).
4. Run the executable immediately if compilation succeeds.

---

## 📝 The `main.c` Template

Boot.dev uses a custom version of the `munit` library. To make the code copy-pasted from the website work locally, you **must** use this template for your `main.c` file.

Copy this into every `main.c`:

```c
#include "munit.h"
#include "exercise.h"
#include <string.h>

// =========================================================
//  BOOT.DEV COMPATIBILITY LAYER
// =========================================================

// 1. Fix munit_assert_int (Ignores the extra 'msg' argument)
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

// 3. Define the shortcuts Boot.dev uses
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

// =========================================================
//  👇 PASTE BOOT.DEV CODE BELOW THIS LINE 👇
// =========================================================


```

---

## 🐛 Debugging Memory Leaks

Since this course is about Memory Management, you will frequently need to check for leaks.

Instead of `run_lesson`, you can run Valgrind manually on the generated executable:

```bash
# 1. Compile manually
gcc -m32 -g -I$(git rev-parse --show-toplevel) -o test_runner *.c $(git rev-parse --show-toplevel)/munit.c

# 2. Run Valgrind
valgrind --leak-check=full ./test_runner

```