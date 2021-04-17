#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <vector>

#include "InterfaceInput.h"
#include "MenuItem.h"
#include "MenuItemsList.h"
#include "InterfaceBuilder.h"

#include "ArduinoJson-v6.17.3.h"

#define INTERFACE_FILE "src/Interface.json"

class Interface {
   public:
    Interface();
    void setInputEvent(InterfaceInput::Button event);

    MenuItem *getCurrentMenuItem();

   private:
    MenuItemsList *mainMenu = nullptr;

};

#endif /* INTERFACE_H_ */
