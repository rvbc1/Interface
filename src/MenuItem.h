#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <vector>

#include "InterfaceInput.h"
#include "iostream"
#include "main.h"

class MenuItemsList;
class Parameter;
class Value;
class Switch;
class Action;

class MenuItem {
    friend class MenuItemsList;
    friend class Parameter;
    friend class Value;
    friend class Switch;
    friend class Action;

   public:
    MenuItem(std::string name);

    virtual void setInputEvent(InterfaceInput::Button event);

    std::string getName();
    virtual MenuItem* getCurrentMenuItem();
    enum Status { THIS_IS_ACTIVE_ITEM,
                  ACTIVE_IS_SUBLIST_ITEM };
    Status status = THIS_IS_ACTIVE_ITEM;

    enum Type { UNDEFINED,
                SUBMENU,
                PARAMTER,
                VALUE,
                SWITCH,
                ACTION,
                BACK_EVENT_ITEM };

    Type getType();

    virtual void display();
    std::string name = "";
   protected:
    MenuItem* parentMenuItem = nullptr;

    // std::string name = "";

    Type type = UNDEFINED;

    void setType(Type type);

    void setAsActiveItem();
};

#endif
