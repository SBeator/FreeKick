#include "WelcomeScence.h"
#include "ResourcesLoader.h"
#include "GameScene.h"

USING_NS_CC;

bool WelcomeScence::init()
{
    if (!Scene::init() || !Scene::initWithPhysics())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();
    auto welcomePage = Sprite::createWithTexture(resourcesLoader->getWelcomePage());
    welcomePage->setAnchorPoint(Point::ZERO);
    welcomePage->setPosition(Point::ZERO);

    this->addChild(welcomePage);

    resourcesLoader->loadResources();

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(WelcomeScence::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}

bool WelcomeScence::onTouchBegan(Touch *touch, Event *unused_event)
{
    auto scene = GameScene::create();

    Director::getInstance()->replaceScene(scene);

    return true;
}
