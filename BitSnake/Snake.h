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

    void updateHead(std::pair<int, int> pos);

public:
    Snake();

    std::pair<int, int> getPos();

    void updatePosition();

    bool isOutOfBounds();

    bool successfulDraw();

    int getDirection();
    
    void updateTail();
    
    void setDirection(int newDir);
};

#endif /* defined(__BitSnake__Snake__) */
