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
    {
        segments.push_front(std::make_pair(3 + i, 3));
    }

    setDirection(2);
}

/// Returns position of snake head
std::pair<int, int> Snake::getPos()
{
    return segments.front();
}

void Snake::updateTail()
{
    segments.pop_back();
}

void Snake::updateHead(std::pair<int, int> pos)
{
    segments.push_front(pos);
}

bool Snake::successfulDraw()
{
    std::pair<int, int> curPos = getPos();
    int curX = curPos.first;
    int curY = curPos.second;

    for (auto it = segments.begin(); it != segments.end(); it++)
    {
        mvaddch((*it).second, (*it).first, '*');
        if ((*it).second == curY && (*it).first == curX && it != segments.begin()) // collision with snake
            return false;
    }
    return true;
}

bool Snake::isOutOfBounds()
{
    std::pair<int, int> curPos = getPos();
    int curX = curPos.first;
    int curY = curPos.second;

    return (curY > getmaxy(stdscr) || curX > getmaxx(stdscr) || curY < 0 || curX < 0);
}

void Snake::updatePosition()
{
    std::pair<int, int> curPos = getPos();
    int curX = curPos.first;
    int curY = curPos.second;

    switch (getDirection())
    {
        case 1:
            curY--;
            break;
        case 2:
            curX++;
            break;
        case 3:
            curY++;
            break;
        case 4:
            curX--;
            break;
    }

    updateHead(std::make_pair(curX, curY));
}


/// Direction of snake : 1 is up, 2 is right, 3 is down, 4 is left
int Snake::getDirection()
{
    return direction;
}

void Snake::setDirection(int newDir)
{
    direction = newDir;
}
