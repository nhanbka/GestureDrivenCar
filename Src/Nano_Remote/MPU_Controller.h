#define RADIAN 180/M_PI

mpu.dmpGetQuaternion(&q, fifoBuffer);
mpu.dmpGetGravity(&gravity, &q);
mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

Serial.print("ypr\t");
Serial.print(ypr[0] * RADIAN);
Serial.print("\t");
Serial.print(ypr[1] * RADIAN);
Serial.print("\t");
Serial.println(ypr[2] * RADIAN);
if ((ypr[1] * RADIAN) <= -25)
{
	BTSerial.write('R');
	Serial.write('R');
}
else if ((ypr[1] * RADIAN) >= 25)
{
	BTSerial.write('L');
	Serial.write('L');
}
else if ((ypr[2] * RADIAN) <= -25)
{
	BTSerial.write('F');
	Serial.write('F');
}
else if ((ypr[2] * RADIAN) >= 20)
{
	BTSerial.write('B');
	Serial.write('B');
}
else {
	BTSerial.write('S');
	Serial.write('S');
}
