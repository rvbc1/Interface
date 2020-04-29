#include "Interface1_manager.h"
#define SPECIAL_BUTTON 224
//#define BUTTON_1 75 // left
//#define BUTTON_2 77 //right
//#define BUTTON_3 80 // down
#define PRINT_PARAMETER 1
#define ERROR 0
Interface1_manager::Interface1_manager(){

    Ssd_1306 = new Interface1 ;
    while(true){
        if( readKey() == SPECIAL_BUTTON){
            print(Ssd_1306->get_Button( readKey() ) );
        }
    }
}

int Interface1_manager::readKey(){
    if(kbhit()){
        switch(getch())
        {
            case SPECIAL_BUTTON:
                return SPECIAL_BUTTON ;
            case BUTTON_1:
                return Interface_Button::LEFT_BUTTON;
            case BUTTON_2:
                return Interface_Button::LEFT;
            case BUTTON_3:

                return BUTTON_3 ;
            break;
        }
    }
}

void Interface1_manager::print(int info) {

    if( info == PRINT_PARAMETER){
        Ssd_1306->display() ;
    }
    else if( info == ERROR ){
        Ssd_1306->display_Error() ;
    }
}
