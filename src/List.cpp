#include "List.h"


//#define DEBUG

#ifdef DEBUG
string intToStr(int n){
	string tmp, ret;
	if(n < 0) {
		ret = "-";
		n = -n;
	}
	do {
		tmp += n % 10 + 48;
		n -= n % 10;
	}
	while(n /= 10);
	for(int i = tmp.size()-1; i >= 0; i--)
		ret += tmp[i];
	return ret;
}
#endif

List::List(){

}

void List::addFirstElement(List_element *element){
	first_pointer = current_element = last_element = element;
	size++;
}

void List::addNextElement(List_element *element){
	last_element->next = element;
	last_element = element;
	size++;
}

void List::add_Parameter(Parameter *parameter){
#ifdef DEBUG
	cout << "Dodawnie " + intToStr(size) + " elementu:" << endl;
	cout << parameter->getHeadLine() << endl;
#endif

	if(size == 0){
		addFirstElement(new List_element(parameter));
	} else {
		addNextElement(new List_element(parameter));
	}

#ifdef DEBUG
	cout << "Dodano, aktualny rozmiar listy: " << size << endl << endl;
#endif
	//     first_pointer =  ;





	//    if(first_element == 0)
	//    {
	//        cout << "Pierwszy " << endl;
	//
	//      current_element = first_element ;
	//    }
	//    else{
	//            cout << "Nie pierwszy " << endl;
	//        last_element = new List_element(parameter) ;
	//
	//        current_element->set_Next_Pointer(last_element);
	//       // first_element->set_Prev_Pointer(last_element);
	//
	//        last_element->set_Next_Pointer(first_element);
	//        //last_element->set_Prev_Pointer(current_element);
	//
	//        current_element = last_element ;
	//    }


}


Parameter* List::get_Parameter(int index){
	/*
    current_element = first_element ;
    for( int i=1 ; i<index ; i++ )
    {
        current_element = current_element->get_Next_Pointer() ;
    }
    return current_element->get_Current_Parameter() ;
	 */
}

