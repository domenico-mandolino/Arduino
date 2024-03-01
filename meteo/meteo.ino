#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN_LED 4 // Pin connecté à la bande de LEDs
#define NUM_LEDS 16 // Nombre total de LEDs
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme; // Crée une instance du capteur BMP280
Adafruit_NeoPixel strip(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);


int status;
void setup() {
  Serial.begin(9600);
 
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }


  status = bme.begin(0x76);
  if (!status) {
    Serial.println(F("Erreur Capteur"));
    Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
    Serial.print("        ID of 0xFF  BMP 180 ou BMP 085\n");
    Serial.print("   ID of 0x56-0x58  BMP 280,\n");
    Serial.print("        ID of 0x60  BME 280.\n");
    Serial.print("        ID of 0x61  BME 680.\n");
    while (1);
    
  }
  
  // if (!bme.begin(0x76)) {
  //   Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
  //   while (1);
  // }
  display.display();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  strip.begin();
  strip.show(); // Initialise toutes les LEDs à 'éteint'
}

void loop() {

     display.clearDisplay();

 


  String message;
  float temp = bme.readTemperature();
  float pressure = bme.readPressure()  ; // Converti en hPa
  float humidity = bme.readHumidity(); // Le BMP280 ne peut pas lire l'humidité. Utilisez un autre capteur si nécessaire.

  // Afficher la température en rouge
  message  = "La température est de " + String(temp) + " degrés Celsius.";
  displayBarGraph(temp, 0, 40, strip.Color(255, 0, 0)); // Température de 0 à 40 degrés comme exemple
  display.setCursor(10, 10);
  display.println(message);
  Serial.println(message);
  display.display();
  display.clearDisplay();
  delay(3000);


  
  // Afficher l'humidité en bleu
  message  = "L'humidité est de " + String(humidity) + " %.";
  displayBarGraph(humidity, 0, 100, strip.Color(0, 0, 255)); // Humidité de 0 à 100% comme exemple
  display.setCursor(10, 10);
  display.println(message);
  Serial.println(message);
  display.display();
  display.clearDisplay();
  delay(3000);


  // Afficher la pression en vert
  message  = "La pression est de " + String(humidity) + " hPa.";
  displayBarGraph(pressure, 950, 1050, strip.Color(0, 255, 0)); // Pression de 950 à 1050 hPa comme exemple
  display.setCursor(10, 10);
  display.println(message);
  Serial.println(message);
  display.display();
  display.clearDisplay();
  delay(3000);
 
}

void displayBarGraph(float value, float minVal, float maxVal, uint32_t color) {

  strip.clear();
  int numLedsToLight = map(value, minVal, maxVal, 0, NUM_LEDS);
  for(int i = 0; i < numLedsToLight; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}



