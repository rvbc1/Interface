#include "List_element.h"


class List{
private:

    List_element *current_element;
    List_element *last_element ;
    List_element *first_pointer ;

public :
    List() ;
    Parameter* get_Parameter(int index);
    void add_Parameter(Parameter *parameter) ;
};

