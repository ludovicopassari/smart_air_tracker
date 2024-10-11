//
// Created by Ludovico Passari on 11/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_BMP280_H
#define INC_0_1_0_ALPHA_1_BMP280_H

#include "SensorInterface.h"         // Interface for sensor abstraction
#include "Adafruit_BMP280.h"         // Adafruit library to interface with the BMP280 sensor

// Structure to hold the data from the BMP280 sensor
struct BMP280Data {
  float pressure;       // Pressure in hPa (hectopascals)
  float temperature;    // Temperature in degrees Celsius
  float altitude;       // Calculated altitude based on pressure and sea level pressure
};

// Class definition for BMP280Sensor, inheriting from SensorInterface
class BMP280Sensor: public SensorInterface<BMP280Data> {
private:
  Adafruit_BMP280 bmp;  // Instance of the Adafruit BMP280 library (I2C)
  uint8_t sensorAddr;   // I2C address of the BMP280 sensor, default is 0x76

public:
  // Constructor for BMP280Sensor, allows setting a custom I2C address (default: 0x76)
  BMP280Sensor(uint8_t addr = 0x76);

  // Method to initialize the BMP280 sensor, returns true if successful, false otherwise
  bool begin(char* errorMessage = nullptr) override;

  // Method to read the sensor data and return it as a BMP280Data structure
  BMP280Data readSensorData() override;

  // Method to read only the temperature from the sensor
  float readTemperature();

  // Method to read only the pressure from the sensor
  float readPressure();

  // Method to calculate the altitude based on sea level pressure (user-defined)
  float readAltitude(float seaLevelPressure);
};

#endif //INC_0_1_0_ALPHA_1_BMP280_H
