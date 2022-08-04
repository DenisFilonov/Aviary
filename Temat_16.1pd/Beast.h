#pragma once
#include "Animal.h"

class Beast :
    public Animal
{
protected:
    string habitat;
    bool isdomestic;

public:
    Beast();
    Beast(string name, bool ispredator, string habitat, bool isdomestic);
    virtual ~Beast() override;

    void setHabitat(string habitat);
    void setIsDomestic(bool isdomestic);

    string getHabitat()const&;
    bool getIsDomestic()const&;


    virtual void show()const override;
    virtual string type()const override;
};

