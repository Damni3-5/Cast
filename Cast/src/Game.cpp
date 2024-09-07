#include "Game.h"

Game::Game(int _screenWidth, int _screenHeight)
{
	this->screenHeight = _screenHeight;
	this->screenWidth = _screenWidth;
	this->state = MENU;

	ResourceManager::LoadTextureR("tiles", "textures/tiles.jpg", false);

	this->GameField = new Field(15, 15);
	//this->PlayerField = new Field(15, 15);

	//this->sprite = Sprite2D(ResourceManager::GetTextureR("tiles"), 100, 100, 1.0f); // Texture2D texture, float x, float y, float scale
}

void Game::Update()
{
	static float timer;
	static int frame;

	BeginDrawing();
	ClearBackground(darkBlue);

	GameField->Draw(screenWidth, screenHeight);

	timer += GetFrameTime();
	if (timer >= 0.3f) 
	{
		timer = 0.0f;
		frame++;
	}

	rlImGuiBegin();
	ImGui::Text("Hello, world!");
	
	rlImGuiEnd();

	EndDrawing();
}

void Game::HandleInput()
{
	
}