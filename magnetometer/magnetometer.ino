#include <LCD_I2C.h>

#include <SPI.h>
#include "Wire.h"
#include "MPU9250.h"

LCD_I2C lcd(0x27, 20, 4);
MPU9250 mpu; // You can also use MPU9255 as is

char print_buffer[32];
float x_avg = 0;
float y_avg = 0;
float z_avg = 0;
constexpr int window = 1;
int cycle_count = 0;

void setup() {
  // serial to display data
  Serial.begin(115200);
  Wire.begin();

  while(!Serial) {}

  delay(2000);
  mpu.setup(0x68);

  lcd.begin();
  lcd.clear();
  // lcd.setBacklight(HIGH);
}

void printline(int row_offset, const char *format_str, float value) {
  char num_buffer[16];
  lcd.setCursor(0, row_offset);
  snprintf(print_buffer, 32, format_str, dtostrf(value, 8, 6, num_buffer));
  lcd.print(print_buffer);
}

inline float updateavg(float avg, float new_sample) {
  avg -= avg / window;
  avg += new_sample / window;
  return avg;
}

void loop() {
  // read the sensor
  if (mpu.update()) {
    // x_avg = updateavg(x_avg, IMU.getAccelX_mss());
    // y_avg = updateavg(y_avg, IMU.getAccelY_mss());
    // z_avg = updateavg(z_avg, IMU.getAccelZ_mss());

    if(cycle_count % 10 == 0) {
      printline(0, "x: %s", mpu.getYaw());
      printline(1, "y: %s", mpu.getPitch());
      printline(2, "z: %s", mpu.getRoll());
    }
    cycle_count += 1;
  }
}
