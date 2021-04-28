#include "MenuItemsList.h"

#include "InterfaceDisplayManager.h"

MenuItemsList::MenuItemsList(std::string name) : MenuItem(name) {
    this->type = MENU_ITEMS_LIST;

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
                case MENU_ITEMS_LIST:
                case VALUE:
                case SWITCH:
                case ACTION:
                    getSelectedMenuItem()->setAsActiveItem();
                    break;
                case BACK_EVENT_ITEM:
                    if (parentMenuItem != nullptr) {
                        parentMenuItem->setAsActiveItem();
                    }
                    break;

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
    InterfaceDisplayManager::displayMenuItemList(this);
}

void MenuItemsList::prepareJsonObject(JsonObject jsonObject) {
    jsonObject[MENU_ITEM_NAME_KEY] = name;
    jsonObject[MENU_ITEM_TYPE_KEY] = getTypeString();
    JsonArray jsonArray = jsonObject.createNestedArray("menuItemsList");
    for (MenuItem* item : subMenuItems) {
        if (item->getType() != BACK_EVENT_ITEM) {
            item->prepareJsonObject(jsonArray.createNestedObject());
        }
    }
}
