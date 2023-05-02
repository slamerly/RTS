#pragma once
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "Grid.h"
#include "Moto.h"
#include "Commander.h"
#include "Soldier.h"

using std::vector;

class Game
{
//Begin singleton
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;
	Game(const Game&&) = delete;
	Game& operator = (const Game&&) = delete;

private:
	//Game() = default;
	Game() : isRunning(true), isUpdatingActors(false){}

//End singleton

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	vector<Actor*> getActors() { return actors; }

	Renderer& getRenderer() { return renderer; }

	// Game specific
	vector<Moto*> getMotos() { return motos; }
	bool getPartyIsEnd() { return partyIsEnd; }
	Grid* getGrid() { return grid; }
	void endGame();

private:
	void processInput();
	void update(float dt);
	void render();

	// Game specific
	void newParty();
	void motoInit();

	Window window {};
	Renderer renderer;
	bool isRunning { true };

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	// Game specific
	Grid* grid;
	vector<Moto*> motos;
	vector<Soldier*> soldiers;
	Commander* command;

	bool partyIsEnd = false;
};

