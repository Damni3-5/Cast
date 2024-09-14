#pragma once

#include "ResourceManager.h"

class Sprite2D
{
public:
	Sprite2D() = default;
	Sprite2D(Texture2D& _texture, float x, float y, float scale = 1.0f);

	void Draw(const Camera2D& camera, Color color = WHITE) const;
	void SetPosition(float x, float y);
	void SetScale(float NewScale);
	void SetRotation(float angle);
	void SetFrame(int frame, int frameWidth, int frameHeight);

	bool IsMouseOver(const Camera2D& camera) const;
	bool IsMouseClicked(const Camera2D& camera, int mouse_button = MOUSE_LEFT_BUTTON) const;

private:
	Texture2D* texture;
	Vector2 position;
	float scale;
	float rotation = 0.0f;
	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 origin;
};