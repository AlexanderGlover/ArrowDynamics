#pragma once
#include <SFML/Graphics.hpp>
#include "../ArrowDynamics/Game.h"
#include "../ArrowDynamics/World.h"

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
	World* mWorld;

	String mStatisticsText;
};