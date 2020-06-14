#include "arm_controller.h"

void setup(){
  Serial.begin(9600);
  initState();        
  
  // init the first position and attach PIN
  Serial.print("Robot Hand Mode");

}

void loop(){
  int i;
  for(i = 0; i < 50; i++){
    rangeIncrease();
    delay(30);
  }
  for(i = 0; i < 50; i++){
    heighIncrease();
    delay(30);
  }
  for(i = 0; i < 50; i++){
    heighDecrease();
    delay(30);
  }
    for(i = 0; i < 50; i++){
    rangeDecrease();
    delay(30);
  }
}
