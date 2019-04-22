#pragma once
//#include "Personals.h"
class ArmoR
{

public:
	char* AR[25]; // описание брони
	float ARpoint; // единицы прочности брони
	
	virtual void armor_E1(); // броня персонажа |отдельный класс
	void first_healphBT(); // для баланса стартовый буст вшит 
};

