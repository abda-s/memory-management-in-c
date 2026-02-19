
## Assignment

Sneklang, being a super-robust programming language toolchain, needs to represent "Tokens" - strings of text that represent Sneklang syntax, things like `if`, `else` and `def`. They're represented as structs, you can see the struct in `exercise.h`.

Take a look at `create_token_pointer_array`. It correctly allocates an array of token pointers on the heap, but notice that the addresses it's adding to each index are the addresses of the stack-allocated inputs.

1. Update the `create_token_pointer_array`'s loop to allocate new space for each token on the heap.
2. Store the address of the new space in the array instead of the stack address.
3. Copy the members of the input struct into the newly allocated one.

