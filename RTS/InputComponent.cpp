#include "InputComponent.h"
#include <SDL_scancode.h>
#include <iostream>
#include "Maths.h"

InputComponent::InputComponent(Actor* ownerP) :
	MoveComponent(ownerP),
	maxForwardSpeed(100.0f),
	maxAngularSpeed(1.0f),
	forwardKey(SDL_SCANCODE_W),
	backKey(SDL_SCANCODE_S),
	leftKey(SDL_SCANCODE_LEFT),
	rightKey(SDL_SCANCODE_RIGHT),
	upKey(SDL_SCANCODE_UP),
	downKey(SDL_SCANCODE_DOWN),
	clockwiseKey(SDL_SCANCODE_D),
	counterClockwiseKey(SDL_SCANCODE_A),
	forwardSpeed(0.0f),
	upSpeed(0.0f),
	angularSpeed(0.0f),
	crash(false)
{
}

void InputComponent::processInput(const Uint8* keyState)
{
	if (keyState[upKey])
	{
		//forwardSpeed += maxForwardSpeed;
		if (forwardSpeed < maxForwardSpeed)
			forwardSpeed += 1.0f;
	}
	else if (keyState[downKey])
	{
		if (forwardSpeed > 0)
		{ 
			forwardSpeed -= 3.0f;		
		}
		else if (forwardSpeed > (maxForwardSpeed / 2) * -1)
		forwardSpeed -= 1.0f;
	}
	else
	{
		if(forwardSpeed > 0)
			forwardSpeed -= 2.0f;
		if (forwardSpeed < 0)
			forwardSpeed += 2.0f;
	}

	//std::cout << forwardSpeed << std::endl;
	if(!crash)
		setForwardSpeed(forwardSpeed);
	else
	{
		setForwardSpeed((forwardSpeed / 2) * -1);
		if (forwardSpeed > 0)
			forwardSpeed -= 2.0f;
		if (forwardSpeed < 0)
			forwardSpeed += 2.0f;
		if (forwardSpeed == 0)
			crash = false;
	}
	
	if (keyState[rightKey])
	{
		if (angularSpeed > -maxAngularSpeed)
		{
			angularSpeed -= Maths::toRadians(5.0f);
		}
	}
	else if (keyState[leftKey])
	{
		if (angularSpeed < maxAngularSpeed)
		{
			angularSpeed += Maths::toRadians(5.0f);
		}
	}
	else
	{
		if (angularSpeed > 0)
			angularSpeed -= Maths::toRadians(10.0f);
		if (angularSpeed < 0)
			angularSpeed += Maths::toRadians(10.0f);
	}
	setAngularSpeed(angularSpeed);
	
	/*
	float upSpeed = 0.0f;
	if (keyState[upKey])
	{
		upSpeed += maxUpSpeed;
	}
	if (keyState[downKey])
	{
		upSpeed -= maxUpSpeed;
	}
	setUpSpeed(upSpeed);
	*/
}

void InputComponent::setMaxForwardSpeed(float maxForwardSpeedP)
{
	maxForwardSpeed = maxForwardSpeedP;
}

void InputComponent::setMaxUpSpeed(float maxUpSpeedP)
{
	maxUpSpeed = maxUpSpeedP;
}

void InputComponent::setMaxAngularSpeed(float maxAngularSpeedP)
{
	maxAngularSpeed = maxAngularSpeedP;
}

void InputComponent::setForwardKey(int key)
{
	forwardKey = key;
}

void InputComponent::setBackKey(int key)
{
	backKey = key;
}

void InputComponent::setLeftKey(int key)
{
	leftKey = key;
}

void InputComponent::setRightKey(int key)
{
	rightKey = key;
}

void InputComponent::setUpKey(int key)
{
	upKey = key;
}

void InputComponent::setDownKey(int key)
{
	downKey = key;
}

void InputComponent::setClockwiseKey(int key)
{
	clockwiseKey = key;
}

void InputComponent::setCounterClockwiseKey(int key)
{
	counterClockwiseKey = key;
}

void InputComponent::setCrash(bool crashP)
{
	crash = crashP;
}
