#define Radian 180/M_PI            
Serial.print("ypr\t");
Serial.print(ypr[0] * Radian);
Serial.print("\t");
Serial.print(ypr[1] * Radian);
Serial.print("\t");
Serial.println(ypr[2] * Radian);
if ((ypr[1] * Radian) <= -25)
{
	BTSerial.write('R');
	Serial.write('R');
}
else if ((ypr[1] * Radian) >= 25)
{
	BTSerial.write('L');
	Serial.write('L');
}
else if ((ypr[2] * Radian) <= -25)
{
	BTSerial.write('F');
	Serial.write('F');
}
else if ((ypr[2] * Radian) >= 20)
{
	BTSerial.write('B');
	Serial.write('B');
}
else {
	BTSerial.write('S');
	Serial.write('S');
}
