#include "okrapch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace okra
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		OKRA_ASSERT(windowHandle, "Window handle is null")
	}

	void OpenGLContext::init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OKRA_CORE_ASSERT(status, "Failed to initialize Glad");

		OKRA_CORE_INFO("OpenGL Info");
		OKRA_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		OKRA_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		OKRA_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}