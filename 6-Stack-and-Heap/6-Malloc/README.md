
## Assignment

We're working on some of the dynamic memory management tooling that we'll eventually need to build a garbage collector for Sneklang.

Complete the `allocate_scalar_array` function. It should:

    1. Accept `size` and `multiplier` parameters and should allocate an array of `size` integers on the heap.
    2. Gracefully return `NULL` if the allocation fails.
    3. Initialize each element in the array to the `index * multiplier`. (e.g. a multiplier of 2 would result in `[0, 2, 4, 6, ...]`)
    Return a pointer to the allocated memory.

Assume that the calling code will eventually call `free` on the returned pointer.
