#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buttonPin = 2; // Utilisez le numéro de la broche GPIO connectée au bouton
int buttonState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Dessiner un smiley si le bouton est pressé
    display.drawCircle(64, 16, 10, SSD1306_WHITE);
    display.fillCircle(60, 13, 2, SSD1306_WHITE);
    display.fillCircle(68, 13, 2, SSD1306_WHITE);
    display.drawPixel(60, 20, SSD1306_WHITE);
    display.drawPixel(68, 20, SSD1306_WHITE);
    display.drawPixel(64, 22, SSD1306_WHITE);
    
    display.display();
    delay(1000); // Délai pour éviter les rebonds du bouton
    display.clearDisplay();
  }
}
