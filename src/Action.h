#ifndef ACTION_H_
#define ACTION_H_

#include "InterfaceInput.h"
#include "Switch.h"
#include "main.h"

class Action : public Switch {
   public:
    Action(std::string name);
    void setInputEvent(InterfaceInput::Button event);
    void setFunction(void (*function)());
    void display();


   private:
    void (*function)() = nullptr;
};

#endif
