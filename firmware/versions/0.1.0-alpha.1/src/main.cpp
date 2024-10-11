#include <Arduino.h>
#include "Sensor.h"
#include "SEN55Sensor.h"

SensorInterface<SEN55Data>* environmentSensor = new SEN55Sensor();

void setup() {

  Serial.begin(115200);
  while (!Serial);

  environmentSensor->begin();


}

void loop() {

  SEN55Data envData = environmentSensor->readSensorData();

  Serial.print("Error message : ");
  Serial.println(envData.errorMessage);

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

  Serial.print("VOC index : ");
  Serial.println(envData.vocIndex);

  Serial.print("NOx index : ");
  Serial.println(envData.noxIndex);


  delay(4000);
}


