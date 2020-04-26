#include "Interface1_manager.h"
#define SPECIAL_BUTTON 224
Interface1_manager::Interface1_manager(){

    Ssd_1306 = new Interface1 ;
    while(true){
        podany_przycisk = getch();
    if(kbhit())
        if( podany_przycisk == SPECIAL_BUTTON)
             Ssd_1306->get_Button(getch()) ;
    }
}
