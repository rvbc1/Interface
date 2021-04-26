#include "MenuItem.h"

MenuItem::MenuItem(std::string name) {
    this->name = name;
}

std::string MenuItem::getName() {
    return name;
}

void MenuItem::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            break;
        case InterfaceInput::RIGHT_BUTTON:
            break;
        case InterfaceInput::ENTER_BUTTON:
            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

MenuItem* MenuItem::getCurrentMenuItem() {
    return this;
}

void MenuItem::setType(MenuItem::Type type) {
    this->type = type;
}

MenuItem::Type MenuItem::getType(){
    return type;
}

void MenuItem::setAsActiveItem() {
    if (parentMenuItem != nullptr) {
        parentMenuItem->status = ACTIVE_IS_SUBLIST_ITEM;
    }
    status = THIS_IS_ACTIVE_ITEM;
}

void MenuItem::display(){
    #ifdef __linux__
    printw("displaing MenuItem %s\n", name.c_str());
    #elif defined (_WIN32) || defined (_WIN64 )
    std::cout << "displaing MenuItem";
    #endif
}
