#include "Font.h"
#include "Log.h"

Font::Font() : filename(""), size(0), TFFFont(nullptr)
{
}

Font::~Font()
{
}

bool Font::load(const string& filenameP, int sizeP)
{
	filename = filenameP;
	size = sizeP;
	TFFFont = TTF_OpenFont(filename.c_str(), size);
	if (TFFFont == nullptr)
	{
		Log::error(LogCategory::Application, "Failed to load font file " + filename);
		return false;
	}

	return true;
}

void Font::updateInfo(int& sizeOut)
{
	sizeOut = size;
}
