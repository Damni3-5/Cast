#pragma once

#include <raylib.h>
#include <string>

class Text2D 
{
public:
    Text2D() = default;
    Text2D(const std::string& _text, float x, float y, int _fontSize, Color _color)
        : text(_text), position({ x, y }), fontSize(_fontSize), color(_color) {}

    void Draw(const Camera2D& camera) const;
    void SetText(const std::string& _text);
    void SetPosition(float x, float y);
    void SetFontSize(int _fontSize);
    void SetColor(Color _color);
public:
    std::string& GetText() { return text; }
    int& GetFontSize() { return fontSize; }
    Vector2& GetPosition() { return position; }
    Color& GetColor() { return color; }
private:
    std::string text;
    Vector2 position;
    int fontSize;
    Color color;
};