//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H
#include <iostream>
#include <cstdio>
#include <stdint.h>
using namespace std;
//#include <main.h>

class Interface1{

private :
	struct parameter  ;
	parameter *middle_parameter ;

	void send_to_display(parameter*);
	void change_value(parameter*) ;
	void send_error_no_changeable() ;



public:
	void which_button(uint16_t) ;
	Interface1();
};
