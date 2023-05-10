#pragma once
#include "Actor.h"
#include <vector>
#include "SpriteComponent.h"
#include "RectangleCollisionComponent.h"

class Tile :
    public Actor
{
public:
    friend class Grid;
    enum class TileState
    {
        Default,
        Border,
        Building,
        Tree,
        EndLine
    };

    Tile();

    void updateActor(float dt) override;

    TileState getTileState() const { return tileState; }
    void setTileState(TileState tileStateP);
    void setGridPosition(Vector2 gridPositionP) override;
    void moveMap(Vector2 valueAdd) override;

    void toggleSelect();

private:
    RectangleCollisionComponent* collision;
    SpriteComponent* sprite;
    TileState tileState;
    bool isSelected;

    void updateTexture();
};

