#include "Input.h"

#include <raylib.h>

Input* Input::s_Instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int keycode)
{
	return ::IsKeyPressed(keycode);
}

bool WindowsInput::IsMouseButtonPressedImpl(int button)
{
	return ::IsMouseButtonPressed(button);
}

float WindowsInput::GetMouseXImpl()
{
	return ::GetMouseX();
}

float WindowsInput::GetMouseYImpl()
{
	return ::GetMouseY();
}