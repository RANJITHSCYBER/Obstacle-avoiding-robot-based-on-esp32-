🚗 Autonomous Obstacle-Avoiding Robot Using Ultrasonic Sensor and Dual Motor Driver
This project demonstrates a simple yet effective implementation of an autonomous obstacle-avoiding robot using an ultrasonic sensor and dual DC motors controlled via an H-bridge motor driver. The robot continuously monitors its surroundings using a distance sensor and makes real-time decisions to avoid collisions by reversing and turning away from obstacles.

📦 Features
Ultrasonic Distance Measurement: Uses a HC-SR04 ultrasonic sensor to detect obstacles in front of the robot.

Motor Control via H-Bridge: Controls two DC motors independently using PWM signals and directional pins.

Obstacle Avoidance Logic: Automatically stops, reverses, and turns when an object is detected within a threshold distance.

Modular Functions: Cleanly separated functions for movement, stopping, and obstacle handling for easy customization and extension.

🛠️ Hardware Requirements
Microcontroller (e.g., ESP32, Arduino)

HC-SR04 Ultrasonic Sensor

L298N Motor Driver Module

Two DC Motors

Power Supply (Battery or USB)

Jumper Wires and Breadboard (optional)

📐 Pin Configuration
Component	Pin Name	GPIO Pin
Ultrasonic Sensor	TRIG	5
Ultrasonic Sensor	ECHO	18
Motor A	ENA	23
Motor B	ENB	22
Motor A	IN1	16
Motor A	IN2	17
Motor B	IN3	19
Motor B	IN4	21
⚙️ Code Overview
setup()
Initializes serial communication and configures all GPIO pins for motor control and ultrasonic sensing.

loop()
Continuously checks the distance in front of the robot. If an obstacle is detected within 20 cm, the robot executes an avoidance maneuver. Otherwise, it moves forward.

getDistance()
Triggers the ultrasonic sensor and calculates the distance to the nearest object using the time-of-flight of the echo signal.

Movement Functions
moveForward(pwmA, pwmB): Moves both motors forward.

moveBackward(pwmA, pwmB): Moves both motors backward.

turnRight(pwmA, pwmB): Turns the robot to the right by rotating motors in opposite directions.

stopMotors(): Stops all motor activity.

avoidObstacle()
Executes a sequence of actions to avoid detected obstacles:

Stops the motors.

Reverses for a short duration.

Stops again.

Turns right.

Stops once more before resuming forward motion.

🧠 Behavior Logic
The robot uses a simple reactive algorithm:

If the path ahead is clear (distance ≥ 20 cm), it moves forward.

If an obstacle is detected (distance < 20 cm), it stops, reverses, and turns to find a new path.

This logic can be extended to include more complex behaviors such as left turns, random direction changes, or path planning using additional sensors.

📈 Future Enhancements
Add left-turn logic for more flexible navigation.

Integrate infrared or bump sensors for enhanced obstacle detection.

Implement speed control based on proximity.

Add Bluetooth or Wi-Fi for remote control and telemetry.

🧪 Testing Tips
Test the ultrasonic sensor independently to ensure accurate distance readings.

Verify motor direction and PWM response before integrating obstacle logic.

Use serial output for debugging and monitoring sensor values.
