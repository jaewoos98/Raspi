#include <stdio.h>
#include <wiringPi.h>

#define SERVO_PIN 1
int main(int argc, char **argv)
{
	wiringPiSetup();
	pinMode(SERVO_PIN, OUTPUT);
	
	for(int j=0;j<100;j++)
	{
		for(int i=0;i<10;i++)
		{
			digitalWrite(SERVO_PIN, HIGH);
			delayMicroseconds(1000);
			digitalWrite(SERVO_PIN, LOW);
			delayMicroseconds(19000);
		}
		
		for(int i=0;i<10;i++)
		{
			digitalWrite(SERVO_PIN, HIGH);
			delayMicroseconds(2000);
			digitalWrite(SERVO_PIN, LOW);
			delayMicroseconds(18000);
		}
	}
	return 0;
}
