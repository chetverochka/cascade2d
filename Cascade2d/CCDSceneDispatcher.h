#pragma once

// Oбщие задачи: 
// 1) исправлять некоторые ограничение цикличного подключения CCDDispatcher.h и CCDLayer.h
// 2) будет расширять свои список возможностей в будущих версиях!

#include <vector>
#include "CCDLayer.h"

namespace cascade {
	class SceneDispatcher {
	protected:
		Layer* currentScene;
		std::vector<Layer*> scenePool;
	public:
		void setCurrrentScene(Layer* newScene) {
			//scenePool.push_back(newScene);
			if (currentScene)
				currentScene->release();
			currentScene = newScene;
			if (currentScene)
				currentScene->retain();
		}

		Layer* getCurrentScene() { return currentScene; }

		std::vector<Layer*> getScenePool() { return scenePool; }
	};
}