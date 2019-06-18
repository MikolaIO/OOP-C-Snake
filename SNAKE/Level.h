#pragma once

class Level
{
    friend class Snake;
    int speed;

    void drawLevel();

public:

    Level();

    void speedIncrease();
    void moveSpeed();
};
