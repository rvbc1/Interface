#include "List.h"

void List::add_Parameter(Parameter *parameter){


     first_pointer = new List_element(parameter) ;
     cout << " Tu juz nie dziala" << endl;

    /*
    if(first_element == 0)
    {
        cout << "Pierwszy " << endl;

      current_element = first_element ;
    }
    else{
            cout << "Nie pierwszy " << endl;
        last_element = new List_element(parameter) ;

        current_element->set_Next_Pointer(last_element);
       // first_element->set_Prev_Pointer(last_element);

        last_element->set_Next_Pointer(first_element);
        //last_element->set_Prev_Pointer(current_element);

        current_element = last_element ;
    }
    */

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

