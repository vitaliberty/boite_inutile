// Définition des fréquences des notes de musiques de la 4ème octave
#define OCTAVE_4_DO 523
#define OCTAVE_4_RE 587
#define OCTAVE_4_MI 659
#define OCTAVE_4_FA 698
#define OCTAVE_4_SOL 784
#define OCTAVE_4_LA 880
#define OCTAVE_4_SI 988
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
// Définition de la durée d'un temps en millisecondes 
#define DUREE_TEMPS 300
// Fonction de démarrage, s'exécute une seule fois:
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruption, LOW);
  Serial.println("systeme initialise");
}
// Fonction principale du programme, s'exécute en boucle:
void loop()
{
    // Jeu des 11 premières notes de "Au clair de la lune"
   
    Serial.println("musique on");
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_MI, 2);
    JouerNote(OCTAVE_4_RE, 2);
    JouerNote(OCTAVE_4_DO, 1);
    JouerNote(OCTAVE_4_MI, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_RE, 1);
    JouerNote(OCTAVE_4_DO, 4);
   
}
void JouerNote(unsigned int Note_P, unsigned int NombreTemps_P)
{
    // Lance l'émission de la note
    tone(9, Note_P, NombreTemps_P * DUREE_TEMPS);
    // Attend que la note soit terminée de jouée
    delay(NombreTemps_P * DUREE_TEMPS);

}
void interruption() {
  state = !state;
  Serial.print("je suis dans l'interruption ");
  if(state){
    Serial.println("pas de musique");
  }else{
    Serial.println("ca fonctionne");
  }
}
