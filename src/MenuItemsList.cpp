#include "MenuItemsList.h"

MenuItemsList::MenuItemsList(std::string name) : MenuItem(name) {
    this->type = SUBMENU;

    MenuItem* backItem = new MenuItem("Back");
    backItem->setType(BACK_EVENT_ITEM);
    backItem->parentMenuItem = this;
    backItem->parentMenuItem = this;
    subMenuItems.push_back(backItem);
}

void MenuItemsList::addItemToList(MenuItem* menuItem) {
    menuItem->parentMenuItem = this;
    subMenuItems.push_back(menuItem);
}

void MenuItemsList::setInputEvent(InterfaceInput::Button event) {
    switch (event) {
        case InterfaceInput::LEFT_BUTTON:
            moveLeft();  //AS LIST
            break;
        case InterfaceInput::RIGHT_BUTTON:
            moveRight();  //AS LIST
            break;
        case InterfaceInput::ENTER_BUTTON:
            switch (getSelectedMenuItem()->type) {  //ALWAYS SET AS ACTIVE SELECTED ITEM IN LIST
                case PARAMTER:
                case SUBMENU:
                case VALUE:
                case SWITCH:
                    getSelectedMenuItem()->setAsActiveItem();
                    break;
                case BACK_EVENT_ITEM:
                    if (parentMenuItem != nullptr) {
                        parentMenuItem->setAsActiveItem();
                    }
                    break;
                case ACTION:
                case UNDEFINED:
                    break;
            }

            break;
        case InterfaceInput::OTHER_BUTTON:
            break;
    }
}

void MenuItemsList::moveLeft() {
    if (subMenuItems.size() > 0) {
        if (currentMainMenuItem > 0) {
            currentMainMenuItem--;
        } else {
            currentMainMenuItem = subMenuItems.size() - 1;
        }
    }
}

void MenuItemsList::moveRight() {
    if (subMenuItems.size() > 0) {
        if (currentMainMenuItem < (subMenuItems.size() - 1)) {
            currentMainMenuItem++;
        } else {
            currentMainMenuItem = 0;
        }
    }
}

MenuItem* MenuItemsList::getCurrentMenuItem() {
    if (status == ACTIVE_IS_SUBLIST_ITEM) {
        return subMenuItems[currentMainMenuItem]->getCurrentMenuItem();
    }
    return this;
}

MenuItem* MenuItemsList::getSelectedMenuItem() {
    return subMenuItems[currentMainMenuItem];
}

void MenuItemsList::display() {
    printw("%s\n  > %s\n", getName().c_str(), subMenuItems[currentMainMenuItem]->getName().c_str());
    // if (subMenuItems[currentMainMenuItem]->type == MenuItem::BACK_EVENT_ITEM) {
    //     printw("BACK ITEM\n");
    // }
}
