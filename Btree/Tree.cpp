#include "Tree.h"
#include <iostream>


void Tree::insert_to_node(int key, BNode * node)
{
	node->keys[node->Count] = key;
	node->Count = node->Count + 1;
	sort(node);
	
}

void Tree::sort(BNode * node)
{
	int m = 0;
	for (int i = 0; i < (2 * t - 1); i++)
	{
		for (int j = i + 1; j <= (2 * t - 1); j++)
		{
			if ((node->keys[i] != 0) && (node->keys[j] != 0))
			{
				if ((node->keys[i]) < (node->keys[j])) // ����������
				{
					m = node->keys[i];
					node->keys[i] = node->keys[j]; // ������ �������
					node->keys[j] = m;
				}
				else break;
			}
		}
	}
}

	void Tree::restruct(BNode *node) {
		if (node->Count<(2 * t - 1)) return;

		//������ ���
		BNode *child1 = new BNode;
		int j;
		for (j = 0; j <= t - 2; j++) child1->keys[j] = node->keys[j];
		for (j = t - 1; j <= (2 * t - 1); j++) child1->keys[j] = 0;
		child1->Count = t - 1; //���������� ������ � ����
		if (node->CountSons != 0) {
			for (int i = 0; i <= (t - 1); i++) {
				child1->children[i] = node->children[i];
				child1->children[i]->parent = child1;
			}
			for (int i = t; i <= (2 * t); i++) child1->children[i] = nullptr;
			child1->Leaf = false;
			child1->CountSons = t - 1; //���������� �������
		}
		else {
			child1->Leaf = true;
			child1->CountSons = 0;
			for (int i = 0; i <= (2 * t); i++) child1->children[i] = nullptr;
		}

		//������ ���
		BNode *child2 = new BNode;
		for (int j = 0; j <= (t - 1); j++) child2->keys[j] = node->keys[j + t];
		for (j = t; j <= (2 * t - 1); j++) child2->keys[j] = 0;
		child2->Count = t; //���������� ������ � ����
		if (node->CountSons != 0) {
			for (int i = 0; i <= (t); i++) {
				child2->children[i] = node->children[i + t];
				child2->children[i]->parent = child2;
			}
			for (int i = t + 1; i <= (2 * t); i++) child2->children[i] = nullptr;
			child2->Leaf = false;
			child2->CountSons = t; //���������� �������
		}
		else {
			child2->Leaf = true;
			child2->CountSons = 0;
			for (int i = 0; i <= (2 * t); i++) child2->children[i] = nullptr;
		}

		//��������
		if (node->parent == nullptr) { //���� �������� ���, �� ��� ������
		//	std::cout << node << " vs " << root << std::endl;
			node->keys[0] = node->keys[t - 1];
			for (int j = 1; j <= (2 * t - 1); j++) node->keys[j] = 0;
			node->children[0] = child1;
			node->children[1] = child2;
			for (int i = 2; i <= (2 * t); i++) node->children[i] = nullptr;
			node->parent = nullptr;
			node->Leaf = false;
			node->Count = 1;
			node->CountSons = 2;
			child1->parent = node;
			child2->parent = node;
		}
		else {
			insert_to_node(node->keys[t - 1], node->parent);
			for (int i = 0; i <= (2 * t); i++) {
				if (node->parent->children[i] == node) node->parent->children[i] = nullptr;
			}
			for (int i = 0; i <= (2 * t); i++) {
				if (node->parent->children[i] == nullptr) {
					for (int j = (2 * t); j>(i + 1); j--) node->parent->children[j] = node->parent->children[j - 1];
					node->parent->children[i + 1] = child2;
					node->parent->children[i] = child1;
					break;
				}
			}
			child1->parent = node->parent;
			child2->parent = node->parent;
			node->parent->Leaf = false;
			//delete node;
		}
	}

Tree::Tree()
{
	root = nullptr;
}


