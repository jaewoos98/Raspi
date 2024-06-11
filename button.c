#include <wiringPi.h>
#include <stdio.h>

int ps[40];				// pin number : 40, pin status array , default status : 0
void toggle(int pin)
{
	ps[pin] = !ps[pin];				// reverse the status
	digitalWrite(pin, ps[pin]);	
}

int main()
{
	wiringPiSetup();					// reset function
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(2, INPUT);

	int mode =0;

	for(;;)
	{
		if(mode)
		{
		toggle(7);
		delay(200);
		toggle(8);
		delay(200);
		toggle(9);
		delay(200);
		}
		else
		{
			toggle(9);
			delay(200);
			toggle(8);
			delay(200);
			toggle(7);
			delay(200);
		}
		int sw = digitalRead(2);
		if(sw == 0)						// button pushed
		{
			mode = !mode;
		}
	}
	return 0;
}

