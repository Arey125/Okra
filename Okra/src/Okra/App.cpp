#include "okrapch.h"

#include "App.h"
#include "Okra/Log.h"

#include <glad/glad.h>

namespace okra {

#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

	App* App::s_Instance = nullptr;

	App::App()
	{
		OKRA_CORE_ASSERT(s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	App::~App()
	{
	}

	void App::run()
	{
		while (m_Running)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto layer : m_LayerStack)
				layer->onUpdate();

			m_Window->onUpdate();
		}
	}

	void App::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		OKRA_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->onEvent(e);
			if (e.handled)
				break;
		}

	}

	void App::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();

	}

	void App::pushOverlay(Layer* overlay)
	{
		m_LayerStack.pushOverlay(overlay);
		overlay->onAttach();
	}

	bool App::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}