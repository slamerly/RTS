#pragma once
#include "MoveComponent.h"
#include "Vector2.h"
#include <vector>

class NavComponent : public MoveComponent
{
public:
	NavComponent(class Actor* owner, int updateOrder = 10);
	NavComponent() = delete;
	NavComponent(const NavComponent&) = delete;
	NavComponent& operator=(const NavComponent&) = delete;

	void update(float dt) override;
	void turnTo(const Vector2& targetPosition);
	void initializePath(std::vector<Vector2> pathP);
	void setFSpeed(float fSpeedP);

private:
	const class Tile* nextNode;
	std::vector<Vector2> path;
	float fSpeed = 0.0f;
	int cpt = 0;
};