#include "fonctions.h"
#include "Arduino.h"
void lumiere(int ledPinVert, int ledPinRouge){
  

  for (int i = 0; i <= 1; i++){
  digitalWrite(ledPinVert, HIGH);
  digitalWrite(ledPinRouge, LOW);
  delay(50);
  digitalWrite(ledPinVert, LOW);
  digitalWrite(ledPinRouge, HIGH);
  delay(50);
  }
  
}
