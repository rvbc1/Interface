#include "Parameter.h"

Parameter::Parameter(string h, double v, string u , bool ch ){
	headline = h;
	value = v ;
	unit = u ;
	if_changeable_value = ch;
}

void Parameter::change_value(double new_value){
	value = new_value ;
	send_to_display() ;
}

void Parameter::send_to_display()
{
	system("cls");

	cout << endl << endl ;
	cout << headline << endl;
	cout << value << " " << unit << endl ;
}
void Parameter::send_error_no_changeable(){
	cout << endl ;
	cout <<"No change" << endl ;
	cout <<"possible" << endl ;
}
