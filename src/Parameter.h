#ifndef PARAMETER_H_
#define PARAMETER_H_

#include "InterfaceInput.h"
#include "Value.h"

class Parameter : public Value {
   public:
    Parameter(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setMinValue(VALUE_TYPE minValue);
    void setMaxValue(VALUE_TYPE maxValue);

    void display();
    void prepareJsonObject(JsonObject jsonObject);

   private:
    VALUE_TYPE minValue = INT16_T_MIN;
    VALUE_TYPE maxValue = INT16_T_MAX;

    void decrementValue();
    void incrementValue();
};

#endif
