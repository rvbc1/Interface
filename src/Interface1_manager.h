#include <conio.h>
#include "Interface1.h"

#include "Interface_Element.h"

class Interface1_manager{
public:
	Interface1_manager() ;
    void print(Interface_Element::Action info) ;
private:
	Interface1 *Ssd_1306 ;
	Interface_Element::Button readKey() ;
};
