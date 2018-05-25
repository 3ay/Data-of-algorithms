#pragma once
#include "BNode.h"
class Tree
{
private:
	BNode *root=nullptr; // узел дерева (указатель на корень дерева)
	void insert_to_node(int key, BNode *node); // метод простого добавления
	void sort(BNode *node); // метод сортировки
	void restruct(BNode *node); // метод разбиения узла SOON
	void deletenode(BNode *node); //рекурсивный метод удаления
	bool searchKey(int key, BNode *node); // поиск по ключу
	void remove(int key, BNode *node); // удаление из произвольного узла
	void removeFromNode(int key, BNode *node);// метод удаления ключа из узла
	void removeLeaf(int key, BNode *node); // удаление ключа из узла
	void lconnect(BNode *node, BNode *othernode); // метод соединения узлов левый
	void rconnect(BNode *node, BNode *othernode); // правый
	void repair(BNode *node); // метод "починки" узла
	// добавление 

public:
	Tree();
	~Tree();
	void insert_k(int key); 
	bool search_k(int key);
	void remove_k(int key);
};

