#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include "Grid.h"
#include "Soldier.h"

class Commander :
    public Actor
{
public:
    Commander();

    void actorInput(const Uint8* keyState) override;
    void addInSelection(Soldier* soldier);
    void removeInSelection(Soldier* soldier);

private:
    MoveComponent* mc;

    vector<Soldier*> selectedUnits;

    float forwardSpeed;
    float upSpeed;

    float maxForwardSpeed;
    float maxUpSpeed;

    void move();
    void unitMovement();
};

