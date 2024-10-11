//
// Created by Ludovico Passari on 11/10/24.
//

#include "BMP280Sensor.h"

// Constructor for BMP280Sensor, initializes the sensor address
BMP280Sensor::BMP280Sensor(uint8_t addr) : sensorAddr(addr) {

}

// Method to initialize the BMP280 sensor
bool BMP280Sensor::begin(char *errorMessage) {
  bool status;

  // Initialize the BMP280 sensor with the specified I2C address (0x76 in this case)
  status = bmp.begin(sensorAddr);

  // If sensor initialization fails, return false
  if (!status) {
    return status;  // You can optionally use errorMessage to provide a more detailed error message
  }

  // Configure the BMP280 sensor with default settings
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode: Normal */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temperature oversampling: x2 */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling: x16 */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering: x16 */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time: 500 ms */

  return true;  // Return true if the initialization and configuration succeed
}

// Method to read all sensor data (temperature, pressure, and altitude) from the BMP280 sensor
BMP280Data BMP280Sensor::readSensorData() {
  BMP280Data measuredData;

  // Read temperature, pressure, and calculate altitude
  measuredData.temperature = bmp.readTemperature();
  measuredData.pressure = bmp.readPressure();
  measuredData.altitude = bmp.readAltitude();

  return measuredData;  // Return the structure containing the sensor readings
}

// Method to read only the temperature from the BMP280 sensor
float BMP280Sensor::readTemperature() {
  return bmp.readTemperature();
}

// Method to read only the pressure from the BMP280 sensor
float BMP280Sensor::readPressure() {
  return bmp.readPressure();
}

// Method to calculate altitude based on pressure and user-defined sea level pressure
// Default sea level pressure is 1013.25 hPa
float BMP280Sensor::readAltitude(float seaLevelPressure) {
  return bmp.readAltitude(seaLevelPressure);
}
