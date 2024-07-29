#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
//Software PWM + 부저
#define wPi_Pin	0

int main(int n, char *s[])
{
	if(n < 2)
	{
		printf("usage : pwm3 [duty_rate(%)] [period]\n\n");
		printf("	  	period = 10 ms if empty\n\n");
		printf("default value : period = 10 ms , DR = 50%\n\n");
	}
	int dr = 50, drh, period = 10;
	else if(n == 2)
	{
		period = 10;
		sscanf(s[1],"%d",&dr);
		drh = (dr * period) / 100;
	}
	else
	{
		sscanf(s[1],"%d",&dr);
		sscanf(s[2],"%d",&period);
		drh = (dr * period) / 100;	

	}
			
	wiringPiSetup();						// wiringPi pin number 사용선언	
	pinMode(wPi_Pin, OUTPUT);

	pwmSetMode(PWM_MODE_MS);				// 일반적인 PWM 모드 사용
	softPwmCreate(wPi_Pin, drh, period);	// pulse width, time
	
	delay(5000);
	softPwmStop(wPi_Pin);
	return 0;
}
