#pragma once

#include "App.h"

extern okra::App* okra::createApp();

int main(int argc, char** argv)
{
	okra::Log::init();

	okra::App* app = okra::createApp();
	app->run();
	delete app;
}