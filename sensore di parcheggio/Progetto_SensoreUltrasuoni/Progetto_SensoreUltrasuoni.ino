#define TRIG_PIN 10
#define ECHO_PIN 9
#define BUZZER 2
void setup(){
  Serial.begin(9600);
  DDRB = DDRB | 0b00000100; //TRIG
  DDRB = DDRB | 0b11111101; //ECHO
  DDRD = DDRD | 0b00000100; //BUZZER
  digitalWrite(TRIG_PIN, LOW);
while(true){
  PORTB = PORTB | 0b00000100;
  delayMicroseconds(100);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long tempo = pulseIn(ECHO_PIN, HIGH);
  float distanza = 0.03438 * tempo / 2;
  if(distanza >= 30&&distanza<50){
    tone(BUZZER, 3000, 200);
    delay(650);
  }
    if(distanza<30&&distanza>=15){
    tone(BUZZER, 3000, 200);
    delay(500);
  }
   if(distanza<15&&distanza>=5){
    tone(BUZZER, 3000, 200);
    delay(300);
  }
   if(distanza<5&&distanza>=2){
    tone(BUZZER, 3000, 200);
  }   
  Serial.print("Distanza: ");
  Serial.print(distanza);
  Serial.println(" cm");
  delay(200);
}
}
