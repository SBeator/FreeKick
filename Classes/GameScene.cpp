#include "GameScene.h"
#include "GameLayer.h"

USING_NS_CC;

bool GameScene::init()
{
    if (!Scene::init() || !Scene::initWithPhysics())
    {
        return false;
    }

    // Add the main game layer
    auto gameLayer = GameLayer::create();
    this->addChild(gameLayer);
    
    return true;
}