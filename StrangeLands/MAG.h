#pragma once
#include "Personals.h"
#include "ArmoR.h"
#include "WeapoN.h"
#include "math.h"
class MAG :
	public Personals
{
public:
	// скилы мага
	void run_attack(); // особая атака магов
	void mag_shit();
};

