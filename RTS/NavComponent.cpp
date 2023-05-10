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
	//cout << "soldier : " << owner.getPosition().x << ", " << owner.getPosition().y << endl;
	if (cpt < path.size())
	{
		//std::cout << cpt << endl;
		setForwardSpeed(fSpeed);
		forwardSpeed = fSpeed;
		Vector2 dist = owner.getGridPosition() - nextNode->getGridPosition();
		if (Maths::nearZero(dist.length(), 2.0f))
		{
			cpt++;
			if (cpt < path.size())
			{
				//cout << path.at(cpt).x << ", " << path.at(cpt).y << " : " << endl;
				 
				
				nextNode = owner.getGame().getGrid()->getTile(path.at(cpt).x, path.at(cpt).y);
				//cout << "initiale : " << nextNode->getPosition().x << ", " << nextNode->getPosition().y << endl;
				turnTo(nextNode->getGridPosition());
			}
			else
			{
				setForwardSpeed(0.0f);
				forwardSpeed = 0;
				owner.inMovement = false;
				//owner.setInitPosition(nextNode->getPosition());
			}
			//owner.setInitPosition(owner.getPosition());
		}
		else
		{
			//cout << nextNode->getPosition().x << ", " << nextNode->getPosition().y << endl;
			//owner.setInitPosition(owner.getPosition());
			//turnTo(nextNode->getPosition());
		}
	}
	else
	{
		//setForwardSpeed(0.0f);
	}
	//MoveComponent::update(dt);
	if (!Maths::nearZero(forwardSpeed))
	{
		//Vector2 newPosition = owner.getPosition() + (owner.valueAddView * 0.1f);
		//newPosition += owner.getForward() * forwardSpeed * dt;
		Vector2 newPosition = owner.getGridPosition() + owner.getForward() * forwardSpeed * dt;
		/*
		if (owner.valueAddView != Vector2::zero)
		{
			newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt + owner.valueAddView;
		}
		*/
		owner.setGridPosition(newPosition);
	}
	owner.valueAddView = Vector2::zero;
}

void NavComponent::turnTo(const Vector2& targetPosition)
{
	Vector2 dir = targetPosition - owner.getGridPosition();
	float angle = Maths::atan2(-dir.y, dir.x);
	owner.setRotation(angle);
}

void NavComponent::initializePath(std::vector<Vector2> pathP)
{
	path.clear();
	path = pathP;
	cpt = 1;
	nextNode = owner.getGame().getGrid()->getTile(path.at(cpt).x, path.at(cpt).y);
	owner.inMovement = true;
	turnTo(nextNode->getGridPosition());
}

void NavComponent::setFSpeed(float fSpeedP)
{
	fSpeed = fSpeedP;
}
