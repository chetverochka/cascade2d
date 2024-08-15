#pragma once

#include <functional>
#include "sl.h"

#include "EventListeners\CCDEventListener.h"
#include "CCDLog.h"
#include "CCDVec.h"
namespace cascade {
	class MouseEvent {
	public:
		Vec touchLocation;
	};

	class EventListenerMouse : public EventListener {
		bool pressed;
		bool mousePressWasDenied;
		Vec onPressedPosition;
	public:
		std::function<bool(MouseEvent)> onMousePressed;
		std::function<bool(MouseEvent)> onMouseReleased;
		std::function<void(MouseEvent)> onMouseMoved;

		EventListenerMouse() {
			EventListener::EventListener();
			pressed = false;
			mousePressWasDenied = false;
		}

		void update(float dt) override {
			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) {
				if (!pressed && !mousePressWasDenied) {
					if (onMousePressed) {
						MouseEvent _event;
						_event.touchLocation = Vec(slGetMouseX(), slGetMouseY());
						onPressedPosition = _event.touchLocation;
						pressed = onMousePressed(_event);
					}
					if (!pressed)
						mousePressWasDenied = true;
					CCDLOG("EventListenerMouse: mouse pressed!\n\n");
				}
			}
			else {
				if (pressed) {
					if (onMouseReleased) {
						MouseEvent _event;
						_event.touchLocation = Vec(slGetMouseX(), slGetMouseY());

						// здесь возможно необходимо поставить pressed = false чтобы избежать странностей в поведении
						pressed = !onMouseReleased(_event);
					}
					CCDLOG("EventListenerMouse: mouse released!\n\n");
				}
				if (mousePressWasDenied) {
					mousePressWasDenied = false;
				}
			}

			bool touchMoved = (onPressedPosition.x != slGetMouseX() || onPressedPosition.y != slGetMouseY());

			if (pressed && touchMoved){
				if (onMouseMoved) {
					MouseEvent _event;
					_event.touchLocation = Vec(slGetMouseX(), slGetMouseY());
					onMouseMoved(_event);
				}
				
				CCDLOG("EventListenerMouse: mouse moved!\n\n");
			}
		}
	};
}