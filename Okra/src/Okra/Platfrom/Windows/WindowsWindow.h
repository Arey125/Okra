#pragma once
#include "Okra/Window.h"

#include <GLFW/glfw3.h>

namespace okra
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;
		
		inline unsigned int getWigth() const override { return m_Data.width; }
		inline unsigned int getHeight() const override { return m_Data.height; }

		//Window
		inline void setEventCallback(const EventCallbackFn& callback) override { m_Data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};

}