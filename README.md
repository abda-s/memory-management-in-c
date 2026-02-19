# Boot.dev Memory Management In C Course (Local C Environment)

This repository contains the exercises for the [Boot.dev Memory Management in C](https://www.boot.dev/courses/learn-memory-management-c) course.

It is configured to run in **GitHub Codespaces** using a 32-bit environment to strictly match the course's requirements (4-byte pointers). It also includes a compatibility layer (`bootdev_shim.h`) that allows the browser-based code to run locally without modification.

## 🛠️ One-Time Setup (If you fork this repo)

When you first open this repository in a GitHub Codespace, the environment is standard 64-bit Ubuntu. You need to install the C toolchain and configure the shortcuts.

**Open a Terminal in Codespaces (`Ctrl` + `~`) and run this entire block:**

```bash
# 1. Install 32-bit compiler tools and debuggers
sudo apt-get update && sudo apt-get install -y build-essential valgrind gdb gcc-multilib

# 2. Create the 'run_lesson' shortcut (Compiles + Runs)
echo 'alias run_lesson="gcc -m32 -g -I\$(git rev-parse --show-toplevel) -include \$(git rev-parse --show-toplevel)/bootdev_shim.h -o test_runner *.c \$(git rev-parse --show-toplevel)/munit.c && ./test_runner"' >> ~/.bashrc

# 3. Apply changes
source ~/.bashrc

```

* **`gcc-multilib`**: Allows compiling 32-bit code on a 64-bit machine.
* **`valgrind`**: The memory leak detector used in the course.
* **`run_lesson`**: Compiles and runs your current lesson.

---

## 📂 Directory Structure

To make the automation work, keep the library files in the **root** folder. Organize your lessons however you like inside subfolders.

```text
.
├── munit.c               <-- DO NOT MOVE (Testing Library Source)
├── munit.h               <-- DO NOT MOVE (Testing Library Header)
├── bootdev_shim.h        <-- DO NOT MOVE (Compatibility Layer for Boot.dev code)
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
2. Automatically inject the compatibility layer (`bootdev_shim.h`).
3. Link them against `munit.c`.
4. Force 32-bit mode (`-m32`).
5. Run the executable immediately if compilation succeeds.