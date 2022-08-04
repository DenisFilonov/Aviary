#include "Beast.h"

Beast::Beast()
{
    name = "Wolf";
    ispredator = true;
    habitat = "Forest";
    isdomestic = false;
}

Beast::Beast(string name, bool ispredator, string habitat, bool isdomestic) :
    Animal(name, ispredator)
{
    this->habitat = habitat;
    this->isdomestic = isdomestic;
}

Beast::~Beast()
{
}

void Beast::setHabitat(string habitat)
{
    this->habitat = habitat;
}

void Beast::setIsDomestic(bool isdomestic)
{
    this->isdomestic = isdomestic;
}

string Beast::getHabitat() const&
{
    return habitat;
}

bool Beast::getIsDomestic() const&
{
    return isdomestic;
}

void Beast::show() const
{
    //добавить потом сюда тернарный оператор
    cout << "\nType: " << type();
    cout << "\nName: " << name;
    cout << "\nPredator: "; (ispredator) ? cout << "Yes" : cout << "No";
    cout << "\nHabitat: " << habitat;
    cout << "\nCan be domestic animal: "; (isdomestic) ? cout << "Yes\n" : cout << "No\n";
}

string Beast::type() const
{
    return "Beast";
}
