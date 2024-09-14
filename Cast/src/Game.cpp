#include "Game.h"

#include "Events/KeyEvent.h"
#include "Input.h"
#include "functions.h"

Game::Game(int _screenWidth, int _screenHeight)
{
	this->screenHeight = _screenHeight;
	this->screenWidth = _screenWidth;
	this->state = MENU;

	this->camera.target = { 0.0f, 0.0f }; 
	this->camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	this->camera.rotation = 0.0f;
	this->camera.zoom = 1.0f;

	ResourceManager::LoadTextureR("tiles", "textures/tiles.jpg", false);
	ResourceManager::LoadTextureR("back", "textures/back.jpg", false);

	this->image = Image2D(ResourceManager::GetTextureR("back"), 0, 0, 0.5f);
	this->sprite = Sprite2D(ResourceManager::GetTextureR("tiles"), 10, 10, 10.0f);
	this->button = Button2D("Jerfinidos", 150, 150, 200, 200, WHITE);
}

void Game::Update()
{
	image.SetAsBackground();
	image.Draw();

	sprite.Draw(camera);

	Text2D text("DemonNex", 100, 100, 10, WHITE);
	text.Draw(camera);

	
	button.Draw(camera);

	if (button.CheckClick(camera))
		button.SetColor(RED);
	else
		button.SetColor(BLUE);
}

void Game::Render()
{
	BeginDrawing();
	ClearBackground(darkBlue);
	BeginMode2D(camera);



	EndMode2D();

	
	DrawText(timer.GetElapsedTimeString().c_str(), 10, 10, 20, WHITE);

	ImGuiRender();
	EndDrawing();
}

void Game::HandleInput()
{
	if (Input::IsKeyPressed(KEY_Q))
	{
		timer.Start();
	}
	if (Input::IsKeyPressed(KEY_E))
	{
		timer.Stop();
	}
	if (sprite.IsMouseClicked(camera)) // Input::IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
	{
		std::cout << 1;
	}

	this->CameraRenderer();
}

void Game::CameraRenderer()
{
	if (IsKeyDown(KEY_D)) this->camera.target.x += 50;
	if (IsKeyDown(KEY_A)) this->camera.target.x -= 50;
	if (IsKeyDown(KEY_W)) this->camera.target.y -= 50;
	if (IsKeyDown(KEY_S)) this->camera.target.y += 50;

	if (IsKeyDown(KEY_R)) this->camera.zoom += 0.05f;
	if (IsKeyDown(KEY_F)) this->camera.zoom -= 0.05f;
	if (this->camera.zoom < 0.1f) this->camera.zoom = 0.1f;
}

void Game::ImGuiRender()
{
	rlImGuiBegin();
	ImGui::Text("Debug Console");
	rlImGuiEnd();
}