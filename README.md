# 🤖 Autonomous Obstacle-Avoiding Robot Using Ultrasonic Sensor and Dual Motor Driver

This project demonstrates a simple yet effective implementation of an autonomous robot that avoids obstacles using an **HC-SR04 ultrasonic sensor** and **dual DC motors** controlled via an **L298N H-bridge motor driver**. The robot continuously monitors its surroundings and makes real-time decisions to avoid collisions by reversing and turning away from obstacles.

---

## 📦 Features

- **Ultrasonic Distance Measurement**: Uses an HC-SR04 sensor to detect obstacles ahead.
- **Motor Control via H-Bridge**: Controls two DC motors independently using PWM and direction pins.
- **Obstacle Avoidance Logic**: Automatically stops, reverses, and turns when an object is detected within a threshold distance.
- **Modular Functions**: Cleanly separated functions for movement and obstacle handling for easy customization.

---

## 🛠️ Hardware Requirements

- Microcontroller (ESP32 or Arduino)
- HC-SR04 Ultrasonic Sensor
- L298N Motor Driver Module
- 2x DC Motors
- Power Supply (Battery or USB)
- Jumper Wires and Breadboard (optional)

---

## 📐 Pin Configuration

| Component         | Pin Name | GPIO Pin |
|------------------|----------|----------|
| Ultrasonic Sensor| TRIG     | 5        |
| Ultrasonic Sensor| ECHO     | 18       |
| Motor A          | ENA      | 23       |
| Motor B          | ENB      | 22       |
| Motor A          | IN1      | 16       |
| Motor A          | IN2      | 17       |
| Motor B          | IN3      | 19       |
| Motor B          | IN4      | 21       |

---

## ⚙️ Code Overview

### `setup()`
- Initializes serial communication.
- Configures GPIO pins for motor control and ultrasonic sensing.

### `loop()`
- Continuously checks distance using the ultrasonic sensor.
- If an obstacle is detected within 20 cm, executes avoidance maneuver.
- Otherwise, moves forward.

### `getDistance()`
- Triggers the ultrasonic sensor.
- Calculates distance using time-of-flight of the echo signal.

---

## 🔁 Movement Functions

- `moveForward(pwmA, pwmB)`: Moves both motors forward.
- `moveBackward(pwmA, pwmB)`: Moves both motors backward.
- `turnRight(pwmA, pwmB)`: Turns the robot right by rotating motors in opposite directions.
- `stopMotors()`: Stops all motor activity.
- `avoidObstacle()`: Executes the following:
  - Stops motors
  - Reverses briefly
  - Stops again
  - Turns right
  - Stops before resuming forward motion

---

## 🧠 Behavior Logic

- **If distance ≥ 20 cm** → Move forward
- **If distance < 20 cm** → Stop → Reverse → Turn → Resume

This logic can be extended with:
- Left-turn logic
- Randomized direction changes
- Path planning with additional sensors

---

## 📈 Future Enhancements

- Add left-turn logic for flexible navigation
- Integrate IR or bump sensors
- Implement speed control based on proximity
- Add Bluetooth/Wi-Fi for remote control and telemetry

---

## 🧪 Testing Tips

- Test ultrasonic sensor independently for accuracy
- Verify motor direction and PWM response
- Use serial output for debugging and sensor monitoring

---

## 📸 Demo

> Add photos or videos of your robot in action in the `/assets` folder!

---

## 🧠 License

MIT License. Feel free to use, modify, and share!

---

## 🙌 Credits

Created by [Your Name]  
Inspired by open-source robotics and embedded systems projects.
