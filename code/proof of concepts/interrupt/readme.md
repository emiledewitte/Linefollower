# start/stop interrupt proof of concept
minimale hard- en software die de correcte werking van een start/stop drukknop aantoont, gebruik makend van een hardware interrupt

const int buttonPin = 2;  
const int ledPin = 13;  
volatile int buttonState = LOW; 

void setup() {
  pinMode(ledPin, OUTPUT);          
  pinMode(buttonPin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE); 
}

void loop() {
  
}

void buttonInterrupt() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {   
    digitalWrite(ledPin, HIGH); // LED aan
  } else {                    
    digitalWrite(ledPin, LOW);  // LED uit
  }
}






