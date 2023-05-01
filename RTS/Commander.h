#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include "Grid.h"

class Commander :
    public Actor
{
public:
    Commander();

    void updateActor(float dt) override;
    void actorInput(const Uint8* keyState) override;

private:
    MoveComponent* mc;

    float forwardSpeed;
    float upSpeed;

    float maxForwardSpeed;
    float maxUpSpeed;

    Actor* map;
    Vector2 initPos;
    InputComponent* inputComp;

    void move();
};

