#pragma once
#include<iostream>
#include<string>

using namespace std;
/*Описать абстрактный класс ZooException c виртуальным методом string showMessage();

a.Реализовать собственные классы наследники PredatorException и MaxCapacityException от ZooException. 
В методе «добавить животное» в классе Клетка при попытке добавить хищника в клетку, где уже содержатся не хищные животные выбрасывать  Exception типа PredatorException.  
В методе «добавить животное» в классе Клетка при попытке добавить больше чем макс. количество животных животные выбрасывать  Exception типа MaxCapacityException.  
При возникновении Exception выводить сообщение об ошибке на экран.
В основной программе (main) проверить работу блока обработки Exception метода «добавить животное» класса Клетка.
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

class NameException : public AviaryException
{
public:
	virtual void showMessage()override
	{
		cout << "\nWarning! Name wasn't set!\n\n";
	}
};