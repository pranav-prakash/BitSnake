//
//  Snake.h
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#ifndef __BitSnake__Snake__
#define __BitSnake__Snake__

#include <list>
#include <ncurses.h>

class Snake
{
private:
    /// Pair stores x, y coordinates of each of the segments
    std::list<std::pair<int, int>> segments;

    int direction;

    void updateHead(std::pair<int, int> pos)
    {
        segments.push_front(pos);
    }

    /// Direction of snake : 1 is up, 2 is right, 3 is down, 4 is left
    int getDirection()
    {
        return direction;
    }

public:
    Snake();

    /// Returns position of snake head
    std::pair<int, int> getPos()
    {
        return segments.front();
    }

    void updateTail()
    {
        segments.pop_back();
    }

    void setDirection(int newDir)
    {
        direction = newDir;
    }

    void updatePosition();
    bool isOutOfBounds();
    bool successfulDraw();
};

#endif /* defined(__BitSnake__Snake__) */
