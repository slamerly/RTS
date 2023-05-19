#include "Commander.h"
#include <SDL_scancode.h>
#include "Game.h"
#include <iostream>

Commander::Commander() :
	Actor()
{
	maxForwardSpeed = 300.0f;
	maxUpSpeed = 300.0f;

	//maxForwardSpeed = 5.0f;
	//maxUpSpeed = 5.0f;

	mc = new MoveComponent(this);
}

void Commander::actorInput(const Uint8* keyState)
{
	// Mouse pos
	int x, y;
	Uint32 mouse = SDL_GetMouseState(&x, &y);

	forwardSpeed = 0.0f;
	if (keyState[SDL_SCANCODE_LEFT] || x <= 75)
	{
		forwardSpeed += maxForwardSpeed;
		move();
	}
	else if (keyState[SDL_SCANCODE_RIGHT] || x >= WINDOW_WIDTH - 75)
	{
		forwardSpeed -= maxForwardSpeed;
		move();
	}
	mc->setForwardSpeed(forwardSpeed);

	upSpeed = 0.0f;
	if (keyState[SDL_SCANCODE_DOWN] || y >= WINDOW_HEIGHT - 75)
	{
		upSpeed += maxForwardSpeed;
		move();
	}
	else if (keyState[SDL_SCANCODE_UP] || y <= 75)
	{
		upSpeed -= maxForwardSpeed;
		move();
	}
	mc->setUpSpeed(upSpeed);

	if (SDL_BUTTON(mouse) && mouse - 1 == SDL_BUTTON_RIGHT)
	{
		getGame().getGrid()->processClick(x, y);

		if (!getGame().isOccupedTile())
		{
			unitMovement();
		}

		/*
		for (auto soldier : selectedUnits)
		{
			soldier->shift(getGame().getGrid()->getVectorTileSelected());
		}
		*/
		//getGame().getSoldiers().at(0)->shift(getGame().getGrid()->getVectorTileSelected());
	}
}

void Commander::addInSelection(Soldier* soldier)
{
	selectedUnits.push_back(soldier);
}

void Commander::removeInSelection(Soldier* soldier)
{
	auto iter = find(begin(selectedUnits), end(selectedUnits), soldier);
	selectedUnits.erase(iter);
}

void Commander::move()
{
	for (auto actors : getGame().getActors())
	{
		if (actors->tag == "map")
		{
			actors->moveMap(getPosition());
		}
	}
}

void Commander::unitMovement()
{
	vector<Vector2> freeTiles = getGame().getAstar()->findNeightbours(getGame().getGrid()->getVectorTileSelected());
	Vector2 target = getGame().getGrid()->getVectorTileSelected();
	vector<Vector2> followingTiles;
	vector<Vector2> adder;

	while (freeTiles.size() + 1 < selectedUnits.size())
	{
		for (auto neighbour : freeTiles)
		{
			if ((neighbour.x == target.x && (neighbour.y == target.y + 1 || neighbour.y == target.y - 1))
				|| (neighbour.y == target.y && (neighbour.x == target.x + 1 || neighbour.x == target.x - 1)))
			{
				auto iter = find(begin(followingTiles), end(followingTiles), neighbour);
				if (iter == end(followingTiles))
				{
					followingTiles.push_back(neighbour);
					break;
				}
			}
			else
			{
				auto iter = find(begin(followingTiles), end(followingTiles), neighbour);
				if (iter == end(followingTiles))
				{
					followingTiles.push_back(neighbour);
					break;
				}
			}
		}

		adder = getGame().getAstar()->findNeightbours(followingTiles.at(followingTiles.size()-1));

		for (auto tile : adder)
		{
			auto iter = find(begin(freeTiles), end(freeTiles), tile);
			if (iter == end(freeTiles) && tile != target)
			{
				freeTiles.push_back(tile);
			}
		}
		adder.clear();
	}
	followingTiles.clear();

	selectedUnits.at(0)->shift(target);

	for (int i = 1; i < selectedUnits.size(); i++)
	{
		selectedUnits.at(i)->shift(freeTiles.at(i-1));
	}

	/*
	for (auto soldier : selectedUnits)
	{
		soldier->shift(getGame().getGrid()->getVectorTileSelected());
	}
	*/
}
