#include "Soldier.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "Game.h"

Soldier::Soldier(Vector2 GridPositionP) :
	Actor()
{
	tag = "map";

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Moto2"));

	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);

	mc = new MoveComponent(this);

	ast = new Astar(getGame().getMap());

	gridPosition = GridPositionP;
}

Soldier::~Soldier()
{
	delete collision, mc, ast;
}

void Soldier::shift(Vector2 target)
{
	std::vector<Vector2> pred = ast->mostShortWay(gridPosition, target);
}
