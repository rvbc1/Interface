#ifndef ACTION_H_
#define ACTION_H_

#include "InterfaceInput.h"
#include "MenuItem.h"
#include "main.h"

class Action : public MenuItem {
   public:
    Action(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void display();

   private:
};

#endif
