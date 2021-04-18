#ifndef INTERFACE_MANAGER_H_
#define INTERFACE_MANAGER_H_
#define _windows_
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
#ifdef _windows_
    void usleep(__int64 usec);
#endif
};
#endif /* INTERFACEMANAGER_H_ */
