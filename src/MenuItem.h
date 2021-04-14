#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <vector>

#include "InterfaceInput.h"
#include "main.h"

class MenuItem {
   public:
    MenuItem(std::string name);

    void addItemToSubMenu(MenuItem* menuItem);
    void setInputEvent(InterfaceInput::Button event);

    std::string getName();
    MenuItem* getCurrentMenuItem();
	    enum Status { THIS_IS_ACTIVE_ITEM,
                  ACTIVE_IS_SUBLIST_ITEM };
	Status status = THIS_IS_ACTIVE_ITEM;
  // private:
    enum Type { UNDEFINED,
                SUBMENU,
                PARAMTER,
                BACK_EVENT_ITEM };

	MenuItem *parentMenuItem = nullptr;

    // enum Status { DISPLAYING_THIS_ITEM,
    //               DISPLAYING_SUBMENU_ITEM };
    std::string name = "";

    Type type = UNDEFINED;
	// Status status = DISPLAYING_THIS_ITEM;

    std::vector<MenuItem *> subMenuItems;

    void moveLeft();
    void moveRight();

    void setType(Type type);

    void setAsActiveItem();
    MenuItem *getSelectedMenuItem(); //LIST PROPERTY

    uint16_t currentMainMenuItem = 0;
};

#endif
