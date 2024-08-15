#pragma once
#include "CCDNode.h"
#include "CCDTexture.h"

namespace cascade {
	class Sprite : public Node {
	protected:
		Texture texture;
	public:
		Sprite(Texture texture) : texture(texture) {
			Node::Node();
			setAnchor(Vec(0.5, 0.5));
			setSize(texture.getSize());
		}
		void draw() override {
			Node::draw();

			if (!texture.isLoaded())
				return;

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
			slSprite(texture.getTexture(), -rotateAnchor.x, -rotateAnchor.y, finalSize.width, finalSize.height);
			slPop();
		}
		
		Texture getTexture() { return texture; }

		void setTexture(Texture t) { texture = t; }
	};
}