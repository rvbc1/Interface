#include "Interface1.h"
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3

struct Interface1::parameter {
	parameter *nastepny ;
	parameter *poprzedni ;
	string headline;
	uint16_t value ;
	string unit;
	bool changealbe_value ;
};

Interface1::Interface1() {

	parameter *battery_voltage = new parameter;
	battery_voltage->headline = "U battery";
	battery_voltage->value = 7.4 ;
	battery_voltage->unit = "V" ;
	battery_voltage->changealbe_value = 0 ;

	parameter *work_time = new parameter;
	work_time->headline = "Work time";
	work_time->value = 2 ;
	work_time->unit = "h" ;
	work_time->changealbe_value = 1 ;

	work_time->poprzedni = battery_voltage;
	battery_voltage->nastepny = work_time ;

	parameter *distance = new parameter;
	distance->headline = "Distance";
	distance->value = 300 ;
	distance->unit = "m" ;
	distance->changealbe_value = 1;

	distance->poprzedni = work_time;
	work_time->nastepny = distance;

	parameter *energy_consumed = new parameter;
	energy_consumed->headline = "En consumed";
	energy_consumed->value = 3 ;
	energy_consumed->unit = "kWh" ;
	energy_consumed->changealbe_value = 0 ;

	energy_consumed->poprzedni = distance ;
	distance->nastepny = energy_consumed ;

	parameter *temperature = new parameter;
	temperature->headline = "Temperture";
	temperature->value = 20 ;
	temperature->unit = "C" ;
	temperature->changealbe_value = 0;

	temperature->poprzedni = energy_consumed ;
	energy_consumed->nastepny = temperature ;
	temperature->nastepny = battery_voltage ;
	battery_voltage->poprzedni = temperature ;

	//poczatkowy stan - napiecie baterii (srodkowe)
	middle_parameter = battery_voltage; // ustawienie pierwszego parametru listy

	send_to_display(middle_parameter) ;
}

void Interface1::which_button(uint16_t button_w){
	if( button_w == BUTTON_1){ //lewo
		middle_parameter = middle_parameter->poprzedni;
		send_to_display(middle_parameter) ;
	}
	else if( button_w == BUTTON_2){ //prawo
		middle_parameter = middle_parameter->nastepny ;
		send_to_display(middle_parameter) ;
	}
	else if( button_w == BUTTON_3){
		if(middle_parameter->changealbe_value){
			change_value(middle_parameter);
		send_to_display(middle_parameter) ;
		}
		else{
			send_error_no_changeable() ;
		}
	}
}

void Interface1::send_to_display(parameter *temp) { //przesylanie danych do wyswietlenia tylko
	cout << endl << endl ;
	cout << temp->headline << ":" << endl;
	cout << temp->value <<" [" << temp->unit << "]" << endl << endl ;
}

void Interface1::change_value(parameter *temp){
	uint16_t new_value ;
	cin >> new_value ;
	temp->value = new_value ;
}

void Interface1::send_error_no_changeable() {
	cout << endl << "No change" << endl;
	cout << "possible" << endl << endl;
}

