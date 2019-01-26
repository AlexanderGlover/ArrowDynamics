#pragma once 
#include "Engine.h"

void Engine::Draw()
{
	mWindow.clear(Color::White);
	mWorld->Draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}