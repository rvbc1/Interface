#include <conio.h>
#include "Interface1.h"

class Interface1_manager{
public:
	Interface1_manager() ;
    void print(int) ;
private:
	Interface1 *Ssd_1306 ;
	int readKey() ;
};
