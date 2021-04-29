#ifndef SWITCH_H_
#define SWITCH_H_

#include "InterfaceInput.h"
#include "MenuItem.h"

#define DEFAULT_SWITCH_NAME "Switch"

class Switch : public MenuItem {
   public:
    Switch(std::string name = DEFAULT_SWITCH_NAME);
    Switch(JsonObject jsonObject);
    void setInputEvent(InterfaceInput::Button event);

    void setValue(uint8_t value);

    void display();

    uint8_t getValue();

    void prepareJsonObject(JsonObject jsonObject);

   protected:
    void parseSwitchFromJsonObject(JsonObject jsonObject);

    uint8_t value = 0;
};

#endif
