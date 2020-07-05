#include <AFMotor.h>
#include "arm_controller.h"

// DEFINE MODE OF CAR AND ARM
#define CAR 0
#define JAW 1
#define HEIGHT 2
#define RANGE 3

#define Forward BACKWARD
#define Backward FORWARD

AF_DCMotor motorRight(2, MOTOR12_64KHZ);   // create motor #2, 64KHz pwm
AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // create motor #1, 64KHz pwm

int speedMode[3] = {50, 100, 3-00};

void motorSetup() {
  motorLeft.setSpeed(100);
  motorRight.setSpeed(100);
}

void setMotorSpeed(int speed_mode) {
  motorLeft.setSpeed(speedMode[speed_mode]);
  motorRight.setSpeed(speedMode[speed_mode]);
}

void goBackward(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Go backward");
    motorLeft.run(Backward);
    motorRight.run(Backward);
  } else {
    if (mode == JAW) {
      Serial.println("Release jaw");
      jawRelease(speed_mode + 1);
    }
    if (mode == HEIGHT) {
      Serial.println("Increase height");
      heightIncrease(speed_mode + 1);
    }
    if (mode == RANGE) {
      Serial.println("Decrease range");
      rangeDecrease(speed_mode + 1);
    }
  }
}

void turnLeft(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Turning left");
    motorRight.run(Forward);
    motorLeft.run(Backward);
  } else {
    Serial.println("Rotate left");
    rotateLeft(speed_mode + 1);
  }
}

void turnRight(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Turning right");
    motorRight.run(Backward);
    motorLeft.run(Forward);
  } else {
    Serial.println("Rotate right");
    rotateRight(speed_mode + 1);
  }
}

void goForward(int mode, int speed_mode) {
  if (mode == CAR) {
    setMotorSpeed(speed_mode);
    Serial.println("Go forward");
    motorLeft.run(Forward);
    motorRight.run(Forward);
  } else {
    if (mode == JAW) {
      Serial.println("Bind jaw");
      jawBind(speed_mode + 1);
    }
    if (mode == HEIGHT) {
      Serial.println("Decrease height");
      heightDecrease(speed_mode + 1);
    }
    if (mode == RANGE) {
      Serial.println("Increase range");
      rangeIncrease(speed_mode + 1);
    }
  }
}


void stopCar() {
  Serial.println("Stop");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}
