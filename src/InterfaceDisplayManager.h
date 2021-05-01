#ifndef INTERFACE_DISPLAY_MANAGER_H_
#define INTERFACE_DISPLAY_MANAGER_H_

#include <iomanip>
#include <iostream>
#include <sstream>

#include "Interface.h"

class InterfaceDisplayManager {
   public:
    static void displayManuItem(MenuItem *item);
   private:
    static void displayMenuItemList(MenuItemsList* item);
    static void displayParameter(Parameter* item);
    static void displayAction(Action* item);
    static void displaySwitch(Switch* item);
    static void displayValue(Value* item);
    static void showItem(std::string itemText);
};
#endif
