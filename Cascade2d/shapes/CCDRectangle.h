#pragma once

#include "CCDNode.h"
#include "CCDSize.h"

namespace cascade {
	class Rectangle : public Node {
	public:
		Rectangle() {
			Node::Node();
			setSize(Size(50, 50));
		}

		void draw() override {
			Node::draw();

			Vec absoluteScale = getAbsoluteScale();
			float rotate = getAbsoluteRotation();
			Vec drawablePosition = getWorldPosForSLDraw(rotate);

			Vec rotateAnchor;
			rotateAnchor.x = (_size.width / 2) + (_anchorPoint.x * _size.width) - _size.width;
			rotateAnchor.y = (_size.height / 2) + (_anchorPoint.y * _size.height) - _size.height;

			Size finalSize;
			finalSize.width = (_size.width - 1) * absoluteScale.x;
			finalSize.height = (_size.height - 1) * absoluteScale.y;

			slPush();
			slTranslate(drawablePosition.x + rotateAnchor.x, drawablePosition.y + rotateAnchor.y);
			slRotate(rotate);
			slRectangleFill(-rotateAnchor.x, -rotateAnchor.y, finalSize.width, finalSize.height);
			slPop();
		}
	};
}