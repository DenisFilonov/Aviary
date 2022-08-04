#pragma once
#include "Animal.h"

class Bird :
    public Animal
{
protected:
    float speed;
    bool isflying;

public:
    Bird();
    Bird(string name, bool ispredator, float speed, bool isflying);
    virtual ~Bird()override;

    void setSpeed(float speed);
    void setFlying(float isflying);

    float getSpeed()const&;
    bool getIsFlying()const&;

    virtual void show()const override;
    virtual string type()const override;
};

