#include "Engine.h"

#include <filesystem>
#include <stdlib.h>
#include <iostream>

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = float(VideoMode::getDesktopMode().width);
	resolution.y = float(VideoMode::getDesktopMode().height);

	mWindow.create(VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)), "Arrow-Dynamics", Style::Fullscreen);
	mWorld = new World(mWindow);
}

void Engine::Start()
{
	Clock clock;

	while (mWindow.isOpen())
	{
		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		if (!mGame.Update(dt))
		{
			mWindow.close();
		}

		Input();
		Update(dtAsSeconds);
		Draw();
	}
}