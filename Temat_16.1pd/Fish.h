#pragma once
#include "Animal.h"

class Fish :
    public Animal
{
protected:
    bool isdeepseafish;

public:
    Fish();
    Fish(string name, bool ispredator, bool isdeepseafish);
    virtual ~Fish() override;

    void setIsDeepSeaFish(bool isdeepseafish);
    bool getIsDeepSeaFish()const&;

    virtual void show()const override;
    virtual string type()const override;
};

