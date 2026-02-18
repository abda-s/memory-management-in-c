## Exercise 1: Declaration and Initialization
Practice Problem: Declare an integer variable, a pointer to an integer, and initialize the pointer to the address of the variable. Print both the variable’s value and the value accessed via the pointer.

Given:
```c
int var = 42;
```
Expected Output:
Memory Address can vary according to the system.
```
Variable 'var' value: 42
Variable 'var' address: 0x7ffc170d9ffc
Pointer 'ptr' address (value of ptr): 0x7ffc170d9ffc
Value accessed via pointer (*ptr): 42
```

## Exercise 2: Accessing Value (Dereferencing)
Practice Problem: Write a program that uses the dereference operator (*) to change the value of a variable through its pointer.

Given:
```c
int num = 100;
```

Expected Output:
```
Original value of num: 100
New value of num after pointer assignment: 500
```

## Exercise 3: Address Operator

Practice Problem: Print the memory addresses of two different variables (e.g., an int and a float) using the address-of operator (&). Additionally, print the address of a pointer variable itself.

Given:
```c
int a = 10;
float b = 20.5f;
```

Expected Output:
```
Address of integer variable 'a': 0x7ffdd91e2bd8
Address of float variable 'b': 0x7ffdd91e2bdc
Address stored IN pointer 'p_a': 0x7ffdd91e2bd8
Address of pointer variable 'p_a' itself: 0x7ffdd91e2be0
```

## Exercise 4: Pointer Size

Practice Problem: Write a program to print the size (in bytes) of a pointer to an integer, a pointer to a character, and a pointer to a float on your system.

Expected Output:
```
Size of int pointer (int *): 8 bytes
Size of char pointer (char *): 8 bytes
Size of float pointer (float *): 8 bytes

Size of 'int' variable: 4 bytes
Size of 'float' variable: 4 bytes
```

## Exercise 5: Passing by Reference

Practice Problem: Create a function increment_value that takes an integer pointer as an argument and increments the value of the variable it points to by one. Demonstrate the change in the main function.

Given:
```c
int count = 10;
```

Expected Output:
```
Before function call, count = 10
After function call, count = 11
```

## Exercise 6: Array Traversal

Practice Problem: Use pointer arithmetic to traverse an integer array and print all its elements.

Given:
```c
int arr[] = {10, 20, 30, 40, 50};
```

Expected Output:
```
Array elements using pointer arithmetic:
Element 0: 10
Element 1: 20
Element 2: 30
Element 3: 40
Element 4: 50
```

## Exercise 7: Accessing Array Elements

Practice Problem: Given an array, access and print the third element (index 2) using three different methods: subscript notation, pointer notation with the base address, and pointer notation with an offset pointer.

Given:
```c
int data[5] = {1, 3, 5, 7, 9};
```

Expected Output:
```
Array element at index 2 (Value should be 5):
1. Subscript notation: 5
2. Pointer notation (arr + 2): 5
3. Pointer notation (ptr + 2): 5
```

## Exercise 8: Pointers to an Array (Array Name as Pointer)

Practice Problem: Declare an array and attempt to assign a new address to the array’s name. Observe the compilation error and explain why it occurs.

Given:
```c
int arr[5] = {1, 2, 3, 4, 5};
int other_var = 10;
```

## Exercise 9: Sum of Array Elements

Practice Problem: Write a function sum_array that accepts an integer pointer (the array base address) and the size of the array. The function must calculate and return the sum of all elements using pointer arithmetic for traversal.

Given:
```c
int numbers[] = {10, 5, 8, 2, 15};
```

Expected Output:
```
The sum of array elements is: 40
```

## Exercise 10: Reverse an Array

Practice Problem: Write a program to reverse an integer array in place (without using a second array) by swapping elements using pointers.

Given:
```c
int numbers[] = {1, 2, 3, 4, 5, 6};
```

Expected Output:
```
Original array: 1 2 3 4 5 6 
Reversed array: 6 5 4 3 2 1
```

## Exercise 11: String Length

Practice Problem: Write a function custom_strlen to calculate the length of a string (null-terminated character array) without using the standard C library function strlen(). The function must use a character pointer to traverse the string until it finds the null terminator (\0).

Given:
```c
char myString[] = "Hello Pointers!";
``` 
Expected Output:
```
The string is: "Hello Pointers!"
Length using custom_strlen: 15
```

## Exercise 12: String Copy

Practice Problem: Implement a function custom_strcpy that copies the content of a source string (src) to a destination string (dest) using only character pointers.

Given:
```c
char source[] = "Pointer Mastery";
char destination[50]; // Ensure destination buffer is large enough
```

Expected Output:
```
Source: Pointer Mastery
Destination: Pointer Mastery
```

## Exercise 13: Basic malloc

Practice Problem: Dynamically allocate memory for a single integer using malloc(). Store the value 108 in this allocated memory, print the value and its memory address, and then free the memory using free().

Expected Output:
```
Value stored dynamically: 108
Memory address allocated: 0x5696c3bc92a0
```