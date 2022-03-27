**----Boite inutile----**

**---Connexion Arduino IDE---**

Arduino Nano "Atmega328P (Old Bootloader) <- dans mon cas/ si non modifier, si besoin"

**--Assignation Pin dans le code--**

ledPinRouge = Pin D13
ledPinVert = Pin D12
frontSwitchPin = Pin D2
handServoPin = Pin D6
boxServoPin = Pin D5
buzzerPin = Pin D9

**-Description Fichiers-**

hardware : gerber file , pour fabriquer pcb via une CNC.
schema_pin_connect_pcb : se reperer sur le circuit imprimé (PCB) pour les Pin de connection.
software/boiteInutile : fichier .ino , .h , .cpp , ce sont des fichiers de compilation du code Arduino Nano
software/boiteInutile/arduino-songs-Buzzer : ce sont des differents types de melodies au choix, a incorporer dans le code a compiler. Utilisation d'un Buzzer Pasif.
Schematic_boite_innutile_arduino_nano : schema de connection.