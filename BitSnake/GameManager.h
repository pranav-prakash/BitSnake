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

    static int getCurrentScore()
    {
        return totalPoints;
    }
    static void addPoint()
    {
        totalPoints++;
    }

    static bool hasGameEnded()
    {
        return gameEnded;
    }

    static void endGame()
    {
        gameEnded = true;
    }

    static void initializeDisplay();
    static void changeDirOnKeypress(Snake &snakeSprite);
    static void updateIfWasEaten(Food &foodSprite, Snake &snakeSprite);
    static void checkBounds(Snake &snakeSprite);
    static void redrawScene(Snake &snakeSprite, Food &foodSprite);
    static void updateGameFrame(Snake &snakeSprite, Food &foodSprite);
    static void displayScoreOnLose();

public:
    static void doGame();
};

#endif /* defined(__BitSnake__GameManager__) */
