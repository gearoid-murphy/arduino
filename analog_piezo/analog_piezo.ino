// https://programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/
// https://www.arduino.cc/en/Tutorial/AnalogInput

int piezoPin = 8;
int sensorPin = A0;
int prevSensorVal = 0;
int maxFrequencyHz = 10000;
int minFrequencyHz = 50;

char printBuffer[32];

void setup() {
  Serial.begin(9600);
}

struct SerialStream
{
  SerialStream & operator << (const char *v) {
    Serial.print(v);
    return *this;
  }
  SerialStream & operator << (int v) {
    Serial.print(v);
    return *this;
  }
};

SerialStream stream;

void loop() {
  int sensorValue = analogRead(sensorPin);

  if(sensorValue != prevSensorVal) {
    int frequency = ((float(sensorValue) / 1023.0) *
                     maxFrequencyHz) + minFrequencyHz;

    Serial.print(sensorValue);
    Serial.print(" ");
    Serial.print(frequency);
    Serial.println();

    // stream <<  << " " << frequency << "\n";
    tone(piezoPin, frequency, 250);


    prevSensorVal = sensorValue;
  }
}


