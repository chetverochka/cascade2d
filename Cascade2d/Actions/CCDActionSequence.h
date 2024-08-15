#pragma once

#include "CCDAction.h"
#include <vector>

namespace cascade {
	class Sequence : public Action {
		std::vector<Action*> actions;
		int currentActionIndex;
		bool currentActionWasRunned;
	public:
		Sequence(std::vector<Action*> sequenceActions) {
			Action::Action();
			_duration = 0.f;
			actions = sequenceActions;
		}

		void run() override {
			Action::run();
			currentActionIndex = 0;
			currentActionWasRunned = false;
			for (auto action : actions) {
				action->setTargetNode(_targetNode);
			}
		}
		void update(float dt) override;
	};
}