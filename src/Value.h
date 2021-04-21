#ifndef VALUE_H_
#define VALUE_H_
#include "InterfaceInput.h"
#include "MenuItem.h"

class Value : public MenuItem {
   public:
    Value(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(int value);
    void setUnit(std::string unit);

    void display();

    private:
    int value = 0;
    std::string unit = "";
};

#endif
