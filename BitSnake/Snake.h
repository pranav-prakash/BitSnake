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
    std::list<std::pair<int, int>> snakes;

public:
    Snake();

    std::pair<int, int> getPos();

    void removeTail();

    void addHead(std::pair<int, int> pos);

    bool successfulDraw(std::pair<int, int> cur);
};

#endif /* defined(__BitSnake__Snake__) */
