//
//  Food.cpp
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include "Food.h"

Food::Food() : gen(std::random_device()())
{
    generateNewFoodPos();
}

void Food::generateNewFoodPos()
{
    std::uniform_int_distribution<> xRand(0, getmaxx(stdscr));
    foodPos.first = xRand(gen);
    std::uniform_int_distribution<> yRand(0, getmaxy(stdscr));
    foodPos.second = yRand(gen);
}

void Food::didEat(Snake &gameSnake)
{
    if (gameSnake.getPos() == foodPos)
    {
        generateNewFoodPos();
        GameManager::addPoint();
    }
    else
    {
        gameSnake.removeTail();
    }
}

void Food::redraw()
{
    mvaddch(foodPos.second, foodPos.first, 'X');
}