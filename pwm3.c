#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
//LED
#define wPi_Pin	22

int main(int n, char *s[])
{
	int period;
	int dr, drh, drl;			// dr = duty rate , drh = duty rate high, drl = duty rate low
	
	if(n < 2)
	{
		printf("usage : pwm3 [duty_rate(%)] [period]\n\n");
		printf("	  	period = 10 ms if empty\n\n");
		return 1;
	}
	else if(n == 2)
	{
		period = 10;
		sscanf(s[1],"%d",&dr);
		drh = (dr * period) / 100;
		drl = period - drh;
	}
	else
	{
		sscanf(s[1],"%d",&dr);
		sscanf(s[2],"%d",&period);
		drh = (dr * period) / 100;		// mark time
		drl = period - drh;				// space time
	}
			
	wiringPiSetup();		// wiringPi pin number 사용 선언	
	
	pinMode(wPi_Pin, OUTPUT);

	pwmSetMode(PWM_MODE_MS);			// 일반적인 PWM 모드 사용
	softPwmCreate(wPi_Pin, drh, period);	// pulse width, time
	//softPWmWrite(wPi_Pin, 70);
	
	delay(5000);
	softPwmStop(wPi_Pin);
	return 0;
}
