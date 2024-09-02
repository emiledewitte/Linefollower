const int buttonPin = 2;  // Het pinnummer van de pushbutton
const int ledPin = 13;   // Het pinnummer van de LED
volatile int buttonState = LOW; // Variabele voor de knopstatus, gemarkeerd als 'volatile' voor gebruik met interrupts

void setup() {
  pinMode(ledPin, OUTPUT);          // Initialiseer de LED-pin als uitgang
  pinMode(buttonPin, INPUT_PULLUP); // Initialiseer de knop-pin als ingang en activeer de interne pull-up weerstand
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, RISING); // Voeg een interrupt toe voor de knop
}

void loop() {
  // Doe hier niets, de interrupt-functie zal de LED-besturing afhandelen
}

void buttonInterrupt() {
  // Lees de knopstatus en update de LED dienovereenkomstig
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {   // Knop wordt ingedrukt
    digitalWrite(ledPin, HIGH); // Zet de LED aan
  } else {                    // Knop wordt losgelaten
    digitalWrite(ledPin, LOW);  // Zet de LED uit
  }
}


