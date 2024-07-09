#include <stdio.h>
#include <wiringPi.h>

// Trigger signal 
#define TRIG	8
#define ECHO	9

void Trigger()
{
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);	// = 10us
	digitalWrite(TRIG, LOW);
	delayMicroseconds(200);	// wait for burst signal start
	// 200us = 8개의 버스트 신호를 충분히 발생시킬 시간
}
