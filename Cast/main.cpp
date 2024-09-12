#include "src/Game.h"

int main()
{
    const int screenWidth = 600, screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [Minesweeper]");

    SetTargetFPS(75);
    
    rlImGuiSetup(true);

    Game game(screenWidth, screenHeight);

    while(!WindowShouldClose()) // спрайт(с хитбоксом), Игрок, Загрузка текстур в imgui, свободная карта, расстановка текстур
    {                           // сохранение карты, загрузка, драг енд дроп текстуры
        game.HandleInput();     // TileMap Text2D AnimatedSprite2D Button2D ParticleSystem2D Light2D Collider2D Sound2D TriggerZone2D UIElement
        game.Update(); 
        game.Render();          
    }

    CloseWindow();

    return 0;
}



