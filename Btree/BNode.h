#pragma once
#include <stddef.h> 

const int t = 2; // степень дерева
class BNode
{

public:
	
	int keys[2 * t]; // ключи узла
	BNode *children[2 * t + 1]; // потомок
	BNode *parent; // предок
	int Count = NULL; // количество ключей узла
	int CountSons = NULL; // количество сыновей
	bool Leaf; // лист - элемент не имеющий потомков
	BNode();
	~BNode();
	
};