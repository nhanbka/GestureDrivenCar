#include <SoftwareSerial.h>
#include "DriveMotor.h"

#define GOING_FORWARD 'F'
#define GOING_FORWARD_SLOW 'f'
#define GOING_FORWARD_FAST 'w'

#define GOING_BACKWARD 'B'
#define GOING_BACKWARD_SLOW 'b'
#define GOING_BACKWARD_FAST 's'

#define TURNING_LEFT 'L'
#define TURNING_LEFT_SLOW 'l'
#define TURNING_LEFT_FAST 'a'

#define TURNING_RIGHT 'R'
#define TURNING_RIGHT_SLOW 'r'
#define TURNING_RIGHT_FAST 'd'

#define STOP 'S'

SoftwareSerial BTserial(2, 3); // RX | TX

char d = 0;
int mode = 0;

void setup() {
  Serial.begin(38400);
  initState();  
  Serial.println("Arduino is ready");
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);

  motorSetup();
  mode = 0;
}

void loop() {
  if (BTserial.available() > 0) {
    d = BTserial.read();
    Serial.println(mode);
    Serial.println(d);
    if (d >= '0' && d < '4') {
      mode = (int)(d - '0');
    } else if (d == GOING_FORWARD) {
      goForward(mode, 1);
    } else if (d == GOING_FORWARD_SLOW){
      goForward(mode, 0);
    } else if (d == GOING_FORWARD_FAST){
      goForward(mode, 2);
    } 
    else if (d == TURNING_RIGHT) {
      turnRight(mode, 1);
    } else if (d == TURNING_RIGHT_SLOW){
      turnRight(mode, 0);
    } else if (d == TURNING_RIGHT_FAST){
      turnRight(mode, 2);
    }
    else if (d == GOING_BACKWARD){
      goBackward(mode, 1);
    } else if (d == GOING_BACKWARD_SLOW){
      goBackward(mode, 0);
    } else if (d == GOING_BACKWARD_FAST){
      goBackward(mode, 2);
    }
    else if (d == TURNING_LEFT) {
      turnLeft(mode, 1);
    } else if (d == TURNING_LEFT_SLOW){
      turnLeft(mode, 0);
    } else if (d == TURNING_LEFT_FAST){
      turnLeft(mode, 2);
    }
    else if (d == STOP) {
      stopCar();
    }
    Serial.println(mode);
  }
}
