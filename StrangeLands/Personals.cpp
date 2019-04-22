#include "Personals.h"
#include <string.h>
#include <iostream>


using namespace std;

Personals::Personals()
{
	Health = 50;
//	WPdam = 9;
}

Personals::~Personals()
{
	//
}

 void Personals :: performArmoR()
{
	armorchic->armor_E1();
}

void Personals :: performWeapon()
{
	weaponchic->weapon();
}

/* void Personals::vibor_pers()
{
	cout << "Выбрете фракцию, Мага (клавиша m)  или Война (клавиша v)" << endl;
	scanf("%c", &M);
	while ((M != 'm') || (M != 'v'))
	{
		if (M == 'm')
		{
			cout << "Вы выбрали Мага. Предсавители данной фракции были созданы Древними путём изменеия людей 'Небесным камнем' " << endl;
			break;
		}
		else if (M == 'v')
		{
			cout << "Вы выбрали Война. Когда пала главная столица Древних, Последний полководец заключил союз с людьми дав неоторым из них 'Сияние берсерка' " << endl;
			break;
		}
		else
		{
			cout << "ERROR" << endl;

		}
	}
}
*/

/* void Personals::armor_E1()
{
	ARpoint = 5;
	AR[25] = "Броня низкого класса";
	printf("Броня: %s\n", AR[25]);
	printf("Защита: %i\n", ARpoint);
}
*/

/* void Personals::weapon()
{
	WPdam = 9;
	printf("Урон оружия: %i\n", WPdam);
}
*/
// ПЕРВЫЙ СТАРТОВЫЙ БУСТ ЛЕЖИТ В КЛАССЕ ArmoR
void Personals::XP_E1()
{
	Health = 50;
	printf("Здоровье: %i\n", Health);
}

void Personals::inventar()
{
	cout << "Персонаж имеет при себе: " << endl;
}
/* void Personals::location()
{
}
*/