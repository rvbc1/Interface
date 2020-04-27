#include "List_element.h"

List_element::List_element(Parameter *parametr) {

     parameter_element  = parametr ;
     cout <<parametr << "wsk na parameter w list_element" << endl;
}

void List_element::print(){
	cout<<parameter_element->getHeadLine() << endl;
}


/*
void List_element::set_Next_Pointer(List_element *next_pointer ){
    next = next_pointer ;
}

List_element* List_element::get_Next_Pointer() {
    return next ;
}
Parameter* List_element::get_Current_Parameter(){
    return parameter_element ;
}
*/
