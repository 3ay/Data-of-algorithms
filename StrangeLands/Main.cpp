#include <iostream>
#include <string.h>
#include <locale.h>

//#include "stdafx.h"
#include "Personals.h"
 #include "Dialogs.h"
#include "VAR.h"
#include "St_weapon_M.h"
#include "St_weapon_V.h"
#include "Frag_smp_mag.h"
#include "St_armor_V.h"
#include "St_armor_M.h"
#include "ArmoR.h"
#include "WeapoN.h"
#include "Vibor_pers.h"
#include "Dialog_v1.h"
#include "Nickname.h"
#include "Opisanie.h"
#include "VAR.h"
#include "MAG.h"
#include "Location.h"
#include "windows.h"
using namespace std;

int main() //int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	Personals bc;
	ArmoR ac;
	Vibor_pers vc;
	WeapoN wp;
	///////////////
	vc.vibor_pers();
	bc.inventar();
	ac.armor_E1();
	bc.XP_E1();
	//////////////
	//Dialogs *dc=new Dialogs();
	Dialogs *dc;
	dc->first_dialog();

	ArmoR *acd;
	acd->first_healphBT();

	Dialog_v1 *dc1;
	dc1->dialog1();

	Nickname *nck;
	nck->nick();

	Opisanie *opi;
	opi->start();
	////////////////////////////////
	 Personals *pers = new VAR();

	pers->performWeapon();
	//pers->performArmoR();
	
	pers->setArmoR(new St_armor_V());
	pers->performArmoR();
	/////////////////////////////////
	Location *loc;
	loc->locyard();
	//wp.weapon();
	/////////////////////////////////////
	Personals *fpers = new Frag_smp_mag();

	fpers->setArmoR(new St_armor_M());
	fpers->performArmoR();

	fpers->setWeapoN(new St_weapon_M());
	fpers->performWeapon();

	system("pause");
	return 0;
}