#include "DoorSprite.h"
#include "ResourcesLoader.h"

USING_NS_CC;

bool DoorSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    auto resourcesLoader = ResourcesLoader::getInstance();

    // image
    this->initWithTexture(resourcesLoader->getTexture("Door"));

    PhysicsBody* body = PhysicsBody::create();

    PhysicsShape* shapSideRight = PhysicsShapeBox::create(Size(DOOR_SIDE_WIDTH, DOOR_HEIGHT), PHYSICSSHAPE_MATERIAL_DEFAULT, Point((DOOR_WIDTH - DOOR_SIDE_WIDTH) / 2, 0));
    shapSideRight->setTag(DOOR_SIDE_SHAPE_TAG);
    body->addShape(shapSideRight);

    PhysicsShape* shapSideLeft = PhysicsShapeBox::create(Size(DOOR_SIDE_WIDTH, DOOR_HEIGHT), PHYSICSSHAPE_MATERIAL_DEFAULT, Point(- (DOOR_WIDTH - DOOR_SIDE_WIDTH) / 2, 0));
    shapSideLeft->setTag(DOOR_SIDE_SHAPE_TAG);
    body->addShape(shapSideLeft);

    PhysicsShape* shapSideBack = PhysicsShapeBox::create(Size(DOOR_WIDTH - DOOR_SIDE_WIDTH * 2, DOOR_BACK_WIDTH), PhysicsMaterial(0, 0, 1.0f), Point(0, (DOOR_HEIGHT - DOOR_SIDE_WIDTH) / 2));
    shapSideBack->setTag(DOOR_BACK_SHAPE_TAG);
    body->addShape(shapSideBack);

    body->setGravityEnable(false);
    body->setDynamic(false);

    _body = body;
    this->setPhysicsBody(_body);

    return true;
}