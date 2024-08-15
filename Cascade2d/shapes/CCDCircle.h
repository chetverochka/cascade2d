#pragma once

#include "CCDNode.h"

namespace cascade {
	class Circle : public Node {
	protected:
		float radius;
		float verticlesNum;
	public:
		Circle() {
			Node::Node();

			setRadius(25.f);
			setVerticlesNum(20);
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
			slCircleFill(-rotateAnchor.x, -rotateAnchor.y, radius, verticlesNum);
			slPop();
		}

		void setSize(Size size) override {}
		
		void setRadius(float r) {
			Node::setSize(Size(r * 2, r * 2));
			radius = r;
		}
		
		void setVerticlesNum(float n) {
			verticlesNum = n;
		}
	};
}