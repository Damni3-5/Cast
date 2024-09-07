#pragma once

#include "colors.h"

#include <iostream>
#include <string>
#include <map>

class ResourceManager
{
public:
	static std::map<std::string, Texture2D> Textures;

	static Texture2D LoadTextureR(std::string name, const char* file, bool is_png);
	static Texture2D& GetTextureR(std::string name);

	static Vector2 GetTextureSize(std::string name);
private:
 	ResourceManager() { }

	static Texture2D loadTextureFromFile(const char* file, bool is_png);
};