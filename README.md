# 🚗 Arduino Ultrasonic Parking Sensor

An Arduino-based parking assistance system that uses an **HC-SR04 ultrasonic sensor** to measure the distance between a vehicle and an obstacle. The system provides real-time feedback through a **16×2 LCD, LEDs, and a buzzer**, helping the driver judge how close the vehicle is to an object.

## 📌 Project Overview

The system continuously measures the distance using the HC-SR04 ultrasonic sensor and changes its warning level based on the detected distance.

| Distance | Status           | LED          | Buzzer         |
| -------- | ---------------- | ------------ | -------------- |
| > 40 cm  | 🟢 Safe          | Green        | Off            |
| 21–40 cm | 🟡 Getting Close | Yellow       | Slow beep      |
| 11–20 cm | 🟠 Caution       | Yellow + Red | Fast beep      |
| ≤ 10 cm  | 🔴 Stop          | Red          | Very fast beep |

The current distance and warning message are displayed on the **16×2 LCD**.

## ⚙️ Features

* 📏 Real-time distance measurement
* 🖥️ 16×2 LCD distance display
* 🟢 Green LED for safe distance
* 🟡 Yellow LED for caution
* 🔴 Red LED for danger
* 🔊 Distance-dependent buzzer alerts
* ⚡ Arduino-based control system
* 📡 HC-SR04 ultrasonic sensing
* 🚗 Designed as a basic parking assistance system

## 🧰 Components Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* 16×2 LCD Display
* 10kΩ Potentiometer for LCD contrast
* Green LED
* Yellow LED
* Red LED
* Piezo Buzzer
* 470Ω Resistors × 3 for LEDs
* 220Ω Resistor for LCD backlight
* Breadboard
* Jumper Wires
* USB Cable / Power Supply

## 🔌 Pin Connections

### HC-SR04

| HC-SR04 Pin | Arduino |
| ----------- | ------- |
| VCC         | 5V      |
| GND         | GND     |
| TRIG        | D7      |
| ECHO        | D6      |

### LEDs

| LED    | Arduino Pin |
| ------ | ----------- |
| Green  | D8          |
| Yellow | D9          |
| Red    | D10         |

Each LED is connected through a **470Ω resistor**.

### Buzzer

| Buzzer   | Arduino |
| -------- | ------- |
| Positive | D13     |
| Negative | GND     |

### LCD 16×2

| LCD Pin | Connection               |
| ------- | ------------------------ |
| RS      | D12                      |
| E       | D11                      |
| D4      | D5                       |
| D5      | D4                       |
| D6      | D3                       |
| D7      | D2                       |
| VSS     | GND                      |
| VDD     | 5V                       |
| V0      | Potentiometer middle pin |
| A       | 5V through 220Ω resistor |
| K       | GND                      |

The potentiometer is used to adjust the **LCD contrast**.

## 🧠 How It Works

The HC-SR04 sends an ultrasonic pulse toward an obstacle.

The sensor measures the time taken for the sound wave to travel to the obstacle and return.

The Arduino then calculates the distance using:

```text
Distance = (Time × Speed of Sound) / 2
```

The division by 2 is required because the ultrasonic pulse travels **to the obstacle and back**.

The Arduino compares the measured distance with predefined thresholds and controls the LCD, LEDs, and buzzer accordingly.

## 🔄 System Flow

```text
HC-SR04
   ↓
Measure Distance
   ↓
Arduino Uno
   ↓
Compare Distance
   ↓
┌───────────────┬──────────────┬──────────────┐
↓               ↓              ↓
LCD             LEDs          Buzzer
↓               ↓              ↓
Distance       Warning       Alert Rate
& Status        Level         Changes
```

## 💻 Software

### Programming Language

* C/C++ (Arduino)

### Arduino Library

* `LiquidCrystal`

### Development Environment

* Arduino IDE

## 🚦 Distance Logic

The system uses four warning levels:

### 🟢 Safe

**Distance > 40 cm**

The vehicle is far enough from the obstacle.

* Green LED ON
* Yellow LED OFF
* Red LED OFF
* Buzzer OFF

### 🟡 Slow Down

**21–40 cm**

The vehicle is getting closer.

* Yellow LED ON
* Green LED OFF
* Red LED OFF
* Slow buzzer

### 🟠 Caution

**11–20 cm**

The vehicle is close to the obstacle.

* Yellow LED ON
* Red LED ON
* Fast buzzer

### 🔴 Stop

**≤ 10 cm**

The vehicle is very close to the obstacle.

* Red LED ON
* Green LED OFF
* Yellow LED OFF
* Very fast buzzer

## 📂 Project Structure

```text
Parking-Sensor/
│
├── Parking_Sensor.ino
└── README.md
```

## 🎯 Applications

* Car parking assistance
* Garage parking systems
* Obstacle detection
* Robotics
* Smart parking prototypes
* Embedded systems learning
* Arduino-based automation projects

## 🔮 Future Improvements

The project can be expanded with:

* 📱 Bluetooth/Wi-Fi monitoring
* 📊 Distance history and data logging
* 📷 Camera-based parking assistance
* 🅿️ Multiple ultrasonic sensors
* 📲 Mobile application
* 🔔 Adjustable warning thresholds
* 🔋 Battery-powered operation
* 🤖 Automatic braking integration
* 🌐 IoT-based parking monitoring

## 👨‍💻 Author

**Nikunj Purohit**

B.Tech Electrical and Computer Engineering

This project was developed as an embedded systems and Arduino-based automation project.
