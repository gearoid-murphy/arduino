// https://www.arduino.cc/en/Tutorial/AnalogInput

int sensorPin = A0;
int prevSensorVal = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  if(sensorValue != prevSensorVal)
  {
    Serial.println(sensorValue);
    prevSensorVal = sensorValue;
  }
}

