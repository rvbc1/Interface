#include "Switch.h"

#include <ncurses.h>

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
    printw("%s\n", name.c_str());
    //printw("%d %s\n", value, name.c_str());
    std::string valueString = "OFF";
    if (value) {
        valueString = "ON";
    }
    printw("-   %s   +%s\n", valueString.c_str(), " | editing");
}