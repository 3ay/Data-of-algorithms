#include "VAR.h"
#include "St_armor_V.h"
#include "St_armor_M.h"
ArmoR  arm;

VAR::VAR()
{
	armorchic = new ArmoR();
	weaponchic= new WeapoN();
}

void VAR :: stena()
{
	arm.ARpoint =+(arm.ARpoint)*0.05;
}

WeapoN wea;
void VAR:: mix_attack()
{
	wea.WPdam = +(wea.WPdam)*0.11;
}


