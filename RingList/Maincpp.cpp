#include "stdio.h"
#include "List.h"

#include <iostream>
#include "Item.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	List *list = new List();
	Data *data = new Data(74);
	Data *data1 = new Data(28);
	Data *data3 = new Data(93);
	//Data *data4 = new Data(3);
	list->Add(data);
	list->Add(data1);
	list->Add(data3);
	list->Show(list->getCout());
	list->Delete(1);
	list->Search(1);
	list->Show(list->getCout());
	std::cout << std::endl;
	system("pause");

	return 0;
}