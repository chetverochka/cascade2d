#pragma once

#include <vector>
#include "CCDEventListener.h"
#include "CCDNode.h"
namespace cascade {
	class EventDispatcher {
	protected:
		std::vector<EventListener*> activeListeners;
	public:
		~EventDispatcher() {
			for (auto listener : activeListeners) {
				if (listener)
					delete listener;
			}
			activeListeners.clear();
		}

		EventDispatcher() {}

		void addEventListener(EventListener* listener, Node* targetNode) {
			activeListeners.push_back(listener);
			listener->setTargetNode(targetNode);
		}

		void removeEventListener(EventListener* listener, bool del = true) {
			for (int i = 0; i < activeListeners.size(); i++) {
				EventListener* list = activeListeners[i];
				if (listener == list) {
					activeListeners.erase(activeListeners.begin() + i);
					if (del)
						delete listener;
					break;
				}
			}
		}

		void update(float dt) {
			for (int i = 0; i < activeListeners.size(); i++) {
				EventListener* list = activeListeners[i];
				if (!list)
					continue;
				Node* n = list->getTargetNode();
				if (!n) {
					activeListeners.erase(activeListeners.begin() + i);
					delete list;
					continue;
				}
				Node* parent = n->getParent();
				if (parent) {
					list->update(dt);
				}
			}
		}

		std::vector<EventListener*> getListeners() { return activeListeners; }
	};
}