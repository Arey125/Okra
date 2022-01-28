#pragma once

#include "Okra/Layer.h"

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
		float m_Time = 0.f;
	};

}
