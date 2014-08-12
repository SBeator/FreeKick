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
    door->setPosition(Point(LAYER_WIDTH / 2, GOAL_LINE_POSITION_Y + DOOR_HEIGHT / 2));
    this->addChild(door);

    _doorRect = door->getBoundingBox();
    _playgroundRect = Rect(0, 0, LAYER_WIDTH, GOAL_LINE_POSITION_Y);

    _gameStatus = GAME_STATUS_READY;

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // Register contact event
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    this->scheduleUpdate();

    return true;
}

bool GameLayer::isGoal()
{
    Point ballPoint = _ball->getPosition();

    return _doorRect.containsPoint(ballPoint);
}

bool GameLayer::isGameOver()
{
    Point ballPoint = _ball->getPosition();

    return !_playgroundRect.containsPoint(ballPoint);
}

void GameLayer::update(float fDelta)
{
    if (_gameStatus == GAME_STATUS_SHOOTING)
    {
        if (this->isGoal())
        {
            _ball->goal();
            _gameStatus = GAME_STATUS_GOAL;
        }
        else if (this->isGameOver())
        {
            _gameStatus = GAME_STATUS_OVER;
        }
    }
    
}


bool GameLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    if (_gameStatus == GAME_STATUS_READY)
    {
        _touchMovePoints.clear();
        gettimeofday(&_timeTouch, NULL);

        return true;
    }
    
    return false;
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

   // _gameStatus = GAME_STATUS_SHOOTING;

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

bool GameLayer::onContactBegin(PhysicsContact& contact)
{



    return true;
}