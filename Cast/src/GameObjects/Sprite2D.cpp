#include "Sprite2D.h"

Sprite2D::Sprite2D(Texture2D& _texture, float x, float y, float scale)
{
	this->texture = &_texture;
	this->position = Vector2(x, y);
	this->scale = scale;
	this->sourceRec = { 0.0f,0.0f, (float)texture->width, (float)texture->height };
	this->destRec = { position.x, position.y, (float)texture->width * scale, (float)texture->height * scale };
	this->origin = { 0.0f, 0.0f };
}

void Sprite2D::Draw(Camera2D& camera, Color color) const
{
	const Vector2 screenPosition = GetWorldToScreen2D(this->position, camera);

	const Rectangle adjustedDestRec = {
		screenPosition.x,
		screenPosition.y,
		destRec.width * camera.zoom,
		destRec.height * camera.zoom
	};

	DrawTexturePro(*texture, sourceRec, adjustedDestRec, origin, rotation, color);
}

void Sprite2D::SetPosition(float x, float y)
{
	this->position = { x, y };
	this->destRec.x = x;
	this->destRec.y = y;
}

void Sprite2D::SetScale(float NewScale)
{
	this->scale = NewScale;
}

void Sprite2D::SetRotation(float angle)
{
	this->rotation = angle;
}

void Sprite2D::SetFrame(int frame, int frameWidth, int frameHeight)
{
	this->sourceRec.x = (float)(frame % (texture->width / frameWidth)) * frameWidth;
	this->sourceRec.y = (float)(frame / (texture->width / frameWidth)) * frameHeight;
	this->sourceRec.width = (float)frameWidth;
	this->sourceRec.height = (float)frameHeight;

	this->destRec.width = (float)frameWidth * scale;
	this->destRec.height = (float)frameHeight * scale;
}



