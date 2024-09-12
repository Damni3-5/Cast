#pragma once 

#include "ResourceManager.h"

class Image2D
{
public:
	Image2D() = default;
	Image2D(Texture2D& _texture, float x, float y, float scale = 1.0f);

	void Draw(Color color = WHITE) const;
	void SetPosition(float x, float y);
	void SetScale(float NewScale);
	void SetRotation(float angle);
	void SetFrame(int frame, int frameWidth, int frameHeight);

	void SetAsBackground();
private:
	Texture2D* texture;
	Vector2 position;
	float scale;
	float rotation = 0.0f;
	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 origin;
};