#include "Parameter.h"

#include "InterfaceDisplayManager.h"

Parameter::Parameter(std::string name) : Value(name) {
    type = MenuItem::PARAMTER;
}

void Parameter::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            decrementValue();
            break;
        case InterfaceInput::RIGHT_BUTTON:
            incrementValue();
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

void Parameter::decrementValue() {
    if (value > minValue) {
        value--;
    }
}

void Parameter::incrementValue() {
    if (value < maxValue) {
        value++;
    }
}


void Parameter::setMinValue(VALUE_TYPE minValue) {
    this->minValue = minValue;
}

void Parameter::setMaxValue(VALUE_TYPE maxValue) {
    this->maxValue = maxValue;
}


void Parameter::display() {
    InterfaceDisplayManager::displayParameter(this);
}


void Parameter::prepareJsonObject(JsonObject jsonObject) {
    jsonObject[MENU_ITEM_NAME_KEY] = name;
    jsonObject[MENU_ITEM_TYPE_KEY] = getTypeString();
    jsonObject[VALUE_KEY] = value;
    jsonObject[MIN_VALUE_KEY] = minValue;
    jsonObject[MAX_VALUE_KEY] = maxValue;
    jsonObject[VALUE_UNIT_KEY] = unit;
}