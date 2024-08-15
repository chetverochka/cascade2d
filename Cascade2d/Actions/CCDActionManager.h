#pragma once
#ifndef CCDACTIONMANAGER_H
#define CCDACTIONMANAGER_H

#include <vector>
#include "CCDAction.h"
#include "CCDNode.h"
namespace cascade {
	class Node;
	class Action;
	class ActionManager {
	protected:
		std::vector<Action*> activeActions;
		Node* targetNode;
	public:
		ActionManager() {}
		void init(Node* node);
		void runAction(Action* action);
		void update(float dt);
		Action* getActionByTag(int tag);
		void stopAction(Action* action);
	};
}

#endif