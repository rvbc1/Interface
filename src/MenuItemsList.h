#ifndef MENU_ITEMS_LIST_H_
#define MENU_ITEMS_LIST_H_

#include <vector>

#include "InterfaceInput.h"
#include "MenuItem.h"
#include "main.h"

class MenuItemsList : public MenuItem {
   public:
    MenuItemsList(std::string name);

    void addItemToList(MenuItem* menuItem);
    void setInputEvent(InterfaceInput::Button event);

    MenuItem* getCurrentMenuItem();
    void display();

   private:
    std::vector<MenuItem*> subMenuItems;

    void moveLeft();
    void moveRight();

    MenuItem* getSelectedMenuItem();

    uint16_t currentMainMenuItem = 0;
};

#endif
