  #include<stdint.h>

// Definir pines LEDs del semaforo
  uint8_t red_led_1 = 2; // Pin LED rojo semaforo 1
  uint8_t yellow_led_1 = 4; // Pin LED amarillo semaforo 1
  uint8_t green_led_1 = 5; // PIn LED verde semaforo 1

  uint8_t red_led_2 = 18; // Pin LED rojo semaforo 2
  uint8_t yellow_led_2 = 19; // Pin LED amarillo semaforo 2
  uint8_t green_led_2 = 22; // PIn LED verde semaforo 2

// Variables temporizadores
  uint32_t previus_millis_red_1 = 0;
  uint32_t previus_millis_yellow_1 = 0;
  uint32_t previus_millis_green_1 = 0;

  uint32_t previus_millis_red_2 = 0;
  uint32_t previus_millis_yellow_2 = 0;
  uint32_t previus_millis_green_2 = 0;

// Intervalos
  uint32_t red_1_interval = 3000;
  uint32_t yellow_1_interval = 1000;
  uint32_t green_1_interval = 2000; 

  uint32_t red_2_interval = 3000;
  uint32_t yellow_2_interval = 1000;
  uint32_t green_2_interval = 2000;



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
  digitalWrite(green_led_1, LOW);

  digitalWrite(red_led_2, LOW);
  digitalWrite(yellow_led_2, LOW);
  digitalWrite(green_led_2, LOW);  

}

void loop() {
  if (millis() - previus_millis_red_1 > red_1_interval) {
  digitalWrite(red_led_1, LOW);  
  previus_millis_red_1 = millis();
  digitalWrite(green_led_1, HIGH);
  digitalWrite(red_led_2, HIGH);
 }

  if (millis() - previus_millis_green_1 > green_1_interval) {
  digitalWrite(green_led_1, LOW);  
  previus_millis_green_1 = millis();
  digitalWrite(yellow_led_1, HIGH);
 } 

  if (millis() - previus_millis_yellow_1 > yellow_1_interval) {
  digitalWrite(yellow_led_1, LOW);  
  previus_millis_yellow_1 = millis();
  digitalWrite(red_led_1, HIGH);
  digitalWrite(green_led_2, HIGH);
 }

 if (millis() - previus_millis_red_2 > red_2_interval) {
  digitalWrite(red_led_2, LOW);  
  previus_millis_red_2 = millis();
  digitalWrite(green_led_2, HIGH);
  digitalWrite(red_led_1, HIGH);
  }

if (millis() - previus_millis_green_2 > green_2_interval) {
  digitalWrite(green_led_2, LOW);  
  previus_millis_green_2 = millis();
  digitalWrite(yellow_led_2, HIGH);
  }

if (millis() - previus_millis_yellow_2 > yellow_2_interval) {
  digitalWrite(yellow_led_2, LOW);  
  previus_millis_yellow_2 = millis();
  digitalWrite(red_led_2, HIGH);
  digitalWrite(green_led_1, HIGH);
  }

}
