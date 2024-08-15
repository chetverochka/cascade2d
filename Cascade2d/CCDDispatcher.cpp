#include "CCDDispatcher.h"

cascade::Dispatcher* cascade::Dispatcher::dispatcher = nullptr;

void cascade::Dispatcher::runApplication(Size winSize, std::string winTitle, bool fullscreen) {
	slWindow(winSize.width, winSize.height, winTitle.c_str(), fullscreen);

	this->winSize = winSize;
	this->winTitle = winTitle;
}

void cascade::Dispatcher::update(float dt) {
	slSetBackColor(0.3f, 0.3f, 0.3f);

	Layer* currentScene = getSceneDispatcher()->getCurrentScene();
	getEventDispatcher()->update(dt);
	currentScene->update(dt);
	currentScene->render();
	currentScene->updateActions(dt);
}