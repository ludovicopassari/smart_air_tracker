//
// Created by Ludovico Passari on 03/10/24.
//
#include <Arduino.h>
#include "DataStorage.h"
#include "NVSStorage.h"

#include <ConfigurationManager.h>
#include <NVSStorage.h>

DataStorage* dataStorage = new NVSStorage;
ConfigurationManager* configurationManager = new ConfigurationManager(dataStorage);


String op = "read";
DeviceConfig configToRead;
DeviceConfig configToWrite;

void setup() {

    Serial.begin(115200);
    while (!Serial);

    if(op == "write"){
        Serial.println("Write configuration...");
        configToWrite.wifi.ssid = "new_ssid";
        configToWrite.wifi.password = "new_password";
        configurationManager->writeConfiguration(configToWrite);
    } else if(op == "read"){
        Serial.println("Read configuration...");
        configurationManager->readConfiguration(configToRead);
    }

}

void loop() {

  // write your code here
  if (op == "read") {
    Serial.print("SSID : ");
    Serial.println(configToRead.wifi.ssid);
    Serial.print("Password : ");
    Serial.println(configToRead.wifi.password);
  }

  delay(3000);
}