Tree::~Tree()
{
	if (root != nullptr)
		deletenode(root);
}
void Tree::insert_k(int key)
{
	if (root == nullptr) {
		BNode *newRoot = new BNode;
		newRoot->keys[0] = key;
		for (int j = 1; j <= (2 * t - 1); j++) newRoot->keys[j] = 0;
		for (int i = 0; i <= (2 * t); i++) newRoot->children[i] = nullptr;
		newRoot->Count = 1;
		newRoot->CountSons = 0;
		newRoot->Leaf = true;
		newRoot->parent = nullptr;
		root = newRoot;
	}
	else {
		BNode *ptr = root;
		while (ptr->Leaf == false) { //����� ������� �� ��� ���, ���� ���� �� ����� �������� ������
			for (int i = 0; i <= (2 * t - 1); i++) { //���������� ��� �����
				if (ptr->keys[i] != 0) {
					if (key<ptr->keys[i]) {
						ptr = ptr->children[i];
						break;
					}
					if ((ptr->keys[i + 1] == 0) && (key>ptr->keys[i])) {
						ptr = ptr->children[i + 1]; //�������������� � ������ ���������� �������, ���� ���� �� "��������"
						break;
					}
				}
				else break;
			}
		}
		insert_to_node(key, ptr);
		std::cout <<" key "<<key<< std::endl;;
		while (ptr->Count == 2 * t) {
			if (ptr == root) {
				restruct(ptr);
				break;
			}
			else {
				restruct(ptr);
				ptr = ptr->parent;
			}
		}
	}
}

bool Tree::search_k(int key)
{
	std::cout << "root capacity " << root->Count;// << " " << root;
	return searchKey(key, this->root);
}
void Tree::remove_k(int key)
{
	BNode *ptr = this->root;
	int position = NULL;
	int positionSon=NULL;
	int i = NULL;
	if (searchKey(key, ptr) == false)
	{
		return;
	}
	else {
		// ����� ����, � ������ ��������� ���� ��� ��������
		for (i = 0; i < ptr->Count - 1; i++)
		{
			if (ptr->keys[i] != 0)
			{
				if (key == ptr->keys[i]) // ��������������� �����, ���������� ��� ���
				{
					position = i;
					break;
				}
				else
				{
					if ((key < ptr->keys[i]))
					{
						ptr = ptr->children[i]; // ��� ������
						positionSon = i + 1;
						i = -1;
					}
				}
			}
			else break;
		}
	}
	if (ptr->Leaf == true) // �������� ����� �����
	{
		if (ptr->Count > (t - 1)) removeFromNode(key, ptr); // ������� ���� �� ����
		else removeLeaf(key, ptr);

	}
	else remove(key, ptr);
}
void Tree::deletenode(BNode *node)
{
	if (node != nullptr)
	{
		for (int i = 0; i <= (2 * t - 1); i++)
		{
			if (node->children[i] != nullptr) deletenode(node->children[i]); // ����������� �����, ���� �� ����� �� �����. ���� (��� ���)
			else
			{
				delete (node);
				break;
			}
		}
	}
}

bool Tree::searchKey(int key, BNode * node)
{
	if (node != nullptr) {
		if (node->Leaf == false) {
			int i;
			for (i = 0; i <= (2 * t - 1); i++) {
				if (node->keys[i] != 0) {
					if (key == node->keys[i]) return true;
					if ((key<node->keys[i])) {
						return searchKey(key, node->children[i]);
						break;
					}
				}
				else break;
			}
			return searchKey(key, node->children[i]);
		}
		else {
			for (int j = 0; j <= (2 * t - 1); j++)
				if (key == node->keys[j]) return true;
			return false;
		}
	}
	else return false;
}

void Tree::remove(int key, BNode * node)
{
	BNode *ptr = node;
	int position; //����� �����
	int i;
	for (int i = 0; i <= node->Count - 1; i++) {
		if (key == node->keys[i]) {
			position = i;
			break;
		}
	}
	int positionSon; //����� ���� �� ��������� � ��������
	if (ptr->parent != nullptr) {
		for (int i = 0; i <= ptr->parent->Count; i++) {
			if (ptr->children[i] == ptr) {
				positionSon == i;
				break;
			}
		}
	}
	//������� ���������� ���� ������� ���������
	ptr = ptr->children[position + 1];
	int newkey = ptr->keys[0];
	while (ptr->Leaf == false) ptr = ptr->children[0];
	//���� ������ � ��������� ����� �� ������ 1 - ���� ���������� ���� � ����� ���������
	//����� - ������ �������� key �� ����� ����, ������� ����� ���� �� �����
	if (ptr->Count>(t - 1)) {
		newkey = ptr->keys[0];
		removeFromNode(newkey, ptr);
		node->keys[position] = newkey;
	}
	else {
		ptr = node;
		//���� ���������� ���� � ����� ���������
		ptr = ptr->children[position];
		newkey = ptr->keys[ptr->Count - 1];
		while (ptr->Leaf == false) ptr = ptr->children[ptr->Count];
		newkey = ptr->keys[ptr->Count - 1];
		node->keys[position] = newkey;
		if (ptr->Count>(t - 1)) removeFromNode(newkey, ptr);
		else {
			//���� ������ �� ������, ��� t-1 - �������������
			removeLeaf(newkey, ptr);
		}
	}
}

