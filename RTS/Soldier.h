#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "Astar.h"
#include "NavComponent.h"

class Soldier :
    public Actor
{
public:
    Soldier(Vector2 tilePositionP);
    ~Soldier();

    CircleCollisionComponent& getCollision() { return *collision; }

    void actorInput(const Uint8* keyState) override;
    void moveMap(Vector2 valueAdd) override;
    void setGridPosition(Vector2 gridPositionP) override;
    void shift(Vector2 target);

private:
    CircleCollisionComponent* collision;
    NavComponent* nc;
    Astar* ast;

    Vector2 tilePosition;
};

