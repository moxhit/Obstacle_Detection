# ESP32 Ultrasonic Sensor and Servo Control

This project demonstrates how to use an ESP32 to control two servos based on the readings from an ultrasonic sensor. The first servo sweeps back and forth, and when the ultrasonic sensor detects an object closer than 10 cm, the second servo moves to the detected angle.

## Components Used

- ESP32 Development Board
- Ultrasonic Sensor (HC-SR04)
- Two Servo Motors
- Jumper Wires
- Breadboard

## Circuit Diagram

![Circuit Diagram](path_to_circuit_diagram_image)

## Connections

### Ultrasonic Sensor
- VCC to 5V (or 3.3V if your sensor supports it)
- GND to GND
- Trig to GPIO 12
- Echo to GPIO 14

### Servos
- Servo 1 Signal to GPIO 2
- Servo 2 Signal to GPIO 4
- VCC to 5V
- GND to GND

## Code

The code for this project can be found in the [GitHub repository](https://github.com/yourusername/ESP32-Ultrasonic-Servo-Control).

## Installation

1. Clone this repository.
    ```sh
    git clone https://github.com/yourusername/ESP32-Ultrasonic-Servo-Control.git
    ```
2. Open the project in your preferred Arduino IDE or PlatformIO.
3. Connect your ESP32 and upload the code.

## Usage

1. Assemble the circuit as per the connection diagram.
2. Upload the code to your ESP32.
3. Open the Serial Monitor to observe the distance readings and servo actions.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
