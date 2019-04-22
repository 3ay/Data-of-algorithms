#include "MAG.h"

ArmoR armM;

void MAG :: run_attack()
{
	armM.ARpoint = +(armM.ARpoint)*0.08;
}

WeapoN weaM;

void MAG::mag_shit()
{
	weaM.WPdam = +(weaM.WPdam)*0.09;
}

