const int ledPin = 13;
const unsigned long interval = 1000;

bool ledState = false;
unsigned long previous;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long current = millis();
  if (current - previous >= interval) {
    previous = current;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
