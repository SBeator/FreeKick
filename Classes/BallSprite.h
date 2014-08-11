#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define BALL_RADIUS 10
#define ROTATE_FACTOR 0.05
#define ARC_FACTOR 0.00000006
#define SHOOT_FACTOR 0.4
#define DAMPING 0.2f
#define MAX_ARC_FORCE 500
#define MAX_SHOOT_FORCE 5000

class BallSprite : public Sprite
{
public:
    CREATE_FUNC(BallSprite);

    virtual bool init();

    void shoot(Point shootForce, float arcForce);

private:
    Speed* _rotationAction;
    PhysicsBody* _physicsBody;
    float _arcForce;
    int _arcDirection;

    virtual void update(float fDelta);
};

