#include "src/Game.h"


int main()
{
    const int screenWidth = 750, screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "raylib [Minesweeper]");

    SetTargetFPS(75);
    
    rlImGuiSetup(true);

    Game game(screenWidth, screenHeight);

    while(!WindowShouldClose())
    {
        
        game.HandleInput();
        game.Update();
    }

    CloseWindow();

    return 0;
}
