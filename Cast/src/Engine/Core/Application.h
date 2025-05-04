#pragma once

#include "Engine/ImGuiLayers/ImGuiLayer.h"

#include "Scene/scene_manager.h"
#include "Renderer/Renderer.h"

class Hitbox {
public:
	glm::vec2 position;
	glm::vec2 size;

	Hitbox(glm::vec2 pos, glm::vec2 size) : position(pos), size(size) {}
	bool intersects(const Hitbox& other) const
	{
		return position.x < other.position.x + other.size.x &&
			position.x + size.x > other.position.x &&
			position.y < other.position.y + other.size.y &&
			position.y + size.y > other.position.y;
	}
	void draw(Shader shaderProgram, GLuint VAO) const
	{
		shaderProgram.Bind();
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(position, 0.0f));
		model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
		model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
		model = glm::scale(model, glm::vec3(size, 1.0f));

		
		GLuint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
		GLuint projectionLoc = glGetUniformLocation(shaderProgram.ID, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		float vertices[] = {
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f
		};

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VAO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glDrawArrays(GL_LINE_STRIP, 0, 5);
		glBindVertexArray(0);
	}
};

class GameObject {
public:
	Hitbox hitbox;
	glm::vec2 velocity;

	GameObject(glm::vec2 pos, glm::vec2 size, glm::vec2 velocity) : hitbox(pos, size), velocity(velocity) {}
	void update(float deltaTime)
	{
		hitbox.position += velocity * deltaTime;
		checkBounds();
	}
	void draw(Shader shaderProgram, GLuint VAO) const
	{
		hitbox.draw(shaderProgram, VAO);
	}

private:
	void checkBounds()
	{
		if (hitbox.position.x > 800.0f) { hitbox.position.x = -hitbox.size.x; }
	}
};

class Application
{
public:
	Application(int _screenWidth, int _screenHeight);
	void Update();
	void Render();
	void HandleInput();

	ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

	inline static Application& Get() { return *s_Instance; }

	void SetWindow(GLFWwindow* win) { window = win; }
	GLFWwindow* GetWindow() { return window; }
public:
	SceneManager scene;
	int screenWidth, screenHeight;

	inline RenderContext& GetRenderContext() 
	{
		return m_renderContext;
	};
private:
	void CameraRenderer();
	void ImGuiRender();

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);
	void OnEvent();

private:
	RenderContext m_renderContext;
	Renderer renderer;

	GLuint VAO, VBO;
	std::vector<GameObject> objects;

	Shader shader;

	ImGuiLayer* m_ImGuiLayer;
	LayerStack m_LayerStack;

	GLFWwindow* window = nullptr;

	static Application* s_Instance;
};