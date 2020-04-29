#include "Parameter.h"
//#define BUTTON_1 75 // left
//#define BUTTON_2 77 // right
//#define BUTTON_3 80 // down
#define DO_NOTHING -1
#define ERROR 0
Parameter::Parameter(string h, int v, string u , bool ch ){
	headline = h;
	value = v ;
	unit = u ;
	if_changeable_value = ch;
	edit_mode = 0 ;
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

int Parameter::getButton(int button){

    if( button == BUTTON_3){
        if(edit_mode){
                edit_mode=0;
        }
        else{
            if(if_changeable_value)
                edit_mode=1 ;
            else
                return ERROR ;
        }
        return DO_NOTHING ;
    }
    else if(edit_mode) {
		if(button == BUTTON_2){
			value++;
			return DO_NOTHING ;
		}
		else if(button == BUTTON_1){
            value--;
            return DO_NOTHING ;
		}
    }
    else if( button == BUTTON_1){ // left
        return BUTTON_1 ;
    }
    else if( button == BUTTON_2){ // right
        return BUTTON_2 ;
    }
}

/*
string Parameter::getHeadLine(){
	return this->headline;
}
*/
