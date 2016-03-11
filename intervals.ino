const int ledPin = 13;
const unsigned long interval = 1000;

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
};

void Interval::poll(unsigned long current) {
  if (current - _previous >= _interval) {
    _previous = current;
    _state = !_state;
    digitalWrite(_pin, _state);
  }
}

Interval ledInterval(ledPin, interval);

void setup() {
}

void loop() {
  unsigned long current = millis();
  ledInterval.poll(current);
}
