//
// Created by Ludovico Passari on 11/10/24.
//

#include "BMP280Sensor.h"

BMP280Sensor::BMP280Sensor(uint8_t addr) : sensorAddr(addr) {

}

bool BMP280Sensor::begin(char *errorMessage) {
  bool status;
  status = bmp.begin(0x76);
  if (!status) {
    return status;
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  return true;
}

BMP280Data BMP280Sensor::readSensorData() {
  BMP280Data measuredData;

  measuredData.temperature = bmp.readTemperature();
  measuredData.pressure = bmp.readPressure();
  measuredData.altitude = bmp.readAltitude();

  return measuredData;
}

float BMP280Sensor::readTemperature() {
  return bmp.readTemperature();
}

float BMP280Sensor::readPressure() {
  return bmp.readPressure();
}

float BMP280Sensor::readAltitude(float seaLevelPressure = 1013.25) {
  return bmp.readAltitude(seaLevelPressure);
}