#include "StatusLayer.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool StatusLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    _goalLabel = Sprite::createWithTexture(resourcesLoader->getTexture("Goal"));
    _goalLabel->setPosition(Point(288, 640));
    _goalLabel->setVisible(false);
    this->addChild(_goalLabel);

    _failLabel = Sprite::createWithTexture(resourcesLoader->getTexture("Fail"));
    _failLabel->setPosition(Point(288, 640));
    _failLabel->setVisible(false);
    this->addChild(_failLabel);

    auto resetItem = MenuItemSprite::create(
        Sprite::createWithTexture(resourcesLoader->getTexture("Reset")),
        Sprite::createWithTexture(resourcesLoader->getTexture("ResetPressed")),
        CC_CALLBACK_0(StatusLayer::resetGame, this));

    resetItem->setPosition(Point(288, 350));

    // create menu, it's an autorelease object
    auto menu = Menu::create(resetItem, NULL);
    menu->setPosition(Point::ZERO);

    _statusMenu = menu;
    _statusMenu->setVisible(false);
    this->addChild(_statusMenu);

    return true;
}

void StatusLayer::gameGoal()
{
    GameStatus::gameGoal();

    _goalLabel->setVisible(true);
    _statusMenu->setVisible(true);
}

void StatusLayer::gameOver()
{
    GameStatus::gameOver();

    _failLabel->setVisible(true);
    _statusMenu->setVisible(true);
}

void StatusLayer::resetGame()
{
    _goalLabel->setVisible(false);
    _failLabel->setVisible(false);
    _statusMenu->setVisible(false);

    _gameLayer->reset();
}
