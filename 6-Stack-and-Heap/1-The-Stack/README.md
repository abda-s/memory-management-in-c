
## Assignment

    1. Run the code in its current state.

See how with each successive nested function call (`printMessageOne`, which calls `printMessageTwo`, which calls` printMessageThree`) the memory addresses allocate more and more space?

    2. Update where `printMessageTwo` and `printMessageThree` are called from so that all three of the functions use the same stack space.

The offsets printed by `printStackPointerDiff` should now be different from before. The `printStackPointerDiff()` calls should remain at the start of each function.
