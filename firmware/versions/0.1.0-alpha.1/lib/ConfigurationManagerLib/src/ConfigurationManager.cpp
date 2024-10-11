//
// Created by Ludovico Passari on 02/10/24.
//

#include "ConfigurationManager.h"

ConfigurationManager::ConfigurationManager(DataStorage *dataStorage) {
  storage = dataStorage;
}

bool ConfigurationManager::writeConfiguration(DeviceConfig &config) {
  bool success = true;

  if (storage->begin()) {
    success &= storage->writeString("wifi/ssid", config.wifi.ssid, false);
    success &= storage->writeString("wifi/passwd", config.wifi.password, false);
  }

  return success;

};

bool ConfigurationManager::readConfiguration(DeviceConfig &config) {
  if (storage->begin()) {
    config.wifi.ssid = storage->readString("wifi/ssid");
    config.wifi.password = storage->readString("wifi/passwd");
  }
  storage->end();
  return true;
};