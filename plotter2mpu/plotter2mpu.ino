// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpup;
Adafruit_MPU6050 mpud;
sensors_event_t au, gu, tempu;
sensors_event_t ad, gd, tempd;
void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  // Try to initialize!
  if (!mpup.begin(0x68)) {
    Serial.println("Failed to find MPU6050u chip");
    while (1) {
      delay(10);
    }
  }
  if (!mpud.begin(0x69)) {
    Serial.println("Failed to find MPU6050d chip");
    while (1) {
      delay(10);
    }
  }

  mpup.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpup.setGyroRange(MPU6050_RANGE_250_DEG);
  mpup.setFilterBandwidth(MPU6050_BAND_21_HZ);

  mpud.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpud.setGyroRange(MPU6050_RANGE_250_DEG);
  mpud.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */


  mpup.getEvent(&au, &gu, &tempu);
  mpud.getEvent(&ad, &gd, &tempd);
  Serial.print("AccelXU:");
  Serial.print(au.acceleration.x);
  Serial.print(",");/*
  Serial.print("AccelYU:");
  Serial.print(au.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZU:");
  Serial.print(au.acceleration.z);
  Serial.print(",");*/
  Serial.print("AccelXD:");
  Serial.print(ad.acceleration.x);
   Serial.print(",");
  Serial.print("AccelXUD:");
  Serial.print((au.acceleration.x+ad.acceleration.x)/2);
  /*
  Serial.print(",");
  Serial.print("AccelYD:");
  Serial.print(ad.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZD:");
  Serial.print(ad.acceleration.z);*/

  /*
    Serial.print(", ");
    Serial.print("GyroXU:");
    Serial.print(gu.gyro.x);
    Serial.print(",");
    Serial.print("GyroYU:");
    Serial.print(gu.gyro.y);
    Serial.print(",");
    Serial.print("GyroZU:");
    Serial.print(gu.gyro.z);
    Serial.println("");*/

  /*
    Serial.print(", ");
    Serial.print("GyroXD:");
    Serial.print(gd.gyro.x);
    Serial.print(",");
    Serial.print("GyroYD:");
    Serial.print(gd.gyro.y);
    Serial.print(",");
    Serial.print("GyroZD:");
    Serial.print(gd.gyro.z);*/
  Serial.println("");
  delay(10);
}
