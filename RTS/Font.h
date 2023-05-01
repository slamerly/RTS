#pragma once
#include <string>
#include "Renderer.h"
#include <SDL_ttf.h>

using std::string;

class Font
{
public:
	Font();
	~Font();

	bool load(const string& filenameP, int sizeP);
	inline TTF_Font* toTFFFont() const { return TFFFont; }
	void updateInfo(int& sizeOut);

	inline int getSize() const { return size; }

private:
	string filename;
	TTF_Font* TFFFont;
	int size;
};

