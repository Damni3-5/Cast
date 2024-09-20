#pragma once

//#include "colors.h"
#include "GameObjects/Sprite2D.h"
#include "GameObjects/Image2D.h"
#include "GameObjects/Text2D.h"
#include "GameObjects/Button2D.h"
#include "GameObjects/Timer.h"

#include "ImGuiLayer.h"

//#include <nlohmann/json.hpp>

enum GameState {MENU = 0, GAME, END, EDITOR};

class Application
{
public:
	Application(int _screenWidth, int _screenHeight);
	void Update();
	void Render();
	void HandleInput();

	ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }


	inline static Application& Get() { return *s_Instance; }
	GameState game_state;
private:
	void CameraRenderer();
	void ImGuiRender();

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);
	void OnEvent(Event& e);

	//void LoadSprite(const nlohmann::json& obj);
	//void SaveSprite(nlohmann::json& obj, const Sprite2D& sprite);
private:
	int screenWidth, screenHeight;

	ImGuiLayer* m_ImGuiLayer;
	LayerStack m_LayerStack;

	Image2D image;
	Sprite2D sprite;
	Camera2D camera;
	Timer timer;
	Button2D button;
	Text2D text;
private:
	static Application* s_Instance;
};