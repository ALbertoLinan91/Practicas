  #include<stdint.h>

// Definir pines LEDs del semaforo
  uint8_t red_led_1 = 3; // Pin LED rojo semaforo 1
  uint8_t yellow_led_1 = 4; // Pin LED amarillo semaforo 1
  uint8_t green_led_1 = 5; // PIn LED verde semaforo 1

  uint8_t red_led_2 = 6; // Pin LED rojo semaforo 2
  uint8_t yellow_led_2 = 7; // Pin LED amarillo semaforo 2
  uint8_t green_led_2 = 8; // PIn LED verde semaforo 2

// Variables temporizadores
  uint32_t previus_millis_red_1 = 0;
  uint32_t previus_millis_yellow_1 = 0;
  uint32_t previus_millis_green_1 = 0;

  uint32_t previus_millis_red_2 = 0;
  uint32_t previus_millis_yellow_2 = 0;
  uint32_t previus_millis_green_2 = 0;

// Intervalos
  uint32_t red_1_interval = 1000;
  uint32_t yellow_1_interval = 1000;
  uint32_t green_1_interval = 1000; 

  uint32_t red_2_interval = 1000;
  uint32_t yellow_2_interval = 1000;
  uint32_t green_2_interval = 1000;



void setup() {
  // Configurar pines de salida
  Serial.begin(9600);
  pinMode(red_led_1, OUTPUT);
  pinMode(yellow_led_1, OUTPUT);
  pinMode(green_led_1, OUTPUT);

  pinMode(red_led_2, OUTPUT);
  pinMode(yellow_led_2, OUTPUT);
  pinMode(green_led_2, OUTPUT);

  // Inicializar LEDs apagados
  digitalWrite(red_led_1, LOW);
  digitalWrite(yellow_led_1, LOW);
  digitalWrtie(green_led_1, LOW);

  digitalWrite(red_led_2, LOW);
  digitalWrite(yellow_led_2, LOW);
  digitalWrtie(green_led_2, LOW);  

}

void loop() {
  uint32_t actual_millis = millis();
  if(actual_millis - previus_millis_red_1 > red_1_interval){
  previus_millis_red_1 = millis();
  if(digitalRead(red_led_1) ) {
    digitalWrite(red_led_1, false); 
  }else  {
    digitalWrite(red_led_1, true);
  }
}
 
  if(actual_millis - previus_millis_yellow_1 > yellow_1_interval){
  previus_millis_yellow_1 = millis();
  if(digitalRead(yellow_led_1) ) {
    digitalWrite(yellow_led_1, false); 
  }else  {
    digitalWrite(yellow_led_1, true);
  }
}
 
   if(actual_millis - previus_millis_green_1 > green_1_interval){
  previus_millis_green_1 = millis();
  if(digitalRead(green_led_1) ) {
    digitalWrite(green_led_1, false); 
  }else  {
    digitalWrite(green_led_1, true);
  }
}
 


}
