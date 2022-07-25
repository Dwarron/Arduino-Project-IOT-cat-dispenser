#include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur
Servo monServo;  // on crée l'objet monServo

void setup() {
  pinMode(13, OUTPUT); // Pin 13 réglé en sortie pour une LED

  Serial.begin(9600);
  monServo.attach(A0); // on définit le Pin utilisé par le servomoteur
  monServo.write(0); // par défaut le servo est à la position 0°
}

void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); // lecture du port série
    if (inChar == '0') {
      digitalWrite(13, LOW);
    }
    else if (inChar == '1') {
      digitalWrite(13, HIGH);
    }
    else if (inChar == '2')
    {
      Serial.print("distribution");
      
      digitalWrite(13, HIGH);  // on allume la LED pour le début de la distribution
      monServo.write(180); // on déplace le servo de 180°
      delay(3000);         // on attend que les coquettes/friandises tombes
      monServo.write(0);   // le servo retourne à sa position original
      delay(50);
      digitalWrite(13, LOW);  // on éteint la LED pour la fin de la distribution
    }
  }
}
