#include "Item.h"
#include "stdio.h"


Item::Item()
{
	//Item *next;

}
Item::Item(Data *data)

{
	this->data = data;
	this->next = NULL;
}

Item::~Item()
{
}
