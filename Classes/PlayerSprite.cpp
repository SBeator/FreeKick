#include "PlayerSprite.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool PlayerSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    // image
    this->initWithTexture(resourcesLoader->getTexture("Player"));

    PhysicsBody* body = PhysicsBody::create();
    auto shape = PhysicsShapeBox::create(Size(PLAYER_WIDTH, PLAYER_HIT_HEIGHT), PhysicsMaterial(0.5, 0.2, 1.0f), Point(0, (PLAYER_HIT_HEIGHT - PLAYER_IMAGE_HEIGHT) / 2));
    body->addShape(shape);
    body->setGravityEnable(false);
    body->setDynamic(false);

    _body = body;
    this->setPhysicsBody(_body);

    return true;
}