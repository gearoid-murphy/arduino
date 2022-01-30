// https://www.youtube.com/watch?v=wxjerCHCEMg
// https://www.arduino.cc/en/Tutorial/Button

int prevSensorVal = HIGH;

void setup(){
  Serial.begin(9600);
  // pinMode(2, INPUT_PULLUP);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  int sensorVal = digitalRead(2);

  if(sensorVal != prevSensorVal)
  {
    Serial.println(sensorVal);
    prevSensorVal = sensorVal;
  }

  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  }
  else {
    digitalWrite(13, HIGH);
  }
}

