    
// return status after each device operation (0 = success, !0 = error)
uint8_t devStatus;      

// wait for ready
// load and configure the DMP
Serial.println(F("Initializing DMP..."));
devStatus = mpu.dmpInitialize();

// supply your own gyro offsets here, scaled for min sensitivity
mpu.setXGyroOffset(220);
mpu.setYGyroOffset(76);
mpu.setZGyroOffset(-85);
mpu.setZAccelOffset(1788);

// make sure it worked (returns 0 if so)
if (devStatus == 0) {
	// turn on the DMP, now that it's ready
	Serial.println(F("Enabling DMP..."));
	mpu.setDMPEnabled(true);

	// enable Arduino interrupt detection
	Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
	attachInterrupt(0, dmpDataReady, RISING);
	mpuIntStatus = mpu.getIntStatus();

	// set our DMP Ready flag so the main loop() function knows it's okay to use it
	Serial.println(F("DMP ready! Waiting for first interrupt..."));
	dmpReady = true;

	// get expected DMP packet size for later comparison
	packetSize = mpu.dmpGetFIFOPacketSize();
}
else {
	// ERROR!
	// 1 = initial memory load failed
	// 2 = DMP configuration updates failed
	// (if it's going to break, usually the code will be 1)
	Serial.print(F("DMP Initialization failed (code "));
	Serial.print(devStatus);
	Serial.println(F(")"));
}
