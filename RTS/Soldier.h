#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "MoveComponent.h"

class Soldier :
    public Actor
{
public:
    Soldier();

    CircleCollisionComponent& getCollision() { return *collision; }

private:
    CircleCollisionComponent* collision;
    MoveComponent* mc;
};

