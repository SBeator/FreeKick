#pragma once

#include "cocos2d.h"

USING_NS_CC;

#define PLAYER_WIDTH 20
#define PLAYER_HIT_HEIGHT 40
#define PLAYER_IMAGE_HEIGHT 60

class PlayerSprite : public Sprite
{
public:
    CREATE_FUNC(PlayerSprite);

    virtual bool init();

private:

    PhysicsBody* _body;
};

