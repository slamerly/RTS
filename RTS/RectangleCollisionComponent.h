#pragma once
#include "Component.h"
#include "Vector2.h"
#include "CircleCollisionComponent.h"

class RectangleCollisionComponent :
    public Component
{
public:
    RectangleCollisionComponent(Actor* owner);
    RectangleCollisionComponent() = delete;
    RectangleCollisionComponent(const RectangleCollisionComponent&) = delete;
    RectangleCollisionComponent& operator=(const RectangleCollisionComponent&) = delete;

    float getWidth() const;
    float getHeigh() const;
    void setWidth(float widthP);
    void setHeigh(float heighP);

    const Vector2 getCenter() const;

private:
    float width;
    float heigh;
};

bool Intersect(const RectangleCollisionComponent& a, const RectangleCollisionComponent& b);
bool Intersect(const RectangleCollisionComponent& a, const CircleCollisionComponent& b);
bool Intersect(const CircleCollisionComponent& a, const RectangleCollisionComponent& b);

