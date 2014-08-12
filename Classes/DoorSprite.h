#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define DOOR_SIDE_SHAPE_TAG 202
#define DOOR_BACK_SHAPE_TAG 203
#define DOORPOSTS_SHAPE_TAG 203

#define DOOR_WIDTH 300
#define DOOR_HEIGHT 80
#define DOOR_SIDE_WIDTH 10
#define DOOR_BACK_WIDTH 10

class DoorSprite : public Sprite
{
public:
    CREATE_FUNC(DoorSprite);

    virtual bool init();

private:

    PhysicsBody* _body;
};

