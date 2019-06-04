const int buttonPin = D1;
const int ledPin =  D4;

int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  digitalWrite(ledPin, !buttonState);
}
