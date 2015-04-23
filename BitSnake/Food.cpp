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
    std::uniform_int_distribution<> xRand(2, getmaxx(stdscr) - 2);
    foodPos.first = xRand(gen);
    std::uniform_int_distribution<> yRand(2, getmaxy(stdscr) - 2);
    foodPos.second = yRand(gen);
}

std::pair<int, int> Food::getFoodPos()
{
    return foodPos;
}

void Food::redraw()
{
    mvaddch(foodPos.second, foodPos.first, 'X');
}

bool Food::wasEatenBy(Snake &sn)
{
    return sn.getPos() == getFoodPos();
}