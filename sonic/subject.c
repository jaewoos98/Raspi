#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23
#define TRIG 8
#define ECHO 9

extern double Dist(int trigPin, int echoPin);
extern void calcRange();
extern void playsound(int um, int rythm);
extern int song[];
extern int rythm[];

int main()
{
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
