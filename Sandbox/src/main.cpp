#include <Okra.h>

class ExampleLayer : public okra::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override
	{
		OKRA_INFO("ExamleLayer::update");
	}
	void onEvent(okra::Event& event) override
	{
		OKRA_TRACE("{0}", event);
	}
};

class Sandbox : public okra::App
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new okra::ImGuiLayer());
	}
	~Sandbox() {}
};

okra::App* okra::createApp()
{
	return new Sandbox();
}