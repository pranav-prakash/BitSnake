//
//  BitSnake -- main
//
//  Created by Pranav Prakash on 4/20/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include "Snake.h"
#include "Food.h"
#include "GameManager.h"

using namespace std;


int main(int argc, const char *argv[])
{
    GameManager::initializeDisplay();
    
    Food foodSprite;
    Snake snakeSprite;
    
    while (!GameManager::hasGameEnded())
    {

        GameManager::changeDirOnKeypress(snakeSprite);
        
        GameManager::updateIfWasEaten(foodSprite, snakeSprite);
        
        if (snakeSprite.isOutOfBounds())
        {
            GameManager::endGame();
            break;
        }
        
        // Output
        erase();
        foodSprite.redraw();
        
        if (!snakeSprite.successfulDraw())
        {
            GameManager::endGame();
        }
        
        mvprintw(0, 0, "You got %i points. 'q' to quit.\n", GameManager::getCurrentScore());
        refresh();
    }
    
    timeout(-1);
    erase();
    mvprintw(0, 0, "You lost and gained a total of %i points.\n", GameManager::getCurrentScore());
    refresh();
    getch(); // wait for input
    
    endwin();
    return 0;
}