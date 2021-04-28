#include "Interface.h"

Interface::Interface() {
    mainMenuItem = InterfaceBuilder::loadInterFaceFromJsonFile(INTERFACE_FILE);
    if (mainMenuItem == nullptr) {
        mainMenuItem = InterfaceBuilder::loadDefaultInterFace();
    }
}

void Interface::setInputEvent(InterfaceInput::Button event) {
    mainMenuItem->getCurrentMenuItem()->setInputEvent(event);
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenuItem->getCurrentMenuItem();
}

MenuItem* Interface::getMenuItemByName(std::string name) {
    return mainMenuItem->getMenuItemByName(name);
}

Action* Interface::getActionByName(std::string name) {
    return (Action*)mainMenuItem->getMenuItemByName(name, MenuItem::ACTION);
}

void Interface::save(std::string filepath) {
    InterfaceBuilder::saveInterfaceToFile(mainMenuItem, filepath);
}
