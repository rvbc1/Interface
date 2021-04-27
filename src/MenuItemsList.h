#ifndef MENU_ITEMS_LIST_H_
#define MENU_ITEMS_LIST_H_

#include <vector>

#include "InterfaceInput.h"
#include "MenuItem.h"

class Interface;

class MenuItemsList : public MenuItem {
    friend class Interface;

   public:
    MenuItemsList(std::string name);

    void addItemToList(MenuItem* menuItem);
    void setInputEvent(InterfaceInput::Button event);

    MenuItem* getCurrentMenuItem();
    MenuItem* getSelectedMenuItem();
    void display();

   private:
    std::vector<MenuItem*> subMenuItems;

    void moveLeft();
    void moveRight();

    

    uint16_t currentMainMenuItem = 0;
};

#endif
