#pragma once

#include "Field.h"
#include "colors.h"
#include "Sprite2D.h"

#include <imgui.h>

#include "imgui/rlImGui.h"
#include "imgui/imgui_impl_raylib.h"

enum GameState {MENU = 0, GAME, END};

class Game
{
public:
	Game(int _screenWidth, int _screenHeight);
	void Update();
	void HandleInput();

	GameState state;
private:
	int screenWidth, screenHeight;

	Sprite2D sprite;

	Field* GameField;
	Field* PlayerField;
};