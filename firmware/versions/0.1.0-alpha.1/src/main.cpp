#include <Arduino.h>

#include "SEN55Sensor.h"
#include "BMP280Sensor.h"

SensorInterface<SEN55Data>* environmentSensor = new SEN55Sensor();
SensorInterface<BMP280Data>* pressureSensor = new BMP280Sensor();

void setup() {

  Serial.begin(115200);
  while (!Serial);

  char errorMessage[256];
  if (!environmentSensor->begin(errorMessage)) {
    Serial.print("Error : ");
    Serial.println(errorMessage);
  }

  pressureSensor->begin(nullptr);


}

void loop() {

  SEN55Data envData = environmentSensor->readSensorData();
  BMP280Data pressData = pressureSensor->readSensorData();

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

  Serial.print("BMP280 temperature : ");
  Serial.println(pressData.temperature);

  Serial.print("BMP280 pressure : ");
  Serial.println(pressData.pressure);


  Serial.println("...........................\n");
  delay(4000);
}


