#include "Interface.h"

#include <ncurses.h>
Interface::Interface() {
    mainMenu = new MenuItem("Main Menu");
    // mainMenuItems.push_back(MenuItem("Test1"));
    // mainMenuItems.push_back(MenuItem("Test2"));
    // mainMenuItems.push_back(MenuItem("Test3"));
    // mainMenuItems.push_back(MenuItem("Test4"));
    // mainMenuItems.push_back(MenuItem("Test5"));

    MenuItem* submenu = new MenuItem("Submenu 1");
    submenu->addItemToSubMenu(new MenuItem("SM1"));
    submenu->addItemToSubMenu(new MenuItem("SM2"));
    submenu->addItemToSubMenu(new MenuItem("SM3"));
    submenu->addItemToSubMenu(new MenuItem("SM4"));
    
    mainMenu->addItemToSubMenu(submenu);
    
    mainMenu->addItemToSubMenu(new MenuItem("Test2"));
    mainMenu->addItemToSubMenu(new MenuItem("Test3"));
    mainMenu->addItemToSubMenu(new MenuItem("Test4"));
    mainMenu->addItemToSubMenu(new MenuItem("Test5"));

    printw("%d",mainMenu->subMenuItems.size());
    printw("%s",mainMenu->subMenuItems[1]->name.c_str());
    mainMenu->currentMainMenuItem = 2;
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
    if(mainMenu->status == MenuItem::DISPLAYING_SUBMENU_ITEM){
        //printw("%s",mainMenu->getCurrentMenuItem()->name.c_str());
        mainMenu->getCurrentMenuItem()->setInputEvent(event);
    } else {
        mainMenu->setInputEvent(event);
    }
}

MenuItem* Interface::getCurrentMenuItem() {
    return mainMenu->getSubMenuCurrentItem();
}

