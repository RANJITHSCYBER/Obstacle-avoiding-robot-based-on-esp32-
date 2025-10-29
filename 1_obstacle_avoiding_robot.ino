#define TRIG_PIN 5
#define ECHO_PIN 18

#define ENA 23
#define ENB 22
#define IN1 16
#define IN2 17
#define IN3 19
#define IN4 21

int speedA = 75; // PWM speed for Motor A
int speedB = 75; // PWM speed for Motor B

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int distance = getDistance();

  if (distance < 20) {
    avoidObstacle();
  } else {
    moveForward(speedA, speedB);
  }

  delay(100);
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void moveForward(int pwmA, int pwmB) {
  analogWrite(ENA, pwmA);
  analogWrite(ENB, pwmB);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward(int pwmA, int pwmB) {
  analogWrite(ENA, pwmA);
  analogWrite(ENB, pwmB);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(int pwmA, int pwmB) {
  analogWrite(ENA, pwmA);
  analogWrite(ENB, pwmB);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void avoidObstacle() {
  stopMotors();
  delay(300);

  moveBackward(speedA, speedB);
  delay(400);

  stopMotors();
  delay(200);

  turnRight(speedA, speedB);
  delay(500);

  stopMotors();
  delay(200);
}

