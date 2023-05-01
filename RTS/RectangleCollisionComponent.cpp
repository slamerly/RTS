#include "RectangleCollisionComponent.h"
#include "Actor.h"
#include <iostream>

RectangleCollisionComponent::RectangleCollisionComponent(Actor* owner) : 
	Component(owner), width(1.0f), heigh(1.0f)
{
}

float RectangleCollisionComponent::getWidth() const
{
	return owner.getScale() * width;
}

float RectangleCollisionComponent::getHeigh() const
{
	return owner.getScale() * heigh;
}

void RectangleCollisionComponent::setWidth(float widthP)
{
	width = widthP;
}

void RectangleCollisionComponent::setHeigh(float heighP)
{
	heigh = heighP;
}

const Vector2 RectangleCollisionComponent::getCenter() const
{
	return owner.getPosition();
}

bool Intersect(const RectangleCollisionComponent& a, const RectangleCollisionComponent& b)
{
	bool xCollision = false;
	bool yCollision = false;
	Vector2 aCenter = a.getCenter();
	Vector2 bCenter = b.getCenter();
	Vector2 ab = bCenter - aCenter;
	float sumOfWidth = a.getWidth()/2 + b.getWidth()/2;
	float sumOfHeigh = a.getHeigh()/2 + b.getHeigh()/2;
	if (abs(ab.x) <= sumOfWidth)
		xCollision = true;
	if (abs(ab.y) <= sumOfHeigh)
		yCollision = true;
	return xCollision && yCollision;
}

bool Intersect(const RectangleCollisionComponent& a, const CircleCollisionComponent& b)
{
	bool xCollision = false;
	bool yCollision = false;
	Vector2 aCenter = a.getCenter();
	Vector2 bCenter = b.getCenter();
	Vector2 ab = bCenter - aCenter;
	float sumOfWidth = a.getWidth()/2 + b.getRadius();
	float sumOfHeigh = a.getHeigh()/2 + b.getRadius();
	if (abs(ab.x) <= sumOfWidth)
		xCollision = true;
	if (abs(ab.y) <= sumOfHeigh)
		yCollision = true;
	return xCollision && yCollision;
}

bool Intersect(const CircleCollisionComponent& a, const RectangleCollisionComponent& b)
{
	bool xCollision = false;
	bool yCollision = false;
	Vector2 aCenter = a.getCenter();
	Vector2 bCenter = b.getCenter();
	Vector2 ab = bCenter - aCenter;
	float sumOfWidth = a.getRadius() + b.getWidth()/2;
	float sumOfHeigh = a.getRadius() + b.getHeigh()/2;
	if (abs(ab.x) <= sumOfWidth)
		xCollision = true;
	if (abs(ab.y) <= sumOfHeigh)
		yCollision = true;
	return xCollision && yCollision;
}
