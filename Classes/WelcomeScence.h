#pragma once

#include "cocos2d.h"

USING_NS_CC;

class WelcomeScence : public Scene
{
public:
    CREATE_FUNC(WelcomeScence);

    virtual bool init();

private: 
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
};