void Tree::removeFromNode(int key, BNode * node)
{
	for (int i = 0; i<node->Count; i++) {
		if (node->keys[i] == key) {
			for (int j = i; j<node->Count; j++) {
				node->keys[j] = node->keys[j + 1];
				node->children[j] = node->children[j + 1];
			}
			node->keys[node->Count - 1] = 0;
			node->children[node->Count - 1] = node->children[node->Count];
			node->children[node->Count] = nullptr;
			break;
		}
	}
	node->Count--;
}

void Tree::removeLeaf(int key, BNode * node)
{
	if ((node == root) && (node->Count == 1)) {
		removeFromNode(key, node);
		root->children[0] = nullptr;
		delete root;
		root = nullptr;
		return;
	}
	if (node == root) {
		removeFromNode(key, node);
		return;
	}
	if (node->Count>(t - 1)) {
		removeFromNode(key, node);
		return;
	}
	BNode *ptr = node;
	int k1;
	int k2;
	int position;
	int positionSon;
	int i;
	for (int i = 0; i <= node->Count - 1; i++) {
		if (key == node->keys[i]) {
			position = i; //������� ����� � ����
			break;
		}
	}
	BNode *parent = ptr->parent;
	for (int j = 0; j <= parent->Count; j++) {
		if (parent->children[j] == ptr) {
			positionSon = j; //������� ���� �� ��������� � ��������
			break;
		}
	}
	//���� ptr-������ ������� (����� �����)
	if (positionSon == 0) {
		if (parent->children[positionSon + 1]->Count>(t - 1)) { //���� � ������� ����� ������, ��� t-1 ������
			k1 = parent->children[positionSon + 1]->keys[0]; //k1 - ����������� ���� ������� �����
			k2 = parent->keys[positionSon]; //k2 - ���� ��������, ������, ��� ���������, � ������, ��� k1
			insert_to_node(k2, ptr);
			removeFromNode(key, ptr);
			parent->keys[positionSon] = k1; //������ ������� k1 � k2
			removeFromNode(k1, parent->children[positionSon + 1]); //������� k1 �� ������� �����
		}
		else { //���� � ������� <u>�������������</u> ����� �� ������ t-1 ������		
			removeFromNode(key, ptr);
			if (ptr->Count <= (t - 2)) repair(ptr);
		}
	}
	else {
		//���� ptr-��������� ������� (����� ������)
		if (positionSon == parent->Count) {
			//���� � ������ ����� ������, ��� t-1 ������
			if (parent->children[positionSon - 1]->Count>(t - 1)) {
				BNode *temp = parent->children[positionSon - 1];
				k1 = temp->keys[temp->Count - 1]; //k1 - ������������ ���� ������ �����
				k2 = parent->keys[positionSon - 1]; //k2 - ���� ��������, ������, ��� ��������� � ������, ��� k1
				insert_to_node(k2, ptr);
				removeFromNode(key, ptr);
				parent->keys[positionSon - 1] = k1;
				removeFromNode(k1, temp);
			}
			else { //���� � <u>�������������</u> ������ ����� �� ������ t-1 ������
				removeFromNode(key, ptr);
				if (ptr->Count <= (t - 2)) repair(ptr);
			}
		}
		else { //���� ptr ����� ������� ������ � �����
			   //���� � ������� ����� ������, ��� t-1 ������
			if (parent->children[positionSon + 1]->Count>(t - 1)) {
				k1 = parent->children[positionSon + 1]->keys[0]; //k1 - ����������� ���� ������� �����
				k2 = parent->keys[positionSon]; //k2 - ���� ��������, ������, ��� ��������� � ������, ��� k1
				insert_to_node(k2, ptr);
				removeFromNode(key, ptr);
				parent->keys[positionSon] = k1; //������ ������� k1 � k2
				removeFromNode(k1, parent->children[positionSon + 1]); //������� k1 �� ������� �����
			}
			else {
				//���� � ������ ����� ������, ��� t-1 ������
				if (parent->children[positionSon - 1]->Count>(t - 1)) {
					BNode *temp = parent->children[positionSon - 1];
					k1 = temp->keys[temp->Count - 1]; //k1 - ������������ ���� ������ �����
					k2 = parent->keys[positionSon - 1]; //k2 - ���� ��������, ������, ��� ��������� � ������, ��� k1
					insert_to_node(k2, ptr);
					removeFromNode(key, ptr);
					parent->keys[positionSon - 1] = k1;
					removeFromNode(k1, temp);
				}
				else { //���� � ����� ������� �� ������ t-1 ������
					removeFromNode(key, ptr);
					if (ptr->Count <= (t - 2)) repair(ptr);
				}
			}
		}
	}

}

