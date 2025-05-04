#pragma once

#define IMGUI_IMPL_OPENGL_LOADER_GLAD

#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#define GL_SILENCE_DEPRECATION

#include "LayerStack.h"


#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif



class ImGuiLayer : public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent() override;

	void Begin();
	void End();

	void OnImGuiRender() override;

	void BlockEvents(bool block) { m_BlockEvents = block; }

	void SetDarkThemeColors();

	uint32_t GetActiveWidgetID() const;
private:
	bool m_BlockEvents = true;
};