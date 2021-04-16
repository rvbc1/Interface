#include "InterfaceBuilder.h"

MenuItemsList* InterfaceBuilder::loadInterFaceFromFile(std::string filepath) {
    StaticJsonDocument<2000> doc;
    std::ifstream myfile(filepath);

    DeserializationError error = deserializeJson(doc, myfile);
    if (error) {
        std::cout << filepath;
        std::cout << " Json deserialize failed: ";
        std::cout << error << std::endl;
    } else {
        if ((doc.containsKey("mainMenu")) && (doc["mainMenu"].is<JsonObject>())) {
            JsonObject mainMenuJsonObject = doc["mainMenu"].as<JsonObject>();
            MenuItemsList* mainMenu = new MenuItemsList(mainMenuJsonObject["name"].as<std::string>());

            loadMenuItemsListFromJsonArray(mainMenu, mainMenuJsonObject["menuItemsList"].as<JsonArray>());
            return mainMenu;
        }
    }
    return nullptr;
}

void InterfaceBuilder::loadMenuItemsListFromJsonArray(MenuItemsList* parent, JsonArray array) {
    for (JsonVariant v : array) {
        if (v["type"].as<std::string>() == "parameter") {
            parent->addItemToList(new Parameter(v["name"].as<std::string>()));
        } else if (v["type"].as<std::string>() == "menuItemsList") {
            MenuItemsList* menuItemsList = new MenuItemsList(v["name"].as<std::string>());
            loadMenuItemsListFromJsonArray(menuItemsList, v["menuItemsList"].as<JsonArray>());
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