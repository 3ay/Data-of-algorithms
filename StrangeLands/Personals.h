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
	virtual void XP_E1(); // �������� ��������� /������� �����
	
	// virtual void weapon(); // ������ ��������� (vir) / ��������� �����
						   //void run_attack(); // ������ ����� ����� (vir_later)
						   //void mix_attack(); // ������ ����� ������ (vir_later)

	void inventar(); // ������� �����
	int Health; //���������� �������� /// ������� �����
	//virtual void location(); // ��������� �����
	//void dialogs(); (������� ������ ��� ����� ����� ������) // ��������� �����
//	void vibor_pers(); // ����� ���������, "m"��� "v" (ENG) // ��������� ������
	


	//char Name[10];
	//char* AR[25];// �������� �����
	//int WPdam; // ������� ������ ������
	// int ARpoint; // ������� ��������� �����
/* private:
	char WP; // �������� ������ ���������
	char M;
	*/
};

