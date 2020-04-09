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

	Parameter *right ;
	Parameter *left ;

	bool if_changeable_value ;

	void change_value(int) ;
	void send_to_display() ;
	void send_error_no_changeable() ;
};
