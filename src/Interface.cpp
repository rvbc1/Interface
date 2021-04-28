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
    // for (MenuItem* item : mainMenu->subMenuItems) {
    //     if (item->getName() == name) {
    //         return item;
    //     }
    // }
    return nullptr;
}

Action* Interface::getActionByName(std::string name) {
    // for (MenuItem* item : mainMenu->subMenuItems) {
    //     if ((item->getName() == name) && (item->getType() == MenuItem::ACTION)) {
    //         return (Action*)item;
    //     }
    // }
    return nullptr;
}

void Interface::save(std::string filepath) {
    InterfaceBuilder::saveInterfaceToFile(mainMenuItem, filepath);
}
