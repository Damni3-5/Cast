#include "ImGuiLayer.h"
#include "Engine/Core/Application.h"

#include "Engine/Core/functions.h"



ImGuiLayer::ImGuiLayer()
	: Layer("ImGuiLayer")
{
}

void ImGuiLayer::OnAttach()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(Application::Get().GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 410");

	ImGuiIO& io = ImGui::GetIO();
	//io.KeyMap[ImGuiKey_Tab] = KEY_TAB;
	//io.KeyMap[ImGuiKey_LeftArrow] = KEY_LEFT;
	//io.KeyMap[ImGuiKey_RightArrow] = KEY_RIGHT;
	//io.KeyMap[ImGuiKey_UpArrow] = KEY_UP;
	//io.KeyMap[ImGuiKey_DownArrow] = KEY_DOWN;
	//io.KeyMap[ImGuiKey_PageUp] = KEY_PAGE_UP;
	//io.KeyMap[ImGuiKey_PageDown] = KEY_PAGE_DOWN;
	//io.KeyMap[ImGuiKey_Home] = KEY_HOME;
	//io.KeyMap[ImGuiKey_End] = KEY_END;
	//io.KeyMap[ImGuiKey_Insert] = KEY_INSERT;
	//io.KeyMap[ImGuiKey_Delete] = KEY_DELETE;
	//io.KeyMap[ImGuiKey_Backspace] = KEY_BACKSPACE;
	//io.KeyMap[ImGuiKey_Space] = KEY_SPACE;
	//io.KeyMap[ImGuiKey_Enter] = KEY_ENTER;
	//io.KeyMap[ImGuiKey_Escape] = KEY_ESCAPE;
	//io.KeyMap[ImGuiKey_A] = KEY_A;
	//io.KeyMap[ImGuiKey_C] = KEY_C;
	//io.KeyMap[ImGuiKey_V] = KEY_V;
	//io.KeyMap[ImGuiKey_X] = KEY_X;
	//io.KeyMap[ImGuiKey_Y] = KEY_Y;
	//io.KeyMap[ImGuiKey_Z] = KEY_Z;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  
	io.ConfigFlags |= ImGuiConfigFlags_NoKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	SetDarkThemeColors();
}

void ImGuiLayer::OnDetach()
{

}

void ImGuiLayer::OnEvent()
{
	if (m_BlockEvents)
	{
		ImGuiIO& io = ImGui::GetIO();
	}
}

void ImGuiLayer::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiLayer::End()
{
	ImGuiIO& io = ImGui::GetIO();
	Application& app = Application::Get();
	io.DisplaySize = ImVec2((float)app.screenWidth / 5.0f, (float)app.screenHeight / 5.0f);

	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}

uint32_t ImGuiLayer::GetActiveWidgetID() const
{
	return 1;//GImGui->ActiveId;
}

void ImGuiLayer::OnImGuiRender()
{
	static bool show = true;
	ImGui::ShowDemoWindow(&show);
}

void ImGuiLayer::SetDarkThemeColors()
{
	auto& colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

	colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
	colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
	colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

	colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
	colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
	colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

	colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
	colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
	colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

	colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
	colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
	colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
	colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

	colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
	colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
}