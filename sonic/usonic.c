#include <stdio.h>
#include <wiringPi.h>
//초음파센서 (HC-SR04)
#define TRIG	8
#define ECHO	9
//Dist 함수는 us.c   안에 있음
//실행파일은 uu
extern double Dist();

int main(int argc, char **argv)
{
	wiringPiSetup();	// pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	while(1)
	{
		printf("Distance : %f(cm)\n", Dist());
		delay(500);
	}

	return 0;
}

