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

void Commander::updateActor(float dt)
{
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

	if (SDL_BUTTON(mouse) & SDL_BUTTON_LEFT)
	{
		getGame().getGrid()->processClick(x, y);
		getGame().getSoldiers().at(0)->shift(getGame().getGrid()->getVectorTileSelected());
	}
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
