#pragma once
#include "Actor.h"

class Grid :
    public Actor
{
public:
    Grid();
    Grid(std::vector<std::vector<int>>* circuit);

    void processClick(int x, int y);
    class Tile* getTile(size_t row, size_t col);

    Vector2 getVectorTileSelected() { return vectorTileSelected; }
    Vector2 getLocationOnGrid(Vector2 position);

private:
    void selectTile(size_t row, size_t col);
    class Tile* selectedTile;

    // 2D vector of tiles in grid
    std::vector<std::vector<class Tile*>> tiles;

    const size_t NB_ROWS = 30; // 15
    const size_t NB_COLS = 40; // 20

    // Start y position of top left corner
    const float START_Y = 20;

    const float TILESIZE = 40.0f;

    Vector2 vectorTileSelected;
};

