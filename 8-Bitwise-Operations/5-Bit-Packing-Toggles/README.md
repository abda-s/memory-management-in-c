# Bit Packing: UI Toggles (32-bit)

## Background
Imagine an app with 50 million users. A single settings screen might contain many toggle switches. We naturally map toggles to `boolean` values (`true`/`false`). However, memory hardware cannot store individual bits; the smallest unit in memory is a `byte` (8 bits), and declaring independent variables might even align them to 32-bit boundaries causing even *more* wasted space!

To write a memory-efficient embedded system, we should pack multiple configuration states into a single unit. In a 32-bit system like ESP32, you can seamlessly pack **thirty-two** different boolean toggle states into a single `uint32_t` (a 32-bit unsigned integer) word. This means setting 32 toggles costs exactly 4 bytes of memory, instead of 32 bytes (or even 128 bytes depending on struct padding!).

## Assignment
You are assigned the task of writing an app settings manager. 32 toggle values correspond to indices `0` through `31`.
Write three functions representing standard operations for an efficient UI menu logic. 

1. `turn_on_setting(uint32_t *settings_word, uint8_t index)`: Toggles setting index `index` to ON (`1`). Notice we are passing by pointer so it modifies the `uint32_t` permanently.
2. `turn_off_setting(uint32_t *settings_word, uint8_t index)`: Toggles setting `index` OFF (`0`).
3. `is_setting_on(uint32_t settings_word, uint8_t index)`: Returns `1` if the setting is ON, or `0` if OFF.

*Don't forget `1U` for bit shifting on 32-bit integers!*
