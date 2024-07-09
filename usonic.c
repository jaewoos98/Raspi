#include <stdio.h>
#include <wiringPi.h>

#define TRIG	8
#define ECHO	9

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

