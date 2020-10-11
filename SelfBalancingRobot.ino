#include "Tone.h"

#define MOTOR1 13

Tone m1;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR1, OUTPUT);
  m1.begin(MOTOR1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  m1.play(100);
  Serial.println(m1.getEpochTicks());
  delay(500);
}
