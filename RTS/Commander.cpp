#include "Commander.h"
#include <SDL_scancode.h>
#include "Game.h"
#include <iostream>

Commander::Commander() :
	Actor()
{
	maxForwardSpeed = 150.0f;
	maxUpSpeed = 150.0f;

	map = getGame().getGrid();
	initPos = map->getPosition();

	mc = new MoveComponent(this);
}

void Commander::updateActor(float dt)
{
}

void Commander::actorInput(const Uint8* keyState)
{
	forwardSpeed = 0.0f;
	if (keyState[SDL_SCANCODE_RIGHT])
	{
		forwardSpeed += maxForwardSpeed;
		move();
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		forwardSpeed -= maxForwardSpeed;
		move();
	}
	mc->setForwardSpeed(forwardSpeed);

	upSpeed = 0.0f;
	if (keyState[SDL_SCANCODE_UP])
	{
		upSpeed += maxForwardSpeed;
		move();
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		upSpeed -= maxForwardSpeed;
		move();
	}
	mc->setUpSpeed(upSpeed);
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
