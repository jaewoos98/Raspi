#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	printf("\033[2J");		//escape sequence
							//\033 : 0x1b(0001 1011) - escape sequance 사용
							//[2J : clear screen
	int dh = wiringPiI2CSetup(0x48);			//dh = device handle
	
	while(1)
	{
		wiringPiI2CWrite(dh, 00);	wiringPiI2CRead(dh);	// x 좌표
		int x = wiringPiI2CRead(dh);	// 0 ~ 255
		int xv = x * 80 / 255;			// x좌표를 맞게 설정
		delay(100);
		
		wiringPiI2CWrite(dh, 01);	wiringPiI2CRead(dh);	// y 좌표
		int y = wiringPiI2CRead(dh);	// 0 ~ 255
		int yv = y * 24 / 255;
		delay(100);
		
		//int xv = ((float)x/80.0)*5.0);
		//int yv = ((float)y/24.0)*5.0);
		
		printf("\033[%d;%dH(%d, %d)\n", yv, xv, xv, yv);	//[y;xH : 해당 좌표로 커서 이동 
		delay(500);
	}

	return 0;
}
