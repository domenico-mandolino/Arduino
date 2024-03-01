// const int boutonPin = 23; // Broche du bouton
// const int ledPin = 13; // Broche de la LED
// int etatBouton = 0;
// int dernierEtatBouton = 0;
// int compteurAppuis = 0;
// bool ledAllumee = false;

// void setup() {
//   pinMode(ledPin, OUTPUT);
//   pinMode(boutonPin, INPUT_PULLUP);
// }

// void loop() {
//   etatBouton = digitalRead(boutonPin);

//   if (etatBouton != dernierEtatBouton) {
//     if (etatBouton == HIGH) {
//       compteurAppuis++;
//     }
//     delay(0);
//   }

//   if (compteurAppuis == 1) {
//     digitalWrite(ledPin, HIGH);
//     ledAllumee = true;
//   } else if (compteurAppuis == 2) {
//     // Ne rien faire, la LED reste allumée
//   } else if (compteurAppuis == 3) {
//     digitalWrite(ledPin, !digitalRead(ledPin));
//     delay(500);
//   } else if (etatBouton == HIGH && ledAllumee) {
//     digitalWrite(ledPin, LOW);
//     ledAllumee = false;
//     compteurAppuis = 0;
//   }

//   dernierEtatBouton = etatBouton;
// }




// // Déclaration des broches
// const int ledPin = 25;
// const int buttonPin = 22;

// // Déclaration des variables
// int buttonState = LOW;
// int previousButtonState = LOW;
// int nbPress = 0;
// unsigned long lastPressTime = 0;



// void setup() {
//   // Configuration des broches
//   pinMode(ledPin, OUTPUT);
//   pinMode(buttonPin, INPUT_PULLUP);

//   // Initialisation de la LED
//   digitalWrite(ledPin, LOW);
// }

// void loop() {
//   // Lecture de l'état du bouton
//   buttonState = digitalRead(buttonPin);

//     // Détection d'un appui simple
//     while (nbPress == 1) {
//     //   // Allumage de la LED
//       digitalWrite(ledPin, HIGH);
//       // nbPress = 0; // Sortie de la boucle
//     }


//       if (nbPress == 2) {
//         // La LED reste allumée
//         // if (millis() - lastPressTime < 500) {
//           digitalWrite(ledPin, HIGH);
//         }
//         else{
//           digitalWrite(ledPin, LOW); // Sortie de la boucle
//         }

  

//     // while (nbPress >= 3) {
//     //   // Clignotement de la LED
//     //   if (millis() - lastPressTime < 500) {
//     //     unsigned long clignotementDebut = millis();

//     //     for (int i = 0; i < 10; i++) {
//     //       // Allumage de la LED
//     //       digitalWrite(ledPin, HIGH);
//     //       while (millis() - clignotementDebut > 50);  // Attente de 50 ms

//     //       // Extinction de la LED
//     //       digitalWrite(ledPin, LOW);
//     //       while (millis() - clignotementDebut > 100);  // Attente de 50 ms
//     //     }

//     //     nbPress = 0;  // Sortie de la boucle après les 10 cycles
//     //   }
//     // }




//   // // Détection d'un appui prolongé
//   // if (buttonState == HIGH && millis() - lastPressTime >= 1000) {
//   //   nbPress = 0;
//   //   digitalWrite(ledPin, LOW);
//   // }

//   // Mise à jour de l'état précédent du bouton
//   // previousButtonState = buttonState;

//   // Ajout d'un délai global pour éviter les faux déclenchements
//   // delay(1000);
// }

// #include <Arduino.h>
// #include <Button>


// Dans la vérification du front montant du bouton, il n'est pas nécessaire d'attribuer une valeur particulière à millis(). Au lieu de cela, tu utilises millis() pour enregistrer le temps auquel le bouton a été enfoncé. Voici comment cela pourrait être fait dans le code :


const int ledPin = 13;
const int buttonPin = 22;

// Déclaration des variables
int buttonState = LOW;
int previousButtonState = LOW;
int nbPress = 0;
unsigned long lastPressTime = 0;
bool ledOn = false;
bool buttonPressed = false;

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
    buttonPressed = true;
  }

  // Gestion des différents cas
  switch (nbPress) {


    case 1:
      // Si la condition est vraie, la LED s'allume
      if (buttonPressed) {
        digitalWrite(ledPin, HIGH);
              Serial.println('1');
      }
      buttonPressed = false;
      break;


    case 2:
      // Si la condition est vraie, la LED reste allumée
      if (buttonPressed) {
        digitalWrite(ledPin, HIGH);
              Serial.println('2');
        ledOn = true;
      }
      break;


      
    case 3:
      // Si la condition est vraie, la LED clignote
      if (buttonPressed) {
        if (millis() - lastPressTime >= 500) {
          digitalWrite(ledPin, !digitalRead(ledPin));
          lastPressTime = millis();
        }
      }
      break;
  }

  // Détection d'un appui prolongé
  if (buttonState == HIGH && millis() - lastPressTime >= 2000) {
    nbPress = 0;
    // Si la condition est vraie, la LED s'éteint
    if (buttonPressed) {
      digitalWrite(ledPin, LOW);
      ledOn = false;
      buttonPressed = false;
    }
  }

  // Extinction de la LED si elle est allumée et que le bouton n'est pas pressé
  if (ledOn && buttonState == LOW) {
    digitalWrite(ledPin, LOW);
    ledOn = false;
  }

  previousButtonState = buttonState;
}
