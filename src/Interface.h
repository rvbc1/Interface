#include "List.h"

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <conio.h>

class Interface{
private :
	Parameter *battery_voltage ;
	Parameter *work_time ;
	Parameter *distance ;
	Parameter *energy_consumed ;
	Parameter *temperature ;

	void get_Value() ;

	List *list_of_elements ;
public:
	Interface() ;
	Interface_Element::Action getAction(Interface_Element::Button) ;
	void display() ;
	void displayError();
	void refresh() ;
};

#endif /* INTERFACE_H_ */
