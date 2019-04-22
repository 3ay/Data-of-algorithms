#include "St_armor_M.h"
#include "ArmoR.h"

void St_armor_M :: armor_E1()
{
	
	AR[25] = " Одежда простого Друида";
	printf("Броня: %s\n", AR[25]);

	ARpoint = 5;
	printf("Защита: %f\n", ARpoint+15);
}


