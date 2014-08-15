#pragma once

#include "cocos2d.h"
#include "DoorSprite.h"
#include "BallSprite.h"
#include "GameStatus.h"
#include "PlayerSprite.h"

USING_NS_CC;

#define LAYER_WIDTH 576
#define LAYER_HEIGHT 1024
#define GOAL_LINE_POSITION_Y 864

class GameLayer : public Layer
{
public:
    CREATE_FUNC(GameLayer);

    virtual bool init();

    bool isGoal();
    bool isGameOver();

    void reset();
    void resetPlayers();

    CC_PROPERTY(GameStatus*, _gameStatus, GameStatus);
private:
    virtual void update(float fDelta);

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    void calTouch(Point beginPoint, Point endPoint, double deltaTime);

    bool onContactBegin(PhysicsContact& contact);

    BallSprite* _ball;
    Rect _doorRect;
    Rect _playgroundRect;
    Vector<PlayerSprite*> _players;

    struct timeval _timeTouch;
    std::vector<Point> _touchMovePoints;
};

