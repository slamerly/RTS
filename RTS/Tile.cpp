#include "Tile.h"
#include "Assets.h"
#include "Game.h"
#include <iostream>

Tile::Tile() :
	Actor(), collision(nullptr), sprite(nullptr), tileState(TileState::Default), isSelected(false)
{
	tag = "map";
}

void Tile::updateActor(float dt)
{
}

void Tile::setTileState(TileState tileStateP)
{
	tileState = tileStateP;
	updateTexture();
}

void Tile::setGridPosition(Vector2 gridPositionP)
{
	gridPosition = gridPositionP;
	//setPosition(getGame().getGrid()->getPosition() + getGridPosition());
}

void Tile::moveMap(Vector2 valueAdd)
{
	setPosition(getGame().getGrid()->getPosition() + getGridPosition());
}

void Tile::toggleSelect()
{
	isSelected = !isSelected;
	updateTexture();
}

void Tile::updateTexture()
{
	if (collision == nullptr)
	{
		collision = new RectangleCollisionComponent(this);
		collision->setHeigh(40);
		collision->setWidth(40);
	}

	switch (tileState)
	{
	case Tile::TileState::Border:
		if (sprite == nullptr)
			sprite = new SpriteComponent(this, Assets::getTexture("Border"));
		else
			sprite->setTexture(Assets::getTexture("Border"));
		break;
	case Tile::TileState::Building:
		if (sprite == nullptr)
			sprite = new SpriteComponent(this, Assets::getTexture("Building"));
		else
			sprite->setTexture(Assets::getTexture("Building"));
		break;
	case Tile::TileState::Tree:
		if (sprite == nullptr)
			sprite = new SpriteComponent(this, Assets::getTexture("Tree"));
		else
			sprite->setTexture(Assets::getTexture("Tree"));
		break;
	case TileState::EndLine:
		if (sprite == nullptr)
			sprite = new SpriteComponent(this, Assets::getTexture("EndLine"));
		else
			sprite->setTexture(Assets::getTexture("EndLine"));
		break;
	case Tile::TileState::Default:
	default:
		sprite = nullptr;
		collision = nullptr;
		break;
	}
}
