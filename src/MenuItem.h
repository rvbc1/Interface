#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <vector>

#include "ArduinoJson-v6.17.3.h"
#include "InterfaceInput.h"
#include "InterfaceJsonKeys.h"
#include "iostream"

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
                MENU_ITEMS_LIST,
                PARAMTER,
                VALUE,
                SWITCH,
                ACTION,
                BACK_EVENT_ITEM };

    Type getType();

    virtual void display();
    virtual void prepareJsonObject(JsonObject jsonObject);

   protected:
    MenuItem* parentMenuItem = nullptr;

    std::string name = "";

    Type type = UNDEFINED;

    void setType(Type type);

    void setAsActiveItem();

   private:
    std::string getTypeString();
};

#endif
