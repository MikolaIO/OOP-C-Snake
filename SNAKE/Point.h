#pragma once
#include <iostream>
#define MAXFRAMEX 50
#define MAXFRAMEY 20

class Point
{
    int x, y;

public:

    Point();

    Point(int x, int y);

    void SetPoint(int x, int y);

    int GetX();
    int GetY();

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void Draw(char ch = 'O');

    void Erase();

    void CopyPos(Point * p);

    int IsEqual(Point * p);

    void Debug();


};
