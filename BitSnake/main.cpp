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
    GameManager snakeGame;
    Food snakeFood;
    Snake gameSnake;
    
    bool gameEnded = false;
    
    int curDir = 2;
    
    while (!gameEnded)
    {
        
        // Logic
        std::pair<int, int> logic = gameSnake.getPos();
        int curX = logic.first;
        int curY = logic.second;
        
        // Input
        int ch = getch();
        switch (ch)
        {
            case KEY_UP:
                curDir = 1;
                break;
            case KEY_RIGHT:
                curDir = 2;
                break;
            case KEY_DOWN:
                curDir = 3;
                break;
            case KEY_LEFT:
                curDir = 4;
                break;
            case 'q':
                gameEnded = true;
                break;
        }
        
        switch (curDir)
        {
            case 1 : curY--; break;
            case 2 : curX++; break;
            case 3 : curY++; break;
            case 4 : curX--; break;
        }
        
        
        gameSnake.addHead(make_pair(curX, curY));
    
        snakeFood.didEat(gameSnake);
        
        
        if (curY > getmaxy(stdscr) || curX > getmaxx(stdscr) || curY < 0 || curX < 0)
        {
            gameEnded = true;
            break;
        }
        
        // Output
        erase();
        snakeFood.redraw();
        
        if (!gameSnake.successfulDraw(make_pair(curX, curY)))
        {
            gameEnded = true;
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