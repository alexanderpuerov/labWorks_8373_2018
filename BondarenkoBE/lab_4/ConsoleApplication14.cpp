// ConsoleApplication14.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

double my_power(double dig, int pow)
{
	double answer = 1;
	if (pow > 0)
	for (int i = 1; i <= pow; i++)
		{
			answer *= dig;
		}
	else
		for (int i = pow; i < 0; i++)
		{
			answer /= dig;
		}
	return answer;
}

int my_fact(int dig)
{
	int answer = 1;
	for (int i = 2; i <= dig; i++)
	{
		answer *= i;
	}
	return answer;
}

double my_root(double dig)
{
	if (dig == 0)
		return 0;
	double answer = dig;
	for (int i = 1; i <= 10; i++)
	{
		answer = 0.5*(answer + dig / answer);
	}
	return answer;
}

int nod(int a, int b) {
	if (b == 0)
		return a;
	return nod(b, a%b);
}

bool my_prime(int prm)
{
	for (int a = 1; a <= prm / 2; a++)
	{
		if (nod(a, prm) != 1)
			continue;
		if ((((int)my_power(a, prm - 1) - 1) % prm) != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(0, "");
	cout << "1 - ���������� � �������, 2 - ���������, 3 - ������ ����������, 4 - �������� �� ��������: ";
	cout.flags(8192);
	cout.unsetf(16);
	int chs=0;
	double dig1;
	int digN;
	while ((chs != 1) && (chs != 2) && (chs != 3) && (chs != 4))
	{
		cin >> chs;
		switch (chs)
		{
		case 1:
			cout << "������� ��������� (�����, ���������� � �������): ";
			cin >> dig1;
			cout << "������� ������� (�����): ";
			cin >> digN;
			while ((dig1 == 0) && (digN == 0))
			{
				cout << "���� � ������� ������� ��������� ����������. ������� ������ ��������" << endl;
				cout << "������� ��������� (�����, ���������� � �������): ";
				cin >> dig1;
				cout << "������� ������� (�����): ";
				cin >> digN;
			}
			if ((my_power(dig1, digN) - (long long int)my_power(dig1, digN)) == 0)
				cout << "�����: " << (long long int)my_power(dig1, digN);
			else
				cout << "�����: " << my_power(dig1, digN);
			break;
		case 2:
			cout << "������� ��������� ���������� (��������������� �����): ";
			cin >> digN;
			cout << "�����: " << my_fact(digN);
			break;
		case 3:
			cout << "������� ����� ��� ������ (���������������): ";
			cin >> dig1;
			if ((my_root(dig1) - (long long int)my_root(dig1)) == 0)
				cout << "�����: " << (long long int)my_root(dig1);
			else
				cout << "�����: " << my_root(dig1);
			break;
		case 4:
			cout << "������� ����������� ����� (�����, �� 12 ������������): ";
			cin >> digN;
			if (my_prime(digN))
			{
				cout << "�����: " << digN << " - �������";
			}
			else
			{
				cout << "�����: " << digN << " - ���������";
			}
			break;
		default:
			cout << "������� ���������� �����: ";
		}
	}
	_getch();
    return 0;
}

