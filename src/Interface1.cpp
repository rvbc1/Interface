#include "Interface1.h"
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3


Interface1::Interface1(){
	battery_voltage = new Parameter("U battery" , 7.4 , "V", 0);
	work_time = new Parameter("Work time" , 2 , "h", 1) ;
	distance = new Parameter("Distance" , 100 , "m", 1 ) ;
	energy_consumed = new Parameter("En consumed" , 3 , "kWh", 0) ;
	temperature = new Parameter("Temperature" , 20 , "C" , 0);

	battery_voltage->right = work_time ;
	work_time->right = distance ;
	distance->right = energy_consumed ;
	energy_consumed->right = temperature ;
	temperature->right = battery_voltage ;

	battery_voltage->left = temperature ;
	temperature->left = energy_consumed ;
	energy_consumed->left = distance ;
	distance->left = work_time ;
	work_time->left = battery_voltage ;

	middle = battery_voltage ;

	middle->send_to_display() ;

}
double Interface1::get_value(){
	double value ;
	cin >> value ;
	return value ;
}

void Interface1::get_button(int button){
	if(button == BUTTON_3)
	{
		if(middle->if_changeable_value)
			middle->change_value(get_value()) ;
		else
			middle->send_error_no_changeable() ;
	}
	else{
		if(button == BUTTON_1)
			middle = middle->left ;
		else if(button == BUTTON_2)
			middle = middle->right ;
		middle->send_to_display();
	}

}

