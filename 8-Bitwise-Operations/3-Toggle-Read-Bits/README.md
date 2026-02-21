# Toggling and Reading Bits

## Background
Now let's complete the standard suite of bit manipulation helpers.
- **Toggling a bit:** Flipping a bit from `0` to `1` or from `1` to `0` is best done using XOR (`^`). If we mask with `1 << n`, the bit at position `n` flips because `X ^ 1` flips `X`, while `X ^ 0` keeps it unchanged.
- **Reading a bit:** Our goal is to extract the value of a single bit as a normal integer `1` or `0`. To do this, we need to push the target bit over to the very end of the word (the least significant bit) using the Right Shift operator `>> n`. But wait! There might be other bits to its left now that shifted down too. To get rid of those bits, we apply a bitwise AND with a mask of `1`. This zeroes out all higher bits and preserves just our `1` or `0`.

## Assignment
Implement `toggle_bit` and `read_bit`. Note we are still using 8-bit integers (`uint8_t`) for simplicity before tackling 32-bit architecture in the next lesson.

1. `toggle_bit`: Takes `word` and `n`, returns word with bit `n` toggled.
2. `read_bit`: Takes `word` and `n`, and returns either an integer `1` or `0` representing the value of that bit inside the word.
