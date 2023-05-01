#include "Moto.h"
#include "Assets.h"
#include "Maths.h"
#include <iostream>

Moto::Moto() :
	Actor()
{
	spriteComp = new SpriteComponent(this, Assets::getTexture("Moto"));
	inputComp = new InputComponent(this);

	inputComp->setMaxForwardSpeed(150);
	inputComp->setMaxAngularSpeed(Maths::toRadians(65.0f));

	collision = new CircleCollisionComponent(this);
	collision->setRadius(10.0f);
}

Moto::~Moto()
{
	delete collision, inputComp, spriteComp;
}

void Moto::updateActor(float dt)
{
}
