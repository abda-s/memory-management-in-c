# Advanced Use Case: Moisture Logger (ESP32)

## Background
Imagine you're working with an ESP32 equipped with a moisture sensor. It reports four possible moisture levels (`0` through `3`) every second. You are assigned to program it to record these readings continuously to the SPI Flash chip. 

Since four possible states can be represented mathematically with just **two bits**, a normal 32-bit `uint32_t` integer is more than enough to store one reading. But if you store one `uint32_t` per second, you're using 4 bytes every second!
`4 bytes * 60 * 60 * 24 * 365 = 126.1 Megabytes/year`. 

This is where bitwise optimization prevents system failure. By packing **SIXTEEN** consecutive 2-bit readings into a single 32-bit `uint32_t`, you reduce the storage cost by a factor of 16. Now, the year's data fits into just `~7.8 Megabytes`!

## How To
When writing a multi-bit value into a specific segment of a word, you must:
1. Identify the shift amount. Since each slot takes 2 bits, slot `index` is shifted by `(index * 2)`.
2. **Clear** the bits currently occupying that segment using `&` and an inverted mask. The mask for two bits is `3U` (binary `11`). `~(3U << (index * 2))`.
3. **Shift** your new value up to the correct segment `(value << (index * 2))`.
4. **Set** the new value in the word using `|`.

When reading the value out of that segment:
1. Right shift the word down so the desired slot is at the bottom `(logger_word >> (index * 2))`.
2. Mask the result with `& 3U` to discard higher bits.

## Assignment
Write an optimization library to pack arrays of data coming from the sensor.

1. `pack_reading(uint32_t *logger_word, uint8_t index, uint8_t value)`: You are passing by pointer to permanently modify the 32-bit word. `index` is `0` to `15` (representing 16 slots). The `value` is the moisture reading from the sensor (a number `0`, `1`, `2`, or `3`). Pack it into the word correctly at the slot.
2. `read_reading(uint32_t logger_word, uint8_t index)`: Return the 2-bit integer value stored at slot `index`.
