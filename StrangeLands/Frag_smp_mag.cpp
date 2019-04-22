#include "Frag_smp_mag.h"
#include "St_armor_M.h"
#include "St_weapon_M.h"
#include "iostream"

using namespace std;

void Frag_smp_mag::dialog_f1()
{
	cout << "*Простой Маг*" << endl;
}

Frag_smp_mag::Frag_smp_mag()
{
	armorchic = new St_armor_M();
	weaponchic = new St_weapon_M();
}