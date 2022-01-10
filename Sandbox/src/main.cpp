#include <Okra.h>

class Sandbox : public okra::App
{
public:
	Sandbox() {}
	~Sandbox() {}
};

okra::App* okra::createApp()
{
	return new Sandbox();
}