 
#include "Engine.h"

void Engine::Input()
{
	if(Keyboard::isKeyPressed(Keyboard::Escape))
	{
		mWindow.close();
	}
}