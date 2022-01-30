#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing...");
  mpu.initialize();
  do {
    Serial.println("Waiting...");
    delay(100);
  } while(!mpu.testConnection());

  Serial.println("Ready!");

  // 0 == 2g
  mpu.setFullScaleAccelRange(0);
}

float Convert(int16_t v) {
    return (float(v) / 32768.0) * 2.0;
}

void loop() {
    int16_t ax = 0;
    int16_t ay = 0;
    int16_t az = 0;

    mpu.getAcceleration (&ax, &ay, &az);

    Serial.print(Convert(ax));
    Serial.print(" | ");
    Serial.print(Convert(ay));
    Serial.print(" | ");
    Serial.print(Convert(az));
    Serial.println();

    delay(10);
}

