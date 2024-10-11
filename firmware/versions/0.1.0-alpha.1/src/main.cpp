#include <Arduino.h>
#include "SEN55Sensor.h"
#include "BMP280Sensor.h"

// Create sensor interface pointers for the SEN55 and BMP280 sensors
SensorInterface<SEN55Data>* environmentSensor = new SEN55Sensor();
SensorInterface<BMP280Data>* pressureSensor = new BMP280Sensor();

void setup() {

  // Initialize the serial communication at a baud rate of 115200
  Serial.begin(115200);

  // Variable to hold any potential error messages
  char errorMessage[256];

  // Initialize the SEN55 sensor and check for errors
  if (!environmentSensor->begin(errorMessage)) {
    Serial.print("Error : ");
    Serial.println(errorMessage);  // Print error message if initialization fails
  }

  // Initialize the BMP280 sensor, ignoring error messages
  pressureSensor->begin(nullptr);
}

void loop() {
  // Read data from the SEN55 sensor
  SEN55Data envData = environmentSensor->readSensorData();

  // Read data from the BMP280 sensor
  BMP280Data pressData = pressureSensor->readSensorData();

  // Print any error messages from the SEN55 sensor
  Serial.print("Error message : ");
  Serial.println(envData.errorMessage);

  // Print environmental data from the SEN55 sensor
  Serial.print("Ambient temperature : ");
  Serial.println(envData.ambientTemperature);

  Serial.print("Ambient humidity : ");
  Serial.println(envData.ambientHumidity);

  Serial.print("PM1.0 concentration : ");
  Serial.println(envData.massConcentrationPm1p0);

  Serial.print("PM2.5 concentration : ");
  Serial.println(envData.massConcentrationPm2p5);

  Serial.print("PM4.0 concentration : ");
  Serial.println(envData.massConcentrationPm4p0);

  Serial.print("PM10.0 concentration : ");
  Serial.println(envData.massConcentrationPm10p0);

  // Print gas indices from the SEN55 sensor (VOC and NOx indices)
  Serial.print("VOC index : ");
  Serial.println(envData.vocIndex);

  Serial.print("NOx index : ");
  Serial.println(envData.noxIndex);

  // Print temperature and pressure from the BMP280 sensor
  Serial.print("BMP280 temperature : ");
  Serial.println(pressData.temperature);

  Serial.print("BMP280 pressure : ");
  Serial.println(pressData.pressure);

  // Print a separator line for readability
  Serial.println("...........................\n");

  // Wait for 4 seconds before the next loop iteration
  delay(4000);
}
