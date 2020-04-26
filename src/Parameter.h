#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>

using namespace std;

class Parameter {
private:
	string headline;
	int value ;
	string unit;


public:
	Parameter(string, int, string, bool ) ;



	bool if_changeable_value ;

	void change_Value(int) ;
	void send_To_Display() ;
	void send_Error_No_Changeable() ;
};
