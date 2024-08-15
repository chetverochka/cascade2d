#pragma once

#ifndef CCDNODE_H
#define CCDNODE_H

#include "sl.h"
#include "CCDSize.h"
#include "CCDVec.h"
#include <vector>
#include <algorithm>
#include "CCDColor.h"
#include "CCDRef.h"
#include "Actions\CCDActionManager.h"
#include "Actions\CCDAction.h"
#include "CCDClock.h"
namespace cascade {
	class ActionManager;
	class Action;
	class Node : public Ref {
	protected:
		Size _size;
		Vec _position;
		float _rotation;
		Vec _anchorPoint;
		ColorRGBA _color;
		std::vector<Node*> childs;
		Node* _parent;
		int _zOrder;
		Vec _scale;
		ActionManager *_actionManager;

		Vec getWorldPosForSLDraw(float rotating);

		float getAbsoluteRotation();

		Vec getAbsoluteScale();

		virtual void setParent(Node* parent) { _parent = parent; }

		Vec rotatePoint(Vec point, float angleDegrees);
	private:
		bool _debugDrawing;
		void drawChilds() { // оптимизировать сорт!
			std::vector<Node*> sortedChilds = childs;

			std::sort(sortedChilds.begin(), sortedChilds.end(), [](Node* a, Node* b) { return a->getZOrder() < b->getZOrder();});

			for (auto child : childs) {
				if (!child)
					continue;
				child->draw();
				child->drawChilds();
			}
		}
	public:
		void init();

		virtual void draw();

		void render();

		Vec convertToWorldPos(Vec position);

		Node* getParent() { return _parent; }

		virtual void setZOrder(int z) { _zOrder = z; }

		void addChild(Node* child, int zOrder = 0);


		void updateChildsPositions() {
			for (auto child : childs) {
				if (child)
					child->setPosition(child->getPosition());
			}
		}

		virtual void setPosition(Vec position) {
			_position = position;
			updateChildsPositions();
		}

		Vec getPosition() { return _position; }

		virtual void setAnchor(Vec anchorPoint) { _anchorPoint = anchorPoint; }

		Vec getAnchor() { return _anchorPoint; }

		virtual void setRotation(float degrees) { _rotation = degrees; }

		float getRotation() { return _rotation; }

		virtual void setSize(Size size) { _size = size; }

		virtual Size getSize() { return _size; }

		void enableDebugDrawing(bool param) { _debugDrawing = param; }

		ColorRGBA getColor() { return _color; }

		virtual void setColor(ColorRGBA color) { _color = color; }

		Node() { Node::init(); }

		virtual void setScale(Vec scale) { _scale = scale; }

		Vec getScale() { return _scale; }

		virtual void setScale(float scale) { _scale = Vec(scale, scale); }

		Vec convertPositionToScale(Vec point);

		int getZOrder() { return _zOrder; }

		void removeChild(Node* node);

		~Node();

		ActionManager* getActionManager() { return _actionManager; }

		void runAction(Action* action);
		void updateActions(float dt);
	};
}

#endif

