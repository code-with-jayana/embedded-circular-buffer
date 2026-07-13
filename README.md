#Embedded Circular Buffer (Ring Buffer) in C

A lightweight, thread-safe-ready, lock-free circular buffer implementation written in pure C. This data structure is optimized for resource-constrained environments like microcontrollers (ARM Cortex-M, ESP32, AVR) to handle asynchronous data streams (e.g., UART, SPI, I2C peripherals) without dynamic memory allocation (`malloc`).

## 📊 How It Works (Architecture)

A circular buffer uses a fixed-size array and two pointers (`head` and `tail`) that wrap around using modulo arithmetic. This eliminates the need to shift elements in memory when data is consumed.

```text
      [ Tail ] -> Reads from here
         |
         v
   +----+----+----+----+----+
   | 10 | 20 | 30 |    |    |   (Capacity: 5 elements)
   +----+----+----+----+----+
                    ^
                    |
                 [ Head ] -> Writes to here next