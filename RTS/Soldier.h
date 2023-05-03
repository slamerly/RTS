#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "MoveComponent.h"
#include "Astar.h"

class Soldier :
    public Actor
{
public:
    Soldier(Vector2 GridPositionP);
    ~Soldier();

    CircleCollisionComponent& getCollision() { return *collision; }

    void shift(Vector2 target);

private:
    CircleCollisionComponent* collision;
    MoveComponent* mc;
    Astar* ast;

    Vector2 gridPosition;
};

