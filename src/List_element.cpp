#include "List_element.h"

List_element::List_element(Parameter *parametr) {
     parameter_element  = parametr ;
}

void List_element::set_Next_Pointer(List_element *next_pointer ){
    next = next_pointer ;
}
void List_element::set_Prev_Pointer(List_element *prev_pointer ){
    prev = prev_pointer ;
}

List_element* List_element::get_Next_Pointer() {
    return next ;
}
List_element* List_element::get_Prev_Pointer() {
    return prev ;
}

Parameter* List_element::get_Current_Parameter(){
    return parameter_element ;
}

/*
void List_element::print(){
	cout<<parameter_element->getHeadLine() << endl;
}
*/
