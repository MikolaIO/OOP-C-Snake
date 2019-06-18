#include <iostream>
#include <conio.h>
#include <dos.h>
#include <ctime>
#include "Point.h"
#include "Snake.h"

int main()
{
    srand(time(NULL));
    Snake snake;
    snake.Hidecursor();
    char op = 'l';
    do
    {
        if(kbhit())
        {
            op = getch();
        }

        switch(op)
        {
        case 'w':
        case 'W':
            snake.TurnUp();
            break;

        case 's':
        case 'S':
            snake.TurnDown();
            break;

        case 'a':
        case 'A':
            snake.TurnLeft();
            break;

        case 'd':
        case 'D':
            snake.TurnRight();
            break;
        }
        snake.Move();


    }while(op != 'e');


    return 0;
}
