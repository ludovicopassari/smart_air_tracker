//
// Created by Ludovico Passari on 02/10/24.
//

#ifndef INC_0_1_0_ALPHA_1_APPLICATION_H
#define INC_0_1_0_ALPHA_1_APPLICATION_H

#include "DataStorage.h"

class Application {

private:
  DataStorage *storage;
public:
  void setup();

  void run();
};


#endif //INC_0_1_0_ALPHA_1_APPLICATION_H
