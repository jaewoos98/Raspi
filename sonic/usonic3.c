#include <stdio.h>
#include <wiringPi.h>
// 학교종 노래 부저로 만들기
#define wPi_PWM1 23
int PSC = 19;			// prescaler
int RANGE = 100;		// C / P * R
//int DUTY = RANGE / 2;

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
int range[12];
int song[] = { SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI ,RE,
			   SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1};
int rythm[] = { 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1,
				4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};	// 박자(4분음표, 2분음표 등)

void calcRange()	
{
	for(int i = 0 ; i < 12; i++)
	{
		range[i] = (1000000 / pitch[i]);
	}
}

void playsound(int um, int rythm)
{
	pwmSetClock(PSC);
	pwmSetRange(range[um]);
	pwmWrite(wPi_PWM1, range[um]/2);
}

int main()
{
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	calcRange();
	
	for(int i=0;song[i]!=-1;i++)
	{
		playsound(song[i], rythm[i]);
		delay(2000 / rythm[i]);
	}
	
	pwmWrite(wPi_PWM1, 0);
	return 0;
}
