#include <stdio.h>
#include <wiringPi.h>

int main()
{
	wiringPiSetup();	// 사용 핀번호 지정
	pinMode(7, OUTPUT);	// 7,8,9번은 OUT 2번은 IN
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(2, INPUT);

	digitalWrite(7, HIGH);
	delay(500);
	digitalWrite(7, LOW);
	digitalWrite(8, HIGH);
	delay(500);
	digitalWrite(8, LOW);
	digitalWrite(9, HIGH);
	delay(500);
	digitalWrite(9, LOW);
}

