//
//  Food.h
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#ifndef __BitSnake__Food__
#define __BitSnake__Food__

#include <utility>
#include <ncurses.h>
#include <random>

class GameManager;

#include "Snake.h"

class Food
{
private:
    std::pair<int, int> foodPos;
    std::mt19937 gen;

public:
    Food();

    void generateNewFoodPos();
    std::pair<int, int> getFoodPos();
    void redraw();

    bool wasEatenBy(Snake &sn);
};

#endif /* defined(__BitSnake__Food__) */
