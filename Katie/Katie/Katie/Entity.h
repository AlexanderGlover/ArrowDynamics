#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "ResourceHolder.h"

namespace Textures
{
	enum ID
	{
		Default,
		Background,
		Mechanic,
		Manager,
	};
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Entity : sf::Transformable
{
public:
	explicit Entity();
	void	SetVelocity(sf::Vector2f velocity);
	void	SetVelocity(float vx, float vy);
	void	SetPosition(sf::Vector2f position);
	const sf::Vector2f	GetPosition();
	sf::Vector2f GetVelocity() const;
protected:
private:
	virtual void UpdateCurrent(sf::Time dt);
	virtual Textures::ID	ToTextureID(int id);
	sf::Vector2f	mVelocity;
};