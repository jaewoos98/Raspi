#include <stdio.h>
#include <wiringPi.h>
//Dist 함수 정의
#define TRIG	8
#define ECHO	9
extern void Trigger();

double Dist()
{
	// Trigger signal 
	// trig.c 정의
	Trigger();
	
	//while(digitalRead(ECHO) != LOW);	
	// ECHO 초기화(필수는 아님)
	
	// Wait for Echo signal
	while(digitalRead(ECHO) == LOW);	
	int start = micros();	// Get start time 
	while(digitalRead(ECHO) == HIGH);
	int end = micros();		// Get end time
	// calculate distance(cm)
	double dist = (end - start) * 0.017;
	return dist;
}


