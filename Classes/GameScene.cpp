#include "GameScene.h"
#include "GameLayer.h"
#include "StatusLayer.h"

USING_NS_CC;

bool GameScene::init()
{
    if (!Scene::init() || !Scene::initWithPhysics())
    {
        return false;
    }

    // Add the main game layer and status layer
    auto statusLayer = StatusLayer::create();
    auto gameLayer = GameLayer::create();
    gameLayer->setGameStatus(statusLayer);
    statusLayer->setGameLayer(gameLayer);

    this->addChild(gameLayer);
    this->addChild(statusLayer);
    
    return true;
}