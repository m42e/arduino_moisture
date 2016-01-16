

#include "Arduino.h"
void setup() {
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	pinMode(7, OUTPUT);	
	pinMode(6, OUTPUT);	
	pinMode(5, OUTPUT);	
	pinMode(4, OUTPUT);	
	pinMode(3, INPUT);	
	digitalWrite(3, HIGH);
	Serial.begin(115200);
}
int value = 0;


void writeLeds(int value){
	if(value & 0x01) digitalWrite(7, LOW); else digitalWrite(7, HIGH);
	if(value & 0x02) digitalWrite(6, LOW); else digitalWrite(6, HIGH);
	if(value & 0x04) digitalWrite(5, LOW); else digitalWrite(5, HIGH);
	if(value & 0x08) digitalWrite(4, LOW); else digitalWrite(4, HIGH);
}

void loop() {
	int r = digitalRead(3);
	int value = analogRead(0);
	writeLeds(value >> 4);
	Serial.println(value);
	delay(300);
}
