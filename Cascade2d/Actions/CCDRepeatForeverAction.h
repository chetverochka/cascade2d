#pragma once

#include "CCDAction.h"

namespace cascade {
	class RepeatForeverAction : public Action {
		Action* loopedAction;
	public:
		RepeatForeverAction(Action* action) {
			Action::Action();
			loopedAction = action;
		}

		void run() {
			Action::run();
			loopedAction->setTargetNode(_targetNode);
		}

		void update(float dt) override {
			if (!loopedAction) {
				return;
			}

			if (!loopedAction->isRunning()) {
				loopedAction->run();
			}

			loopedAction->update(dt);
		}

		~RepeatForeverAction() {
			loopedAction->stop();
			delete loopedAction;
		}
	};
}
