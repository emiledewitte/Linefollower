#define AIN1 6
#define AIN2 13
#define BIN1 9
#define BIN2 10
#define slp 4

int analogInPin = A0;
int sensorValue = 1000;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(slp, OUTPUT);

  digitalWrite(slp, HIGH);
  
}
 
void loop() {

  sensorValue = analogRead(analogInPin);

  outputValue = map(sensorValue, 0, 1023, 0, 255);

  Serial.println (outputValue);
  
  analogWrite(AIN1,outputValue); 
  digitalWrite(AIN2,LOW);
  analogWrite(BIN1,outputValue); 
  digitalWrite(BIN2,LOW);

  delay(1000);
  
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  delay(1000);
  
  digitalWrite(AIN1,LOW); 
  analogWrite(AIN2,outputValue);
  digitalWrite(BIN1,LOW); 
  analogWrite(BIN2,outputValue);

  delay(1000);
  
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  delay(1000);
   
}
