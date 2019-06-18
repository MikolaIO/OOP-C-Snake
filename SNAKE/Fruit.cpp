#include "Fruit.h"

void Fruit::setFruit()
{
    this->SetPoint(rand()%MAXFRAMEX, rand()%MAXFRAMEY);
}

Fruit1::Fruit1()
{
    this->setFruit();
}

void Fruit1::drawFruit()
{
    Draw('*');
}

Fruit2::Fruit2()
{
    this->setFruit();
}

void Fruit2::drawFruit()
{
    Draw('$');
}

