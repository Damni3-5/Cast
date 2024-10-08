#include "Text2D.h"

void Text2D::Draw(const Camera2D& camera) const
{
    const Vector2 screenPosition = GetWorldToScreen2D(this->position, camera);
    DrawText(text.c_str(), screenPosition.x, screenPosition.y, (int)(fontSize * camera.zoom), color);
}

void Text2D::SetText(const std::string& _text)
{
    text = _text;
}

void Text2D::SetPosition(float x, float y)
{
    position = { x, y };
}

void Text2D::SetFontSize(int  _fontSize)
{
    fontSize = _fontSize;
}

void Text2D::SetColor(Color _color)
{
    color = _color;
}
