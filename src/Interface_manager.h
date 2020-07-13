#include "Interface.h"

#ifndef INTERFACEMANAGER_H_
#define INTERFACEMANAGER_H_
#include <conio.h>
#include <ctime>
#include <chrono>

class Interface_manager{
public:
	Interface_manager() ;
    void print(Interface_Element::Action info) ;
private:
	Interface *Ssd_1306 ;
	Interface_Element::Button readKey() ;
};
#endif /* INTERFACEMANAGER_H_ */
