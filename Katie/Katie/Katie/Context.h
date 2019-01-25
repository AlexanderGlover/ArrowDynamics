#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "Player.h"

namespace Context {
	struct Context
	{
		Context();
		Context(sf::RenderWindow& window, ResourceHolder<sf::Texture, int>& textures, ResourceHolder<sf::Font, int>& fonts, Player& player);

		sf::RenderWindow*					mWindow;
		ResourceHolder<sf::Texture, int>*	mTextures;
		ResourceHolder<sf::Font, int>*		mFonts;
		Player*								mPlayer;
	};
};

