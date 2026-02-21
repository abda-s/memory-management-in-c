# Hardware Registers: GPIO Control (ESP32 / ESP-IDF)

## Background for Beginners

When programming microcontrollers like the ESP32, you interact with physical pins (like turning on an LED or reading a button). The microcontroller controls these pins using **Registers**. 

You can think of a 32-bit Register as a row of 32 light switches in memory. 
- Bit 0 controls Pin 0.
- Bit 1 controls Pin 1.
- ... all the way up to Bit 31 for Pin 31.

In earlier lessons, you learned that to turn on a single bit without messing up the others, you use the bitwise OR operator `|`. 

However, to actually save that new value back into the register, you have to use an assignment operator (`=`). In C, programmers combine these two steps into a shortcut operator: `|=`.

So, writing `REGISTER |= (1U << pin);` is exactly the same as writing:
`REGISTER = REGISTER | (1U << pin);`

### The "Read-Modify-Write" Trap
Because `|=` is just a shortcut for `REGISTER = REGISTER | (1U << pin)`, it forces the CPU to take **three** steps to complete the action:
1. **Read**: The CPU reads the current state of all 32 pins.
2. **Modify**: The CPU changes the one bit you requested.
3. **Write**: The CPU writes all 32 bits back to the register.

Imagine you try to turn on Pin 5 using `|=`. Right after step 1 (Read), but before step 3 (Write), a background Wi-Fi task interrupts your code and turns off Pin 6. When your code finally resumes and does Step 3 (Write), it writes back the *old* state of Pin 6, accidentally turning it back on! This is called a **Race Condition**.

### The ESP32 Solution: W1TS and W1TC
To prevent this, ESP32 hardware engineers designed "magic" registers that only require **one** step (a single write). You don't use `|=` on them; you just use normal assignment `=`.

1. **`GPIO_OUT_W1TS_REG` (Write 1 To Set):**
   Think of this register as a row of "Turn ON" buttons. 
   - If you write a `1` to a bit, the hardware pushes the "Turn ON" button for that pin.
   - If you write a `0` to a bit, the hardware ignores it completely. 
   - Usage: `GPIO_OUT_W1TS_REG = (1U << pin);`

2. **`GPIO_OUT_W1TC_REG` (Write 1 To Clear):**
   Think of this register as a row of "Turn OFF" buttons.
   - If you write a `1` to a bit, the hardware pushes the "Turn OFF" button for that pin.
   - If you write a `0`, it ignores it.
   - Usage: `GPIO_OUT_W1TC_REG = (1U << pin);`

By using `=`, we send a command straight to the hardware in one atomic step, completely avoiding the race condition!

### What is `1U` and why do we NEED it?
In C, the literal number `1` is treated as a **signed** 32-bit integer by default. "Signed" means it can be positive or negative. 

In a 32-bit signed integer, the highest bit (Bit 31) is the "Sign Bit". If Bit 31 is `1`, the computer thinks the number is negative.
If you try to shift `1` into the 31st position (`1 << 31`), you overwrite the sign bit. The C programming language considers this **Undefined Behavior**—it can crash your program or cause weird math bugs!

By writing `1U`, the `U` tells the compiler: **"Treat this number as an UNSIGNED integer."** Unsigned integers cannot be negative, meaning they don't have a sign bit. This allows us to safely shift our `1` all the way to Bit 31 (`1U << 31`) without breaking the code!

## Assignment
You have been given a simulated ESP32 MCU with three global 32-bit registers. Implement the three functions representing standard ESP-IDF actions:

1. `turn_on_led(uint8_t pin)`: Set the `pin` bit high using atomic assignment (`=`) to `GPIO_OUT_W1TS_REG`.
2. `turn_off_led(uint8_t pin)`: Set the `pin` bit low using atomic assignment (`=`) to `GPIO_OUT_W1TC_REG`.
3. `is_button_pressed(uint8_t pin)`: Check if the `pin` bit inside the standard `GPIO_IN_REG` is currently `1`. If it is `1`, return `1`. If `0`, return `0`. (Use standard `&` reading logic here).

*Assume `pin` will be a valid index from 0 to 31. Always use `1U`!*
