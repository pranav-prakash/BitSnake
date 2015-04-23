//
//  GameManager.h
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#ifndef __BitSnake__GameManager__
#define __BitSnake__GameManager__

#include <ncurses.h>
#include <time.h>

#include "Food.h"

class Snake;

class GameManager
{
private:
    static int totalPoints;
    static bool gameEnded;

public:
    static void initializeDisplay();
    static int getCurrentScore();
    static void addPoint();
    static bool hasGameEnded();
    static void endGame();
    static void changeDirOnKeypress(Snake &snakeSprite);
    static void updateIfWasEaten(Food &foodSprite, Snake &snakeSprite);
};

#endif /* defined(__BitSnake__GameManager__) */
