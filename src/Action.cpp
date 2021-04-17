#include "Action.h"

Action::Action(std::string name) : MenuItem(name) {
    type = MenuItem::PARAMTER;
}

void Action::setInputEvent(InterfaceInput::Button event) {
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


void Action::display() {
    // printw("%s\n", name.c_str());
    // //printw("%d %s\n", value, name.c_str());
    // printw("-   %d %s   +%s\n", value, unit.c_str(), " | editing");
}