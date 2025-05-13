#include <DHT.h>
#include <DHT_U.h>



#define DHTPIN 17
#define DHTTYPE DHT11

  uint8_t red_led = 2; // Pin LED rojo  
  uint8_t blue_led = 4; // Pin LED azul
  uint8_t green_led = 5; // PIn LED verde

DHT dht(DHTPIN, DHTTYPE);



 void setup() {
  Serial.begin(9600);

  dht.begin();

}

void loop() {
  delay(5000);

  float h = dht.reaHumidity();
  float t = dht.readTemperature();

  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  digitalWrite(red_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(green_led, LOW);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  serial.print("Humedad: ");
  serial.print(h);
  serial.print(" %t");

  serial.print("Temperatura: ");
  serial.print(t);
  serial.print(" *C ");
 
  serial.print("Indice de calor");
  serial.print(hic);
  serial.print(" * C ");
 }
 
  if (isnan(t)>20) {
   digitalWrite(red_led, LOW);  
   digitalWrite(blue_led, LOW);
   digitalWrite(green_led, HIGH);
 }

  if (isnan(t)>15) {
   digitalWrite(red_led, LOW);  
   digitalWrite(blue_led, HIGH);
   digitalWrite(green_led, LOW);
 }

  if (isnan(t)>15 || >20 || isnan(h)<50 ) {
   digitalWrite(red_led, HIGH);  
   digitalWrite(blue_led, LOW);
   digitalWrite(green_led, LOW);
 }


}





