#include "Soldier.h"
#include "SpriteComponent.h"
#include "Assets.h"

Soldier::Soldier() :
	Actor()
{
	tag = "map";

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Moto2"));

	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);

	mc = new MoveComponent(this);
}
