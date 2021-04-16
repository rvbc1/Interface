#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <vector>

#include "InterfaceInput.h"
#include "MenuItem.h"
#include "MenuItemsList.h"

#define ARDUINOJSON_ENABLE_STD_STREAM 1
#include <fstream>

#include "ArduinoJson-v6.17.3.h"

#define INTERFACE_FILE "src/Interface.json"

class Interface {
   public:
    Interface();
    void setInputEvent(InterfaceInput::Button event);

    MenuItem *getCurrentMenuItem();

   private:
    MenuItemsList *mainMenu = nullptr;

    void prepareInterfaceFromFile();
    void loadMenuItemsList(MenuItemsList* parent, JsonArray array);
};

#endif /* INTERFACE_H_ */
