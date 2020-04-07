//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H
#include <iostream>
using namespace std;
//#include <main.h>

class Interface1{

public:
	struct parameter  ;
	Interface1();
	void which_button(int) ; //(uint16_t);
	void send_to_display(parameter* );
	int position ; //uint16_t zmienna;

	parameter *first ;

	parameter *right_parameter ;
	parameter *middle_parameter ;
	parameter *left_parameter ;

};
