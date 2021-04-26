#ifndef INTERFACE_MANAGER_H_
#define INTERFACE_MANAGER_H_
#include <iostream>

#include "Interface.h"
#include "InterfaceInput.h"

class InterfaceManager {
   public:
    InterfaceManager();

   private:
    Interface *interfaceLocal = nullptr;
    InterfaceInput::Button readKey();
    void display();
#if defined (_WIN32) || defined (_WIN64 )
    void usleep(__int64 usec);
#endif
};
#endif /* INTERFACEMANAGER_H_ */
