#include "List.h"

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <conio.h>

class Interface{
public:
	Interface() ;
	void sendAction(Interface_Element::Button) ;
	void displayError();
	void refresh() ;
	string getParameterHeadline() ;
	uint8_t hasSubList() ;
	uint8_t isVisibleValue() ;
	string getParameterUnit() ;
	uint16_t getParameterValue() ;
	uint8_t isNoChangeableErrorCounting() ;
	uint8_t isSaveParameterValueMode() ;
	uint8_t isBackFromSubListParameter() ;
private :
	Parameter *battery_voltage ;
	Parameter *work_time ;
	Parameter *distance ;
	Parameter *energy_consumed ;
	Parameter *temperature ;
	void get_Value() ;
	List *list_of_elements ;


};

#endif /* INTERFACE_H_ */
