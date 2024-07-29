#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23

int PSC = 19;
const int RANGE = 100;
int DUTY = RANGE / 2;


enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI };
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int range[12];

int song[] = { SL, SL, LA, LA, SL, SL, MI,
               SL, SL, MI, MI, RE,
               SL, SL, LA, LA, SL, SL, MI,
               SL, MI, RE, MI, DO, -1 };

int rythm[] = { 4, 4, 4, 4, 4, 4, 5,
                4, 4, 4, 4, 8,
                4, 4, 4, 4, 4, 4, 5,
                4, 4, 4, 4, 8 };

void calcRange() 
{
    for (int i = 0; i < 12; i++)
    {
        range[i] = 1000000 / pitch[i];
        // 19200000 / (psc * pitch[i]);
    }
}

void playsound(int um, int rythm) // um: pitch, rythm
{
    pwmSetClock(PSC); // Prescaler: ~ 1MHz
    pwmSetRange(range[um]);
    pwmWrite(wPi_PWM1, range[um]/2);
    delay(rythm); 
    pwmWrite(wPi_PWM1, 0); 
    delay(50); 
}
