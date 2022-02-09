#include "okrapch.h"
#include "WindowsInput.h"

#include "Okra/App.h"
#include <GLFW/glfw3.h>

namespace okra
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(App::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(App::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::getMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(App::get().getWindow().getNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return {xpos, ypos};
	}

	float WindowsInput::getMouseXImpl()
	{
		auto [xpos, ypos] = getMousePositionImpl();
		return xpos;
	}

	float WindowsInput::getMouseYImpl()
	{
		auto [xpos, ypos] = getMousePositionImpl();
		return ypos;
	}
}