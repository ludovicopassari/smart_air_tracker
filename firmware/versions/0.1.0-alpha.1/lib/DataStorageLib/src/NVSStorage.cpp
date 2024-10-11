//
// Created by Ludovico Passari on 02/10/24.
//

#include "NVSStorage.h"

void NVSStorage::end() {
  preferences.end();
}

bool NVSStorage::begin() {
  return preferences.begin("esp32-device", false); // Namespace "my-app", non sola lettura
}

bool NVSStorage::writeString(const char *key, String valueToWrite, bool checkWrite) {
  bool success = true;
  preferences.putString(key, valueToWrite);

  if (checkWrite) {

    success &= preferences.getString(key, "") == valueToWrite;

  }

  return success;
}


String NVSStorage::readString(const char *key) {
  return preferences.getString(key);
}

