# ESP8266 Firebase LED Control - Hardware Setup

This project involves controlling an LED connected to an ESP8266 module using Firebase Realtime Database. This document provides the hardware setup and connection instructions for the project.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Required](#hardware-required)
- [Circuit Diagram](#circuit-diagram)
- [Hardware Setup Instructions](#hardware-setup-instructions)
- [License](#license)

## Introduction

This project allows real-time control of an LED connected to the ESP8266 module through Firebase. The LED status can be remotely toggled between ON and OFF via updates in the Firebase Realtime Database.

## Hardware Required

- *ESP8266 module (e.g., NodeMCU)*
- *LED*
- *330Ω resistor* (for the LED)
- *Breadboard*
- *Jumper wires*
- *Wi-Fi access point* (for connectivity)

## Circuit Diagram

Connect the ESP8266 module to an LED and a 330Ω resistor according to the table below.

| ESP8266 Pin | Component               |
|-------------|-------------------------|
| GPIO5 (D1)  | LED Anode (+)            |
| GND         | LED Cathode (-) (through a 330Ω resistor) |

### Note:

- *GPIO5 (D1)* is used to control the LED, which will be turned on or off depending on the signal from the ESP8266.
- The *330Ω resistor* is used to limit the current flowing through the LED to prevent it from burning out.

## Hardware Setup Instructions

1. *Assemble the Circuit*:
   - Connect the *LED Anode (+)* to *GPIO5 (D1)* on the ESP8266 module.
   - Connect the *LED Cathode (-)* to one end of the *330Ω resistor*.
   - Connect the other end of the *resistor* to *GND* on the ESP8266 module.

2. *Check Connections*:
   - Ensure all connections are tight and secure.
   - Double-check the polarity of the LED to avoid reverse connections.

3. *Power Up*:
   - Connect the ESP8266 module to a power source (via USB or a power supply).
   - The LED will be controlled based on the Firebase input.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
