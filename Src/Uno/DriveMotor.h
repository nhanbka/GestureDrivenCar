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

void motorSetup() {
  motorLeft.setSpeed(1000);
  motorRight.setSpeed(1000);
}

void goBackward(int mode) {
  if (mode == CAR) {
    Serial.println("Go backward");
    motorLeft.run(Backward);
    motorRight.run(Backward);
  } else {
    if (mode == JAW) {
      Serial.println("Release jaw");
      jawRelease();
    }
    
    if (mode == HEIGHT) {
      Serial.println("Increase height");
      heightIncrease();
    }
    
    if (mode == RANGE) {
      Serial.println("Decrease range");
      rangeDecrease();
    }
  }
}

void turnLeft(int mode) {
  if (mode == CAR) {
    Serial.println("Turning left");
    motorRight.run(Forward);
    motorLeft.run(Backward);
  } else {
    Serial.println("Rotate left");
    rotateLeft();
  }
}

void turnRight(int mode) {
  if (mode == CAR) {
    // running because of current signal
    Serial.println("Turning right");
    motorRight.run(Backward);
    motorLeft.run(Forward);
  } else {
    Serial.println("Rotate right");
    rotateRight();
  }
}

void goForward(int mode) {
  if (mode == CAR) {
    Serial.println("Go forward");
    motorLeft.run(Forward);
    motorRight.run(Forward);
  } else {
    if (mode == JAW) {
      Serial.println("Bind jaw");
      jawBind();
    }

    if (mode == HEIGHT) {
      Serial.println("Decrease height");
      heightDecrease();
    }

    if (mode == RANGE) {
      Serial.println("Increase range");
      rangeIncrease();
    }
  }
}


void stopCar() {
  Serial.println("Stop");
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}
