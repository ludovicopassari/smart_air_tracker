//
// Created by Ludovico Passari on 11/10/24.
//

#include "SEN55Sensor.h"

// Constructor for SEN55Sensor - the default constructor doesn't need any specific initialization
SEN55Sensor::SEN55Sensor() = default;

// Method to initialize the SEN55 sensor
bool SEN55Sensor::begin(char *errorMessage) {
  // Initialize I2C communication
  Wire.begin();

  // Initialize the SEN55 sensor with the I2C communication object
  sen55.begin(Wire);

  uint16_t error;

  // Perform a device reset to ensure sensor is in a known state
  error = sen55.deviceReset();

  // If there's an error during reset, convert the error to a string and return false
  if (error) {
    errorToString(error, errorMessage, 256);  // Convert error code to a human-readable message
    return false;
  }

  // Set the temperature offset (0.0 by default)
  float tempOffset = 0.0;
  error = sen55.setTemperatureOffsetSimple(tempOffset);

  // If setting the temperature offset fails, return the error
  if (error) {
    errorToString(error, errorMessage, 256);
    return false;
  }

  // Start measurement on the SEN55 sensor
  error = sen55.startMeasurement();

  // If there's an error starting the measurement, return the error
  if (error) {
    errorToString(error, errorMessage, 256);
    return false;
  }

  // Return true if initialization is successful
  return true;
}

// Method to read data from the SEN55 sensor
SEN55Data SEN55Sensor::readSensorData() {
  uint16_t error;  // Variable to hold any error codes
  char errorMessage[256] = {};  // Buffer for error messages, initialized as an empty string

  // Wait for 1 second before reading data to ensure measurement is complete
  delay(1000);

  // Declare and initialize a structure to hold the sensor data
  SEN55Data measuredData{};

  // Read the measured values from the SEN55 sensor
  // This reads PM concentrations, humidity, temperature, VOC and NOx indices
  error = sen55.readMeasuredValues(
          measuredData.massConcentrationPm1p0, measuredData.massConcentrationPm2p5, measuredData.massConcentrationPm4p0,
          measuredData.massConcentrationPm10p0, measuredData.ambientHumidity, measuredData.ambientTemperature,
          measuredData.vocIndex,
          measuredData.noxIndex);

  // Convert any error code into a human-readable error message
  errorToString(error, errorMessage, 256);

  // Copy the error message into the `measuredData` structure to be returned
  strcpy(measuredData.errorMessage, errorMessage);

  // Return the structure containing the sensor data
  return measuredData;
}
