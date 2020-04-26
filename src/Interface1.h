//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H
#include <conio.h>
//#include "Parameter.h"
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

	int actual_index ;
public:
	Interface1() ;
	void get_Button(int) ;

};
