#include "ArmoR.h"
#include "Personals.h"
#include <iostream>


using namespace std;

void ArmoR :: armor_E1()
{
	
	AR[25] ="Броня низкого класса";
	printf("Броня: %s\n",AR[25]);
	ARpoint = 5;
	printf("Защита: %f\n", ARpoint);
	
}
Personals HP;
void ArmoR::first_healphBT()
{
	HP.Health;
	printf("Здоровье увеличилось:  %i\n",HP.Health + 15);
}


