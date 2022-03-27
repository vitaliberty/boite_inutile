#include "fonctions.h"
#include "PacmanNotes.h"
#include "Arduino.h"

void pacman(){

  const int ledPinRouge = 13; 
  const int ledPinVert = 12;
  int counter = 0;
  
  int tempo = 105;

  // change this to whichever pin you want to use
  int buzzer = 9;

  int melody[] = {

  // Pacman
  // Score available at https://musescore.com/user/85429/scores/107109
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
  NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

  NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
  NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
  NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  
  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;
  
  int divider = 0, noteDuration = 0;

   pinMode(ledPinRouge, OUTPUT);
   pinMode(ledPinVert, OUTPUT);

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    if(counter % 2 == 0)
    {
    digitalWrite(ledPinRouge, HIGH);
    delay(noteDuration);
    digitalWrite(ledPinRouge, LOW);
    }else
    {
    digitalWrite(ledPinVert, HIGH);
    delay(noteDuration);
    digitalWrite(ledPinVert, LOW);
    }
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
    counter++;
  }
  
}
