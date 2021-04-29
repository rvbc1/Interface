#include "InterfaceBuilder.h"

MenuItem* InterfaceBuilder::loadInterFaceFromJsonFile(std::string filepath) {
    StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
    std::ifstream interfaceJsonFile(filepath);

    DeserializationError error = deserializeJson(doc, interfaceJsonFile);
    if (error) {
        std::cout << filepath;
        std::cout << " Json deserialize failed: ";
        std::cout << error << std::endl;
    } else {
        return loadMenuItem(doc.as<JsonVariant>());
    }
    return nullptr;
}

void InterfaceBuilder::loadMenuItemsListFromJsonArray(MenuItemsList* parent, JsonArray array) {
    for (JsonVariant v : array) {
        MenuItem* item = loadMenuItem(v);
        if (item != nullptr) {
            parent->addItemToList(item);
        }
    }
}

MenuItem* InterfaceBuilder::loadMenuItem(JsonVariant v) {
    if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_PARAMETER) {
        return new Parameter(v.as<JsonObject>());
    } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_VALUE) {
        return new Value(v.as<JsonObject>());
    } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_SWITCH) {
        return new Switch(v.as<JsonObject>());
    } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_ACTION) {
        Action* action = new Action(v[MENU_ITEM_NAME_KEY].as<std::string>());
        return action;

    } else if (v[MENU_ITEM_TYPE_KEY].as<std::string>() == MENU_ITEM_TYPE_MENU_ITEMS_LIST) {
        MenuItemsList* menuItemsList = new MenuItemsList(v[MENU_ITEM_NAME_KEY].as<std::string>());
        loadMenuItemsListFromJsonArray(menuItemsList, v[MENU_ITEMS_LIST_KEY].as<JsonArray>());
        return menuItemsList;
    }
    return nullptr;
}

MenuItem* InterfaceBuilder::loadDefaultInterFace() {
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

void InterfaceBuilder::saveInterfaceToFile(MenuItem* item, std::string filepath) {
    StaticJsonDocument<JSON_DOCUMENT_SIZE> jsonDocument;
    JsonObject jsonObject = jsonDocument.to<JsonObject>();
    item->prepareJsonObject(jsonObject);

    std::ofstream outputFileStream(filepath, std::ofstream::out);
    // serializeJson(jsonDocument, ofs);
    serializeJsonPretty(jsonDocument, outputFileStream);
    outputFileStream.close();
}