#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>

#include "Interface_Element.h"

using namespace std;

class Parameter {
private:
	string headline;
	int value ;
	string unit;
    bool edit_mode ;
public:
	Parameter(string, int, string, bool ) ;
	bool if_changeable_value ;
	void sendToDisplay() ;
	Interface_Element::Action getButton(Interface_Element::Button) ;
	void sendErrorNoChangeable() ;
	//string getHeadLine();
};
