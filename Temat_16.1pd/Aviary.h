#pragma once
#include "Beast.h"
#include "Bird.h"
#include "Fish.h"
#include "AviaryException.h"


class Aviary
{
protected:
	Animal** arr;
	int size;
	int maxamountincage;

public:
	Aviary();
	Aviary(int maxamountincage);
	~Aviary();

	int getSize()const&;
	void addAnimal(Animal* an);
	void removeAnimal(string name);
	void editAnimalsInfo(string name)const&;
	void editAnimalsInfoByID(int id)const&;

	void showAviary()const&;
	int findAnimalByName(string name)const&;
	void showCurrentType(string type)const&;
	void showAnimalByName(string name)const&;

	void sort(bool(*cmp)(const Animal*, const Animal*))const&;
};