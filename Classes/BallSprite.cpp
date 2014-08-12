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
    PhysicsShape* shap = PhysicsShapeCircle::create(BALL_RADIUS);
    shap->setTag(BALL_SHAPE_TAG);
    PhysicsBody *body = PhysicsBody::create();
    body->addShape(shap);
    body->setLinearDamping(DAMPING);
    body->setAngularDamping(DAMPING);
    body->setMass(0);
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

    _physicsBody->setVelocity(velocity.rotateByAngle(Point(0, 0), ARC_FACTOR * _arcForce * speed));
}

void BallSprite::shoot(Point shootForce, float arcForce)
{
    float force = shootForce.getLength();
    if (force > MAX_SHOOT_FORCE)
    {
        shootForce = shootForce * MAX_SHOOT_FORCE / force;
        force = MAX_SHOOT_FORCE;
    }

    _physicsBody->setVelocity(shootForce * SHOOT_FACTOR);

    _arcForce = arcForce < MAX_ARC_FORCE
                    ? arcForce > -MAX_ARC_FORCE
                        ? arcForce  
                        : -MAX_ARC_FORCE
                    : MAX_ARC_FORCE;
    _arcDirection = _arcForce > 0 ? 1 : -1;

    _physicsBody->setAngularVelocity(ROTATE_FACTOR * _arcDirection * force * SHOOT_FACTOR);
}

void BallSprite::goal()
{
    _physicsBody->setLinearDamping(DAMPING);
}