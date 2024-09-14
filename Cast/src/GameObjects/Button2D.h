#pragma once

#include <raylib.h>
#include <string>

class Button2D {
public:
    Button2D() = default;
    Button2D(const std::string& _text, float x, float y, float width, float height, Color _color)
        : text(_text), position({ x, y }), size({ width, height }), color(_color), isPressed(false) {}

    void Draw(const Camera2D& camera) const;
    bool CheckClick(const Camera2D& camera);
    void SetText(const std::string& _text);
    void SetPosition(float x, float y);
    void SetSize(float width, float height);
    void SetColor(Color _color);
    const std::string& GetText() const;
    Vector2 GetPosition() const;
    Vector2 GetSize() const;
    Color GetColor() const;

private:
    std::string text;
    Vector2 position;
    Vector2 size;
    Color color;
    bool isPressed;
    int fontSize = 20;
};
