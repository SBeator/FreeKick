#pragma once

#include "cocos2d.h"
#include "GameLayer.h"
#include "GameStatus.h"

USING_NS_CC;

class StatusLayer : public Layer, public GameStatus
{
public:
    CREATE_FUNC(StatusLayer);

    virtual void gameGoal();

    virtual void gameOver();

    virtual bool init();

    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);

private:

    void resetGame();

    Sprite* _goalLabel;
    Sprite* _failLabel;
    Menu* _statusMenu;
};

