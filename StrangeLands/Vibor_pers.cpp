#include "Vibor_pers.h"
#include "iostream"

using namespace std;

void Vibor_pers::vibor_pers()
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
