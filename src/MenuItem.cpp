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
        menuItem->parentMenuItem = this;
        subMenuItems.push_back(menuItem);
    } else if (type == SUBMENU) {
        menuItem->parentMenuItem = this;
        subMenuItems.push_back(menuItem);
    } else {
        //TRYING ADD ELEMENT TO RESERVED MENU ITEM
    }
}

void MenuItem::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            // if (parentMenuItem != nullptr) {
            //     //printw("left");
            //     parentMenuItem->moveLeft();
            // } else {
            //     printw("no parent");
            // }
            moveLeft();
            break;
        case InterfaceInput::RIGHT_BUTTON:
            // if (parentMenuItem != nullptr) {
            //     parentMenuItem->moveRight();
            // }
            moveRight();
            // if (parentMenuItem != nullptr) {
            //     //printw("right");
            //     parentMenuItem->moveRight();
            // } else {
            //     printw("no parent");
            // }
            break;
        case InterfaceInput::ENTER_BUTTON:
            switch (getSelectedMenuItem()->type) {  //ALWAYS SET AS ACTIVE SELECTED ITEM
                case SUBMENU:
                    getSelectedMenuItem()->setAsActiveItem();
                    break;
                case BACK_EVENT_ITEM:
                    if (parentMenuItem != nullptr) {
                        parentMenuItem->setAsActiveItem();
                    }
                    break;
                case PARAMTER:
                case UNDEFINED:
                    break;
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
    // if (status == DISPLAYING_SUBMENU_ITEM) {
    //     printw("return submenu ");
    //     return subMenuItems[currentMainMenuItem];
    // }
    // return this;
    if (status == ACTIVE_IS_SUBLIST_ITEM) {
        return subMenuItems[currentMainMenuItem]->getCurrentMenuItem();
    }
    return this;
}

void MenuItem::setType(MenuItem::Type type) {
    this->type = type;
}

void MenuItem::setAsActiveItem() {
    if (parentMenuItem != nullptr) {
        parentMenuItem->status = ACTIVE_IS_SUBLIST_ITEM;
    }
    status = THIS_IS_ACTIVE_ITEM;
    // status = ACTIVE_IS_SUBLIST_ITEM;
}

MenuItem* MenuItem::getSelectedMenuItem() {
    return subMenuItems[currentMainMenuItem];
}