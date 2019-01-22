#include "pch.h"
#include "Engine.h"

namespace Textures
{
	enum ID { Landscape, Airplane, Missle };
}

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