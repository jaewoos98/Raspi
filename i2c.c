#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

//YL-40 가변 저항
main()
{
	int fd = wiringPiI2CSetup(0x48);		//dh = device handle
	wiringPiI2CWrite(fd, 3);				//channel 03 (VR) = 가변 저항(Variable Resistor) / 다른 채널번호 사용하면 온도,조도센서 사용가능
	
	while(1)
	{
		int val = wiringPiI2CRead(fd);
		float f = (float)((val/255.0)*5.0);
		printf("VR input level = %d (%4.1fV)\n" , val, f);
		delay(500);
	}
}


