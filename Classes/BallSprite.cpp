#include "BallSprite.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool BallSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    // image
    this->initWithTexture(resourcesLoader->getTexture("Ball"));

    // physics body
    PhysicsBody *body = PhysicsBody::create();
    body->addShape(PhysicsShapeCircle::create(BALL_RADIUS));
    body->setDynamic(true);
    body->setLinearDamping(DAMPING);
    body->setGravityEnable(false);
    _physicsBody = body;
    this->setPhysicsBody(_physicsBody);

    this->scheduleUpdate();
    return true;
}

void BallSprite::update(float fDelta)
{
    auto velocity = _physicsBody->getVelocity();
    auto speed = velocity.getLength();

    _physicsBody->setAngularVelocity(ROTATE_FACTOR * _arcForce * speed);
    _physicsBody->setVelocity(velocity.rotateByAngle(Point(0, 0), ARC_FACTOR * _arcForce * speed));
}

void BallSprite::shoot(Point shootForce, float arcForce)
{
    float force = shootForce.getLength();
    if (force > MAX_SHOOT_FORCE)
    {
        shootForce = shootForce * MAX_SHOOT_FORCE / force;
    }

    _physicsBody->setVelocity(shootForce * SHOOT_FACTOR);
    _arcForce = arcForce < MAX_ARC_FORCE
                    ? arcForce > -MAX_ARC_FORCE
                        ? arcForce  
                        : -MAX_ARC_FORCE
                    : MAX_ARC_FORCE;
}
