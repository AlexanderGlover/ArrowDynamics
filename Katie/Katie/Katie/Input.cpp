 
#include "Engine.h"

void Engine::Input()
{
	if(Keyboard::isKeyPressed(Keyboard::Escape))
	{
		mWindow.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		mPendingClose = true;
	}
	else if(mPendingClose)
	{
		mWindow.close();
	}

	if(Keyboard::isKeyPressed(Keyboard::Q))
	{
		if(!mQPressed)
		{
			mDrawSecondaryBackground = !mDrawSecondaryBackground;
		}
		mQPressed = true;
	}
	else
	{
		mQPressed = false;
	}
}