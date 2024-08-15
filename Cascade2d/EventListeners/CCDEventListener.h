#pragma once

#include "CCDNode.h"

namespace cascade {
	class EventListener {
	protected:
		Node* _targetNode;
		bool _swallowTouches;
	public:
		EventListener() {
			_swallowTouches = false;
		}

		virtual void update(float dt) {}

		void setTargetNode(Node* node) { _targetNode = node; }
		Node* getTargetNode() { return _targetNode; }

		void setSwallowTouches(bool param) { _swallowTouches = param; };
		bool isSwallowTouches() { return _swallowTouches; }
	};
}