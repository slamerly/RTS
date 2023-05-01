#pragma once
#include "MoveComponent.h"
#include <SDL_stdinc.h>

class InputComponent : 
	public MoveComponent
{
public:
	InputComponent(Actor* ownerP);
	InputComponent() = delete;
	InputComponent(const InputComponent&) = delete;
	InputComponent& operator=(const InputComponent&) = delete;

	void processInput(const Uint8* keyState);

	void setMaxForwardSpeed(float maxForwardSpeedP);
	void setMaxUpSpeed(float maxUpSpeedP);
	void setMaxAngularSpeed(float maxAngularSpeedP);
	void setForwardKey(int key);
	void setBackKey(int key);
	void setLeftKey(int key);
	void setRightKey(int key);
	void setUpKey(int key);
	void setDownKey(int key);
	void setClockwiseKey(int key);
	void setCounterClockwiseKey(int key);

	void setCrash(bool crashP);

private:
	float maxForwardSpeed;
	float maxUpSpeed;
	float maxAngularSpeed;

	float forwardSpeed;
	float upSpeed;
	float angularSpeed;

	int forwardKey;
	int backKey;
	int leftKey;
	int rightKey;
	int upKey;
	int downKey;
	int clockwiseKey;
	int counterClockwiseKey;

	bool crash;
};