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
    timeout(50);
}

void GameManager::changeDirOnKeypress(Snake &snakeSprite)
{
    // Input
    int ch = getch();
    int newDir = snakeSprite.getDirection();
    switch (ch)
    {
        case KEY_UP:
            newDir = 1;
            break;
        case KEY_RIGHT:
            newDir = 2;
            break;
        case KEY_DOWN:
            newDir = 3;
            break;
        case KEY_LEFT:
            newDir = 4;
            break;
    }
    snakeSprite.setDirection((newDir%2 == snakeSprite.getDirection()%2)?snakeSprite.getDirection():newDir);
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

void GameManager::redrawScene(Snake &snakeSprite, Food &foodSprite)
{

    // Output
    erase();
    foodSprite.redraw();

    if (!snakeSprite.successfulDraw())
    {
        GameManager::endGame();
    }

    mvprintw(0, 0, "Your score is %i. 'Ctrl-C' to quit.\n", GameManager::getCurrentScore());
    refresh();
}

void GameManager::updateGameFrame(Snake &snakeSprite, Food &foodSprite)
{
    changeDirOnKeypress(snakeSprite);
    updateIfWasEaten(foodSprite, snakeSprite);
    checkBounds(snakeSprite);
    redrawScene(snakeSprite, foodSprite);
}

void GameManager::checkBounds(Snake &snakeSprite)
{

    if (snakeSprite.isOutOfBounds())
    {
        endGame();
    }
}

void GameManager::displayScoreOnLose()
{
    timeout(-1);
    erase();
    mvprintw(0, 0, "Game Over! Total score was %i.\n", getCurrentScore());
    refresh();
    getch(); // wait for input
}

void GameManager::doGame()
{
    initializeDisplay();

    Food foodSprite;
    Snake snakeSprite;

    while (!hasGameEnded())
    {
        updateGameFrame(snakeSprite, foodSprite);
    }

    displayScoreOnLose();

    endwin();
}
