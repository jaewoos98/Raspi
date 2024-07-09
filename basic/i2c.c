#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

//YL-40 가변 저항
main()
{
	int dh = wiringPiI2CSetup(0x48);			//dh = device handle
	
	while(1)
	{
		wiringPiI2CWrite(dh, 00);						//channel 00 (LDR) = 조도 센서(Light-Dependent Resistor)
		wiringPiI2CRead(dh);							//채널 변경 간 이전 값을 초기화시킴
		int v1 = wiringPiI2CRead(dh);
		delay(100);
		
		wiringPiI2CWrite(dh, 01);						//channel 01 (TS) = 온도 센서(Temperature Sensitive)
		wiringPiI2CRead(dh);
		int v2 = wiringPiI2CRead(dh);
		delay(100);
		
		wiringPiI2CWrite(dh, 03);						//channel 03 (VR) = 가변 저항(Variable Resistor)
		wiringPiI2CRead(dh);
		int v3 = wiringPiI2CRead(dh);
		delay(100);
		
		float f1 = (float)((v1/255.0)*5.0);
		float f2 = (float)((v2/255.0)*5.0);
		float f3 = (float)((v3/255.0)*5.0);
		
		printf("LDR = %d (%4.1fV), TS = %d (%4.1fV), VR = %d (%4.1fV)\n" , v1, v2, v3, f1, f2, f3);
		delay(500);
	}
}


// 조이스틱 연결 테스트!
// x축이 Ain0, y축이 Ain1
// x축을 바꾸면 조도, y축 바꾸면 온도
