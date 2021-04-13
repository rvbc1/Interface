#ifndef INTERFACE_MANAGER_H_
#define INTERFACE_MANAGER_H_


#include <iostream>
#include "Interface.h"
#include "InterfaceInput.h"


class InterfaceManager{
public:
	InterfaceManager() ;
private:
	Interface *interface = nullptr;
	InterfaceInput::Button readKey() ;
	void display() ;
};
#endif /* INTERFACEMANAGER_H_ */
