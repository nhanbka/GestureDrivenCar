#include <SoftwareSerial.h>
#include <AFMotor.h>

#define GOING_FORWARD 'F'
#define GOING_BACKWARD 'B'
#define TURNING_LEFT 'L'
#define TURNING_RIGHT 'R'
#define STOP 'S'

 
AF_DCMotor motor2(2, MOTOR12_64KHZ);   // create motor #2, 64KHz pwm  
AF_DCMotor motor1(1, MOTOR12_64KHZ);  // create motor #1, 64KHz pwm
SoftwareSerial BTserial(2, 3); // RX | TX 

char d = 0; 

void setup() {
  Serial.begin(38400);
  Serial.println("Arduino is ready");
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);
  
  motor1.setSpeed(1000);  
  motor2.setSpeed(1000);
}

void goingBackward() {
  // running because of current signal
  Serial.println("Go backward");     
  motor1.run(FORWARD);     
  motor2.run(FORWARD);     
    
  delay(1000);   
  
  // then stop to wait for another signal
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  delay(100);
}

void turningLeft() {
  // running because of current signal
  Serial.println("Turning left");         
  motor1.run(RELEASE);     
  motor2.run(FORWARD);    
  delay(1000);  
   
  // then stop to wait for another signal
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  delay(100);
}

void turningRight() {
  // running because of current signal
  Serial.println("Turning right");       
  motor1.run(FORWARD);     
  motor2.run(RELEASE);   
  delay(1000); 

  // then stop to wait for another signal
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  delay(100);
}

void goingForward() {
  // running because of current signal
  Serial.println("Go forward");     
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);      
    
  delay(1000);    

  // then stop to wait for another signal
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  delay(100);
}


void stopCar() {
  // running because of current signal
 Serial.println("Stop");     
 motor1.run(RELEASE);     
 motor2.run(RELEASE);     
 delay(1000);    

  // then stop to wait for another signal
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  delay(100);
}

void loop() {
  if(BTserial.available() > 0){
    d = BTserial.read();
    Serial.println(d);
    if(d == GOING_FORWARD){
      goingForward();
    }
    if(d == TURNING_RIGHT){
      turningRight();
    }
    if(d == GOING_BACKWARD){
      goingBackward();
    }
     if(d == TURNING_LEFT){
      turningLeft();
    }
    if(d == STOP){
      stopCar();
    }
  }
}
