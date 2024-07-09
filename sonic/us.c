#include <stdio.h>
#include <wiringPi>
//Dist 함수 정의
#define TRIG	8
#define ECHO	9

double Dist()
{
	// Trigger signal 
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);	// = 10us
	digitalWrite(TRIG, LOW);
	delayMicroseconds(200);	// wait for burst signal start
	// 200us = 8개의 버스트 신호를 충분히 발생시킬 시간
	
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


