
## Assignment

    1. Run the `get_full_greeting` function in its current state. If you take a look at the `main.c` file, you'll notice that it's testing to ensure that a pointer to stack memory isn't returned (which you never should do, because it's undefined behavior).
    2. Fix the `get_full_greeting` function so that it allocates memory on the heap and returns a pointer to that memory. Use the provided `size` parameter to allocate enough space for the resulting string, be sure to account for the size of each `char`.

Use `snprintf` to write the formatted output to a buffer. Remember to pass in the size rather than the hard-coded 100.
