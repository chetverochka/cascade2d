#pragma once

#include <string>
#include "CCDSize.h"
#include "CCDNode.h"
#include "CCDSceneDispatcher.h"
#include "EventListeners\CCDEventDispatcher.h"
#include "CCDColor.h"
namespace cascade {
	class Dispatcher {
	public:
		static Dispatcher* getInstance() {
			if (!dispatcher) {
				dispatcher = new Dispatcher();
			}
			return dispatcher;
		}
		Size getWinSize() { return winSize; }

		SceneDispatcher* getSceneDispatcher() { return sceneDispatcher; }

		void runApplication(Size winSize, std::string winTitle, bool fullscreen);

		EventDispatcher* getEventDispatcher() { return eventDispatcher; }

		void update(float dt);
	protected:

		static Dispatcher* dispatcher;

		Dispatcher() {
			sceneDispatcher = new SceneDispatcher();
			eventDispatcher = new EventDispatcher();

			winColor = Color4F(0.3f, 0.3f, 0.3f, 1);
		}
		~Dispatcher() {
			delete sceneDispatcher;
			delete eventDispatcher;
		}

		Size winSize;
		std::string winTitle;
		Color4F winColor;


		SceneDispatcher* sceneDispatcher;
		EventDispatcher* eventDispatcher;
	};
}