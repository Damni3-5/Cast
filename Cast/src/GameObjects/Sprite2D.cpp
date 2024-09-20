#include "Sprite2D.h"

#include "Input.h"

Sprite2D::Sprite2D(Texture2D& _texture, float x, float y, float scale)
{
	this->texture = &_texture;
	this->position = Vector2(x, y);
	this->scale = scale;
	this->sourceRec = { 0.0f,0.0f, (float)texture->width, (float)texture->height };
	this->destRec = { position.x, position.y, (float)texture->width * scale, (float)texture->height * scale };
	this->origin = { 0.0f, 0.0f };
}

void Sprite2D::Draw(const Camera2D& camera, Color color) const
{
	const Vector2 screenPosition = GetWorldToScreen2D(this->position, camera);

	const Rectangle adjustedDestRec = {
		screenPosition.x,
		screenPosition.y,
		destRec.width * camera.zoom * scale,
		destRec.height * camera.zoom * scale
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

bool Sprite2D::IsMouseOver(const Camera2D& camera) const
{
	const Vector2 mousePosWorld = GetScreenToWorld2D({ Input::GetMouseX(), Input::GetMouseY() }, camera);
	return CheckCollisionPointRec(mousePosWorld, destRec);
}

bool Sprite2D::IsMouseClicked(const Camera2D& camera, int mouse_button) const
{
	return IsMouseOver(camera) && Input::IsMouseButtonPressed(mouse_button);
}



