#include <wiringPi.h>
#include <stdio.h>

#define RED		 7
#define GREEN	 8
#define YELLOW	 9
#define SW		 2

int ps[40];								// pin number : 40, pin status array , default status : 0
void toggle(int pin)	
{
	ps[pin] = !ps[pin];				// reverse the status
	digitalWrite(pin, ps[pin]);	
}

int main()
{
	wiringPiSetup();					// reset function
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);

	int mode = 0;
	int intv = 2;						// delay time of interval
	int time;
	for(;;)
	{
		time =(9- intv)*100;
		if(mode)
		{
			toggle(RED);
			delay(time);
			toggle(GREEN);
			delay(time);
			toggle(YELLOW);
			delay(time);
		}
		else
		{
			toggle(YELLOW);
			delay(time);
			toggle(GREEN);
			delay(time);
			toggle(RED);
			delay(time);
		}
		int sw = digitalRead(SW);
		if(sw == 0)						// button pushed
		{
			intv++;
		}
		if(intv>8)
		{
			intv=1;
		}

	}
	return 0;
}
