#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX 
// Replace 2,3 with any pin you use on the board
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX
char c = ' ';
void setup() {
  Serial.begin(9600);
  Serial.println("Arduino is ready");
  Serial.println("Remember to select Both NL & CR in the serial monitor");
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);
}
void loop() {
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTserial.available()) {
    c = BTserial.read();
    Serial.write(c);
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available()) {
    c = Serial.read();
    BTserial.write(c);
  }
}
