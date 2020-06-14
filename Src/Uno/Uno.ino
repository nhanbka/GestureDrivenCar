#include <SoftwareSerial.h>
#include "DriveMotor.h"


#define GOING_FORWARD 'F'
#define GOING_BACKWARD 'B'
#define TURNING_LEFT 'L'
#define TURNING_RIGHT 'R'
#define STOP 'S'


SoftwareSerial BTserial(2, 3); // RX | TX 


char d = 0; 

void setup() {
  Serial.begin(38400);
  Serial.println("Arduino is ready");
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);

  motorSetup();
}


void loop() {
  if(BTserial.available() > 0){
    d = BTserial.read();
    Serial.write(d);
    if(d == GOING_FORWARD){
      goForward();
    }
    if(d == TURNING_RIGHT){
      turnRight();
    }
    if(d == GOING_BACKWARD){
      goBackward();
    }
     if(d == TURNING_LEFT){
      turnLeft();
    }
    if(d == STOP){
      stopCar();
    }
  }
}