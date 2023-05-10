#include "Soldier.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "Game.h"
#include "Tile.h"
#include <iostream>

Soldier::Soldier(Vector2 tileSPositionP) :
	Actor()
{
	tag = "map";

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Moto2"));

	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);

	//mc = new MoveComponent(this);
	nc = new NavComponent(this);
	nc->setFSpeed(150);

	ast = new Astar(getGame().getMap());

	tilePosition = tileSPositionP;
	setGridPosition(getGame().getGrid()->getTile(tilePosition.x, tilePosition.y)->getPosition());
	//cout << "Position : " << getPosition().x << ", " << getPosition().y << endl;
	//cout << "Grid position : " << getGame().getGrid()->getPosition().x << ", " << getGame().getGrid()->getPosition().y << endl;
	//cout << "Tile position : " << getGame().getGrid()->getTile(tilePosition.x, tilePosition.y)->getGridPosition().x << ", " << getGame().getGrid()->getTile(tilePosition.x, tilePosition.y)->getGridPosition().y << endl;
	//cout << "Position on grid : " << getGame().getGrid()->getLocationOnGrid(getGridPosition()).x << ", " << getGame().getGrid()->getLocationOnGrid(getGridPosition()).y << endl;
}

Soldier::~Soldier()
{
	delete collision, nc, ast;
}

void Soldier::actorInput(const Uint8* keyState)
{
	//cout << "soldier : " << getPosition().x << ", " << getPosition().y << endl;
	//setInitPosition(getPosition());
}

void Soldier::moveMap(Vector2 valueAdd)
{
	//cout << "grid position: " << getGame().getGrid()->getPosition().x << ", " << getGame().getGrid()->getPosition().y << endl;
	//cout << "soldier  grid position: " << gridPosition.x << ", " << gridPosition.y << endl;
	setPosition(getGame().getGrid()->getPosition() + getGridPosition());
	/*
	valueAddView = valueAdd;
	if (inMovement)
	{
		/*
		setInitPosition(getPosition());
		Vector2 dif = getInitPosition() - (getInitPosition() + (-1 * valueAdd));
		cout << "position : " << getPosition().x << ", " << getPosition().y << endl << dif.x << ", " << dif.y << endl;
		setPosition(getPosition() + dif);
	}
	else
	{
		valueAddView = Vector2::zero;
		setPosition(getInitPosition() + valueAdd);
	}
	*/
}

void Soldier::setGridPosition(Vector2 gridPositionP)
{
	gridPosition = gridPositionP;
	setPosition(getGame().getGrid()->getPosition() + getGridPosition());
}

void Soldier::shift(Vector2 target)
{
	//cout << "Position : " << getGame().getGrid()->getLocationOnGrid(getPosition()).x << ", " << getGame().getGrid()->getLocationOnGrid(getPosition()).y << endl;
	//cout << "Soldier Grid Position : " << getGridPosition().x << ", " << getGridPosition().y << endl;
	//cout << "Grid Position : " << getGame().getGrid()->getLocationOnGrid(getGridPosition()).x << ", " << getGame().getGrid()->getLocationOnGrid(getGridPosition()).y << endl;

	std::vector<Vector2> pred = ast->mostShortWay(getGame().getGrid()->getLocationOnGrid(getGridPosition()), target);
	//std::vector<Vector2> pred = ast->mostShortWay(gridPosition, target);

	reverse(pred.begin(), pred.end());
	
	for (auto vec : pred)
	{
		std::cout << "[" << vec.x << ", " << vec.y << "] -> ";
	}
	
	//gridPosition = pred.at(pred.size() - 1);

	nc->initializePath(pred);
	//tilePosition = target;
	//gridPosition = pred.at(pred.size());
}
