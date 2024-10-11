//
// Created by Ludovico Passari on 02/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_DEVICECONFIG_H
#define INC_0_1_0_ALPHA_1_DEVICECONFIG_H

#include <Arduino.h>

struct WiFiConfig {
  String ssid;
  String password;
};

struct MQTTConfig {
  String host;
  unsigned int port;
  String client_id;
  String username;
  String password;
  //int keep_alive;
  unsigned int qos;
  //bool clean_session;
};

struct User {
  String id;
  String username;
};
/*
struct Sensor {
    const char* id;
    const char* type;
    const char* model;
    const char* unit;
    float min_value;
    float max_value;
    float accuracy;
    int sampling_rate;
};*/

struct DeviceConfig {
  String device_id;
  String device_name;
  String location;
  WiFiConfig wifi;
  MQTTConfig mqtt;
  User user;
  //Sensor sensors[3]; // Array di sensori
};

#endif //INC_0_1_0_ALPHA_1_DEVICECONFIG_H
