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
		virtual void onImGuiRender() override;
		
		void begin();
		void end();


		float m_Time = 0.f;
	};

}
