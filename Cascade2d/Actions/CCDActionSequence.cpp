#include "CCDActionSequence.h"

void cascade::Sequence::update(float dt) {
	if (currentActionIndex >= actions.size()) {
		_running = false;
		return;
	}
	Action* currentAction = actions[currentActionIndex];
	if (!currentActionWasRunned) {
		currentActionWasRunned = true;
		if (currentAction) {
			currentAction->run();
		}
	}
	else if (currentActionWasRunned && !currentAction->isRunning()) {

		// должно предотвращать утечку памяти
		/*for (int i = 0; i < actions.size(); i++) {
			Action* act = actions[i];
			if (act == currentAction) {
				delete currentAction;
				actions.erase(actions.begin() + i);
				break;
			}
		}*/

		if (currentActionIndex + 1 <= actions.size() - 1) {
			currentActionIndex++;
			currentAction = actions[currentActionIndex];
			currentActionWasRunned = false;
		}
		else {
			_running = false;
			return;
		}
	}

	currentAction->update(dt);
}