#ifndef PARAMETER_H_
#define PARAMETER_H_


#include "InterfaceInput.h"
#include "MenuItem.h"
#include "main.h"

class Parameter : public MenuItem {
   public:
    Parameter(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(int value);
    void setUnit(std::string unit);

    void display();

    private:
    int value = 0;
    std::string unit = "";
};

#endif
