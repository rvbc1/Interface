#ifndef INTERFACE_BUILDER_H_
#define INTERFACE_BUILDER_H_

#include <fstream>
#include "MenuItemsList.h"
#include "Parameter.h"
#include "Value.h"
#include "ArduinoJson-v6.17.3.h"

#define JSON_DOCUMENT_SIZE 2000

class InterfaceBuilder {
public:
    static MenuItemsList* loadInterFaceFromJsonFile(std::string  filepath);
    static MenuItemsList* loadDefaultInterFace();
    static void loadMenuItemsListFromJsonArray(MenuItemsList* parent, JsonArray array);
};

#endif 