//
// Created by Ludovico Passari on 02/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_DATASTORAGE_H
#define INC_0_1_0_ALPHA_1_DATASTORAGE_H

#include <Arduino.h>
#include "DeviceConfig.h"

class DataStorage {
public:
  virtual bool begin() = 0;

  virtual void end() = 0;

  virtual String readString(const char *key) = 0;

  virtual bool writeString(const char *key, String valueToWrite, bool checkWrite) = 0;
};

#endif //INC_0_1_0_ALPHA_1_DATASTORAGE_H
