#pragma once

#include "CCDAction.h"

namespace cascade {
	class DelayAction : public Action {
	public:
		DelayAction(float duration) {
			_duration = abs(duration);
		}
		void update(float dt) override {
			if (_clock.getElapsedInSeconds() > _duration) {
				_running = false;
			}
		}
	};
}