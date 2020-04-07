#include "Interface1.h"
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define MAX_POSITION 4


struct Interface1::parameter {
	parameter *nastepny ;
	parameter *poprzedni ;
	string headline;
	int value ;
	string unit;
};

Interface1::Interface1() {

	parameter *battery_voltage = new parameter;
	battery_voltage->headline = "Battery voltage";
	battery_voltage->value = 7.4 ;
	battery_voltage->unit = "V" ;
	first = battery_voltage ;


	parameter *work_time = new parameter;
	work_time->headline = "Work time";
	work_time->value = 2 ;
	work_time->unit = "h" ;

	work_time->poprzedni = battery_voltage;
	battery_voltage->nastepny = work_time ;

	parameter *distance = new parameter;
	distance->headline = "Distance";
	distance->value = 300 ;
	distance->unit = "m" ;

	distance->poprzedni = work_time;
	work_time->nastepny = distance;

	parameter *energy_consumed = new parameter;
	energy_consumed->headline = "Energy consumed";
	energy_consumed->value = 3 ;
	energy_consumed->unit = "kWh" ;

	energy_consumed->poprzedni = distance ;
	distance->nastepny = energy_consumed ;

	parameter *temperature = new parameter;
	temperature->headline = "Temperture";
	temperature->value = 20 ;
	temperature->unit = "C" ;

	temperature->poprzedni = energy_consumed ;
	energy_consumed->nastepny = temperature ;
	temperature->nastepny = battery_voltage ;
	battery_voltage->poprzedni = temperature ;

	//poczatkowy stan - napiecie baterii (srodkowe)
	left_parameter = temperature;
	middle_parameter = battery_voltage;
	right_parameter = work_time;

	send_to_display(middle_parameter) ;
}

void Interface1::which_button(int button_w){
	if( button_w == BUTTON_1){ //lewo
		send_to_display(left_parameter) ;
		right_parameter = middle_parameter ;
		middle_parameter = left_parameter ;
		left_parameter = left_parameter->poprzedni ;
	}
	else if( button_w == BUTTON_2){ //prawo
		send_to_display(right_parameter) ;
		left_parameter = middle_parameter ;
		middle_parameter = right_parameter ;
		right_parameter = right_parameter->nastepny ;
	}
}

void Interface1::send_to_display(parameter *temp) { //przesylanie danych do wyswietlenia tylko
	cout << endl;
	cout << temp->headline << ":" << endl;
	cout << temp->value <<" [" << temp->unit << "]" << endl;
}

