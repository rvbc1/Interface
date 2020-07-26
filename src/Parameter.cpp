#include "Parameter.h"
#include "List.h"
//#define DEBUG
#include <windows.h>
Parameter::Parameter(string h, int v, string u , uint8_t ch ){
	headline = h;
	value = v ;
	unit = u ;
	changeable_value = ch;
	edit_mode = false ;
}

List* Parameter::getSubList(){
    if( has_sub_list)
        return list ;
}
void Parameter::createList(){
    list = new List();
    has_sub_list = true;
    list->addBackParameter() ;
}

void Parameter::addBackParameterToList(){
    list->addBackParameter() ;
}

void Parameter::addToSubList(Parameter *p){
	if( !has_sub_list)
        createList() ;
    list->addParameter(p) ;
}

uint8_t Parameter::ifHasSubList(){
    return has_sub_list ;
}

uint8_t Parameter::ifInSubList(){
    return in_sub_list ;
}

void Parameter::sendToDisplay()
{
    system("cls");
    cout << headline << endl;
    if( !back_from_sub_list){
        if( visible_value){
            if( has_sub_list == false )
                cout << value << " " << unit ;
            }
        else{
            for( int i = value ; i > 0 ; i /= 10)
                cout <<" ";
            cout << " " << unit ;
        }
    }

#ifdef DEBUG
	cout << endl << endl;
	if(has_sub_list){
		cout << "This parameter has sub list" << endl;
		list->print();
	} else {
		cout << "This parameter has no sub list" << endl;
	}

#endif


}
void Parameter::refreshEditMode(){

    if(edit_mode){
        visible_value = !visible_value ;
        sendToDisplay() ;
    }
}

void Parameter::sendErrorNoChangeable(){

    system("cls");
	cout <<"No change" << endl ;
	cout <<"possible" ;
}

Parameter* Parameter::getParametr(){
    if(has_sub_list && in_sub_list)
        return list->getParameter();
    else
        return this ;
}

Interface_Element::Action Parameter::getButton(Interface_Element::Button button){

    if( button == Interface_Element::ENTER){
        if(edit_mode){
                edit_mode = false ;
                visible_value = true ;
        }
        else{
            if(changeable_value){
                edit_mode = true ;
                visible_value = false ;
            }
            else if(has_sub_list){
                 in_sub_list = true ;
            }
            else if(back_from_sub_list)
                return Interface_Element::SET_OUT_OF_SUB_LIST ;
            else
                return Interface_Element::ERROR_NO_CHANGEABLE;
        }
        return Interface_Element::DO_NOTHING ;
    }
    else if(edit_mode) {
        visible_value = true ;
		if(button == Interface_Element::RIGHT_BUTTON){
			value++;
			return Interface_Element::DO_NOTHING ;
		}
		else if(button == Interface_Element::LEFT_BUTTON){
            value--;
            return Interface_Element::DO_NOTHING ;
		}

    }
    else if( button == Interface_Element::LEFT_BUTTON){
        return Interface_Element::MOVE_LEFT ;
    }
    else if( button == Interface_Element::RIGHT_BUTTON){
        return Interface_Element::MOVE_RIGHT ;
    }
}


string Parameter::getHeadLine(){
	return this->headline;
}

void Parameter::setOutOfSubList(){
    in_sub_list = false ;
    list->resetSubList() ;
}

void Parameter::newMove(Interface_Element::Action action){

   if(action == Interface_Element::MOVE_RIGHT)
        list->moveRight() ;
    else if( action == Interface_Element::MOVE_LEFT)
        list->moveLeft() ;
}
void Parameter::closeLastOpenSubList(){
    if( in_sub_list ){
        if( list->hasOpenSubList())
            list->setOutOfSubList() ;
        else
          setOutOfSubList() ;
    }
}

void Parameter::setAsBackParameter(){
    back_from_sub_list = true ;
}
uint8_t Parameter::isBackParameter(){
    return back_from_sub_list ;
}

