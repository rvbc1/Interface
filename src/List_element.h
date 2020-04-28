#include "Parameter.h"


class List_element{

  private:
     // List_element *next ; //*prev;
      Parameter *parameter_element ;
  public:
      List_element *next ; //*public for test //Marek
      List_element(Parameter *parametr);

      List_element* get_Next_Pointer() ;
      Parameter* get_Current_Parameter();

      void set_Next_Pointer(List_element *next_pointer );
      void print();
};

