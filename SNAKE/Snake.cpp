#include "Snake.h"


    Snake::Snake()
    {
        size = 1;
        random = 0;
        cell[0] = new Point(20, 20); //domyœlna pozycja
        for( int i=1; i<MAXSNAKESIZE; i++)
        {
            cell[i] = NULL;
        }
        state = 0;
        started = 0;
    }

    void Snake::AddCell(int x, int y)
    {
        cell[size++] = new Point(x, y);
    }

    void Snake::snakeDraw()
    {
        for (int i=0; i<size; i++)
            cell[i]->Draw();
    }

    void Snake::TurnUp()
    {
        if( dir!='s')
        dir = 'w';
    }

    void Snake::TurnDown()
    {
        if( dir!='w')
        dir = 's';
    }

    void Snake::TurnLeft()
    {
        if( dir!='d')
        dir = 'a';
    }

    void Snake::TurnRight()
    {
        if( dir!='a')
        dir = 'd';
    }

    void Snake::WelcomeScreen()
    {
        SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), 15);
        cout << "\n       ---_ ......._-_--.";
        cout << "\n      (|\\ /      / /| \\  \\";
        cout << "\n      /  /     .'  -=-'   `.";
        cout << "\n     /  /    .'             )";
        cout << "\n   _/  /   .'        _.)   /";
        cout << "\n  / o   o        _.-' /  .'                   Rules";
        cout << "\n  \\          _.-'    / .'*|";
        cout << "\n   \\______.-'//    .'.' \\*|           # - gives one point";
        cout << "\n    \\|  \\ | //   .'.' _ |*|           $ - gives two points";
        cout << "\n     `   \\|//  .'.'_ _ _|*|          Only your tail can hurt!";
        cout << "\n      .  .// .'.' | _ _ \\*|";
        cout << "\n      \\`-|\\_/ /    \\ _ _ \\*\\";
        cout << "\n       `/'\\__/      \\ _ _ \\*\\";
        cout << "\n      /^|            \\ _ _ \\*";
        cout << "\n     '  `             \\ _ _ \\ ";
        cout << "\n                       \\_";

    }


    void Snake::Move()
    {

        system("cls");

        if( state == 0)
        {
            if( !started )
            {
            WelcomeScreen();
            cout << "Press any key to start";
            getch();
            started = 1;
            state = 1;
            }
            else
            {
            cout << "Game Over" << endl;
            cout << "Your score: " << size << endl;
            cout << "Press any key to start";
            getch();
            state = 1;
            size = 1;
            }
        }

        //pod¹¿anie cia³a wê¿a za g³ow¹
        for(int i=size-1; i>0; i--)
        {
            cell[i-1]->CopyPos(cell[i]);
        }

        switch(dir)
        {
        case 'w':
            cell[0]->MoveUp();
            break;
        case 's':
            cell[0]->MoveDown();
            break;
        case 'a':
            cell[0]->MoveLeft();
            break;
        case 'd':
            cell[0]->MoveRight();
            break;
        }

        if( SelfCollision())
        state = 0;

        FruitCollision();
        l1.drawLevel();
        snakeDraw();
        if (random==0)
        f1.drawFruit();
        if (random==1)
        f2.drawFruit();
        l1.moveSpeed();



    }

    void Snake::randomize()
    {
        random=rand()%2;
    }

    int Snake::SelfCollision()
    {
        for( int i = 1; i < size; i++)
            if( cell[0]->IsEqual(cell[i]))
            return 1;
        return 0;
    }

    void Snake::FruitCollision()
    {
        if( f1.GetX() == cell[0]->GetX() && f1.GetY() == cell[0]->GetY())
        {
            if ( random == 0 )
            {
            AddCell(0, 0);
            randomize();
            f1.setFruit();
            l1.speedIncrease();
            }
        }
        else
        if( f2.GetX() == cell[0]->GetX() && f2.GetY() == cell[0]->GetY())
        {
            if ( random == 1 )
            {
            AddCell(0, 0);
            AddCell(0, 0);
            randomize();
            f2.setFruit();
            l1.speedIncrease();
            }
        }
    }

    void Snake::Debugs()
    {

        for(int i=0; i<size; i++)
        {
            cell[i]->Debug();
        }
    }

    void Snake::Hidecursor()
    {

       HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_CURSOR_INFO info;
       info.dwSize = 100;
       info.bVisible = FALSE;
       SetConsoleCursorInfo(consoleHandle, &info);
    }


