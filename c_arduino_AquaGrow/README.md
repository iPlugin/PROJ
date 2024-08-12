# Automatic Plant Watering System

This project is an **Automatic Plant Watering System** that monitors the light intensity and soil humidity levels to automate the watering process for plants. The system reads data from light and humidity sensors and controls a watering pump based on predefined thresholds. The project is developed using an Arduino board.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Maintaining the right moisture levels in soil is crucial for plant health. This project aims to automate the watering process, ensuring that plants receive water when they need it, based on real-time sensor data.

## Features

- **Light Sensor Monitoring**: Measures the intensity of ambient light.
- **Humidity Sensor Monitoring**: Tracks soil moisture levels.
- **Automatic Watering**: Activates a water pump if the light level is sufficient and the soil moisture is low.
- **Serial Monitoring**: Displays real-time sensor data on the Serial Monitor.

## Components

- Arduino Board (e.g., Uno, Nano)
- Light Sensor (e.g., LDR or Photocell)
- Soil Moisture Sensor
- Water Pump
- Relay Module (for controlling the water pump)
- Jumper Wires
- Breadboard
- Power Supply

## Circuit Diagram

![Circuit Diagram](link-to-your-circuit-diagram-image)

The circuit is simple:
- The light sensor is connected to the analog pin `A1`.
- The soil moisture sensor is connected to the analog pin `A0`.
- The water pump is connected to the digital pin `2` through a relay module.

## Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/automatic-plant-watering-system.git
    ```
2. **Open the project** in the Arduino IDE.
3. **Upload the code** to your Arduino board.

## Usage

1. **Power the Arduino board**.
2. **Monitor the Serial Monitor** in the Arduino IDE to observe the sensor readings.
3. **Observe the water pump**: It should turn on when the light level is above 40% and the soil moisture is below 60%.

## Contributing

Contributions are welcome! If you have any suggestions, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
