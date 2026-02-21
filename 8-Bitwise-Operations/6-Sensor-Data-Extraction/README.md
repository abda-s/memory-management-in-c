# Bit Unpacking: Sensor Data Extraction (32-bit Registers)

## Background
Often, sensors and microcontrollers communicate through standardized protocols. But within a 32-bit SoC like the ESP32, hardware manufacturers pack multiple distinct data fields into single 32-bit memory-mapped registers. 

Let's imagine a simulated Environmental Sensor peripheral that stores its readings in a single 32-bit `sensor_data` register:
- **Bits 0 to 11 (12 bits):** Hold a temperature reading (0 to 4095 scale). 
- **Bits 12 to 23 (12 bits):** Hold a humidity reading (0 to 4095 scale).
- **Bits 24 to 31 (8 bits):** Reserved for status flags.

To extract the temperature value out as a normal integer, you just need to isolate the bottom 12 bits. In C, we mask the data with `0xFFF`. (Hexadecimal `F` represents `1111` in binary. `FFF` corresponds to 12 contiguous ones: `1111 1111 1111`).

To extract the humidity value, you first need to right-shift the register by 12 bits `(sensor_data >> 12)` to slide the 12-bit humidity reading down into the least significant bit positions, and *then* mask with `0xFFF` to zero-out anything remaining to the left (like the status flags).

## Assignment
Write two functions to unpack the 12-bit values from the 32-bit `sensor_data` register.

1. `extract_temperature(uint32_t sensor_data)`: Returns the standard integer value hidden in the bottom 12 bits (0-11).
2. `extract_humidity(uint32_t sensor_data)`: Returns the standard integer value hidden in the next 12 bits (12-23).
