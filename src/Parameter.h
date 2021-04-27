#ifndef PARAMETER_H_
#define PARAMETER_H_

#include "InterfaceInput.h"
#include "MenuItem.h"

#define PARAMETER_VALUE_TYPE int16_t
#define INT16_T_MIN          -32768
#define INT16_T_MAX          32767

class Parameter : public MenuItem {
   public:
    Parameter(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(PARAMETER_VALUE_TYPE value);
    void setMinValue(PARAMETER_VALUE_TYPE minValue);
    void setMaxValue(PARAMETER_VALUE_TYPE maxValue);
    void setUnit(std::string unit);

    void display();

    PARAMETER_VALUE_TYPE getValue();
    std::string getUnit();

   private:
    PARAMETER_VALUE_TYPE value = 0;
    PARAMETER_VALUE_TYPE minValue = INT16_T_MIN;
    PARAMETER_VALUE_TYPE maxValue = INT16_T_MAX;
    std::string unit = "";

    void decrementValue();
    void incrementValue();
};

#endif
