#include "MenuItem.h"

#include <ncurses.h>

MenuItem::MenuItem(std::string name) {
    this->name = name;
}

std::string MenuItem::getName() {
    return name;
}

void MenuItem::addItemToSubMenu(MenuItem* menuItem) {
    if (type == UNDEFINED) {
        type = SUBMENU;
        MenuItem* backItem = new MenuItem("Back");
        backItem->setType(BACK_EVENT_ITEM);
        backItem->parentMenuItem = this;
        subMenuItems.push_back(backItem);
        subMenuItems.push_back(menuItem);
        menuItem->parentMenuItem = this;
    } else if (type == SUBMENU) {
        subMenuItems.push_back(menuItem);
        menuItem->parentMenuItem = this;
    } else {
        //TRYING ADD ELEMENT TO RESERVED MENU ITEM
    }
}

void MenuItem::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            if (parentMenuItem != nullptr) {
                parentMenuItem->moveLeft();
            }
            break;
        case InterfaceInput::RIGHT_BUTTON:
            if (parentMenuItem != nullptr) {
                parentMenuItem->moveRight();
            }
            break;
        case InterfaceInput::ENTER_BUTTON:
            if (status == DISPLAYING_THIS_ITEM) {
                if (type == SUBMENU) {
                    printw("set subemnu");
                    status = DISPLAYING_SUBMENU_ITEM;
                }
            }
            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

void MenuItem::moveLeft() {
    if (subMenuItems.size() > 0) {
        if (currentMainMenuItem > 0) {
            currentMainMenuItem--;
        } else {
            currentMainMenuItem = subMenuItems.size() - 1;
        }
    }
}

void MenuItem::moveRight() {
    if (subMenuItems.size() > 0) {
        if (currentMainMenuItem < (subMenuItems.size() - 1)) {
            currentMainMenuItem++;
        } else {
            currentMainMenuItem = 0;
        }
    }
}

MenuItem* MenuItem::getCurrentMenuItem() {
    if (status == DISPLAYING_SUBMENU_ITEM) {
        printw("return submenu ");
        return subMenuItems[currentMainMenuItem];
    }
    return this;
}

void MenuItem::setType(MenuItem::Type type) {
    this->type = type;
}