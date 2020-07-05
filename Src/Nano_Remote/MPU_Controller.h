#define RADIAN 180/M_PI

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

int turn_angle;       // to make a decision whether to turn left or right
int move_direction;   // to make a decision whether to go forward or backward
mpu.dmpGetQuaternion(&q, fifoBuffer);
mpu.dmpGetGravity(&gravity, &q);
mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

turn_angle = ypr[1] * RADIAN;
move_direction = ypr[2] * RADIAN;
Serial.print("ypr\t");
Serial.print(ypr[0] * RADIAN);
Serial.print("\t");
Serial.print(ypr[1] * RADIAN);
Serial.print("\t");
Serial.println(ypr[2] * RADIAN);

// For turning right
if (turn_angle <= -15 && turn_angle >= -30){
	BTSerial.write(TURNING_RIGHT_SLOW);
	Serial.write(TURNING_RIGHT_SLOW);
} else if (turn_angle < -30 && turn_angle >= -50){
  BTSerial.write(TURNING_RIGHT);
  Serial.write(TURNING_RIGHT);
} else if (turn_angle < -50){
  BTSerial.write(TURNING_RIGHT_FAST);
  Serial.write(TURNING_RIGHT_FAST);
}
// For turning left
else if (turn_angle >= 15 && turn_angle <= 30){
	BTSerial.write(TURNING_LEFT_SLOW);
	Serial.write(TURNING_LEFT_SLOW);
} else if (turn_angle > 30 && turn_angle <= 50){
  BTSerial.write(TURNING_LEFT);
  Serial.write(TURNING_LEFT);
} else if (turn_angle > 50){
  BTSerial.write(TURNING_LEFT_FAST);
  Serial.write(TURNING_LEFT_FAST);
}
// For going forward
else if (move_direction <= -15 && move_direction >= -25){
	BTSerial.write(GOING_FORWARD_SLOW);
	Serial.write(GOING_FORWARD_SLOW);
} else if (move_direction < -25 && move_direction >= -40){
  BTSerial.write(GOING_FORWARD);
  Serial.write(GOING_FORWARD);
} else if (move_direction < -40){
  BTSerial.write(GOING_FORWARD_FAST);
  Serial.write(GOING_FORWARD_FAST);
}
// For going backward
else if (move_direction >= 15 && move_direction <= 25) {
	BTSerial.write(GOING_BACKWARD_SLOW);
	Serial.write(GOING_BACKWARD_SLOW);
} else if (move_direction > 25 && move_direction <= 40) {
  BTSerial.write(GOING_BACKWARD);
  Serial.write(GOING_BACKWARD);
} else if (move_direction > 40) {
  BTSerial.write(GOING_BACKWARD_FAST);
  Serial.write(GOING_BACKWARD_FAST);
}
else {
	BTSerial.write(STOP);
	Serial.write(STOP);
}
