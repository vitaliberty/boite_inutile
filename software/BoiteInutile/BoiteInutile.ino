// fichiers et bibliotheques a inclure.
#include "NokiaNotes.h"
#include "fonctions.h"
#include <Servo.h>                     

// declaration variables Servo.
Servo handServo;         // tantatuce pour intervenir sur le bouton frontal de la boite inutile                
Servo boxServo;          // tantatuce pour intervenir sur l'ouverture de la boite inutile

// declaration Notes StarWars.
const int c = 261;
const int d = 294;
const int dS = 311;
const int e = 329;
const int f = 349;
const int fS = 370;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 466;
const int aSL = 233;
const int b = 494;
const int bH = 932;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int fSL = 185;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

// assignation Pin et differentes valeurs.
int switchStatus=0, action=1, vot, randNumber=0;                
const int ledPinRouge = 13; 
const int ledPinVert = 12;
const int frontSwitchPin = 2;
const int handServoPin = 6;
const int boxServoPin = 5;
const int buzzerPin = 9;
//const int buzzer = 9;
int counter = 0;

void setup()
{
  Serial.begin(9600);   // "baudrate" communication moniteur / arduino

  // declaration type de Pin.
  pinMode(ledPinRouge, OUTPUT);  
  pinMode(ledPinVert, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // attachement assignation Pin et declaration variables des Servo.
  handServo.attach(handServoPin);           
  boxServo.attach(boxServoPin);
  handServo.write(180);                       
  boxServo.write(40);

  // option RANDOM, si utilisation;  a decommenter sur ligne 63 et 81.
  //randomSeed(analogRead(0));

  // demarage de la boite inutile , appel fonction melodie nokia et fonction lumiere pour l'activation des led's (facultatif).
  nokia();
  lumiere(ledPinVert, ledPinRouge);
}


void loop()
{
// boite inutile fermé, jeu de lumiere en cours. 
lumiere(ledPinVert, ledPinRouge);

  
// si bouton frontal est active, alors choix parmis 16 comportements differents en fonction du compteur sous le nom de variable "action" 
  
  switchStatus = digitalRead(frontSwitchPin); 
  
  //action = random(1,16);
   
  if (switchStatus == LOW){                 

    if (action == 1)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 1");    
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 100; i--)
      {
        handServo.write(i);
        delay(20);
      }
      pacman();                       // appel de la melodie Pac Man
      for (int i = 100; i <=130; i++)
      {
        handServo.write(i);
        delay(6);
      }
      for (int i = 130; i >= 26; i--){
        handServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 26; i <=180; i++)
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 100; i >= 40; i--)
      {
        boxServo.write(i);
        delay(20);
      }
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    
    else if (action == 2)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 2");       
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(550);
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(550);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 3)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 3");        
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      boxServo.write(70);
      delay(2000);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(500);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
   
    else if (action == 4)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 4");      
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 85; i--)
      {
        handServo.write(i);
        delay(20);
      }
      pirates();                       // appel de la melodie Pirates des Caribes
      delay(2000);
      handServo.write(0);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 5)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 5");    
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      handServo.write(65);
      delay(550);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(2000);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 6)             
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 6");      
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 12; i++)
      {
        for (int j = 40; j <= 100; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = 180; i >= 85; i--)
      {
        handServo.write(i);
        delay(30);
      }
      handServo.write(0);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      delay(1500);
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 7)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 7");   
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(400);
      handServo.write(66);
      delay(1000);
      for (int i = 0; i < 6; i++)
      {
        for (int j = 40; j <= 100; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      delay(500);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 8)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 8");    
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 7; i++)
      {
        handServo.write(95);
        delay(100);
        handServo.write(70);
        delay(100);
      }
      delay(500);
      handServo.write(180);
      delay(1000);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 9)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 9");      
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      boxServo.write(100);
      for (int i = 180; i >=85; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(500);
      takeonme();                       // appel de la melodie Take On Me
      digitalWrite(ledPinRouge, HIGH);
      handServo.write(40);
      delay(200);
      for (int i = 0; i <=180; i++)
      {
        handServo.write(i);
        delay(40);
      }
      boxServo.write(40);
      delay(2000);
      boxServo.write(80);
      delay(3000);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
  
    
    else if (action == 10)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 10");     
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(100);
      }
      delay(1000);
      for (int i = 0; i < 10; i++)
      {
        for (int j = 40; j <= 100; j++){
          boxServo.write(j);
          delay(6);
      }
        delay(100);
      }
      boxServo.write(100);
      delay(100);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 11)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 11");     
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 3; i++)
      {
        handServo.write(95);
        delay(200);
        handServo.write(70);
        delay(200);
      }
      delay(1500);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      delay(1500);
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      //silentnight();
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 12)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 12");      
      for (int i = 40; i <= 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 180; i >= 96; i--)
      {
        handServo.write(i);
        delay(50);
      }
      delay(2000);
      handServo.write(0);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 13)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 13");  
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      for (int i = 180; i >= 60; i--)
      {
        handServo.write(i);
        delay(70);
      }
      for (int i = 0; i < 3; i++)
      {
        handServo.write(90);
        delay(200);
        handServo.write(70);
        delay(800);
      }
      //zelda();
      handServo.write(0);
      delay(2000);
      handServo.write(180);
      delay(500);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 14)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 14");     
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(4000);
      boxServo.write(100);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(500);
      boxServo.write(80);
      delay(4000);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    
    else if (action == 15)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 15");    
      for (int i = 40; i <= 100; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 0; i < 3; i++)
      {      
        for (int j = 40; j <= 95; j++){
          boxServo.write(j);
          delay(50);
        }
        for (int j = 95; j >= 40; j--)
        {
          boxServo.write(j);
          delay(50);
        }
      }
      for (int j = 40; j <= 110; j++){
        boxServo.write(j);
        delay(20);
      }
      for (int i = 180; i >= 95; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(1000);
      handServo.write(0);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(40);
      action++;
      digitalWrite(ledPinRouge, LOW);
    }
    else if (action == 16)
    {
      digitalWrite(ledPinVert, LOW);
      digitalWrite(ledPinRouge, HIGH);
      Serial.println("Action 16");   
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 100; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 100; i <=130; i++)
      {
        handServo.write(i);
        delay(6);
      }
      for (int i = 0; i >= 10; i++)
      {
        for (int i = 130; i >= 100; i--)
        {
          handServo.write(i);
          delay(20);
        }
        delay(1000);
        for (int i = 100; i <=130; i++)
        {
          handServo.write(i);
          delay(6);
        }
      }
      for (int i = 130; i >= 26; i--){
        handServo.write(i);
        delay(6);
      }
      delay(1000);
      
      for (int i = 100; i >= 40; i--)
      {
        boxServo.write(i);
        delay(6);
      }
      for (int i = 0; i <= 15; i++)
      {
        digitalWrite(ledPinVert, HIGH);
        digitalWrite(ledPinRouge, LOW);
        delay(50);
        digitalWrite(ledPinVert, LOW);
        digitalWrite(ledPinRouge, HIGH);
        delay(50);
      }
      for (int i = 40; i <= 100; i++)
      {
        boxServo.write(i);
        delay(6);
      }
      firstSection();                       // appel de la melodie Star Wars
      for (int i = 26; i <=180; i++)
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 100; i >= 40; i--)
      {
        boxServo.write(i);
        delay(20);
      }
        boxServo.write(100);
        boxServo.write(40);
        boxServo.write(100);
        boxServo.write(40);
        boxServo.write(100);
        boxServo.write(40);
        boxServo.write(100);
        delay(550);
        handServo.write(100);
        delay(550);
        handServo.write(180);
        boxServo.write(40);
      action = 1;
      digitalWrite(ledPinRouge, LOW);
    }
    
  }

}
// fin de choix de comportemnts.

