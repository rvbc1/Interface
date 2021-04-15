#include "Interface.h"

#include "Parameter.h"

#include <ncurses.h>
Interface::Interface() {
    mainMenu = new MenuItemsList("Main Menu");

    MenuItemsList* submenu = new MenuItemsList("Submenu 1");
    submenu->addItemToList(new Parameter("SM1"));
    MenuItemsList* submenu2 = new MenuItemsList("Submenu 2");
    submenu->addItemToList(submenu2);
    submenu->addItemToList(new MenuItem("SM3"));
    submenu->addItemToList(new MenuItem("SM4"));

    submenu2->addItemToList(new MenuItem("RX1"));
    submenu2->addItemToList(new MenuItem("RX2"));
    
    mainMenu->addItemToList(submenu);
    
    mainMenu->addItemToList(new MenuItem("Test2"));
    mainMenu->addItemToList(new MenuItem("Test3"));
    mainMenu->addItemToList(new MenuItem("Test4"));
    mainMenu->addItemToList(new MenuItem("Test5"));


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

void Interface::setInputEvent(InterfaceInput::Button event) {
    mainMenu->getCurrentMenuItem()->setInputEvent(event);
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenu->getCurrentMenuItem();
}

