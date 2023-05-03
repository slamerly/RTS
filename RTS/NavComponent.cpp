#include "NavComponent.h"
#include "Actor.h"
#include "Tile.h"
#include "Maths.h"
#include "Game.h"
#include <iostream>

NavComponent::NavComponent(Actor* owner, int updateOrder) :
	MoveComponent(owner, updateOrder),
	nextNode(nullptr)
{
	setForwardSpeed(0.0f);
}

void NavComponent::update(float dt)
{
	if (cpt < path.size())
	{
		std::cout << cpt << endl;
		setForwardSpeed(fSpeed);
		Vector2 dist = owner.getPosition() - nextNode->getPosition();
		if (Maths::nearZero(dist.length(), 2.0f))
		{
			cpt++;
			if (cpt < path.size())
			{
				nextNode = owner.getGame().getGrid()->getTile(path.at(cpt).x, path.at(cpt).y);
				turnTo(nextNode->getPosition());
			}
		}
	}
	else
	{
		setForwardSpeed(0.0f);
	}
	MoveComponent::update(dt);
}

void NavComponent::turnTo(const Vector2& targetPosition)
{
	Vector2 dir = targetPosition - owner.getPosition();
	float angle = Maths::atan2(-dir.y, dir.x);
	owner.setRotation(angle);
}

void NavComponent::initializePath(std::vector<Vector2> pathP)
{
	path.clear();
	path = pathP;
	cpt = 1;
	nextNode = owner.getGame().getGrid()->getTile(path.at(cpt).x, path.at(cpt).y);
	turnTo(nextNode->getPosition());
}

void NavComponent::setFSpeed(float fSpeedP)
{
	fSpeed = fSpeedP;
}
