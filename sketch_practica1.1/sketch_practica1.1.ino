#include<stdint>

//Definir pines para LEDs
int8_t red_led = 15; //Pin del led rojo
int8_t green_led = 16; //Pin del led verde

void setup() {
  //Inicializamos el puerto serie para mostrar por pantalla
  Serial.begin(9600);
 //Configurar los pines como salida
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);

}

void loop() {
  // Endender LED rojo y apagar LED verde
 digitalWrite(red_led,HIGH);
 digitalWrite(green_led, LOW);
 delay(1000); //Esperar un segundo

 // Endender LED verde y apagar LED rojo
 digitalWrite(green_led,HIGH);
 digitalWrite(red_led,LOW);
delay(1000);
}
