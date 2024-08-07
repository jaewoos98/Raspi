#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>

#define wPi_PWM1 23
#define TRIG 8
#define ECHO 9
// 거리측정에 따른 노래 재생속도 변화
extern double Dist(int trigPin, int echoPin);
extern void calcRange();
extern void playsound(int um, int rythm);
extern int song[];
extern int rythm[];

void signal_handler(int signum) { // <signal.h>
    if (signum == SIGINT) { 
        pwmWrite(wPi_PWM1, 0);
        pinMode(wPi_PWM1, INPUT);
        exit(signum); // <stdlib.h> 
    }
}

int main()
{
	void signal_handler(int signum);
    wiringPiSetup();
    pinMode(wPi_PWM1, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    calcRange();

    for (;;)
    {
        double distance = Dist(TRIG, ECHO);
        printf("Distance: %f cm\n", distance);

        double speedf;

        if (distance < 50)
            speedf = 0.5;
        else if (distance <= 100)
            speedf = 2.0/3.0; 
        else
            speedf = 1.0;

        for (int i = 0; song[i] != -1; i++)
        {
            int adjusted_rythm = (int)(rythm[i] * 200 * speedf);
            playsound(song[i], adjusted_rythm);
        }

        delay(500);
    }
    return 0;
}
