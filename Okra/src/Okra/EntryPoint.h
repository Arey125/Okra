#pragma once

#include "App.h"
#include <cstdio>

extern okra::App* okra::createApp();

int main(int argc, char** argv)
{
	printf("Okra Engine works!");
	okra::App* app = okra::createApp();
	app->run();
	delete app;
}