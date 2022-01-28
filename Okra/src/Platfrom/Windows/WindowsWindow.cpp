#include "okrapch.h"
#include "WindowsWindow.h"

#include "Okra/Events/KeyEvent.h"
#include "Okra/Events/MouseEvent.h"
#include "Okra/Events/AppEvent.h"

#include <glad/glad.h>

namespace okra
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		OKRA_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}


	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const
	{
		return m_Data.vSync;
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		m_Data.title = props.title;
		m_Data.width = props.width;
		m_Data.height = props.height;

		OKRA_CORE_INFO("Creating window {0} ({1}, {2})",
			props.title, props.width, props.height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			OKRA_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.width, (int)props.height,
			m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OKRA_CORE_ASSERT(status, "Failed to initialize Glad");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				WindowResizeEvent event(width, height);
				data.width = width;
				data.height = height;

				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.eventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.eventCallback(event);
						break;
					}
				}
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.eventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrollEvent event(xOffset, yOffset);
				data.eventCallback(event);
			});
		
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event(xPos, yPos);
				data.eventCallback(event);
			});

	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}