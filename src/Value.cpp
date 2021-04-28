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

void Value::setValue(VALUE_TYPE value) {
    this->value = value;
}

VALUE_TYPE Value::getValue(){
    return value;
}

void Value::setUnit(std::string unit) {
    this->unit = unit;
}

std::string Value::getUnit() {
    return unit;
}

void Value::display() {
    InterfaceDisplayManager::displayValue(this);
}

void Value::prepareJsonObject(JsonObject jsonObject) {
    jsonObject[MENU_ITEM_NAME_KEY] = name;
    jsonObject[MENU_ITEM_TYPE_KEY] = getTypeString();
    jsonObject[VALUE_KEY] = value;
    jsonObject[VALUE_UNIT_KEY] = unit;
}