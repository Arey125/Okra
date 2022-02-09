#pragma once

#include "Okra/Layer.h"
#include "Okra/Events/MouseEvent.h"
#include "Okra/Events/KeyEvent.h"
#include "Okra/Events/AppEvent.h"

namespace okra
{

	class OKRA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onUpdate() override;
		virtual void onEvent(Event& event) override;

	private:

		//Mouse events
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
		bool OnMouseMovedEvent(MouseMovedEvent &e);
		bool OnMouseScrolledEvent(MouseScrollEvent &e);
		
		//Keyboard events
		bool onKeyPressedEvent(KeyPressedEvent&e);
		bool onKeyReleasedEvent(KeyReleasedEvent &e);
		bool onKeyTypedEvent(KeyTypedEvent &e);
		
		//App events
		bool OnWindowResizedEvent(WindowResizeEvent &e);

		float m_Time = 0.f;
	};

}
