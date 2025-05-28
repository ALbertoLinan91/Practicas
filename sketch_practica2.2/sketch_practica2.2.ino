#include <stdint.h>

int32_t LEDPin1 = 13;
int32_t LEDPin2 = 18;
int32_t LEDPin3 = 19;
int32_t LDRPin = 2;
int32_t thershold = 100;
int32_t thershold2 = 500;
int32_t thershold3 = 900;

void setup() {
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);

}

void loop() {
  int32_t input = analogRead(LDRPin);
  if(input > thershold){
    digitalWrite(LEDPin1, HIGH);
  }
  else{
    digitalWrite(LEDPin1, LOW);
  }

  if(input > thershold2){
    digitalWrite(LEDPin2, HIGH);
  }
  else{
    digitalWrite(LEDPin2, LOW);
  }

  if(input > thershold3){
    digitalWrite(LEDPin3, HIGH);
  }
  else{
    digitalWrite(LEDPin3, LOW);
  }
}