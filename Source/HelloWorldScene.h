#pragma once

#include "Cascade.h"

using namespace cascade;

class HelloWorld : public cascade::Layer {
private:
	cascade::Sprite* sprite;
public:
	HelloWorld() {
		Layer::Layer(cascade::Dispatcher::getInstance()->getWinSize());

		sprite = new cascade::Sprite(cascade::Texture("example.png"));
		sprite->setPosition(cascade::Dispatcher::getInstance()->getWinSize() / 2);
		addChild(sprite);
	}

	void update(float dt) override {
		
	}

	~HelloWorld(){
		delete sprite;
	}
};
