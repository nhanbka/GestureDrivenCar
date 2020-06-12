#include <AFMotor.h>


AF_DCMotor motorRight(2, MOTOR12_64KHZ);   // create motor #2, 64KHz pwm  
AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // create motor #1, 64KHz pwm

void motorSetup() {
  motorLeft.setSpeed(1000);
  motorRight.setSpeed(1000);
}

void goBackward() {
  // running because of current signal
  Serial.println("Go backward");     
  motorLeft.run(FORWARD);     
  motorRight.run(FORWARD);     
    
//  delay(1000);   
  
  // then stop to wait for another signal
//  motorLeft.run(RELEASE);
//  motorRight.run(RELEASE);

//  delay(100);
}

void turnLeft() {
  // running because of current signal
  Serial.println("Turning left");         
  motorRight.run(BACKWARD);     
  motorLeft.run(RELEASE);  
//  delay(1000);  
   
  // then stop to wait for another signal
//  motorLeft.run(RELEASE);
//  motorRight.run(RELEASE);

//  delay(100);
}

void turnRight() {
  // running because of current signal
  Serial.println("Turning right");       
  motorRight.run(RELEASE);     
  motorLeft.run(BACKWARD);    
//  delay(1000); 

  // then stop to wait for another signal
//  motorLeft.run(RELEASE);
//  motorRight.run(RELEASE);

//  delay(100);
}

void goForward() {
  // running because of current signal
  Serial.println("Go forward");     
  motorLeft.run(BACKWARD);     
  motorRight.run(BACKWARD);      
    
//  delay(1000);    

  // then stop to wait for another signal
//  motorLeft.run(RELEASE);
//  motorRight.run(RELEASE);

//  delay(100);
}


void stopCar() {
  // running because of current signal
 Serial.println("Stop");     
 motorLeft.run(RELEASE);     
 motorRight.run(RELEASE);     
// delay(1000);    

  // then stop to wait for another signal
//  motorLeft.run(RELEASE);
//  motorRight.run(RELEASE);

//  delay(100);
}
