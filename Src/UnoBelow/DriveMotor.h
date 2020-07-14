#include <AFMotor.h>

// DEFINE MODE OF CAR AND ARM
#define CAR 0
#define JAW 1
#define HEIGHT 2
#define RANGE 3

#define Forward BACKWARD
#define Backward FORWARD

AF_DCMotor motorRight(2, MOTOR12_64KHZ);   // create motor #2, 64KHz pwm
AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // create motor #1, 64KHz pwm

int speedMode[3] = {150, 200, 255};

void motorSetup() {
  motorLeft.setSpeed(speedMode[0]);
  motorRight.setSpeed(speedMode[0]);
}

void setMotorSpeed(int speed_mode) {
  motorRight.setSpeed(speedMode[speed_mode]);
  motorLeft.setSpeed(speedMode[speed_mode]);
}

void goBackward(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Go backward");
    motorLeft.run(Backward);
    motorRight.run(Backward);
  }
}

void turnLeft(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Turning left");
    motorRight.run(Forward);
    motorLeft.run(Backward);
  }
}

void turnRight(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Turning right");
    motorRight.run(Backward);
    motorLeft.run(Forward);
  }
}

void goForward(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Go forward");
    motorLeft.run(Forward);
    motorRight.run(Forward);
  }
}

void stopCar() {
  Serial.println("Stop");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}