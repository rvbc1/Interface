#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <vector>

#include "InterfaceInput.h"
#include "main.h"

class MenuItem {
   public:
    MenuItem(std::string name);

    virtual void setInputEvent(InterfaceInput::Button event);

    std::string getName();
    virtual MenuItem* getCurrentMenuItem();
    enum Status { THIS_IS_ACTIVE_ITEM,
                  ACTIVE_IS_SUBLIST_ITEM };
    Status status = THIS_IS_ACTIVE_ITEM;

   //protected:
    enum Type { UNDEFINED,
                SUBMENU,
                PARAMTER,
                BACK_EVENT_ITEM };

    MenuItem* parentMenuItem = nullptr;

    std::string name = "";

    Type type = UNDEFINED;

    void setType(Type type);

    void setAsActiveItem();

    virtual void display();
};

#endif
