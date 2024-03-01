const int boutonPin = 23;  // Broche du bouton
const int ledPin = 13;    // Broche de la LED

bool boutonAppuye = false;

void setup() {
  pinMode(boutonPin, INPUT_PULLUP);
d:\ProjetsLaPlateforme\Arduino\sketch_feb29c\sketch_feb29c.ino  pinMode(ledPin, OUTPUT);
}
void loop() {
  // Vérifier si le bouton est appuyé
  if (digitalRead(boutonPin) == HIGH) {
    // Si le bouton est appuyé, allumer la LED
    digitalWrite(ledPin, LOW);
    boutonAppuye = true;
    
  } else {
    // Si le bouton est relâché, éteindre la LED seulement si elle était allumée précédemment
    if (boutonAppuye) {
      digitalWrite(ledPin, HIGH);
      boutonAppuye = false;
    }
  }
}


