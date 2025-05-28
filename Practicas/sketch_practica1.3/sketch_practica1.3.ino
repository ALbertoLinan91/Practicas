#include<stdint.h>

//Definir pines para los LEDs
uint8_t red_led = 15; //Pin del LED rojo
uint8_t button = 23; //Pin del boton

bool led_state = false;


void setup() {
  //Configurar los pines como salida
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(button, INPUT_PULLUP); //Inicializamos el pin boton como
  //Pullup significa que 1 es en reposo y 0 pulsando

  digitalWrite(red_led, LOW); // Inicializamos el led rojo como apagado

}

void loop() {
  if(digitalRead(button) == LOW) { // Si el boton esta a 0
  delay(50);
  led_state =! led_state; // Intercambiamos el valor de led_state
  digitalWrite(red_led, led_state); // Utilizamos la funcion digital
  }
}
