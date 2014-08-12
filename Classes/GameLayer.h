#pragma once

#include "cocos2d.h"
#include "DoorSprite.h"
#include "BallSprite.h"

USING_NS_CC;

#define LAYER_WIDTH 576
#define LAYER_HEIGHT 1024
#define GOAL_LINE_POSITION_Y 864


typedef enum _game_status {
    GAME_STATUS_READY = 1,
    GAME_STATUS_SHOOTING,
    GAME_STATUS_GOAL,
    GAME_STATUS_OVER,
} GameStatus;

class GameLayer : public Layer
{
public:
    CREATE_FUNC(GameLayer);

    virtual bool init();

    bool isGoal();
    bool isGameOver();
    
private:
    virtual void update(float fDelta);

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    void calTouch(Point beginPoint, Point endPoint, double deltaTime);

    bool onContactBegin(PhysicsContact& contact);

    GameStatus _gameStatus;

    BallSprite* _ball;
    Rect _doorRect;
    Rect _playgroundRect;

    struct timeval _timeTouch;
    std::vector<Point> _touchMovePoints;
};

