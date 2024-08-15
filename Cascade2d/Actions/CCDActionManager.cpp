#include "CCDActionManager.h"
#include "CCDNode.h"
#include "CCDAction.h"
void cascade::ActionManager::init(cascade::Node* node) {
	targetNode = node;
}

void cascade::ActionManager::update(float dt) {
	for (int i = 0; i < activeActions.size(); i++) {
		Action* act = activeActions[i];
		if (!act) {
			continue;
		}
		if (!act->isRunning()) {
			activeActions.erase(activeActions.begin() + i);
			delete act;
			continue;
		}
		act->update(dt);
	}

}

void cascade::ActionManager::runAction(cascade::Action* action) {
	if (!action) {
		return;
	}

	activeActions.push_back(action);
	action->setTargetNode(targetNode);
	action->run();
}

cascade::Action* cascade::ActionManager::getActionByTag(int tag) {
	for (auto act : activeActions) {
		if (!act)
			continue;

		int _tag = act->getTag();
		if (_tag == tag)
			return act;
	}
}

void cascade::ActionManager::stopAction(cascade::Action* action) {
	for (auto act : activeActions) {
		if (!act)
			continue;

		if (act == action) {
			act->stop();
		}
	}
}