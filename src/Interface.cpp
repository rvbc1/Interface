#include "Interface.h"

#include <ncurses.h>

#include "Parameter.h"
Interface::Interface() {
    prepareInterfaceFromFile();
    // mainMenu = new MenuItemsList("Main Menu");

    // mainMenu->addItemToList(new Parameter("U battery"));
    // mainMenu->addItemToList(new Parameter("Work time"));
    // mainMenu->addItemToList(new Parameter("Distance"));
    // mainMenu->addItemToList(new Parameter("En consumed"));
    // mainMenu->addItemToList(new Parameter("Temperature"));

    // MenuItemsList *pid = new MenuItemsList("pid");
    // pid->addItemToList(new Parameter("P"));
    // pid->addItemToList(new Parameter("I"));
    // pid->addItemToList(new Parameter("D"));

    // mainMenu->addItemToList(pid);

    // list_of_elements = new List();

    // list_of_elements->addParameter(new Parameter("U battery" , 7.4 , "V", 0 )) ;
    // list_of_elements->addParameter(new Parameter("Work time" , 2 , "h", 1)) ;
    // list_of_elements->addParameter(new Parameter("Distance" , 100 , "m", 1)) ;
    // list_of_elements->addParameter(new Parameter("En consumed" , 3 , "kWh", 0)) ;
    // list_of_elements->addParameter(new Parameter("Temperature" , 20 , "C" , 0)) ;

    // Parameter *pid = new Parameter("pid", 3, "P I D", 0);
    // pid->addToSubList(new Parameter("P" , 20 , "kp" , 1));
    // pid->addToSubList(new Parameter("I" , 20 , "ki" , 1));
    // pid->addToSubList(new Parameter("D" , 20 , "kd" , 1));
    // list_of_elements->addParameter(pid);
}

void Interface::prepareInterfaceFromFile() {
    StaticJsonDocument<2000> doc;
    std::ifstream myfile(INTERFACE_FILE);

    DeserializationError error = deserializeJson(doc, myfile);
    if (error) {
        std::cout << INTERFACE_FILE;
        std::cout << " Json deserialize failed: ";
        std::cout << error.c_str() << std::endl;
    } else {
        if ((doc.containsKey("mainMenu")) && (doc["mainMenu"].is<JsonObject>())) {
            JsonObject mainMenuJsonObject = doc["mainMenu"].as<JsonObject>();
            mainMenu = new MenuItemsList(mainMenuJsonObject["name"].as<std::string>());

            // JsonArray mainMenuJsonArray = mainMenuJsonObject["menuItemsList"].as<JsonArray>();
            // for (JsonVariant v : mainMenuJsonArray) {

            //     mainMenu->addItemToList(new Parameter(v["name"].as<std::string>()));
            // }

            loadMenuItemsList(mainMenu, mainMenuJsonObject["menuItemsList"].as<JsonArray>());
        }
    }
}

void Interface::loadMenuItemsList(MenuItemsList* parent, JsonArray array) {
    for (JsonVariant v : array) {
        if (v["type"].as<std::string>() == "parameter") {
            parent->addItemToList(new Parameter(v["name"].as<std::string>()));
        } else if (v["type"].as<std::string>() == "menuItemsList"){
            MenuItemsList *menuItemsList = new MenuItemsList(v["name"].as<std::string>());
            loadMenuItemsList(menuItemsList, v["menuItemsList"].as<JsonArray>());
            parent->addItemToList(menuItemsList);
        }
    }
}

void Interface::setInputEvent(InterfaceInput::Button event) {
    mainMenu->getCurrentMenuItem()->setInputEvent(event);
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenu->getCurrentMenuItem();
}
