#include "Parameter.h"

#include <ncurses.h>

Parameter::Parameter(std::string name) : MenuItem(name) {
    type = MenuItem::PARAMTER;
}

void Parameter::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            value--;
            break;
        case InterfaceInput::RIGHT_BUTTON:
            value++;
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

void Parameter::setValue(int value){
    this->value = value;
}

void Parameter::display() {
    printw("%s\n", name.c_str());
    //printw("%d %s\n", value, name.c_str());
    printw("-   %d   +%s\n", value, " | editing");
}