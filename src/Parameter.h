#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>

#include "InterfaceButton.h"

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
	void send_To_Display() ;
	int getButton(int) ;
	void send_Error_No_Changeable() ;
	//string getHeadLine();
};
