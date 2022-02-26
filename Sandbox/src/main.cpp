#include <Okra.h>
#include <imgui/imgui.h>

class ExampleLayer : public okra::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override
	{
		if (okra::Input::isKeyPressed(OKRA_KEY_TAB))
			OKRA_TRACE("Tab key is pressed");
	}

	void onImGuiRender() override
	{
		ImGui::Begin("Text");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void onEvent(okra::Event& event) override
	{
		if (event.getEventType() == okra::EventType::KeyPressed)
		{
			okra::KeyPressedEvent& e = (okra::KeyPressedEvent&)event;
			OKRA_TRACE("{0}", (char)e.getKeyCode());
		}
	}
};

class Sandbox : public okra::App
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

okra::App* okra::createApp()
{
	return new Sandbox();
}