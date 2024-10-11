//
// Created by Ludovico Passari on 11/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_SEN55SENSOR_H
#define INC_0_1_0_ALPHA_1_SEN55SENSOR_H

#include "SensorInterface.h"     // Include the interface that SEN55Sensor will implement
#include <SensirionI2CSen5x.h>   // Library for interfacing with the SEN55 sensor over I2C
#include <Wire.h>                // I2C communication library for Arduino

// Structure to hold the data from the SEN55 sensor
struct SEN55Data {
  float massConcentrationPm1p0;  // PM1.0 particulate matter concentration
  float massConcentrationPm2p5;  // PM2.5 particulate matter concentration
  float massConcentrationPm4p0;  // PM4.0 particulate matter concentration
  float massConcentrationPm10p0; // PM10.0 particulate matter concentration
  float ambientHumidity;         // Ambient humidity in percentage
  float ambientTemperature;      // Ambient temperature in degrees Celsius
  float vocIndex;                // VOC (Volatile Organic Compounds) index
  float noxIndex;                // NOx (Nitrogen Oxides) index
  char errorMessage[256];        // Error message string (if any error occurs)
};

// Class definition for SEN55Sensor, inheriting from SensorInterface
class SEN55Sensor : public SensorInterface<SEN55Data> {
private:
  SensirionI2CSen5x sen55;       // Private instance of the SEN55 sensor from the Sensirion library

public:
  // Constructor for the SEN55 sensor class
  SEN55Sensor();

  // Method to initialize the sensor, returns true if successful, false otherwise
  bool begin(char* errorMessage) override;

  // Method to read the sensor data and return it as an SEN55Data structure
  SEN55Data readSensorData() override;
};

#endif //INC_0_1_0_ALPHA_1_SEN55SENSOR_H
