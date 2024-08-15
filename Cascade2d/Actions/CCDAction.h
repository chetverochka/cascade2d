#pragma once

#ifndef CCDACTION_H
#define CCDACTION_H

#include "CCDClock.h"
#include "CCDNode.h"
namespace cascade {
	class Node;
	class Action {
	protected:
		float _duration;
		float _elapsed;
		Node* _targetNode;
		bool _running;
		Clock _clock;
		int _tag;
	public:
		Action() {
			_tag = 0;
			_running = false;
		}
		virtual void run() {
			_clock.restart();
			_running = true;
		}

		virtual void update(float dt) {}

		void setTargetNode(Node* node);

		bool isRunning() { return _running; }

		int getTag() { return _tag; }

		void setTag(int tag) { _tag = tag; }

		void stop() { _running = false; }
	};
}

#endif