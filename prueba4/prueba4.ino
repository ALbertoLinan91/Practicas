cpp
#include 

#define DHTPIN 2          // Pin donde está conectado el DHT11
#define DHTTYPE DHT11     // Definimos el tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE); // Inicializamos el sensor DHT

// Definimos los pines de los LEDs
#define LED_VERDE 3
#define LED_AZUL 4
#define LED_ROJO 5

void setup() {
  Serial.begin(9600);     // Iniciamos la comunicación serial
  dht.begin();            // Iniciamos el sensor DHT

  // Configuramos los pines de los LEDs como salida
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}

void loop() {
  // Esperamos un momento para obtener lecturas estables
  delay(2000);

  // Leemos la temperatura y la humedad
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Comprobamos si las lecturas son válidas
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer del sensor DHT!");
    return;
  }

  // Mostramos los valores en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  // Controlamos los LEDs según las condiciones
  if (t < 20) {
    digitalWrite(LED_VERDE, HIGH); // Activa el LED verde
  } else {
    digitalWrite(LED_VERDE, LOW);  // Desactiva el LED verde
  }

  if (t > 15) {
    digitalWrite(LED_AZUL, HIGH);  // Activa el LED azul
  } else {
    digitalWrite(LED_AZUL, LOW);   // Desactiva el LED azul
  }

  if (t < 20 && t > 15 && h < 50) {
    digitalWrite(LED_ROJO, HIGH);   // Activa el LED rojo
  } else {
    digitalWrite(LED_ROJO, LOW);    // Desactiva el LED rojo
  }