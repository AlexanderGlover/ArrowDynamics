#include "Entity.h"

Entity::Entity()
{
}

void Entity::UpdateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}

void Entity::SetPosition(sf::Vector2f position)
{
	setPosition(position);
}

const sf::Vector2f Entity::GetPosition()
{
	return(getPosition());
}

void Entity::SetVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::SetVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::GetVelocity() const
{
	return(mVelocity);
}

Textures::ID Entity::ToTextureID(int id)
{
	return(Textures::Default);
}