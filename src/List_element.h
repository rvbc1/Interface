#include "Parameter.h"


class List_element{

  private:
//      List_element *next ; //*prev;
      Parameter *parameter_element ;
  public:
      List_element *next ; //*public for test //Marek
      List_element(Parameter *parametr) ;
      void set_Next_Pointer(List_element *next_pointer );
    //  void set_Prev_Pointer(List_element *prev_pointer );

      List_element* get_Next_Pointer() ;
     // List_element* get_Prev_Pointer() ;
      Parameter* get_Current_Parameter();
};

