#pragma once
#include <stddef.h> 

const int t = 2; // ������� ������
class BNode
{

public:
	
	int keys[2 * t]; // ����� ����
	BNode *children[2 * t + 1]; // �������
	BNode *parent; // ������
	int Count = NULL; // ���������� ������ ����
	int CountSons = NULL; // ���������� �������
	bool Leaf; // ���� - ������� �� ������� ��������
	BNode();
	~BNode();
	
};