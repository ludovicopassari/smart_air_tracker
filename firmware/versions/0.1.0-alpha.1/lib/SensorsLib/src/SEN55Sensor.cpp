//
// Created by Ludovico Passari on 11/10/24.
//

#include "SEN55Sensor.h"

SEN55Sensor::SEN55Sensor() = default;

void SEN55Sensor::begin() {
  Wire.begin();

  sen55.begin(Wire);

  uint16_t error;
  char errorMessage[256];
  error = sen55.deviceReset();
  if (error) {
    Serial.print("Error trying to execute deviceReset(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  }

  float tempOffset = 0.0;
  error = sen55.setTemperatureOffsetSimple(tempOffset);
  if (error) {
    Serial.print("Error trying to execute setTemperatureOffsetSimple(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  } else {
    Serial.print("Temperature Offset set to ");
    Serial.print(tempOffset);
    Serial.println(" deg. Celsius (SEN54/SEN55 only");
  }

  // Start Measurement
  error = sen55.startMeasurement();
  if (error) {
    Serial.print("Error trying to execute startMeasurement(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
  }


}

SEN55Data SEN55Sensor::readSensorData() {
  uint16_t error;
  char errorMessage[256] = {};

  delay(1000);
  // declare and init struct with predefined data-type values
  SEN55Data measuredData{};


  error = sen55.readMeasuredValues(
          measuredData.massConcentrationPm1p0, measuredData.massConcentrationPm2p5, measuredData.massConcentrationPm4p0,
          measuredData.massConcentrationPm10p0, measuredData.ambientHumidity, measuredData.ambientTemperature,
          measuredData.vocIndex,
          measuredData.noxIndex);


  errorToString(error, errorMessage, 256);
  strcpy(measuredData.errorMessage, errorMessage);

  return measuredData;

}