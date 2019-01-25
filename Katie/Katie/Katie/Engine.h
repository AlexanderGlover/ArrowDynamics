#pragma once
#include <SFML/Graphics.hpp>
#include "../ArrowDynamics/Game.h"

using namespace sf;

class Engine
{
public:
	Engine();
	void Start();
protected:
	RenderWindow mWindow;

	Sprite mBackgroundSprite;
	Texture mBackgroundTexture;

	Sprite mSecondBackgroundSprite;
	Texture mSecondBackgroundTexture;
	
	void Input();
	void Update(float dtAsSeconds);
	void Draw();
private:
	Game mGame;
	bool mPendingClose;
	bool mDrawSecondaryBackground;
	bool mQPressed;
};