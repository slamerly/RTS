#include "Soldier.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "Game.h"
#include "Tile.h"
#include "Astar.h"
#include <iostream>

Soldier::Soldier(Vector2 tileSPositionP) :
	Actor()
{
	tag = "map";

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Moto2"));

	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);

	nc = new NavComponent(this);
	nc->setFSpeed(150);

	tilePosition = tileSPositionP;
	setGridPosition(getGame().getGrid()->getTile(tilePosition.x, tilePosition.y)->getPosition());
	setPosition(getGame().getGrid()->getTile(tilePosition.x, tilePosition.y)->getPosition());
}

Soldier::~Soldier()
{
	delete collision, nc;
}

void Soldier::moveMap(Vector2 valueAdd)
{
	setPosition(getGame().getGrid()->getPosition() + getGridPosition());
}

void Soldier::setGridPosition(Vector2 gridPositionP)
{
	gridPosition = gridPositionP;
	setPosition(getGame().getGrid()->getPosition() + getGridPosition());
}

void Soldier::shift(Vector2 target)
{
	if (getGame().getGrid()->getTile(target.x, target.y)->getTileState() == Tile::TileState::Default) {

		std::vector<Vector2> pred = getGame().getAstar()->mostShortWay(getGame().getGrid()->getLocationOnGrid(getGridPosition()), target);

		tilePosition = target;

		reverse(pred.begin(), pred.end());
		/*
		for (auto vec : pred)
		{
			std::cout << "[" << vec.x << ", " << vec.y << "] -> ";
		}
		*/
		nc->initializePath(pred);
	}
}
