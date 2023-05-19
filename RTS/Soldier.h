#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "NavComponent.h"

class Soldier :
    public Actor
{
public:
    Soldier(Vector2 tilePositionP);
    ~Soldier();

    CircleCollisionComponent& getCollision() { return *collision; }
    Vector2 getOccupedTile() { return tilePosition; }

    void moveMap(Vector2 valueAdd) override;
    void setGridPosition(Vector2 gridPositionP) override;
    void shift(Vector2 target);

private:
    CircleCollisionComponent* collision;
    NavComponent* nc;

    Vector2 tilePosition;
};

