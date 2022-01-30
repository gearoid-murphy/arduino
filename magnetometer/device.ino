#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include "Wire.h"
#include "MPU9250.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
MPU9250 IMU(Wire,0x68);
char print_buffer[32];
float x_avg = 0;
float y_avg = 0;
float z_avg = 0;
constexpr int window = 1;
int cycle_count = 0;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  int status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }

  IMU.setAccelRange(MPU9250::ACCEL_RANGE_2G);
  IMU.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  IMU.setSrd(19);
  IMU.calibrateAccel();

  lcd.begin();
  lcd.clear();
  lcd.setBacklight(HIGH);
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
  IMU.readSensor();

  x_avg = updateavg(x_avg, IMU.getMagX_uT());
  y_avg = updateavg(y_avg, IMU.getMagY_uT());
  z_avg = updateavg(z_avg, IMU.getMagZ_uT());

  // x_avg = updateavg(x_avg, IMU.getAccelX_mss());
  // y_avg = updateavg(y_avg, IMU.getAccelY_mss());
  // z_avg = updateavg(z_avg, IMU.getAccelZ_mss());

  if(cycle_count % 10 == 0) {
    printline(0, "x: %s", x_avg);
    printline(1, "y: %s", y_avg);
    printline(2, "z: %s", z_avg);
  }
  cycle_count += 1;
}