////////////////////////////////////////////////////////

// musique de Star Wars

// Fonction Buzzer
void beep(int note, int duration)
{
//Play tone on buzzerPin
tone(buzzerPin, note, duration);

//Play different LED depending on value of 'counter'
if(counter % 2 == 0)
{
digitalWrite(ledPinRouge, HIGH);
delay(duration);
digitalWrite(ledPinRouge, LOW);
}else
{
digitalWrite(ledPinVert, HIGH);
delay(duration);
digitalWrite(ledPinVert, LOW);
}

//Stop tone on buzzerPin
noTone(buzzerPin);

delay(50);

//Increment counter
counter++;
}

// Fonction d'appel de la melodie "StarWars" (exemple ligne 620).
void firstSection()
{

beep(g, 500);
beep(g, 500);
beep(g, 500);
beep(dS, 350);
beep(aS, 150);
beep(g, 500);
beep(dS, 350);
beep(aS, 150);
beep(g, 650);

delay(500);

beep(dH, 500);
beep(dH, 500);
beep(dH, 500);
beep(dSH, 350);
beep(aS, 150);
beep(fS, 500);
beep(dS, 350);
beep(aS, 150);
beep(g, 650);

delay(500);

beep(gH, 500);
beep(g, 300);
beep(g, 150);
beep(gH, 500);
beep(fSH, 325);
beep(fH, 175);
beep(eH, 125);
beep(dSH, 125);
beep(eH, 250);

delay(325);

beep(gS, 250);
beep(cSH, 500);
beep(cH, 325);
beep(b, 175);
beep(aS, 125);
beep(a, 125);
beep(aS, 250);

delay(350);

beep(dS, 250);
beep(fS, 500);
beep(dS, 350);
beep(fS, 125);
beep(aS, 500);
beep(g, 375);
beep(aS, 125);
beep(dH, 650);

delay(500);

beep(gH, 500);
beep(g, 300);
beep(g, 150);
beep(gH, 500);
beep(fSH, 325);
beep(fH, 175);
beep(eH, 125);
beep(dSH, 125);
beep(eH, 250);

delay(325);

beep(gS, 250);
beep(cSH, 500);
beep(cH, 325);
beep(b, 175);
beep(aS, 125);
beep(a, 125);
beep(aS, 250);

delay(350);

beep(dS, 250);
beep(fS, 500);
beep(dS, 350);
beep(aS, 150);
beep(g, 500);
beep(dS, 350);
beep(aS, 150);
beep(g, 650);

delay(500);

}
