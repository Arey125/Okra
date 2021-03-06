#pragma once

#include "Core.h"

#include "Window.h"
#include "Okra/LayerStack.h"
#include "Okra/Events/Event.h"
#include "Okra/Events/AppEvent.h"

#include "Okra/ImGui/ImGuiLayer.h"

#include "Okra/Renderer/Shader.h"
#include "Okra/Renderer/Buffer.h"

namespace okra {

	class OKRA_API App
	{
	public:
		App();
		~App();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline static App& get() { return *s_Instance; }
		inline Window& getWindow() { return *m_Window; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		//Graphics
		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		static App* s_Instance;
	};

	//defined in client
	extern okra::App* createApp();
}

