#pragma once
#include "Actor.h"

class Grid :
    public Actor
{
public:
    Grid();
    Grid(std::vector<std::vector<int>>* circuit);

    void processClick(int x, int y);
    class Tile& getStartTile();
    class Tile& getEndTile();

private:
    void selectTile(size_t row, size_t col);
    class Tile* selectedTile;


    // 2D vector of tiles in grid
    std::vector<std::vector<class Tile*>> tiles;

    const size_t NB_ROWS = 15;
    const size_t NB_COLS = 20; // 16

    // Start y position of top left corner
    const float START_Y = 20;

    const float TILESIZE = 40.0f;
};

