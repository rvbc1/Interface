#include "Switch.h"

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
    #ifdef __linux__
    printw("%s\n", name.c_str());
    if (value) {
        printw(" OFF    [ON]   +%s\n", " | editing");
    } else {
        printw("[OFF]    ON    +%s\n", " | editing");
    }
#elif defined (_WIN32) || defined (_WIN64 )
    std::cout << name << std::endl;
    if (value) {
        std::cout << " OFF    [ON]   + | editing" << std::endl;
    }
    else {
        std::cout << "[OFF]    ON    + | editing" << std::endl;
    }
    #endif
}