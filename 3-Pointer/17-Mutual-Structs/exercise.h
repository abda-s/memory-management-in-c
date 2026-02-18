#ifndef EXERCISE_H
#define EXERCISE_H

// 1. Define the typedefs (Aliases)
typedef struct Employee employee_t;
typedef struct Department department_t;

// 2. Define the actual structs
struct Employee {
    int id;
    char *name;
    department_t *department;
};

struct Department {
    char *name;
    employee_t *manager;
};

// 3. Function Declarations
employee_t create_employee(int id, char *name);
department_t create_department(char *name);

void assign_employee(employee_t *emp, department_t *department);
void assign_manager(department_t *dept, employee_t *manager);

#endif