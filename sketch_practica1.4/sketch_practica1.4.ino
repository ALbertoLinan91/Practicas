#include<stdint.h>

// Definir LED y botones
uint8_t led = 15; // Pin LED
uint8_t button_1 = 22; // Boton 1
uint8_t button_2 = 23; // Boton 2

uint32_t previus_millis = 0;

uint32_t led_interval = 10000;



void setup() {
  // Configurar los pines como salidas
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
 }

void loop() {
  if(digitalRead(button_1) == LOW){
  delay(250);
  digitalWrite(led,HIGH);
  previus_millis = millis();
}

  if(digitalRead(button_2) == LOW){
  delay(250);
  digitalWrite(led,LOW);
  }

  if(millis()- previus_millis > led_interval){
  digitalWrite(led,LOW); 
  }

}



