const int ledPin = 13;
const unsigned long interval = 1000;

#define DEBUG

class Interval
{
    bool _state;
    unsigned long _previous;
    uint8_t _pin;
    unsigned long _interval;

  public:
    Interval(uint8_t pin, long interval = 1000):
      _state(false), _previous(0), _pin(pin), _interval(interval)
    {
      pinMode(pin, OUTPUT);
    }
    void poll(unsigned long);
    void print();
};

void Interval::poll(unsigned long current) {
  if (current - _previous >= _interval) {
    _previous = current;
    _state = !_state;
    digitalWrite(_pin, _state);
#ifdef DEBUG
    print();
#endif
  }
}

void Interval::print() {
  Serial.print("Interval with ");
  Serial.print(_pin);
  Serial.print(" pin: ");
  Serial.println(_state ? "HIGH" : "LOW");
}

Interval ledInterval(ledPin, interval);

void setup() {
  Serial.begin(9600);
  Serial.println("Intervals example started.");
}

void loop() {
  unsigned long current = millis();
  ledInterval.poll(current);
}
