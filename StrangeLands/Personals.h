#pragma once
#include "ArmoR.h"
#include "WeapoN.h"

class Personals
{
public:

	Personals();
	~Personals();

	
	ArmoR *armorchic  ;

	WeapoN *weaponchic ;
	
	void  performArmoR();

	void setArmoR(ArmoR *am1)
	{
		armorchic = am1;
	}
	
	
	void performWeapon();
	void setWeapoN(WeapoN *wp1)
	{
		weaponchic = wp1;
	}
	//virtual void display() = 0;
	virtual void XP_E1(); // здоровье персонажа /√Ћј¬Ќџ…  ласс
	
	// virtual void weapon(); // оружие персонажа (vir) / отдельный класс
						   //void run_attack(); // особа€ атака магов (vir_later)
						   //void mix_attack(); // особа€ атака войнов (vir_later)

	void inventar(); // главный класс
	int Health; //количество здоровь€ /// √Ћј¬ный  Ћјсс
	//virtual void location(); // ќ“ƒ≈льный класс
	//void dialogs(); (надоело каждый раз новый дилог писать) // ќ“ƒ≈Ћ№Ќџ… класс
//	void vibor_pers(); // выбор персонажа, "m"или "v" (ENG) // ќтдельный  Ћассс
	


	//char Name[10];
	//char* AR[25];// описание брони
	//int WPdam; // единицы дамага оружи€
	// int ARpoint; // единицы прочности брони
/* private:
	char WP; // описание оружи€ персонажа
	char M;
	*/
};

