//
// Created by Ludovico Passari on 02/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_CONFIGURATIONMANAGER_H
#define INC_0_1_0_ALPHA_1_CONFIGURATIONMANAGER_H

#include <DataStorage.h>
#include <DataStorage.h>

class ConfigurationManager {
private:
    DataStorage * storage;
public:
    ConfigurationManager(DataStorage* dataStorage);
    bool writeConfiguration(DeviceConfig& config);
    bool readConfiguration(DeviceConfig& config);

};


#endif //INC_0_1_0_ALPHA_1_CONFIGURATIONMANAGER_H
