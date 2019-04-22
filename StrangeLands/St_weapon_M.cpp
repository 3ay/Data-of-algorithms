#include "St_weapon_M.h"
#include "WeapoN.h"


void St_weapon_M::weapon()
{
	sprintf(WPname, "Костяной нож друида");
	printf("Оружие:%s\n", WPname);
	WPdam = 9;
	printf("Урон: %f\n", WPdam-3);
}
