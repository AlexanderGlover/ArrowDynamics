#include "pch.h"
#include "Engine.h"

void Engine::Draw()
{
	mWindow.clear(Color::White);

	if (mDrawSecondaryBackground)
	{
		mWindow.draw(mSecondBackgroundSprite);
	}
	else
	{
		mWindow.draw(mBackgroundSprite);
	}
	
	mWindow.display();
}