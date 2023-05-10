#pragma once
#include <vector>
#include <string>
#include "Vector2.h"
#include "SDL_stdinc.h"

using std::vector;

class Game;
class Component;

class Actor
{
public:
	enum class ActorState
	{
		Active, Paused, Dead
	};

	Actor();
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	Game& getGame() const { return game; }
	const ActorState getState() const { return state; }
	const Vector2 getPosition() const { return position; }
	const float getScale() const { return scale; }
	const float getRotation() const { return rotation; }
	Vector2 getForward() const;
	Vector2 getUp() const;

	void setPosition(Vector2 positionP);
	void setScale(float scaleP);
	void setRotation(float rotationP);
	void setState(ActorState stateP);

	void update(float dt);
	void updateComponents(float dt);
	virtual void updateActor(float dt);
	void addComponent(Component* component);
	void removeComponent(Component* component);
	void processInput(const Uint8* keyState);
	virtual void actorInput(const Uint8* keyState);

	// RTS
	Vector2 getInitPosition() { return initPos; }
	const Vector2 getGridPosition() const { return gridPosition; }
	std::string tag;
	bool inMovement = false;
	Vector2 valueAddView;
	Vector2 gridPosition;

	void setInitPosition(Vector2 initPosP);
	virtual void moveMap(Vector2 valueAdd);
	virtual void setGridPosition(Vector2 gridPositionP);

private:
	Game& game;
	ActorState state;
	Vector2 position;
	Vector2 initPos;
	float scale;
	float rotation;

	vector<Component*> components;	
};

