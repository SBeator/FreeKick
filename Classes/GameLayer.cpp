#include "GameLayer.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool GameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    auto texture = resourcesLoader->getTexture("Playground");
    auto background = Sprite::createWithTexture(texture);
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Point::ZERO);
    this->addChild(background);
    
    return true;
}


