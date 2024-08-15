#pragma once

#include "sl.h"

namespace cascade {
	
	class Clock {
		float _timeFromStart;
	public:
		Clock() {
			restart();
		}
		float getElapsedInSeconds() {
			return slGetTime() - _timeFromStart;
		}
		void restart() {
			_timeFromStart = slGetTime();
		}
	};
}