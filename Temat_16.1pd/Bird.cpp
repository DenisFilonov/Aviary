#include "Bird.h"

Bird::Bird()
{
    name = "Sparrow";
    ispredator = false;
    speed = 14.2;
    isflying = true;
}

Bird::Bird(string name, bool ispredator, float speed, bool isflying) : Animal(name,ispredator)
{
    this->speed = speed;
    this->isflying = isflying;
}

Bird::~Bird()
{
}

void Bird::setSpeed(float speed)
{
    this->speed = speed;
}

void Bird::setFlying(float isflying)
{
    this->isflying = isflying;
}

float Bird::getSpeed() const&
{
    return speed;
}

bool Bird::getIsFlying() const&
{
    return isflying;
}


void Bird::show() const
{
    //добавить потом сюда тернарный оператор
    cout << "\nType: " << type();
    cout << "\nName: " << name;
    cout << "\nPredator: "; (ispredator) ? cout << "Yes" : cout << "No";
    cout << "\nSpeed: " << speed;
    cout << "\nType of bird: "; (isflying) ? cout << "Flying\n" : cout << "Walking\n";
}

string Bird::type() const
{
    return "Bird";
}
