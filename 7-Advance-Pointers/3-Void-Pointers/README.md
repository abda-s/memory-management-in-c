
## Assignment

In Sneklang, we have to dynamically interpret Snek code and store the values in memory. The `snek_object_kind_t` enum defines the different types of objects that can be stored in memory.

Complete the `snek_zero_out` function. It accepts a generic pointer to one of:

- snek_int_t
- snek_float_t
- snek_bool_t

It should "zero out" the `.value` field of the struct by setting it to the zero value of its type. Use the `kind` parameter to figure out which type of struct you are working with.

When working with pointers and dereferencing them, parentheses usage is essential. Consider the following examples:

- `((some_struct_t*)ptr)->field` means casting is applied to ptr and then the field is obtained.
- `(some_struct_t*)ptr->field` means casting is applied to ptr->field.

