
int ledPin = D4;
void setup() {
  // There's no need to call pinMode with analogWrite. For more info check https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
}

void loop() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}
