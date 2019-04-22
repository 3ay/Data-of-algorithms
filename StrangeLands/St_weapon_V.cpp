#include "St_weapon_V.h"



void St_weapon_V::weapon()
{
	sprintf(WPname,"Даснийски палаш");
	printf("Оружие:%s\n", WPname[25]);
	printf("Урон: %i\n", WPdam - 1); //Wpdam=9 (изначально)
}