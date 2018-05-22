#include "List.h"
#include "Item.h"
#include <stddef.h>
#include <iostream>
#include "Data.h"

void List::Add(Data *data)
{
	
	 
	 Item *item = new Item(data);
	 if (this->Cout > 0) // ���� ������ ����� ���� �� ����� �������
	 {
		 Item *lastMax = Head;
		 Item *temp = Head;
		 Item *previous = Head;
		 do {
			 // ������������ ��������� ������� � �����������
			 // � ���������� ��������� � ���������
			 if (temp->data->value <= item->data->value
				 && previous->data->value < temp->data->value)
			 {
				 lastMax = temp; // ���������� ������� (������������� ����) ��������� �� ������������
			 }
			 previous = temp; // ������� ����� temp ������ ��������� �� temp
			 temp = temp->next;// ��������� � ����. ��-�� ������
		 } while (temp != this->Head && temp != nullptr);
		 item->next = lastMax->next; // ������� �������� 
		 lastMax->next = item;
		 // ���� item ������ ����. �������� � ����. ��-� ������, �� item ��������� ��-�
		 if (item->data->value < item->next->data->value && item->next == this->Head)
		 {
			 Head = item;
		 }
	 }
	 else 
	 {
		 Head = item;
		 Head->next = item;
	 }
	
	 setCout(getCout() + 1);
	} 	

void List::sort_list()
{
	Item *item = Head;
	if (item->data->key > item->next->data->key)
	{
		Head->next = item->next;
		item->next = Head;
	}
}
List::List()
{
	Head = NULL;
	setCout(0);
}
List::~List()
{
	while (Cout != 0)
	{
		//delete (Head); delete(Tail);
	}

}
void List::Show(int x)
{
	Item *t_head = Head;
	
	for (int i=0;i<getCout();i++)
	{
		std::cout << t_head->data->value << " ";
		t_head = t_head->next;
		
	}
}
void List::Search(int x)
{
	x = x - 1;
	if (x <= getCout() && (Head != NULL) && (x >= 0))
	{
		Item *previous = Head;

		for (int i = 0; i < x; i++)
		{
			Head = previous; 
			previous = previous->next;
		}
	std::cout<<"������� ������: "<< previous->data->value <<std::endl ;
	}
	
}
int List::getCout()
{
	return Cout;
}
void List::setCout(int x)
{
	Cout = x;
}
void List::Delete(int x)
{
	x = x-1;
	if (x <=getCout()&&(Head!=NULL)&&(x>=0))
	{
		Item *previous = Head;
		
		
		for (int i = 0; i <x; i++)
		{
			Head = previous; // ����������
			previous= previous->next; // ���������
		}
		if ( previous == Head) // ���� ��������� �������� �������
		{
			Head = previous -> next;
		}
		else
		{
			Head->next = previous->next;
		}
		
		std::cout << "Delete " << previous->data->value<<std::endl;

		delete(previous);
		setCout(getCout()-1);
	}
	
}
void Print_el(int x)
	{
		std::cout << x << std::endl;
	}