#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <vector>

#include "InterfaceInput.h"
#include "MenuItem.h"

class Interface {
   public:
    Interface();
    void setInputEvent(InterfaceInput::Button event);

    MenuItem *getCurrentMenuItem();

   private:
    MenuItem *mainMenu = nullptr;
};

#endif /* INTERFACE_H_ */
