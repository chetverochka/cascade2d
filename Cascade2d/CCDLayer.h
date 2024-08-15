#pragma once

#include "CCDNode.h"

namespace cascade {

	class Dispatcher;

	class Layer : public Node {
	public:
		Layer() {
			Node::Node();
		}
		Layer(Size layerSize) {
			Node::Node();
			setSize(layerSize);
		}

		void draw() { Node::draw(); }

		virtual	void update(float dt) {}
	};
}