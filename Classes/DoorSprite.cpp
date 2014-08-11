#include "DoorSprite.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool DoorSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    // image
    this->initWithTexture(resourcesLoader->getTexture("Door"));

    return true;
}