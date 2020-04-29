//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H
#include <conio.h>
#include "List.h"


class Interface1{
private :
	Parameter *battery_voltage ;
	Parameter *work_time ;
	Parameter *distance ;
	Parameter *energy_consumed ;
	Parameter *temperature ;

	void get_Value() ;

	List *list_of_elements ;
public:
	Interface1() ;
	int get_Button(int) ;
	void display() ;
	void display_Error();
};
