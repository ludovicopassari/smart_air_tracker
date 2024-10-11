//
// Created by Ludovico Passari on 02/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_NVSSTORAGE_H
#define INC_0_1_0_ALPHA_1_NVSSTORAGE_H

#include "DataStorage.h"
#include <Preferences.h>


class NVSStorage : public DataStorage {
private:
  Preferences preferences;
public:
  bool begin() override;

  void end() override;

  bool writeString(const char *key, String valueToWrite, bool checkWrite);

  String readString(const char *key);
};


#endif //INC_0_1_0_ALPHA_1_NVSSTORAGE_H
