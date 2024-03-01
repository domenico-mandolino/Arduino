const int ledPin = 13;
const int buttonPin = 22;

// Déclaration des variables
int buttonState = LOW;
int previousButtonState = LOW;
int nbPress = 0;
unsigned long lastPressTime = 0;
bool ledOn = false;

void setup() {
  // Configuration des broches
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  // Initialisation de la LED
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Lecture de l'état du bouton
  buttonState = digitalRead(buttonPin);

  // Détection d'un appui simple
  if (buttonState == HIGH && previousButtonState == LOW) {
    nbPress++;
    lastPressTime = millis();
  }

  // Gestion des différents cas
  switch (nbPress) {

    case 1:
      // Si la condition est vraie, la LED s'allume
      digitalWrite(ledPin, HIGH);
      Serial.println('1');
      break;

    case 2:
      // Si la condition est vraie, la LED reste allumée
      
      digitalWrite(ledPin, HIGH);
      Serial.println('2');
      ledOn = true;
      break;
    };

    case 3:
      // Si la condition est vraie, la LED clignote
      if (millis() - lastPressTime >= 500) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        lastPressTime = millis();
        Serial.println('3');
      break;
      };
  }

  // Détection d'un appui prolongé
  if (buttonState == HIGH && millis() - lastPressTime >= 2000) {
    nbPress = 0;
    // Si la condition est vraie, la LED s'éteint
    digitalWrite(ledPin, LOW);
    ledOn = false;
    Serial.println('4');
  }

  // Extinction de la LED si elle est allumée et que le bouton n'est pas pressé
  if (ledOn && buttonState == LOW) {
    digitalWrite(ledPin, LOW);
    ledOn = false;
  }

  previousButtonState = buttonState;
}
