#include "Interface1_manager.h"

Interface1_manager::Interface1_manager(){

		Ssd_1306 = new Interface1 ;

		while(true){
			cout <<"podaj przysisk: 1-lewo, 2-prawo, 3-zmiana" << endl;
			cin >> podany_przycisk ;
			Ssd_1306->get_button(podany_przycisk) ;
		}
}
