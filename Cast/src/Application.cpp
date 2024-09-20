#include "Application.h"

#include "Events/KeyEvent.h"
#include "Input.h"

Application* Application::s_Instance = nullptr;

Application::Application(int _screenWidth, int _screenHeight)
{
	s_Instance = this;

	this->screenHeight = _screenHeight;
	this->screenWidth = _screenWidth;
	this->game_state = EDITOR;

	this->camera.target = { 0.0f, 0.0f };
	this->camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
	this->camera.rotation = 0.0f;
	this->camera.zoom = 1.0f;

	ResourceManager::LoadTextureR("tiles", "textures/tiles.jpg", false);
	ResourceManager::LoadTextureR("back", "textures/back.jpg", false);

	this->image = Image2D(ResourceManager::GetTextureR("back"), 0, 0, 0.5f);
	this->sprite = Sprite2D(ResourceManager::GetTextureR("tiles"), 10, 10, 1.0f);
	this->button = Button2D("Jerfinidos", 150, 150, 200, 200, WHITE);
	this->text = Text2D("DemonNex", 100, 100, 10, RED);

	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);
	PushLayer();
}

void Application::Update()
{
	image.SetAsBackground();
	image.Draw();

	sprite.Draw(camera);

	text.Draw(camera);
	
	button.Draw(camera);

	if (button.CheckClick(camera))
		button.SetColor(RED);
	else
		button.SetColor(BLUE);
}

void Application::Render()
{
	BeginDrawing();
	ClearBackground(darkBlue);
	BeginMode2D(camera);


	EndMode2D();

	
	DrawText(timer.GetElapsedTimeString().c_str(), 10, 10, 20, WHITE);


	//if(game_state == EDITOR) 
	//	ImGuiRender();
	EndDrawing();
}

void Application::HandleInput()
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

	}
	sprite.SetPosition(sprite.GetPosition().x + 1, sprite.GetPosition().y);

	this->CameraRenderer();
}

void Application::CameraRenderer()
{
		if (IsKeyDown(KEY_D)) this->camera.target.x += 50;
		if (IsKeyDown(KEY_A)) this->camera.target.x -= 50;
		if (IsKeyDown(KEY_W)) this->camera.target.y -= 50;
		if (IsKeyDown(KEY_S)) this->camera.target.y += 50;

		const float mouseWheelMove = GetMouseWheelMove();
		this->camera.zoom += mouseWheelMove * 0.08f;
		if (this->camera.zoom < 0.1f) this->camera.zoom = 0.1f;
}

void Application::ImGuiRender()
{
	ImGuiIO& io = ImGui::GetIO();

	for (int i = 0; i < 512; i++) 
	{
		io.KeysDown[i] = IsKeyDown(i);
	}

	io.KeyShift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
	io.KeyCtrl = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
	io.KeyAlt = IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);
	io.KeySuper = IsKeyDown(KEY_LEFT_SUPER) || IsKeyDown(KEY_RIGHT_SUPER);

	int keyPressed = GetCharPressed();
	if (keyPressed > 0) 
		io.AddInputCharacter((unsigned int)keyPressed);

	ImGui_ImplRaylib_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Info2");
	
	ImGuiShowObjectInfo(sprite);
	ImGuiShowObjectInfo(text);

	ImGui::End();
	ImGui::Render();

	ImGui_ImplRaylib_RenderDrawData(ImGui::GetDrawData());
}

void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);

	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	{
		if (e.Handled)
			break;
		(*it)->OnEvent(e);
	}
}