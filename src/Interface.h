#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <vector>

#include "ArduinoJson-v6.17.3.h"
#include "InterfaceBuilder.h"
#include "InterfaceInput.h"
#include "MenuItem.h"
#include "MenuItemsList.h"
#include "InterfaceJsonKeys.h"

#define INTERFACE_FILE "Interface.json"

class Interface {
   public:
    Interface();
    void setInputEvent(InterfaceInput::Button event);

    MenuItem *getCurrentMenuItem();

    Action *getActionByName(std::string name);

    void save(std::string filepath);

   private:
    MenuItem *mainMenuItem = nullptr;

    MenuItem *getMenuItemByName(std::string name);
};

#endif /* INTERFACE_H_ */
