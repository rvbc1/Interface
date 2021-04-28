#ifndef VALUE_H_
#define VALUE_H_
#include "InterfaceInput.h"
#include "MenuItem.h"

#define VALUE_TYPE  int16_t
#define INT16_T_MIN -32768
#define INT16_T_MAX 32767

class Value : public MenuItem {
   public:
    Value(std::string name);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(VALUE_TYPE value);
    VALUE_TYPE getValue();

    void setUnit(std::string unit);
    std::string getUnit();

    void display();
    void prepareJsonObject(JsonObject jsonObject);

   protected:
    VALUE_TYPE value = 0;
    std::string unit = "";

   private:
};

#endif
