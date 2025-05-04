#include "Application.h"

#include "Input.h"

Application* Application::s_Instance = nullptr;

Application::Application(int _screenWidth, int _screenHeight) 
	: m_renderContext({0}), scene(m_renderContext)
{
	s_Instance = this;

	this->screenHeight = _screenHeight;
	this->screenWidth = _screenWidth;
	GLFWwindow* glfwWindow = glfwCreateWindow(screenHeight, screenWidth, "GLFW + ImGui", nullptr, nullptr);
	Application::Get().SetWindow(glfwWindow);
	glfwMakeContextCurrent(Application::Get().GetWindow());
	glfwSwapInterval(1);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	//ResourceManager::LoadTextureR("tiles", "textures/tiles.jpg", false);
	//ResourceManager::LoadTextureR("back", "textures/back.jpg", false);

	this->shader.Compile("shaders/v.glsl", "shaders/f.glsl");

	objects.emplace_back(glm::vec2(0, 100), glm::vec2(50, 50), glm::vec2(0, 0));
	objects.emplace_back(glm::vec2(0, 200), glm::vec2(50, 50), glm::vec2(300, 0));
	objects.emplace_back(glm::vec2(0, 300), glm::vec2(50, 50), glm::vec2(150, 0));

	this->renderer = Renderer();

	m_ImGuiLayer = new ImGuiLayer();
	PushLayer(new Layer("Demon"));
	PushOverlay(m_ImGuiLayer);
}

void Application::Update()
{
	glfwPollEvents();
	this->renderer.Clear(0.2f, 0.3f, 1.0f, 1.0f);
}

void Application::Render()
{
	GLfloat vertices[] = {
	-0.5f, -0.5f, 
	 0.5f, -0.5f, 
	 0.5f,  0.5f, 
	-0.5f,  0.5f  
	};

	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	VBuffer vbo(vertices, sizeof(vertices));
	IBuffer ibo(indices, 6);
	VArray vao;
	vao.Bind();
	//vbo.Bind();
	ibo.Bind();
	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr));
	this->shader.Bind();
	this->renderer.Draw(vao, ibo);

	const float deltaTime = 0.016f;

	for (auto& object : objects)
	{
		//object.update(deltaTime);
		object.draw(shader, vao.m_array);
	}

	for (Layer* layer : m_LayerStack) 
	{
		layer->OnUpdate(1);     
	}
	
	ImGuiRender();

	glfwSwapBuffers(Application::Get().GetWindow());
}
 
void Application::HandleInput()
{
	
	//if (Input::IsKeyPressed(KEY_Q))
	//{
	//	timer.Start();
	//}
	//if (Input::IsKeyPressed(KEY_E))
	//{
	//	timer.Stop();
	//}
	//if (sprite.IsMouseClicked(camera)) // Input::IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
	//{
	//
	//}
	//sprite.SetPosition(sprite.GetPosition().x + 1, sprite.GetPosition().y);
	//
	//this->CameraRenderer();
}

void Application::CameraRenderer()
{
		//if (IsKeyDown(KEY_D)) this->camera.target.x += 50;
		//if (IsKeyDown(KEY_A)) this->camera.target.x -= 50;
		//if (IsKeyDown(KEY_W)) this->camera.target.y -= 50;
		//if (IsKeyDown(KEY_S)) this->camera.target.y += 50;
		//
		//const float mouseWheelMove = GetMouseWheelMove();
		//this->camera.zoom += mouseWheelMove * 0.08f;
		//if (this->camera.zoom < 0.1f) this->camera.zoom = 0.1f;
}

void Application::ImGuiRender()
{
	m_ImGuiLayer->Begin();
	for (Layer* layer : m_LayerStack)
	{
		layer->OnImGuiRender();
	}
	m_ImGuiLayer->End();
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

void Application::OnEvent()
{
	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	{
		break;
	}
}