#pragma once
#include "Data.h"
class Item
{
public:
	Data *data;
	Item *next;
	Item();

	Item(Data * data);
	~Item();
};

