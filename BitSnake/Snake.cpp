//
//  Snake.cpp
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include "Snake.h"

Snake::Snake()
{

    for (int i = 0; i < 5; i++)
        snakes.push_front(std::make_pair(3 + i, 3));
}

std::pair<int, int> Snake::getPos()
{
    return snakes.front();
}

void Snake::removeTail()
{
    snakes.pop_back();
}

void Snake::addHead(std::pair<int, int> pos)
{
    snakes.push_front(pos);
}

bool Snake::successfulDraw(std::pair<int, int> cur)
{
    for (auto it = snakes.begin(); it != snakes.end(); it++)
    {
        mvaddch((*it).second, (*it).first, '*');
        if ((*it).second == cur.second && (*it).first == cur.first && it != snakes.begin()) // collision with snake
            return false;
    }
    return true;
}