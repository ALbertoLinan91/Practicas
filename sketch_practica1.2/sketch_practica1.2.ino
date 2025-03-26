#include<stidnt.h>

  //Definir pines para los LEds
  uint8_t red_led = 15;  //Pin led rojo
  uint8_t green_led = 16;  //Pin led verde

  // Variables de temporizadores
  uint64_t previus_millis_red = 0;
  uint64_t previus_millis_green = 0;

  //Intervalos
  uint64_t red_interval = 1000;
   green_interval = 2000;


void setup() {
  // Configurar los pines como salida
  Serial.begin(9600);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTOUT);

  //Inicializar led apagados
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
}

void loop() {
  uint64_t actual_millis = millis();
  if(actual_millis - previus_millis_red > red_interval){
  previus_millis_red = millis();
  if(digitalRead(red_led)  ) {
    digitalWrite(red_led, false);
  }else{
    digitalWrite(red_led, true);
    }
  }

  if(actual_millis - previus_millis_green > green_interval){
  previus_millis_green = milli();
  if(digitalRead(green_led)  ) {
    digitalWrite(green_led, false);
  }else{
    digitalWrite(green_led, true)
    }
  }
}
