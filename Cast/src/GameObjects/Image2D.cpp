#include "Image2D.h"

Image2D::Image2D(Texture2D& _texture, float x, float y, float scale)
{
	this->texture = &_texture;
	this->position = Vector2(x, y);
	this->scale = scale;
	this->sourceRec = { 0.0f,0.0f, (float)texture->width, (float)texture->height };
	this->destRec = { position.x, position.y, (float)texture->width * scale, (float)texture->height * scale };
	this->origin = { 0.0f, 0.0f };
}

void Image2D::Draw(Color color) const
{
	DrawTexturePro(*texture, sourceRec, destRec, origin, rotation, color);
}

void Image2D::SetPosition(float x, float y)
{
	this->position = { x, y };
	this->destRec.x = x;
	this->destRec.y = y;
}

void Image2D::SetScale(float NewScale)
{
	this->scale = NewScale;
}

void Image2D::SetRotation(float angle)
{
	this->rotation = angle;
}

void Image2D::SetFrame(int frame, int frameWidth, int frameHeight)
{
	this->sourceRec.x = (float)(frame % (texture->width / frameWidth)) * frameWidth;
	this->sourceRec.y = (float)(frame / (texture->width / frameWidth)) * frameHeight;
	this->sourceRec.width = (float)frameWidth;
	this->sourceRec.height = (float)frameHeight;

	this->destRec.width = (float)frameWidth * scale;
	this->destRec.height = (float)frameHeight * scale;
}

void Image2D::SetAsBackground()
{
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();

	this->destRec.x = 0;
	this->destRec.y = 0;
	this->destRec.width = (float)screenWidth;
	this->destRec.height = (float)screenHeight;

	this->scale = std::min((float)screenWidth / texture->width, (float)screenHeight / texture->height);
}