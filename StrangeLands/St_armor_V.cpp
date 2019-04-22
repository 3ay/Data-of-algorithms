#include "St_armor_V.h"
#include "ArmoR.h"

void St_armor_V :: armor_E1()
{
	
	AR[25] = "Одежда война-наемника";
	printf("Броня: %s\n", AR[25]);

	ARpoint = 5;
	printf("Защита: %f\n", ARpoint+25);
}


