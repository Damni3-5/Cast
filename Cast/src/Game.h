#pragma once

#include "colors.h"
#include "GameObjects/Sprite2D.h"
#include "GameObjects/Image2D.h"
#include "GameObjects/Timer.h"

#include <imgui.h>

#include "imgui/rlImGui.h"
#include "imgui/imgui_impl_raylib.h"

enum GameState {MENU = 0, GAME, END};

class Game
{
public:
	Game(int _screenWidth, int _screenHeight);
	void Update();
	void Render();
	void HandleInput();

	GameState state;
private:
	void ImGuiRender();
private:
	int screenWidth, screenHeight;

	Image2D image;
	Sprite2D sprite;
	Camera2D camera;
	Timer timer;
};