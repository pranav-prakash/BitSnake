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

class GameManager
{
private:
    static int totalPoints;
public:
    
    GameManager();
    
    static int getCurrentScore();
    static void addPoint();
};


#endif /* defined(__BitSnake__GameManager__) */
