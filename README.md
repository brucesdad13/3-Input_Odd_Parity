# Three-Bit Binary Odd Parity Generator

This repository contains the Arduino code and schematic for a three-bit binary odd parity generator. The project utilizes TTL logic gates including two 74LS04 hex inverters, two 74LS10 triple 3-input NAND gates, and a 74LS32 quad 2-input OR gate to construct the parity generator.

## Description

The Arduino Nano drives the circuit by setting inputs for all permutations of the 3-bit binary odd parity function. The final output from the 74LS32 represents the odd parity bit, which the Nano reads back. This circuit was created with parts on-hand for educational purposes and does not represent an optimal design.

## Features

- **Circuit Integration**: Combines multiple TTL logic families to demonstrate a functional parity generator.
- **Serial Monitoring**: Outputs the parity bit's state to the Arduino's serial monitor for real-time observation.
- **Modular Code**: Easily adaptable codebase for experimenting with different logic configurations or educational purposes.

## Hardware Requirements

- Arduino Nano V3
- 2 x 74LS04 hex inverters
- 2 x 74LS10 triple 3-input NAND gates
- 1 x 74LS32 quad 2-input OR gate
- Breadboard and jumper wires
- External power supply (if required)

## Software Requirements

- Platform IO or Arduino IDE (comment out Arduino.h for Arduino IDE)
- Serial Monitor for output viewing (built-in to IDE)
- Oscilloscope for verifying operation (optional)

## Setup and Configuration

1. **Wiring**: Connect the Arduino output pins to the input of the 74LS04 and 74LS10 as depicted in the wiring diagram below. Wire outputs from the 74LS04 to the inputs of the 74LS10. Connect outputs from the 74LS10 to another 74LS04 for inversion. Finally, connect these outputs to the 74LS32, configured to act as a 4-input OR gate.
2. **Flashing the Code**: Open the provided `main.cpp` in VSCode or the Arduino IDE. Configure your board and port under the Tools menu and upload the sketch.

## Usage

Once the Arduino is programmed and the circuit is powered up, the Arduino will begin cycling through input permutations and display the resulting parity bit on the serial monitor. This allows for real-time tracking and troubleshooting of the parity generation process.

## Images

![LogiSim sketch of the 3-bit odd parity circuit](https://github.com/brucesdad13/3-Input_Odd_Parity/blob/main/images/LogiSim.png)
![Breadboard wiring example for a Nano v3 driven 3-bit odd parity circuit using TTL logic devices](https://github.com/brucesdad13/3-Input_Odd_Parity/blob/main/images/Breadboard.jpg)
![Oscilloscope capture demonstrating a working 3-input odd parity circuit](https://github.com/brucesdad13/3-Input_Odd_Parity/blob/main/images/Oscilloscope.png)

## Contributing

Contributions to the project are welcome. Please fork the repository and submit a pull request with your enhancements.

## License

This project is released under the MIT License. See the `LICENSE` file for more details.

## Contact

For any queries regarding this project, please contact Charles Stevenson (brucesdad13@gmail.com)
