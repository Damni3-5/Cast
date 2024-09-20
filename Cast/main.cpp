#include "src/Application.h"

int main(int argc, char** argv)
{
    const int screenWidth = 1200, screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [Cast]");

    SetTargetFPS(75);

    Application game(screenWidth, screenHeight);

    while(!WindowShouldClose()) // спрайт(с хитбоксом), Игрок, Загрузка текстур в imgui, свободная карта, расстановка текстур
    {                           // сохранение карты, загрузка, драг енд дроп текстуры
                                // TileMap AnimatedSprite2D Light2D Collider2D Sound2D TriggerZone2D UIElement
        game.Update(); 
        game.Render();
        game.HandleInput();
    }

    CloseWindow();

    return 0;
}



