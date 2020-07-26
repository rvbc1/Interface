#include "Interface_manager.h"
#define BUTTON_1 75 // left
#define BUTTON_2 77 // right
#define BUTTON_3 80 // down
#define SPECIAL_BUTTON 224
#define INTERVAL 0.4

Interface_manager::Interface_manager(){

    Ssd_1306 = new Interface ;

    auto start = chrono::system_clock::now() ;
    chrono::duration<double> elapsed_seconds  ;
    double time ;

    while(true){

        if(kbhit()){
         if( getch() == SPECIAL_BUTTON){
                print(Ssd_1306->getAction( readKey() ) );
            }
        }
        auto end = chrono::system_clock::now() ;
        elapsed_seconds = end - start ;
        if( time < elapsed_seconds.count() + INTERVAL ){ // double fmod( double x, double y );
            time += INTERVAL ;
            Ssd_1306->refresh() ;
        }
    }
}

Interface_Element::Button Interface_manager::readKey(){
    if(kbhit()){
        switch(getch())
        {
            case BUTTON_1:
                return Interface_Element::LEFT_BUTTON;
            case BUTTON_2:
                return Interface_Element::RIGHT_BUTTON;
            case BUTTON_3:
                return Interface_Element::ENTER ;
            break;
        }
    }
}

void Interface_manager::print(Interface_Element::Action info) {

    if( info == Interface_Element::PRINT){
        Ssd_1306->display() ;
    }
    else if( info ==Interface_Element::ERROR_NO_CHANGEABLE){
        Ssd_1306->displayError() ;
    }
}
