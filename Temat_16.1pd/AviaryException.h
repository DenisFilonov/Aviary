#pragma once
#include<iostream>
#include<string>

using namespace std;
/*������� ����������� ����� ZooException c ����������� ������� string showMessage();

a.����������� ����������� ������ ���������� PredatorException � MaxCapacityException �� ZooException. 
� ������ ��������� �������� � ������ ������ ��� ������� �������� ������� � ������, ��� ��� ���������� �� ������ �������� �����������  Exception ���� PredatorException.  
� ������ ��������� �������� � ������ ������ ��� ������� �������� ������ ��� ����. ���������� �������� �������� �����������  Exception ���� MaxCapacityException.  
��� ������������� Exception �������� ��������� �� ������ �� �����.
� �������� ��������� (main) ��������� ������ ����� ��������� Exception ������ ��������� �������� ������ ������.
*/


class AviaryException
{
public:
	virtual void showMessage() = 0;
};

class PredatorException : public AviaryException
{
public:
	virtual void showMessage()override
	{
		cout << "\nWarning! Do not put predators in aviary with non-predators, or non-predators to predators!\n\n";
	}
};

class MaxCapacityException : public AviaryException
{
public:
	virtual void showMessage()override
	{
		cout << "\nWarning! The capacity of aviary is overload!\n\n";
	}
};