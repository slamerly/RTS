#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
//#include "MoveComponent.h"
#include "Astar.h"
#include "NavComponent.h"

class Soldier :
    public Actor
{
public:
    Soldier(Vector2 GridPositionP);
    ~Soldier();

    CircleCollisionComponent& getCollision() { return *collision; }

    void actorInput(const Uint8* keyState) override;
    void moveMap(Vector2 valueAdd) override;
    void shift(Vector2 target);

private:
    CircleCollisionComponent* collision;
    //MoveComponent* mc;
    NavComponent* nc;
    Astar* ast;

    Vector2 gridPosition;
};

