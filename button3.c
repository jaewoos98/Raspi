#include <wiringPi.h>
#include <stdio.h>

#define RED		 7
#define GREEN	 8
#define YELLOW	 9
#define SW		 2


int mode = 0;
int intv = 0;						// delay time of interval
int time;
int ps[40];							// pin number : 40, pin status array , default status : 0

void toggle(int pin)	
{
	ps[pin] = !ps[pin];				// reverse the status
	digitalWrite(pin, ps[pin]);	
}

void gpioisr()						// setting ISR 
{
		if(++intv > 8) intv = 0;
		printf("GPIO interrupt occured...\n");
}		

int main()
{
	wiringPiSetup();				// reset function
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);				// registration GPIO ISR
	
	for(;;)
	{
		time =(9- intv)*100;
		
		if(mode)											// only "else" working
		{
			toggle(RED);	delay(time);
			toggle(GREEN);	delay(time);
			toggle(YELLOW);	delay(time);
		}
		else
		{
			toggle(YELLOW);	delay(time);
			toggle(GREEN);	delay(time);
			toggle(RED);	delay(time);
		}
	}
	return 0;
}
