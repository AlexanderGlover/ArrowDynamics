#pragma once
#include <SFML/Graphics.hpp>

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
	bool mPendingClose;
	bool mDrawSecondaryBackground;
	bool mQPressed;
};