
## Assignment

Let's get back to Sneklang's built in 2D graphics library. Take a look at the `new_coord` function. It accepts an x and y value and creates a new pointer to a stack-allocated `coord_t` struct.

    1. Run the code in its current state. You should see something... weird. Why don't the `x` and `y` values match the ones passed in on lines 20–22???

    Because we're accessing stack memory (the pointer created on line 16) outside of the function that created it, the memory has been deallocated and is no longer safe to use. Technically the behavior is undefined, but it's likely that in this specific scenario you're just seeing it get overwritten by the next function call (thus `50` and `60` always print).

    2. Fix the `new_coord` function so that it returns a struct, not a pointer to a struct. This will force the compiler to copy the struct to the `main` function's stack frame, and the memory will be safe to use. You'll have to update syntax in a few places to accommodate the change.

