#include "Interface1.h"
#define BUTTON_1 75 // left
#define BUTTON_2 77 //right
#define BUTTON_3 80 // down
#define SPECIAL_BUTTON 224
#define NUMBER_OF_ELEMENTS 5

Interface1::Interface1(){

	list_of_elements = new List();

	battery_voltage = new Parameter("U battery" , 7.4 , "V", 0);
	work_time = new Parameter("Work time" , 2 , "h", 1) ;
	distance = new Parameter("Distance" , 100 , "m", 1 ) ;
	energy_consumed = new Parameter("En consumed" , 3 , "kWh", 0) ;
	temperature = new Parameter("Temperature" , 20 , "C" , 0);

	list_of_elements->add_Parameter(battery_voltage) ;
	list_of_elements->add_Parameter(work_time) ;
	list_of_elements->add_Parameter(distance) ;
	list_of_elements->add_Parameter(energy_consumed) ;
	list_of_elements->add_Parameter(temperature) ;


	list_of_elements->print();


    actual_index = 1;

  //  ( list_of_elements->get_Parameter(actual_index) )->send_To_Display() ;

}

void Interface1::get_Value(){

    int wczytany_znak = getch() ;

    if( kbhit())
    {
        while(wczytany_znak != BUTTON_3)
        {
            wczytany_znak = getch();
            ( list_of_elements->get_Parameter(actual_index) )->change_Value(wczytany_znak) ;
        }
    }

}

void Interface1::get_Button(int button){
/*
	if(button == BUTTON_3)
	{
		if(( list_of_elements->get_Parameter(actual_index) )->if_changeable_value)
            get_Value() ;
		else
			( list_of_elements->get_Parameter(actual_index) )->send_Error_No_Changeable() ;
	}
	else{
		if(button == BUTTON_1){
            actual_index-- ;
            if(actual_index <=0) actual_index=NUMBER_OF_ELEMENTS ;
		}
		else if(button == BUTTON_2)
        {actual_index=(actual_index++)%(NUMBER_OF_ELEMENTS + 1 ) ;

        }


    ( list_of_elements->get_Parameter(actual_index) )->send_To_Display() ;

	}
	*/
}

