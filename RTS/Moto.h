#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"

class Moto :
    public Actor
{
public:
    Moto();
    ~Moto();
    void updateActor(float dt) override;

    CircleCollisionComponent& getCollision() { return *collision; }
    InputComponent& getInputComponent() { return *inputComp; }
    SpriteComponent& getSpriteComponent() { return *spriteComp; }

private:
    CircleCollisionComponent* collision;
    InputComponent* inputComp;
    SpriteComponent* spriteComp;
};

