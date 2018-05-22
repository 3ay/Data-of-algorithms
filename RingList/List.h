#pragma once
#include "Item.h"
class List
{
private: int Cout = 0; // size of List
public:

	Item *Head;
	List();
	void Add(Data * data);
	void sort_list();
	~List();
	int getCout();
	void setCout(int x);
	void Delete(int x);
	void Show(int x);
	void Search(int x);
		 
};
