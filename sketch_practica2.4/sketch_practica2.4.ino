#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 19          // Pin donde está conectado el sensor
#define DHTTYPE DHT11   // Tipo de sensor

// Definir pines de los LEDs
const int red_led = 18;    // Pin para LED rojo
const int blue_led = 4;   // Pin para LED azul
const int green_led = 23;    // Pin para LED verde

// Pines del sensor (ejemplo con DHT11)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop() {
  // Leer temperatura y humedad
  float temperatura = dht.readTemperature(); // en grados Celsius
  float humedad = dht.readHumidity();        // en porcentaje

  // Verificar si la lectura fue exitosa
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer del sensor");
    return;
  }

  // Encender o apagar LEDs según las condiciones
  if (temperatura >= 15 && humedad < 50) {
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, LOW);
  } else {
    digitalWrite(blue_led, LOW);
  }

  if (temperatura >= 20 && humedad < 50) {
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
  } else {
    digitalWrite(green_led, LOW);
  }

  if (temperatura >= 15 && humedad >= 50) {
    digitalWrite(red_led, HIGH);
     digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  } else {
    digitalWrite(red_led, LOW);
  }

  // imprimir valores en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C, Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  delay(2000); // Esperar 2 segundos antes de la siguiente lectura

}