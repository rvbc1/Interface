#ifndef INTERFACE_DISPLAY_MANAGER_H_
#define INTERFACE_DISPLAY_MANAGER_H_

#include "Interface.h"

class InterfaceDisplayManager {
   public:
    static void displayMenuItemList(MenuItemsList* item);
    static void displayParameter(Parameter* item);
    static void displayAction(Action* item);
    static void displaySwitch(Switch* item);
    static void displayValue(Value* item);
};
#endif 