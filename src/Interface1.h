//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H

#include "Parameter.h"


class Interface1{
private :
	Parameter *battery_voltage ;
	Parameter *work_time ;
	Parameter *distance ;
	Parameter *energy_consumed ;
	Parameter *temperature ;

	Parameter *middle ;

	double get_value() ;

public:
	Interface1() ;
	void get_button(int) ;

};
