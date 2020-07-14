#include "arm_controller.h"

// DEFINE MODE OF CAR AND ARM
#define CAR 0
#define JAW 1
#define HEIGHT 2
#define RANGE 3

#define Forward BACKWARD
#define Backward FORWARD

void goBackward(int mode, int speed_mode) {
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

void turnLeft(int mode, int speed_mode) {
  if (mode != CAR) {
    Serial.println("Rotate left");
    rotateLeft(speed_mode + 1);
  }
}

void turnRight(int mode, int speed_mode) {
  if (mode != CAR) {
    Serial.println("Rotate right");
    rotateRight(speed_mode + 1);
  }
}

void goForward(int mode, int speed_mode) {
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

void stopCar() {
  Serial.println("Stop");
}
