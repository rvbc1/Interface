#include "Parameter.h"

#include "InterfaceDisplayManager.h"

Parameter::Parameter(std::string name) : Value(name) {
    type = MenuItem::PARAMTER;
}

Parameter::Parameter(JsonObject jsonObject) : Value(DEFAULT_PARAMETER_NAME){
    type = MenuItem::PARAMTER;
    parseParameterFromJsonObject(jsonObject);
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
    value -= valueChange;
    if (value < minValue) {
        value = minValue;
    }
}

void Parameter::incrementValue() {
    value += valueChange;
    if (value > maxValue) {
        value = maxValue;
    }
}

void Parameter::setMinValue(VALUE_TYPE minValue) {
    this->minValue = minValue;
}

void Parameter::setMaxValue(VALUE_TYPE maxValue) {
    this->maxValue = maxValue;
}

void Parameter::setValueChange(VALUE_TYPE change) {
    valueChange = change;
}

void Parameter::display() {
    InterfaceDisplayManager::displayParameter(this);
}

void Parameter::prepareJsonObject(JsonObject jsonObject) {
    prepareValueJsonObject(jsonObject);
    jsonObject[MIN_VALUE_KEY] = minValue;
    jsonObject[MAX_VALUE_KEY] = maxValue;
    jsonObject[VALUE_CHANGE_KEY] = valueChange;
}

void Parameter::parseParameterFromJsonObject(JsonObject jsonObject) {
    parseValueFromJsonObject(jsonObject);

    if (jsonObject.containsKey(MIN_VALUE_KEY)) {
        setMinValue(jsonObject[MIN_VALUE_KEY].as<VALUE_TYPE>());
    }
    if (jsonObject.containsKey(MAX_VALUE_KEY)) {
        setMaxValue(jsonObject[MAX_VALUE_KEY].as<VALUE_TYPE>());
    }

    if (jsonObject.containsKey(VALUE_CHANGE_KEY)) {
        setValueChange(jsonObject[VALUE_CHANGE_KEY].as<VALUE_TYPE>());
    }
}