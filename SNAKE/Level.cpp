#include "Level.h"
#include "Point.h"
#include <windows.h>
#include <iostream>

using namespace std;


    void Level::drawLevel()
    {
    for (int i = 0; i < MAXFRAMEX+2; i++)
        cout << "#";
    cout << endl;
    for (int i = 0; i < MAXFRAMEY; i++)
    {
        for (int j = 0; j < MAXFRAMEX; j++)
        {
            if (j == 0)
                cout << "#";
                bool print = false;
                if (!print)
                    cout << " ";
                if (j == MAXFRAMEX - 1)
                    cout << "#";
        }
        cout << endl;

    }
    for (int i = 0; i < MAXFRAMEX+2; i++)
        cout << "#";
    cout << endl;
    }

    Level::Level()
    {
        speed = 30;
    }


    void Level::speedIncrease()
    {
        if(speed > 5)
        speed--;
    }
    void Level::moveSpeed()
    {
        Sleep(speed);
    }
