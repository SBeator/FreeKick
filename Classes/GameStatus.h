#pragma once

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

typedef enum _game_status {
    GAME_STATUS_READY = 1,
    GAME_STATUS_SHOOTING,
    GAME_STATUS_GOAL,
    GAME_STATUS_OVER,
} GameStatusEnum;

class GameStatus
{
public:
    virtual void gameReady();
    bool isReady();

    virtual void gameShooting();
    bool isShooting();

    virtual void gameGoal();
    bool isGoal();

    virtual void gameOver();
    bool isOver();

private:
    GameStatusEnum _gameStatusEnum;
};

