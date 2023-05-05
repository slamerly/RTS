#include "Soldier.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "Game.h"
#include <iostream>

Soldier::Soldier(Vector2 GridPositionP) :
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

	gridPosition = GridPositionP;
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
	valueAddView = valueAdd;
	if (inMovement)
	{
		/*
		setInitPosition(getPosition());
		Vector2 dif = getInitPosition() - (getInitPosition() + (-1 * valueAdd));
		cout << "position : " << getPosition().x << ", " << getPosition().y << endl << dif.x << ", " << dif.y << endl;
		setPosition(getPosition() + dif);
		*/
	}
	else
	{
		valueAddView = Vector2::zero;
		setPosition(getInitPosition() + valueAdd);
	}
}

void Soldier::shift(Vector2 target)
{
	std::vector<Vector2> pred = ast->mostShortWay(getGame().getGrid()->getLocationOnGrid(getPosition()), target);
	//std::vector<Vector2> pred = ast->mostShortWay(gridPosition, target);

	reverse(pred.begin(), pred.end());
	
	for (auto vec : pred)
	{
		std::cout << "[" << vec.x << ", " << vec.y << "] -> ";
	}
	
	//gridPosition = pred.at(pred.size() - 1);

	nc->initializePath(pred);
	//gridPosition = pred.at(pred.size());
}
