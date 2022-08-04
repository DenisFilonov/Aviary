#pragma once
#include<iostream>
#include<string>

using namespace std;

class Animal
{
protected:
	string name;
	bool ispredator;

public:
	Animal();
	Animal(string name, bool ispredator);
	virtual ~Animal();

	void setName(string name);
	void setIsPredator(bool ispredator);

	string getName()const&;
	bool getIsPredator()const&;

	//=================================================================
	virtual void show()const = 0;
	virtual string type()const = 0;
};

bool upType(const Animal* a, const Animal* b);
bool dwType(const Animal* a, const Animal* b);