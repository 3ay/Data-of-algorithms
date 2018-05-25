#include "stdio.h"
#include "BNode.h"
#include "Tree.h"
#include <iostream>
int main()
{
	Tree *tr = new Tree();
	tr->insert_k(0);
	tr->insert_k(5);
	tr->insert_k(3);
	tr->insert_k(6);

	tr->insert_k(7);
	tr->insert_k(8);
	tr->insert_k(9);
	tr->insert_k(10);
	tr->insert_k(11);
	tr->insert_k(12);

	std::cout << tr->search_k(0) << std::endl;
	
	tr->remove_k(5);
	std::cout << tr->search_k(5) << std::endl;
	system("pause");

	return 0;
}