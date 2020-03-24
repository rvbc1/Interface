//#ifndef CLASSES_Interface1_H
//#define CLASSES_Interface1_H
#include <iostream>
using namespace std;
//#include <main.h>

class Interface1{
public:
	Interface1();
	void which_button(int) ; //(uint16_t);
	int position ; //uint16_t zmienna;

private:
	void voltage();
	void value2();
	void value3();
	void value4();

	void show_parameter();

};
