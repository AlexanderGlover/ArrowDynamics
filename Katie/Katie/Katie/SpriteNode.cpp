#pragma once
#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& rect) :
	mSprite(texture, rect)
{
}

SpriteNode::SpriteNode(const sf::Texture& texture) :
	mSprite(texture)
{
}

void SpriteNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}