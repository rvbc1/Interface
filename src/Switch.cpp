#include "Switch.h"

#include "InterfaceDisplayManager.h"

Switch::Switch(std::string name) : MenuItem(name) {
    type = MenuItem::SWITCH;
}

void Switch::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            value = false;
            break;
        case InterfaceInput::RIGHT_BUTTON:
            value = true;
            break;
        case InterfaceInput::ENTER_BUTTON:
            if (parentMenuItem != nullptr) {
                parentMenuItem->setAsActiveItem();
            }
            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

void Switch::setValue(uint8_t value) {
    this->value = value;
}

void Switch::display() {
    InterfaceDisplayManager::displaySwitch(this);
}

uint8_t Switch::getValue(){
    return value;
}