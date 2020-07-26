#include "Interface.h"
Interface::Interface(){

	list_of_elements = new List();

	list_of_elements->addParameter(new Parameter("U battery" , 7.4 , "V", 0 )) ;
	list_of_elements->addParameter(new Parameter("Work time" , 2 , "h", 1)) ;
	list_of_elements->addParameter(new Parameter("Distance" , 100 , "m", 1)) ;
	list_of_elements->addParameter(new Parameter("En consumed" , 3 , "kWh", 0)) ;
	list_of_elements->addParameter(new Parameter("Temperature" , 20 , "C" , 0)) ;

	Parameter *pid = new Parameter("pid", 3, "P I D", 0);
	pid->addToSubList(new Parameter("P" , 20 , "kp" , 1));
	pid->addToSubList(new Parameter("I" , 20 , "ki" , 1));
	pid->addToSubList(new Parameter("D" , 20 , "kd" , 1));
	list_of_elements->addParameter(pid);
/*

	Parameter *podlista1 = new Parameter("podlista1");
	podlista1->addToSubList(new Parameter("argument1" , 20 , "m" , 1));
	podlista1->addToSubList(new Parameter("argument2" , 560 , "k" , 1));
	podlista1->addToSubList(new Parameter("argument3" , 2033 , "m" , 1));


    Parameter *podlista2 = new Parameter("podlista2");
	podlista2->addToSubList(new Parameter("arg1" , 20 , "k" , 1));
	podlista2->addToSubList(new Parameter("arg2" , 560 , "k" , 1));
	podlista2->addToSubList(new Parameter("arg3" , 2033 , "k" , 1));

	Parameter *podlista3 = new Parameter("podlista3");
	podlista3->addToSubList(new Parameter("a1" , 1 , "C" , 1));
	podlista3->addToSubList(new Parameter("a2" , 100 , "C" , 1));
	podlista3->addToSubList(new Parameter("a3" , 1000 , "C" , 1));
	podlista3->addBackParameterToList() ;

	podlista2->addToSubList(podlista3) ;
	podlista2->addBackParameterToList() ;
    podlista1->addToSubList(podlista2) ;

    podlista1->addBackParameterToList() ;

    list_of_elements->addParameter(podlista1);
*/
    display();
}

Interface_Element::Action Interface::getAction(Interface_Element::Button button){

	Interface_Element::Action action = list_of_elements->getParameter()->getButton(button);

	switch(action){
        case Interface_Element::ERROR_NO_CHANGEABLE:
            list_of_elements->sendNoChangeableValueError() ;
            return Interface_Element::ERROR_NO_CHANGEABLE;

        case Interface_Element::MOVE_LEFT :
            list_of_elements->moveLeft() ;
            return Interface_Element::PRINT;

        case Interface_Element::MOVE_RIGHT:
            list_of_elements->moveRight();
            return Interface_Element::PRINT;

        case Interface_Element::DO_NOTHING:
            return Interface_Element::PRINT;

        case Interface_Element::SET_OUT_OF_SUB_LIST:
            list_of_elements->setOutOfSubList() ;
            return Interface_Element::PRINT;
	}
}

void Interface::display(){
    list_of_elements->getParameter()->sendToDisplay();
}

void Interface::displayError(){
    list_of_elements->getParameter()->sendErrorNoChangeable() ;
}

void Interface::refresh(){

  //  list_of_elements->refreshNoChangeableValueError() ;
    list_of_elements->getParameter()->refreshEditMode() ;
}
