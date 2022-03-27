#include "fonctions.h"
#include "SilentNighNotes.h"
#include "Arduino.h"

void silentnight(){

  const int ledPinRouge = 13; 
  const int ledPinVert = 12;
  int counter = 0;

  // change this to make the song slower or faster
  int tempo = 300;
  
  // change this to whichever pin you want to use
  int buzzer = 9;
  int melody[] = {

  // Silent Night, Original Version
  // Score available at https://musescore.com/marcsabatella/scores/3123436

  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_D5,2, NOTE_D5,4,
  NOTE_B4,-2,
  NOTE_C5,2, NOTE_C5,4,
  NOTE_G4,-2,

  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  NOTE_A4,2, NOTE_A4,4,
  NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
  NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
  NOTE_E4,-2, 
  
  NOTE_D5,2, NOTE_D5,4,
  NOTE_F5,-4, NOTE_D5,8, NOTE_B4,4,
  NOTE_C5,-2,
  NOTE_E5,-2,
  NOTE_C5,4, NOTE_G4,4, NOTE_E4,4,
  NOTE_G4,-4, NOTE_F4,8, NOTE_D4,4,
  NOTE_C4,-2,
  NOTE_C4,-1,
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
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
