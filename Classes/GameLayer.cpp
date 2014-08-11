#include "GameLayer.h"
#include "ResourcesLoader.h"
#include "DoorSprite.h"

USING_NS_CC;

bool GameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();
    
    // background
    auto background = Sprite::createWithTexture(resourcesLoader->getTexture("Playground"));
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Point::ZERO);
    this->addChild(background);

    // ball
    auto ball = BallSprite::create();
    ball->setPosition(Point(100,300));
    _ball = ball;
    this->addChild(_ball);

    // door
    auto door = DoorSprite::create();
    door->setAnchorPoint(Point(0.5, 0));
    door->setPosition(Point(LAYER_WIDTH / 2, GOAL_LINE_POSITION_Y));
    this->addChild(door);

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    _touchMovePoints.clear();
    gettimeofday(&_timeTouch, NULL);

    return true;
}

void GameLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
    _touchMovePoints.push_back(touch->getLocation());
}

void GameLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
    auto beginPoint = touch->getStartLocation();
    auto endPoint = touch->getLocation();

    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    this->calTouch(beginPoint, endPoint, (double)(tv.tv_sec - _timeTouch.tv_sec) + (double)(tv.tv_usec - _timeTouch.tv_usec) / 1000000);
}

void GameLayer::calTouch(Point beginPoint, Point endPoint, double deltaTime)
{
    auto touchArror = endPoint - beginPoint;
    int pointsNumber = _touchMovePoints.size();

    float touchLength = touchArror.getLength();
    if (touchLength == 0 || pointsNumber == 0 || deltaTime <= 0)
    {
        return;
    }

    int centerPointIndex = pointsNumber / 2;
    auto centerPoint = _touchMovePoints.at(centerPointIndex);

    float xb = beginPoint.x;
    float yb = beginPoint.y;
    float xe = endPoint.x;
    float ye = endPoint.y;
    float xc = centerPoint.x;
    float yc = centerPoint.y;

    float direction = (beginPoint.y - endPoint.y) * centerPoint.x 
                    + (endPoint.x - beginPoint.x) * centerPoint.y
                    + beginPoint.x * endPoint.y
                    - endPoint.x * beginPoint.y;

    float arcForce = -direction / touchLength / deltaTime;

    float force = touchLength / deltaTime;

    auto shootArror = centerPoint - beginPoint;

    auto shootForce = shootArror * force / shootArror.getLength();

    if (_ball)
    {
        _ball->shoot(shootForce, arcForce);
    }
}