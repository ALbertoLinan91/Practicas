#include <stdint.h>

// Definición de pines
int8_t triggerPin = 32; //pin trigger de sensor, salida que dispara el pulso ultrasonico
int8_t buzzerPin = 25; // Pin del buzzer
int8_t echoPin = 18; //pintrigger de sensor, entrada que recibe el eco reflejado


//variables que nos serviran para el calculo de la distancia y tiempo que tarde el sonido en viajar
int32_t duration; //declaración de variable duration tipo de datos entero
int32_t distance; //declaración de variable duration tipo de dato entero
int32_t delayVal; //declaración de variable delayval tipo de dato entero, es el retardo en milisegundos


void setup() {  //Funcion de configuración, configuración de pines
  pinMode(triggerPin,OUTPUT ); // Configura el pin del sensor como entrada
  pinMode(buzzerPin, OUTPUT); // Configura el pin del buzzer como salida
  pinMode(echoPin,INPUT); ////Configuración pin echo como entrada

  // Inicializa el buzzer apagado
  digitalWrite(buzzerPin, LOW);

  // Inicializa la comunicación serial para depuración
  Serial.begin(115200);
 
}

void loop() { //bucle principal, se ejecuta despues del setup, aqui va la lógica de programa

//Emisión de un pulso mediante el pin trigger del sensor.
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);

//calculo de la distancia del sonido desde que sale, rebote y vuelve mediante el pin echo
//Guardamos en la variable duration cuando emitamos un sonido y vuelva
duration = pulseIn (echoPin,HIGH);
distance = duration * 0.034 / 2;
//distancia es tiempo por la velocidad entre dos (340 metros por segundo)

//Funcion map:dependiendo de la distancia tendre una espera de pitido de 0 a 400 ms,es decir a menor distancia menor tiempo de espera
 if(distance < 100 && distance > 5){ //Si la distancia esta entre 5 y 100 cm
    delayVal = map(distance, 0, 100, 0, 400);
    Serial.println(map(distance, 0, 100, 0, 400));
//Activamos el pin delbuffer y dependiendo del tiempo calculado en la funcion map, lo vuelvo a apagar
    digitalWrite(buzzerPin, HIGH);//pongo el buffer a sonar
    delay(delayVal);//me espero el tiempo calculado arriba con la funcion map
    digitalWrite(buzzerPin, LOW); // apago el buffer
    delay(delayVal); // me espero de nuev el tiempo calculado 
  }else if(distance < 6){ //Si la distancia es menor de 6cm (muycerca) pita de manera continuada
    digitalWrite(buzzerPin, HIGH);
  }else if(distance > 35){ //Si la distancia es mayor a nuestro rango de 35 cm no suena
    digitalWrite(buzzerPin, LOW);
  }
 
  delay(100);
}