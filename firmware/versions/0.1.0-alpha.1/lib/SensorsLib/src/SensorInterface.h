//
// Created by Ludovico Passari on 11/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_SENSORINTERFACE_H
#define INC_0_1_0_ALPHA_1_SENSORINTERFACE_H


// SensorInterface.h
template<typename T>
class SensorInterface {
public:
  // returns true if some error occur
  virtual bool begin(char* errorMessage) = 0;


  //virtual float readSingleValue() = 0;


  virtual T readSensorData() = 0;


  virtual ~SensorInterface() {}
};

#endif //INC_0_1_0_ALPHA_1_SENSORINTERFACE_H
