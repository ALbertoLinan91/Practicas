#include <stdint.h>

int8_t BUZZERPin = 13;
int8_t PIRPin = 2;

void setup() {
  pinMode(BUZZERPin, OUTPUT);
  pinMode(PIRPin, INPUT);
}

void loop() {
  int32_t value = digitalRead(PIRPin);

  if(value == HIGH){
    digitalWrite(BUZZERPin, HIGH);
    delay(60);
    digitalWrite(BUZZERPin, LOW);
    delay(60);
  }
  else{
    digitalWrite(BUZZERPin, LOW);
  }

  tone(BUZZERPin, 100);
  delay(500);
}
