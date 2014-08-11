#pragma once

#include "cocos2d.h"
#include "BallSprite.h"

USING_NS_CC;

#define LAYER_WIDTH 576
#define LAYER_HEIGHT 1024
#define GOAL_LINE_POSITION_Y 864

class GameLayer : public Layer
{
public:
    CREATE_FUNC(GameLayer);

    virtual bool init();

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
private:

    BallSprite* _ball;

    void calTouch(Point beginPoint, Point endPoint, double deltaTime);
    struct timeval _timeTouch;
    std::vector<Point> _touchMovePoints;
};

