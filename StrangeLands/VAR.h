#pragma once
#include "Personals.h"
#include "ArmoR.h"
#include "WeapoN.h"
#include "math.h"
class VAR :
	public Personals
{
public:
	// скилы война
	void mix_attack(); // особая атака войнов
	void stena(); // особая стойкость
	VAR();
};

