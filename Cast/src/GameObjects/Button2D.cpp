#include "Button2D.h"

#include "Input.h"

void Button2D::Draw(const Camera2D& camera) const
{
    const Vector2 screenPosition = GetWorldToScreen2D(position, camera);
    DrawRectangle(screenPosition.x, screenPosition.y, size.x, size.y, color);

    const Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), fontSize, 1.0f);
    const Vector2 textPosition = {
        screenPosition.x + (size.x - textSize.x) / 2,
        screenPosition.y + (size.y - textSize.y) / 2
    };
    DrawText(text.c_str(), textPosition.x, textPosition.y, fontSize, WHITE);
}

bool Button2D::CheckClick(const Camera2D& camera) 
{
    const Vector2 worldMousePosition = GetScreenToWorld2D({ Input::GetMouseX(), Input::GetMouseY() }, camera);

    if (CheckCollisionPointRec(worldMousePosition, { position.x, position.y, size.x, size.y }))
    {
        if (Input::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            isPressed = true;
        else
            isPressed = false;
    }
    return isPressed;
}

void Button2D::SetText(const std::string& _text)
{
    text = _text;
}

void Button2D::SetPosition(float x, float y)
{
    position = { x, y };
}

void Button2D::SetSize(float width, float height)
{
    size = { width, height };
}

void Button2D::SetColor(Color _color)
{
    color = _color;
}

const std::string& Button2D::GetText() const
{
    return text;
}

Vector2 Button2D::GetPosition() const
{
    return position;
}

Vector2 Button2D::GetSize() const
{
    return size;
}

Color Button2D::GetColor() const
{
    return color;
}