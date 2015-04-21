//
//  GameManager.cpp
//  BitSnake
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include "GameManager.h"

GameManager::GameManager()
{
    // Initialize curses gui
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);
}

int GameManager::totalPoints = 0;

int GameManager::getCurrentScore()
{
    return totalPoints;
}

void GameManager::addPoint()
{
    totalPoints++;
}