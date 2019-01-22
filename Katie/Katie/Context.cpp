#include "pch.h"

#include "Context.h"

namespace Context {

Context::Context()
{
}

Context::Context(sf::RenderWindow& window, ResourceHolder<sf::Texture, int>& textures, ResourceHolder<sf::Font, int>& fonts, Player& player)
{
	mWindow = &window;
	mTextures = &textures;
	mFonts = &fonts;
	mPlayer = &player;

}

}