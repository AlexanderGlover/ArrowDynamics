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

	String mAssetPath = "../Assets";

	TCHAR full_path[MAX_PATH];
	DWORD string_len = GetFullPathName(TEXT("Assets"),
		MAX_PATH,
		full_path,
		NULL);
	printf("Length of full path string: %lu\n"
		"Full path: '%s'",
		(unsigned long)string_len,
		full_path);

	String dataPath = full_path;
	dataPath += "/background.jpg";

	mBackgroundTexture.loadFromFile(dataPath);
	mBackgroundSprite.setTexture(mBackgroundTexture);
}

void Engine::Start()
{
	Clock clock;

	mPendingClose = false;
	mDrawSecondaryBackground = false;

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