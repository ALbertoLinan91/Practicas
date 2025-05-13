#include <WiFi.h>

#include <PubSubClient.h> //Permitte al equipo esp 32 actuar como cliente MQTT

#include "time.h" 

// WiFi
const char* ssid = "xxxxx";//wifi clase :"ALUMNOS_CICLOS" 
const char* password = "xxxxxx";//password clase :"Ciclos2025sz?" 

// configuración  NTP
const char* ntpServer = "es.pool.ntp.org";
const int32_t gmtOffset_sec = 3600;
const int32_t daylightOffset_sec = 3600;//horario de verano 

// Configuración MQTT
const char* mqtt_server = "broker.emqx.io";
const char* mqtt_username = "guallar";
const char* mqtt_password = "1234";
const int mqtt_port = 1883;

// permite al dispositivo conectarse a servidores a través de WiFi usando el protocolo TCP/IP.
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

struct tm timeinfo;

// LED conectado al pin GPIO 2
const int ledPin = 2;

// Callback MQTT función para programas que utilizan MQTT
// topic es el nombre del topico,payload datos del mensaje y lenght la longitud del mensaje
void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.print("Mensaje recibido en el tópico: "); //imprimimos el mensaje de 
  Serial.println(topic);

  String message; //convierte el payload en un string legible 
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensaje: ");
  Serial.println(message);

  if (message == "1") {
    Serial.println("Encendiendo LED");
    digitalWrite(ledPin, HIGH); // Encender LED
  } else if (message == "0") {
    Serial.println("Apagando LED");
    digitalWrite(ledPin, LOW); // Apagar LED
  }
}

//función utilizada para reconectar el dispositiv al broker MQTT si la conexión se pierde. Es comúnmente llamada en el loop() para mantener la conexión activa.
void reconnect() {
  Serial.print("Conectando a MQTT..."); //mensaje de conexión
  String client_id = "esp32-client-" + String(WiFi.macAddress()); //generación de un cliente único
  if (mqtt_client.connect(client_id.c_str(), mqtt_username, mqtt_password)) { //intento de conexión, si es correcta imprimimos este mensaje
    Serial.println("Conectado a MQTT");
    mqtt_client.subscribe("sensor/boton");
  } else { //Si la conexión no es exitosa, imprimimos error
    Serial.print("Error, código: ");
    Serial.println(mqtt_client.state());
    delay(5000);
  }
}

void setup() {
  Serial.begin(115200); //velocidad de comunicación de los baudios

  pinMode(ledPin, OUTPUT); // Inicializacíon pin del LED
  digitalWrite(ledPin, LOW); // el LED inicia apagado

  WiFi.begin(ssid, password); //arrabque de la conexión cogiendo el nombre y contraseña del wifi
  Serial.println("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado. IP:");
  Serial.println(WiFi.localIP());

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(callback);
}

//bucle principal verifica si el cliente esta conectado, si es asi llama a la función reconect
void loop() {
  if (!mqtt_client.connected()) {
    reconnect();
  }

  mqtt_client.loop();

//obtención de hora y formateo en el formato correcto legible y la muestra.
  if (getLocalTime(&timeinfo)) {
    char formattedTime[64];
    strftime(formattedTime, sizeof(formattedTime), "%d/%m/%Y %H:%M:%S", &timeinfo);
    Serial.println(formattedTime);
    mqtt_client.publish("sensor/hora", formattedTime);
  }

  delay(1000);
}
