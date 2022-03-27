#include "fonctions.h"

#include "Arduino.h"

void pirates(){
// Define pin 10 for buzzer, you can use any other digital pins (Pin 0-13)
const int buzzer = 9;
const int ledPinRouge = 13; 
const int ledPinVert = 12;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songspeed = 0.75;

int counter = 0;

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988

int notes[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0
};
    

// Durations (in ms) of each music note of the song
// Quarter Note is 250 ms when songSpeed = 1.0
int duration[] = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125
    };

  pinMode(ledPinRouge, OUTPUT);
  pinMode(ledPinVert, OUTPUT);

  for (int i=0;i<36;i++)
  {
  int wait = duration[i] * songspeed;
  tone(buzzer,notes[i],wait);
  if(counter % 2 == 0)
    {
    digitalWrite(ledPinRouge, HIGH);
    delay(wait);
    digitalWrite(ledPinRouge, LOW);
    }else
    {
    digitalWrite(ledPinVert, HIGH);
    delay(wait);
    digitalWrite(ledPinVert, LOW);
    }
  delay(wait);
  counter++;
  }
}
