#include "Vibor_pers.h"
#include "iostream"

using namespace std;

void Vibor_pers::vibor_pers()
{
	cout << "������� �������, ���� (������� m)  ��� ����� (������� v)" << endl;
	scanf("%c", &M);
	while ((M != 'm') || (M != 'v'))
	{
		if (M == 'm')
		{
			cout << "�� ������� ����. ������������ ������ ������� ���� ������� �������� ���� �������� ����� '�������� ������' " << endl;
			break;
		}
		else if (M == 'v')
		{
			cout << "�� ������� �����. ����� ���� ������� ������� �������, ��������� ���������� �������� ���� � ������ ��� �������� �� ��� '������ ��������' " << endl;
			break;
		}
		else
		{
			cout << "ERROR" << endl;

		}
	}
}
