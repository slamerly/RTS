#include "Border.h"
#include "SpriteComponent.h"
#include "Assets.h"

Border::Border() :
	Actor()
{
	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Border"));
}
