#include <SPi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Definir constantes
#define ANCHO_PANTALLA 128 //ancho pantalla OLED
#define ALTO_PANTALLA 64 //alto pantalla OLED

//objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display (ANCHO_PANTALLA, ALTO_PAMTALLA, &Wire. -1);

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
  //Iniciar pantalla OLED en la direccion 0x3C
  display.begin(SSD1306_SWITCHAPVCC, 0x3C);

}

void loop() {
  //Limpiar buffer
  display.clear.Display();
  //Tamaño del texto
  display.setTextSize(1);
  //Color del texto
  display.setTextColor(SSD1306_WHITE);
  //Posicion texto
  display.setCursor(10, 32);
  //Escribir texto
  display.println("OLED");
  //Enviar a pantalla
  display.display();

}
