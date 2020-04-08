#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>

using namespace std;

class Parameter {
private:
	string headline;
	double value ;
	string unit;


public:
	Parameter(string, double, string, bool) ;

	Parameter *right ;
	Parameter *left ;

	bool if_changeable_value ;

	void change_value(double) ;
	void send_to_display() ; //(Parameter*) ;
	void send_error_no_changeable() ;
};
