#include <SoftwareSerial.h>
#include "DriveMotor.h"

#define GOING_FORWARD 'F'
#define GOING_BACKWARD 'B'
#define TURNING_LEFT 'L'
#define TURNING_RIGHT 'R'
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
      goForward(mode);
    } else if (d == TURNING_RIGHT) {
      turnRight(mode);
    } else if (d == GOING_BACKWARD){
      goBackward(mode);
    } else if (d == TURNING_LEFT) {
      turnLeft(mode);
    } else if (d == STOP) {
      stopCar();
    }
    Serial.println(mode);
  }
}
