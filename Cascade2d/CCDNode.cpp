#include "CCDNode.h"
#include "Actions\CCDActionManager.h"
#include "Actions\CCDAction.h"
using namespace cascade;

void Node::init() {
	_size = Size(0, 0);
	_position = Vec(0, 0);
	_rotation = 0;
	_parent = nullptr;
	_anchorPoint = Vec(0, 0);
	_zOrder = 0;
	_debugDrawing = false;
	_color = ColorRGBA::WHITE;
	_scale = Vec(1.f, 1.f);

	_actionManager = new ActionManager();
	_actionManager->init(this);
}

void Node::draw() {
	if (!_debugDrawing)
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
	slRectangleOutline(-rotateAnchor.x, -rotateAnchor.y, finalSize.width, finalSize.height);
	slPop();	
}

void Node::render() {
	draw();
	drawChilds();
}

Vec Node::convertToWorldPos(Vec position) {
	Vec pos;
	pos.x = (_position.x - (_size.width * _anchorPoint.x)) + position.x;
	pos.y = (_position.y - (_size.height * _anchorPoint.y)) + position.y;

	if (_parent) {
		return _parent->convertToWorldPos(pos);
	}

	return pos;
}

void Node::addChild(Node* child, int zOrder) {
	child->setParent(this);
	child->setZOrder(zOrder);
	child->retain();
	childs.push_back(child);

	updateChildsPositions();
	
}

float Node::getAbsoluteRotation() {
	float rotation = _rotation;

	if (_parent) {
		rotation += _parent->getAbsoluteRotation();
	}

	return rotation;
}

Vec Node::getWorldPosForSLDraw(float rotating) {
	Vec worldPos = _position;

	if (_parent) {
		worldPos = _parent->convertPositionToScale(_position);
		worldPos = _parent->rotatePoint(worldPos, _parent->getRotation());
		worldPos = _parent->convertToWorldPos(worldPos);	
	}

	Vec scale = getAbsoluteScale();
	Size scaledSize = Size(_size.width * scale.x, _size.height * scale.y);

	Vec pos;
	pos.x = (worldPos.x + scaledSize.width / 2) - (scaledSize.width * _anchorPoint.x);
	pos.y = (worldPos.y + scaledSize.height / 2) - (scaledSize.height * _anchorPoint.y);

	return pos;
}

Vec Node::rotatePoint(Vec point, float angleDegrees) {

	Size scaledSize;
	scaledSize.width = _size.width * getAbsoluteScale().x;
	scaledSize.height = _size.height * getAbsoluteScale().y;

	Vec centerPos;
	centerPos.x = _anchorPoint.x * scaledSize.width;
	centerPos.y = _anchorPoint.y * scaledSize.height;

	float angleRadians = angleDegrees * 3.141592 / 180.0;

	float translatedX = point.x - centerPos.x;
	float translatedY = point.y - centerPos.y;

	float rotatedX = translatedX * cos(angleRadians) - translatedY * sin(angleRadians);
	float rotatedY = translatedX * sin(angleRadians) + translatedY * cos(angleRadians);

	Vec result;
	result.x = rotatedX + centerPos.x;
	result.y = rotatedY + centerPos.y;

	return result;
}

Vec Node::getAbsoluteScale() {
	Vec scale = _scale;

	if (_parent) {
		Vec parentScale = _parent->getScale();

		scale.x += parentScale.x - 1;
		scale.y += parentScale.y - 1;
	}

	return scale;
}

// конвертирует позицию точки на ноде с учётом наложения Scalинга
Vec Node::convertPositionToScale(Vec point) {
	Vec scale = getAbsoluteScale();
	return Vec(scale.x * point.x, scale.y * point.y);
}

void Node::removeChild(Node* node) {
	for (int i = 0; i < childs.size(); i++) {
		Node* child = childs[i];

		if (child == node) {
			child->release();
			childs.erase(childs.begin() + i);
			break;
		}
	}
}

void Node::updateActions(float dt) {
	_actionManager->update(dt);
	for (auto child : childs) {
		if (child) {
			child->updateActions(dt);
		}
	}
}

void Node::runAction(Action* action) {
	_actionManager->runAction(action);
}

Node::~Node() {
	for (auto child : childs) {
		if (child)
			child->release();
	}
	childs.clear();

	delete _actionManager;
}