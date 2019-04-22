#include "WeapoN.h"
#include <iostream>


using namespace std;

void WeapoN :: weapon()
{
	
	 sprintf(WPname, "****Изящный клинок****");
	//sprintf(WPname,"%s","sdsdsddssd");
	printf("Оружие в руках: %s\n", WPname);
		WPdam=9;
	//printf("урон оружия: %f\n", WPdam); // стартовое оружие по умолчанию "Изящный клинок"
		//sprintf(WPdam, "урон оружия");
	cout <<"Урон оружия: "<< WPdam << endl;

}
	
	