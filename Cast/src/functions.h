#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <raylib.h>

#include <string>
#include <sstream>

#include "GameObjects/Sprite2D.h"
#include "GameObjects/Image2D.h"
#include "GameObjects/Text2D.h"
#include "GameObjects/Button2D.h"

#include <imgui.h>

#include "imgui/rlImGui.h"
#include "imgui/imgui_impl_raylib.h"

//std::string Vector2ToString(const Vector2& vec) 
//{
//    std::ostringstream oss;
//    oss << "(" << vec.x << ", " << vec.y << ")";
//    return oss.str();
//}

template <typename T>
inline void ImGuiShowObjectInfo(T& obj) 
{
	if constexpr (std::is_same_v<T, Sprite2D>)
	{
		float pos[2] = { obj.GetPosition().x, obj.GetPosition().y };

		ImGui::Text("Class: Sprite2D");
		if (ImGui::InputFloat2("Position", pos)) obj.SetPosition(pos[0], pos[1]); 
		ImGui::SliderFloat("Scale", &obj.GetScale(), 0.1f, 10.0f);
		ImGui::SliderFloat("Rotation", &obj.GetRotation(), 0.0f, 360.0f);
		ImGui::Text("Texture Width: %d", obj.GetTexture()->width);
		ImGui::Text("Texture Height: %d", obj.GetTexture()->height);
		ImGui::Image(obj.GetTexture(), ImVec2(obj.GetTexture()->width / 2, obj.GetTexture()->height / 2));
	}
	else if constexpr (std::is_same_v<T, Text2D>) 
	{
		float pos[2] = { obj.GetPosition().x, obj.GetPosition().y };
		char buffer[256];
		std::strncpy(buffer, obj.GetText().c_str(), sizeof(buffer));
		const Color objColor = obj.GetColor();
		float color[4] = { objColor.r / 255.0f, objColor.g / 255.0f, objColor.b / 255.0f, objColor.a / 255.0f };

	    ImGui::Text("Class: Text2D");
		if (ImGui::InputText("Text", buffer, sizeof(buffer))) obj.SetText(buffer);
		if (ImGui::InputFloat2("Position", pos)) obj.SetPosition(pos[0], pos[1]);
		ImGui::SliderInt("Font Size", &obj.GetFontSize(), 1, 10);
		if (ImGui::ColorEdit4("Color", color)) 
			obj.SetColor({
		(unsigned char)(color[0] * 255),
		(unsigned char)(color[1] * 255),
		(unsigned char)(color[2] * 255),
		(unsigned char)(color[3] * 255)});
	}
	//else if constexpr (std::is_same_v<T, Button2D>) {
	//    ImGui::Text("Button2D");
	//    ImGui::Text("Text: %s", obj.GetText().c_str());
	//    ImGui::Text("Position: (%.2f, %.2f)", obj.GetPosition().x, obj.GetPosition().y);
	//    ImGui::Text("Size: (%.2f, %.2f)", obj.GetSize().x, obj.GetSize().y);
	//    ImGui::Text("Color: (%d, %d, %d, %d)", obj.GetColor().r, obj.GetColor().g, obj.GetColor().b, obj.GetColor().a);
	//}
}