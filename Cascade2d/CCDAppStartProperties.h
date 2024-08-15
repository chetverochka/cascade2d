#pragma once
#include "CCDSize.h"
#include <string>

namespace cascade {
	struct AppStartProperties {
		std::string winTitle;
		Size winSize;
		bool fullscreen;
		AppStartProperties() {
			fullscreen = false;
			winTitle = "Cascade Window";
			winSize = Size(600, 500);
		}
	};
}