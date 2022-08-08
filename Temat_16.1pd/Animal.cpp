#include "Animal.h"

Animal::Animal()
{
    name = "Undefenied";
    ispredator = false;
}


Animal::Animal(string name, bool ispredator)
{
    if (name.size() == 0) throw new NameException();
    this->name = name;
    this->ispredator = ispredator;
}


Animal::~Animal()
{
}

void Animal::setName(string name)
{
    if (name.size() == 0) throw new NameException();
    this->name = name;
}

void Animal::setIsPredator(bool ispredator)
{
    this->ispredator = ispredator;
}

string Animal::getName() const&
{
    return name;
}

bool Animal::getIsPredator() const&
{
    return ispredator;
}



//================================================================================
bool upType(const Animal* a, const Animal* b)
{
    return a->type() < b->type();
}

bool dwType(const Animal* a, const Animal* b)
{
    return !upType(a,b);
}
