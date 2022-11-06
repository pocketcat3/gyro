#include "MPU6050.h"
#include "LedControl.h"

int Yangel;
int Xangel;
int ax, ay, az, gx, gy, gz;
MPU6050 accgyro;

LedControl lc = LedControl(12, 11, 10, 1);
void setup() {
  Serial.begin(38400);
  accgyro.initialize();
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {

  accgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Yangel = map(ay, 10000, -10000, 7, 0);
  Xangel = map(ax, 10000, -10000, 0, 7);
  lc.setLed(0, Yangel, Xangel, 1);
  Serial.print(ax);
  Serial.print(',');
  Serial.print(ay);
  Serial.print(',');
  Serial.println();
  delay(80);
  lc.clearDisplay(0);
 
}
