// 4DOF ARM CONTROLLER library
// copyright iuthaytrungVoCungLun @ 2020
// this code is private domain, do not use
// without our permission!!

#include <Servo.h>


//||---------------------------------------||
//||---------------------------------------||
//||---------CODE FOR HAND CONFIG----------||
//||---------------------------------------||
//||---------------------------------------||


// PIN CONFIGURATION
#define JAW_SERVO_PIN 7
#define HEIGHT_SERVO_PIN 5
#define RANGE_SERVO_PIN 6
#define ROTATE_SERVO_PIN 9

// JAW SERVO CONFIGURATION
#define MAX_JAW_SERVO 180
#define MIN_JAW_SERVO 80

// HEIGHT SERVO CONFIGURATION
#define MAX_HEIGHT_SERVO 180
#define MIN_HEIGHT_SERVO 0

// RANGE SERVO CONFIGURATION
#define MAX_RANGE_SERVO 180
#define MIN_RANGE_SERVO 0

// ROTATE SERVO CONFIGURATION
#define MAX_ROTATE_SERVO 180
#define MIN_ROTATE_SERVO 0


//||---------------------------------------||
//||---------------------------------------||
//||-------------HAND VARIABLE-------------||
//||---------------------------------------||
//||---------------------------------------||


Servo jawServo;
Servo heightServo;
Servo rangeServo;
Servo rotateServo;

// variable to store the servo position
int jaw_pos = 100;
int height_pos = 180;
int range_pos = 80;
int rotate_pos = 90;


void initState() {
  jawServo.write(jaw_pos);
  jawServo.attach(JAW_SERVO_PIN);

  heightServo.write(height_pos);
  heightServo.attach(HEIGHT_SERVO_PIN);

  rangeServo.write(range_pos);
  rangeServo.attach(RANGE_SERVO_PIN);

  rotateServo.write(rotate_pos);
  rotateServo.attach(ROTATE_SERVO_PIN);
}


//||---------------------------------------||
//||---------------------------------------||
//||---------CODE FOR HAND ACTION----------||
//||---------------------------------------||
//||---------------------------------------||


void rangeDecrease(int speed_mode) {
  if (range_pos == MIN_RANGE_SERVO) {
    rangeServo.write(range_pos);
    return;
  } else {
    range_pos-=speed_mode;
    rangeServo.write(range_pos);
  }
}

void rangeIncrease(int speed_mode) {
  if (range_pos == MAX_RANGE_SERVO) {
    rangeServo.write(range_pos);
    return;
  } else {
    range_pos+=speed_mode;
    rangeServo.write(range_pos);
  }
}

void heightIncrease(int speed_mode) {
  if (height_pos == MAX_HEIGHT_SERVO) {
    heightServo.write(height_pos);
    return;
  } else {
    height_pos+=speed_mode;
    heightServo.write(height_pos);
  }
}

void heightDecrease(int speed_mode) {
  if (height_pos == MIN_HEIGHT_SERVO) {
    heightServo.write(height_pos);
    return;
  } else {
    height_pos-=speed_mode;
    heightServo.write(height_pos);
  }
}

void rotateRight(int speed_mode) {
  if (rotate_pos == MIN_ROTATE_SERVO) {
    rotateServo.write(rotate_pos);
    return;
  } else {
    rotate_pos-=speed_mode;
    rotateServo.write(rotate_pos);
  }
}

void rotateLeft(int speed_mode) {
  if (rotate_pos == MAX_ROTATE_SERVO) {
    rotateServo.write(rotate_pos);
    return;
  } else {
    rotate_pos+=speed_mode;
    rotateServo.write(rotate_pos);
  }
}

void jawBind(int speed_mode) {
  if (jaw_pos == MIN_JAW_SERVO) {
    jawServo.write(jaw_pos);
    return;
  } else {
    jaw_pos-=speed_mode;
    jawServo.write(jaw_pos);
  }
}

void jawRelease(int speed_mode) {
  if (jaw_pos == MAX_JAW_SERVO) {
    jawServo.write(jaw_pos);
    return;
  } else {
    jaw_pos+=speed_mode;
    jawServo.write(jaw_pos);
  }
}
