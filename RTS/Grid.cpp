#include "Grid.h"
#include "Tile.h"

Grid::Grid() :
	Actor(), selectedTile(nullptr)
{
	tiles.resize(NB_ROWS);
	for (size_t i = 0; i < tiles.size(); i++)
	{
		tiles[i].resize(NB_COLS);
	}
	// Create tiles
	for (size_t i = 0; i < NB_ROWS; i++)
	{
		for (size_t j = 0; j < NB_COLS; j++)
		{
			tiles[i][j] = new Tile();
			tiles[i][j]->setPosition(Vector2(TILESIZE / 2.0f + j * TILESIZE, START_Y + i * TILESIZE));
			tiles[i][j]->setTileState(Tile::TileState::Default);
		}
	}

	// Set start/end tiles
	//getStartTile().setTileState(Tile::TileState::Default);
	//getEndTile().setTileState(Tile::TileState::Border);
}

Grid::Grid(std::vector<std::vector<int>>* circuit) :
	Actor(), selectedTile(nullptr)
{
	tiles.resize(NB_ROWS);
	for (size_t i = 0; i < tiles.size(); i++)
	{
		tiles[i].resize(NB_COLS);
	}
	// Create tiles
	for (size_t i = 0; i < NB_ROWS; i++)
	{
		for (size_t j = 0; j < NB_COLS; j++)
		{
			tiles[i][j] = new Tile();
			tiles[i][j]->setPosition(Vector2(TILESIZE / 2.0f + j * TILESIZE, START_Y + i * TILESIZE));

			switch (circuit->at(i).at(j))
			{
			case 0:
			default:
				tiles[i][j]->setTileState(Tile::TileState::Default);
				break;
			case 1:
				tiles[i][j]->setTileState(Tile::TileState::Border);
				break;
			case 2:
				tiles[i][j]->setTileState(Tile::TileState::Tree);
				break;
			case 3:
				tiles[i][j]->setTileState(Tile::TileState::Building);
				break;
			case 4:
				tiles[i][j]->setTileState(Tile::TileState::EndLine);
			}
		}
	}
}

void Grid::processClick(int x, int y)
{
	y -= static_cast<int>(START_Y - TILESIZE / 2);
	if (y <= 0)
	{
		x /= static_cast<int>(TILESIZE);
		y /= static_cast<int>(TILESIZE);

		if (x >= 0 && x < static_cast<int>(NB_COLS) && y >= 0 && y < static_cast<int>(NB_ROWS))
		{
			selectTile(y, x);
		}
	}
}

Tile& Grid::getStartTile()
{
	return *tiles[3][0];
}

Tile& Grid::getEndTile()
{
	return *tiles[3][NB_COLS-1];
}

void Grid::selectTile(size_t row, size_t col)
{
	tiles[row][col]->toggleSelect();
}
