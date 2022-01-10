#pragma once

#include "Core.h"

namespace okra {

	class OKRA_API App
	{
	public:
		App();
		~App();

		void run();
	};

	//defined in client
	extern okra::App* createApp();
}

