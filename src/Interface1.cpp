#include "Interface1.h"
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define MAX_POSITION 4

Interface1::Interface1(){
	position = 1 ;
}

void Interface1::voltage() {

}
void Interface1::value2() {

}
void Interface1::value3() {

}
void Interface1::value4() {

}

void Interface1::which_button(int button_w){
	if( button_w == BUTTON_1){
		if(position == 1 ) position = MAX_POSITION ;
		else position-- ;
	}
	else if( button_w == BUTTON_2){
			position = (position+1)%MAX_POSITION ;
		}
	show_parameter() ;
}

void Interface1::show_parameter(){
	if(position == 1 ) voltage() ;
	else if( position == 2 ) value2();
	else if( position == 3 ) value3();
	else if( position == 4 ) value4();
}


