//
//  GameManager.cpp
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include "GameManager.h"

int GameManager::totalPoints = 0;
bool GameManager::gameEnded = false;

void GameManager::initializeDisplay()
{
    // Initialize curses gui
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);
}

void GameManager::changeDirOnKeypress(Snake &snakeSprite)
{
    // Input
    int ch = getch();
    switch (ch)
    {
        case KEY_UP:
            snakeSprite.setDirection(1);
            break;
        case KEY_RIGHT:
            snakeSprite.setDirection(2);
            break;
        case KEY_DOWN:
            snakeSprite.setDirection(3);
            break;
        case KEY_LEFT:
            snakeSprite.setDirection(4);
            break;
    }
    
    snakeSprite.updatePosition();
}

void GameManager::updateIfWasEaten(Food &foodSprite, Snake &snakeSprite)
{
    if (!foodSprite.wasEatenBy(snakeSprite))
    {
        snakeSprite.updateTail();
    }

    if (foodSprite.wasEatenBy(snakeSprite))
    {
        foodSprite.generateNewFoodPos();
        addPoint();
    }
}

int GameManager::getCurrentScore()
{
    return totalPoints;
}

void GameManager::addPoint()
{
    totalPoints++;
}

bool GameManager::hasGameEnded()
{
    return gameEnded;
}

void GameManager::endGame()
{
    gameEnded = true;
}