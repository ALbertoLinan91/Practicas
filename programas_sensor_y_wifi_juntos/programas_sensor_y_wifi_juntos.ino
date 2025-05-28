#include <WiFi.h> // librería para manejar conexiones wifi
#include <PubSubClient.h> //Permitte al equipo esp 32 actuar como cliente MQTT
#include "time.h" //librería para trabajar con funciones relacionadas con fechasy horas
#include <stdint.h> //Librería para poder trabajar con numeros y tipo de datos enteros

//variables que nos serviran para el calculo de la distancia y tiempo que tarde el sonido en viajar
int32_t duration; //declaración de variable duration tipo de datos entero
int32_t distance; //declaración de variable distancia tipo de dato entero
int32_t delayVal; //declaración de variable delayval tipo de dato entero, es el retardo en milisegundos

// Definición de pineado
const int ledPin = 2; //pin led placa
int8_t triggerPin = 32; //pin trigger de sensor, salida que dispara el pulso ultrasonico
int8_t buzzerPin = 25; // Pin del buzzer
int8_t echoPin = 18; //pintrigger de sensor, entrada que recibe el eco reflejado
int8_t led_alarm_red = 23;
int8_t led_caution_yellow = 22;
int8_t led_clear_green = 19;


// WiFi
const char* ssid = "ALUMNOS_CICLOS";//wifi clase :"ALUMNOS_CICLOS" 
const char* password = "Ciclos2025sz?";//password clase :"Ciclos2025sz?"

// configuración  NTP (network time protocol)
const char* ntpServer = "es.pool.ntp.org";// configuramos horario en español
const int32_t gmtOffset_sec = 3600; //declaramos segundos
const int32_t daylightOffset_sec = 3600;//horario de verano 

// Configuración MQTT (protcolo de comunicación ligero)
const char* mqtt_server = "broker.emqx.io";// direccion del servidor MQTT al que te quieres conectar
const char* mqtt_username = "Liñan";//nombre usuario para autentificarse en el servidor MQTT
const char* mqtt_password = "12345";//comtraseña de usuario MQTT
const int mqtt_port = 1883; //puerto en que el servidor MQTT esta comunicandose.

// permite al dispositivo conectarse a servidores a través de WiFi usando el protocolo TCP/IP.
WiFiClient espClient; // llamada a wifi, gestiona la conexion wifi.
PubSubClient mqtt_client(espClient);//libreria que permitecomunicar MQTT, se usara como conexion al servidor MQTT

struct tm timeinfo; //estructura que almacena información de fecha y hora


// Callback MQTT función para programas que utilizan MQTT
// topic es el nombre del topico,payload datos del mensaje y lenght la longitud del mensaje
void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.print("Mensaje recibido en el tópico: "); //imprimimos el mensaje de 
  Serial.println(topic);

  String message; //convierte el payload en un string legible 
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i]; // Convierte cada byte a char y lo concatena
  }

  Serial.print("Mensaje: ");
  Serial.println(message);

  if (message == "1") { 
    Serial.println("Sistema de escaneo activado"); // antes"encendido led"
    digitalWrite(ledPin, HIGH); // Encender LED
  } else if (message == "0") {
    Serial.println("Sistema de escaneo desactivado"); //antes "led apagado"
    digitalWrite(ledPin, LOW); // Apagar LED
  }
}

//función utilizada para reconectar el dispositivo al broker MQTT si la conexión se pierde. Es comúnmente llamada en el loop() para mantener la conexión activa.
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

  pinMode(triggerPin,OUTPUT ); // Configura el pin del sensor como entrada
  pinMode(buzzerPin, OUTPUT); // Configura el pin del buzzer como salida
  pinMode(echoPin,INPUT); ////Configuración pin echo como entrada
  pinMode (led_alarm_red, OUTPUT) ;//inicializa led rojo apagado
  pinMode (led_caution_yellow,OUTPUT);//inicializa led amarillo apagado
  pinMode (led_clear_green, OUTPUT);//inicializa led verde apagado

  // Inicializa el buzzer apagado
  digitalWrite(buzzerPin, LOW);

  WiFi.begin(ssid, password); //arranque de la conexión cogiendo el nombre y contraseña del wifi
  Serial.println("Conectando a WiFi...");//mensaje a la consola si la conexion es correcta
  while (WiFi.status() != WL_CONNECTED) { //este ciclo  comienza mientras no este conectado a wifi
    delay(1000);
    Serial.print(".");// mientras espera imprime un punto
  }
  Serial.println("\nWiFi conectado. IP:");// si esta conectado a IP imprime 
  Serial.println(WiFi.localIP());//muestra direccion IP local de la red wifi a la que se conectado

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);//configura la hora del programa usando el servidor NPT 

  mqtt_client.setServer(mqtt_server, mqtt_port);// configura el cliente MQTT para que se conecte al servidor MQTT con el puerto y direccion 
  mqtt_client.setCallback(callback);// establece como respondera el dispositivo ante nuevos mensajes MQTT
}

