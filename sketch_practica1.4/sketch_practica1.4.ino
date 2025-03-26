#include<stdint.h>

// Definir LED y botones
uint8_t led = 2; // Pin LED
uint8_t button_1 = 23; // Boton 1
uint8_t button_2 = 24; // Boton 2

uint32_t previus_millis = 0;

uint32_t led_interval = 10000;



void setup() {
  // Configurar los pines como salidas
  serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button_1, IMPUT_PULLUP);
  pinMode(button_2, IMPUT_PULLUP);
 }

void loop() {
  if(digitalRead(button_1) == LOW){
  delay(250);
  digitalWrite(led,HIGH);
  prevuis_millis = millis();
}

  if(digitalRead(button_2) == LOW){
  delay(250);
  digitalWrite(led,LOW);
  }

  if(millis()- previus_millis > led_interval){
  digitalWrite(led,LOW); 
  }

}



