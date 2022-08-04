#include "Fish.h"

Fish::Fish()
{
    name = "Betta mahachaiensis";
    ispredator = false;
    isdeepseafish = false;
}

Fish::Fish(string name, bool ispredator, bool isdeepseafish) : Animal(name,ispredator)
{
    this->isdeepseafish = isdeepseafish;
}

Fish::~Fish()
{
}

void Fish::setIsDeepSeaFish(bool isdeepseafish)
{
    this->isdeepseafish = isdeepseafish;
}

bool Fish::getIsDeepSeaFish() const&
{
    return isdeepseafish;
}

void Fish::show() const
{
    cout << "\nType: " << type();
    cout << "\nName: " << name;
    cout << "\nPredator: "; (ispredator) ? cout << "Yes" : cout << "No";
    cout << "\nDeep sea fish: "; (isdeepseafish) ? cout << "Yes\n" : cout << "No\n";
}

string Fish::type() const
{
    return "Fish";
}
