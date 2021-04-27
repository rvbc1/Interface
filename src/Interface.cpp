#include "Interface.h"

Interface::Interface() {
    mainMenu = InterfaceBuilder::loadInterFaceFromJsonFile(INTERFACE_FILE);
    if (mainMenu == nullptr) {
        mainMenu = InterfaceBuilder::loadDefaultInterFace();
    }
}

void Interface::setInputEvent(InterfaceInput::Button event) {
    mainMenu->getCurrentMenuItem()->setInputEvent(event);
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenu->getCurrentMenuItem();
}

MenuItem* Interface::getMenuItemByName(std::string name) {
    for (MenuItem* item : mainMenu->subMenuItems) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

Action* Interface::getActionByName(std::string name) {
    for (MenuItem* item : mainMenu->subMenuItems) {
        if ((item->getName() == name) && (item->getType() == MenuItem::ACTION)) {
            return (Action*)item;
        }
    }
    return nullptr;
}

void Interface::save(std::string filepath) {
    StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
    JsonArray array = doc.createNestedArray();
    for (MenuItem* item : mainMenu->subMenuItems) {
        JsonObject jsonObject = array.createNestedObject();
        jsonObject[MENU_ITEM_NAME_KEY] = item->getName();
    }
    std::ofstream ofs(filepath, std::ofstream::out);
    serializeJson(doc, ofs);
    ofs.close();
}
