#include "Interface1.h"

#define DO_NOTHING -1
#define ERROR 0
#define PRINT_PARAMETER 1

Interface1::Interface1(){

	list_of_elements = new List();

	list_of_elements->add_Parameter(new Parameter("U battery" , 7.4 , "V", 0 )) ;
	list_of_elements->add_Parameter(new Parameter("Work time" , 2 , "h", 1)) ;
	list_of_elements->add_Parameter(new Parameter("Distance" , 100 , "m", 1)) ;
	list_of_elements->add_Parameter(new Parameter("En consumed" , 3 , "kWh", 0)) ;
	list_of_elements->add_Parameter(new Parameter("Temperature" , 20 , "C" , 0)) ;

    display();
}

int Interface1::get_Button(int button){

	int action = list_of_elements->get_Parameter()->getButton(button);

	switch(action){
        case ERROR:
            return ERROR;
        case BUTTON_1:
            list_of_elements->moveLeft() ;
            return PRINT_PARAMETER;
        case BUTTON_2:
            list_of_elements->moveRight();
            return PRINT_PARAMETER;
        case DO_NOTHING:
            return PRINT_PARAMETER;
	}
}

void Interface1::display(){
    list_of_elements->get_Parameter()->send_To_Display();
}

void Interface1::display_Error(){
    list_of_elements->get_Parameter()->send_Error_No_Changeable() ;
}
