int buttonState = HIGH;
int buttonPing = 12;
int buzzerPin = 11;

void play(int frequency, int wait) {
  tone(buzzerPin, frequency);
  delay(wait);
  noTone(buzzerPin);
}


void setup() {
  // initialize digital pin
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPing, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.setTimeout(300);
  play(659, 200);
}

void loop() {
  buttonState = digitalRead(buttonPing);
  if(buttonState == LOW) {
    play(523, 250);
    Serial.println("hola");
  }

  String pcText = "";
  while(Serial.available()) {
    pcText+= Serial.readString();
  }

  pcText.trim();
  if(pcText == "music") {
    play(783, 400);
  }
  
}
