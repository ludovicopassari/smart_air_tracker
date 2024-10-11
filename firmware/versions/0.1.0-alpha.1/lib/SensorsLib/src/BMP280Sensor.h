//
// Created by Ludovico Passari on 11/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_BMP280_H
#define INC_0_1_0_ALPHA_1_BMP280_H

#include "SensorInterface.h"
#include "Adafruit_BMP280.h"

struct BMP280Data{
  float pressure;
  float temperature;
  float altitude;
};

class BMP280Sensor: public SensorInterface<BMP280Data> {
private:
  Adafruit_BMP280 bmp; // I2C
  uint8_t sensorAddr;
public:
  BMP280Sensor(uint8_t addr = 0x76);
  bool begin(char* errorMessage = nullptr) override;
  BMP280Data readSensorData() override;
  float readTemperature();
  float readPressure();
  float readAltitude(float seaLevelPressure);

};


#endif //INC_0_1_0_ALPHA_1_BMP280_H
