#include "ResourceManager.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

std::map<std::string, Texture2D> ResourceManager::Textures;

Texture2D ResourceManager::LoadTextureR(std::string name, const char* file, bool is_png)
{
	Textures[name] = loadTextureFromFile(file, is_png);
	return Textures[name];
}

Texture2D& ResourceManager::GetTextureR(std::string name)
{
	return Textures[name];
}

Vector2 ResourceManager::GetTextureSize(std::string name)
{
	return Vector2(Textures[name].width, Textures[name].height);
}

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool is_png)
{
	Texture2D texture;

	if (is_png)
		texture = LoadTexture(file);
	else if (!is_png)
	{
		int width, height, channels;
		unsigned char* data = stbi_load(file, &width, &height, &channels, 0);
		Image img;
		img =
		{
			.data = data, 
			.width = width, .height = height,
			.mipmaps = 1,
			.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8
		};
		texture = LoadTextureFromImage(img);
		stbi_image_free(data);
	}
	else
	{
		printf("Ошибка загрузки изображения: %s\n", stbi_failure_reason());
	}

	return texture;
}