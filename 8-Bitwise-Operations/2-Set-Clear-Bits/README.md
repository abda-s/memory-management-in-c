# Setting and Clearing Bits

## Background
There's no straightforward way to directly modify a single bit inside a word using memory commands because memory operations always work on the whole byte. The trick is to create a second word that contains all zeros except for a one at the exact position `n`. We call this extra value a **mask**.

To create this mask generically, we start with the number 1 (`00000001`) and shift it to the left `n` times using `(1 << n)`.

- **To set a bit:** We apply a bitwise `|` (OR) between our original word and this new mask. No matter what the original value of bit `n` was, the result will have a `1` in that position. All other bits remain unchanged because `0 | X = X`.
- **To clear a bit:** We need a mask with `0` at position `n` and `1` everywhere else. The bitwise `&` (AND) forces the output bit to `0` because `X & 0 = 0`, but leaves the rest untouched (`X & 1 = X`). We get this mask by inverting our set mask: `~(1 << n)`.

*Note: For these early lessons, we are keeping things simple using 8-bit integers (`uint8_t`). When you progress to 32-bit registers, you will use `1U << n` instead of `1 << n`.*

## Assignment
Implement `set_bit` and `clear_bit` in `exercise.c`. Note that in bit-indexing, it starts at 0 (the least significant bit is bit 0).

1. `set_bit`: Takes a `uint8_t word` and an `uint8_t n`, returns the word with bit `n` set to `1`.
2. `clear_bit`: Takes a `uint8_t word` and an `uint8_t n`, returns the word with bit `n` cleared to `0`.
