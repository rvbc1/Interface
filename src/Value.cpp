#include "Value.h"

#include "InterfaceDisplayManager.h"

Value::Value(std::string name) : MenuItem(name) {
    type = MenuItem::VALUE;
}

void Value::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            break;
        case InterfaceInput::RIGHT_BUTTON:
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

void Value::setValue(int value) {
    this->value = value;
}

void Value::setUnit(std::string unit) {
    this->unit = unit;
}

void Value::display() {
    InterfaceDisplayManager::displayValue(this);
}