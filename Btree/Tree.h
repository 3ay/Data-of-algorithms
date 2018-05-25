#pragma once
#include "BNode.h"
class Tree
{
private:
	BNode *root=nullptr; // ���� ������ (��������� �� ������ ������)
	void insert_to_node(int key, BNode *node); // ����� �������� ����������
	void sort(BNode *node); // ����� ����������
	void restruct(BNode *node); // ����� ��������� ���� SOON
	void deletenode(BNode *node); //����������� ����� ��������
	bool searchKey(int key, BNode *node); // ����� �� �����
	void remove(int key, BNode *node); // �������� �� ������������� ����
	void removeFromNode(int key, BNode *node);// ����� �������� ����� �� ����
	void removeLeaf(int key, BNode *node); // �������� ����� �� ����
	void lconnect(BNode *node, BNode *othernode); // ����� ���������� ����� �����
	void rconnect(BNode *node, BNode *othernode); // ������
	void repair(BNode *node); // ����� "�������" ����
	// ���������� 

public:
	Tree();
	~Tree();
	void insert_k(int key); 
	bool search_k(int key);
	void remove_k(int key);
};

