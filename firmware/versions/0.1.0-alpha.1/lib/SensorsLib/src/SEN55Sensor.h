//
// Created by Ludovico Passari on 11/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_SEN55SENSOR_H
#define INC_0_1_0_ALPHA_1_SEN55SENSOR_H

#include "SensorInterface.h"
#include <SensirionI2CSen5x.h>
#include <Wire.h>

struct SEN55Data {
  float massConcentrationPm1p0;
  float massConcentrationPm2p5;
  float massConcentrationPm4p0;
  float massConcentrationPm10p0;
  float ambientHumidity;
  float ambientTemperature;
  float vocIndex;
  float noxIndex;
  char errorMessage[256];
};

class SEN55Sensor : public SensorInterface<SEN55Data> {
private:
  SensirionI2CSen5x sen55;
public:
  SEN55Sensor();

  bool begin(char* errorMessage) override;

  SEN55Data readSensorData() override;
};


#endif //INC_0_1_0_ALPHA_1_SEN55SENSOR_H
