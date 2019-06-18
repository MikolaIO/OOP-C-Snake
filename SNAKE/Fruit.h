#pragma once
#include "Point.h"

class Fruit : public Point
{
    public:

        void setFruit();

        virtual void drawFruit(){};
};

class Fruit1 : public Fruit
{

public:
    Fruit1();

    void drawFruit();


};

class Fruit2 : public Fruit
{

public:
    Fruit2();

    void drawFruit();
};

