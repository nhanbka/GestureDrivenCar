#include <AFMotor.h>
#define Forward BACKWARD
#define Backward FORWARD

AF_DCMotor motorRight(2, MOTOR12_64KHZ);   // create motor #2, 64KHz pwm  
AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // create motor #1, 64KHz pwm

void motorSetup() {
  motorLeft.setSpeed(1000);
  motorRight.setSpeed(1000);
}

void goBackward() {
  // running because of current signal
  Serial.println("Go backward");     
  motorLeft.run(Backward);     
  motorRight.run(Backward);     
}

void turnLeft() {
  // running because of current signal
  Serial.println("Turning left");         
  motorRight.run(Forward);     
  motorLeft.run(Backward);  
}

void turnRight() {
  // running because of current signal
  Serial.println("Turning right");   
  motorRight.run(Backward);      
  motorLeft.run(Forward);     
}

void goForward() {
  // running because of current signal
  Serial.println("Go forward");     
  motorLeft.run(Forward);     
  motorRight.run(Forward);      
}


void stopCar() {
  // running because of current signal
 Serial.println("Stop");     
 motorLeft.run(RELEASE);     
 motorRight.run(RELEASE);     
}
