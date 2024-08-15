#include <windows.h> 
#include "Cascade.h"
#include "HelloWorldScene.h"

using namespace cascade;

int main() {
	Dispatcher::getInstance()->runApplication(Size(640,420), "Cascade window", false);
	
	HelloWorld* scene = new HelloWorld();
	Dispatcher::getInstance()->getSceneDispatcher()->setCurrrentScene(scene);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE)){
		Dispatcher::getInstance()->update(slGetDeltaTime());
		slRender();
	}
	slClose();
	return 0;
}

