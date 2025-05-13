#define pinLed1 13  //Led RGB red
#define pinLed2 5  //Led RGB green
#define pinLed3 23  //Led RGB blue
#define pinBuzzer 2  //Altavoz
#define potenciometro 4
int porValue = 0;


void setup() {
  serialBegun(115200);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

}

void loop() {
  portValue = analogRead(potenciometro);
  Serial.println(portValue);

  if(potvalue >= 1365){
    digitalWrite(pinLed1, HIGH);
  }else if (portValue < 1365){
    digitalWrite(pinLed1, LOW);
  }

    if(potvalue >= 2730){
    digitalWrite(pinLed2, HIGH);
  }else if (portValue < 2730){
    digitalWrite(pinLed2, LOW);
  }

    if(potvalue >= 4095){
    digitalWrite(pinLed3, HIGH);
  }else if (portValue < 4095){
    digitalWrite(pinLed3, LOW);
  }

  tone(pinBuzzer, 1000 , 5000);

  delay(1000);
}
