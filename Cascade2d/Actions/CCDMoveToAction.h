#pragma once

#include "CCDAction.h"
#include "CCDVec.h"

namespace cascade {
	class MoveTo : public Action {
		Vec startPos;
		Vec targetPos;
		Vec currentPos;
	public:
		MoveTo(float duration, Vec tPos) { 
			Action::Action();
			targetPos = tPos;
			_duration = abs(duration);
		}
		void run() override {
			Action::run();
			startPos = _targetNode->getPosition();
			currentPos = startPos;
		}

		void update(float dt) override {
			float elapsed = _clock.getElapsedInSeconds();
			if (!_running) {
				return;
			}
			else {
				if (targetPos == currentPos || elapsed > _duration) {
					_running = false;
					return;
				}
			}
			if (elapsed < _duration) {
				float interpolation = elapsed / _duration;
				currentPos.x = (targetPos.x - startPos.x) * interpolation;
				currentPos.y = (targetPos.y - startPos.y) * interpolation;
				_targetNode->setPosition(Vec(startPos.x + currentPos.x, startPos.y + currentPos.y));
			}
		}
	};
}