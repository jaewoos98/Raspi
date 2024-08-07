#include <stdio.h>
#include <wiringPi.h>
//GPIO PWM
#define wPi_22		22			// wPi number 22번 사용
// LED 밝기조절
int main(int n, char *s[])
{
	int period;
	int dr, drh, drl;			// dr = duty rate , drh = duty rate high, drl = duty rate low
	
	if(n < 2)
	{
		printf("usage : pwm [duty_rate(%)] [period]\n\n");
		return 1;
	}
	
	period = 10;
	sscanf(s[1],"%d",&dr);
	drh = (dr * period) / 100;
	drl = period - drh;
			
	wiringPiSetup();		// wiringPi pin number 사용 선언	
	
	pinMode(wPi_22, OUTPUT);
	for(int i =0; i<100; i++)
	{
		digitalWrite(wPi_22, HIGH);
		delay(drh);
		digitalWrite(wPi_22, LOW);
		delay(drl);
	}
	return 0;
}
