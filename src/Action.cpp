#include "Action.h"

Action::Action(std::string name) : MenuItem(name) {
    type = MenuItem::ACTION;
}

void Action::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            value = false;
            break;
        case InterfaceInput::RIGHT_BUTTON:
            value = true;
            break;
        case InterfaceInput::ENTER_BUTTON:
            if ((value) && (function != nullptr)) {
                function();
                value = false;
            }
            if (parentMenuItem != nullptr) {
                parentMenuItem->setAsActiveItem();
            }
            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

void Action::setFunction(void (*function)()) {
    this->function = function;
}

void Action::display() {
#ifdef __linux__
    printw("%s\n", name.c_str());
    if (value) {
        printw(" NO    [YES]   +%s\n", " | editing");
    } else {
        printw("[NO]    YES    +%s\n", " | editing");
    }
#elif defined (_WIN32) || defined (_WIN64 )

#endif
}