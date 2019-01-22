#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = float(VideoMode::getDesktopMode().width);
	resolution.y = float(VideoMode::getDesktopMode().height);

	mWindow.create(VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)), "Katie Engine", Style::Fullscreen);
	
	mBackgroundTexture.loadFromFile("background.jpg");
	mBackgroundSprite.setTexture(mBackgroundTexture);
}

void Engine::Start()
{
	Clock clock;

	mPendingClose = false;
	mDrawSecondaryBackground = false;

	while(mWindow.isOpen())
	{
		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		Input();
		Update(dtAsSeconds);
		Draw();
	}
}