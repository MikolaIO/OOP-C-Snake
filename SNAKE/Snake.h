#pragma once
#define MAXSNAKESIZE 100
#include "Point.h"
#include "Fruit.h"
#include "Level.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Snake : public Fruit
{
    Point * cell[MAXSNAKESIZE];
    int size; //aktualny romiar wê¿a
    char dir; //aktualny kierunek wê¿a
    int state;
    int started;
    int random; //losowanie owocu

    Fruit1 f1;
    Fruit2 f2;
    Level l1;


public:

    Snake();


    void AddCell(int x, int y);

    void snakeDraw();

    void TurnUp();

    void TurnDown();

    void TurnLeft();

    void TurnRight();

    void WelcomeScreen();


    void Move();

    void randomize();

    int SelfCollision();

    void FruitCollision();

    void Debugs();

    void Hidecursor();

};
