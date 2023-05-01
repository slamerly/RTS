#pragma once
#include <map>
#include <string>
#include "Texture.h"
#include "Font.h"
using std::map;
using std::string;

// A static singleton Assets class that hosts several functions to load resources. 
// Each loaded resource is also stored for future reference by string handles. 
// All functions and resources are static and no public constructor is defined.
class Assets
{
public:
    static std::map<std::string, Texture> textures;
    static std::map<std::string, Font> fonts;

    // Loads a texture from file
    static Texture loadTexture(Renderer& renderer, const string& filename, const string& name);

    // Loads a font
    static Font loadFont(const string& filename, const int& size, const string& name);

    // Retrieves a stored texture
    static Texture& getTexture(const string& name);

    // Retrieves a stored font
    static Font& getFont(const string& name);

    // Properly de-allocates all loaded resources
    static void clear();

private:
    Assets() {}

    // Loads a single texture from file
    static Texture loadTextureFromFile(Renderer& renderer, const string& filename);

    // Loads a single font from file
    static Font loadFontFromFile(const string& filename, const int& size);
};