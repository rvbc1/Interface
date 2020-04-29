/*
 * InterfaceButton.h
 *
 *  Created on: 29.04.2020
 *      Author: Admin
 */

#ifndef INTERFACEBUTTON_H_
#define INTERFACEBUTTON_H_

#define BUTTON_1 75 // left
#define BUTTON_2 90 //right
#define BUTTON_3 80 // down
#define SPECIAL_BUTTON 224

class Interface_Button {
public:
	enum button {LEFT, ENTER, RIGHT};
	static const int LEFT_BUTTON = 7;
private:
	Interface_Button();
	virtual ~Interface_Button();
};

#endif /* INTERFACEBUTTON_H_ */
