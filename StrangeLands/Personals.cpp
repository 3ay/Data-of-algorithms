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
	cout << "������� �������, ���� (������� m)  ��� ����� (������� v)" << endl;
	scanf("%c", &M);
	while ((M != 'm') || (M != 'v'))
	{
		if (M == 'm')
		{
			cout << "�� ������� ����. ������������ ������ ������� ���� ������� �������� ���� �������� ����� '�������� ������' " << endl;
			break;
		}
		else if (M == 'v')
		{
			cout << "�� ������� �����. ����� ���� ������� ������� �������, ��������� ���������� �������� ���� � ������ ��� �������� �� ��� '������ ��������' " << endl;
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
	AR[25] = "����� ������� ������";
	printf("�����: %s\n", AR[25]);
	printf("������: %i\n", ARpoint);
}
*/

/* void Personals::weapon()
{
	WPdam = 9;
	printf("���� ������: %i\n", WPdam);
}
*/
// ������ ��������� ���� ����� � ������ ArmoR
void Personals::XP_E1()
{
	Health = 50;
	printf("��������: %i\n", Health);
}

void Personals::inventar()
{
	cout << "�������� ����� ��� ����: " << endl;
}
/* void Personals::location()
{
}
*/