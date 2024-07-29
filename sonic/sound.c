#include <stdio.h>
#include <wiringPi.h>

double Dist(int trigPin, int echoPin)
{
   
    digitalWrite(trigPin, 1);
    delayMicroseconds(10);
    digitalWrite(trigPin, 0);
    delayMicroseconds(200);

    
    while (digitalRead(echoPin) != 1); 
    int t1 = micros(); 
    while (digitalRead(echoPin) != 0); 
    int t2 = micros(); 

    return (t2 - t1) * 0.017; 
}
