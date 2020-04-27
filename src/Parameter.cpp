#include "Parameter.h"
#define BUTTON_1 75
#define BUTTON_2 77
Parameter::Parameter(string h, int v, string u , bool ch ){
	headline = h;
	value = v ;
	unit = u ;
	if_changeable_value = ch;
}

void Parameter::change_Value(int l_or_r ){

   if( l_or_r == BUTTON_1)
   {
        value-- ;

   }
   else if( l_or_r == BUTTON_2)
        value++ ;
	send_To_Display() ;
}

void Parameter::send_To_Display()
{
	system("cls");

	cout << headline << endl;
	cout << value << " " << unit ;
}
void Parameter::send_Error_No_Changeable(){

    system("cls");

	cout <<"No change" << endl ;
	cout <<"possible" ;
}

string Parameter::getHeadLine(){
	return this->headline;
}