void Tree::lconnect(BNode * node, BNode * othernode)
{
	if (node == nullptr) return;
	for (int i = 0; i <= (othernode->Count - 1); i++) {
		node->keys[node->Count] = othernode->keys[i];
		node->children[node->Count] = othernode->children[i];
		node->Count = node->Count + 1;
	}
	node->children[node->Count] = othernode->children[othernode->Count];
	for (int j = 0; j <= node->Count; j++) {
		if (node->children[j] == nullptr) break;
		node->children[j]->parent = node;
	}
	delete othernode;
}

void Tree::rconnect(BNode * node, BNode * othernode)
{
	if (node == nullptr) return;
	for (int i = 0; i <= (othernode->Count - 1); i++) {
		node->keys[node->Count] = othernode->keys[i];
		node->children[node->Count + 1] = othernode->children[i + 1];
		node->Count = node->Count + 1;
	}
	for (int j = 0; j <= node->Count; j++) {
		if (node->children[j] == nullptr) break;
		node->children[j]->parent = node;
	}
	delete othernode;
}

void Tree::repair(BNode * node)
{
	if ((node == root) && (node->Count == 0)) {
		if (root->children[0] != nullptr) {
			root->children[0]->parent = nullptr;
			root = root->children[0];
		}
		else {
			delete root;
		}
		return;
	}
	BNode *ptr = node;
	int k1;
	int k2;
	int positionSon;
	BNode *parent = ptr->parent;
	for (int j = 0; j <= parent->Count; j++) {
		if (parent->children[j] == ptr) {
			positionSon = j; //������� ���� �� ��������� � ��������
			break;
		}
	}
	//���� ptr-������ ������� (����� �����)
	if (positionSon == 0) {
		insert_to_node(parent->keys[positionSon], ptr);
		lconnect(ptr, parent->children[positionSon + 1]);
		parent->children[positionSon + 1] = ptr;
		parent->children[positionSon] = nullptr;
		removeFromNode(parent->keys[positionSon], parent);
		if (ptr->Count == 2 * t) {
			while (ptr->Count == 2 * t) {
				if (ptr == root) {
					restruct(ptr);
					break;
				}
				else {
					restruct(ptr);
					ptr = ptr->parent;
				}
			}
		}
		else
			if (parent->Count <= (t - 2)) repair(parent);
	}
	else {
		//���� ptr-��������� ������� (����� ������)
		if (positionSon == parent->Count) {
			insert_to_node(parent->keys[positionSon - 1], parent->children[positionSon - 1]);
			lconnect(parent->children[positionSon - 1], ptr);
			parent->children[positionSon] = parent->children[positionSon - 1];
			parent->children[positionSon - 1] = nullptr;
			removeFromNode(parent->keys[positionSon - 1], parent);
			BNode *temp = parent->children[positionSon];
			if (ptr->Count == 2 * t) {
				while (temp->Count == 2 * t) {
					if (temp == root) {
						restruct(temp);
						break;
					}
					else {
						restruct(temp);
						temp = temp->parent;
					}
				}
			}
			else
				if (parent->Count <= (t - 2)) repair(parent);
		}
		else { //���� ptr ����� ������� ������ � �����
			insert_to_node(parent->keys[positionSon], ptr);
			lconnect(ptr, parent->children[positionSon + 1]);
			parent->children[positionSon + 1] = ptr;
			parent->children[positionSon] = nullptr;
			removeFromNode(parent->keys[positionSon], parent);
			if (ptr->Count == 2 * t) {
				while (ptr->Count == 2 * t) {
					if (ptr == root) {
						restruct(ptr);
						break;
					}
					else {
						restruct(ptr);
						ptr = ptr->parent;
					}
				}
			}
			else
				if (parent->Count <= (t - 2)) repair(parent);
		}
	}
}