//bucle principal verifica si el cliente esta conectado, si es asi llama a la función reconect
//bucle donde tambien se ejecutara la parte del programa del sensor 
void loop() {

//SENSOR HC-SR04
//Emisión de un pulso mediante el pin trigger del sensor.
digitalWrite(triggerPin, LOW);//apaga señal antes de empezar, asi el sensor esta estable
delayMicroseconds(2);//pausa de 2 m.seg asi el disparo es mas claro
digitalWrite(triggerPin, HIGH);//debe emitir una honda ultrasonica
delayMicroseconds(10);//mantiene la señal encendida durante 10 m.seg
digitalWrite(triggerPin, LOW);//se apaga señal de disparo

//calculo de la distancia del sonido desde que sale, rebote y vuelve mediante el pin echo
//Guardamos en la variable duration cuando emitamos un sonido y vuelva
duration = pulseIn (echoPin,HIGH);
distance = duration * 0.034 / 2;
//distancia es tiempo por la velocidad entre dos (340 metros por segundo)

//Funcion map:dependiendo de la distancia tendre una espera de pitido de 0 a 400 ms,es decir a menor distancia menor tiempo de espera
 if(distance < 50 && distance > 5){ //Si la distancia esta entre 5 y 100 cm
    delayVal = map(distance, 0, 50, 0, 400);
    //Serial.println(map(distance, 0, 100, 0, 400));
    Serial.println("Objeto detectado");
    digitalWrite(led_caution_yellow, HIGH);
    digitalWrite(led_alarm_red, LOW);
    digitalWrite(led_clear_green, LOW);
//Activamos el pin delbuffer y dependiendo del tiempo calculado en la funcion map, lo vuelvo a apagar
    digitalWrite(buzzerPin, HIGH);//pongo el buffer a sonar
    delay(delayVal);//me espero el tiempo calculado arriba con la funcion map
    digitalWrite(buzzerPin, LOW); // apago el buffer
    delay(delayVal); // me espero de nuevo el tiempo calculado 

  }else if(distance < 6){ //Si la distancia es menor de 6cm (muycerca) pita de manera continuada
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Objeto detectado demasiado cerca");
    digitalWrite(led_alarm_red, HIGH);
    digitalWrite(led_caution_yellow, LOW);
    digitalWrite(led_clear_green, LOW);
  }else if(distance > 50){ //Si la distancia es mayor a nuestro rango de 50 cm no suena
    digitalWrite(buzzerPin, LOW);
    Serial.println("Objeto no detectado");
    digitalWrite(led_clear_green, HIGH);
    digitalWrite(led_alarm_red, LOW);
    digitalWrite(led_caution_yellow, LOW);

  }
  delay(250);


//WIFI
  if (!mqtt_client.connected()) { //el programa verifica la conexion activada
    reconnect(); //aseguramos la comunicacion con el servidor siempre encendida
  }
  mqtt_client.loop();// se encarga de mantener conexion y y mantener mensajes con MQTT
//obtención de hora y formateo en el formato correcto legible y la muestra.
  if (getLocalTime(&timeinfo)) { //intente obtener hora local
    char formattedTime[64]; // se formate hora en legible... mes/dia/hora
    strftime(formattedTime, sizeof(formattedTime), "%d/%m/%Y %H:%M:%S", &timeinfo);
    Serial.println(formattedTime);// imprime hora
    mqtt_client.publish("sensor/hora", formattedTime);//publics texto elegido
  }
  delay(500);
}
