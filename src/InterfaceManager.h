#ifndef INTERFACE_MANAGER_H_
#define INTERFACE_MANAGER_H_

#include <iostream>

#include "Interface.h"
#include "InterfaceInput.h"

class InterfaceManager {
   public:
    InterfaceManager();
        static void saveInterface();

   private:
    static Interface *interface;
    InterfaceInput::Button readKey();
    void display();
};
#endif /* INTERFACEMANAGER_H_ */
