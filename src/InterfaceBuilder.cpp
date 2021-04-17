#include "InterfaceBuilder.h"

MenuItemsList* InterfaceBuilder::loadInterFaceFromJsonFile(std::string filepath) {
    StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
    std::ifstream interfaceJsonFile(filepath);

    DeserializationError error = deserializeJson(doc, interfaceJsonFile);
    if (error) {
        std::cout << filepath;
        std::cout << " Json deserialize failed: ";
        std::cout << error << std::endl;
    } else {
        if ((doc.containsKey(MAIN_MENU_OBJECT_NAME)) && (doc[MAIN_MENU_OBJECT_NAME].is<JsonObject>())) {
            JsonObject mainMenuJsonObject = doc[MAIN_MENU_OBJECT_NAME].as<JsonObject>();
            MenuItemsList* mainMenu = new MenuItemsList(mainMenuJsonObject["name"].as<std::string>());

            loadMenuItemsListFromJsonArray(mainMenu, mainMenuJsonObject[MENU_ITEMS_LIST_KEY].as<JsonArray>());
            return mainMenu;
        }
    }
    return nullptr;
}

void InterfaceBuilder::loadMenuItemsListFromJsonArray(MenuItemsList* parent, JsonArray array) {
    for (JsonVariant v : array) {
        if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_PARAMETER) {
            Parameter* parameter = new Parameter(v[MENU_ITEM_NAME_KEY].as<std::string>());
            parameter->setValue(v[VALUE_KEY].as<int>());
            if (v.containsKey(MIN_VALUE_KEY)) {
                parameter->setMinValue(v[MIN_VALUE_KEY].as<PARAMETER_VALUE_TYPE>());
            }
            if (v.containsKey(MAX_VALUE_KEY)) {
                parameter->setMaxValue(v[MAX_VALUE_KEY].as<PARAMETER_VALUE_TYPE>());
            }
            if (v.containsKey(VALUE_UNIT_KEY)) {
                parameter->setUnit(v[VALUE_UNIT_KEY].as<std::string>());
            }
            parent->addItemToList(parameter);

        } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_VALUE) {
            Value* value = new Value(v[MENU_ITEM_NAME_KEY].as<std::string>());
            value->setValue(v[VALUE_KEY].as<int>());
            if (v.containsKey(VALUE_UNIT_KEY)) {
                value->setUnit(v[VALUE_UNIT_KEY].as<std::string>());
            }
            parent->addItemToList(value);

        } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_SWITCH) {
            Switch* switchM = new Switch(v[MENU_ITEM_NAME_KEY].as<std::string>());
            switchM->setValue(v["value"].as<uint8_t>());
            parent->addItemToList(switchM);

        } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_ACTION) {
            parent->addItemToList(new Action(v[MENU_ITEM_NAME_KEY].as<std::string>()));

        } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_MENU_ITEMS_LIST) {
            MenuItemsList* menuItemsList = new MenuItemsList(v[MENU_ITEM_NAME_KEY].as<std::string>());
            loadMenuItemsListFromJsonArray(menuItemsList, v[MENU_ITEMS_LIST_KEY].as<JsonArray>());
            parent->addItemToList(menuItemsList);
        }
    }
}

MenuItemsList* InterfaceBuilder::loadDefaultInterFace() {
    MenuItemsList* mainMenu = new MenuItemsList("Main Menu");

    mainMenu->addItemToList(new Parameter("U battery"));
    mainMenu->addItemToList(new Parameter("Work time"));
    mainMenu->addItemToList(new Parameter("Distance"));
    mainMenu->addItemToList(new Parameter("En consumed"));
    mainMenu->addItemToList(new Parameter("Temperature"));

    MenuItemsList* pid = new MenuItemsList("pid");
    pid->addItemToList(new Parameter("P"));
    pid->addItemToList(new Parameter("I"));
    pid->addItemToList(new Parameter("D"));

    mainMenu->addItemToList(pid);

    return mainMenu;
}